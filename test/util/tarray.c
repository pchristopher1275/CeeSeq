typedef struct FooArr_t {
    Array body;
} FooArr;

static inline FooArr *FooArr_new(int nelems) {
    return (FooArr*)Array_new(nelems, sizeof(Foo), (Array_clearElement)record_clearer);
}

static inline void FooArr_init(FooArr *arr, int nelems) {
    Array_init((Array*)arr, nelems, sizeof(Foo), (Array_clearElement)record_clearer);
}

static inline void FooArr_clear(FooArr *arr) {
    Array_clear((Array*)arr);
}

static inline void FooArr_free(FooArr *arr) {
    Array_free((Array*)arr);
}

static inline void FooArr_truncate(FooArr *arr) {
    Array_truncate((Array*)arr);
}

static inline int FooArr_len(FooArr *arr) {
    return Array_len((Array*)arr);
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


static inline void FooArr_set(FooArr *arr, int index, Foo elem, Error *err) {
    Array_setCheck(arr, index, err);
    Array_set((Array*)arr, index, (char*)&elem);
}

static inline void FooArr_setp(FooArr *arr, int index, Foo *elem, Error *err) {
    Array_setCheck(arr, index, err);
    Array_set((Array*)arr, index, (char*)elem);
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

static inline Foo *FooArr_insert(FooArr *arr, int index, Error *err) {
    Array_insertNCheck(arr, index, 1, err);
    return (Foo *)Array_insertN((Array*)arr, index, 1);
}

static inline void FooArr_remove(FooArr *arr, int index, Error *err) {
    Array_removeNCheck(arr, index, 1, err);
    Array_removeN((Array*)arr, index, 1);
}

static inline void FooArr_fit(FooArr *arr) {
    Array_fit((Array*)arr);
}

typedef struct FooArrIter_t {
   FooArr *arr;
   int index;
   bool last;
   Foo *pvalue;
   Foo value;
} FooArrIter;

static inline bool FooArrIter_next(FooArrIter *iterator) {
    return ArrayIter_nextValue((ArrayIter*)iterator, (char*)&iterator->value);
}

static inline bool FooArrIter_insert(FooArrIter *iterator, Foo value) {
    return ArrayIter_insert((ArrayIter*)iterator, (char*)&value);
}

static inline bool FooArrIter_remove(FooArrIter *iterator) {
    return ArrayIter_remove((ArrayIter*)iterator);
}

#define FooArrIter_declare(var, arr)  FooArrIter var = {arr, -1, false, NULL, {0}}
#define FooArr_foreach(var, arr)  for (FooArrIter_declare(var, arr); FooArrIter_next(&var); )
#define FooArr_loop(var, arr)    FooArrIter_declare(var, arr); while (FooArrIter_next(&var)) 


typedef struct FooPtrArr_t {
    Array body;
} FooPtrArr;

static inline FooPtrArr *FooPtrArr_new(int nelems) {
    return (FooPtrArr*)Array_new(nelems, sizeof(Foo *), (Array_clearElement)NULL);
}

static inline void FooPtrArr_init(FooPtrArr *arr, int nelems) {
    Array_init((Array*)arr, nelems, sizeof(Foo *), (Array_clearElement)NULL);
}

static inline void FooPtrArr_clear(FooPtrArr *arr) {
    Array_clear((Array*)arr);
}

static inline void FooPtrArr_free(FooPtrArr *arr) {
    Array_free((Array*)arr);
}

static inline void FooPtrArr_truncate(FooPtrArr *arr) {
    Array_truncate((Array*)arr);
}

static inline int FooPtrArr_len(FooPtrArr *arr) {
    return Array_len((Array*)arr);
}

static inline Foo *FooPtrArr_get(FooPtrArr *arr, int index, Error *err) {
    Foo * v = {0};
    Array_getCheck(arr, index, v, err);
    memmove(&v, Array_get((Array*)arr, index), Array_elemSize((Array*)arr));
    return v;
}

static inline Foo **FooPtrArr_getp(FooPtrArr *arr, int index, Error *err) {
    Array_getCheck(arr, index, NULL, err);
    return (Foo **)Array_get((Array*)arr, index);
}


static inline void FooPtrArr_set(FooPtrArr *arr, int index, Foo *elem, Error *err) {
    Array_setCheck(arr, index, err);
    Array_set((Array*)arr, index, (char*)&elem);
}

static inline void FooPtrArr_setp(FooPtrArr *arr, int index, Foo **elem, Error *err) {
    Array_setCheck(arr, index, err);
    Array_set((Array*)arr, index, (char*)elem);
}

static inline void FooPtrArr_pop(FooPtrArr *arr, Error *err) {
    Array_popNCheck(arr, 1, err);
    Array_popN((Array*)arr, 1);
}

static inline void FooPtrArr_push(FooPtrArr *arr, Foo *elem) {
    Foo * *p = (Foo **)Array_pushN((Array*)arr, 1);
    *p = elem;
    return; 
}

static inline void FooPtrArr_pushp(FooPtrArr *arr, Foo **elem) {
    Foo * *p = (Foo **)Array_pushN((Array*)arr, 1);
    *p = *elem;
    return; 
}

static inline Foo **FooPtrArr_insert(FooPtrArr *arr, int index, Error *err) {
    Array_insertNCheck(arr, index, 1, err);
    return (Foo **)Array_insertN((Array*)arr, index, 1);
}

static inline void FooPtrArr_remove(FooPtrArr *arr, int index, Error *err) {
    Array_removeNCheck(arr, index, 1, err);
    Array_removeN((Array*)arr, index, 1);
}

static inline void FooPtrArr_fit(FooPtrArr *arr) {
    Array_fit((Array*)arr);
}

typedef struct FooPtrArrIter_t {
   FooPtrArr *arr;
   int index;
   bool last;
   Foo **pvalue;
   Foo *value;
} FooPtrArrIter;

static inline bool FooPtrArrIter_next(FooPtrArrIter *iterator) {
    return ArrayIter_nextValue((ArrayIter*)iterator, (char*)&iterator->value);
}

static inline bool FooPtrArrIter_insert(FooPtrArrIter *iterator, Foo * value) {
    return ArrayIter_insert((ArrayIter*)iterator, (char*)&value);
}

static inline bool FooPtrArrIter_remove(FooPtrArrIter *iterator) {
    return ArrayIter_remove((ArrayIter*)iterator);
}

#define FooPtrArrIter_declare(var, arr)  FooPtrArrIter var = {arr, -1, false, NULL, {0}}
#define FooPtrArr_foreach(var, arr)  for (FooPtrArrIter_declare(var, arr); FooPtrArrIter_next(&var); )
#define FooPtrArr_loop(var, arr)    FooPtrArrIter_declare(var, arr); while (FooPtrArrIter_next(&var)) 


typedef struct IntArr_t {
    Array body;
} IntArr;

static inline IntArr *IntArr_new(int nelems) {
    return (IntArr*)Array_new(nelems, sizeof(int), (Array_clearElement)NULL);
}

static inline void IntArr_init(IntArr *arr, int nelems) {
    Array_init((Array*)arr, nelems, sizeof(int), (Array_clearElement)NULL);
}

static inline void IntArr_clear(IntArr *arr) {
    Array_clear((Array*)arr);
}

static inline void IntArr_free(IntArr *arr) {
    Array_free((Array*)arr);
}

static inline void IntArr_truncate(IntArr *arr) {
    Array_truncate((Array*)arr);
}

static inline int IntArr_len(IntArr *arr) {
    return Array_len((Array*)arr);
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


static inline void IntArr_set(IntArr *arr, int index, int elem, Error *err) {
    Array_setCheck(arr, index, err);
    Array_set((Array*)arr, index, (char*)&elem);
}

static inline void IntArr_setp(IntArr *arr, int index, int *elem, Error *err) {
    Array_setCheck(arr, index, err);
    Array_set((Array*)arr, index, (char*)elem);
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

static inline int *IntArr_insert(IntArr *arr, int index, Error *err) {
    Array_insertNCheck(arr, index, 1, err);
    return (int *)Array_insertN((Array*)arr, index, 1);
}

static inline void IntArr_remove(IntArr *arr, int index, Error *err) {
    Array_removeNCheck(arr, index, 1, err);
    Array_removeN((Array*)arr, index, 1);
}

static inline void IntArr_fit(IntArr *arr) {
    Array_fit((Array*)arr);
}

typedef struct IntArrIter_t {
   IntArr *arr;
   int index;
   bool last;
   int *pvalue;
   int value;
} IntArrIter;

static inline bool IntArrIter_next(IntArrIter *iterator) {
    return ArrayIter_nextValue((ArrayIter*)iterator, (char*)&iterator->value);
}

static inline bool IntArrIter_insert(IntArrIter *iterator, int value) {
    return ArrayIter_insert((ArrayIter*)iterator, (char*)&value);
}

static inline bool IntArrIter_remove(IntArrIter *iterator) {
    return ArrayIter_remove((ArrayIter*)iterator);
}

#define IntArrIter_declare(var, arr)  IntArrIter var = {arr, -1, false, NULL, 0}
#define IntArr_foreach(var, arr)  for (IntArrIter_declare(var, arr); IntArrIter_next(&var); )
#define IntArr_loop(var, arr)    IntArrIter_declare(var, arr); while (IntArrIter_next(&var)) 


