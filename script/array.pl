#!/usr/bin/perl
use strict;
use lib "$ENV{HOME}/CeeSeq/script/lib";
use JSON::Tiny qw(decode_json encode_json);
use Data::Dumper;

sub template {
	my ($out, $cfg) = @_;
	my $TYPENAME   = $cfg->{typename};
	my $ELEMNAME_NS = $cfg->{elemname};
	my $CLEARER    = $cfg->{clearer};
	my $ELEMNAME   = "";
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

static inline ${ELEMNAME}*${TYPENAME}_insert(${TYPENAME} *arr, int index, Error *err) {
	Array_insertNCheck(arr, index, 1, err);
	return (${ELEMNAME}*)Array_insertN((Array*)arr, index, 1);
}

static inline void ${TYPENAME}_remove(${TYPENAME} *arr, int index, Error *err) {
	Array_removeNCheck(arr, index, 1, err);
	Array_removeN((Array*)arr, index, 1);
}

static inline void ${TYPENAME}_fit(${TYPENAME} *arr) {
	Array_fit((Array*)arr);
}

typedef struct ${TYPENAME}Iter_t {
   ${TYPENAME} *arr;
   int index;
   bool last;
   ${ELEMNAME}*pvalue;
   ${ELEMNAME}value;
} ${TYPENAME}Iter;

static inline bool ${TYPENAME}Iter_next(${TYPENAME}Iter *iterator) {
	return ArrayIter_nextValue((ArrayIter*)iterator, (char*)&iterator->value);
}

static inline bool ${TYPENAME}Iter_insert(${TYPENAME}Iter *iterator, ${ELEMNAME_NS} value) {
	return ArrayIter_insert((ArrayIter*)iterator, (char*)&value);
}

static inline bool ${TYPENAME}Iter_remove(${TYPENAME}Iter *iterator) {
	return ArrayIter_remove((ArrayIter*)iterator);
}

#define ${TYPENAME}Iter_declare(var, arr)  ${TYPENAME}Iter var = {arr, -1, false, NULL, ${ELEMZERO}}
#define ${TYPENAME}_foreach(var, arr)  for (${TYPENAME}Iter_declare(var, arr); ${TYPENAME}Iter_next(&var); )
#define ${TYPENAME}_loop(var, arr)    ${TYPENAME}Iter_declare(var, arr); while (${TYPENAME}Iter_next(&var)) 


END
	## change any tabs to spaces so that the spacing is rendered correctly
	$templ =~ s/\t/    /g;
	print {$out} $templ;
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