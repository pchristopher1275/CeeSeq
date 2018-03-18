// *** DO NOT MODIFY THIS FILE (see test/util/for_tarray.in.h) generated 03/18/2018 13:38:09 ***
// *** DO NOT MODIFY THIS FILE (see test/util/for_tarray.in.h) generated 03/18/2018 13:38:09 ***
#define Foo_newUninitialized() ((Foo*)sysmem_newptrclear(sizeof(Foo)))        
static inline int Foo_i(Foo *self){return self->i;}
static inline void Foo_setI(Foo *self, int value){self->i = value;}
static inline double Foo_d(Foo *self){return self->d;}
static inline void Foo_setD(Foo *self, double value){self->d = value;}
static inline void FooArr_changeLength(FooArr *arr, int newLength) {
    Array_changeLength((Array*)arr, newLength);
}                        

static inline void FooArr_clear(FooArr *arr) {
    Array_clear((Array*)arr);
    FooArr zero = {0};
    *arr = zero;
}

#define FooArr_declareSlice(name) FooArrSlice name = {0}            

#define FooArr_each(it, arr) for (Foo *s##it = arr->data, \
                                                       *e##it = arr->data + arr->len, \
                                                       *it    = s##it;\
                                          it < e##it;\
                                          it++)

#define FooArr_eachIndexOf(it) ((int)(it - s##it))

#define FooArr_eachInsert(it, arr, valPtr) FooArr_eachInsertImpl(it, arr, valPtr, 0, 1)

#define FooArr_eachInsertAfter(it, arr, valPtr) FooArr_eachInsertImpl(it, arr, valPtr, 1, 1)

#define FooArr_eachInsertImpl(it, arr, valPtr, insertOffset, itOffset) do {\
   int index##it = FooArr_eachIndexOf(it);\
   Error_declare(err##it);\
   FooArr_insertp(arr, index##it + (insertOffset), valPtr, err##it);\
   Error_maypost(err##it);\
    s##it     = arr->data, \
   e##it     = arr->data + arr->len, \
   it        = s##it + (index##it+(itOffset));\
} while(0); continue

#define FooArr_eachLast(it) ((it + 1) >= e##it)

#define FooArr_eachRemove(it, arr) FooArr_eachRemoveImpl(it, arr, 0)

#define FooArr_eachRemoveImpl(it, arr, itOffset) do {\
   int index##it = FooArr_eachIndexOf(it);\
   Error_declare(err##it);\
   FooArr_remove(arr, index##it, err##it);\
   Error_maypost(err##it);\
    s##it     = arr->data, \
   e##it     = arr->data + arr->len, \
   it        = s##it + (index##it + (itOffset));\
} while(0); continue

static inline void FooArr_fit(FooArr *arr) {
    Array_fit((Array*)arr);
}

#define FooArr_foreach(var, arr)  for (FooArrIter_declare(var, arr); FooArrIter_next(&var); )            

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

#define FooArr_loop(var, arr) FooArrIter_declare(var, arr); while (FooArrIter_next(&var)) 

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

#define FooArr_reach(it, arr) for (Foo *s##it = arr->data, \
                                                        *e##it = arr->data + arr->len, \
                                                        *it    = e##it-1;\
                                       it >= s##it;\
                                       it--)

#define FooArr_reachInsert(it, arr, valPtr) FooArr_eachInsertImpl(it, arr, valPtr, 0, 0)

#define FooArr_reachInsertAfter(it, arr, valPtr) FooArr_eachInsertImpl(it, arr, valPtr, 1, -1)

#define FooArr_reachLast(it) ((it - 1) < s##it)

#define FooArr_reachRemove(it, arr) FooArr_eachRemoveImpl(it, arr, -1)

static inline void FooArr_remove(FooArr *arr, int index, Error *err) {
    Array_removeNCheck(arr, index, 1, err);
    Array_removeN((Array*)arr, index, 1);
}    

static inline void FooArr_removeN(FooArr *arr, int index, int N, Error *err) {
    Array_removeNCheck(arr, index, N, err);
    Array_removeN((Array*)arr, index, N);
}

#define FooArr_rforeach(var, arr)  for (FooArrIter_rdeclare(var, arr); FooArrIter_previous(&var); )            

#define FooArr_rloop(var, arr)    FooArrIter_rdeclare(var, arr); while (FooArrIter_previous(&var))             

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

#define FooArrIter_declare(var, arr)  FooArrIter var = {arr, -1, false, NULL}            

static inline bool FooArrIter_next(FooArrIter *iterator) {
    return ArrayIter_next((ArrayIter*)iterator);
}

static inline bool FooArrIter_previous(FooArrIter *iterator) {
    return ArrayIter_previous((ArrayIter*)iterator);
}            

#define FooArrIter_rdeclare(var, arr)  FooArrIter var = {arr, FooArr_len(arr), false, NULL}            

static inline void FooArr_binInsert(FooArr *arr, Foo elem) {
    Array_binInsert((Array*)arr, (char*)&elem, (Array_compare)Foo_cmp, false);
}            

static inline void FooArr_binRemove(FooArr *arr, Foo elem) {
    Array_binRemove((Array*)arr, (char*)&elem, (Array_compare)Foo_cmp, false);
}        

static inline Foo *FooArr_binSearch(FooArr *arr, Foo elem) {
    return (Foo *)Array_binSearch((Array*)arr, (char*)&elem, (Array_compare)Foo_cmp, NULL);
}

static inline void FooArr_sort(FooArr *arr) {
    Array_sort((Array*)arr, (Array_compare)Foo_cmp);
}                

static inline void FooArr_binInsertBoth(FooArr *arr, Foo elem) {
    Array_binInsert((Array*)arr, (char*)&elem, (Array_compare)Foo_cmpBoth, false);
}            

static inline void FooArr_binRemoveBoth(FooArr *arr, Foo elem) {
    Array_binRemove((Array*)arr, (char*)&elem, (Array_compare)Foo_cmpBoth, false);
}        

static inline Foo *FooArr_binSearchBoth(FooArr *arr, Foo elem) {
    return (Foo *)Array_binSearch((Array*)arr, (char*)&elem, (Array_compare)Foo_cmpBoth, NULL);
}

static inline void FooArr_sortBoth(FooArr *arr) {
    Array_sort((Array*)arr, (Array_compare)Foo_cmpBoth);
}                

static inline void FooArr_binInsertMulti(FooArr *arr, Foo elem) {
    Array_binInsert((Array*)arr, (char*)&elem, (Array_compare)Foo_cmp, true);
}            

static inline void FooArr_binRemoveMulti(FooArr *arr, Foo elem) {
    Array_binRemove((Array*)arr, (char*)&elem, (Array_compare)Foo_cmp, true);
}        

static inline FooArrSlice FooArr_binSearchMulti(FooArr *arr, Foo elem) {
    FooArrSlice slice = {0};
    Array_binSearch((Array*)arr, (char*)&elem, (Array_compare)Foo_cmp, (ArraySlice*)&slice);
    return slice;
}

static inline void FooArr_sortMulti(FooArr *arr) {
    Array_sort((Array*)arr, (Array_compare)Foo_cmp);
}                

static inline void FooArr_binInsertBothMulti(FooArr *arr, Foo elem) {
    Array_binInsert((Array*)arr, (char*)&elem, (Array_compare)Foo_cmpBoth, true);
}            

static inline void FooArr_binRemoveBothMulti(FooArr *arr, Foo elem) {
    Array_binRemove((Array*)arr, (char*)&elem, (Array_compare)Foo_cmpBoth, true);
}        

static inline FooArrSlice FooArr_binSearchBothMulti(FooArr *arr, Foo elem) {
    FooArrSlice slice = {0};
    Array_binSearch((Array*)arr, (char*)&elem, (Array_compare)Foo_cmpBoth, (ArraySlice*)&slice);
    return slice;
}

static inline void FooArr_sortBothMulti(FooArr *arr) {
    Array_sort((Array*)arr, (Array_compare)Foo_cmpBoth);
}                


typedef struct IntArr_t {
   int len;
   int cap;
   int elemSize;
   void (*clearer)(int*);
   int *data;
} IntArr;

typedef struct IntArrIter_t {
   IntArr *arr;
   int index;
   bool last;
   int *var;
} IntArrIter;

static inline void IntArr_changeLength(IntArr *arr, int newLength) {
    Array_changeLength((Array*)arr, newLength);
}                        

static inline void IntArr_clear(IntArr *arr) {
    Array_clear((Array*)arr);
    IntArr zero = {0};
    *arr = zero;
}

#define IntArr_each(it, arr) for (int *s##it = arr->data, \
                                                       *e##it = arr->data + arr->len, \
                                                       *it    = s##it;\
                                          it < e##it;\
                                          it++)

#define IntArr_eachIndexOf(it) ((int)(it - s##it))

#define IntArr_eachInsert(it, arr, valPtr) IntArr_eachInsertImpl(it, arr, valPtr, 0, 1)

#define IntArr_eachInsertAfter(it, arr, valPtr) IntArr_eachInsertImpl(it, arr, valPtr, 1, 1)

#define IntArr_eachInsertImpl(it, arr, valPtr, insertOffset, itOffset) do {\
   int index##it = IntArr_eachIndexOf(it);\
   Error_declare(err##it);\
   IntArr_insertp(arr, index##it + (insertOffset), valPtr, err##it);\
   Error_maypost(err##it);\
    s##it     = arr->data, \
   e##it     = arr->data + arr->len, \
   it        = s##it + (index##it+(itOffset));\
} while(0); continue

#define IntArr_eachLast(it) ((it + 1) >= e##it)

#define IntArr_eachRemove(it, arr) IntArr_eachRemoveImpl(it, arr, 0)

#define IntArr_eachRemoveImpl(it, arr, itOffset) do {\
   int index##it = IntArr_eachIndexOf(it);\
   Error_declare(err##it);\
   IntArr_remove(arr, index##it, err##it);\
   Error_maypost(err##it);\
    s##it     = arr->data, \
   e##it     = arr->data + arr->len, \
   it        = s##it + (index##it + (itOffset));\
} while(0); continue

static inline void IntArr_fit(IntArr *arr) {
    Array_fit((Array*)arr);
}

#define IntArr_foreach(var, arr)  for (IntArrIter_declare(var, arr); IntArrIter_next(&var); )            

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

#define IntArr_loop(var, arr) IntArrIter_declare(var, arr); while (IntArrIter_next(&var)) 

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

#define IntArr_reach(it, arr) for (int *s##it = arr->data, \
                                                        *e##it = arr->data + arr->len, \
                                                        *it    = e##it-1;\
                                       it >= s##it;\
                                       it--)

#define IntArr_reachInsert(it, arr, valPtr) IntArr_eachInsertImpl(it, arr, valPtr, 0, 0)

#define IntArr_reachInsertAfter(it, arr, valPtr) IntArr_eachInsertImpl(it, arr, valPtr, 1, -1)

#define IntArr_reachLast(it) ((it - 1) < s##it)

#define IntArr_reachRemove(it, arr) IntArr_eachRemoveImpl(it, arr, -1)

static inline void IntArr_remove(IntArr *arr, int index, Error *err) {
    Array_removeNCheck(arr, index, 1, err);
    Array_removeN((Array*)arr, index, 1);
}    

static inline void IntArr_removeN(IntArr *arr, int index, int N, Error *err) {
    Array_removeNCheck(arr, index, N, err);
    Array_removeN((Array*)arr, index, N);
}

#define IntArr_rforeach(var, arr)  for (IntArrIter_rdeclare(var, arr); IntArrIter_previous(&var); )            

#define IntArr_rloop(var, arr)    IntArrIter_rdeclare(var, arr); while (IntArrIter_previous(&var))             

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

#define IntArrIter_declare(var, arr)  IntArrIter var = {arr, -1, false, NULL}            

static inline bool IntArrIter_next(IntArrIter *iterator) {
    return ArrayIter_next((ArrayIter*)iterator);
}

static inline bool IntArrIter_previous(IntArrIter *iterator) {
    return ArrayIter_previous((ArrayIter*)iterator);
}            

#define IntArrIter_rdeclare(var, arr)  IntArrIter var = {arr, IntArr_len(arr), false, NULL}            

