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

typedef struct SymbolPtrArIt_t {
   SymbolPtrAr *arr;
   int index;
   bool last;
   Symbol **var;
} SymbolPtrArIt;

static inline bool SymbolPtrArIt_next(SymbolPtrArIt *iterator) {
    return ArrayIt_next((ArrayIt*)iterator);
}

static inline bool SymbolPtrArIt_previous(SymbolPtrArIt *iterator) {
    return ArrayIt_previous((ArrayIt*)iterator);
}

#define SymbolPtrArIt_declare(var, arr)  SymbolPtrArIt var = {arr, -1, false, NULL}
#define SymbolPtrArIt_rdeclare(var, arr)  SymbolPtrArIt var = {arr, SymbolPtrAr_len(arr), false, NULL}
#define SymbolPtrAr_foreach(var, arr)  for (SymbolPtrArIt_declare(var, arr); SymbolPtrArIt_next(&var); )
#define SymbolPtrAr_rforeach(var, arr)  for (SymbolPtrArIt_rdeclare(var, arr); SymbolPtrArIt_previous(&var); )
#define SymbolPtrAr_loop(var, arr)    SymbolPtrArIt_declare(var, arr); while (SymbolPtrArIt_next(&var)) 
#define SymbolPtrAr_rloop(var, arr)    SymbolPtrArIt_rdeclare(var, arr); while (SymbolPtrArIt_previous(&var)) 

