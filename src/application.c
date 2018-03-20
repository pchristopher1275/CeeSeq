//      *** DO NOT MODIFY THIS FILE generated 03/20/2018 16:34:02 ***
struct Arguments_t;
typedef struct Arguments_t Arguments;
struct Marshal_t;
typedef struct Marshal_t Marshal;
typedef struct Marshal_t MarshalSi;
typedef struct Marshal_t MarshalSii;
typedef struct Marshal_t MarshalSs;
struct Dispatch_t;
typedef struct Dispatch_t Dispatch;
typedef struct Dispatch_t IncrementFrameDispatch;
typedef struct Dispatch_t DecrementFrameDispatch;
typedef struct Dispatch_t SelectNextPushedPadDispatch;
typedef struct Dispatch_t MidiFileDropDispatch;
typedef struct Dispatch_t ManageChokeGroupsDispatch;
struct MEventAr_t;
typedef struct MEventAr_t MEventAr;
struct PtrAr_t;
typedef struct PtrAr_t PtrAr;
struct SymbolPtrAr_t;
typedef struct SymbolPtrAr_t SymbolPtrAr;
struct IntAr_t;
typedef struct IntAr_t IntAr;
struct BinFilePayload_t;
typedef struct BinFilePayload_t BinFilePayload;
struct BinFile_t;
typedef struct BinFile_t BinFile;
struct Midiseq_t;
typedef struct Midiseq_t Midiseq;
struct Pad_t;
typedef struct Pad_t Pad;
struct IndexedOff_t;
typedef struct IndexedOff_t IndexedOff;
struct TimedOff_t;
typedef struct TimedOff_t TimedOff;
struct NoteManager_t;
typedef struct NoteManager_t NoteManager;
struct PortFindCell_t;
typedef struct PortFindCell_t PortFindCell;
struct PortFind_t;
typedef struct PortFind_t PortFind;
struct PadList_t;
typedef struct PadList_t PadList;
struct Track_t;
typedef struct Track_t Track;
struct TrackList_t;
typedef struct TrackList_t TrackList;
struct PortRef_t;
typedef struct PortRef_t PortRef;
struct DropDown_t;
typedef struct DropDown_t DropDown;
struct Hub_t;
typedef struct Hub_t Hub;
struct Outlet_t;
typedef struct Outlet_t Outlet;
struct Timed_t;
typedef struct Timed_t Timed;
struct NoteEvent_t;
typedef struct NoteEvent_t NoteEvent;
struct FloatEvent_t;
typedef struct FloatEvent_t FloatEvent;
struct NoteSequence_t;
typedef struct NoteSequence_t NoteSequence;
struct Sequence_t;
typedef struct Sequence_t Sequence;
struct RecordBuffer_t;
typedef struct RecordBuffer_t RecordBuffer;
typedef struct Array_t {
   int len;
   int cap;
   int elemSize;
   void (*clearer)(char*);
   char *data;
} Array;

typedef struct ArrayIt_t {
   Array *arr;
   int index;
   bool last;
   char *var;
} ArrayIt;

struct RecordBuffer_t
{
    Ticks recordStart;
    SequenceAr sequences;
};
struct Sequence_t
{
    int itype;
    long version;
};
struct NoteSequence_t
{
    long version;
    Ticks sequenceLength;
    Ticks startTime;
    int cursor;
    bool cycle;
    Outlet *outlet;
    NoteSequence *recordBuffer;
    TimedOffAr offs;
    NoteEventAr events;
};
struct FloatEvent_t
{
    Ticks time;
    double value;
};
struct NoteEvent_t
{
    uint8_t pitch;
    uint8_t velocity;
    Ticks stime;
    Ticks duration;
};
struct Timed_t
{
    Ticks time;
    int version;
    Sequence *sequence;
};
struct Outlet_t
{
    int itype;
};
struct Arguments_t
{
    Symbol *s1;
    long i1;
    long i2;
    long ivalue;
    long inlet;
};
typedef struct SymbolPtrAr_t {
   int len;
   int cap;
   int elemSize;
   void (*clearer)(Symbol **);
   Symbol **data;
} SymbolPtrAr;

typedef struct SymbolPtrArIt_t {
   SymbolPtrAr *arr;
   int index;
   bool last;
   Symbol **var;
} SymbolPtrArIt;

struct PortRef_t
{
    Port *port;
    int outlet;
};
struct DropDown_t
{
    SymbolPtrAr table;
    int selected;
    PortRef portRef;
};
struct Hub_t
{
    PadList *padList;
    TrackList *trackList;
    Port *currBankPort;
    Port *currFramePort;
    Port *selBankPort;
    Port *selFramePort;
    Port *selPadPort;
    Port *chokeGroupPort;
    DropDown cgLocalGlobalMenu;
    DropDown cgInstrumentMenu;
    DropDown cgIndexMenu;
    int bank;
    int frame;
    bool grabNextTappedPad;
    int selectedPad;
    Arguments arguments;
    DispatchPtAr dispatcher;
    RecordBuffer *recordBuffer;
    SequenceAr runningSequences;
    Ticks masterClock;
    TimedAr queue;
};
struct TrackList_t
{
    TrackAr list;
};
struct Track_t
{
    Symbol *name;
    NoteManager *noteManager;
};
struct PadList_t
{
    PadAr pads;
    PadPtrAr running;
};
struct PortFind_t
{
    PortFindCellAr objects;
    void *hub;
    Port_anythingDispatchFunc anythingDispatch;
    Port_intDispatchFunc intDispatch;
};
struct PortFindCell_t
{
    Port *reciever;
    t_symbol *varname;
};
struct NoteManager_t
{
    TimedOffAr pending;
    IndexedOffAr endgroups;
    Port *output;
    t_atom *atoms;
};
struct TimedOff_t
{
    Ticks time;
    int pitch;
};
struct IndexedOff_t
{
    int padIndex;
    int pitch;
};
struct Pad_t
{
    t_symbol *trackName;
    int padIndex;
    Midiseq *sequence;
    bool chokeGroupGlobal;
    int chokeGroupInstrument;
    int chokeGroupIndex;
    int64_t chokeGroup;
    bool noteReleasePending;
    bool inEndgroup;
    Track *track;
    SequenceAr sequenceList;
    bool useMasterClock;
};
typedef struct MEventAr_t {
   int len;
   int cap;
   int elemSize;
   void (*clearer)(MEvent*);
   MEvent *data;
} MEventAr;

typedef struct MEventArIt_t {
   MEventAr *arr;
   int index;
   bool last;
   MEvent *var;
} MEventArIt;

struct Midiseq_t
{
    bool useMasterClock;
    Ticks sequenceLength;
    MEventAr events;
    Ticks startTime;
    int ptr;
};
struct BinFile_t
{
    int version;
    sds filename;
    sds buffer;
    FILE *stream;
    BinFilePayload *payload;
};
struct BinFilePayload_t
{
    PortFind *portFind;
};
typedef struct IntAr_t {
   int len;
   int cap;
   int elemSize;
   void (*clearer)(int*);
   int *data;
} IntAr;

typedef struct IntArIt_t {
   IntAr *arr;
   int index;
   bool last;
   int *var;
} IntArIt;

typedef struct PtrAr_t {
   int len;
   int cap;
   int elemSize;
   void (*clearer)(void **);
   void **data;
} PtrAr;

typedef struct PtrArIt_t {
   PtrAr *arr;
   int index;
   bool last;
   void **var;
} PtrArIt;

struct ManageChokeGroupsDispatch_t
{
    int itype;
};
struct MidiFileDropDispatch_t
{
    int itype;
};
struct SelectNextPushedPadDispatch_t
{
    int itype;
};
struct DecrementFrameDispatch_t
{
    int itype;
};
struct IncrementFrameDispatch_t
{
    int itype;
};
struct Dispatch_t
{
    int itype;
    Symbol *selector;
    Symbol *portId;
    int inlet;
    Marshal *marshal;
};
struct MarshalSs_t
{
    int itype;
};
struct MarshalSii_t
{
    int itype;
};
struct MarshalSi_t
{
    int itype;
};
struct Marshal_t
{
    int itype;
};
