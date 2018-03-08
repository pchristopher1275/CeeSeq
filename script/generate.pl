#!/usr/bin/perl
use strict;
use lib "$ENV{HOME}/CeeSeq/script/lib";
use JSON::Tiny qw(decode_json encode_json);
use Data::Dumper;

sub writeWarning {
	my ($out) = @_;
	print {$out} "// *** DO NOT MODIFY THIS FILE (see header.pl) ***\n";
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
		print "$line: $_";
		s/\n$/ /;

		if (/^\@end\s/) {
			$found = 1;
			last;
		}
		if (/^\@type\s/) {
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
	close($fd);
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
		push @$classes, decode_json($text);
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

	writeWarning($out);
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
	print {$out} "\n";
}

sub writeOrdinaryLine {
	my ($cfg, $line) = @_;
	my $out = $cfg->{out};
	print {$fd} $line, "\n";
}

sub writeAllClassesFromFile {
	my ($out, $file) = @_;
	my $cfg = {out=>$out, file=>$file, typeCallback=>\&writeClassFromAtType, notTypeCallback=>\&writeOrdinaryLine};
	scanInDotH($cfg);
}

sub main {
	my $srcFile = "src/midiseq.in.h";
	my $dstFile = $srcFile;
	if ($dstFile !~ s/\.in\.h$/.h/) {
		die "generate.pl was passed a bad file name '$srcFile'";
	}
	my $cFile = $srcFile;
	$cFile =~ s/\.in\.h$/.c/;

	
	my $classes = collectAllClassesFromFile();
	my $apif    = scanAPIF($cFile);
	

	open my $out, ">", $dstFile or die "Failed to open $dstFile";
	writeWarning($out);
	for my $class (@$classes) {
		writePredefined($out, $class);		
	}
	writeAllClassesFromFile($out, $srcFile);
	close($out);


	# ## Predefined
	# for my $class (@classes) {
	# 	writePredefined($out, $class);		
	# }
	# print {$out} "\n\n";

	## Structs
	# for my $class (@classes) {
	# 	writeWarning($out);
	# 	writeStruct($out, $class);
	# 	writeNewUnitialized($out, $class) unless $class->{noNewUnitialized};
	# 	if (defined($class->{preAccessor})) {
	# 		$class->{preAccessor}($out);
	# 	}
	# 	writeAccessor($out, $class);
	# 	if (defined($class->{postAccessor})) {
	# 		$class->{postAccessor}($out);
	# 	}
	# 	writeAPIFForType($apif, $out, $class->{typeName});
	# 	if (defined($class->{argDeclare})) {
	# 		writeArgDeclare($out, $class);
	# 	}
	# 	if (defined($class->{includes})) {
	# 		for my $i (@{$class->{includes}}) {
	# 			printf {$out} "#include \"%s\"\n", $i;
	# 		}
	# 	}
	# 	print {$out} "\n";
	# }	
}	

main();
