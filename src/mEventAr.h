typedef struct MEventAr_t {
    Array body;
} MEventAr;

static inline MEventAr *MEventAr_new(int nelems) {
    return (MEventAr*)Array_new(nelems, sizeof(MEvent), (Array_clearElement)NULL);
}

static inline void MEventAr_init(MEventAr *arr, int nelems) {
    Array_init((Array*)arr, nelems, sizeof(MEvent), (Array_clearElement)NULL);
}

static inline void MEventAr_clear(MEventAr *arr) {
    Array_clear((Array*)arr);
    MEventAr zero = {{0}};
    *arr = zero;
}

static inline void MEventAr_free(MEventAr *arr) {
    Array_free((Array*)arr);
}

static inline void MEventAr_truncate(MEventAr *arr) {
    Array_truncate((Array*)arr);
}

static inline int MEventAr_len(MEventAr *arr) {
    return Array_len((Array*)arr);
}

static inline MEvent MEventAr_get(MEventAr *arr, int index, Error *err) {
    MEvent v = {0};
    Array_getCheck(arr, index, v, err);
    memmove(&v, Array_get((Array*)arr, index), Array_elemSize((Array*)arr));
    return v;
}

static inline MEvent *MEventAr_getp(MEventAr *arr, int index, Error *err) {
    Array_getCheck(arr, index, NULL, err);
    return (MEvent *)Array_get((Array*)arr, index);
}


static inline void MEventAr_set(MEventAr *arr, int index, MEvent elem, Error *err) {
    Array_setCheck(arr, index, err);
    Array_set((Array*)arr, index, (char*)&elem);
}

static inline void MEventAr_setp(MEventAr *arr, int index, MEvent *elem, Error *err) {
    Array_setCheck(arr, index, err);
    Array_set((Array*)arr, index, (char*)elem);
}

static inline void MEventAr_pop(MEventAr *arr, Error *err) {
    Array_popNCheck(arr, 1, err);
    Array_popN((Array*)arr, 1);
}

static inline void MEventAr_push(MEventAr *arr, MEvent elem) {
    MEvent *p = (MEvent *)Array_pushN((Array*)arr, 1);
    *p = elem;
    return; 
}

static inline void MEventAr_pushp(MEventAr *arr, MEvent *elem) {
    MEvent *p = (MEvent *)Array_pushN((Array*)arr, 1);
    *p = *elem;
    return; 
}

static inline void MEventAr_insert(MEventAr *arr, int index, MEvent elem, Error *err) {
    Array_insertNCheck(arr, index, 1, err);
    MEvent *p = (MEvent *)Array_insertN((Array*)arr, index, 1);
    *p = elem;
}

static inline void MEventAr_insertp(MEventAr *arr, int index, MEvent *elem, Error *err) {
    Array_insertNCheck(arr, index, 1, err);
    MEvent *p = (MEvent *)Array_insertN((Array*)arr, index, 1);
    *p = *elem;
}


static inline void MEventAr_remove(MEventAr *arr, int index, Error *err) {
    Array_removeNCheck(arr, index, 1, err);
    Array_removeN((Array*)arr, index, 1);
}

static inline void MEventAr_removeN(MEventAr *arr, int index, int N, Error *err) {
    Array_removeNCheck(arr, index, N, err);
    Array_removeN((Array*)arr, index, N);
}

static inline void MEventAr_fit(MEventAr *arr) {
    Array_fit((Array*)arr);
}

static inline int MEventAr_last(MEventAr *arr) {
    return Array_len((Array*)arr)-1;
}

static inline void MEventAr_changeLength(MEventAr *arr, int newLength) {
    Array_changeLength((Array*)arr, newLength);
}

typedef struct MEventArIt_t {
   MEventAr *arr;
   int index;
   bool last;
   MEvent *var;
} MEventArIt;

static inline bool MEventArIt_next(MEventArIt *iterator) {
    return ArrayIt_next((ArrayIt*)iterator);
}

static inline bool MEventArIt_previous(MEventArIt *iterator) {
    return ArrayIt_previous((ArrayIt*)iterator);
}

#define MEventArIt_declare(var, arr)  MEventArIt var = {arr, -1, false, NULL}
#define MEventArIt_rdeclare(var, arr)  MEventArIt var = {arr, MEventAr_len(arr), false, NULL}
#define MEventAr_foreach(var, arr)  for (MEventArIt_declare(var, arr); MEventArIt_next(&var); )
#define MEventAr_rforeach(var, arr)  for (MEventArIt_rdeclare(var, arr); MEventArIt_previous(&var); )
#define MEventAr_loop(var, arr)    MEventArIt_declare(var, arr); while (MEventArIt_next(&var)) 
#define MEventAr_rloop(var, arr)    MEventArIt_rdeclare(var, arr); while (MEventArIt_previous(&var)) 

