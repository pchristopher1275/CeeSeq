#!/usr/bin/perl
use strict;
use lib "$ENV{HOME}/CeeSeq/script/lib";
use JSON::Tiny qw(decode_json encode_json);
use POSIX qw(strftime);
use Data::Dumper;

my $gVerbose             = 1;
my $gApplicationName     = undef;
my $gAcceptAllCalls      = 0;
my $gNow                 = strftime("%m/%d/%Y %H:%M:%S", localtime);
my $gUndefinedItype      = 10;
my $gMasterSourceDir     = undef;
my $gGenerateCoverage    = 0;

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



my @templates = (
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
		key =>    'ArrayFIt:struct',
		symbol => '',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@typedef struct ${TYPENAME}FIt_t {
			@   ${TYPENAME} *arr;
			@   int lBound;
			@   int uBound;
			@
			@   int index;
			@   ${ELEMNAME}*var;
			@} ${TYPENAME}FIt;
ENDxxxxxxxxxx
	},

		{
		key =>    'ArrayRIt:struct',
		symbol => '',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@typedef struct ${TYPENAME}RIt_t {
			@   ${TYPENAME} *arr;
			@   int lBound;
			@   int uBound;
			@
			@   int index;
			@   ${ELEMNAME}*var;
			@} ${TYPENAME}RIt;
ENDxxxxxxxxxx
	},

	{
		key =>    'Array:new',
		symbol => '',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@static inline ${TYPENAME} *${TYPENAME}_new(int nelems) {
			@	void (*clearer)(${ELEMNAME}*) = ${CLEARER};
			@	return (${TYPENAME}*)Array_new(nelems, sizeof(${ELEMNAME_NS}), (Array_clearElement)clearer);
			@}
ENDxxxxxxxxxx
	},

	{
		key =>    'Array:init',
		symbol => '',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@static inline void ${TYPENAME}_init(${TYPENAME} *arr, int nelems) {
			@   void (*clearer)(${ELEMNAME}*) = ${CLEARER};
			@	Array_init((Array*)arr, nelems, sizeof(${ELEMNAME_NS}), (Array_clearElement)clearer);
			@}
ENDxxxxxxxxxx
	},


	{
		key =>    'Array:clear',
		symbol => '',
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
		symbol => '',
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
		key =>    'Array:at',
		symbol => '${TYPENAME}_at',
		tmpl   => <<'ENDxxxxxxxxxx',
			@#define ${TYPENAME}_at(arr, index) (arr)->data[index]
ENDxxxxxxxxxx
	},

	{
		key =>    'Array:atp',
		symbol => '${TYPENAME}_at',
		tmpl   => <<'ENDxxxxxxxxxx',
			@#define ${TYPENAME}_atp(arr, index) ((arr)->data + (index))
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
		key =>    'ArrayFIt:next',
		symbol => '${TYPENAME}FIt_next',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@static inline bool ${TYPENAME}FIt_next(${TYPENAME}FIt *iterator) {
			@	return ArrayFIt_next((ArrayFIt*)iterator);
			@}
ENDxxxxxxxxxx
	},	

	{
		key =>    'ArrayFIt:atEnd',
		symbol => '${TYPENAME}FIt_atEnd',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@static inline bool ${TYPENAME}FIt_atEnd(${TYPENAME}FIt *iterator) {
			@	return iterator->index+1 >= iterator->uBound;
			@}
ENDxxxxxxxxxx
	},	

	{
		key =>    'ArrayRIt:atEnd',
		symbol => '${TYPENAME}RIt_atEnd',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@static inline bool ${TYPENAME}RIt_atEnd(${TYPENAME}RIt *iterator) {
			@	return iterator->index-1 < iterator->lBound;
			@}
ENDxxxxxxxxxx
	},	


	{
		key =>    'ArrayFIt:remove',
		symbol => '${TYPENAME}FIt_remove',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@static inline bool ${TYPENAME}FIt_remove(${TYPENAME}FIt *iterator) {
			@	return ArrayFIt_remove((ArrayFIt*)iterator);
			@}
ENDxxxxxxxxxx
	},	

	{
		key =>    'ArrayRIt:next',
		symbol => '${TYPENAME}RIt_next',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@static inline bool ${TYPENAME}RIt_next(${TYPENAME}RIt *iterator) {
			@	return ArrayRIt_next((ArrayRIt*)iterator);
			@}
ENDxxxxxxxxxx
	},	

	{
		key =>    'ArrayRIt:remove',
		symbol => '${TYPENAME}RIt_remove',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@static inline bool ${TYPENAME}RIt_remove(${TYPENAME}RIt *iterator) {
			@	return ArrayRIt_remove((ArrayRIt*)iterator);
			@}
ENDxxxxxxxxxx
	},	

	{
		key    =>    'ArrayFIt:declare',
		symbol => '${TYPENAME}FIt_declare',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@#define ${TYPENAME}FIt_declare(var, arr, offset)  ${TYPENAME}FIt var = {arr, 0, (arr)->len, offset-1, NULL}
ENDxxxxxxxxxx
	},	

	{
		key    =>    'ArrayFIt:declare0',
		symbol => '${TYPENAME}FIt_declare0',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@#define ${TYPENAME}FIt_declare0(var)  ${TYPENAME}FIt var = {0}
ENDxxxxxxxxxx
	},	
		
	{
		key    =>    'ArrayRIt:declare',
		symbol => '${TYPENAME}RIt_declare',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@#define ${TYPENAME}RIt_declare(var, arr, offset)  ${TYPENAME}RIt var = {arr, 0, (arr)->len, (arr)->len-offset, NULL}
ENDxxxxxxxxxx
	},	

	{
		key    =>    'ArrayRIt:declare0',
		symbol => '${TYPENAME}RIt_declare0',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@#define ${TYPENAME}RIt_declare0(var)  ${TYPENAME}RIt var = {0}
ENDxxxxxxxxxx
	},	

	{
		key     =>  'Array:foreach',
		implies => ["ArrayFIt:declare", "ArrayFIt:next"],
		symbol  => '${TYPENAME}_foreach',
		tmpl    => <<'ENDxxxxxxxxxx', 
			@#define ${TYPENAME}_foreach(var, arr)                for (${TYPENAME}FIt_declare(var, arr, 0); ${TYPENAME}FIt_next(&var); )
			@#define ${TYPENAME}_foreachOffset(var, arr, offset)  for (${TYPENAME}FIt_declare(var, arr, offset); ${TYPENAME}FIt_next(&var); )			
ENDxxxxxxxxxx
	},	

	{ 
		key =>    'Array:rforeach',
		implies => ["ArrayRIt:declare", "ArrayRIt:next"],
		symbol => '${TYPENAME}_rforeach',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@#define ${TYPENAME}_rforeach(var, arr)                for (${TYPENAME}RIt_declare(var, arr, 0); ${TYPENAME}RIt_next(&var); )
			@#define ${TYPENAME}_rforeachOffset(var, arr, offset)  for (${TYPENAME}RIt_declare(var, arr, offset); ${TYPENAME}RIt_next(&var); )
ENDxxxxxxxxxx
	},
	{ 
		key =>    'Array:rforeachOffset',
		implies => ["ArrayRIt:declare", "ArrayRIt:next"],
		symbol => '${TYPENAME}_rforeach',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@#define ${TYPENAME}_rforeachOffset(var, arr)  for (${TYPENAME}RIt_declare(var, arr, offset); ${TYPENAME}RIt_next(&var); )			
ENDxxxxxxxxxx
	},	

	{
		key =>    'Array:loop',
		implies => ["ArrayFIt:next"],
		symbol => '${TYPENAME}_loop',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@#define ${TYPENAME}_loop(var) while (${TYPENAME}FIt_next(&var)) 
ENDxxxxxxxxxx
	},

	{
		key =>    'Array:rloop',
		implies => ["ArrayRIt:next"],
		symbol => '${TYPENAME}_rloop',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@#define ${TYPENAME}_rloop(var) while (${TYPENAME}RIt_next(&var)) 			
ENDxxxxxxxxxx
	},

	{
		key     =>  'Array:each',
		implies => [],
		symbol  => '${TYPENAME}_each',
		tmpl    => <<'ENDxxxxxxxxxx', 
			@#define ${TYPENAME}_each(it, arr) for (${ELEMNAME_NS}* it = arr->data; it < arr->data + arr->len; it++)
ENDxxxxxxxxxx
	},	

	{
		key     =>  'Array:reach',
		implies => [],
		symbol  => '${TYPENAME}_reach',
		tmpl    => <<'ENDxxxxxxxxxx', 
			@#define ${TYPENAME}_reach(it, arr) for (${ELEMNAME_NS}* it = arr->data+arr->len-1; it >= arr->data; it--)
ENDxxxxxxxxxx
	},	

# 	{
# 		key =>    'Array:slice',
# 		symbol => '',
# 		tmpl   => <<'ENDxxxxxxxxxx', 
# 			@typedef struct ${TYPENAME}Slice_t {
# 			@	int len;
# 			@	${ELEMNAME}*data;
# 			@	int index;
# 			@	${ELEMNAME}*var;
# 			@} ${TYPENAME}Slice;
# ENDxxxxxxxxxx
# 	},

# 	{
# 		key =>    'Array:declareSlice',
# 		symbol => '${TYPENAME}_declareSlice',
# 		tmpl   => <<'ENDxxxxxxxxxx', 
# 			@#define ${TYPENAME}_declareSlice(name) ${TYPENAME}Slice name = {0}			
# ENDxxxxxxxxxx
# 	},

# 	{
# 		key =>    'Array:sliceEmpty',
# 		symbol => '${TYPENAME}_sliceEmpty',
# 		tmpl   => <<'ENDxxxxxxxxxx', 
# 			@#define ${TYPENAME}_sliceEmpty(slice) (slice.data == NULL)
# ENDxxxxxxxxxx
# 	},	

# 	{
# 		key =>    'Array:sliceForeach',
# 		symbol => '${TYPENAME}_sliceForeach',
# 		tmpl   => <<'ENDxxxxxxxxxx', 
# 			@#define ${TYPENAME}_sliceForeach(slice) for (slice.index=0, slice.var=slice.data; slice.index < slice.len; slice.index++, slice.var++)
# ENDxxxxxxxxxx
# 	},	

# 	{
# 		key =>    'Array:rsliceForeach',
# 		symbol => '${TYPENAME}_rsliceForeach',
# 		tmpl   => <<'ENDxxxxxxxxxx', 
# 			@#define ${TYPENAME}_rsliceForeach(slice) for (slice.index=slice.len-1, slice.var = slice.data + slice.index*sizeof(${ELEMNAME_NS}); \\
# 			@								               slice.index >= 0; slice.index--, slice.var--)
# ENDxxxxxxxxxx
# 	},	

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
			@static inline ${TYPENAME}FIt ${TYPENAME}_binSearch${TAG}(${TYPENAME} *arr, ${ELEMNAME}elem) {
			@	int (*compare)(${ELEMNAME}*, ${ELEMNAME}*) = ${COMPARE};
			@	${TYPENAME}FIt it = {0};
			@   if (Array_binSearch((Array*)arr, (char*)&elem, (Array_compare)compare, (ArrayFIt*)&it) != NULL) {
			@   	return it;
			@	}
			@   it.index  = arr->len;
			@   it.uBound = 0;
			@	return it;
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
		key =>    'Array:pqSort',
		symbol => '${TYPENAME}_pqSort${TAG}',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@static inline void ${TYPENAME}_pqSort${TAG}(${TYPENAME} *arr) {
			@	int (*compare)(${ELEMNAME}*, ${ELEMNAME}*) = ${COMPARE};
			@   Array_pqSort((Array*)arr, (Array_compare)compare);
			@}
ENDxxxxxxxxxx
	},	

	{
		key =>    'Array:pqPush',
		symbol => '${TYPENAME}_pqPush${TAG}',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@static inline void ${TYPENAME}_pqPush${TAG}(${TYPENAME} *arr, ${ELEMNAME}elem) {
			@	int (*compare)(${ELEMNAME}*, ${ELEMNAME}*) = ${COMPARE};
			@   Array_pqPush((Array*)arr, (char*)&elem, (Array_compare)compare);
			@}
ENDxxxxxxxxxx
	},	

	{
		key =>    'Array:pqPop',
		symbol => '${TYPENAME}_pqPop${TAG}',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@static inline bool ${TYPENAME}_pqPop${TAG}(${TYPENAME} *arr, ${ELEMNAME}*elem) {
			@	int (*compare)(${ELEMNAME}*, ${ELEMNAME}*) = ${COMPARE};
			@   return Array_pqPop((Array*)arr, (char*)elem, (Array_compare)compare);
			@}
ENDxxxxxxxxxx
	},	

	{
		key =>    'Array:pqPeek',
		symbol => '${TYPENAME}_pqPeek${TAG}',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@static inline ${ELEMNAME}*${TYPENAME}_pqPeek${TAG}(${TYPENAME} *arr) {
			@   return (${ELEMNAME}*)Array_pqPeek((Array*)arr);
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
		key =>    'Interface:itype',
		symbol => '',
		tmpl   => <<'ENDxxxxxxxxxx',
			@#define Interface_itype(self) (self->itype) 
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
			@static inline int ${IFCNAME}_nthIType(int n, int *itype) {
			@	static int itypes[] = {
			@		${ITYPELIST}
			@	};
			@	static int len = sizeof(itypes)/sizeof(int);
			@	if (n < 0 || n >= len) {
			@		return 0;
			@	}
			@	*itype = itypes[n];
			@	return 1;
			@}
			@#define ${IFCNAME}_foreachIType(itype) for (int __##itype = 0, itype = 0; ${IFCNAME}_nthIType(__##itype, &itype); __##itype++)
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

	{
		key =>    'Lifecycle:new',
		symbol => '',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@${TYPENAME} *${TYPENAME}_new()
			@{
			@	${TYPENAME} *self = Mem_malloc(sizeof(${TYPENAME}));
			@	${TYPENAME}_init(self);
			@	return self;
			@}
ENDxxxxxxxxxx
	},

	{
		key =>    'Lifecycle:free',
		symbol => '',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@void ${TYPENAME}_free(${TYPENAME} *self)
			@{
			@   if (self != NULL) {
			@		${TYPENAME}_clear(self);
			@		Mem_free(self);
			@   }
			@}
ENDxxxxxxxxxx
	},

	{
		key =>    'Lifecycle:initStart',
		symbol => '',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@void ${TYPENAME}_init(${TYPENAME} *self)
			@{
ENDxxxxxxxxxx
	},

	{
		key =>    'Lifecycle:initITypeField',
		symbol => '',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@	self->itype = ${TYPENAME}_itype;
ENDxxxxxxxxxx
	},

	{
		key =>    'Lifecycle:initFieldValue',
		symbol => '',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@	self->${FIELDNAME} = 0;
ENDxxxxxxxxxx
	},

	{
		key =>    'Lifecycle:initFieldPointer',
		symbol => '',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@	self->${FIELDNAME} = NULL;
ENDxxxxxxxxxx
	},

	{
		key =>    'Lifecycle:initFieldString',
		symbol => '',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@	self->${FIELDNAME} = String_empty();
ENDxxxxxxxxxx
	},

	{
		key =>    'Lifecycle:initFieldKnownPointer',
		symbol => '',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@	self->${FIELDNAME} = ${FIELDTYPE}_new();
ENDxxxxxxxxxx
	},

	{
		key =>    'Lifecycle:initFieldKnownValue',
		symbol => '',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@	${FIELDTYPE}_init(&self->${FIELDNAME});			
ENDxxxxxxxxxx
	},

	{
		key =>    'Lifecycle:initFieldKnownArrayPointer',
		symbol => '',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@	self->${FIELDNAME} = ${FIELDTYPE}_new(0);
ENDxxxxxxxxxx
	},

	{
		key =>    'Lifecycle:initFieldKnownArrayValue',
		symbol => '',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@	${FIELDTYPE}_init(&self->${FIELDNAME}, 0);
ENDxxxxxxxxxx
	},

	{
		key =>    'Lifecycle:initEnd',
		symbol => '',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@	return;
			@}
ENDxxxxxxxxxx
	},

	{
		key =>    'Lifecycle:clearStart',
		symbol => '',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@void ${TYPENAME}_clear(${TYPENAME} *self)
			@{
ENDxxxxxxxxxx
	},

	{
		key =>    'Lifecycle:initUser',
		symbol => '',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@	${TYPENAME}_userInit(self);
ENDxxxxxxxxxx
	},

	{
		key =>    'Lifecycle:clearUser',
		symbol => '',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@	${TYPENAME}_userClear(self);
ENDxxxxxxxxxx
	},

	{
		key =>    'Lifecycle:clearFieldString',
		symbol => '',
		tmpl   => <<'ENDxxxxxxxxxx',
			@	String_free(self->${FIELDNAME}); 		
ENDxxxxxxxxxx
	},

	{
		key =>    'Lifecycle:clearFieldKnownPointer',
		symbol => '',
		tmpl   => <<'ENDxxxxxxxxxx',
			@	${FIELDTYPE}_free(self->${FIELDNAME});
ENDxxxxxxxxxx
	},

	{
		key =>    'Lifecycle:clearFieldKnownValue',
		symbol => '',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@	${FIELDTYPE}_clear(&self->${FIELDNAME});
ENDxxxxxxxxxx
	},

	{
		key =>    'Lifecycle:clearEnd',
		symbol => '',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@	return;
			@}
ENDxxxxxxxxxx
	},

	{
		key =>    'Lifecycle:newProto',
		symbol => '',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@${TYPENAME} *${TYPENAME}_new();
ENDxxxxxxxxxx
	},

	{
		key =>    'Lifecycle:initProto',
		symbol => '',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@void ${TYPENAME}_init(${TYPENAME} *self);
ENDxxxxxxxxxx
	},

	{
		key =>    'Lifecycle:clearProto',
		symbol => '',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@void ${TYPENAME}_clear(${TYPENAME} *self);
ENDxxxxxxxxxx
	},

	{
		key =>    'Lifecycle:freeProto',
		symbol => '',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@void ${TYPENAME}_free(${TYPENAME} *self);
ENDxxxxxxxxxx
	},

	{
		key =>    'Coverage:preamble',
		symbol => '',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@const bool Coverage_activated = ${ACTIVATE};
			@const char **Coverage_array   = NULL;
ENDxxxxxxxxxx
	},

	{
		key =>    'Coverage:finalize',
		symbol => '',
		tmpl   => <<'ENDxxxxxxxxxx', 
			@#line 1 "**coverage**" 
			@void Coverage_initialize()
			@{
			@	Coverage_array = Mem_calloc(sizeof(const char *) * ${COVERSIZE});	
			@}
			@
			@void Coverage_finalize(const char *file)
			@{
			@	String *coverFile = Coverage_createCoverageFile(file);
			@	FILE *out = fopen(coverFile, "w");
			@	if (!out) {
			@		Error_declare(err);
			@		Error_format(err, "Failed to open coverage file %s", coverFile);
			@		Error_maypost(err);
			@		exit(1);
			@	}
			@	fprintf(out, "*totalSize %d\n", ${COVERSIZE});
			@	for (int i = 0; i < ${COVERSIZE}; i++) {
			@		if (Coverage_array[i] != NULL) {
			@			fprintf(out, "%s\n", Coverage_array[i]);
			@		}
			@	}
			@	fclose(out);
			@	String_free(coverFile);
			@}
ENDxxxxxxxxxx
	},

);
my %templateMap = map {$_->{key} => $_} @templates;

my $Expand_called = undef;

sub Expand_setCalled {
	my ($called) = @_;
	die "Bad called passed to Expand_setCalled" unless $called->{itype} eq 'Called';
	$Expand_called = $called;
}

sub Expand_expand {
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
		if ($symbol) {
			$symbol = $expandVar->($symbol);
			next unless Called_isName($Expand_called, $symbol);
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
		}
	}

	my %special = ("Array:struct" => 1, "Array:slice" => 2, "ArrayFIt:struct" => 3, "ArrayFIt:struct" => 4);
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

sub Expand_emitFull {
	my ($out, $inputKeys, $inputDictionary, %opts) = @_;
	my ($outputKeys, $res) = Expand_expand($inputKeys, $inputDictionary);
	for my $key (@$outputKeys) {
		my $t = $res->{$key};
		next unless defined($t);
		print {$out} $t;
		print {$out} "\n" if $opts{newline};
	}
}

sub Expand_emit {
	Expand_emitFull(@_, newline=>0);
}

sub Expand_emitNl {
	Expand_emitFull(@_, newline=>1);
}


sub ClassOrInterface_emitAccessors {
	my ($artifact, $out) = @_;
	my $typeName = $artifact->{typeName};
	for my $field (@{$artifact->{fields}}) {

		## XXX: this is legacy, can I remove?
		if (defined($field->{group})) {
			next;
		}
		next if $field->{name} eq 'itype';


		my $getter       = $field->{getter}; 
		my $getterReturn = $field->{getterReturn};
		my $rtype        = $field->{type};
		my $maybeAmper   = '';
		if ($getterReturn eq 'pointer') {
			$rtype      = "$rtype *";
			$maybeAmper = "&";
		}
		my $stype = Util_spaceAdjustType($rtype);
		my $setter = $field->{setter}; 
		my ($first, $rest) = ($field->{name} =~ /^(.)(.*)$/);
		die "INTERNAL ERROR" unless defined($rest);
		my $setName = 'set' . uc($first) . $rest;
	
		my $exCfg = {TYPENAME=>$typeName, STYPE=>$stype, FIELDNAME=>$field->{name}, MAYBEAMPER=>$maybeAmper, SETNAME=>$setName};
		
		if (defined($getter)) {			
			if ($getter ne 'none') {
		 		die "The 'getter' flag set to something funny: getter=$getter, typeName=$typeName";
		 	}
		} else {
			Expand_emit($out, ["Type:getter"], $exCfg);
		}
			
		if (defined($setter)) {	
			if ($setter ne 'none') {
				die "The 'setter' flag set to something funny: setter=$setter, typeName=$typeName";
			}
		} else {
			Expand_emit($out, ["Type:setter"], $exCfg);
		}
	}
}

sub ClassOrInterface_emitStruct {
	my ($artifact, $out) = @_;
	Expand_emit($out, ["Struct:head"], {TYPENAME => $artifact->{typeName}});	
	for my $field (@{$artifact->{fields}}) {
		my $stype = Util_spaceAdjustType($field->{type});
		Expand_emit($out, ["Struct:field"], {STYPE=>$stype, NAME => $field->{name}});	
	}
	Expand_emit($out, ["Struct:tail"], {});		
}

sub ClassOrInterface_emitArgDeclare {
	my ($self, $out) = @_;
	my $args = "";
	my $struct = "{";
	for my $field (@{$self->{fields}}) {
		if (defined($field->{group})) {
			next;
		}
		$args   .= "$field->{name}, ";
		$struct .= "($field->{name}), ";
	}
	$args   =~ s/,\s*$//;
	$struct =~ s/,\s*$//;
	$struct .= "}";
	Expand_emit($out, ["Type:argDeclare"], {ARGS=>$args, STRUCT=>$struct, TYPENAME=>$self->{typeName}});
}

sub ClassArtifact_new {
	return {itype => 'Class'};
}

sub ClassArtifact_isa {
	return $_[0]->{itype} eq 'Class';
}

sub ClassArtifact_emitStruct {
	ClassOrInterface_emitStruct(@_);
}

sub ClassArtifact_emitArgDeclare {
	ClassOrInterface_emitArgDeclare(@_);
}

sub ClassArtifact_emitLifecylePrototype {
	my ($self, $out) = @_;
	if (defined($self->{lifecycle}) && $self->{lifecycle} eq "manual") {
		return;
	}
	Expand_emit($out, ["Lifecycle:newProto", "Lifecycle:initProto", "Lifecycle:clearProto", "Lifecycle:freeProto"], {TYPENAME=>$self->{typeName}});
}

sub ClassArtifact_emitLifecyle {
	my ($self, $out, $api, $artifactMap) = @_;
	if ($self->{lifecycle} eq "manual") {
		return;
	}
	for my $t (qw/init clear/) {
		Expand_emit($out, ["Lifecycle:${t}Start"], {TYPENAME=>$self->{typeName}});
		if ($t eq 'clear' && Api_definedCall($api, $self->{typeName}, "userClear")) {
			Expand_emit($out, ["Lifecycle:clearUser"], {TYPENAME=>$self->{typeName}});
		} 
		for my $field (@{$self->{fields}}) {
			my $name        = $field->{name};
			my $type        = $field->{type};
			my $isItype     = $name eq 'itype';
			(my $typeName   = $type) =~ s/[\s\*]+//g;
			my $isKnown     = $artifactMap->{$typeName} ? 1 : 0;
			my $isArray     = $isKnown ? $artifactMap->{$typeName}{itype} eq 'Container' : 0;
			my $isInterface = $isKnown ? $artifactMap->{$typeName}{itype} eq 'Interface' : 0;
			my $isPointer   = ($type =~ /\*/);
			my $isString    = $typeName eq 'String';
			my $isUnmanaged = defined($field->{lifecycle}) && $field->{lifecycle} eq 'unmanaged' ? 1 : 0;
			my $dict        = {FIELDTYPE=>$typeName, FIELDNAME=>$name, TYPENAME=>$self->{typeName}};
			
			if ($isItype) {
				if ($t eq 'init') {
					Expand_emit($out, ["Lifecycle:initITypeField"], $dict);
				}
			}
			elsif ($isString) {
				Expand_emit($out, ["Lifecycle:${t}FieldString"], $dict);
			} elsif ($isKnown) {
				if ($isUnmanaged || $isInterface) {
					if ($isPointer) {
						if ($t eq 'init') {
							Expand_emit($out, ["Lifecycle:${t}FieldPointer"], $dict);
						}
					} else {
						if ($t eq 'init') {
							Expand_emit($out, ["Lifecycle:${t}FieldValue"], $dict);
						}
					}
				} elsif ($isPointer) {
					if ($isArray && $t eq 'init') {
						Expand_emit($out, ["Lifecycle:${t}FieldKnownArrayPointer"], $dict);
					} else {
						Expand_emit($out, ["Lifecycle:${t}FieldKnownPointer"], $dict);
					}
				} else {
					if ($isArray && $t eq 'init') {
						Expand_emit($out, ["Lifecycle:${t}FieldKnownArrayValue"], $dict);
					} else {
						Expand_emit($out, ["Lifecycle:${t}FieldKnownValue"], $dict);
					}
				}	
			} elsif ($isPointer) {
				if ($t eq 'init') {
					Expand_emit($out, ["Lifecycle:${t}FieldPointer"], $dict);
				}
			} else {
				if ($t eq 'init') {
					Expand_emit($out, ["Lifecycle:${t}FieldValue"], $dict);
				}
			}
		}
		if ($t eq 'init' && Api_definedCall($api, $self->{typeName}, "userInit")) {
			Expand_emit($out, ["Lifecycle:initUser"], {TYPENAME=>$self->{typeName}});
		} 
		Expand_emit($out, ["Lifecycle:${t}End"], {TYPENAME=>$self->{typeName}});
	}
	Expand_emit($out, ["Lifecycle:new", "Lifecycle:free"], {TYPENAME=>$self->{typeName}});
}


sub ClassArtifact_emitInlines {
	my ($self, $out) = @_;
	ClassOrInterface_emitAccessors($self, $out);
	if (defined($self->{argDeclare})) {
		ClassArtifact_emitArgDeclare($self, $out);
	}
	
	if (defined($self->{implements})) {
		my $h = {TYPENAME=>$self->{typeName}};
		for my $ifc (@{$self->{implements}}) {
			$h->{IFCNAME} = $ifc;
			Expand_emit($out, ['Interface:castTo', 'Interface:castFrom'], $h);
		}
	}
}


sub InterfaceArtifact_new {
	return {itype => 'Interface'};
}

sub InterfaceArtifact_isa {
	return $_[0]->{itype} eq 'Interface';
}

sub InterfaceArtifact_emitStruct {
	ClassArtifact_emitStruct(@_);
}

sub InterfaceArtifact_emitInterfaceMethod {
	my ($self, $out, $methodIndex, $justProto, $api) = @_;
	die "Bad type expected Interface found $self->{itype}" unless $self->{itype} eq 'Interface';
	my $ifcName       = $self->{typeName};
	my $method        = $self->{methods}[$methodIndex];
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
		RTYPE         => Util_spaceAdjustType($method->{retVal}),
		ENDPROTO      => ";",
		SWITCHTARGET  => $itypeReceiver ? "itype" : "self->itype",
	};

	if ($justProto) {
		Expand_emit($out, ['Interface:proto'], $cfg);
		return;
	}

	$cfg->{ENDPROTO} = "";
	my ($defClassName, $defMethodName);
	if (defined($defMethod)) {
		($defClassName, $defMethodName) = split "_", $defMethod;
	}

	Expand_emit($out, ['Interface:proto', 'Interface:startFunction'], $cfg);
	my @implementedBy = sort {$a cmp $b} keys(%{$self->{implementedBy}});
	for my $implementedBy (@implementedBy) {
		$cfg->{TYPENAME} = $implementedBy;
		if (!defined($defMethod) || Api_definedCall($api, $implementedBy, $methodName)) {
			$cfg->{CALLTYPENAME}     = $implementedBy;
			$cfg->{CALLMETHODNAME}   = $methodName;	
			$cfg->{CASTRECIEVER}     = $itypeReceiver ? "itype" : "($implementedBy*)self";
		} else {
			$cfg->{CALLTYPENAME}     = $defClassName;
			$cfg->{CALLMETHODNAME}   = $defMethodName;	
			$cfg->{CASTRECIEVER}     = $itypeReceiver ? "itype" : "self";
		}
		
		if ($absentOk && !Api_definedCall($api, $implementedBy, $methodName)) {
			if ($retVoid) {
				Expand_emit($out, ['Interface:caseAbsentVoid'], $cfg);
			} else {
				Expand_emit($out, ['Interface:caseAbsent'], $cfg);
			}
		} else {
			if ($retVoid) {
				Expand_emit($out, ['Interface:caseVoid'], $cfg);
			} else {
				Expand_emit($out, ['Interface:case'], $cfg);
			}
		}
	}
	if ($retVoid) {
		Expand_emit($out, ['Interface:endFunctionVoid'], $cfg);
	} else {
		Expand_emit($out, ['Interface:endFunction'], $cfg);
	}
	print {$out} "\n";
}

sub InterfaceArtifact_emitInlines {
	my ($self, $out) = @_;
	my @itypeList = sort map {"${_}_itype"} keys(%{$self->{implementedBy}});
	my $h = {IFCNAME => $self->{typeName}, ITYPELIST=>join(", ", @itypeList)};
	Expand_emit($out, ['Interface:foreachIType'], $h);
	ClassOrInterface_emitAccessors($self, $out);
	if (defined($self->{argDeclare})) {
		ClassOrInterface_emitArgDeclare($self, $out);
	}
}

sub InterfaceArtifact_emitInterfaceMethods {
	my ($self, $out, $api) = @_;
	for (my $methodIndex = 0; $methodIndex < @{$self->{methods}}; $methodIndex++) {
		InterfaceArtifact_emitInterfaceMethod($self, $out, $methodIndex, 0, $api);
	}
}


sub ContainerArtifact_new {
	return {itype => 'Container'};
}

sub ContainerArtifact_isa {
	return $_[0]->{itype} eq 'Container';
}

sub ContainerArtifact_emitStruct {
	my ($self, $out) = @_;

	my $TYPENAME    = $self->{typeName};
	my $ELEMNAME_NS = $self->{elemName};
	my $ELEMNAME    = "";
	if ($ELEMNAME_NS !~ /\*$/) {
		$ELEMNAME = "$ELEMNAME_NS ";
	} else {
		$ELEMNAME = $ELEMNAME_NS;
	}

	my $dict = {
		TYPENAME    => $TYPENAME, 
		ELEMNAME    => $ELEMNAME, 
		ELEMNAME_NS => $ELEMNAME_NS
	};

	# my $needsSlice = 0;
	# my $binarySearch = $self->{binarySearch};
	# if (defined($binarySearch)) {
	# 	for my $b (@$binarySearch) {
	# 		if ($b->{multi}) {
	# 			$needsSlice = 1;
	# 			last;
	# 		}
	# 	}
	# }
	
	my @keys = ("Array:struct", 'ArrayFIt:struct', 'ArrayRIt:struct');
	# if ($needsSlice) {
	# 	push @keys, "Array:slice";
	# }
	Expand_emitNl($out, \@keys, $dict);
	return
}

sub ContainerArtifact_emitInlines {
	my ($self, $out) = @_;
	my $TYPENAME    = $self->{typeName};
	my $ELEMNAME_NS = $self->{elemName};
	my $CLEARER     = $self->{clearer};
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
	my $binarySearch = $self->{binarySearch};

	# my $needsSlice = 0;
	# if (defined($binarySearch)) {
	# 	my $needslice = 0;
	# 	for my $b (@$binarySearch) {
	# 		if ($b->{multi}) {
	# 			$needsSlice = 1;
	# 			last;
	# 		}
	# 	}
	# }

	my $dict = {
		TYPENAME=>$TYPENAME, 
		ELEMNAME_NS=>$ELEMNAME_NS, 
		ELEMNAME=>$ELEMNAME, 
		CLEARER=>$CLEARER, 
		ELEMZERO=>$ELEMZERO,
		ELEMPTR=>$ELEMPTR,
		ELEMNAME_NP=>$ELEMNAME_NP,
	};

	##
	## Setup base keys
	##
	my @keys = (
		'Array:new', 'Array:init', 'Array:clear', 'Array:free',
		'Array:truncate', 'Array:len',  'Array:get', 'Array:getp', 'Array:at', 'Array:atp', 'Array:set', 'Array:setp',
		'Array:pop', 'Array:push', 'Array:pushp', 'Array:insert', 'Array:insertp', 'Array:remove',
		'Array:removeN', 'Array:fit', 'Array:last', 'Array:changeLength', 'Array:foreach', 'Array:rforeach',
		'Array:loop', 'Array:rloop', "ArrayFIt:next", "ArrayRIt:next", "ArrayFIt:remove", "ArrayRIt:remove",
		"ArrayFIt:declare0", "ArrayFIt:declare", "ArrayRIt:declare0", "ArrayRIt:declare", "ArrayFIt:atEnd", "ArrayRIt:atEnd"
	);

	push @keys, ('Array:each', 'Array:reach');
	# if ($needsSlice) {
	# 	push @keys, "Array:declareSlice", "Array:sliceEmpty", "Array:sliceForeach", "Array:rsliceForeach";
	# }	
	
	Expand_emitNl($out, \@keys, $dict);
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

			my @keys = ('Array:binInsert', 'Array:binRemove', 'Array:sort', 
						"Array:pqSort", "Array:pqPush", "Array:pqPop", "Array:pqPeek");
			if ($domulti) {
				$dict->{MULTI} = "true";
				push @keys, "Array:binSearchSliceReturn";
			} else {
				$dict->{MULTI} = "false";
				push @keys, "Array:binSearchElemReturn";
			}
			Expand_emitNl($out, \@keys, $dict);
		}
	}
}

sub Coverage_new {
	my ($coverageActivated) = @_;
	return {
		itype => "Coverage", 
		coverageIndex => 0, 
		coverageOn => 1, 
		coverageActivated => $coverageActivated ? 1 : 0,
		directory => "test/coverage",
	};
}

sub Coverage_openTriedFile {
	my ($self, $srcPath) = @_;
	return unless $self->{coverageActivated};
	my ($basename) = ($srcPath =~ m{([^/]+)$});
	die "INTERNAL ERROR" unless defined($basename);
	my $triedFile  = "$self->{directory}/$basename.tried";
	open my $fd, ">", $triedFile or die "Failed to open $triedFile";
	$self->{triedOut} = $fd;
}

sub Coverage_closeTriedFile {
	my ($self) = @_;
	return unless $self->{coverageActivated};
	close($self->{triedOut});
	$self->{triedOut} = undef;
}

sub Coverage_writePreamble {
	my ($self, $out) = @_;
	Expand_emit($out, ['Coverage:preamble'], {ACTIVATE => $self->{coverageActivated} ? "true" : "false"});
}

sub Coverage_writeFinalize {
	my ($self, $out) = @_;
	Expand_emit($out, ['Coverage:finalize'], {COVERSIZE => $self->{coverageIndex}});
}

## This is a strange function. It takes a line of text and tests that it doesn't look like a function def that
## DOES NOT have either COVER or APIF. But if it finds such a line, it looks at the rest of the file
## it's working on for other unmarked functions, and then aborts.
sub Coverage_verifyNoUnmarkedFunctions {
	my ($self, $text, $inp, $filename, $line) = @_;
	return if /^\s/;
	return if m[^(?:NOCOVER|COVER|APIF|\#|\s*/)];
	return unless (/^\S/ && /\(/ && !/;\s*$/);

	my $err = sub {
		print "COVER BUG at line $line file $filename: `$_[0]`\n";
	};
	$err->($text);
	while (<$inp>) {
		chomp;
		$line++;
		next if /^\s/;
		next if m[^(?:NOCOVER|COVER|APIF|\#|\s*/)];
		if (/^\S/ && /\(/ && !/;\s*$/) {
			$err->($_);
		}
	}
	die "COVER FATALITY";
}

sub Coverage_write {
	my ($self, $out, $text, $file, $line, $inp) = @_;
	if ($self->{coverageOn}) {
		Coverage_verifyNoUnmarkedFunctions($self, $text, $inp, $file, $line);
	}

	my $hasAPIF         = ($text =~ /^APIF/ || $text =~ /^COVER/);
	my $looksLikeDefine = ($text =~ /^#/);
	my $looksLikeCase   = ($text =~ /^\s*case/);
	if ($self->{inFunction} || $hasAPIF) {
		my $lead = "";
		if ($looksLikeDefine) {
			$lead = "#";
			$text =~ s/^#//;
		} elsif (!$looksLikeCase && !$hasAPIF && !$self->{needOpenBracket} && $self->{coverageOn}) {
			my $coverageIndex = $self->{coverageIndex}++;
			my $coverageLine  = "$file $line";
			my $triedOut      = $self->{triedOut};
			print {$triedOut} "$coverageLine\n";
			$lead = "Coverage_array[$coverageIndex] = \"$coverageLine\"; ";
		}
		$text =~ s/\t/    /g;
		printf {$out} "%-55s%s\n", $lead, $text;
	} else {
		print {$out} "$text\n";
	}

	if ($self->{inFunction} && $text =~ /^\}/) {
		$self->{inFunction} = 0;
	} elsif ($hasAPIF) {
		die "Found APIF while waiting for close of APIF function" if $self->{inFunction};
		$self->{inFunction}      = 1;
		$self->{needOpenBracket} = ($text !~ m{\{\s*$} );
	} elsif ($self->{needOpenBracket} && $text =~ /^\s*\{/) {
		$self->{needOpenBracket} = 0;
	} elsif ($text =~ /Coverage_off/) {
		$self->{coverageOn} = 0;
	} elsif ($text =~ /Coverage_on/) {
		$self->{coverageOn} = 1;
	}
}

sub TemplateFile_scanUntilAtEnd {
	my ($self) = @_;
	die "Bad type" unless $self->{itype} eq 'TemplateFile';
	my $start = $self->{line};
	my $found = 0;
	my @text;
	my $inp = $self->{inp};
	while (<$inp>) {
		$self->{line}++;
		chomp;

		## Remove C++ comments from the line
		s[//.*][];

		if (/^\@end/) {
			$found = 1;
			last;
		}
		if (/^\@/) {
			die "Failed to find \@end while processing \@type at line $start and failing on line $self->{line}";
		}
		push @text, $_;
	}
	if (!$found) {
		die "Failed to find \@end: found EOF started at line $start";
	}
	return @text;
}

sub TemplateFile_scanArtifact {
	my ($self, $artifact) = @_;
	die "Bad type" unless $self->{itype} eq 'TemplateFile';
	my $startLine = $self->{line};
	my @text = TemplateFile_scanUntilAtEnd($self);
	my $buffer = join("\n", @text);
	# print "START\n$buffer\nEND\n";
	eval {
		my $art = decode_json($buffer);
		for my $k (keys(%$art)) {
			$artifact->{$k} = $art->{$k};
		}
		$artifact->{srcFile} = $self->{file};
		$artifact->{fields}  = [] unless (defined($artifact->{fields}) || ContainerArtifact_isa($artifact));
	};
	if ($@) {
		my $commaEnd          = 0;
		my $closeBracketStart = 0;
		my $count             = 0;
		for my $line (@text) {
			$closeBracketStart = ($line =~ /^\s*[}\]]/);
			if ($closeBracketStart && $commaEnd) {
				printf {*STDERR} "Suspicious comma in file %s at line %d\n", $self->{file}, ($startLine + $count);
			}
			$commaEnd = ($line =~ /,\s*$/);
			$count++;
		}
		die "Failed to decode json for type in file $self->{file}, starting at $startLine\n$@";
	}
	return $artifact;
}

sub TemplateFile_scanAllArtifacts {
	my ($self) = @_;
	die "Bad type" unless $self->{itype} eq 'TemplateFile';
	open my $inp, "<", $self->{file} or die "Failed to open $self->{file}";
	$self->{inp} = $inp;
	my @artifacts;
	while (<$inp>) {
		chomp;
		$self->{line}++;
		if (/^\@type/) {
			push @artifacts, TemplateFile_scanArtifact($self, ClassArtifact_new());
		} elsif (/^\@interface/) {
			push @artifacts, TemplateFile_scanArtifact($self, InterfaceArtifact_new());
		} elsif (/^\@container/) {
			push @artifacts, TemplateFile_scanArtifact($self, ContainerArtifact_new());
		} elsif (/^\@header/) {
			TemplateFile_scanUntilAtEnd($self);
		}
	}

	close($self->{inp});
	return @artifacts;
}

sub TemplateFile_copyTemplateCode {
	my ($self, $out, $coverage) = @_;
	die "Bad type" unless $self->{itype} eq 'TemplateFile';
	open my $inp, "<", $self->{file} or die "Failed to open $self->{file}";
	$self->{inp} = $inp;
	
	my $lineDir = sub {
		print {$out} "#line ", $self->{line}+1, " \"$self->{file}\"\n";
	};
	$self->{line} = 0;
	$lineDir->();

	my $triedOut;
	if ($gGenerateCoverage) {
		Coverage_openTriedFile($coverage, $self->{file});
	}

	my $file = $self->{file};
	if ($file =~ m{([^/]+)$}) {
		$file = $1;
	}

	while (<$inp>) {
		chomp;
		$self->{line}++;
		if (/^\@type/) {
			TemplateFile_scanUntilAtEnd($self);
			$lineDir->();
		} elsif (/^\@interface/) {
			TemplateFile_scanUntilAtEnd($self);
			$lineDir->();
		} elsif (/^\@container/) {
			TemplateFile_scanUntilAtEnd($self);
			$lineDir->();
		} elsif (/^\@header/) {
			TemplateFile_scanUntilAtEnd($self);
			$lineDir->();
		} else {
			if ($gGenerateCoverage) {
				Coverage_write($coverage, $out, $_, $file, $self->{line}, $inp);
			} else {
				print {$out} "$_\n";
			}
		}
	}
	Coverage_closeTriedFile($coverage) if ($gGenerateCoverage);
	close($self->{inp});
}

sub TemplateFile_copyHeader {
	my ($self, $out) = @_;
	die "Bad type" unless $self->{itype} eq 'TemplateFile';
	open my $inp, "<", $self->{file} or die "Failed to open $self->{file}";
	$self->{inp} = $inp;
	while (<$inp>) {
		chomp;
		$self->{line}++;
		if (/^\@type/) {
			TemplateFile_scanUntilAtEnd($self);
		} elsif (/^\@interface/) {
			TemplateFile_scanUntilAtEnd($self);
		} elsif (/^\@container/) {
			TemplateFile_scanUntilAtEnd($self);
		} elsif (/^\@header/) {
			my @lines = TemplateFile_scanUntilAtEnd($self);
			for my $line (@lines) {
				print {$out} "$line\n";
			}
		} 
	}
	close($self->{inp});	
}

sub TemplateFile_new {
	my ($file) = @_;
	return {itype => 'TemplateFile', file=>$file, line => 0};
}

sub ArtifactList_new {
	return {itype => 'ArtifactList'}
}

sub ArtifactList_scanFromTemplateFiles {
	my ($self, @templateFiles) = @_;
	die "Bad type" unless $self->{itype} eq 'ArtifactList';
	my @artifacts;
	for my $file (@templateFiles) {
		my $templateFile = TemplateFile_new($file);
		push @artifacts, TemplateFile_scanAllArtifacts($templateFile);
	}

	## Pull any types out of Class and Interface
	my @additionalArtifacts;
	for my $artifact (@artifacts) {
		next unless (ClassArtifact_isa($artifact) || InterfaceArtifact_isa($artifact));
		my $containers = $artifact->{containers};
		next unless defined($containers); 
		for my $cont (@{$containers}) {
			if ($cont->{type} eq 'array') {
				my $container = ContainerArtifact_new();
				for my $k (keys(%$cont)) {
					$container->{$k} = $cont->{$k};
				}	
				push @additionalArtifacts, $container;
			} else {
				die "Unknown container type $cont->{type}";
			}
		}
	}
	push @artifacts, @additionalArtifacts;
	@artifacts = sort {$a->{typeName} cmp $b->{typeName}} @artifacts;


	## Add itype to fields as needed. Crossreference classes and interfaces
	my %artMap = map {$_->{typeName} => $_} @artifacts;
	my $nextItype = $gUndefinedItype + 1;
	for my $artifact (@artifacts) {
		if (ClassArtifact_isa($artifact)) {
			if (defined($artifact->{implements}) && @{$artifact->{implements}} > 0) {
				$artifact->{itypeIndex} = $nextItype++;	
			}	
			my $implements = $artifact->{implements};
			next unless defined($implements);
			unshift @{$artifact->{fields}}, {name=>"itype", type=>"int"}; 
			for my $interfaceName (@{$artifact->{implements}}) {
				my $interface = $artMap{$interfaceName};
				die "Class $artifact->{typeName} implements non-existent interface $interfaceName" unless defined($interface);
				my $implementedBy = $interface->{implementedBy};
				if (!defined($implementedBy)) {
					$implementedBy              = {};
					$interface->{implementedBy} = $implementedBy;
				}
				$implementedBy->{$artifact->{typeName}} = 1;
			}
		} elsif (InterfaceArtifact_isa($artifact)) {
			unshift @{$artifact->{fields}}, {name=>"itype", type=>"int"};
		}
	}

	$self->{artifacts}   = \@artifacts;
	$self->{artifactMap} = \%artMap;
	return;
}

sub ArtifactList_emitPredefined {
	my ($self, $out) = @_;
	for my $artifact (@{$self->{artifacts}}) {
		if (ClassArtifact_isa($artifact) && defined($artifact->{aliasFor})) {
			Expand_emit($out, ['Predefined:alias'], {ALIAS=>$artifact->{aliasFor}, TYPENAME=>$artifact->{typeName}});
		} else {
			Expand_emit($out, ['Predefined:struct'], {TYPENAME=>$artifact->{typeName}});
		}
	}
}

sub Util_copyFile {
	my ($file, $out) = @_;
	open my $inp, "<", $file or die "Failed to open $file";
	while (<$inp>) {
		print {$out} $_;
	}
	close($inp);
}

sub ArtifactList_emitStructs {
	my ($self, $out) = @_;
	my $artifacts = $self->{artifacts};
	my @structNamesToWrite = map {$_->{typeName}} @$artifacts;
	my %artMap = map {$_->{typeName} => $_} @$artifacts;

	my %valueDepend;
	for my $structName (@structNamesToWrite) {
		my $artifact = $artMap{$structName};
		die "INTERNAL ERROR" if defined($valueDepend{$structName});
		my $subhash = {};
		$valueDepend{$structName} = $subhash;
		if (ContainerArtifact_isa($artifact)) {
			if ($artifact->{elemName} !~ /\*/ && defined($artMap{$artifact->{elemName}})) {
				$subhash->{$artifact->{elemName}} = 1;	
			}
		} else {
			for my $field (@{$artifact->{fields}}) {
				if ($field->{type} !~ /\*/ && defined($artMap{$field->{type}})) {
					$subhash->{$field->{type}} = 1;
				}
			}
		}
	}

	## Start by writing the Array structs
	Artifact_emitStruct({itype => 'Container', typeName=>"Array", elemName=>"char"}, $out);
	Util_copyFile("$gMasterSourceDir/array.c", $out);
	
	my %written;
	my %queued;
	my $wt;
	$wt = sub {
		my ($structName) = @_;
		return if !defined($structName);
		return if $written{$structName};
		die "Unable to output structs in the right order" if $queued{$structName};
		
		my $depends = $valueDepend{$structName} || die "INTERNAL ERROR";
		for my $artifactName (keys(%$depends)) {
			if (!$written{$artifactName}) {				
				$queued{$structName} = 1;
				$wt->($artifactName);
				delete($queued{$structName});
			}
		}
		$written{$structName} = 1;
		my $artifact = $artMap{$structName} || die "INTERNAL ERROR";
		Artifact_emitStruct($artifact, $out);
	};
	while (@structNamesToWrite) {
		$wt->(pop @structNamesToWrite, \@structNamesToWrite);
	}
}

sub ArtifactList_emitInterfaceDefines {
	my ($self, $out) = @_;
	

	Expand_emit($out, ["Interface:undefined"], {ITYPE=>$gUndefinedItype});
	for my $artifact (@{$self->{artifacts}}) {
		if (ClassArtifact_isa($artifact) && defined($artifact->{itypeIndex})) {
			printf {$out} "#define $artifact->{typeName}_itype $artifact->{itypeIndex}\n";
		}
	}
	Expand_emit($out, ["Interface:itype"], {});
	for my $artifact (@{$self->{artifacts}}) {
		if (InterfaceArtifact_isa($artifact)) {
			for (my $methodIndex = 0; $methodIndex < @{$artifact->{methods}}; $methodIndex++) {
				my $method = $artifact->{methods}[$methodIndex];
				InterfaceArtifact_emitInterfaceMethod($artifact, $out, $methodIndex, 1);
			}
		}
	}
}

sub ArtifactList_emitInlines {
	my ($self, $out, $api) = @_;
	for my $artifact (@{$self->{artifacts}}) {
		Artifact_emitInlines($artifact, $out, $api);
	}
}

sub ArtifactList_emitInterfaceMethods {
	my ($self, $out, $api) = @_;	
	## Write all interface methods
	for my $artifact (@{$self->{artifacts}}) {
		Artifact_emitInterfaceMethods($artifact, $out, $api);
	}

	## Write toString
	my $cfg = {
		RTYPE         => Util_spaceAdjustType("const char *"),
		IFCNAME       => "Interface",
		METHODNAME    => "toString",
	};
	Expand_emit($out, ['Interface:protoToString'], $cfg);
	Expand_emit($out, ['Interface:startFunction'], {SWITCHTARGET => "itype"});
	Expand_emit($out, ['Interface:caseToString'], {TYPENAME => "Undefined"});
	for my $artifact (@{$self->{artifacts}}) {
		next unless ClassArtifact_isa($artifact);
		next unless @{$artifact->{implements} || []} > 0;
		Expand_emit($out, ['Interface:caseToString'], {TYPENAME => $artifact->{typeName}});
	}
	Expand_emit($out, ['Interface:endFunctionToString'], {});		
}

sub ArtifactList_emitLifecylePrototype {
	my ($self, $out, $api, $artifactMap) = @_;
	for my $artifact (@{$self->{artifacts}}) {
		Artifact_emitLifecyclePrototype($artifact, $out, $api, $self->{artifactMap});
	}	
}

sub ArtifactList_emitLifecyle {
	my ($self, $out, $api, $artifactMap) = @_;
	for my $artifact (@{$self->{artifacts}}) {
		Artifact_emitLifecycle($artifact, $out, $api, $self->{artifactMap});
	}	
}

sub Util_spaceAdjustType {
	my ($type) = @_;
	return $type =~ /\*$/ ? $type : "$type ";
}

sub Artifact_emitStruct {
	my ($artifact, $out) = @_;
	my %vtable = (
		"Container" => \&ContainerArtifact_emitStruct,
		"Class"     => \&ClassArtifact_emitStruct,
		"Interface" => \&InterfaceArtifact_emitStruct,
	);
	my $f = $vtable{$artifact->{itype}};
	die "Bad artifact passed to Artifact_emitStruct '$artifact->{itype}'" unless defined($f);
	$f->($artifact, $out);
}

sub Artifact_emitInlines {
	my ($artifact, $out) = @_;
	my %vtable = (
		"Container" => \&ContainerArtifact_emitInlines,
		"Class"     => \&ClassArtifact_emitInlines,
		"Interface" => \&InterfaceArtifact_emitInlines,
	);
	my $f = $vtable{$artifact->{itype}};
	die "Bad artifact passed to Artifact_emitInlines '$artifact->{itype}'" unless defined($f);
	$f->($artifact, $out);
}

sub Artifact_emitInterfaceMethods {
	my ($artifact, $out, $api) = @_;
	if (InterfaceArtifact_isa($artifact)) {
		InterfaceArtifact_emitInterfaceMethods($artifact, $out, $api);
	}
}

sub Artifact_emitLifecyclePrototype {
	my ($artifact, $out, $api, $artifactMap) = @_;
	if (ClassArtifact_isa($artifact)) {
		ClassArtifact_emitLifecylePrototype($artifact, $out);
	}
}

sub Artifact_emitLifecycle {
	my ($artifact, $out, $api, $artifactMap) = @_;
	if (ClassArtifact_isa($artifact)) {
		ClassArtifact_emitLifecyle($artifact, $out, $api, $artifactMap);
	}
}

sub Called_new {
	return {itype => "Called"};
}

sub Called_scan {
	my ($self, $templateFiles) = @_;
	my %used = (PortRef => {port => 1, outlet => 1});
	for my $source (@$templateFiles) {
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
	$self->{used} = \%used;
}

sub Called_setAllUsed {
	$_[0]->{allUsed} = 1;
}

sub Called_clearAllUsed {
	$_[0]->{allUsed} = 0;	
}

sub Called_isName {
	my ($self, $name) = @_;
	my ($className, $methodName) = split "_", $name;
	die "Bad name passed to Called_isName" unless defined($methodName);
	return $self->{allUsed} || $self->{used}{$className}{$methodName};
}

sub Called_is {
	my ($self, $className, $methodName) = @_;
	return $self->{allUsed} || $self->{used}{$className}{$methodName};	
}

sub Api_new {
	return {itype => 'Api'};
}

sub Api_scan {
	my ($self, $templateFiles) = @_;

	my @funcs = ("const char *Interface_toString(int itype)");
	for my $source (@$templateFiles) {
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
	$self->{funcs}        = \@funcs;
	$self->{definedCalls} = \%definedCalls;
}

sub Api_emitPrototypes {
	my ($self, $out) = @_;
	for my $line (@{$self->{funcs}}) {
		print {$out} $line,";\n";
	}
}

sub Api_definedCall {
	my ($self, $className, $methodName) = @_;
	return $self->{definedCalls}{$className}{$methodName};
}

sub Main_handleArgs {
	my @beforeArgs = @ARGV;
	my @afterArgs;
	my %opts;
	my $needArg = sub {
		my ($name) = @_;
		my $a = shift @beforeArgs;
		die "Option $name needs an arg but doesn't have one" unless defined($a);
		return $a;
	};
	while (1) {
		my $a = shift @beforeArgs;
		last unless defined($a);
		if ($a =~ /-g/) {
			$gApplicationName = $needArg->("-g");
		} elsif ($a =~ /-a/) {
			$gAcceptAllCalls = 1;
		} elsif ($a =~ /-c/) {
			$gGenerateCoverage = 1;
		} elsif ($a =~ /^-/){
			die "Unknown option $a"
		} else {
			push @afterArgs, $a;
		}
	}
	return @afterArgs;
}

sub Main_listTemplateFiles {
	my (@srcDirs) = @_;
	my @templateFiles;
	for my $srcDir (@srcDirs) {
		$srcDir =~ s[/$][];
		my @lines = backtick "ls $srcDir/*.in.c";
	
		for my $line (@lines) {
			$line =~ s/^\s*//;
			$line =~ s/\s*$//;
			if ($line =~ /\.in\.c$/) {
				push @templateFiles, $line;
			} 
		}
	}

	return @templateFiles;
}

sub Main_emitWarning {
	my ($out) = @_;
	for my $i (0 .. 9) {
		print {$out} "// *** DO NOT MODIFY THIS FILE generated $gNow ***\n";
	}
}

sub Main_readIgnores {
	my $file = "generate_ignores.json";
	if (-r $file) {
		my @line;
		open my $fd, "<", $file or die "Failed to open $file";
		while (<$fd>) {
			push @line, $_;
		}
		close($fd);
		my $buffer = join('', @line);
		my $hash = decode_json($buffer);
		die "Ill formed file $file" unless defined($hash->{ignores});
		return sub {
			my ($file) = @_;
			my ($base) = ($file =~ m{/([^/]+)$});
			return 0 unless defined($base);
			return $hash->{ignores}{$base};
		};
	}
	return sub {return 0;};
}

sub Main_main {
	my @srcDirs = Main_handleArgs();
	die "Requires at least one argument" unless @srcDirs > 0;
	my @templateFiles = Main_listTemplateFiles(@srcDirs);
	my $ignoreSub       = Main_readIgnores();
	@templateFiles = grep {!$ignoreSub->($_)} @templateFiles;
	
	my $called = Called_new();
	my $api    = Api_new();

	if (!defined($gMasterSourceDir)) {
		$gMasterSourceDir = $srcDirs[0];
	}
	$gMasterSourceDir =~ s[/$][];
	my @extraCallFiles = ("$gMasterSourceDir/shared.c", "$gMasterSourceDir/hub.c", "$gMasterSourceDir/port.c",);
	Called_scan($called, [@extraCallFiles, @templateFiles]);
	
	## For now I accept everything. This is because when I have interface methods that rely on method accessors, the method
	## accessors may note be generated. We need to search for interface methods that rely on method accessors, and add those
	## accessors to the Called_is list.
	$gAcceptAllCalls = 1;
	if ($gAcceptAllCalls) {
		Called_setAllUsed($called);
	}

	Expand_setCalled($called);
	Api_scan($api, \@templateFiles);
	my $artifactList = ArtifactList_new();
	ArtifactList_scanFromTemplateFiles($artifactList, @templateFiles);
	
	my $outFile = $gApplicationName;
	if (!defined($outFile)) {
		$outFile = "$gMasterSourceDir/application.c";
	}
	
	my $coverage = Coverage_new($gGenerateCoverage);

	## Let's write the application
	open my $out, ">", $outFile or die "Failed to open $outFile";
	Main_emitWarning($out);
	Coverage_writePreamble($coverage, $out);
	ArtifactList_emitPredefined($artifactList, $out);
	ArtifactList_emitStructs($artifactList, $out);
	Api_emitPrototypes($api, $out);
	ArtifactList_emitLifecylePrototype($artifactList, $out);
	ArtifactList_emitInterfaceDefines($artifactList, $out);
	ArtifactList_emitInlines($artifactList, $out);
	ArtifactList_emitLifecyle($artifactList, $out, $api);
	for my $tFile (@templateFiles) {
		my $templateFile = TemplateFile_new($tFile);
		TemplateFile_copyHeader($templateFile, $out);	
	}
	ArtifactList_emitInterfaceMethods($artifactList, $out, $api);
	for my $tFile (@templateFiles) {
		my $templateFile = TemplateFile_new($tFile);
		TemplateFile_copyTemplateCode($templateFile, $out, $coverage);	
	}
	Coverage_writeFinalize($coverage, $out);
	close($out);
	
	return;
}	

Main_main();
