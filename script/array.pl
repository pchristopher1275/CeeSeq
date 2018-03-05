#!/usr/bin/perl
use strict;
use lib "$ENV{HOME}/CeeSeq/script/lib";
use JSON::Tiny qw(decode_json encode_json);
use Data::Dumper;

sub template {
	my ($out, $cfg) = @_;
	my $TYPENAME    = $cfg->{typename};
	my $ELEMNAME_NS = $cfg->{elemname};
	my $CLEARER     = $cfg->{clearer};
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

	my $binarySearch = $cfg->{binarySearch};
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
typedef struct ${ELEMNAME}Slice_t {
	int len;
	${ELEMNAME}*data;
	int index;
	${ELEMNAME}*var;
} ${ELEMNAME}Slice;
#define ${TYPENAME}_sliceEmpty(slice) (slice.data == NULL)
#define ${TYPENAME}_sliceForeach(slice) for (slice.index=0, slice.var = slice.data; slice.index < slice.len; slice.index++, slice.var += sizeof(${ELEMNAME}))

#define ${TYPENAME}_rsliceForeach(slice) for (slice.index=slice.len-1, slice.var = slice.data + slice.index*sizeof(${ELEMNAME}); \
											  slice.index >= 0; slice.index--, slice.var -= sizeof(${ELEMNAME}))

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
static inline ${ELEMNAME}Slice ${TYPENAME}_binSearch${TAG}(${TYPENAME} *arr, ${ELEMNAME}elem) {
	${ELEMNAME}Slice slice = {0};
	Array_binSearch((Array*)arr, (char*)&elem, (Array_compare)${COMPARE}, &slice);
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

sub from_jsonfile {
	my ($file) = @_;
	open my $fd, $file or die "Failed to open $file";
	my @lines = <$fd>;
	close($fd);
	my $buffer = join("", @lines);
	return decode_json($buffer);
}

sub to_jsonfile {
	my ($file, $data) = @_;
	open my $fd, ">", $file or die "Failed to open $file";
	print {$fd} encode_json($data), "\n";
	close($fd);
}


sub main {
	die "Requires at least one argument" unless @ARGV > 0;
	my $out = \*STDOUT;
	my $config = from_jsonfile($ARGV[0]);
	for my $cfg (@{$config->{config}}) {
		template($out, $cfg);	
	}
}

main();