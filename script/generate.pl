#!/usr/bin/perl
use strict;
use lib "$ENV{HOME}/CeeSeq/script/lib";
use JSON::Tiny qw(decode_json encode_json);
use Data::Dumper;

my $gVerbose = 1;

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
	print {$out} "// *** DO NOT MODIFY THIS FILE (see $srcFile) ***\n";
}

sub writeStruct {
	my ($out, $config) = @_;
	if (defined($config->{manualStruct})) {
		$config->{manualStruct}($out);
		return;
	}

	print {$out} <<END;
struct $config->{typeName}_t
{
END
	my $persist;
	for my $field (@{$config->{fields}}) {
		if (defined($field->{group})) {
			if ($field->{group} eq 'persist') {
				$persist = 1;
				print {$out} "    // ** PERSISTED **\n";
			} elsif ($field->{group} eq 'noPersist') {
				$persist = 0;				
				print {$out} "    // ** not persisted **\n";
			}
			next;
		}

		if (defined($field->{comment})) {
			if (ref($field->{comment}) eq 'ARRAY') {
				for my $comment (@{$field->{comment}}) {
					print {$out} "    // $comment\n";
				}
			} else {
				print {$out} "    // $field->{comment}\n";
			}
		}

		my $stype = spaceAdjustType($field->{type});
		print {$out} "    $stype$field->{name};\n";
	}
	print {$out} <<END;  
};
END
}

sub writeNewUnitialized {
	my ($out, $config) = @_;
	print {$out}<<END;
#define $config->{typeName}_newUninitialized() (($config->{typeName}*)sysmem_newptrclear(sizeof($config->{typeName})))
END
}

sub writePredefined {
	my ($out, $config) = @_;
	print Dumper($config), "\n";
	print {$out}<<END;
struct $config->{typeName}_t;
typedef struct $config->{typeName}_t $config->{typeName};
END
}

sub writeArgDeclare {
	my ($out, $config) = @_;
	my $args = "";
	my $struct = "{";
	for my $field (@{$config->{fields}}) {
		if (defined($field->{group})) {
			next;
		}
		$args   .= "$field->{name}, ";
		$struct .= "($field->{name}), ";
	}
	$args   =~ s/,\s*$//;
	$struct =~ s/,\s*$//;
	$struct .= "}";
	print {$out}<<END;
#define $config->{typeName}_declare(name, $args) $config->{typeName} name = $struct
END
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
	my ($out, $config) = @_;
	my $typeName = $config->{typeName};
	for my $field (@{$config->{fields}}) {
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

		if (defined($getter)) {			
			if ($getter eq 'proto') {
				print {$out}<<END;
${stype}${typeName}_$field->{name}($typeName *self);
END
		 	} elsif ($getter eq 'none') {
		 		## Nothing
		 	} else {
		 		die "INTERNAL ERROR";
		 	}
		} else {
			print {$out}<<END;
static inline ${stype}${typeName}_$field->{name}($typeName *self){return ${maybeAmper}self->$field->{name};}
END
		}

		my $setter = $field->{setter}; 
		my $setName = setNameFromFieldName($field->{name});
		if (defined($setter)) {	
			if ($setter eq 'proto') {		
				print {$out}<<END;
void ${typeName}_${setName}($typeName *self, ${stype}value);
END
			} elsif ($setter eq 'none') {
				## Do nothing
			} else {
				die "INTERNAL ERROR";
			}
		} else {
			print {$out}<<END;
static inline void ${typeName}_${setName}($typeName *self, ${stype}value){self->$field->{name} = value;}
END
		}


	}
}

sub scanAPIF {
	my ($source) = @_;
	open my $fd, $source or die "Failed to open $source";
	my @a;
	while (<$fd>) {
		next unless /^\s*APIF/;
		my $line = $_;
		chomp($line);
		my $bracket = '{';
		$line =~ s/\s*$bracket?\s*$//;
		$line =~ s/^\s*APIF\s*//;
		push @a, $line;
	}
	close($fd);
	return {funcs=>\@a};
}

sub writeAPIFForType {
	my ($apif, $out, $type) = @_;
	for my $line (@{$apif->{funcs}}) {
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

		if (/^\@end/) {
			$found = 1;
			last;
		}
		if (/^\@type/) {
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
	my ($file, $typeCallback, $notTypeCallback) = ($cfg->{file}, $cfg->{typeCallback}, $cfg->{notTypeCallback});
	die "INTERNAL ERROR" unless defined($file) && defined($typeCallback) && defined($notTypeCallback);
	open my $inp, "<", $file or die "Failed to open $file";
	$cfg->{inp}  = $inp;
	$cfg->{line} = 0;
	while (<$inp>) {
		$cfg->{line}++;
		if (/^\@type\s/) {
			$cfg->{lastAtType} = $cfg->{line};
			my $text = scanUntilAtEnd($cfg);
			$typeCallback->($cfg, $text);
		} else {
			$notTypeCallback->($cfg, $_);
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
		die "Failed to decode json for type starting at $cfg->{lastAtType}";
	}
}

sub collectAllClassesFromFile {
	my ($file) = @_;
	my $cfg = {file=>$file, typeCallback=>\&collectClassFromAtType, notTypeCallback=>sub {}};
	scanInDotH($cfg);
	return $cfg->{classes};
}

sub writeClassFromAtType {
	my ($cfg, $lines) = @_;
	my $text = join("\n", @$lines);
	my $class;
	eval {
		$class = decode_json($text);
	};
	if ($@) {
		die "Failed to decode json for type starting at $cfg->{lastAtType}";
	}
	my $out  = $cfg->{out};
	my $apif = $cfg->{apif};
	my $file = $cfg->{file};
	writeWarning($out, $file);
	writeStruct($out, $class);
	writeNewUnitialized($out, $class) unless $class->{noNewUnitialized};
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
	writeAPIFForType($apif, $out, $class->{typeName});
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

sub writeOrdinaryLine {
	my ($cfg, $line) = @_;
	my $out = $cfg->{out};
	print {$out} $line;
}

sub writeAllClassesFromFile {
	my ($out, $file, $apif) = @_;
	my $cfg = {out=>$out, file=>$file, typeCallback=>\&writeClassFromAtType, notTypeCallback=>\&writeOrdinaryLine, apif=>$apif};
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

	my $templ = <<END;
typedef struct ${TYPENAME}_t {
	Array body;
} ${TYPENAME};

static inline ${TYPENAME} *${TYPENAME}_new(int nelems) {
	return (${TYPENAME}*)Array_new(nelems, sizeof(${ELEMNAME_NS}), (Array_clearElement)${CLEARER});
}

static inline void ${TYPENAME}_init(${TYPENAME} *arr, int nelems) {
	Array_init((Array*)arr, nelems, sizeof(${ELEMNAME_NS}), (Array_clearElement)${CLEARER});
}

static inline void ${TYPENAME}_clear(${TYPENAME} *arr) {
	Array_clear((Array*)arr);
	$TYPENAME zero = {{0}};
	*arr = zero;
}

static inline void ${TYPENAME}_free(${TYPENAME} *arr) {
	Array_free((Array*)arr);
}

static inline void ${TYPENAME}_truncate(${TYPENAME} *arr) {
	Array_truncate((Array*)arr);
}

static inline int ${TYPENAME}_len(${TYPENAME} *arr) {
	return Array_len((Array*)arr);
}

static inline ${ELEMNAME}${TYPENAME}_get(${TYPENAME} *arr, int index, Error *err) {
	${ELEMNAME_NS} v = $ELEMZERO;
	Array_getCheck(arr, index, v, err);
	memmove(&v, Array_get((Array*)arr, index), Array_elemSize((Array*)arr));
	return v;
}

static inline ${ELEMNAME}*${TYPENAME}_getp(${TYPENAME} *arr, int index, Error *err) {
	Array_getCheck(arr, index, NULL, err);
	return (${ELEMNAME}*)Array_get((Array*)arr, index);
}


static inline void ${TYPENAME}_set(${TYPENAME} *arr, int index, ${ELEMNAME}elem, Error *err) {
	Array_setCheck(arr, index, err);
	Array_set((Array*)arr, index, (char*)&elem);
}

static inline void ${TYPENAME}_setp(${TYPENAME} *arr, int index, ${ELEMNAME}*elem, Error *err) {
	Array_setCheck(arr, index, err);
	Array_set((Array*)arr, index, (char*)elem);
}

static inline void ${TYPENAME}_pop(${TYPENAME} *arr, Error *err) {
	Array_popNCheck(arr, 1, err);
	Array_popN((Array*)arr, 1);
}

static inline void ${TYPENAME}_push(${TYPENAME} *arr, ${ELEMNAME}elem) {
	${ELEMNAME_NS} *p = (${ELEMNAME}*)Array_pushN((Array*)arr, 1);
	*p = elem;
	return; 
}

static inline void ${TYPENAME}_pushp(${TYPENAME} *arr, ${ELEMNAME}*elem) {
	${ELEMNAME_NS} *p = (${ELEMNAME}*)Array_pushN((Array*)arr, 1);
	*p = *elem;
	return; 
}

static inline void ${TYPENAME}_insert(${TYPENAME} *arr, int index, ${ELEMNAME}elem, Error *err) {
	Array_insertNCheck(arr, index, 1, err);
	${ELEMNAME_NS} *p = (${ELEMNAME}*)Array_insertN((Array*)arr, index, 1);
	*p = elem;
}

static inline void ${TYPENAME}_insertp(${TYPENAME} *arr, int index, ${ELEMNAME}*elem, Error *err) {
	Array_insertNCheck(arr, index, 1, err);
	${ELEMNAME_NS} *p = (${ELEMNAME}*)Array_insertN((Array*)arr, index, 1);
	*p = *elem;
}


static inline void ${TYPENAME}_remove(${TYPENAME} *arr, int index, Error *err) {
	Array_removeNCheck(arr, index, 1, err);
	Array_removeN((Array*)arr, index, 1);
}

static inline void ${TYPENAME}_removeN(${TYPENAME} *arr, int index, int N, Error *err) {
	Array_removeNCheck(arr, index, N, err);
	Array_removeN((Array*)arr, index, N);
}

static inline void ${TYPENAME}_fit(${TYPENAME} *arr) {
	Array_fit((Array*)arr);
}

static inline int ${TYPENAME}_last(${TYPENAME} *arr) {
	return Array_len((Array*)arr)-1;
}

static inline void ${TYPENAME}_changeLength(${TYPENAME} *arr, int newLength) {
	Array_changeLength((Array*)arr, newLength);
}

typedef struct ${TYPENAME}Iter_t {
   ${TYPENAME} *arr;
   int index;
   bool last;
   ${ELEMNAME}*var;
} ${TYPENAME}Iter;

static inline bool ${TYPENAME}Iter_next(${TYPENAME}Iter *iterator) {
	return ArrayIter_next((ArrayIter*)iterator);
}

static inline bool ${TYPENAME}Iter_previous(${TYPENAME}Iter *iterator) {
	return ArrayIter_previous((ArrayIter*)iterator);
}

#define ${TYPENAME}Iter_declare(var, arr)  ${TYPENAME}Iter var = {arr, -1, false, NULL}
#define ${TYPENAME}Iter_rdeclare(var, arr)  ${TYPENAME}Iter var = {arr, ${TYPENAME}_len(arr), false, NULL}
#define ${TYPENAME}_foreach(var, arr)  for (${TYPENAME}Iter_declare(var, arr); ${TYPENAME}Iter_next(&var); )
#define ${TYPENAME}_rforeach(var, arr)  for (${TYPENAME}Iter_rdeclare(var, arr); ${TYPENAME}Iter_previous(&var); )
#define ${TYPENAME}_loop(var, arr)    ${TYPENAME}Iter_declare(var, arr); while (${TYPENAME}Iter_next(&var)) 
#define ${TYPENAME}_rloop(var, arr)    ${TYPENAME}Iter_rdeclare(var, arr); while (${TYPENAME}Iter_previous(&var)) 

END
	## change any tabs to spaces so that the spacing is rendered correctly
	$templ =~ s/\t/    /g;
	print {$out} $templ;

	my $binarySearch = $arrayCfg->{binarySearch};
	if (defined($binarySearch)) {
		my $needslice = 0;
		for my $b (@$binarySearch) {
			if ($b->{multi}) {
				$needslice = 1;
				last;
			}
		}
		if ($needslice) {
			$templ = <<END;
typedef struct ${TYPENAME}Slice_t {
	int len;
	${ELEMNAME}*data;
	int index;
	${ELEMNAME}*var;
} ${TYPENAME}Slice;
#define ${TYPENAME}_declareSlice(name) ${TYPENAME}Slice name = {0}
#define ${TYPENAME}_sliceEmpty(slice) (slice.data == NULL)
#define ${TYPENAME}_sliceForeach(slice) for (slice.index=0, slice.var=slice.data; slice.index < slice.len; slice.index++, slice.var++)

#define ${TYPENAME}_rsliceForeach(slice) for (slice.index=slice.len-1, slice.var = slice.data + slice.index*sizeof(${ELEMNAME_NS}); \\
											  slice.index >= 0; slice.index--, slice.var--)

END
			$templ =~ s/\t/    /g;
			print {$out} $templ;
		}



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
			my $MULTI = $domulti ? "true" : "false";

			$templ = <<END;
static inline void ${TYPENAME}_binInsert${TAG}(${TYPENAME} *arr, ${ELEMNAME}elem) {
	Array_binInsert((Array*)arr, (char*)&elem, (Array_compare)${COMPARE}, ${MULTI});
}

static inline void ${TYPENAME}_binRemove${TAG}(${TYPENAME} *arr, ${ELEMNAME}elem) {
	Array_binRemove((Array*)arr, (char*)&elem, (Array_compare)${COMPARE}, ${MULTI});
}

static inline void ${TYPENAME}_sort${TAG}(${TYPENAME} *arr) {
	Array_sort((Array*)arr, (Array_compare)${COMPARE});
}

END
			$templ =~ s/\t/    /g;
			print {$out} $templ;

			if ($domulti) {

				$templ = <<END;
static inline ${TYPENAME}Slice ${TYPENAME}_binSearch${TAG}(${TYPENAME} *arr, ${ELEMNAME}elem) {
	${TYPENAME}Slice slice = {0};
	Array_binSearch((Array*)arr, (char*)&elem, (Array_compare)${COMPARE}, (ArraySlice*)&slice);
	return slice;
}
END
			} else {
				$templ = <<END;
static inline ${ELEMNAME}*${TYPENAME}_binSearch${TAG}(${TYPENAME} *arr, ${ELEMNAME}elem) {
	return (${ELEMNAME}*)Array_binSearch((Array*)arr, (char*)&elem, (Array_compare)${COMPARE}, NULL);
}
END
			}
			$templ =~ s/\t/    /g;
			print {$out} $templ;
		}
	}


}

sub filesInDirectory {
	my ($srcDir) = @_;
	$srcDir =~ s[/$][];
	my @lines = backtick "ls $srcDir/*";
	my @templateHeaders;
	my @cFiles;
	for my $line (@lines) {
		$line =~ s/^\s*//;
		$line =~ s/\s*$//;
		if ($line =~ /\.in.h$/) {
			push @templateHeaders, $line;
		} elsif ($line =~ /\.c$/) {
			push @cFiles, $line;
		}
	}
	return (\@templateHeaders, \@cFiles);
}

sub collectAllClasses {
	my ($templateHeaders) = @_;
	my %classes;
	my %classOrder;
	for my $header (@$templateHeaders) {
		my $headerClasses = collectAllClassesFromFile($header);	
		$classOrder{$header} = [];
		for my $class (@$headerClasses) {
			if (defined($classes{$class->{typeName}})) {
				my $otherClass = $classes{$class->{typeName}};
				die "Found the same typeName in two files: '$otherClass->{srcFile}' and '$class->{srcFile}'";
			}
			$classes{$class->{typeName}} = $class;
			push @{$classOrder{$header}}, $class->{typeName};
		}
	}
	return {classes => \%classes, file2ClassOrder => \%classOrder};
}

sub processTemplateHeader {
	my ($out, $templateHeader) = @_;
	my $cFile = $templateHeader;
	if ($cFile !~ s/\.in\.h$/.c/) {
		die "generate.pl was passed a bad file name '$templateHeader'";
	}
	my $apif = scanAPIF($cFile);
	writeAllClassesFromFile($out, $templateHeader, $apif);
}

sub main {
	my ($srcDir) = @ARGV;
	die "generate requires 1 argument" unless @ARGV == 1;
	my ($templateHeaders, $cFiles) = filesInDirectory($srcDir);
	if (@$templateHeaders <= 0) {
		die "No templates found in directory $srcDir"
	}

	my $allClasses = collectAllClasses($templateHeaders);
	for my $templateHeader (@$templateHeaders) {
		my $header = $templateHeader;
		if ($header !~ s/\.in\.h$/.h/) {
			die "generate.pl was passed a bad file name '$templateHeader'";
		}

		open my $out, ">", $header or die "Failed to open $header";
		writeWarning($out, $templateHeader);

		my $order = $allClasses->{file2ClassOrder}{$templateHeader};
		die "INTERNAL ERROR" unless defined($order);
		for my $className (@$order) {
			writePredefined($out, $allClasses->{classes}{$className});		
		}

		processTemplateHeader($out, $templateHeader);
		close($out);
	}
}	

main();
