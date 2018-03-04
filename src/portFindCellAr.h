typedef struct PortFindCellAr_t {
    Array body;
} PortFindCellAr;

static inline PortFindCellAr *PortFindCellAr_new(int nelems) {
    return (PortFindCellAr*)Array_new(nelems, sizeof(PortFindCell), (Array_clearElement)NULL);
}

static inline void PortFindCellAr_init(PortFindCellAr *arr, int nelems) {
    Array_init((Array*)arr, nelems, sizeof(PortFindCell), (Array_clearElement)NULL);
}

static inline void PortFindCellAr_clear(PortFindCellAr *arr) {
    Array_clear((Array*)arr);
    PortFindCellAr zero = {{0}};
    *arr = zero;
}

static inline void PortFindCellAr_free(PortFindCellAr *arr) {
    Array_free((Array*)arr);
}

static inline void PortFindCellAr_truncate(PortFindCellAr *arr) {
    Array_truncate((Array*)arr);
}

static inline int PortFindCellAr_len(PortFindCellAr *arr) {
    return Array_len((Array*)arr);
}

static inline PortFindCell PortFindCellAr_get(PortFindCellAr *arr, int index, Error *err) {
    PortFindCell v = {0};
    Array_getCheck(arr, index, v, err);
    memmove(&v, Array_get((Array*)arr, index), Array_elemSize((Array*)arr));
    return v;
}

static inline PortFindCell *PortFindCellAr_getp(PortFindCellAr *arr, int index, Error *err) {
    Array_getCheck(arr, index, NULL, err);
    return (PortFindCell *)Array_get((Array*)arr, index);
}


static inline void PortFindCellAr_set(PortFindCellAr *arr, int index, PortFindCell elem, Error *err) {
    Array_setCheck(arr, index, err);
    Array_set((Array*)arr, index, (char*)&elem);
}

static inline void PortFindCellAr_setp(PortFindCellAr *arr, int index, PortFindCell *elem, Error *err) {
    Array_setCheck(arr, index, err);
    Array_set((Array*)arr, index, (char*)elem);
}

static inline void PortFindCellAr_pop(PortFindCellAr *arr, Error *err) {
    Array_popNCheck(arr, 1, err);
    Array_popN((Array*)arr, 1);
}

static inline void PortFindCellAr_push(PortFindCellAr *arr, PortFindCell elem) {
    PortFindCell *p = (PortFindCell *)Array_pushN((Array*)arr, 1);
    *p = elem;
    return; 
}

static inline void PortFindCellAr_pushp(PortFindCellAr *arr, PortFindCell *elem) {
    PortFindCell *p = (PortFindCell *)Array_pushN((Array*)arr, 1);
    *p = *elem;
    return; 
}

static inline void PortFindCellAr_insert(PortFindCellAr *arr, int index, PortFindCell elem, Error *err) {
    Array_insertNCheck(arr, index, 1, err);
    PortFindCell *p = (PortFindCell *)Array_insertN((Array*)arr, index, 1);
    *p = elem;
}

static inline void PortFindCellAr_insertp(PortFindCellAr *arr, int index, PortFindCell *elem, Error *err) {
    Array_insertNCheck(arr, index, 1, err);
    PortFindCell *p = (PortFindCell *)Array_insertN((Array*)arr, index, 1);
    *p = *elem;
}


static inline void PortFindCellAr_remove(PortFindCellAr *arr, int index, Error *err) {
    Array_removeNCheck(arr, index, 1, err);
    Array_removeN((Array*)arr, index, 1);
}

static inline void PortFindCellAr_fit(PortFindCellAr *arr) {
    Array_fit((Array*)arr);
}

static inline int PortFindCellAr_last(PortFindCellAr *arr) {
    return Array_len((Array*)arr)-1;
}

static inline int PortFindCellAr_changeLength(PortFindCellAr *arr, int newLength) {
    return Array_changeLength((Array*)arr, newLength);
}

typedef struct PortFindCellArIter_t {
   PortFindCellAr *arr;
   int index;
   bool last;
   PortFindCell *var;
} PortFindCellArIter;

static inline bool PortFindCellArIter_next(PortFindCellArIter *iterator) {
    return ArrayIter_next((ArrayIter*)iterator);
}

static inline bool PortFindCellArIter_previous(PortFindCellArIter *iterator) {
    return ArrayIter_previous((ArrayIter*)iterator);
}

#define PortFindCellArIter_declare(var, arr)  PortFindCellArIter var = {arr, -1, false, NULL}
#define PortFindCellArIter_rdeclare(var, arr)  PortFindCellArIter var = {arr, PortFindCellAr_len(arr), false, NULL}
#define PortFindCellAr_foreach(var, arr)  for (PortFindCellArIter_declare(var, arr); PortFindCellArIter_next(&var); )
#define PortFindCellAr_rforeach(var, arr)  for (PortFindCellArIter_rdeclare(var, arr); PortFindCellArIter_previous(&var); )
#define PortFindCellAr_loop(var, arr)    PortFindCellArIter_declare(var, arr); while (PortFindCellArIter_next(&var)) 
#define PortFindCellAr_rloop(var, arr)    PortFindCellArIter_rdeclare(var, arr); while (PortFindCellArIter_previous(&var)) 
