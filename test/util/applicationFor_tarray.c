// *** DO NOT MODIFY THIS FILE generated 03/25/2018 17:01:19 ***
// *** DO NOT MODIFY THIS FILE generated 03/25/2018 17:01:19 ***
// *** DO NOT MODIFY THIS FILE generated 03/25/2018 17:01:19 ***
// *** DO NOT MODIFY THIS FILE generated 03/25/2018 17:01:19 ***
// *** DO NOT MODIFY THIS FILE generated 03/25/2018 17:01:19 ***
// *** DO NOT MODIFY THIS FILE generated 03/25/2018 17:01:19 ***
// *** DO NOT MODIFY THIS FILE generated 03/25/2018 17:01:19 ***
// *** DO NOT MODIFY THIS FILE generated 03/25/2018 17:01:19 ***
// *** DO NOT MODIFY THIS FILE generated 03/25/2018 17:01:19 ***
// *** DO NOT MODIFY THIS FILE generated 03/25/2018 17:01:19 ***
struct Foo_t;
typedef struct Foo_t Foo;
struct IntArr_t;
typedef struct IntArr_t IntArr;
struct FooArr_t;
typedef struct FooArr_t FooArr;
typedef struct Array_t {
   int len;
   int cap;
   int elemSize;
   void (*clearer)(char*);
   char *data;
} Array;

typedef struct ArrayIt_t {
   Array *arr;
   int index;
   bool last;
   char *var;
} ArrayIt;

#include "../../src/array.c"
struct Foo_t
{
    int i;
    double d;
};
typedef struct FooArr_t {
   int len;
   int cap;
   int elemSize;
   void (*clearer)(Foo*);
   Foo *data;
} FooArr;

typedef struct FooArrSlice_t {
    int len;
    Foo *data;
    int index;
    Foo *var;
} FooArrSlice;

typedef struct FooArrIt_t {
   FooArr *arr;
   int index;
   bool last;
   Foo *var;
} FooArrIt;

typedef struct IntArr_t {
   int len;
   int cap;
   int elemSize;
   void (*clearer)(int*);
   int *data;
} IntArr;

typedef struct IntArrIt_t {
   IntArr *arr;
   int index;
   bool last;
   int *var;
} IntArrIt;

const char *Interface_toString(int itype);
typedef struct Undefined_t {
    int itype;
    char buffer[1024];
} Undefined;
#define Undefined_itype 10
Undefined Undefined_instance = {Undefined_itype, {0}};
#define Undefined_ptr(typeName) ((typeName*)&Undefined_instance)
#define Foo_newUninitialized() ((Foo*)sysmem_newptrclear(sizeof(Foo)))        
static inline int Foo_i(Foo *self){return self->i;}
static inline void Foo_setI(Foo *self, int value){self->i = value;}
static inline double Foo_d(Foo *self){return self->d;}
static inline void Foo_setD(Foo *self, double value){self->d = value;}
static inline void IntArr_changeLength(IntArr *arr, int newLength) {
    Array_changeLength((Array*)arr, newLength);
}                        

static inline void IntArr_clear(IntArr *arr) {
    Array_clear((Array*)arr);
    IntArr zero = {0};
    *arr = zero;
}

#define IntArr_each(it, arr) for (int* it = arr->data; it < arr->data + arr->len; it++)

static inline void IntArr_fit(IntArr *arr) {
    Array_fit((Array*)arr);
}

#define IntArr_foreach(var, arr)  for (IntArrIt_declare(var, arr); IntArrIt_next(&var); )            

static inline void IntArr_free(IntArr *arr) {
    Array_free((Array*)arr);
}

static inline int IntArr_get(IntArr *arr, int index, Error *err) {
    int v = 0;
    Array_getCheck(arr, index, v, err);
    memmove(&v, Array_get((Array*)arr, index), Array_elemSize((Array*)arr));
    return v;
}

static inline int *IntArr_getp(IntArr *arr, int index, Error *err) {
    Array_getCheck(arr, index, NULL, err);
    return (int *)Array_get((Array*)arr, index);
}

static inline void IntArr_init(IntArr *arr, int nelems) {
    Array_init((Array*)arr, nelems, sizeof(int), (Array_clearElement)NULL);
}

static inline void IntArr_insert(IntArr *arr, int index, int elem, Error *err) {
    Array_insertNCheck(arr, index, 1, err);
    int *p = (int *)Array_insertN((Array*)arr, index, 1);
    *p = elem;
}

static inline void IntArr_insertp(IntArr *arr, int index, int *elem, Error *err) {
    Array_insertNCheck(arr, index, 1, err);
    int *p = (int *)Array_insertN((Array*)arr, index, 1);
    *p = *elem;
}            

static inline int IntArr_last(IntArr *arr) {
    return Array_len((Array*)arr)-1;
}            

static inline int IntArr_len(IntArr *arr) {
    return Array_len((Array*)arr);
}

#define IntArr_loop(var, arr) IntArrIt_declare(var, arr); while (IntArrIt_next(&var)) 

static inline IntArr *IntArr_new(int nelems) {
    return (IntArr*)Array_new(nelems, sizeof(int), (Array_clearElement)NULL);
}

static inline void IntArr_pop(IntArr *arr, Error *err) {
    Array_popNCheck(arr, 1, err);
    Array_popN((Array*)arr, 1);
}

static inline void IntArr_push(IntArr *arr, int elem) {
    int *p = (int *)Array_pushN((Array*)arr, 1);
    *p = elem;
    return; 
}            

static inline void IntArr_pushp(IntArr *arr, int *elem) {
    int *p = (int *)Array_pushN((Array*)arr, 1);
    *p = *elem;
    return; 
}

#define IntArr_reach(it, arr) for (int* it = arr->data+arr->len-1; it >= arr->data; it--)

static inline void IntArr_remove(IntArr *arr, int index, Error *err) {
    Array_removeNCheck(arr, index, 1, err);
    Array_removeN((Array*)arr, index, 1);
}    

static inline void IntArr_removeN(IntArr *arr, int index, int N, Error *err) {
    Array_removeNCheck(arr, index, N, err);
    Array_removeN((Array*)arr, index, N);
}

#define IntArr_rforeach(var, arr)  for (IntArrIt_rdeclare(var, arr); IntArrIt_previous(&var); )            

#define IntArr_rloop(var, arr)    IntArrIt_rdeclare(var, arr); while (IntArrIt_previous(&var))             

static inline void IntArr_set(IntArr *arr, int index, int elem, Error *err) {
    Array_setCheck(arr, index, err);
    Array_set((Array*)arr, index, (char*)&elem);
}

static inline void IntArr_setp(IntArr *arr, int index, int *elem, Error *err) {
    Array_setCheck(arr, index, err);
    Array_set((Array*)arr, index, (char*)elem);
}

static inline void IntArr_truncate(IntArr *arr) {
    Array_truncate((Array*)arr);
}

#define IntArrIt_declare(var, arr)  IntArrIt var = {arr, -1, false, NULL}            

static inline bool IntArrIt_next(IntArrIt *iterator) {
    return ArrayIt_next((ArrayIt*)iterator);
}

static inline bool IntArrIt_previous(IntArrIt *iterator) {
    return ArrayIt_previous((ArrayIt*)iterator);
}            

#define IntArrIt_rdeclare(var, arr)  IntArrIt var = {arr, IntArr_len(arr), false, NULL}            

static inline void FooArr_changeLength(FooArr *arr, int newLength) {
    Array_changeLength((Array*)arr, newLength);
}                        

static inline void FooArr_clear(FooArr *arr) {
    Array_clear((Array*)arr);
    FooArr zero = {0};
    *arr = zero;
}

#define FooArr_declareSlice(name) FooArrSlice name = {0}            

#define FooArr_each(it, arr) for (Foo* it = arr->data; it < arr->data + arr->len; it++)

static inline void FooArr_fit(FooArr *arr) {
    Array_fit((Array*)arr);
}

#define FooArr_foreach(var, arr)  for (FooArrIt_declare(var, arr); FooArrIt_next(&var); )            

static inline void FooArr_free(FooArr *arr) {
    Array_free((Array*)arr);
}

static inline Foo FooArr_get(FooArr *arr, int index, Error *err) {
    Foo v = {0};
    Array_getCheck(arr, index, v, err);
    memmove(&v, Array_get((Array*)arr, index), Array_elemSize((Array*)arr));
    return v;
}

static inline Foo *FooArr_getp(FooArr *arr, int index, Error *err) {
    Array_getCheck(arr, index, NULL, err);
    return (Foo *)Array_get((Array*)arr, index);
}

static inline void FooArr_init(FooArr *arr, int nelems) {
    Array_init((Array*)arr, nelems, sizeof(Foo), (Array_clearElement)record_clearer);
}

static inline void FooArr_insert(FooArr *arr, int index, Foo elem, Error *err) {
    Array_insertNCheck(arr, index, 1, err);
    Foo *p = (Foo *)Array_insertN((Array*)arr, index, 1);
    *p = elem;
}

static inline void FooArr_insertp(FooArr *arr, int index, Foo *elem, Error *err) {
    Array_insertNCheck(arr, index, 1, err);
    Foo *p = (Foo *)Array_insertN((Array*)arr, index, 1);
    *p = *elem;
}            

static inline int FooArr_last(FooArr *arr) {
    return Array_len((Array*)arr)-1;
}            

static inline int FooArr_len(FooArr *arr) {
    return Array_len((Array*)arr);
}

#define FooArr_loop(var, arr) FooArrIt_declare(var, arr); while (FooArrIt_next(&var)) 

static inline FooArr *FooArr_new(int nelems) {
    return (FooArr*)Array_new(nelems, sizeof(Foo), (Array_clearElement)record_clearer);
}

static inline void FooArr_pop(FooArr *arr, Error *err) {
    Array_popNCheck(arr, 1, err);
    Array_popN((Array*)arr, 1);
}

static inline void FooArr_push(FooArr *arr, Foo elem) {
    Foo *p = (Foo *)Array_pushN((Array*)arr, 1);
    *p = elem;
    return; 
}            

static inline void FooArr_pushp(FooArr *arr, Foo *elem) {
    Foo *p = (Foo *)Array_pushN((Array*)arr, 1);
    *p = *elem;
    return; 
}

#define FooArr_reach(it, arr) for (Foo* it = arr->data+arr->len-1; it >= arr->data; it--)

static inline void FooArr_remove(FooArr *arr, int index, Error *err) {
    Array_removeNCheck(arr, index, 1, err);
    Array_removeN((Array*)arr, index, 1);
}    

static inline void FooArr_removeN(FooArr *arr, int index, int N, Error *err) {
    Array_removeNCheck(arr, index, N, err);
    Array_removeN((Array*)arr, index, N);
}

#define FooArr_rforeach(var, arr)  for (FooArrIt_rdeclare(var, arr); FooArrIt_previous(&var); )            

#define FooArr_rloop(var, arr)    FooArrIt_rdeclare(var, arr); while (FooArrIt_previous(&var))             

#define FooArr_rsliceForeach(slice) for (slice.index=slice.len-1, slice.var = slice.data + slice.index*sizeof(Foo); \\
                                               slice.index >= 0; slice.index--, slice.var--)

static inline void FooArr_set(FooArr *arr, int index, Foo elem, Error *err) {
    Array_setCheck(arr, index, err);
    Array_set((Array*)arr, index, (char*)&elem);
}

static inline void FooArr_setp(FooArr *arr, int index, Foo *elem, Error *err) {
    Array_setCheck(arr, index, err);
    Array_set((Array*)arr, index, (char*)elem);
}

#define FooArr_sliceEmpty(slice) (slice.data == NULL)

#define FooArr_sliceForeach(slice) for (slice.index=0, slice.var=slice.data; slice.index < slice.len; slice.index++, slice.var++)

static inline void FooArr_truncate(FooArr *arr) {
    Array_truncate((Array*)arr);
}

#define FooArrIt_declare(var, arr)  FooArrIt var = {arr, -1, false, NULL}            

static inline bool FooArrIt_next(FooArrIt *iterator) {
    return ArrayIt_next((ArrayIt*)iterator);
}

static inline bool FooArrIt_previous(FooArrIt *iterator) {
    return ArrayIt_previous((ArrayIt*)iterator);
}            

#define FooArrIt_rdeclare(var, arr)  FooArrIt var = {arr, FooArr_len(arr), false, NULL}            

static inline void FooArr_binInsert(FooArr *arr, Foo elem) {
    int (*compare)(Foo *, Foo *) = Foo_cmp;
    Array_binInsert((Array*)arr, (char*)&elem, (Array_compare)compare, false);
}            

static inline void FooArr_binRemove(FooArr *arr, Foo elem) {
    int (*compare)(Foo *, Foo *) = Foo_cmp;
    Array_binRemove((Array*)arr, (char*)&elem, (Array_compare)compare, false);
}        

static inline Foo *FooArr_binSearch(FooArr *arr, Foo elem) {
    int (*compare)(Foo *, Foo *) = Foo_cmp;
    return (Foo *)Array_binSearch((Array*)arr, (char*)&elem, (Array_compare)compare, NULL);
}

static inline void FooArr_sort(FooArr *arr) {
    int (*compare)(Foo *, Foo *) = Foo_cmp;
    Array_sort((Array*)arr, (Array_compare)compare);
}                

static inline void FooArr_binInsertBoth(FooArr *arr, Foo elem) {
    int (*compare)(Foo *, Foo *) = Foo_cmpBoth;
    Array_binInsert((Array*)arr, (char*)&elem, (Array_compare)compare, false);
}            

static inline void FooArr_binRemoveBoth(FooArr *arr, Foo elem) {
    int (*compare)(Foo *, Foo *) = Foo_cmpBoth;
    Array_binRemove((Array*)arr, (char*)&elem, (Array_compare)compare, false);
}        

static inline Foo *FooArr_binSearchBoth(FooArr *arr, Foo elem) {
    int (*compare)(Foo *, Foo *) = Foo_cmpBoth;
    return (Foo *)Array_binSearch((Array*)arr, (char*)&elem, (Array_compare)compare, NULL);
}

static inline void FooArr_sortBoth(FooArr *arr) {
    int (*compare)(Foo *, Foo *) = Foo_cmpBoth;
    Array_sort((Array*)arr, (Array_compare)compare);
}                

static inline void FooArr_binInsertMulti(FooArr *arr, Foo elem) {
    int (*compare)(Foo *, Foo *) = Foo_cmp;
    Array_binInsert((Array*)arr, (char*)&elem, (Array_compare)compare, true);
}            

static inline void FooArr_binRemoveMulti(FooArr *arr, Foo elem) {
    int (*compare)(Foo *, Foo *) = Foo_cmp;
    Array_binRemove((Array*)arr, (char*)&elem, (Array_compare)compare, true);
}        

static inline FooArrSlice FooArr_binSearchMulti(FooArr *arr, Foo elem) {
    int (*compare)(Foo *, Foo *) = Foo_cmp;
    FooArrSlice slice = {0};
    Array_binSearch((Array*)arr, (char*)&elem, (Array_compare)compare, (ArraySlice*)&slice);
    return slice;
}

static inline void FooArr_sortMulti(FooArr *arr) {
    int (*compare)(Foo *, Foo *) = Foo_cmp;
    Array_sort((Array*)arr, (Array_compare)compare);
}                

static inline void FooArr_binInsertBothMulti(FooArr *arr, Foo elem) {
    int (*compare)(Foo *, Foo *) = Foo_cmpBoth;
    Array_binInsert((Array*)arr, (char*)&elem, (Array_compare)compare, true);
}            

static inline void FooArr_binRemoveBothMulti(FooArr *arr, Foo elem) {
    int (*compare)(Foo *, Foo *) = Foo_cmpBoth;
    Array_binRemove((Array*)arr, (char*)&elem, (Array_compare)compare, true);
}        

static inline FooArrSlice FooArr_binSearchBothMulti(FooArr *arr, Foo elem) {
    int (*compare)(Foo *, Foo *) = Foo_cmpBoth;
    FooArrSlice slice = {0};
    Array_binSearch((Array*)arr, (char*)&elem, (Array_compare)compare, (ArraySlice*)&slice);
    return slice;
}

static inline void FooArr_sortBothMulti(FooArr *arr) {
    int (*compare)(Foo *, Foo *) = Foo_cmpBoth;
    Array_sort((Array*)arr, (Array_compare)compare);
}                

const char *Interface_toString(int itype)
{
    switch(itype) {
        case Undefined_itype:
            return "Undefined";
    }
    return "Unknown";
}
#line 23 "./for_tarray.in.c"

#line 31 "./for_tarray.in.c"
