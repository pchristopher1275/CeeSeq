// *** DO NOT MODIFY THIS FILE (see src/dispatch.in.h) generated 03/12/2018 11:58:24 ***
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

// *** DO NOT MODIFY THIS FILE (see src/dispatch.in.h) generated 03/12/2018 11:58:24 ***
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



// *** DO NOT MODIFY THIS FILE (see src/dispatch.in.h) generated 03/12/2018 11:58:24 ***
struct Marshal_t
{
    int itype;
};

// *** DO NOT MODIFY THIS FILE (see src/dispatch.in.h) generated 03/12/2018 11:58:24 ***
struct MarshalSi_t
{
    int itype;
};
void MarshalSi_process(MarshalSi *self, Arguments *args, long argc, Atom *argv, Error *err);
void MarshalSi_zeroArgs(MarshalSi *self, Arguments *args);
void MarshalSi_zeroArgs(MarshalSi *self, Arguments *args);



// *** DO NOT MODIFY THIS FILE (see src/dispatch.in.h) generated 03/12/2018 11:58:24 ***
struct MarshalSii_t
{
    int itype;
};
void MarshalSii_process(MarshalSii *self, Arguments *args, long argc, Atom *argv, Error *err);



// *** DO NOT MODIFY THIS FILE (see src/dispatch.in.h) generated 03/12/2018 11:58:24 ***
struct MarshalSs_t
{
    int itype;
};
void MarshalSs_process(MarshalSs *self, Arguments *args, long argc, Atom *argv, Error *err);
void MarshalSs_zeroArgs(MarshalSi *self, Arguments *args);



// *** DO NOT MODIFY THIS FILE (see src/dispatch.in.h) generated 03/12/2018 11:58:24 ***
struct Dispatch_t
{
    int itype;
    Symbol *selector;
    Symbol *portId;
    int inlet;
    Marshal *marshal;
};

// *** DO NOT MODIFY THIS FILE (see src/dispatch.in.h) generated 03/12/2018 11:58:24 ***
struct IncrementFrameDispatch_t
{
    int itype;
};
void IncrementFrameDispatch_init(IncrementFrameDispatch *self);
void IncrementFrameDispatch_exec(IncrementFrameDispatch *self, Hub *hub, Arguments *args, Error *err);



// *** DO NOT MODIFY THIS FILE (see src/dispatch.in.h) generated 03/12/2018 11:58:24 ***
struct DecrementFrameDispatch_t
{
    int itype;
};
void DecrementFrameDispatch_init(DecrementFrameDispatch *self);
void DecrementFrameDispatch_exec(DecrementFrameDispatch *self, Hub *hub, Arguments *args, Error *err);



// *** DO NOT MODIFY THIS FILE (see src/dispatch.in.h) generated 03/12/2018 11:58:24 ***
struct SelectNextPushedPadDispatch_t
{
    int itype;
};
void SelectNextPushedPadDispatch_init(SelectNextPushedPadDispatch *self);
void SelectNextPushedPadDispatch_exec(SelectNextPushedPadDispatch *self, Hub *hub, Arguments *args, Error *err);



// *** DO NOT MODIFY THIS FILE (see src/dispatch.in.h) generated 03/12/2018 11:58:24 ***
struct MidiFileDropDispatch_t
{
    int itype;
};
void MidiFileDropDispatch_init(MidiFileDropDispatch *self);
void MidiFileDropDispatch_exec(MidiFileDropDispatch *self, Hub *hub, Arguments *args, Error *err);
void MidiFileDropDispatch_clear(MidiFileDropDispatch *self);



// *** DO NOT MODIFY THIS FILE (see src/dispatch.in.h) generated 03/12/2018 11:58:24 ***
struct ManageChokeGroupsDispatch_t
{
    int itype;
};
int ManageChokeGroupsDispatch_initDispatchPtAr(ManageChokeGroupsDispatch *self, DispatchPtAr *disPtAr);
void ManageChokeGroupsDispatch_exec(ManageChokeGroupsDispatch *self, Hub *hub, Arguments *args, Error *err);





