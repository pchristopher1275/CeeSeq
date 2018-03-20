// *** DO NOT MODIFY THIS FILE (see src/sequence.in.h) generated 03/20/2018 10:23:21 ***
// *** DO NOT MODIFY THIS FILE (see src/sequence.in.h) generated 03/20/2018 10:23:21 ***

static inline int Outlet_nthIType(int n, int *itype) {
    static int itypes[] = {
        
    };
    static int len = sizeof(itypes)/sizeof(int);
    if (n < 0 || n >= len) {
        return 0;
    }
    *itype = itypes[n];
    return 1;
}
#define Outlet_foreachIType(itype) for (int __##itype = 0, itype = 0; Outlet_nthIType(__##itype, &itype); __##itype++)


// *** DO NOT MODIFY THIS FILE (see src/sequence.in.h) generated 03/20/2018 10:23:21 ***
static inline Ticks Timed_time(Timed *self){return self->time;}
static inline int Timed_version(Timed *self){return self->version;}
static inline Sequence *Timed_sequence(Timed *self){return self->sequence;}


// *** DO NOT MODIFY THIS FILE (see src/sequence.in.h) generated 03/20/2018 10:23:21 ***
#define NoteEventAr_foreach(var, arr)  for (NoteEventArIt_declare(var, arr); NoteEventArIt_next(&var); )            

static inline int NoteEventAr_len(NoteEventAr *arr) {
    return Array_len((Array*)arr);
}

static inline void NoteEventAr_push(NoteEventAr *arr, NoteEvent elem) {
    NoteEvent *p = (NoteEvent *)Array_pushN((Array*)arr, 1);
    *p = elem;
    return; 
}            

#define NoteEventArIt_declare(var, arr)  NoteEventArIt var = {arr, -1, false, NULL}            

static inline bool NoteEventArIt_next(NoteEventArIt *iterator) {
    return ArrayIt_next((ArrayIt*)iterator);
}


// *** DO NOT MODIFY THIS FILE (see src/sequence.in.h) generated 03/20/2018 10:23:21 ***

// *** DO NOT MODIFY THIS FILE (see src/sequence.in.h) generated 03/20/2018 10:23:21 ***


// *** DO NOT MODIFY THIS FILE (see src/sequence.in.h) generated 03/20/2018 10:23:21 ***

static inline int Sequence_nthIType(int n, int *itype) {
    static int itypes[] = {
        
    };
    static int len = sizeof(itypes)/sizeof(int);
    if (n < 0 || n >= len) {
        return 0;
    }
    *itype = itypes[n];
    return 1;
}
#define Sequence_foreachIType(itype) for (int __##itype = 0, itype = 0; Sequence_nthIType(__##itype, &itype); __##itype++)
static inline long Sequence_version(Sequence *self){return self->version;}
static inline void SequenceAr_clear(SequenceAr *arr) {
    Array_clear((Array*)arr);
    SequenceAr zero = {0};
    *arr = zero;
}

#define SequenceAr_foreach(var, arr)  for (SequenceArIt_declare(var, arr); SequenceArIt_next(&var); )            

static inline void SequenceAr_init(SequenceAr *arr, int nelems) {
    Array_init((Array*)arr, nelems, sizeof(Sequence *), (Array_clearElement)NULL);
}

#define SequenceArIt_declare(var, arr)  SequenceArIt var = {arr, -1, false, NULL}            

static inline bool SequenceArIt_next(SequenceArIt *iterator) {
    return ArrayIt_next((ArrayIt*)iterator);
}


// *** DO NOT MODIFY THIS FILE (see src/sequence.in.h) generated 03/20/2018 10:23:21 ***
