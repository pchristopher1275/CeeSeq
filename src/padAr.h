typedef struct PadAr_t {
    Array body;
} PadAr;

static inline PadAr *PadAr_new(int nelems) {
    return (PadAr*)Array_new(nelems, sizeof(Pad), (Array_clearElement)NULL);
}

static inline void PadAr_init(PadAr *arr, int nelems) {
    Array_init((Array*)arr, nelems, sizeof(Pad), (Array_clearElement)NULL);
}

static inline void PadAr_clear(PadAr *arr) {
    Array_clear((Array*)arr);
    PadAr zero = {{0}};
    *arr = zero;
}

static inline void PadAr_free(PadAr *arr) {
    Array_free((Array*)arr);
}

static inline void PadAr_truncate(PadAr *arr) {
    Array_truncate((Array*)arr);
}

static inline int PadAr_len(PadAr *arr) {
    return Array_len((Array*)arr);
}

static inline Pad PadAr_get(PadAr *arr, int index, Error *err) {
    Pad v = {0};
    Array_getCheck(arr, index, v, err);
    memmove(&v, Array_get((Array*)arr, index), Array_elemSize((Array*)arr));
    return v;
}

static inline Pad *PadAr_getp(PadAr *arr, int index, Error *err) {
    Array_getCheck(arr, index, NULL, err);
    return (Pad *)Array_get((Array*)arr, index);
}


static inline void PadAr_set(PadAr *arr, int index, Pad elem, Error *err) {
    Array_setCheck(arr, index, err);
    Array_set((Array*)arr, index, (char*)&elem);
}

static inline void PadAr_setp(PadAr *arr, int index, Pad *elem, Error *err) {
    Array_setCheck(arr, index, err);
    Array_set((Array*)arr, index, (char*)elem);
}

static inline void PadAr_pop(PadAr *arr, Error *err) {
    Array_popNCheck(arr, 1, err);
    Array_popN((Array*)arr, 1);
}

static inline void PadAr_push(PadAr *arr, Pad elem) {
    Pad *p = (Pad *)Array_pushN((Array*)arr, 1);
    *p = elem;
    return; 
}

static inline void PadAr_pushp(PadAr *arr, Pad *elem) {
    Pad *p = (Pad *)Array_pushN((Array*)arr, 1);
    *p = *elem;
    return; 
}

static inline void PadAr_insert(PadAr *arr, int index, Pad elem, Error *err) {
    Array_insertNCheck(arr, index, 1, err);
    Pad *p = (Pad *)Array_insertN((Array*)arr, index, 1);
    *p = elem;
}

static inline void PadAr_insertp(PadAr *arr, int index, Pad *elem, Error *err) {
    Array_insertNCheck(arr, index, 1, err);
    Pad *p = (Pad *)Array_insertN((Array*)arr, index, 1);
    *p = *elem;
}


static inline void PadAr_remove(PadAr *arr, int index, Error *err) {
    Array_removeNCheck(arr, index, 1, err);
    Array_removeN((Array*)arr, index, 1);
}

static inline void PadAr_removeN(PadAr *arr, int index, int N, Error *err) {
    Array_removeNCheck(arr, index, N, err);
    Array_removeN((Array*)arr, index, N);
}

static inline void PadAr_fit(PadAr *arr) {
    Array_fit((Array*)arr);
}

static inline int PadAr_last(PadAr *arr) {
    return Array_len((Array*)arr)-1;
}

static inline void PadAr_changeLength(PadAr *arr, int newLength) {
    Array_changeLength((Array*)arr, newLength);
}

typedef struct PadArIter_t {
   PadAr *arr;
   int index;
   bool last;
   Pad *var;
} PadArIter;

static inline bool PadArIter_next(PadArIter *iterator) {
    return ArrayIter_next((ArrayIter*)iterator);
}

static inline bool PadArIter_previous(PadArIter *iterator) {
    return ArrayIter_previous((ArrayIter*)iterator);
}

#define PadArIter_declare(var, arr)  PadArIter var = {arr, -1, false, NULL}
#define PadArIter_rdeclare(var, arr)  PadArIter var = {arr, PadAr_len(arr), false, NULL}
#define PadAr_foreach(var, arr)  for (PadArIter_declare(var, arr); PadArIter_next(&var); )
#define PadAr_rforeach(var, arr)  for (PadArIter_rdeclare(var, arr); PadArIter_previous(&var); )
#define PadAr_loop(var, arr)    PadArIter_declare(var, arr); while (PadArIter_next(&var)) 
#define PadAr_rloop(var, arr)    PadArIter_rdeclare(var, arr); while (PadArIter_previous(&var)) 

