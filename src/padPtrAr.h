typedef struct PadPtrAr_t {
    Array body;
} PadPtrAr;

static inline PadPtrAr *PadPtrAr_new(int nelems) {
    return (PadPtrAr*)Array_new(nelems, sizeof(Pad *), (Array_clearElement)NULL);
}

static inline void PadPtrAr_init(PadPtrAr *arr, int nelems) {
    Array_init((Array*)arr, nelems, sizeof(Pad *), (Array_clearElement)NULL);
}

static inline void PadPtrAr_clear(PadPtrAr *arr) {
    Array_clear((Array*)arr);
    PadPtrAr zero = {{0}};
    *arr = zero;
}

static inline void PadPtrAr_free(PadPtrAr *arr) {
    Array_free((Array*)arr);
}

static inline void PadPtrAr_truncate(PadPtrAr *arr) {
    Array_truncate((Array*)arr);
}

static inline int PadPtrAr_len(PadPtrAr *arr) {
    return Array_len((Array*)arr);
}

static inline Pad *PadPtrAr_get(PadPtrAr *arr, int index, Error *err) {
    Pad * v = {0};
    Array_getCheck(arr, index, v, err);
    memmove(&v, Array_get((Array*)arr, index), Array_elemSize((Array*)arr));
    return v;
}

static inline Pad **PadPtrAr_getp(PadPtrAr *arr, int index, Error *err) {
    Array_getCheck(arr, index, NULL, err);
    return (Pad **)Array_get((Array*)arr, index);
}


static inline void PadPtrAr_set(PadPtrAr *arr, int index, Pad *elem, Error *err) {
    Array_setCheck(arr, index, err);
    Array_set((Array*)arr, index, (char*)&elem);
}

static inline void PadPtrAr_setp(PadPtrAr *arr, int index, Pad **elem, Error *err) {
    Array_setCheck(arr, index, err);
    Array_set((Array*)arr, index, (char*)elem);
}

static inline void PadPtrAr_pop(PadPtrAr *arr, Error *err) {
    Array_popNCheck(arr, 1, err);
    Array_popN((Array*)arr, 1);
}

static inline void PadPtrAr_push(PadPtrAr *arr, Pad *elem) {
    Pad * *p = (Pad **)Array_pushN((Array*)arr, 1);
    *p = elem;
    return; 
}

static inline void PadPtrAr_pushp(PadPtrAr *arr, Pad **elem) {
    Pad * *p = (Pad **)Array_pushN((Array*)arr, 1);
    *p = *elem;
    return; 
}

static inline void PadPtrAr_insert(PadPtrAr *arr, int index, Pad *elem, Error *err) {
    Array_insertNCheck(arr, index, 1, err);
    Pad * *p = (Pad **)Array_insertN((Array*)arr, index, 1);
    *p = elem;
}

static inline void PadPtrAr_insertp(PadPtrAr *arr, int index, Pad **elem, Error *err) {
    Array_insertNCheck(arr, index, 1, err);
    Pad * *p = (Pad **)Array_insertN((Array*)arr, index, 1);
    *p = *elem;
}


static inline void PadPtrAr_remove(PadPtrAr *arr, int index, Error *err) {
    Array_removeNCheck(arr, index, 1, err);
    Array_removeN((Array*)arr, index, 1);
}

static inline void PadPtrAr_fit(PadPtrAr *arr) {
    Array_fit((Array*)arr);
}

static inline int PadPtrAr_last(PadPtrAr *arr) {
    return Array_len((Array*)arr)-1;
}

typedef struct PadPtrArIter_t {
   PadPtrAr *arr;
   int index;
   bool last;
   Pad **var;
} PadPtrArIter;

static inline bool PadPtrArIter_next(PadPtrArIter *iterator) {
    return ArrayIter_next((ArrayIter*)iterator);
}

static inline bool PadPtrArIter_previous(PadPtrArIter *iterator) {
    return ArrayIter_previous((ArrayIter*)iterator);
}

#define PadPtrArIter_declare(var, arr)  PadPtrArIter var = {arr, -1, false, NULL}
#define PadPtrArIter_rdeclare(var, arr)  PadPtrArIter var = {arr, PadPtrAr_len(arr), false, NULL}
#define PadPtrAr_foreach(var, arr)  for (PadPtrArIter_declare(var, arr); PadPtrArIter_next(&var); )
#define PadPtrAr_rforeach(var, arr)  for (PadPtrArIter_rdeclare(var, arr); PadPtrArIter_previous(&var); )
#define PadPtrAr_loop(var, arr)    PadPtrArIter_declare(var, arr); while (PadPtrArIter_next(&var)) 
#define PadPtrAr_rloop(var, arr)    PadPtrArIter_rdeclare(var, arr); while (PadPtrArIter_previous(&var)) 


