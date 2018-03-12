#!/usr/bin/perl
use strict;
use lib "$ENV{HOME}/CeeSeq/script/lib";
use JSON::Tiny qw(decode_json encode_json);
 use POSIX qw(strftime);
use Data::Dumper;

my $gVerbose                 = 1;
my $gAllClassesAndInterfaces = undef;
my $gApif                    = undef;
my $gNow                     = strftime("%m/%d/%Y %H:%M:%S", localtime);

sub run {
    my ($cmd, %opts) = @_;
    print "$cmd\n" if $gVerbose;
    if (system $cmd) {
        die "Failed '$cmd'" unless $opts{noexit};
    }
}

sub backtick {
    my ($cmd) = @_;
    if (wantarray) {
        my @a = `$cmd`;
        if ($?) {
            die "Failed '$cmd'";
        }
        return @a;
    } else {
        my $buffer = `$cmd`;
        if ($?) {
            die "Failed '$cmd'";
        }
        return $buffer;
    }
}


sub writeWarning {
	my ($out, $srcFile) = @_;
	print {$out} "// *** DO NOT MODIFY THIS FILE (see $srcFile) generated $gNow ***\n";
}

sub writeStruct {
	my ($out, $classOrInterface) = @_;
	pexpand($out, ["Struct:head"], {TYPENAME => $classOrInterface->{typeName}});	
	for my $field (@{$classOrInterface->{fields}}) {
		my $stype = spaceAdjustType($field->{type});
		pexpand($out, ["Struct:field"], {STYPE=>$stype, NAME => $field->{name}});	
	}
	pexpand($out, ["Struct:tail"], {});
}

sub writePredefined {
	my ($out, $class) = @_;
	if (defined($class->{aliasFor})) {
		pexpand($out, ['Predefined:alias'], {ALIAS=>$class->{aliasFor}, TYPENAME=>$class->{typeName}});
	} else {
		pexpand($out, ['Predefined:struct'], {TYPENAME=>$class->{typeName}});
	}
}

sub writeArgDeclare {
	my ($out, $class) = @_;
	my $args = "";
	my $struct = "{";
	for my $field (@{$class->{fields}}) {
		if (defined($field->{group})) {
			next;
		}
		$args   .= "$field->{name}, ";
		$struct .= "($field->{name}), ";
	}
	$args   =~ s/,\s*$//;
	$struct =~ s/,\s*$//;
	$struct .= "}";
	pexpand($out, ["Type:argDeclare"], {ARGS=>$args, STRUCT=>$struct, TYPENAME=>$class->{typeName}});
	
}

sub spaceAdjustType {
	my ($type) = @_;
	return $type =~ /\*$/ ? $type : "$type ";
}

sub setNameFromFieldName {
	my ($fieldName) = @_;
	my ($first, $rest) = ($fieldName =~ /^(.)(.*)$/);
	die "INTERNAL ERROR" unless defined($rest);
	return 'set' . uc($first) . $rest;
}

sub writeAccessor {
	my ($out, $class, $usedCalls) = @_;
	my $typeName     = $class->{typeName};
	for my $field (@{$class->{fields}}) {
		if (defined($field->{group})) {
			next;
		}

		my $getter       = $field->{getter}; 
		my $getterReturn = $field->{getterReturn};
		my $rtype        = $field->{type};
		my $maybeAmper   = '';
		if ($getterReturn eq 'pointer') {
			$rtype      = "$rtype *";
			$maybeAmper = "&";
		}
		my $stype = spaceAdjustType($rtype);
		my $setter = $field->{setter}; 
		my $setName = setNameFromFieldName($field->{name});
		my $exCfg = {TYPENAME=>$typeName, STYPE=>$stype, FIELDNAME=>$field->{name}, MAYBEAMPER=>$maybeAmper, SETNAME=>$setName};
		
		if (defined($getter)) {			
			if ($getter ne 'none') {
		 		die "The 'getter' flag set to something funny: getter=$getter, typename=$typeName";
		 	}
		} else {
			pexpand($out, ["Type:getter"], $exCfg);
		}
			
		if (defined($setter)) {	
			if ($setter ne 'none') {
				die "The 'setter' flag set to something funny: setter=$setter, typename=$typeName";
			}
		} else {
			pexpand($out, ["Type:setter"], $exCfg);
		}
	}
}

sub scanAPIF {
	my ($sources) = @_;

	my @funcs;
	for my $source (@$sources) {
		open my $fd, $source or die "Failed to open $source";
		while (<$fd>) {
			next unless /^\s*APIF/;
			my $line = $_;
			chomp($line);
			my $bracket = '{';
			$line =~ s/\s*$bracket?\s*$//;
			$line =~ s/^\s*APIF\s*//;
			push @funcs, $line;
		}
		close($fd);
	}
	my %definedCalls;
	for my $func (@funcs) {
		die "INTERNAL ERROR '$func'" unless $func =~ /([[:alpha:]][[:alnum:]]*)_([[:alpha:]][[:alnum:]]*)/;
		my $className  = $1;
		my $methodName = $2;
		my $subhash = $definedCalls{$className};
		if (!defined($subhash)) {
			$subhash = {};
			$definedCalls{$className} = $subhash;
		}
		$subhash->{$methodName} = 1;
	}

	$gApif = {funcs=>\@funcs, definedCalls=>\%definedCalls};
}

sub writeAPIFForType {
	my ($out, $type) = @_;
	for my $line (@{$gApif->{funcs}}) {
		my ($t) = ($line =~ /^\s*\S+\s*\**\s*([^_\s]+)/);
		die "Bad APIF line '$line'" unless defined($t);
		if ($t eq $type) {
			print {$out} <<END;
$line;
END
		}
	}
	print {$out} "\n";
}

sub scanUntilAtEnd {
	my ($cfg) = @_;
	my $inp  = $cfg->{inp};
	my $line = $cfg->{line};
	my $start = $line;
	my $found = 0;
	my @text;
	while (<$inp>) {
		$line++;
		chomp;

		## Remove C++ comments from the line
		s[//.*][];

		if (/^\@end/) {
			$found = 1;
			last;
		}
		if (/^\@/) {
			die "Failed to find \@end while processing \@type at line $start and failing on line $line";
		}
		push @text, $_;
	}
	if (!$found) {
		die "Failed to find \@end: found EOF started at line $start";
	}
	$cfg->{line} = $line;
	return \@text;
}

sub scanInDotH {
	my ($cfg) = @_;
	my ($file, $typeCallback, $interfaceCallback, $nothingCallback) = ($cfg->{file}, $cfg->{typeCallback}, $cfg->{interfaceCallback}, $cfg->{nothingCallback});
	die "INTERNAL ERROR" unless defined($file) && defined($typeCallback) && defined($nothingCallback);
	open my $inp, "<", $file or die "Failed to open $file";
	$cfg->{inp}  = $inp;
	$cfg->{line} = 0;
	while (<$inp>) {
		$cfg->{line}++;
		chomp;
				
		if (/^\@type/) {
			$cfg->{lastAtType} = $cfg->{line};
			my $text = scanUntilAtEnd($cfg);
			$typeCallback->($cfg, $text);
		} elsif (/^\@interface/) {
			$cfg->{lastAtType} = $cfg->{line};
			my $text = scanUntilAtEnd($cfg);
			$interfaceCallback->($cfg, $text);
		} else {
			$nothingCallback->($cfg, $_);
		}
	}
	delete($cfg->{inp});
	delete($cfg->{line});
	close($inp);
}

sub collectClassFromAtType {
	my ($cfg, $lines) = @_;
	my $text = join("\n", @$lines);
	my $classes = $cfg->{classes};
	if (!defined($classes)) {
		$classes = [];
		$cfg->{classes} = $classes;
	}
	eval {
		my $class = decode_json($text);
		$class->{srcFile} = $cfg->{file};
		push @$classes, $class;
	};
	if ($@) {
		die "Failed to decode json for type in file $cfg->{file}, starting at $cfg->{lastAtType}\n";
	}
}

sub collectInterfaceFromAtType {
	my ($cfg, $lines) = @_;
	my $text = join("\n", @$lines);
	my $interfaces = $cfg->{interfaces};
	if (!defined($interfaces)) {
		$interfaces = [];
		$cfg->{interfaces} = $interfaces;
	}
	eval {
		my $interface = decode_json($text);
		$interface->{srcFile} = $cfg->{file};
		push @$interfaces, $interface;
	};
	if ($@) {
		die "Failed to decode json for interface in file $cfg->{file}, starting at $cfg->{lastAtType}\n";
	}	
}


sub collectAllClassesFromFile {
	my ($file) = @_;
	my $cfg = {file=>$file, typeCallback=>\&collectClassFromAtType, interfaceCallback=>\&collectInterfaceFromAtType, nothingCallback=>sub {}};
	scanInDotH($cfg);
	return {classes=>$cfg->{classes}, interfaces=>$cfg->{interfaces}};
}

sub crossrefClassesAndInterfaces {
	my ($interfaces, $classes) = @_;

	for my $interfaceName (keys(%$interfaces)) {
		print "Doing $interfaceName ", defined($interfaces->{$interfaceName}{fields}), "\n";
		if (!defined($interfaces->{$interfaceName}{fields})) {
			$interfaces->{$interfaceName}{fields} = [];
		}
		unshift @{$interfaces->{$interfaceName}{fields}}, {name=>"itype", type=>"int"}; 
	}
	print Dumper($interfaces),"\n";


	for my $className (keys(%$classes)) {
		next unless defined($classes->{$className}{implements});
		## First, add the itype field to the class
		unshift @{$classes->{$className}{fields}}, {name=>"itype", type=>"int"}; 

		## Now add each class that implements interface ifc, to the implementedBy list of ifc.
		for my $ifc (@{$classes->{$className}{implements}}) {
			die "Class $className implements an interface that doesn't exist" unless defined($interfaces->{$ifc});
			my $interface     = $interfaces->{$ifc};
			my $implementedBy = $interface->{implementedBy};
			if (!defined($implementedBy)) {
				$implementedBy = {};
				$interface->{implementedBy} = $implementedBy;
			}
			$implementedBy->{$className} = 1;
		}
	}
}


sub writeClassFromAtType {
	my ($cfg, $lines) = @_;
	my $text = join("\n", @$lines);
	my $class;
	eval {
		$class = decode_json($text);
	};
	if ($@) {
		die "Failed to decode json for type starting in file $cfg->{srcFile} at line $cfg->{lastAtType}\n";
	}
	my $storedClass = $gAllClassesAndInterfaces->{classes}{$class->{typeName}};
	die "INTERNAL ERROR: didn't find stored type $class->{typeName}" unless defined($storedClass);
	$class = $storedClass;

	my $out       = $cfg->{out};
	my $file      = $cfg->{file};
	writeWarning($out, $file);
	writeStruct($out, $class);
	pexpand($out, ['Type:newUninitialized'], {TYPENAME => $class->{typeName}}) unless $class->{noNewUnitialized};
	if (defined($class->{preAccessor})) {
		$class->{preAccessor}($out);
	}
	writeAccessor($out, $class);
	if (defined($class->{postAccessor})) {
		$class->{postAccessor}($out);
	}
	if (defined($class->{argDeclare})) {
		writeArgDeclare($out, $class);
	}
	writeAPIFForType($out, $class->{typeName});
	if (defined($class->{containers})) {
		for my $cont (@{$class->{containers}}) {
			if ($cont->{type} eq 'array') {
				writeArray($out, $cont);
			} else {
				die "Unknown container type $cont->{type}";
			}
		}
	}
	print {$out} "\n";
}

sub writeInterfaceFromAtType {
	my ($cfg, $lines) = @_;
	my $text = join("\n", @$lines);
	my $interface;
	eval {
		$interface = decode_json($text);
	};
	if ($@) {
		die "Failed to decode json for interface starting in file $cfg->{srcFile} at line $cfg->{lastAtType}\n";
	}
	my $storedInterface = $gAllClassesAndInterfaces->{interfaces}{$interface->{typeName}};
	die "INTERNAL ERROR: didn't find stored interface $interface->{typeName}" unless defined($storedInterface);
	$interface = $storedInterface;

	my $out       = $cfg->{out};
	my $file      = $cfg->{file};
	writeWarning($out, $file);
	writeStruct($out, $interface);
}

sub writeOrdinaryLine {
	my ($cfg, $line) = @_;
	my $out = $cfg->{out};
	print {$out} $line, "\n";
}

sub writeAllClassesFromFile {
	my ($out, $file) = @_;
	my $cfg = {out=>$out, file=>$file, typeCallback=>\&writeClassFromAtType, interfaceCallback=>\&writeInterfaceFromAtType, nothingCallback=>\&writeOrdinaryLine};
	scanInDotH($cfg);
}

sub writeArray {
	my ($out, $arrayCfg) = @_;
	my $TYPENAME    = $arrayCfg->{typename};
	my $ELEMNAME_NS = $arrayCfg->{elemname};
	my $CLEARER     = $arrayCfg->{clearer};
	my $ELEMNAME    = "";
	if ($ELEMNAME_NS !~ /\*$/) {
		$ELEMNAME = "$ELEMNAME_NS ";
	} else {
		$ELEMNAME = $ELEMNAME_NS;
	}
	if (!defined($CLEARER)) {
		$CLEARER = "NULL";
	}
	my %use0 = (int=>1, double=>1);
	my $ELEMZERO = "{0}";
	if ($use0{$ELEMNAME_NS}) {
		$ELEMZERO = "0";
	}

	##
	## Setup base keys
	##
	my @keys = ("Array:struct", 'ArrayIter:struct', 'Array:new', 'Array:init', 'Array:clear', 'Array:free',
				'Array:truncate', 'Array:len',  'Array:get', 'Array:getp', 'Array:set', 'Array:setp',
				'Array:pop', 'Array:push', 'Array:pushp', 'Array:insert', 'Array:insertp', 'Array:remove',
				'Array:removeN', 'Array:fit', 'Array:last', 'Array:changeLength', 'Array:foreach', 'Array:rforeach',
				'Array:loop', 'Array:rloop');

	my $binarySearch = $arrayCfg->{binarySearch};
	if (defined($binarySearch)) {
		my $needslice = 0;
		for my $b (@$binarySearch) {
			if ($b->{multi}) {
				push @keys, "Array:slice", "Array:declareSlice", "Array:sliceEmpty", "Array:sliceForeach", "Array:rsliceForeach";						
				last;
			}
		}
	}
	
	my $dict = {TYPENAME=>$TYPENAME, ELEMNAME_NS=>$ELEMNAME_NS, ELEMNAME=>$ELEMNAME, CLEARER=>$CLEARER, ELEMZERO=>$ELEMZERO};
	pexpand($out, \@keys, $dict);

	if (defined$binarySearch) {
		my $usedEmpty = 0;
		for my $b (@$binarySearch) {
			my $COMPARE = $b->{compare} or die "Failed to define compare function for binarySearch";
			my $TAG     = $b->{tag};
			my $domulti = $b->{multi};
			if (!$TAG) {
				die "Too many binarySearch clauses without a tag" if $usedEmpty;
				$usedEmpty = 1;
				$TAG = "";
			}
			$dict->{COMPARE} = $COMPARE;
			$dict->{TAG}     = $TAG;

			my @keys = ('Array:binInsert', 'Array:binRemove', 'Array:sort');
			if ($domulti) {
				$dict->{MULTI} = "true";
				push @keys, "Array:binSearchSliceReturn";
			} else {
				$dict->{MULTI} = "false";
				push @keys, "Array:binSearchElemReturn";
			}
			pexpand($out, \@keys, $dict);
		}
	}
}

sub filesInDirectory {
	my ($srcDir) = @_;
	$srcDir =~ s[/$][];
	my @lines = backtick "ls $srcDir/*";
	my @headerTemplates;
	my @cFiles;
	my @cTemplates;
	my %isCTemplate;
	for my $line (@lines) {
		$line =~ s/^\s*//;
		$line =~ s/\s*$//;
		if ($line =~ /\.in.h$/) {
			push @headerTemplates, $line;
		} elsif ($line =~ /\.in\.c$/) {
			my $short = $line;
			die "INTERNAL ERROR" unless $short =~ m{([^/]+)\.in\.c};
			$isCTemplate{$line} = 1;
			push @cTemplates, $line;
		} elsif ($line =~ /\.c$/) {
			my $short = $line;
			die "INTERNAL ERROR" unless $line =~ m{([^/]+)\.c};
			if (!$isCTemplate{$line}) {
				push @cFiles, $line;	
			}
		}
	}
	return (\@headerTemplates, \@cFiles, \@cTemplates);
}

sub collectAllClasses {
	my ($headerTemplates) = @_;
	my %classes;
	my %classOrder;
	my %interfaces;
	my %interfaceOrder;
	for my $header (@$headerTemplates) {
		my $classesAndInterfaces = collectAllClassesFromFile($header);	
		my $headerClasses        = $classesAndInterfaces->{classes};
		my $headerInterfaces     = $classesAndInterfaces->{interfaces};

		$classOrder{$header}     = [];
		for my $class (@$headerClasses) {
			if (defined($classes{$class->{typeName}})) {
				my $otherClass = $classes{$class->{typeName}};
				die "Found the same type typeName in two files: '$otherClass->{srcFile}' and '$class->{srcFile}'";
			}
			$classes{$class->{typeName}} = $class;
			push @{$classOrder{$header}}, $class->{typeName};
		}

		$interfaceOrder{$header} = [];
		for my $interface (@$headerInterfaces) {
			if (defined($interfaces{$interface->{typeName}})) {
				my $otherInterface = $interfaces{$interface->{typeName}};
				die "Found the same interface typeName in two files: '$otherInterface->{srcFile}' and '$interface->{srcFile}'";
			}
			$interfaces{$interface->{typeName}} = $interface;
			push @{$interfaceOrder{$header}}, $interface->{typeName};
		}
	}

	$gAllClassesAndInterfaces = {classes => \%classes, classOrder => \%classOrder, interfaces=>\%interfaces, interfaceOrder=>\%interfaceOrder};
}

sub processTemplateHeader {
	my ($out, $templateHeader) = @_;
	my $cFile = $templateHeader;
	if ($cFile !~ s/\.in\.h$/.c/) {
		die "generate.pl was passed a bad file name '$templateHeader'";
	}
	
	writeAllClassesFromFile($out, $templateHeader);
}


my %extraUsedCalls = (
	## These guys are embedded in a define in a header
	PortRef => {port => 1, outlet => 1},
);

my $gUsedCalls;
sub collectUsedCalls {
	my ($cFiles) = @_;
	my %used = %extraUsedCalls;
	for my $source (@$cFiles) {
		open my $fd, $source or die "Failed to open $source";
		while (<$fd>) {
			next if /^\s*APIF/;
			
			while(/([[:alpha:]][[:alnum:]]*)_([[:alpha:]][[:alnum:]]*)(?:\b|$)\(/ag) {
				my $className  = $1;
				my $methodName = $2;
				my $methods    = $used{$className};
	  			if (!defined($methods)) {
	  				$methods = {};
	  				$used{$className} = $methods;
	  			}
	  			$methods->{$methodName} = 1;
			}	 
		}
		close($fd);
	}
	$gUsedCalls = \%used;
}


my @templates = (
	{
		key =>    'Type:newUninitialized',
		symbol => '${TYPENAME}_newUninitialized',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@#define ${TYPENAME}_newUninitialized() ((${TYPENAME}*)sysmem_newptrclear(sizeof(${TYPENAME})))		
ENDxxxxxxxxxx
	},

	{
		key =>    'Type:argDeclare',
		symbol => '${TYPENAME}_declare',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@#define ${TYPENAME}_declare(name, ${ARGS}) ${TYPENAME} name = ${STRUCT}
ENDxxxxxxxxxx
	},

	{
		key =>    'Type:getter',
		symbol => '${TYPENAME}_${FIELDNAME}',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@static inline ${STYPE}${TYPENAME}_${FIELDNAME}(${TYPENAME} *self){return ${MAYBEAMPER}self->${FIELDNAME};}
ENDxxxxxxxxxx
	},

	{
		key =>    'Type:setter',
		symbol => '${TYPENAME}_${SETNAME}',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@static inline void ${TYPENAME}_${SETNAME}(${TYPENAME} *self, ${STYPE}value){self->${FIELDNAME} = value;}
ENDxxxxxxxxxx
	},


	{
		key =>    'Array:struct',
		symbol => '',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@typedef struct ${TYPENAME}_t {
			@	Array body;
			@} ${TYPENAME};
ENDxxxxxxxxxx
	},


	{
		key =>    'ArrayIter:struct',
		symbol => '',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@typedef struct ${TYPENAME}Iter_t {
			@   ${TYPENAME} *arr;
			@   int index;
			@   bool last;
			@   ${ELEMNAME}*var;
			@} ${TYPENAME}Iter;
ENDxxxxxxxxxx
	},

	{
		key =>    'Array:new',
		symbol => '${TYPENAME}_new',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@static inline ${TYPENAME} *${TYPENAME}_new(int nelems) {
			@	return (${TYPENAME}*)Array_new(nelems, sizeof(${ELEMNAME_NS}), (Array_clearElement)${CLEARER});
			@}
ENDxxxxxxxxxx
	},

	{
		key =>    'Array:init',
		symbol => '${TYPENAME}_init',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@static inline void ${TYPENAME}_init(${TYPENAME} *arr, int nelems) {
			@	Array_init((Array*)arr, nelems, sizeof(${ELEMNAME_NS}), (Array_clearElement)${CLEARER});
			@}
ENDxxxxxxxxxx
	},


	{
		key =>    'Array:clear',
		symbol => '${TYPENAME}_clear',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@static inline void ${TYPENAME}_clear(${TYPENAME} *arr) {
			@	Array_clear((Array*)arr);
			@	${TYPENAME} zero = {{0}};
			@	*arr = zero;
			@}
ENDxxxxxxxxxx
	},

	{
		key =>    'Array:free',
		symbol => '${TYPENAME}_free',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@static inline void ${TYPENAME}_free(${TYPENAME} *arr) {
			@	Array_free((Array*)arr);
			@}
ENDxxxxxxxxxx
	},

	{
		key =>    'Array:truncate',
		symbol => '${TYPENAME}_truncate',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@static inline void ${TYPENAME}_truncate(${TYPENAME} *arr) {
			@	Array_truncate((Array*)arr);
			@}
ENDxxxxxxxxxx
	},


	{
		key =>    'Array:len',
		symbol => '${TYPENAME}_len',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@static inline int ${TYPENAME}_len(${TYPENAME} *arr) {
			@	return Array_len((Array*)arr);
			@}
ENDxxxxxxxxxx
	},


	{
		key =>    'Array:get',
		symbol => '${TYPENAME}_get',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@static inline ${ELEMNAME}${TYPENAME}_get(${TYPENAME} *arr, int index, Error *err) {
			@	${ELEMNAME_NS} v = ${ELEMZERO};
			@	Array_getCheck(arr, index, v, err);
			@	memmove(&v, Array_get((Array*)arr, index), Array_elemSize((Array*)arr));
			@	return v;
			@}
ENDxxxxxxxxxx
	},

	{
		key =>    'Array:getp',
		symbol => '${TYPENAME}_getp',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@static inline ${ELEMNAME}*${TYPENAME}_getp(${TYPENAME} *arr, int index, Error *err) {
			@	Array_getCheck(arr, index, NULL, err);
			@	return (${ELEMNAME}*)Array_get((Array*)arr, index);
			@}
ENDxxxxxxxxxx
	},


	{
		key =>    'Array:set',
		symbol => '${TYPENAME}_set',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@static inline void ${TYPENAME}_set(${TYPENAME} *arr, int index, ${ELEMNAME}elem, Error *err) {
			@	Array_setCheck(arr, index, err);
			@	Array_set((Array*)arr, index, (char*)&elem);
			@}
ENDxxxxxxxxxx
	},

	{
		key =>    'Array:setp',
		symbol => '${TYPENAME}_setp',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@static inline void ${TYPENAME}_setp(${TYPENAME} *arr, int index, ${ELEMNAME}*elem, Error *err) {
			@	Array_setCheck(arr, index, err);
			@	Array_set((Array*)arr, index, (char*)elem);
			@}
ENDxxxxxxxxxx
	},

	{
		key =>    'Array:pop',
		symbol => '${TYPENAME}_pop',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@static inline void ${TYPENAME}_pop(${TYPENAME} *arr, Error *err) {
			@	Array_popNCheck(arr, 1, err);
			@	Array_popN((Array*)arr, 1);
			@}
ENDxxxxxxxxxx
	},

	{
		key =>    'Array:push',
		symbol => '${TYPENAME}_push',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@static inline void ${TYPENAME}_push(${TYPENAME} *arr, ${ELEMNAME}elem) {
			@	${ELEMNAME_NS} *p = (${ELEMNAME}*)Array_pushN((Array*)arr, 1);
			@	*p = elem;
			@	return; 
			@}			
ENDxxxxxxxxxx
	},

	{
		key =>    'Array:pushp',
		symbol => '${TYPENAME}_pushp',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@static inline void ${TYPENAME}_pushp(${TYPENAME} *arr, ${ELEMNAME}*elem) {
			@	${ELEMNAME_NS} *p = (${ELEMNAME}*)Array_pushN((Array*)arr, 1);
			@	*p = *elem;
			@	return; 
			@}
ENDxxxxxxxxxx
	},

	{
		key =>    'Array:insert',
		symbol => '${TYPENAME}_insert',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@static inline void ${TYPENAME}_insert(${TYPENAME} *arr, int index, ${ELEMNAME}elem, Error *err) {
			@	Array_insertNCheck(arr, index, 1, err);
			@	${ELEMNAME_NS} *p = (${ELEMNAME}*)Array_insertN((Array*)arr, index, 1);
			@	*p = elem;
			@}
ENDxxxxxxxxxx
	},

	{
		key =>    'Array:insertp',
		symbol => '${TYPENAME}_insertp',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@static inline void ${TYPENAME}_insertp(${TYPENAME} *arr, int index, ${ELEMNAME}*elem, Error *err) {
			@	Array_insertNCheck(arr, index, 1, err);
			@	${ELEMNAME_NS} *p = (${ELEMNAME}*)Array_insertN((Array*)arr, index, 1);
			@	*p = *elem;
			@}			
ENDxxxxxxxxxx
	},

	{
		key =>    'Array:remove',
		symbol => '${TYPENAME}_remove',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@static inline void ${TYPENAME}_remove(${TYPENAME} *arr, int index, Error *err) {
			@	Array_removeNCheck(arr, index, 1, err);
			@	Array_removeN((Array*)arr, index, 1);
			@}	
ENDxxxxxxxxxx
	},

	{
		key =>    'Array:removeN',
		symbol => '${TYPENAME}_removeN',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@static inline void ${TYPENAME}_removeN(${TYPENAME} *arr, int index, int N, Error *err) {
			@	Array_removeNCheck(arr, index, N, err);
			@	Array_removeN((Array*)arr, index, N);
			@}
ENDxxxxxxxxxx
	},

	{
		key =>    'Array:fit',
		symbol => '${TYPENAME}_fit',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@static inline void ${TYPENAME}_fit(${TYPENAME} *arr) {
			@	Array_fit((Array*)arr);
			@}
ENDxxxxxxxxxx
	},

	{
		key =>    'Array:last',
		symbol => '${TYPENAME}_last',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@static inline int ${TYPENAME}_last(${TYPENAME} *arr) {
			@	return Array_len((Array*)arr)-1;
			@}			
ENDxxxxxxxxxx
	},	

	{
		key =>    'Array:changeLength',
		symbol => '${TYPENAME}_changeLength',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@static inline void ${TYPENAME}_changeLength(${TYPENAME} *arr, int newLength) {
			@	Array_changeLength((Array*)arr, newLength);
			@}						
ENDxxxxxxxxxx
	},	

	{
		key =>    'ArrayIter:next',
		symbol => '${TYPENAME}Iter_next',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@static inline bool ${TYPENAME}Iter_next(${TYPENAME}Iter *iterator) {
			@	return ArrayIter_next((ArrayIter*)iterator);
			@}
ENDxxxxxxxxxx
	},	

	{
		key =>    'ArrayIter:previous',
		symbol => '${TYPENAME}Iter_previous',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@static inline bool ${TYPENAME}Iter_previous(${TYPENAME}Iter *iterator) {
			@	return ArrayIter_previous((ArrayIter*)iterator);
			@}			
ENDxxxxxxxxxx
	},	

	{
		key    =>    'ArrayIter:declare',
		symbol => '${TYPENAME}Iter_declare',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@#define ${TYPENAME}Iter_declare(var, arr)  ${TYPENAME}Iter var = {arr, -1, false, NULL}			
ENDxxxxxxxxxx
	},	
		
	{
		key =>    'ArrayIter:rdeclare',
		implies => ['Array:len'],
		symbol => '${TYPENAME}Iter_rdeclare',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@#define ${TYPENAME}Iter_rdeclare(var, arr)  ${TYPENAME}Iter var = {arr, ${TYPENAME}_len(arr), false, NULL}			
ENDxxxxxxxxxx
	},	

	{
		key     =>  'Array:foreach',
		implies => ["ArrayIter:declare", "ArrayIter:next"],
		symbol  => '${TYPENAME}_foreach',
		tmpl    => <<'ENDxxxxxxxxxx', 
			@#define ${TYPENAME}_foreach(var, arr)  for (${TYPENAME}Iter_declare(var, arr); ${TYPENAME}Iter_next(&var); )			
ENDxxxxxxxxxx
	},	

	{
		key =>    'Array:rforeach',
		implies => ["ArrayIter:rdeclare", "ArrayIter:previous"],
		symbol => '${TYPENAME}_rforeach',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@#define ${TYPENAME}_rforeach(var, arr)  for (${TYPENAME}Iter_rdeclare(var, arr); ${TYPENAME}Iter_previous(&var); )			
ENDxxxxxxxxxx
	},	

	{
		key =>    'Array:loop',
		implies => ["ArrayIter:declare", "ArrayIter:next"],
		symbol => '${TYPENAME}_loop',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@#define ${TYPENAME}_loop(var, arr) ${TYPENAME}Iter_declare(var, arr); while (${TYPENAME}Iter_next(&var)) 
ENDxxxxxxxxxx
	},

	{
		key =>    'Array:rloop',
		implies => ["ArrayIter:rdeclare", "ArrayIter:previous"],
		symbol => '${TYPENAME}_rloop',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@#define ${TYPENAME}_rloop(var, arr)    ${TYPENAME}Iter_rdeclare(var, arr); while (${TYPENAME}Iter_previous(&var)) 			
ENDxxxxxxxxxx
	},


	{
		key =>    'Array:slice',
		symbol => '',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@typedef struct ${TYPENAME}Slice_t {
			@	int len;
			@	${ELEMNAME}*data;
			@	int index;
			@	${ELEMNAME}*var;
			@} ${TYPENAME}Slice;
ENDxxxxxxxxxx
	},

	{
		key =>    'Array:declareSlice',
		symbol => '${TYPENAME}_declareSlice',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@#define ${TYPENAME}_declareSlice(name) ${TYPENAME}Slice name = {0}			
ENDxxxxxxxxxx
	},

	{
		key =>    'Array:sliceEmpty',
		symbol => '${TYPENAME}_sliceEmpty',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@#define ${TYPENAME}_sliceEmpty(slice) (slice.data == NULL)
ENDxxxxxxxxxx
	},	

	{
		key =>    'Array:sliceForeach',
		symbol => '${TYPENAME}_sliceForeach',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@#define ${TYPENAME}_sliceForeach(slice) for (slice.index=0, slice.var=slice.data; slice.index < slice.len; slice.index++, slice.var++)
ENDxxxxxxxxxx
	},	

	{
		key =>    'Array:rsliceForeach',
		symbol => '${TYPENAME}_rsliceForeach',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@#define ${TYPENAME}_rsliceForeach(slice) for (slice.index=slice.len-1, slice.var = slice.data + slice.index*sizeof(${ELEMNAME_NS}); \\
			@								               slice.index >= 0; slice.index--, slice.var--)
ENDxxxxxxxxxx
	},	

	{
		key =>    'Array:binInsert',
		symbol => '${TYPENAME}_binInsert${TAG}',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@static inline void ${TYPENAME}_binInsert${TAG}(${TYPENAME} *arr, ${ELEMNAME}elem) {
			@	Array_binInsert((Array*)arr, (char*)&elem, (Array_compare)${COMPARE}, ${MULTI});
			@}			
ENDxxxxxxxxxx
	},	

	{
		key =>    'Array:binRemove',
		symbol => '${TYPENAME}_binRemove${TAG}',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@static inline void ${TYPENAME}_binRemove${TAG}(${TYPENAME} *arr, ${ELEMNAME}elem) {
			@	Array_binRemove((Array*)arr, (char*)&elem, (Array_compare)${COMPARE}, ${MULTI});
			@}		
ENDxxxxxxxxxx
	},	

	{
		key =>    'Array:sort',
		symbol => '${TYPENAME}_sort${TAG}',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@static inline void ${TYPENAME}_sort${TAG}(${TYPENAME} *arr) {
			@	Array_sort((Array*)arr, (Array_compare)${COMPARE});
			@}				
ENDxxxxxxxxxx
	},	

	{
		key =>    'Array:binSearchSliceReturn',
		symbol => '${TYPENAME}_binSearch${TAG}',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@static inline ${TYPENAME}Slice ${TYPENAME}_binSearch${TAG}(${TYPENAME} *arr, ${ELEMNAME}elem) {
			@	${TYPENAME}Slice slice = {0};
			@	Array_binSearch((Array*)arr, (char*)&elem, (Array_compare)${COMPARE}, (ArraySlice*)&slice);
			@	return slice;
			@}
ENDxxxxxxxxxx
	},	

	{
		key =>    'Array:binSearchElemReturn',
		symbol => '${TYPENAME}_binSearch${TAG}',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@static inline ${ELEMNAME}*${TYPENAME}_binSearch${TAG}(${TYPENAME} *arr, ${ELEMNAME}elem) {
			@	return (${ELEMNAME}*)Array_binSearch((Array*)arr, (char*)&elem, (Array_compare)${COMPARE}, NULL);
			@}
ENDxxxxxxxxxx
	},	

	{
		key =>    'Predefined:struct',
		symbol => '',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@struct ${TYPENAME}_t;
			@typedef struct ${TYPENAME}_t ${TYPENAME};
ENDxxxxxxxxxx
	},
	{
		key =>    'Predefined:alias',
		symbol => '',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@typedef struct ${ALIAS}_t ${TYPENAME};
ENDxxxxxxxxxx
	},

	{
		key =>    'Struct:head',
		symbol => '',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@struct ${TYPENAME}_t
			@{
ENDxxxxxxxxxx
	},

	{
		key =>    'Struct:field',
		symbol => '',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@    ${STYPE}${NAME};
ENDxxxxxxxxxx
	},

	{
		key =>    'Struct:tail',
		symbol => '',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@};
ENDxxxxxxxxxx
	},

);
my %templateMap = map {$_->{key} => $_} @templates;

sub expand {
	my ($inputKeys, $inputDictionary) = @_;
	
	my $expandVar = sub {
		$_[0] =~ s/\$\{(\w+)\}/exists $inputDictionary->{$1} ? $inputDictionary->{$1} : '<EXPAND_FAIL>'/eg;
		return $_[0];
	};

	## Filter based on gUsedCalls. Also add any implied keys into keysToProcess
	my @keysToProcess;
	my %implied;
	my %seen;
	for my $requestedKey (@$inputKeys) {
		my $hsh = $templateMap{$requestedKey};
		if (!defined($hsh)) {
			die "Failed to find template key '$requestedKey'";
		}
		my $symbol = $hsh->{symbol};
		if ($symbol && defined($gUsedCalls)) {
			$symbol = $expandVar->($symbol);
			my ($className, $methodName) = split '_', $symbol;
			die "INTERNAL ERROR" unless defined($methodName);
			next unless $gUsedCalls->{$className}{$methodName};
		}

		next if $seen{$requestedKey};
		$seen{$requestedKey} = 1;

		push @keysToProcess, $requestedKey;

		my $topImplies = $hsh->{implies};
		if (defined($topImplies)) {
			my %implieds = map {$_ => 1} @$topImplies;
			while (%implieds) {
				my @impliedKeys = keys(%implieds);
				%implieds       = ();
				for my $imp (@impliedKeys) {
					next if $seen{$imp};
					$seen{$imp} = 1;
					push @keysToProcess, $imp;
					my $hsh = $templateMap{$imp};
					next unless defined($hsh);
					my $nimplies = $hsh->{implies};
					next unless defined($nimplies);
					for my $nimp (@$nimplies) {
						next if $seen{$nimp};
						$seen{$nimp} = 1;
						$implieds{$nimp} = 1;
					}
				}
			}
		}
	}
	
	my %special = ("Array:struct" => 1, "Array:slice" => 2, "ArrayIter:struct" => 3);
	my $srt = sub {
		my $ls = $special{$a};
		my $rs = $special{$b};
		if (defined($ls) && defined($rs)) {
			return $ls <=> $rs;
		} elsif (!defined($ls) && defined($rs)) {
			return 1;
		} elsif (defined($ls) && !defined($rs)) {
			return -1;
		}
		return $a cmp $b;
	};
	@keysToProcess = sort {$srt->()} @keysToProcess;


	## Now do the expansion of all desiered keys
	my %results;
	for my $requestedKey (@keysToProcess) {
		my $hsh = $templateMap{$requestedKey};
		my $tmpl = $hsh->{tmpl};
		$tmpl =~ s/^\s*\@//mg;
		$tmpl = $expandVar->($tmpl);
		$tmpl =~ s/\t/    /g;
		$results{$requestedKey} = $tmpl;
	}

	return \@keysToProcess, \%results;
}

sub pexpand {
	my ($out, $inputKeys, $inputDictionary) = @_;
	my ($outputKeys, $res) = expand($inputKeys, $inputDictionary);
	for my $key (@$outputKeys) {
		my $t = $res->{$key};
		next unless defined($t);
		print {$out} $t;
	}
}

sub writeInterfaceH {
	my ($allClasses, $srcDir) = @_; 
	my %classes    = %{$allClasses->{classes}};
	my %classOrder = %{$allClasses->{classOrder}};
	my $outFile = "$srcDir/interface.h";
	open my $fd, ">", $outFile or die "Failed to open $outFile";
	my $nextIType = 10;
	for my $file (keys(%classOrder)) {
		printf {$fd} "// From file '%s'\n", $file;
		my @order = @{$classOrder{$file}};
		for my $className (@order) {
			my $class = $classes{$className};
			next unless defined($class->{implements});
			printf {$fd} "#define Interface_type$className $nextIType\n";
			$nextIType++;
		}
	}
	close($fd);
}

sub main {
	my ($srcDir) = @ARGV;
	die "generate requires 1 argument" unless @ARGV == 1;
	my ($templateHeaders, $cFiles, $cTemplates) = filesInDirectory($srcDir);
	if (@$templateHeaders <= 0) {
		die "No templates found in directory $srcDir"
	}

	collectAllClasses($templateHeaders);
	crossrefClassesAndInterfaces($gAllClassesAndInterfaces->{interfaces}, $gAllClassesAndInterfaces->{classes});
	# print Dumper($gAllClassesAndInterfaces->{classes}),"\n";
	# return;
	my $allCFiles = [@$cFiles, @$cTemplates];
	collectUsedCalls($allCFiles);
	scanAPIF($allCFiles);

	writeInterfaceH($gAllClassesAndInterfaces, $srcDir);
	
	
	for my $templateHeader (@$templateHeaders) {
		my $header = $templateHeader;
		if ($header !~ s/\.in\.h$/.h/) {
			die "generate.pl was passed a bad file name '$templateHeader'";
		}

		open my $out, ">", $header or die "Failed to open $header";
		writeWarning($out, $templateHeader);

		my $interfaceOrder = $gAllClassesAndInterfaces->{interfaceOrder}{$templateHeader};
		die "INTERNAL ERROR" unless defined($interfaceOrder);
		for my $interfaceName (@$interfaceOrder) {
			writePredefined($out, $gAllClassesAndInterfaces->{interfaces}{$interfaceName});		
		}

		my $classOrder = $gAllClassesAndInterfaces->{classOrder}{$templateHeader};
		die "INTERNAL ERROR" unless defined($classOrder);
		for my $className (@$classOrder) {
			writePredefined($out, $gAllClassesAndInterfaces->{classes}{$className});		
		}

		processTemplateHeader($out, $templateHeader, $gUsedCalls);
		close($out);
	}
}	

main();
