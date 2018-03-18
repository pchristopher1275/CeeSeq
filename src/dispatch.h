// *** DO NOT MODIFY THIS FILE (see src/dispatch.in.h) generated 03/16/2018 14:26:58 ***

// *** DO NOT MODIFY THIS FILE (see src/dispatch.in.h) generated 03/16/2018 14:26:58 ***
static inline Symbol *Arguments_s1(Arguments *self){return self->s1;}
static inline void Arguments_setS1(Arguments *self, Symbol *value){self->s1 = value;}
static inline void Arguments_setI1(Arguments *self, long value){self->i1 = value;}
static inline void Arguments_setI2(Arguments *self, long value){self->i2 = value;}
static inline long Arguments_ivalue(Arguments *self){return self->ivalue;}
static inline void Arguments_setIvalue(Arguments *self, long value){self->ivalue = value;}
static inline void Arguments_setInlet(Arguments *self, long value){self->inlet = value;}

// *** DO NOT MODIFY THIS FILE (see src/dispatch.in.h) generated 03/16/2018 14:26:58 ***

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
#define Marshal_foreachIType(itype) for (int __##itype = 0, itype = 0; Marshal_nthIType(__##itype, &itype); __##itype++)

// *** DO NOT MODIFY THIS FILE (see src/dispatch.in.h) generated 03/16/2018 14:26:58 ***
static inline MarshalSi *MarshalSi_castFromMarshal(Marshal *self) {
    if (self->itype == MarshalSi_itype) {
        return (MarshalSi*)self;
    }
    return NULL;
}
static inline Marshal *MarshalSi_castToMarshal(MarshalSi *self) {
    return (Marshal*)self;
}

// *** DO NOT MODIFY THIS FILE (see src/dispatch.in.h) generated 03/16/2018 14:26:58 ***
static inline MarshalSii *MarshalSii_castFromMarshal(Marshal *self) {
    if (self->itype == MarshalSii_itype) {
        return (MarshalSii*)self;
    }
    return NULL;
}
static inline Marshal *MarshalSii_castToMarshal(MarshalSii *self) {
    return (Marshal*)self;
}

// *** DO NOT MODIFY THIS FILE (see src/dispatch.in.h) generated 03/16/2018 14:26:58 ***
static inline MarshalSs *MarshalSs_castFromMarshal(Marshal *self) {
    if (self->itype == MarshalSs_itype) {
        return (MarshalSs*)self;
    }
    return NULL;
}
static inline Marshal *MarshalSs_castToMarshal(MarshalSs *self) {
    return (Marshal*)self;
}

// *** DO NOT MODIFY THIS FILE (see src/dispatch.in.h) generated 03/16/2018 14:26:58 ***

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
#define Dispatch_foreachIType(itype) for (int __##itype = 0, itype = 0; Dispatch_nthIType(__##itype, &itype); __##itype++)
static inline Marshal *Dispatch_marshal(Dispatch *self){return self->marshal;}
#define Dispatch_declare(name, itype, selector, portId, inlet, marshal) Dispatch name = {(itype), (selector), (portId), (inlet), (marshal)}
#define DispatchPtAr_foreach(var, arr)  for (DispatchPtArIter_declare(var, arr); DispatchPtArIter_next(&var); )            

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

#define DispatchPtArIter_declare(var, arr)  DispatchPtArIter var = {arr, -1, false, NULL}            

static inline bool DispatchPtArIter_next(DispatchPtArIter *iterator) {
    return ArrayIter_next((ArrayIter*)iterator);
}

static inline Dispatch **DispatchPtAr_binSearch(DispatchPtAr *arr, Dispatch *elem) {
    return (Dispatch **)Array_binSearch((Array*)arr, (char*)&elem, (Array_compare)Dispatch_cmp, NULL);
}

static inline void DispatchPtAr_sort(DispatchPtAr *arr) {
    Array_sort((Array*)arr, (Array_compare)Dispatch_cmp);
}                


// *** DO NOT MODIFY THIS FILE (see src/dispatch.in.h) generated 03/16/2018 14:26:58 ***
static inline IncrementFrameDispatch *IncrementFrameDispatch_castFromDispatch(Dispatch *self) {
    if (self->itype == IncrementFrameDispatch_itype) {
        return (IncrementFrameDispatch*)self;
    }
    return NULL;
}
static inline Dispatch *IncrementFrameDispatch_castToDispatch(IncrementFrameDispatch *self) {
    return (Dispatch*)self;
}

// *** DO NOT MODIFY THIS FILE (see src/dispatch.in.h) generated 03/16/2018 14:26:58 ***
static inline DecrementFrameDispatch *DecrementFrameDispatch_castFromDispatch(Dispatch *self) {
    if (self->itype == DecrementFrameDispatch_itype) {
        return (DecrementFrameDispatch*)self;
    }
    return NULL;
}
static inline Dispatch *DecrementFrameDispatch_castToDispatch(DecrementFrameDispatch *self) {
    return (Dispatch*)self;
}

// *** DO NOT MODIFY THIS FILE (see src/dispatch.in.h) generated 03/16/2018 14:26:58 ***
static inline SelectNextPushedPadDispatch *SelectNextPushedPadDispatch_castFromDispatch(Dispatch *self) {
    if (self->itype == SelectNextPushedPadDispatch_itype) {
        return (SelectNextPushedPadDispatch*)self;
    }
    return NULL;
}
static inline Dispatch *SelectNextPushedPadDispatch_castToDispatch(SelectNextPushedPadDispatch *self) {
    return (Dispatch*)self;
}

// *** DO NOT MODIFY THIS FILE (see src/dispatch.in.h) generated 03/16/2018 14:26:58 ***
static inline MidiFileDropDispatch *MidiFileDropDispatch_castFromDispatch(Dispatch *self) {
    if (self->itype == MidiFileDropDispatch_itype) {
        return (MidiFileDropDispatch*)self;
    }
    return NULL;
}
static inline Dispatch *MidiFileDropDispatch_castToDispatch(MidiFileDropDispatch *self) {
    return (Dispatch*)self;
}

// *** DO NOT MODIFY THIS FILE (see src/dispatch.in.h) generated 03/16/2018 14:26:58 ***
static inline ManageChokeGroupsDispatch *ManageChokeGroupsDispatch_castFromDispatch(Dispatch *self) {
    if (self->itype == ManageChokeGroupsDispatch_itype) {
        return (ManageChokeGroupsDispatch*)self;
    }
    return NULL;
}
static inline Dispatch *ManageChokeGroupsDispatch_castToDispatch(ManageChokeGroupsDispatch *self) {
    return (Dispatch*)self;
}



