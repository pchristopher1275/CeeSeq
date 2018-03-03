typedef struct IntAr_t {
    Array body;
} IntAr;

static inline IntAr *IntAr_new(int nelems) {
    return (IntAr*)Array_new(nelems, sizeof(int), (Array_clearElement)NULL);
}

static inline void IntAr_init(IntAr *arr, int nelems) {
    Array_init((Array*)arr, nelems, sizeof(int), (Array_clearElement)NULL);
}

static inline void IntAr_clear(IntAr *arr) {
    Array_clear((Array*)arr);
    IntAr zero = {{0}};
    *arr = zero;
}

static inline void IntAr_free(IntAr *arr) {
    Array_free((Array*)arr);
}

static inline void IntAr_truncate(IntAr *arr) {
    Array_truncate((Array*)arr);
}

static inline int IntAr_len(IntAr *arr) {
    return Array_len((Array*)arr);
}

static inline int IntAr_get(IntAr *arr, int index, Error *err) {
    int v = 0;
    Array_getCheck(arr, index, v, err);
    memmove(&v, Array_get((Array*)arr, index), Array_elemSize((Array*)arr));
    return v;
}

static inline int *IntAr_getp(IntAr *arr, int index, Error *err) {
    Array_getCheck(arr, index, NULL, err);
    return (int *)Array_get((Array*)arr, index);
}


static inline void IntAr_set(IntAr *arr, int index, int elem, Error *err) {
    Array_setCheck(arr, index, err);
    Array_set((Array*)arr, index, (char*)&elem);
}

static inline void IntAr_setp(IntAr *arr, int index, int *elem, Error *err) {
    Array_setCheck(arr, index, err);
    Array_set((Array*)arr, index, (char*)elem);
}

static inline void IntAr_pop(IntAr *arr, Error *err) {
    Array_popNCheck(arr, 1, err);
    Array_popN((Array*)arr, 1);
}

static inline void IntAr_push(IntAr *arr, int elem) {
    int *p = (int *)Array_pushN((Array*)arr, 1);
    *p = elem;
    return; 
}

static inline void IntAr_pushp(IntAr *arr, int *elem) {
    int *p = (int *)Array_pushN((Array*)arr, 1);
    *p = *elem;
    return; 
}

static inline void IntAr_insert(IntAr *arr, int index, int elem, Error *err) {
    Array_insertNCheck(arr, index, 1, err);
    int *p = (int *)Array_insertN((Array*)arr, index, 1);
    *p = elem;
}

static inline void IntAr_insertp(IntAr *arr, int index, int *elem, Error *err) {
    Array_insertNCheck(arr, index, 1, err);
    int *p = (int *)Array_insertN((Array*)arr, index, 1);
    *p = *elem;
}


static inline void IntAr_remove(IntAr *arr, int index, Error *err) {
    Array_removeNCheck(arr, index, 1, err);
    Array_removeN((Array*)arr, index, 1);
}

static inline void IntAr_fit(IntAr *arr) {
    Array_fit((Array*)arr);
}

static inline int IntAr_last(IntAr *arr) {
    return Array_len((Array*)arr)-1;
}

typedef struct IntArIter_t {
   IntAr *arr;
   int index;
   bool last;
   int *var;
} IntArIter;

static inline bool IntArIter_next(IntArIter *iterator) {
    return ArrayIter_next((ArrayIter*)iterator);
}

static inline bool IntArIter_previous(IntArIter *iterator) {
    return ArrayIter_previous((ArrayIter*)iterator);
}

#define IntArIter_declare(var, arr)  IntArIter var = {arr, -1, false, NULL}
#define IntArIter_rdeclare(var, arr)  IntArIter var = {arr, IntAr_len(arr), false, NULL}
#define IntAr_foreach(var, arr)  for (IntArIter_declare(var, arr); IntArIter_next(&var); )
#define IntAr_rforeach(var, arr)  for (IntArIter_rdeclare(var, arr); IntArIter_previous(&var); )
#define IntAr_loop(var, arr)    IntArIter_declare(var, arr); while (IntArIter_next(&var)) 
#define IntAr_rloop(var, arr)    IntArIter_rdeclare(var, arr); while (IntArIter_previous(&var)) 


