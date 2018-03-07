typedef struct TimedOffAr_t {
    Array body;
} TimedOffAr;

static inline TimedOffAr *TimedOffAr_new(int nelems) {
    return (TimedOffAr*)Array_new(nelems, sizeof(TimedOff), (Array_clearElement)NULL);
}

static inline void TimedOffAr_init(TimedOffAr *arr, int nelems) {
    Array_init((Array*)arr, nelems, sizeof(TimedOff), (Array_clearElement)NULL);
}

static inline void TimedOffAr_clear(TimedOffAr *arr) {
    Array_clear((Array*)arr);
    TimedOffAr zero = {{0}};
    *arr = zero;
}

static inline void TimedOffAr_free(TimedOffAr *arr) {
    Array_free((Array*)arr);
}

static inline void TimedOffAr_truncate(TimedOffAr *arr) {
    Array_truncate((Array*)arr);
}

static inline int TimedOffAr_len(TimedOffAr *arr) {
    return Array_len((Array*)arr);
}

static inline TimedOff TimedOffAr_get(TimedOffAr *arr, int index, Error *err) {
    TimedOff v = {0};
    Array_getCheck(arr, index, v, err);
    memmove(&v, Array_get((Array*)arr, index), Array_elemSize((Array*)arr));
    return v;
}

static inline TimedOff *TimedOffAr_getp(TimedOffAr *arr, int index, Error *err) {
    Array_getCheck(arr, index, NULL, err);
    return (TimedOff *)Array_get((Array*)arr, index);
}


static inline void TimedOffAr_set(TimedOffAr *arr, int index, TimedOff elem, Error *err) {
    Array_setCheck(arr, index, err);
    Array_set((Array*)arr, index, (char*)&elem);
}

static inline void TimedOffAr_setp(TimedOffAr *arr, int index, TimedOff *elem, Error *err) {
    Array_setCheck(arr, index, err);
    Array_set((Array*)arr, index, (char*)elem);
}

static inline void TimedOffAr_pop(TimedOffAr *arr, Error *err) {
    Array_popNCheck(arr, 1, err);
    Array_popN((Array*)arr, 1);
}

static inline void TimedOffAr_push(TimedOffAr *arr, TimedOff elem) {
    TimedOff *p = (TimedOff *)Array_pushN((Array*)arr, 1);
    *p = elem;
    return; 
}

static inline void TimedOffAr_pushp(TimedOffAr *arr, TimedOff *elem) {
    TimedOff *p = (TimedOff *)Array_pushN((Array*)arr, 1);
    *p = *elem;
    return; 
}

static inline void TimedOffAr_insert(TimedOffAr *arr, int index, TimedOff elem, Error *err) {
    Array_insertNCheck(arr, index, 1, err);
    TimedOff *p = (TimedOff *)Array_insertN((Array*)arr, index, 1);
    *p = elem;
}

static inline void TimedOffAr_insertp(TimedOffAr *arr, int index, TimedOff *elem, Error *err) {
    Array_insertNCheck(arr, index, 1, err);
    TimedOff *p = (TimedOff *)Array_insertN((Array*)arr, index, 1);
    *p = *elem;
}


static inline void TimedOffAr_remove(TimedOffAr *arr, int index, Error *err) {
    Array_removeNCheck(arr, index, 1, err);
    Array_removeN((Array*)arr, index, 1);
}

static inline void TimedOffAr_removeN(TimedOffAr *arr, int index, int N, Error *err) {
    Array_removeNCheck(arr, index, N, err);
    Array_removeN((Array*)arr, index, N);
}

static inline void TimedOffAr_fit(TimedOffAr *arr) {
    Array_fit((Array*)arr);
}

static inline int TimedOffAr_last(TimedOffAr *arr) {
    return Array_len((Array*)arr)-1;
}

static inline void TimedOffAr_changeLength(TimedOffAr *arr, int newLength) {
    Array_changeLength((Array*)arr, newLength);
}

typedef struct TimedOffArIter_t {
   TimedOffAr *arr;
   int index;
   bool last;
   TimedOff *var;
} TimedOffArIter;

static inline bool TimedOffArIter_next(TimedOffArIter *iterator) {
    return ArrayIter_next((ArrayIter*)iterator);
}

static inline bool TimedOffArIter_previous(TimedOffArIter *iterator) {
    return ArrayIter_previous((ArrayIter*)iterator);
}

#define TimedOffArIter_declare(var, arr)  TimedOffArIter var = {arr, -1, false, NULL}
#define TimedOffArIter_rdeclare(var, arr)  TimedOffArIter var = {arr, TimedOffAr_len(arr), false, NULL}
#define TimedOffAr_foreach(var, arr)  for (TimedOffArIter_declare(var, arr); TimedOffArIter_next(&var); )
#define TimedOffAr_rforeach(var, arr)  for (TimedOffArIter_rdeclare(var, arr); TimedOffArIter_previous(&var); )
#define TimedOffAr_loop(var, arr)    TimedOffArIter_declare(var, arr); while (TimedOffArIter_next(&var)) 
#define TimedOffAr_rloop(var, arr)    TimedOffArIter_rdeclare(var, arr); while (TimedOffArIter_previous(&var)) 

static inline void TimedOffAr_binInsertTime(TimedOffAr *arr, TimedOff elem) {
    Array_binInsert((Array*)arr, (char*)&elem, (Array_compare)TimedOff_cmpTime, false);
}

static inline void TimedOffAr_binRemoveTime(TimedOffAr *arr, TimedOff elem) {
    Array_binRemove((Array*)arr, (char*)&elem, (Array_compare)TimedOff_cmpTime, false);
}

static inline void TimedOffAr_sortTime(TimedOffAr *arr) {
    Array_sort((Array*)arr, (Array_compare)TimedOff_cmpTime);
}

static inline TimedOff *TimedOffAr_binSearchTime(TimedOffAr *arr, TimedOff elem) {
    return (TimedOff *)Array_binSearch((Array*)arr, (char*)&elem, (Array_compare)TimedOff_cmpTime, NULL);
}
