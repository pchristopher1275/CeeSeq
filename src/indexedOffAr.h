typedef struct IndexedOffAr_t {
    Array body;
} IndexedOffAr;

static inline IndexedOffAr *IndexedOffAr_new(int nelems) {
    return (IndexedOffAr*)Array_new(nelems, sizeof(IndexedOff), (Array_clearElement)NULL);
}

static inline void IndexedOffAr_init(IndexedOffAr *arr, int nelems) {
    Array_init((Array*)arr, nelems, sizeof(IndexedOff), (Array_clearElement)NULL);
}

static inline void IndexedOffAr_clear(IndexedOffAr *arr) {
    Array_clear((Array*)arr);
    IndexedOffAr zero = {{0}};
    *arr = zero;
}

static inline void IndexedOffAr_free(IndexedOffAr *arr) {
    Array_free((Array*)arr);
}

static inline void IndexedOffAr_truncate(IndexedOffAr *arr) {
    Array_truncate((Array*)arr);
}

static inline int IndexedOffAr_len(IndexedOffAr *arr) {
    return Array_len((Array*)arr);
}

static inline IndexedOff IndexedOffAr_get(IndexedOffAr *arr, int index, Error *err) {
    IndexedOff v = {0};
    Array_getCheck(arr, index, v, err);
    memmove(&v, Array_get((Array*)arr, index), Array_elemSize((Array*)arr));
    return v;
}

static inline IndexedOff *IndexedOffAr_getp(IndexedOffAr *arr, int index, Error *err) {
    Array_getCheck(arr, index, NULL, err);
    return (IndexedOff *)Array_get((Array*)arr, index);
}


static inline void IndexedOffAr_set(IndexedOffAr *arr, int index, IndexedOff elem, Error *err) {
    Array_setCheck(arr, index, err);
    Array_set((Array*)arr, index, (char*)&elem);
}

static inline void IndexedOffAr_setp(IndexedOffAr *arr, int index, IndexedOff *elem, Error *err) {
    Array_setCheck(arr, index, err);
    Array_set((Array*)arr, index, (char*)elem);
}

static inline void IndexedOffAr_pop(IndexedOffAr *arr, Error *err) {
    Array_popNCheck(arr, 1, err);
    Array_popN((Array*)arr, 1);
}

static inline void IndexedOffAr_push(IndexedOffAr *arr, IndexedOff elem) {
    IndexedOff *p = (IndexedOff *)Array_pushN((Array*)arr, 1);
    *p = elem;
    return; 
}

static inline void IndexedOffAr_pushp(IndexedOffAr *arr, IndexedOff *elem) {
    IndexedOff *p = (IndexedOff *)Array_pushN((Array*)arr, 1);
    *p = *elem;
    return; 
}

static inline void IndexedOffAr_insert(IndexedOffAr *arr, int index, IndexedOff elem, Error *err) {
    Array_insertNCheck(arr, index, 1, err);
    IndexedOff *p = (IndexedOff *)Array_insertN((Array*)arr, index, 1);
    *p = elem;
}

static inline void IndexedOffAr_insertp(IndexedOffAr *arr, int index, IndexedOff *elem, Error *err) {
    Array_insertNCheck(arr, index, 1, err);
    IndexedOff *p = (IndexedOff *)Array_insertN((Array*)arr, index, 1);
    *p = *elem;
}


static inline void IndexedOffAr_remove(IndexedOffAr *arr, int index, Error *err) {
    Array_removeNCheck(arr, index, 1, err);
    Array_removeN((Array*)arr, index, 1);
}

static inline void IndexedOffAr_removeN(IndexedOffAr *arr, int index, int N, Error *err) {
    Array_removeNCheck(arr, index, N, err);
    Array_removeN((Array*)arr, index, N);
}

static inline void IndexedOffAr_fit(IndexedOffAr *arr) {
    Array_fit((Array*)arr);
}

static inline int IndexedOffAr_last(IndexedOffAr *arr) {
    return Array_len((Array*)arr)-1;
}

static inline void IndexedOffAr_changeLength(IndexedOffAr *arr, int newLength) {
    Array_changeLength((Array*)arr, newLength);
}

typedef struct IndexedOffArIter_t {
   IndexedOffAr *arr;
   int index;
   bool last;
   IndexedOff *var;
} IndexedOffArIter;

static inline bool IndexedOffArIter_next(IndexedOffArIter *iterator) {
    return ArrayIter_next((ArrayIter*)iterator);
}

static inline bool IndexedOffArIter_previous(IndexedOffArIter *iterator) {
    return ArrayIter_previous((ArrayIter*)iterator);
}

#define IndexedOffArIter_declare(var, arr)  IndexedOffArIter var = {arr, -1, false, NULL}
#define IndexedOffArIter_rdeclare(var, arr)  IndexedOffArIter var = {arr, IndexedOffAr_len(arr), false, NULL}
#define IndexedOffAr_foreach(var, arr)  for (IndexedOffArIter_declare(var, arr); IndexedOffArIter_next(&var); )
#define IndexedOffAr_rforeach(var, arr)  for (IndexedOffArIter_rdeclare(var, arr); IndexedOffArIter_previous(&var); )
#define IndexedOffAr_loop(var, arr)    IndexedOffArIter_declare(var, arr); while (IndexedOffArIter_next(&var)) 
#define IndexedOffAr_rloop(var, arr)    IndexedOffArIter_rdeclare(var, arr); while (IndexedOffArIter_previous(&var)) 

typedef struct IndexedOffArSlice_t {
    int len;
    IndexedOff *data;
    int index;
    IndexedOff *var;
} IndexedOffArSlice;
#define IndexedOffAr_declareSlice(name) IndexedOffArSlice name = {0}
#define IndexedOffAr_sliceEmpty(slice) (slice.data == NULL)
#define IndexedOffAr_sliceForeach(slice) for (slice.index=0, slice.var=slice.data; slice.index < slice.len; slice.index++, slice.var++)

#define IndexedOffAr_rsliceForeach(slice) for (slice.index=slice.len-1, slice.var = slice.data + slice.index*sizeof(IndexedOff); \
                                              slice.index >= 0; slice.index--, slice.var--)

static inline void IndexedOffAr_binInsertPadIndex(IndexedOffAr *arr, IndexedOff elem) {
    Array_binInsert((Array*)arr, (char*)&elem, (Array_compare)IndexedOff_cmpPadIndex, true);
}

static inline void IndexedOffAr_binRemovePadIndex(IndexedOffAr *arr, IndexedOff elem) {
    Array_binRemove((Array*)arr, (char*)&elem, (Array_compare)IndexedOff_cmpPadIndex, true);
}

static inline void IndexedOffAr_sortPadIndex(IndexedOffAr *arr) {
    Array_sort((Array*)arr, (Array_compare)IndexedOff_cmpPadIndex);
}

static inline IndexedOffArSlice IndexedOffAr_binSearchPadIndex(IndexedOffAr *arr, IndexedOff elem) {
    IndexedOffArSlice slice = {0};
    Array_binSearch((Array*)arr, (char*)&elem, (Array_compare)IndexedOff_cmpPadIndex, (ArraySlice*)&slice);
    return slice;
}
