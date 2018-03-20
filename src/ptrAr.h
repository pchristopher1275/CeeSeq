typedef struct PtrAr_t {
    Array body;
} PtrAr;

static inline PtrAr *PtrAr_new(int nelems) {
    return (PtrAr*)Array_new(nelems, sizeof(void *), (Array_clearElement)NULL);
}

static inline void PtrAr_init(PtrAr *arr, int nelems) {
    Array_init((Array*)arr, nelems, sizeof(void *), (Array_clearElement)NULL);
}

static inline void PtrAr_clear(PtrAr *arr) {
    Array_clear((Array*)arr);
    PtrAr zero = {{0}};
    *arr = zero;
}

static inline void PtrAr_free(PtrAr *arr) {
    Array_free((Array*)arr);
}

static inline void PtrAr_truncate(PtrAr *arr) {
    Array_truncate((Array*)arr);
}

static inline int PtrAr_len(PtrAr *arr) {
    return Array_len((Array*)arr);
}

static inline void *PtrAr_get(PtrAr *arr, int index, Error *err) {
    void * v = {0};
    Array_getCheck(arr, index, v, err);
    memmove(&v, Array_get((Array*)arr, index), Array_elemSize((Array*)arr));
    return v;
}

static inline void **PtrAr_getp(PtrAr *arr, int index, Error *err) {
    Array_getCheck(arr, index, NULL, err);
    return (void **)Array_get((Array*)arr, index);
}


static inline void PtrAr_set(PtrAr *arr, int index, void *elem, Error *err) {
    Array_setCheck(arr, index, err);
    Array_set((Array*)arr, index, (char*)&elem);
}

static inline void PtrAr_setp(PtrAr *arr, int index, void **elem, Error *err) {
    Array_setCheck(arr, index, err);
    Array_set((Array*)arr, index, (char*)elem);
}

static inline void PtrAr_pop(PtrAr *arr, Error *err) {
    Array_popNCheck(arr, 1, err);
    Array_popN((Array*)arr, 1);
}

static inline void PtrAr_push(PtrAr *arr, void *elem) {
    void * *p = (void **)Array_pushN((Array*)arr, 1);
    *p = elem;
    return; 
}

static inline void PtrAr_pushp(PtrAr *arr, void **elem) {
    void * *p = (void **)Array_pushN((Array*)arr, 1);
    *p = *elem;
    return; 
}

static inline void PtrAr_insert(PtrAr *arr, int index, void *elem, Error *err) {
    Array_insertNCheck(arr, index, 1, err);
    void * *p = (void **)Array_insertN((Array*)arr, index, 1);
    *p = elem;
}

static inline void PtrAr_insertp(PtrAr *arr, int index, void **elem, Error *err) {
    Array_insertNCheck(arr, index, 1, err);
    void * *p = (void **)Array_insertN((Array*)arr, index, 1);
    *p = *elem;
}


static inline void PtrAr_remove(PtrAr *arr, int index, Error *err) {
    Array_removeNCheck(arr, index, 1, err);
    Array_removeN((Array*)arr, index, 1);
}

static inline void PtrAr_removeN(PtrAr *arr, int index, int N, Error *err) {
    Array_removeNCheck(arr, index, N, err);
    Array_removeN((Array*)arr, index, N);
}

static inline void PtrAr_fit(PtrAr *arr) {
    Array_fit((Array*)arr);
}

static inline int PtrAr_last(PtrAr *arr) {
    return Array_len((Array*)arr)-1;
}

static inline void PtrAr_changeLength(PtrAr *arr, int newLength) {
    Array_changeLength((Array*)arr, newLength);
}

typedef struct PtrArIt_t {
   PtrAr *arr;
   int index;
   bool last;
   void **var;
} PtrArIt;

static inline bool PtrArIt_next(PtrArIt *iterator) {
    return ArrayIt_next((ArrayIt*)iterator);
}

static inline bool PtrArIt_previous(PtrArIt *iterator) {
    return ArrayIt_previous((ArrayIt*)iterator);
}

#define PtrArIt_declare(var, arr)  PtrArIt var = {arr, -1, false, NULL}
#define PtrArIt_rdeclare(var, arr)  PtrArIt var = {arr, PtrAr_len(arr), false, NULL}
#define PtrAr_foreach(var, arr)  for (PtrArIt_declare(var, arr); PtrArIt_next(&var); )
#define PtrAr_rforeach(var, arr)  for (PtrArIt_rdeclare(var, arr); PtrArIt_previous(&var); )
#define PtrAr_loop(var, arr)    PtrArIt_declare(var, arr); while (PtrArIt_next(&var)) 
#define PtrAr_rloop(var, arr)    PtrArIt_rdeclare(var, arr); while (PtrArIt_previous(&var)) 

