typedef struct TrackAr_t {
    Array body;
} TrackAr;

static inline TrackAr *TrackAr_new(int nelems) {
    return (TrackAr*)Array_new(nelems, sizeof(Track), (Array_clearElement)NULL);
}

static inline void TrackAr_init(TrackAr *arr, int nelems) {
    Array_init((Array*)arr, nelems, sizeof(Track), (Array_clearElement)NULL);
}

static inline void TrackAr_clear(TrackAr *arr) {
    Array_clear((Array*)arr);
    TrackAr zero = {{0}};
    *arr = zero;
}

static inline void TrackAr_free(TrackAr *arr) {
    Array_free((Array*)arr);
}

static inline void TrackAr_truncate(TrackAr *arr) {
    Array_truncate((Array*)arr);
}

static inline int TrackAr_len(TrackAr *arr) {
    return Array_len((Array*)arr);
}

static inline Track TrackAr_get(TrackAr *arr, int index, Error *err) {
    Track v = {0};
    Array_getCheck(arr, index, v, err);
    memmove(&v, Array_get((Array*)arr, index), Array_elemSize((Array*)arr));
    return v;
}

static inline Track *TrackAr_getp(TrackAr *arr, int index, Error *err) {
    Array_getCheck(arr, index, NULL, err);
    return (Track *)Array_get((Array*)arr, index);
}


static inline void TrackAr_set(TrackAr *arr, int index, Track elem, Error *err) {
    Array_setCheck(arr, index, err);
    Array_set((Array*)arr, index, (char*)&elem);
}

static inline void TrackAr_setp(TrackAr *arr, int index, Track *elem, Error *err) {
    Array_setCheck(arr, index, err);
    Array_set((Array*)arr, index, (char*)elem);
}

static inline void TrackAr_pop(TrackAr *arr, Error *err) {
    Array_popNCheck(arr, 1, err);
    Array_popN((Array*)arr, 1);
}

static inline void TrackAr_push(TrackAr *arr, Track elem) {
    Track *p = (Track *)Array_pushN((Array*)arr, 1);
    *p = elem;
    return; 
}

static inline void TrackAr_pushp(TrackAr *arr, Track *elem) {
    Track *p = (Track *)Array_pushN((Array*)arr, 1);
    *p = *elem;
    return; 
}

static inline void TrackAr_insert(TrackAr *arr, int index, Track elem, Error *err) {
    Array_insertNCheck(arr, index, 1, err);
    Track *p = (Track *)Array_insertN((Array*)arr, index, 1);
    *p = elem;
}

static inline void TrackAr_insertp(TrackAr *arr, int index, Track *elem, Error *err) {
    Array_insertNCheck(arr, index, 1, err);
    Track *p = (Track *)Array_insertN((Array*)arr, index, 1);
    *p = *elem;
}


static inline void TrackAr_remove(TrackAr *arr, int index, Error *err) {
    Array_removeNCheck(arr, index, 1, err);
    Array_removeN((Array*)arr, index, 1);
}

static inline void TrackAr_removeN(TrackAr *arr, int index, int N, Error *err) {
    Array_removeNCheck(arr, index, N, err);
    Array_removeN((Array*)arr, index, N);
}

static inline void TrackAr_fit(TrackAr *arr) {
    Array_fit((Array*)arr);
}

static inline int TrackAr_last(TrackAr *arr) {
    return Array_len((Array*)arr)-1;
}

static inline void TrackAr_changeLength(TrackAr *arr, int newLength) {
    Array_changeLength((Array*)arr, newLength);
}

typedef struct TrackArIter_t {
   TrackAr *arr;
   int index;
   bool last;
   Track *var;
} TrackArIter;

static inline bool TrackArIter_next(TrackArIter *iterator) {
    return ArrayIter_next((ArrayIter*)iterator);
}

static inline bool TrackArIter_previous(TrackArIter *iterator) {
    return ArrayIter_previous((ArrayIter*)iterator);
}

#define TrackArIter_declare(var, arr)  TrackArIter var = {arr, -1, false, NULL}
#define TrackArIter_rdeclare(var, arr)  TrackArIter var = {arr, TrackAr_len(arr), false, NULL}
#define TrackAr_foreach(var, arr)  for (TrackArIter_declare(var, arr); TrackArIter_next(&var); )
#define TrackAr_rforeach(var, arr)  for (TrackArIter_rdeclare(var, arr); TrackArIter_previous(&var); )
#define TrackAr_loop(var, arr)    TrackArIter_declare(var, arr); while (TrackArIter_next(&var)) 
#define TrackAr_rloop(var, arr)    TrackArIter_rdeclare(var, arr); while (TrackArIter_previous(&var)) 

