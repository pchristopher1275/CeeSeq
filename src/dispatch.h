// *** DO NOT MODIFY THIS FILE (see src/dispatch.in.h) generated 03/14/2018 14:15:48 ***
struct Marshal_t;
typedef struct Marshal_t Marshal;
struct Dispatch_t;
typedef struct Dispatch_t Dispatch;
struct Arguments_t;
typedef struct Arguments_t Arguments;
typedef struct Marshal_t MarshalSi;
typedef struct Marshal_t MarshalSii;
typedef struct Marshal_t MarshalSs;
typedef struct Dispatch_t IncrementFrameDispatch;
typedef struct Dispatch_t DecrementFrameDispatch;
typedef struct Dispatch_t SelectNextPushedPadDispatch;
typedef struct Dispatch_t MidiFileDropDispatch;
typedef struct Dispatch_t ManageChokeGroupsDispatch;

// *** DO NOT MODIFY THIS FILE (see src/dispatch.in.h) generated 03/14/2018 14:15:48 ***
struct Arguments_t
{
    Symbol *s1;
    long i1;
    long i2;
    long ivalue;
    long inlet;
};
static inline Symbol *Arguments_s1(Arguments *self){return self->s1;}
static inline void Arguments_setS1(Arguments *self, Symbol *value){self->s1 = value;}
static inline void Arguments_setI1(Arguments *self, long value){self->i1 = value;}
static inline void Arguments_setI2(Arguments *self, long value){self->i2 = value;}
static inline long Arguments_ivalue(Arguments *self){return self->ivalue;}
static inline void Arguments_setIvalue(Arguments *self, long value){self->ivalue = value;}

// *** DO NOT MODIFY THIS FILE (see src/dispatch.in.h) generated 03/14/2018 14:15:48 ***
struct Marshal_t
{
    int itype;
};
Marshal *Marshal_create(int itype);
void Marshal_free(Marshal *self);
void Marshal_process(Marshal *self, Arguments *a1, long a2, Atom *a3, Error *err);
void Marshal_zeroArgs(Marshal *self, Arguments *a1, Error *err);

static inline int Marshal_nthIType(int n, int *itype) {
    static int itypes[] = {
        12, 13, 14
    };
    static int len = sizeof(itypes)/sizeof(int);
    if (n < 0 || n >= len) {
        return 0;
    }
    *itype = itypes[n];
    return 1;
}
#define Marshal_foreachIType(itype) for (int __#itype = 0, itype = 0; Marshal_nthIType(__#itype, &itype); __#itype++)

// *** DO NOT MODIFY THIS FILE (see src/dispatch.in.h) generated 03/14/2018 14:15:48 ***
// type MarshalSi is an alias for Marshal
void MarshalSi_process(MarshalSi *self, Arguments *args, long argc, Atom *argv, Error *err);
void MarshalSi_zeroArgs(MarshalSi *self, Arguments *args);
static inline MarshalSi *MarshalSi_castFromMarshal(Marshal *self) {
    if (self->itype == MarshalSi_itype) {
        return (MarshalSi*)self;
    }
    return NULL;
}
static inline Marshal *MarshalSi_castToMarshal(MarshalSi *self) {
    return (Marshal*)self;
}

// *** DO NOT MODIFY THIS FILE (see src/dispatch.in.h) generated 03/14/2018 14:15:48 ***
// type MarshalSii is an alias for Marshal
void MarshalSii_process(MarshalSii *self, Arguments *args, long argc, Atom *argv, Error *err);
void MarshalSii_zeroArgs(MarshalSi *self, Arguments *args);
static inline MarshalSii *MarshalSii_castFromMarshal(Marshal *self) {
    if (self->itype == MarshalSii_itype) {
        return (MarshalSii*)self;
    }
    return NULL;
}
static inline Marshal *MarshalSii_castToMarshal(MarshalSii *self) {
    return (Marshal*)self;
}

// *** DO NOT MODIFY THIS FILE (see src/dispatch.in.h) generated 03/14/2018 14:15:48 ***
// type MarshalSs is an alias for Marshal
void MarshalSs_process(MarshalSs *self, Arguments *args, long argc, Atom *argv, Error *err);
void MarshalSs_zeroArgs(MarshalSi *self, Arguments *args);
static inline MarshalSs *MarshalSs_castFromMarshal(Marshal *self) {
    if (self->itype == MarshalSs_itype) {
        return (MarshalSs*)self;
    }
    return NULL;
}
static inline Marshal *MarshalSs_castToMarshal(MarshalSs *self) {
    return (Marshal*)self;
}

// *** DO NOT MODIFY THIS FILE (see src/dispatch.in.h) generated 03/14/2018 14:15:48 ***
struct Dispatch_t
{
    int itype;
    Symbol *selector;
    Symbol *portId;
    int inlet;
    Marshal *marshal;
};
int Dispatch_cmp(Dispatch *left, Dispatch *right);
Dispatch *Dispatch_newDefault(int itype);
void Dispatch_freeDefault(Dispatch *d);
void Dispatch_initDispatchPtArDefault(int itype, DispatchPtAr *disPtAr);
typedef struct DispatchPtAr_t {
    Array body;
} DispatchPtAr;

typedef struct DispatchPtArIter_t {
   DispatchPtAr *arr;
   int index;
   bool last;
   Dispatch **var;
} DispatchPtArIter;

static inline void DispatchPtAr_init(DispatchPtAr *arr, int nelems) {
    Array_init((Array*)arr, nelems, sizeof(Dispatch *), (Array_clearElement)NULL);
}

static inline void DispatchPtAr_push(DispatchPtAr *arr, Dispatch *elem) {
    Dispatch * *p = (Dispatch **)Array_pushN((Array*)arr, 1);
    *p = elem;
    return; 
}            

static inline void DispatchPtAr_truncate(DispatchPtAr *arr) {
    Array_truncate((Array*)arr);
}

static inline Dispatch **DispatchPtAr_binSearch(DispatchPtAr *arr, Dispatch *elem) {
    return (Dispatch **)Array_binSearch((Array*)arr, (char*)&elem, (Array_compare)Dispatch_cmp, NULL);
}

static inline void DispatchPtAr_sort(DispatchPtAr *arr) {
    Array_sort((Array*)arr, (Array_compare)Dispatch_cmp);
}                

void Dispatch_exec(Dispatch *self, Hub *a1, Arguments *a2, Error *err);
Dispatch *Dispatch_create(int itype, Error *err);
void Dispatch_free(Dispatch *self, Error *err);
void Dispatch_initDispatchPtAr(int itype, DispatchPtAr *a1, Error *err);

static inline int Dispatch_nthIType(int n, int *itype) {
    static int itypes[] = {
        15, 16, 17, 18, 19
    };
    static int len = sizeof(itypes)/sizeof(int);
    if (n < 0 || n >= len) {
        return 0;
    }
    *itype = itypes[n];
    return 1;
}
#define Dispatch_foreachIType(itype) for (int __#itype = 0, itype = 0; Dispatch_nthIType(__#itype, &itype); __#itype++)

// *** DO NOT MODIFY THIS FILE (see src/dispatch.in.h) generated 03/14/2018 14:15:48 ***
// type IncrementFrameDispatch is an alias for Dispatch
Dispatch *IncrementFrameDispatch_create(IncrementFrameDispatch *self);
void IncrementFrameDispatch_exec(IncrementFrameDispatch *self, Hub *hub, Arguments *args, Error *err);
static inline IncrementFrameDispatch *IncrementFrameDispatch_castFromDispatch(Dispatch *self) {
    if (self->itype == IncrementFrameDispatch_itype) {
        return (IncrementFrameDispatch*)self;
    }
    return NULL;
}
static inline Dispatch *IncrementFrameDispatch_castToDispatch(IncrementFrameDispatch *self) {
    return (Dispatch*)self;
}

// *** DO NOT MODIFY THIS FILE (see src/dispatch.in.h) generated 03/14/2018 14:15:48 ***
// type DecrementFrameDispatch is an alias for Dispatch
Dispatch *DecrementFrameDispatch_create(int itype);
void DecrementFrameDispatch_exec(DecrementFrameDispatch *self, Hub *hub, Arguments *args, Error *err);
static inline DecrementFrameDispatch *DecrementFrameDispatch_castFromDispatch(Dispatch *self) {
    if (self->itype == DecrementFrameDispatch_itype) {
        return (DecrementFrameDispatch*)self;
    }
    return NULL;
}
static inline Dispatch *DecrementFrameDispatch_castToDispatch(DecrementFrameDispatch *self) {
    return (Dispatch*)self;
}

// *** DO NOT MODIFY THIS FILE (see src/dispatch.in.h) generated 03/14/2018 14:15:48 ***
// type SelectNextPushedPadDispatch is an alias for Dispatch
Dispatch *SelectNextPushedPadDispatch_create(int itype);
void SelectNextPushedPadDispatch_exec(SelectNextPushedPadDispatch *self, Hub *hub, Arguments *args, Error *err);
static inline SelectNextPushedPadDispatch *SelectNextPushedPadDispatch_castFromDispatch(Dispatch *self) {
    if (self->itype == SelectNextPushedPadDispatch_itype) {
        return (SelectNextPushedPadDispatch*)self;
    }
    return NULL;
}
static inline Dispatch *SelectNextPushedPadDispatch_castToDispatch(SelectNextPushedPadDispatch *self) {
    return (Dispatch*)self;
}

// *** DO NOT MODIFY THIS FILE (see src/dispatch.in.h) generated 03/14/2018 14:15:48 ***
// type MidiFileDropDispatch is an alias for Dispatch
Dispatch *MidiFileDropDispatch_create(int itype);
void MidiFileDropDispatch_exec(MidiFileDropDispatch *self, Hub *hub, Arguments *args, Error *err);
static inline MidiFileDropDispatch *MidiFileDropDispatch_castFromDispatch(Dispatch *self) {
    if (self->itype == MidiFileDropDispatch_itype) {
        return (MidiFileDropDispatch*)self;
    }
    return NULL;
}
static inline Dispatch *MidiFileDropDispatch_castToDispatch(MidiFileDropDispatch *self) {
    return (Dispatch*)self;
}

// *** DO NOT MODIFY THIS FILE (see src/dispatch.in.h) generated 03/14/2018 14:15:48 ***
// type ManageChokeGroupsDispatch is an alias for Dispatch
int ManageChokeGroupsDispatch_initDispatchPtAr(int myItype, DispatchPtAr *disPtAr);
void ManageChokeGroupsDispatch_exec(ManageChokeGroupsDispatch *self, Hub *hub, Arguments *args, Error *err);
static inline ManageChokeGroupsDispatch *ManageChokeGroupsDispatch_castFromDispatch(Dispatch *self) {
    if (self->itype == ManageChokeGroupsDispatch_itype) {
        return (ManageChokeGroupsDispatch*)self;
    }
    return NULL;
}
static inline Dispatch *ManageChokeGroupsDispatch_castToDispatch(ManageChokeGroupsDispatch *self) {
    return (Dispatch*)self;
}



