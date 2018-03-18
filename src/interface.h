typedef struct Undefined_t {
    int itype;
    char buffer[1024];
} Undefined;
#define Undefined_itype 10
Undefined Undefined_instance = {Undefined_itype, {0}};
#define Undefined_ptr(typename) ((typename*)&Undefined_instance)

// From file 'src/sequence.in.h'

// From file 'src/dispatch.in.h'
#define MarshalSi_itype 12
#define MarshalSii_itype 13
#define MarshalSs_itype 14
#define IncrementFrameDispatch_itype 15
#define DecrementFrameDispatch_itype 16
#define SelectNextPushedPadDispatch_itype 17
#define MidiFileDropDispatch_itype 18
#define ManageChokeGroupsDispatch_itype 19

// From file 'src/midiseq.in.h'
const char *Interface_toString(int itype);