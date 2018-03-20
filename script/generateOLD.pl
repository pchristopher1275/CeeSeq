#!/usr/bin/perl
use strict;
use lib "$ENV{HOME}/CeeSeq/script/lib";
use JSON::Tiny qw(decode_json encode_json);
 use POSIX qw(strftime);
use Data::Dumper;

my $gVerbose                 = 1;
my $gAllClassesAndInterfaces = undef;
my $gApif                    = undef;
my $gUsedCalls               = undef;
my $gAcceptAllCalls          = 0;
my $gNow                     = strftime("%m/%d/%Y %H:%M:%S", localtime);
my $gNextItype               = 10;
my $gUndefinedItype          = $gNextItype++;

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
	my ($out, $artifact) = @_;
	if (defined($artifact->{aliasFor})) {
		pexpand($out, ['Predefined:alias'], {ALIAS=>$artifact->{aliasFor}, TYPENAME=>$artifact->{typeName}});
	} else {
		pexpand($out, ['Predefined:struct'], {TYPENAME=>$artifact->{typeName}});
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
		 		die "The 'getter' flag set to something funny: getter=$getter, typeName=$typeName";
		 	}
		} else {
			pexpand($out, ["Type:getter"], $exCfg);
		}
			
		if (defined($setter)) {	
			if ($setter ne 'none') {
				die "The 'setter' flag set to something funny: setter=$setter, typeName=$typeName";
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

sub writeApif {
	my ($out) = @_;
	for my $line (@{$gApif->{funcs}}) {
		print {$out} $line,";\n";
	}
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
	my ($file, $typeCallback, $interfaceCallback, $nothingCallback, $containerCallback) = (
		$cfg->{file}, $cfg->{typeCallback}, $cfg->{interfaceCallback}, $cfg->{nothingCallback}, $cfg->{containerCallback});
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
		} elsif (/^\@container/) {
			$cfg->{lastAtType} = $cfg->{line};
			my $text = scanUntilAtEnd($cfg);
			$containerCallback->($cfg, $text);
		} else {
			$nothingCallback->($cfg, $_);
		}
	}
	delete($cfg->{inp});
	delete($cfg->{line});
	close($inp);
}

sub filterDotInC {
	my ($inDotC) = @_;
	my $outFile = $inDotC;
	my $header  = $inDotC;
	die "INTERNAL ERROR: bad .in.c [1] file" unless $outFile =~ s[\.in\.c$][.c];
	die "INTERNAL ERROR: bad .in.c [2] file" unless $header  =~ s[\.in\.c$][\.in\.h];
	open my $inp, "<", $inDotC or die "Failed to open file $inDotC";
	open my $out, ">", $outFile or die "Failed to open file $inDotC";
	while (<$inp>) {
		print {$out} $_;
	}
	close($inp);

	my $interfaces     = $gAllClassesAndInterfaces->{interfaces};
	my $interfaceOrder = $gAllClassesAndInterfaces->{interfaceOrder}{$header};
	die "INTERNAL ERROR: didn't find iterfaceOrder for $header" unless defined($interfaceOrder);
	for my $interfaceName (@$interfaceOrder) {
		my $interface = $interfaces->{$interfaceName};
		for (my $methodIndex = 0; $methodIndex < @{$interface->{methods}}; $methodIndex++) {
		 	writeInterfaceMethod($out, $interface, $methodIndex, 0);
		}
	}
	close($out);
}

sub filterAllDotInC {
	my ($inDotCList) = @_;
	for my $inDotC (@$inDotCList) {
		filterDotInC($inDotC);
	}
}

sub reportBadJson {
	my ($cfg, $lines) = @_;
	my $commaEnd          = 0;
	my $closeBracketStart = 0;
	my $startLineNumber   = $cfg->{lastAtType};
	my $count             = 0;
	for my $line (@$lines) {
		$closeBracketStart = ($line =~ /^\s*[}\]]/);
		if ($closeBracketStart && $commaEnd) {
			printf {*STDERR} "Suspicious comma in file %s at line %d\n", $cfg->{file}, ($startLineNumber + $count);
		}
		$commaEnd = ($line =~ /,\s*$/);
		$count++;
	}
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
		$class->{itype}   = $gNextItype++;
		push @$classes, $class;
	};
	if ($@) {
		reportBadJson($cfg, $lines);
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
		reportBadJson($cfg, $lines);
		die "Failed to decode json for interface in file $cfg->{file}, starting at $cfg->{lastAtType}\n";
	}	
}

sub collectContainerFromAtType {
	my ($cfg, $lines) = @_;
	my $text = join("\n", @$lines);
	my $containers = $cfg->{containers};
	if (!defined($containers)) {
		$containers = [];
		$cfg->{containers} = $containers;
	}
	eval {
		my $container = decode_json($text);
		$container->{srcFile} = $cfg->{file};
		print Dumper($container), "<----\n";
		push @$containers, $containers;
	};
	if ($@) {
		reportBadJson($cfg, $lines);
		die "Failed to decode json for interface in file $cfg->{file}, starting at $cfg->{lastAtType}\n";
	}	

}

sub collectAllClassesFromFile {
	my ($file) = @_;
	my $cfg = {
		file=>$file, 
		typeCallback      => \&collectClassFromAtType, 
		interfaceCallback => \&collectInterfaceFromAtType,
		nothingCallback   => sub {}, 
		containerCallback => \&collectContainerFromAtType,
	};
	scanInDotH($cfg);
	print Dumper($cfg->{containers}), "XXX\n";
	return {classes=>$cfg->{classes}, interfaces=>$cfg->{interfaces}, containers => $cfg->{containers}};
}

sub crossrefClassesAndInterfaces {
	my ($interfaces, $classes) = @_;

	for my $interfaceName (keys(%$interfaces)) {
		if (!defined($interfaces->{$interfaceName}{fields})) {
			$interfaces->{$interfaceName}{fields} = [];
		}
		unshift @{$interfaces->{$interfaceName}{fields}}, {name=>"itype", type=>"int"}; 
	}

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
	pexpand($out, ['Type:newUninitialized'], {TYPENAME => $class->{typeName}}) unless $class->{noNewUnitialized};
	writeAccessor($out, $class);
	if (defined($class->{argDeclare})) {
		writeArgDeclare($out, $class);
	}
	if (defined($class->{containers})) {
		for my $cont (@{$class->{containers}}) {
			if ($cont->{type} eq 'array') {
				writeArray($out, $cont, 0);
			} else {
				die "Unknown container type $cont->{type}";
			}
		}
	}
	if (defined($class->{implements})) {
		my $h = {TYPENAME=>$class->{typeName}};
		for my $ifc (@{$class->{implements}}) {
			$h->{IFCNAME} = $ifc;
			pexpand($out, ['Interface:castTo', 'Interface:castFrom'], $h);
		}
	}
}

sub writeContainerFromAtType {
	my ($cfg, $lines) = @_;
	my $text = join("\n", @$lines);
	my $cont;
	eval {
		$cont = decode_json($text);
	};
	if ($@) {
		die "Failed to decode json for container starting in file $cfg->{srcFile} at line $cfg->{lastAtType}\n";
	}
	
	my $out = $cfg->{out};
	if ($cont->{type} eq 'array') {
		writeArray($out, $cont, 1);
		writeArray($out, $cont, 0);
	} else {
		die "Unknown container type $cont->{type}";
	}
}

sub writeInterfaceMethod {
	my ($out, $interface, $methodIndex, $justProto) = @_;
	my $ifcName       = $interface->{typeName};
	my $method        = $interface->{methods}[$methodIndex];
	my $itypeReceiver = $method->{itypeReceiver};
	my $defMethod     = $method->{defMethod};
	my $retVoid       = $method->{retVal} eq 'void';
	my $retPtr        = ($method->{retVal} =~ /\*/);
	my $absentOk      = defined($defMethod) ? 0 : $method->{absentOk};
	my $methodName    = $method->{name};
	my @methodArgs    = @{$method->{args}};

	my $forwardError = 1;
	if (@methodArgs == 0 || $methodArgs[$#methodArgs] !~ m[Error\s*\*]) {
		$forwardError = 0;
	} else {
		pop @methodArgs;
	}

	my @argWithVariable;
	my @variable;
	my $count = 1;
	for my $arg (@methodArgs) {
		if ($arg =~ /\*/) {
			push @argWithVariable, "${arg}a$count";
		} else {
			push @argWithVariable, "$arg a$count";
		}
		push @variable, "a$count";
		$count++;
	}
	if ($forwardError) {
		push @variable, "err"
	}

	my $typedArgs  = "";
	my $listArgs   = "";
	if (@argWithVariable > 0) {
		$typedArgs = ", " . join(", ", @argWithVariable);
		$listArgs  = ", " . join(", ", @variable);
	}
	
	
	my $cfg       = {
		IFCNAME       => $ifcName,
		TYPEDRECIEVER => $itypeReceiver ? "int itype" : "$ifcName *self",
		METHODNAME    => $methodName,
		DEFRET        => $retPtr ? "NULL" : '0',
		LISTARGS      => $listArgs,
		TYPEDARGS     => $typedArgs,
		RTYPE         => spaceAdjustType($method->{retVal}),
		ENDPROTO      => ";",
		SWITCHTARGET  => $itypeReceiver ? "itype" : "self->itype",
	};

	if ($justProto) {
		pexpand($out, ['Interface:proto'], $cfg);
		return;
	}

	$cfg->{ENDPROTO} = "";
	my ($defClassName, $defMethodName);
	if (defined($defMethod)) {
		($defClassName, $defMethodName) = split "_", $defMethod;
	}

	pexpand($out, ['Interface:proto', 'Interface:startFunction'], $cfg);
	my @implementedBy = sort {$a cmp $b} keys(%{$interface->{implementedBy}});
	for my $implementedBy (@implementedBy) {
		$cfg->{TYPENAME} = $implementedBy;
		if (!defined($defMethod) || $gApif->{definedCalls}{$implementedBy}{$methodName}) {
			$cfg->{CALLTYPENAME}     = $implementedBy;
			$cfg->{CALLMETHODNAME}   = $methodName;	
			$cfg->{CASTRECIEVER}     = $itypeReceiver ? "itype" : "($implementedBy*)self";
		} else {
			$cfg->{CALLTYPENAME}     = $defClassName;
			$cfg->{CALLMETHODNAME}   = $defMethodName;	
			$cfg->{CASTRECIEVER}     = $itypeReceiver ? "itype" : "self";
		}
		
		if ($absentOk && !$gApif->{definedCalls}{$implementedBy}{$methodName}) {
			if ($retVoid) {
				pexpand($out, ['Interface:caseAbsentVoid'], $cfg);
			} else {
				pexpand($out, ['Interface:caseAbsent'], $cfg);
			}
		} else {
			if ($retVoid) {
				pexpand($out, ['Interface:caseVoid'], $cfg);
			} else {
				pexpand($out, ['Interface:case'], $cfg);
			}
		}
	}
	if ($retVoid) {
		pexpand($out, ['Interface:endFunctionVoid'], $cfg);
	} else {
		pexpand($out, ['Interface:endFunction'], $cfg);
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

	print {$out} "\n";
	my @itypes;
	for my $className (keys(%{$interface->{implementedBy}})) {
		push @itypes, $gAllClassesAndInterfaces->{classes}{$className}{itype};
	}
	@itypes = sort {$a <=> $b} @itypes;
	my $h = {IFCNAME => $interface->{typeName}, ITYPELIST=>join(", ", @itypes)};
	pexpand($out, ['Interface:foreachIType'], $h);
	writeAccessor($out, $interface);
	if (defined($interface->{argDeclare})) {
		writeArgDeclare($out, $interface);
	}
	if (defined($interface->{containers})) {
		for my $cont (@{$interface->{containers}}) {
			if ($cont->{type} eq 'array') {
				writeArray($out, $cont, 0);
			} else {
				die "Unknown container type $interface->{type}";
			}
		}
	}
}

sub writeOrdinaryLine {
	my ($cfg, $line) = @_;
	my $out = $cfg->{out};
	print {$out} $line, "\n";
}

sub writeAllClassesFromFile {
	my ($out, $file) = @_;
	my $cfg = {
		out=>$out, 
		file=>$file, 
		typeCallback=>\&writeClassFromAtType, 
		interfaceCallback=>\&writeInterfaceFromAtType, 
		nothingCallback=>\&writeOrdinaryLine,
		containerCallback=>\&writeContainerFromAtType,
	};
	scanInDotH($cfg);
}

sub writeArray {
	my ($out, $arrayCfg, $outputStructs) = @_;
	my $TYPENAME    = $arrayCfg->{typeName};
	my $ELEMNAME_NS = $arrayCfg->{elemName};
	my $CLEARER     = $arrayCfg->{clearer};
	my $ELEMNAME    = "";
	if ($ELEMNAME_NS !~ /\*$/) {
		$ELEMNAME = "$ELEMNAME_NS ";
	} else {
		$ELEMNAME = $ELEMNAME_NS;
	}
	my $ELEMNAME_NP = $ELEMNAME_NS;
	$ELEMNAME_NP =~ s/\*//g;
	my $ELEMPTR = "";
	while ($ELEMNAME_NS =~ /\*/ga) {
		$ELEMPTR .= "*"
	}
	$ELEMPTR .= "*";
	

	if (!defined($CLEARER)) {
		$CLEARER = "NULL";
	}
	my %use0 = (int=>1, double=>1);
	my $ELEMZERO = "{0}";
	if ($use0{$ELEMNAME_NS}) {
		$ELEMZERO = "0";
	}
	my $binarySearch = $arrayCfg->{binarySearch};

	my $needsSlice = 0;
	if (defined($binarySearch)) {
		my $needslice = 0;
		for my $b (@$binarySearch) {
			if ($b->{multi}) {
				$needsSlice = 1;
				last;
			}
		}
	}

	my $dict = {
		TYPENAME=>$TYPENAME, 
		ELEMNAME_NS=>$ELEMNAME_NS, 
		ELEMNAME=>$ELEMNAME, 
		CLEARER=>$CLEARER, 
		ELEMZERO=>$ELEMZERO,
		ELEMPTR=>$ELEMPTR,
		ELEMNAME_NP=>$ELEMNAME_NP,
	};

	if ($outputStructs) {
		my @keys = ("Array:struct", 'ArrayIt:struct');
		if ($needsSlice) {
			push @keys, "Array:slice";
		}
		pexpandNl($out, \@keys, $dict);
		return
	}

	##
	## Setup base keys
	##
	my @keys = ('Array:new', 'Array:init', 'Array:clear', 'Array:free',
				'Array:truncate', 'Array:len',  'Array:get', 'Array:getp', 'Array:set', 'Array:setp',
				'Array:pop', 'Array:push', 'Array:pushp', 'Array:insert', 'Array:insertp', 'Array:remove',
				'Array:removeN', 'Array:fit', 'Array:last', 'Array:changeLength', 'Array:foreach', 'Array:rforeach',
				'Array:loop', 'Array:rloop');

	push @keys, ('Array:each', 'Array:reach', 'Array:eachInsert', 'Array:eachInsertAfter', 
				 'Array:reachInsert', 'Array:reachInsertAfter', 'Array:eachIndexOf', 'Array:eachLast', 'Array:reachLast',
				 'Array:eachRemove', 'Array:reachRemove');

	if ($needsSlice) {
		push @keys, "Array:declareSlice", "Array:sliceEmpty", "Array:sliceForeach", "Array:rsliceForeach";
	}	
	
	pexpandNl($out, \@keys, $dict);
	if (defined($binarySearch)) {
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
			pexpandNl($out, \@keys, $dict);
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
	for my $line (@lines) {
		$line =~ s/^\s*//;
		$line =~ s/\s*$//;
		if ($line =~ /\.in.h$/) {
			push @headerTemplates, $line;
		} elsif ($line =~ /\.in\.c$/) {
			push @cTemplates, $line;
		} elsif ($line =~ /\.c$/) {
			push @cFiles, $line;
		}
	}
	my %templateHash = map {$_ => 1} @cTemplates;
	my @a;
	for my $cFile (@cFiles) {
		my $cTemplate = $cFile;
		die "INTERNAL ERROR" unless $cTemplate =~ s/\.c$/.in.c/;	
		if (!$templateHash{$cTemplate}) {
			push @a, $cFile;
		}
	}
	@cFiles = @a;

	return (\@headerTemplates, \@cFiles, \@cTemplates);
}

sub collectAllClasses {
	my ($headerTemplates) = @_;
	my %classes;
	my %classOrder;
	my %interfaces;
	my %interfaceOrder;
	my %artifacts;
	for my $header (@$headerTemplates) {
		my $classesAndInterfaces = collectAllClassesFromFile($header);	
		my $headerClasses        = $classesAndInterfaces->{classes};
		my $headerInterfaces     = $classesAndInterfaces->{interfaces};
		my $containers           = $classesAndInterfaces->{containers};
		$classOrder{$header}     = [];
		for my $class (@$headerClasses) {
			if (defined($classes{$class->{typeName}})) {
				my $otherClass = $classes{$class->{typeName}};
				die "Found the same type typeName in two files: '$otherClass->{srcFile}' and '$class->{srcFile}'";
			}
			$class->{artifactType}         = 'class';
			$artifacts{$class->{typeName}} = $class;
			$classes{$class->{typeName}}   = $class;
			push @{$classOrder{$header}}, $class->{typeName};
			for my $cont (@{$class->{containers}}) {
				$cont->{artifactType}         = 'container';
				$artifacts{$cont->{typeName}} = $cont;
			}
		}

		$interfaceOrder{$header} = [];
		for my $interface (@$headerInterfaces) {
			if (defined($interfaces{$interface->{typeName}})) {
				my $otherInterface = $interfaces{$interface->{typeName}};
				die "Found the same interface typeName in two files: '$otherInterface->{srcFile}' and '$interface->{srcFile}'";
			}
			$interface->{artifactType}          = 'interface';
			$interfaces{$interface->{typeName}} = $interface;
			$artifacts{$interface->{typeName}}  = $interface;
			push @{$interfaceOrder{$header}}, $interface->{typeName};
			for my $cont (@{$interface->{containers}}) {
				$cont->{artifactType}         = 'container';
				$artifacts{$cont->{typeName}} = $cont;
			}
		}

		print Dumper($containers), "#######\n";
		for my $cont (@$containers) {
			print Dumper($cont), "[][]\n";
			$cont->{artifactType}         = 'container';
			$artifacts{$cont->{typeName}} = $cont;
		}
	}

	$gAllClassesAndInterfaces = {
		classes        => \%classes, 
		classOrder     => \%classOrder, 
		interfaces     => \%interfaces, 
		interfaceOrder => \%interfaceOrder,
		artifacts      => \%artifacts,
	};
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

sub usedCall {
	my ($className, $methodName) = @_;
	return $gUsedCalls->{$className}{$methodName} || $gAcceptAllCalls;
}

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
			@   int len;
			@   int cap;
			@   int elemSize;
			@   void (*clearer)(${ELEMNAME_NS}*);
			@   ${ELEMNAME}*data;
			@} ${TYPENAME};
ENDxxxxxxxxxx
	},


	{
		key =>    'ArrayIt:struct',
		symbol => '',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@typedef struct ${TYPENAME}It_t {
			@   ${TYPENAME} *arr;
			@   int index;
			@   bool last;
			@   ${ELEMNAME}*var;
			@} ${TYPENAME}It;
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
			@	${TYPENAME} zero = {0};
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
		key =>    'ArrayIt:next',
		symbol => '${TYPENAME}It_next',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@static inline bool ${TYPENAME}It_next(${TYPENAME}It *iterator) {
			@	return ArrayIt_next((ArrayIt*)iterator);
			@}
ENDxxxxxxxxxx
	},	

	{
		key =>    'ArrayIt:previous',
		symbol => '${TYPENAME}It_previous',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@static inline bool ${TYPENAME}It_previous(${TYPENAME}It *iterator) {
			@	return ArrayIt_previous((ArrayIt*)iterator);
			@}			
ENDxxxxxxxxxx
	},	

	{
		key    =>    'ArrayIt:declare',
		symbol => '${TYPENAME}It_declare',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@#define ${TYPENAME}It_declare(var, arr)  ${TYPENAME}It var = {arr, -1, false, NULL}			
ENDxxxxxxxxxx
	},	
		
	{
		key =>    'ArrayIt:rdeclare',
		implies => ['Array:len'],
		symbol => '${TYPENAME}It_rdeclare',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@#define ${TYPENAME}It_rdeclare(var, arr)  ${TYPENAME}It var = {arr, ${TYPENAME}_len(arr), false, NULL}			
ENDxxxxxxxxxx
	},	

	{
		key     =>  'Array:foreach',
		implies => ["ArrayIt:declare", "ArrayIt:next"],
		symbol  => '${TYPENAME}_foreach',
		tmpl    => <<'ENDxxxxxxxxxx', 
			@#define ${TYPENAME}_foreach(var, arr)  for (${TYPENAME}It_declare(var, arr); ${TYPENAME}It_next(&var); )			
ENDxxxxxxxxxx
	},	

	{
		key     =>  'Array:each',
		implies => [],
		symbol  => '${TYPENAME}_each',
		tmpl    => <<'ENDxxxxxxxxxx', 
			@#define ${TYPENAME}_each(it, arr) for (${ELEMNAME_NP} ${ELEMPTR}s##it = arr->data, \
            @                    								   ${ELEMPTR}e##it = arr->data + arr->len, \
            @                    								   ${ELEMPTR}it    = s##it;\
            @              							it < e##it;\
            @              							it++)
ENDxxxxxxxxxx
	},	

	{
		key     =>  'Array:reach',
		implies => [],
		symbol  => '${TYPENAME}_reach',
		tmpl    => <<'ENDxxxxxxxxxx', 
			@#define ${TYPENAME}_reach(it, arr) for (${ELEMNAME_NP} ${ELEMPTR}s##it = arr->data, \
            @                        							    ${ELEMPTR}e##it = arr->data + arr->len, \
            @                    								    ${ELEMPTR}it    = e##it-1;\
            @               						it >= s##it;\
            @               						it--)
ENDxxxxxxxxxx
	},	

	{
		key     =>  'Array:eachRemoveImpl',
		implies => ["Array:eachIndexOf", "Array:remove"],
		symbol  => '',
		tmpl    => <<'ENDxxxxxxxxxx', 
			@#define ${TYPENAME}_eachRemoveImpl(it, arr, itOffset) do {\
			@   int index##it = ${TYPENAME}_eachIndexOf(it);\
			@   Error_declare(err##it);\
			@   ${TYPENAME}_remove(arr, index##it, err##it);\
			@   Error_maypost(err##it);\
			@	s##it     = arr->data, \
            @   e##it     = arr->data + arr->len, \
            @   it        = s##it + (index##it + (itOffset));\
			@} while(0); continue
ENDxxxxxxxxxx
	},	

	{
		key     =>  'Array:eachRemove',
		implies => ["Array:eachRemoveImpl"],
		symbol  => '${TYPENAME}_eachRemove',
		tmpl    => <<'ENDxxxxxxxxxx', 
			@#define ${TYPENAME}_eachRemove(it, arr) ${TYPENAME}_eachRemoveImpl(it, arr, 0)
ENDxxxxxxxxxx
	},	

	{
		key     =>  'Array:reachRemove',
		implies => ["Array:eachRemoveImpl"],
		symbol  => '${TYPENAME}_reachRemove',
		tmpl    => <<'ENDxxxxxxxxxx', 
			@#define ${TYPENAME}_reachRemove(it, arr) ${TYPENAME}_eachRemoveImpl(it, arr, -1)
ENDxxxxxxxxxx
	},	


	{
		key     =>  'Array:eachInsertImpl',
		implies => ["Array:eachIndexOf", "Array:insertp"],
		symbol  => '',
		tmpl    => <<'ENDxxxxxxxxxx', 
			@#define ${TYPENAME}_eachInsertImpl(it, arr, valPtr, insertOffset, itOffset) do {\
			@   int index##it = ${TYPENAME}_eachIndexOf(it);\
			@   Error_declare(err##it);\
			@   ${TYPENAME}_insertp(arr, index##it + (insertOffset), valPtr, err##it);\
			@   Error_maypost(err##it);\
			@	s##it     = arr->data, \
            @   e##it     = arr->data + arr->len, \
            @   it        = s##it + (index##it+(itOffset));\
			@} while(0); continue
ENDxxxxxxxxxx
	},

	{
		key     =>  'Array:eachInsert',
		implies => ["Array:eachInsertImpl"],
		symbol  => '${TYPENAME}_eachInsert',
		tmpl    => <<'ENDxxxxxxxxxx', 
			@#define ${TYPENAME}_eachInsert(it, arr, valPtr) ${TYPENAME}_eachInsertImpl(it, arr, valPtr, 0, 1)
ENDxxxxxxxxxx
	},	

	{
		key     =>  'Array:eachInsertAfter',
		implies => ["Array:eachInsertImpl"],
		symbol  => '${TYPENAME}_eachInsertAfter',
		tmpl    => <<'ENDxxxxxxxxxx', 
			@#define ${TYPENAME}_eachInsertAfter(it, arr, valPtr) ${TYPENAME}_eachInsertImpl(it, arr, valPtr, 1, 1)
ENDxxxxxxxxxx
	},	

	{
		key     =>  'Array:reachInsert',
		implies => ["Array:eachInsertImpl"],
		symbol  => '${TYPENAME}_reachInsert',
		tmpl    => <<'ENDxxxxxxxxxx', 
			@#define ${TYPENAME}_reachInsert(it, arr, valPtr) ${TYPENAME}_eachInsertImpl(it, arr, valPtr, 0, 0)
ENDxxxxxxxxxx
	},	

	{
		key     =>  'Array:reachInsertAfter',
		implies => ["Array:reachInsertImpl"],
		symbol  => '${TYPENAME}_reachInsertAfter',
		tmpl    => <<'ENDxxxxxxxxxx', 
			@#define ${TYPENAME}_reachInsertAfter(it, arr, valPtr) ${TYPENAME}_eachInsertImpl(it, arr, valPtr, 1, -1)
ENDxxxxxxxxxx
	},	

	{
		key     =>  'Array:eachIndexOf',
		implies => [],
		symbol  => '${TYPENAME}_eachIndexOf',
		tmpl    => <<'ENDxxxxxxxxxx', 
			@#define ${TYPENAME}_eachIndexOf(it) ((int)(it - s##it))
ENDxxxxxxxxxx
	},	

	{
		key     =>  'Array:eachLast',
		implies => [],
		symbol  => '${TYPENAME}_eachLast',
		tmpl    => <<'ENDxxxxxxxxxx', 
			@#define ${TYPENAME}_eachLast(it) ((it + 1) >= e##it)
ENDxxxxxxxxxx
	},	

	{
		key     =>  'Array:reachLast',
		implies => [],
		symbol  => '${TYPENAME}_reachLast',
		tmpl    => <<'ENDxxxxxxxxxx', 
			@#define ${TYPENAME}_reachLast(it) ((it - 1) < s##it)
ENDxxxxxxxxxx
	},	

	{
		key =>    'Array:rforeach',
		implies => ["ArrayIt:rdeclare", "ArrayIt:previous"],
		symbol => '${TYPENAME}_rforeach',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@#define ${TYPENAME}_rforeach(var, arr)  for (${TYPENAME}It_rdeclare(var, arr); ${TYPENAME}It_previous(&var); )			
ENDxxxxxxxxxx
	},	

	{
		key =>    'Array:loop',
		implies => ["ArrayIt:declare", "ArrayIt:next"],
		symbol => '${TYPENAME}_loop',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@#define ${TYPENAME}_loop(var, arr) ${TYPENAME}It_declare(var, arr); while (${TYPENAME}It_next(&var)) 
ENDxxxxxxxxxx
	},

	{
		key =>    'Array:rloop',
		implies => ["ArrayIt:rdeclare", "ArrayIt:previous"],
		symbol => '${TYPENAME}_rloop',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@#define ${TYPENAME}_rloop(var, arr)    ${TYPENAME}It_rdeclare(var, arr); while (${TYPENAME}It_previous(&var)) 			
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
			@	int (*compare)(${ELEMNAME}*, ${ELEMNAME}*) = ${COMPARE};
			@	Array_binInsert((Array*)arr, (char*)&elem, (Array_compare)compare, ${MULTI});
			@}			
ENDxxxxxxxxxx
	},	

	{
		key =>    'Array:binRemove',
		symbol => '${TYPENAME}_binRemove${TAG}',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@static inline void ${TYPENAME}_binRemove${TAG}(${TYPENAME} *arr, ${ELEMNAME}elem) {
			@	int (*compare)(${ELEMNAME}*, ${ELEMNAME}*) = ${COMPARE};
			@	Array_binRemove((Array*)arr, (char*)&elem, (Array_compare)compare, ${MULTI});
			@}		
ENDxxxxxxxxxx
	},	

	{
		key =>    'Array:sort',
		symbol => '${TYPENAME}_sort${TAG}',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@static inline void ${TYPENAME}_sort${TAG}(${TYPENAME} *arr) {
			@	int (*compare)(${ELEMNAME}*, ${ELEMNAME}*) = ${COMPARE};
			@	Array_sort((Array*)arr, (Array_compare)compare);
			@}				
ENDxxxxxxxxxx
	},	

	{
		key =>    'Array:binSearchSliceReturn',
		symbol => '${TYPENAME}_binSearch${TAG}',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@static inline ${TYPENAME}Slice ${TYPENAME}_binSearch${TAG}(${TYPENAME} *arr, ${ELEMNAME}elem) {
			@	int (*compare)(${ELEMNAME}*, ${ELEMNAME}*) = ${COMPARE};
			@	${TYPENAME}Slice slice = {0};
			@	Array_binSearch((Array*)arr, (char*)&elem, (Array_compare)compare, (ArraySlice*)&slice);
			@	return slice;
			@}
ENDxxxxxxxxxx
	},	

	{
		key =>    'Array:binSearchElemReturn',
		symbol => '${TYPENAME}_binSearch${TAG}',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@static inline ${ELEMNAME}*${TYPENAME}_binSearch${TAG}(${TYPENAME} *arr, ${ELEMNAME}elem) {
			@	int (*compare)(${ELEMNAME}*, ${ELEMNAME}*) = ${COMPARE};
			@	return (${ELEMNAME}*)Array_binSearch((Array*)arr, (char*)&elem, (Array_compare)compare, NULL);
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

	{
		key =>    'Alias:comment',
		symbol => '',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@// type ${TYPENAME} is an alias for ${ALIAS}
ENDxxxxxxxxxx
	},

	{
		key =>    'Interface:proto',
		symbol => '',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@${RTYPE}${IFCNAME}_${METHODNAME}(${TYPEDRECIEVER}${TYPEDARGS}, Error *err)${ENDPROTO}
ENDxxxxxxxxxx
	},

	{
		key =>    'Interface:protoToString',
		symbol => '',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@${RTYPE}${IFCNAME}_${METHODNAME}(int itype)
ENDxxxxxxxxxx
	},

	{
		key =>    'Interface:startFunction',
		symbol => '',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@{
			@	switch(${SWITCHTARGET}) {
ENDxxxxxxxxxx
	},

	{
		key =>    'Interface:endFunction',
		symbol => '',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@}
ENDxxxxxxxxxx
	},


	{
		key =>    'Interface:caseVoid',
		symbol => '',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@		case ${TYPENAME}_itype:
			@			${CALLTYPENAME}_${CALLMETHODNAME}(${CASTRECIEVER}${LISTARGS});
			@			return;
ENDxxxxxxxxxx
	},

	{
		key =>    'Interface:caseAbsentVoid',
		symbol => '',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@		case ${TYPENAME}_itype:
			@			return;
ENDxxxxxxxxxx
	},

	{
		key =>    'Interface:case',
		symbol => '',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@		case ${TYPENAME}_itype:
			@			return ${CALLTYPENAME}_${CALLMETHODNAME}(${CASTRECIEVER}${LISTARGS});
ENDxxxxxxxxxx
	},

	{
		key =>    'Interface:caseAbsent',
		symbol => '',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@		case ${TYPENAME}_itype:
			@			return ${DEFRET};
ENDxxxxxxxxxx
	},

	{
		key =>    'Interface:caseToString',
		symbol => '',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@		case ${TYPENAME}_itype:
			@			return "${TYPENAME}";
ENDxxxxxxxxxx
	},


	{
		key =>    'Interface:endFunction',
		symbol => '',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@		default:
			@			Error_format(err, "Failed to resolve interface call in ${TYPENAME}_${METHODNAME}: found type %s", Interface_toString(${SWITCHTARGET}));
			@    }
			@    return ${DEFRET};
			@}
ENDxxxxxxxxxx
	},

	{
		key =>    'Interface:endFunctionToString',
		symbol => '',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@    }
			@    return "Unknown";
			@}
ENDxxxxxxxxxx
	},

	{
		key =>    'Interface:endFunctionVoid',
		symbol => '',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@       default:
			@			Error_format(err, "Failed to resolve interface call in ${TYPENAME}_${METHODNAME}: found type %s", Interface_toString(${SWITCHTARGET}));
			@    }
			@    return;
			@}
ENDxxxxxxxxxx
	},


	{
		key =>    'Interface:foreachIType',
		symbol => '',
		tmpl   => <<'ENDxxxxxxxxxx', 
static inline int ${IFCNAME}_nthIType(int n, int *itype) {
	static int itypes[] = {
		${ITYPELIST}
	};
	static int len = sizeof(itypes)/sizeof(int);
	if (n < 0 || n >= len) {
		return 0;
	}
	*itype = itypes[n];
	return 1;
}
#define ${IFCNAME}_foreachIType(itype) for (int __##itype = 0, itype = 0; ${IFCNAME}_nthIType(__##itype, &itype); __##itype++)
ENDxxxxxxxxxx
	},

	{
		key =>    'Interface:castTo',
		symbol => '',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@static inline ${IFCNAME} *${TYPENAME}_castTo${IFCNAME}(${TYPENAME} *self) {
			@	return (${IFCNAME}*)self;
			@}
ENDxxxxxxxxxx
	},

	{
		key =>    'Interface:castFrom',
		symbol => '',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@static inline ${TYPENAME} *${TYPENAME}_castFrom${IFCNAME}(${IFCNAME} *self) {
			@	if (self->itype == ${TYPENAME}_itype) {
			@		return (${TYPENAME}*)self;
			@	}
			@	return NULL;
			@}
ENDxxxxxxxxxx
	},

	{
		key =>    'Interface:undefined',
		symbol => '',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@typedef struct Undefined_t {
			@	int itype;
			@	char buffer[1024];
			@} Undefined;
			@#define Undefined_itype ${ITYPE}
			@Undefined Undefined_instance = {Undefined_itype, {0}};
			@#define Undefined_ptr(typeName) ((typeName*)&Undefined_instance)
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
			next unless usedCall($className, $methodName);
		}

		next if $seen{$requestedKey};
		$seen{$requestedKey} = 1;
		push @keysToProcess, $requestedKey;

		my $topImplies = $hsh->{implies};
		if (defined($topImplies)) {
			for my $imp (@$topImplies) {
				next if $seen{$imp};
				$seen{$imp} = 1;
				push @keysToProcess, $imp;
			}


			# my %implieds = map {$_ => 1} @$topImplies;
			# while (%implieds) {
			# 	my @impliedKeys = keys(%implieds);
			# 	%implieds       = ();
			# 	for my $imp (@impliedKeys) {
			# 		if ($imp eq 'Array:eachIndexOf') {
			# 			print "Hmmmmm after before $imp\n";
			# 		}
			# 		next if $seen{$imp};
			# 		$seen{$imp} = 1;
			# 		push @keysToProcess, $imp;
			# 		my $hsh = $templateMap{$imp};
			# 		next unless defined($hsh);
			# 		my $nimplies = $hsh->{implies};
			# 		next unless defined($nimplies);
			# 		for my $nimp (@$nimplies) {
			# 			if ($nimp eq 'Array:eachIndexOf') {
			# 			print "Hmmmmm YYYYYY $imp\n";
			# 		}
			# 			next if $seen{$nimp};
			# 			$seen{$nimp} = 1;
			# 			$implieds{$nimp} = 1;
			# 		}
			# 	}
			# }
		}
	}

	my %special = ("Array:struct" => 1, "Array:slice" => 2, "ArrayIt:struct" => 3);
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

sub pexpandFull {
	my ($out, $inputKeys, $inputDictionary, %opts) = @_;
	my ($outputKeys, $res) = expand($inputKeys, $inputDictionary);
	for my $key (@$outputKeys) {
		my $t = $res->{$key};
		next unless defined($t);
		print {$out} $t;
		print {$out} "\n" if $opts{newline};
	}
}

sub pexpand {
	pexpandFull(@_, newline=>0);
}

sub pexpandNl {
	pexpandFull(@_, newline=>1);
}

sub writeInterfaceH {
	my ($allClasses, $srcDir) = @_; 
	my %classes    = %{$allClasses->{classes}};
	my %classOrder = %{$allClasses->{classOrder}};
	my $outFile = "$srcDir/interface.h";
	open my $fd, ">", $outFile or die "Failed to open $outFile";

	pexpand($fd, ["Interface:undefined"], {ITYPE=>$gUndefinedItype});
	for my $file (keys(%classOrder)) {
		printf {$fd} "\n// From file '%s'\n", $file;
		my @order = @{$classOrder{$file}};
		for my $className (@order) {
			my $class = $classes{$className};
			next unless defined($class->{implements});
			my $itype = $class->{itype};
			printf {$fd} "#define ${className}_itype $itype\n";
		}
	}
	print {$fd} "const char *Interface_toString(int itype);";
	close($fd);
}
sub writeInterfaceC {
	my ($allClasses, $srcDir) = @_; 
	my %classes    = %{$allClasses->{classes}};
	my %classOrder = %{$allClasses->{classOrder}};
	my $outFile = "$srcDir/interface.c";
	open my $fd, ">", $outFile or die "Failed to open $outFile";
	my $cfg = {
		RTYPE         => spaceAdjustType("const char *"),
		IFCNAME       => "Interface",
		METHODNAME    => "toString",
	};
	pexpand($fd, ['Interface:protoToString'], $cfg);
	pexpand($fd, ['Interface:startFunction'], {SWITCHTARGET => "itype"});
	pexpand($fd, ['Interface:caseToString'], {TYPENAME => "Undefined"});
	for my $file (keys(%classOrder)) {
		my @order = @{$classOrder{$file}};
		for my $className (@order) {
			my $class = $classes{$className};
			next unless defined($class->{implements});
			pexpand($fd, ['Interface:caseToString'], {TYPENAME => $class->{typeName}});
		}
	}
	pexpand($fd, ['Interface:endFunctionToString'], {});
	close($fd);
}


sub writeStructArtifact {
	my ($out, $artifact) = @_;
	if ($artifact->{artifactType} eq 'class' || $artifact->{artifactType} eq 'interface') {
		writeStruct($out, $artifact);
	} elsif ($artifact->{artifactType} eq 'container') {
		writeArray($out, $artifact, 1);	
	}
}

## Writes the list of structs in an order where a value field in a struct, implies that
## the struct for the value field is 
sub writeAllStructs {
	my ($out) = @_;
	my $artifacts = $gAllClassesAndInterfaces->{artifacts};
	my @structNamesToWrite = keys(%$artifacts);

	my %valueDepend;
	for my $structName (@structNamesToWrite) {
		my $artifact = $artifacts->{$structName};
		die "INTERNAL ERROR" if defined($valueDepend{$structName});
		my $subhash = {};
		$valueDepend{$structName} = $subhash;
		if ($artifact->{artifactType} eq 'container') {
			if ($artifact->{elemName} !~ /\*/ && defined($artifacts->{$artifact->{elemName}})) {
				$subhash->{$artifact->{elemName}} = 1;	
			}
		} else {
			for my $field (@{$artifact->{fields}}) {
				if ($field->{type} !~ /\*/ && defined($artifacts->{$field->{type}})) {
					$subhash->{$field->{type}} = 1;
				}
			}
		}
	}

	## Start by writing the Array structs
	writeStructArtifact($out, {artifactType=>"container", typeName=>"Array", elemName=>"char"});

	my %written;
	my %queued;
	my $wt;
	$wt = sub {
		my ($structName, $structList) = @_;
		return if !defined($structName);
		return if $written{$structName};
		die "Unable to output structs in the right order" if $queued{$structName};
		
		my $depends = $valueDepend{$structName} || die "INTERNAL ERROR";
		for my $classOrInterfaceName (keys(%$depends)) {
			if (!$written{$classOrInterfaceName}) {				
				$queued{$structName} = 1;
				$wt->($classOrInterfaceName, $structList);
				delete($queued{$structName});
			}
		}
		$written{$structName} = 1;
		my $artifact = $artifacts->{$structName};
		writeStructArtifact($out, $artifact);
		if (!%queued) {
			$wt->(pop @$structList, $structList);
		}
	};
	while (@structNamesToWrite) {
		$wt->(pop @structNamesToWrite, \@structNamesToWrite);
	}
}

sub writeTypesH {
	my ($srcDir, $templateHeaders) = @_;
	my $file = "$srcDir/types.h";
	open my $out, ">", $file or die "Failed to open $file";
	writeWarning($out, "XXX-Temporarily-Out-Of-Service");
	my $artifacts = $gAllClassesAndInterfaces->{artifacts};
	for my $artifactName (keys(%$artifacts)) {
		my $artifact = $artifacts->{$artifactName};
		writePredefined($out, $artifact);
	}
	writeAllStructs($out);
	writeApif($out);
	for my $templateHeader (@$templateHeaders) {
		writeWarning($out, $templateHeader);
		my $interfaceOrder = $gAllClassesAndInterfaces->{interfaceOrder}{$templateHeader};
		die "INTERNAL ERROR" unless defined($interfaceOrder);
		for my $interfaceName (@$interfaceOrder) {
			my $interface = $gAllClassesAndInterfaces->{interfaces}{$interfaceName};
			for (my $methodIndex = 0; $methodIndex < @{$interface->{methods}}; $methodIndex++) {
				writeInterfaceMethod($out, $interface, $methodIndex, 1);
			}
		}
	}

	close($out);
}

sub main {

	my @args = @ARGV;
	$gAcceptAllCalls = (grep {$_ eq '-a'} @args) > 0;
	@args = (grep {$_ ne '-a'} @args);
	die "generate requires 1 argument" unless @args == 1;
	my ($srcDir) = @args;
	my ($templateHeaders, $cFiles, $cTemplates) = filesInDirectory($srcDir);
	if (@$templateHeaders <= 0) {
		die "No templates found in directory $srcDir"
	}

	collectAllClasses($templateHeaders);
	crossrefClassesAndInterfaces($gAllClassesAndInterfaces->{interfaces}, $gAllClassesAndInterfaces->{classes});
	my $allCFiles = [@$cFiles, @$cTemplates];
	collectUsedCalls($allCFiles);
	scanAPIF($allCFiles);

	writeInterfaceH($gAllClassesAndInterfaces, $srcDir);
	writeInterfaceC($gAllClassesAndInterfaces, $srcDir);
	writeTypesH($srcDir, $templateHeaders);

	for my $templateHeader (@$templateHeaders) {
		my $header = $templateHeader;
		if ($header !~ s/\.in\.h$/.h/) {
			die "generate.pl was passed a bad file name '$templateHeader'";
		}

		open my $out, ">", $header or die "Failed to open $header";
		writeWarning($out, $templateHeader);
		processTemplateHeader($out, $templateHeader);
		close($out);
	}

	for my $inDotC (@$cTemplates) {
		filterDotInC($inDotC);
	}
}	

main();
