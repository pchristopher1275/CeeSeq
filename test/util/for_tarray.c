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


static inline void FooArr_remove(FooArr *arr, int index, Error *err) {
    Array_removeNCheck(arr, index, 1, err);
    Array_removeN((Array*)arr, index, 1);
}

static inline void FooArr_fit(FooArr *arr) {
    Array_fit((Array*)arr);
}

static inline int FooArr_last(FooArr *arr) {
    return Array_len((Array*)arr)-1;
}

typedef struct FooArrIter_t {
   FooArr *arr;
   int index;
   bool last;
   Foo *var;
} FooArrIter;

static inline bool FooArrIter_next(FooArrIter *iterator) {
    return ArrayIter_next((ArrayIter*)iterator);
}

static inline bool FooArrIter_previous(FooArrIter *iterator) {
    return ArrayIter_previous((ArrayIter*)iterator);
}

#define FooArrIter_declare(var, arr)  FooArrIter var = {arr, -1, false, NULL}
#define FooArrIter_rdeclare(var, arr)  FooArrIter var = {arr, FooArr_len(arr), false, NULL}
#define FooArr_foreach(var, arr)  for (FooArrIter_declare(var, arr); FooArrIter_next(&var); )
#define FooArr_rforeach(var, arr)  for (FooArrIter_rdeclare(var, arr); FooArrIter_previous(&var); )
#define FooArr_loop(var, arr)    FooArrIter_declare(var, arr); while (FooArrIter_next(&var)) 
#define FooArr_rloop(var, arr)    FooArrIter_rdeclare(var, arr); while (FooArrIter_previous(&var)) 


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

static inline void FooPtrArr_insert(FooPtrArr *arr, int index, Foo *elem, Error *err) {
    Array_insertNCheck(arr, index, 1, err);
    Foo * *p = (Foo **)Array_insertN((Array*)arr, index, 1);
    *p = elem;
}

static inline void FooPtrArr_insertp(FooPtrArr *arr, int index, Foo **elem, Error *err) {
    Array_insertNCheck(arr, index, 1, err);
    Foo * *p = (Foo **)Array_insertN((Array*)arr, index, 1);
    *p = *elem;
}


static inline void FooPtrArr_remove(FooPtrArr *arr, int index, Error *err) {
    Array_removeNCheck(arr, index, 1, err);
    Array_removeN((Array*)arr, index, 1);
}

static inline void FooPtrArr_fit(FooPtrArr *arr) {
    Array_fit((Array*)arr);
}

static inline int FooPtrArr_last(FooPtrArr *arr) {
    return Array_len((Array*)arr)-1;
}

typedef struct FooPtrArrIter_t {
   FooPtrArr *arr;
   int index;
   bool last;
   Foo **var;
} FooPtrArrIter;

static inline bool FooPtrArrIter_next(FooPtrArrIter *iterator) {
    return ArrayIter_next((ArrayIter*)iterator);
}

static inline bool FooPtrArrIter_previous(FooPtrArrIter *iterator) {
    return ArrayIter_previous((ArrayIter*)iterator);
}

#define FooPtrArrIter_declare(var, arr)  FooPtrArrIter var = {arr, -1, false, NULL}
#define FooPtrArrIter_rdeclare(var, arr)  FooPtrArrIter var = {arr, FooPtrArr_len(arr), false, NULL}
#define FooPtrArr_foreach(var, arr)  for (FooPtrArrIter_declare(var, arr); FooPtrArrIter_next(&var); )
#define FooPtrArr_rforeach(var, arr)  for (FooPtrArrIter_rdeclare(var, arr); FooPtrArrIter_previous(&var); )
#define FooPtrArr_loop(var, arr)    FooPtrArrIter_declare(var, arr); while (FooPtrArrIter_next(&var)) 
#define FooPtrArr_rloop(var, arr)    FooPtrArrIter_rdeclare(var, arr); while (FooPtrArrIter_previous(&var)) 


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


static inline void IntArr_remove(IntArr *arr, int index, Error *err) {
    Array_removeNCheck(arr, index, 1, err);
    Array_removeN((Array*)arr, index, 1);
}

static inline void IntArr_fit(IntArr *arr) {
    Array_fit((Array*)arr);
}

static inline int IntArr_last(IntArr *arr) {
    return Array_len((Array*)arr)-1;
}

typedef struct IntArrIter_t {
   IntArr *arr;
   int index;
   bool last;
   int *var;
} IntArrIter;

static inline bool IntArrIter_next(IntArrIter *iterator) {
    return ArrayIter_next((ArrayIter*)iterator);
}

static inline bool IntArrIter_previous(IntArrIter *iterator) {
    return ArrayIter_previous((ArrayIter*)iterator);
}

#define IntArrIter_declare(var, arr)  IntArrIter var = {arr, -1, false, NULL}
#define IntArrIter_rdeclare(var, arr)  IntArrIter var = {arr, IntArr_len(arr), false, NULL}
#define IntArr_foreach(var, arr)  for (IntArrIter_declare(var, arr); IntArrIter_next(&var); )
#define IntArr_rforeach(var, arr)  for (IntArrIter_rdeclare(var, arr); IntArrIter_previous(&var); )
#define IntArr_loop(var, arr)    IntArrIter_declare(var, arr); while (IntArrIter_next(&var)) 
#define IntArr_rloop(var, arr)    IntArrIter_rdeclare(var, arr); while (IntArrIter_previous(&var)) 


