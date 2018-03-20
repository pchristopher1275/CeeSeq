#!/usr/bin/perl
use strict;
use lib "$ENV{HOME}/CeeSeq/script/lib";
use JSON::Tiny qw(decode_json encode_json);
use POSIX qw(strftime);
use Data::Dumper;

my $gVerbose             = 1;
my $gApplicationName     = "application";
my $gAcceptAllCalls      = 0;
my $gNow                 = strftime("%m/%d/%Y %H:%M:%S", localtime);

## XXX: temporary
my $gUsedCalls = undef;

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

sub ClassArtifact_new {
	return {itype => 'Class'};
}

sub ClassArtifact_isa {
	return $_[0]->{itype} eq 'Class';
}

sub InterfaceArtifact_new {
	return {itype => 'Interface'};
}

sub InterfaceArtifact_isa {
	return $_[0]->{itype} eq 'Interface';
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

	my $needsSlice = 0;
	my $binarySearch = $self->{binarySearch};
	if (defined($binarySearch)) {
		for my $b (@$binarySearch) {
			if ($b->{multi}) {
				$needsSlice = 1;
				last;
			}
		}
	}
	
	my @keys = ("Array:struct", 'ArrayIt:struct');
	if ($needsSlice) {
		push @keys, "Array:slice";
	}
	Expand_emitNl($out, \@keys, $dict);
	return
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
		} 
	}

	close($self->{inp});
	return @artifacts;
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

	## Add itype to fields as needed. Crossreference classes and interfaces
	my %artMap = map {$_->{typeName} => $_} @artifacts;
	for my $artifact (@artifacts) {
		if (ClassArtifact_isa($artifact)) {
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

	$self->{artifacts} = \@artifacts;
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

sub writeStruct {
	my ($out, $classOrInterface) = @_;
	pexpand($out, ["Struct:head"], {TYPENAME => $classOrInterface->{typeName}});	
	for my $field (@{$classOrInterface->{fields}}) {
		my $stype = spaceAdjustType($field->{type});
		pexpand($out, ["Struct:field"], {STYPE=>$stype, NAME => $field->{name}});	
	}
	pexpand($out, ["Struct:tail"], {});
}

sub Util_spaceAdjustType {
	my ($type) = @_;
	return $type =~ /\*$/ ? $type : "$type ";
}

sub Artifact_emitStruct {
	my ($artifact, $out) = @_;
	if (ClassArtifact_isa($artifact) || InterfaceArtifact_isa($artifact)) {
		Expand_emit($out, ["Struct:head"], {TYPENAME => $artifact->{typeName}});	
		for my $field (@{$artifact->{fields}}) {
			my $stype = Util_spaceAdjustType($field->{type});
			Expand_emit($out, ["Struct:field"], {STYPE=>$stype, NAME => $field->{name}});	
		}
		Expand_emit($out, ["Struct:tail"], {});		
	} elsif (ContainerArtifact_isa($artifact)) {
		ContainerArtifact_emitStruct($artifact, $out);
	}
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
	ContainerArtifact_emitStruct({itype => 'Container', typeName=>"Array", elemName=>"char"}, $out);
	

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
		} else {
			push @afterArgs, $a;
		}
	}
	return @afterArgs;
}

sub Main_listTemplateFiles {
	my ($srcDir, $includeList) = @_;
	$srcDir =~ s[/$][];
	my @lines = backtick "ls $srcDir/*.in.c";
	my @templateFiles;
	for my $line (@lines) {
		$line =~ s/^\s*//;
		$line =~ s/\s*$//;
		if ($line =~ /\.in\.c$/) {
			push @templateFiles, $line;
		} 
	}
	
	if (defined($includeList)) {
		my %includeHash = map {$_ => 1} @$includeList;
		my @a = @templateFiles;
		@templateFiles = ();
		for my $file (@a) {
			push @templateFiles, $file if $includeHash{$file};
		}
	}

	return @templateFiles;
}

sub Main_emitWarning {
	my ($out, $file) = @_;
	my $message = defined($file) ? "source = $file" : '';
	print {$out} "// $message     *** DO NOT MODIFY THIS FILE generated $gNow ***\n";
}

sub Main_main {
	my @args = Main_handleArgs();
	die "Requires at least one argument" unless @args > 0;
	my $srcDir = $args[0];
	my @templateFiles = Main_listTemplateFiles(shift @args, @args);
	my $artifactList = ArtifactList_new();
	ArtifactList_scanFromTemplateFiles($artifactList, @templateFiles);

	my $outFile = "$srcDir/$gApplicationName.c";
	open my $out, ">", $outFile or die "Failed to open $outFile";

	Main_emitWarning($out);
	ArtifactList_emitPredefined($artifactList, $out);
	ArtifactList_emitStructs($artifactList, $out);
	close($out);
	

	return;
}	

Main_main();
