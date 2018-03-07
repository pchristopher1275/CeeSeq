typedef struct SymbolPtrAr_t {
    Array body;
} SymbolPtrAr;

static inline SymbolPtrAr *SymbolPtrAr_new(int nelems) {
    return (SymbolPtrAr*)Array_new(nelems, sizeof(Symbol *), (Array_clearElement)NULL);
}

static inline void SymbolPtrAr_init(SymbolPtrAr *arr, int nelems) {
    Array_init((Array*)arr, nelems, sizeof(Symbol *), (Array_clearElement)NULL);
}

static inline void SymbolPtrAr_clear(SymbolPtrAr *arr) {
    Array_clear((Array*)arr);
    SymbolPtrAr zero = {{0}};
    *arr = zero;
}

static inline void SymbolPtrAr_free(SymbolPtrAr *arr) {
    Array_free((Array*)arr);
}

static inline void SymbolPtrAr_truncate(SymbolPtrAr *arr) {
    Array_truncate((Array*)arr);
}

static inline int SymbolPtrAr_len(SymbolPtrAr *arr) {
    return Array_len((Array*)arr);
}

static inline Symbol *SymbolPtrAr_get(SymbolPtrAr *arr, int index, Error *err) {
    Symbol * v = {0};
    Array_getCheck(arr, index, v, err);
    memmove(&v, Array_get((Array*)arr, index), Array_elemSize((Array*)arr));
    return v;
}

static inline Symbol **SymbolPtrAr_getp(SymbolPtrAr *arr, int index, Error *err) {
    Array_getCheck(arr, index, NULL, err);
    return (Symbol **)Array_get((Array*)arr, index);
}


static inline void SymbolPtrAr_set(SymbolPtrAr *arr, int index, Symbol *elem, Error *err) {
    Array_setCheck(arr, index, err);
    Array_set((Array*)arr, index, (char*)&elem);
}

static inline void SymbolPtrAr_setp(SymbolPtrAr *arr, int index, Symbol **elem, Error *err) {
    Array_setCheck(arr, index, err);
    Array_set((Array*)arr, index, (char*)elem);
}

static inline void SymbolPtrAr_pop(SymbolPtrAr *arr, Error *err) {
    Array_popNCheck(arr, 1, err);
    Array_popN((Array*)arr, 1);
}

static inline void SymbolPtrAr_push(SymbolPtrAr *arr, Symbol *elem) {
    Symbol * *p = (Symbol **)Array_pushN((Array*)arr, 1);
    *p = elem;
    return; 
}

static inline void SymbolPtrAr_pushp(SymbolPtrAr *arr, Symbol **elem) {
    Symbol * *p = (Symbol **)Array_pushN((Array*)arr, 1);
    *p = *elem;
    return; 
}

static inline void SymbolPtrAr_insert(SymbolPtrAr *arr, int index, Symbol *elem, Error *err) {
    Array_insertNCheck(arr, index, 1, err);
    Symbol * *p = (Symbol **)Array_insertN((Array*)arr, index, 1);
    *p = elem;
}

static inline void SymbolPtrAr_insertp(SymbolPtrAr *arr, int index, Symbol **elem, Error *err) {
    Array_insertNCheck(arr, index, 1, err);
    Symbol * *p = (Symbol **)Array_insertN((Array*)arr, index, 1);
    *p = *elem;
}


static inline void SymbolPtrAr_remove(SymbolPtrAr *arr, int index, Error *err) {
    Array_removeNCheck(arr, index, 1, err);
    Array_removeN((Array*)arr, index, 1);
}

static inline void SymbolPtrAr_removeN(SymbolPtrAr *arr, int index, int N, Error *err) {
    Array_removeNCheck(arr, index, N, err);
    Array_removeN((Array*)arr, index, N);
}

static inline void SymbolPtrAr_fit(SymbolPtrAr *arr) {
    Array_fit((Array*)arr);
}

static inline int SymbolPtrAr_last(SymbolPtrAr *arr) {
    return Array_len((Array*)arr)-1;
}

static inline void SymbolPtrAr_changeLength(SymbolPtrAr *arr, int newLength) {
    Array_changeLength((Array*)arr, newLength);
}

typedef struct SymbolPtrArIter_t {
   SymbolPtrAr *arr;
   int index;
   bool last;
   Symbol **var;
} SymbolPtrArIter;

static inline bool SymbolPtrArIter_next(SymbolPtrArIter *iterator) {
    return ArrayIter_next((ArrayIter*)iterator);
}

static inline bool SymbolPtrArIter_previous(SymbolPtrArIter *iterator) {
    return ArrayIter_previous((ArrayIter*)iterator);
}

#define SymbolPtrArIter_declare(var, arr)  SymbolPtrArIter var = {arr, -1, false, NULL}
#define SymbolPtrArIter_rdeclare(var, arr)  SymbolPtrArIter var = {arr, SymbolPtrAr_len(arr), false, NULL}
#define SymbolPtrAr_foreach(var, arr)  for (SymbolPtrArIter_declare(var, arr); SymbolPtrArIter_next(&var); )
#define SymbolPtrAr_rforeach(var, arr)  for (SymbolPtrArIter_rdeclare(var, arr); SymbolPtrArIter_previous(&var); )
#define SymbolPtrAr_loop(var, arr)    SymbolPtrArIter_declare(var, arr); while (SymbolPtrArIter_next(&var)) 
#define SymbolPtrAr_rloop(var, arr)    SymbolPtrArIter_rdeclare(var, arr); while (SymbolPtrArIter_previous(&var)) 

