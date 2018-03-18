// *** DO NOT MODIFY THIS FILE (see src/dispatch.in.h) generated 03/16/2018 14:26:58 ***
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
// *** DO NOT MODIFY THIS FILE (see src/midiseq.in.h) generated 03/16/2018 14:26:58 ***
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
// *** DO NOT MODIFY THIS FILE (see src/dispatch.in.h) generated 03/16/2018 14:26:58 ***
struct Marshal_t
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
typedef struct DispatchPtAr_t {
    Array body;
} DispatchPtAr;

typedef struct DispatchPtArIter_t {
   DispatchPtAr *arr;
   int index;
   bool last;
   Dispatch **var;
} DispatchPtArIter;

struct Arguments_t
{
    Symbol *s1;
    long i1;
    long i2;
    long ivalue;
    long inlet;
};
// type MarshalSi is an alias for Marshal
// type MarshalSii is an alias for Marshal
// type MarshalSs is an alias for Marshal
// type IncrementFrameDispatch is an alias for Dispatch
// type DecrementFrameDispatch is an alias for Dispatch
// type SelectNextPushedPadDispatch is an alias for Dispatch
// type MidiFileDropDispatch is an alias for Dispatch
// type ManageChokeGroupsDispatch is an alias for Dispatch
// *** DO NOT MODIFY THIS FILE (see src/midiseq.in.h) generated 03/16/2018 14:26:58 ***
struct BinFilePayload_t
{
    PortFind *portFind;
};
struct BinFile_t
{
    int version;
    sds filename;
    sds buffer;
    FILE *stream;
    BinFilePayload *payload;
};
struct Midiseq_t
{
    bool useMasterClock;
    Ticks sequenceLength;
    MEventAr events;
    Ticks startTime;
    int ptr;
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
};
typedef struct PadAr_t {
    Array body;
} PadAr;

typedef struct PadArIter_t {
   PadAr *arr;
   int index;
   bool last;
   Pad *var;
} PadArIter;

typedef struct PadPtrAr_t {
    Array body;
} PadPtrAr;

typedef struct PadPtrArIter_t {
   PadPtrAr *arr;
   int index;
   bool last;
   Pad **var;
} PadPtrArIter;

struct IndexedOff_t
{
    int padIndex;
    int pitch;
};
typedef struct IndexedOffAr_t {
    Array body;
} IndexedOffAr;

typedef struct IndexedOffArSlice_t {
    int len;
    IndexedOff *data;
    int index;
    IndexedOff *var;
} IndexedOffArSlice;

typedef struct IndexedOffArIter_t {
   IndexedOffAr *arr;
   int index;
   bool last;
   IndexedOff *var;
} IndexedOffArIter;

struct TimedOff_t
{
    Ticks time;
    int pitch;
};
typedef struct TimedOffAr_t {
    Array body;
} TimedOffAr;

typedef struct TimedOffArIter_t {
   TimedOffAr *arr;
   int index;
   bool last;
   TimedOff *var;
} TimedOffArIter;

struct NoteManager_t
{
    TimedOffAr pending;
    IndexedOffAr endgroups;
    Port *output;
    t_atom *atoms;
};
struct PortFindCell_t
{
    Port *reciever;
    t_symbol *varname;
};
typedef struct PortFindCellAr_t {
    Array body;
} PortFindCellAr;

typedef struct PortFindCellArIter_t {
   PortFindCellAr *arr;
   int index;
   bool last;
   PortFindCell *var;
} PortFindCellArIter;

struct PortFind_t
{
    PortFindCellAr objects;
    void *hub;
    Port_anythingDispatchFunc anythingDispatch;
    Port_intDispatchFunc intDispatch;
};
struct PadList_t
{
    PadAr pads;
    PadPtrAr running;
};
struct Track_t
{
    Symbol *name;
    NoteManager *noteManager;
};
typedef struct TrackAr_t {
    Array body;
} TrackAr;

typedef struct TrackArIter_t {
   TrackAr *arr;
   int index;
   bool last;
   Track *var;
} TrackArIter;

struct TrackList_t
{
    TrackAr list;
};
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
};
sds DBLog_stripBaseName(const char *path);
void DBLog_printSDS(const char *file, int line, sds message);
static inline bool Error_iserror(Error *err);
sds Error_message(Error *err);
void Error_clear(Error *err);
void Error_formatFileLine(Error *dst, const char *file, int line, sds message);
const char *Error_maxErrToString(Error_maxErrorInteger maxErr);
int Error_maypost(Error *err);
void DBLog_init(const char *tag, Error *err);
Ticks cseqHub_now();
int port_parseEvSymbol(Symbol *id);
static const char *Port_idString(Port *port);
static int Port_isVstType(Port *port);
static int Port_isNullType(Port *port);
void Port_send(Port *port, int outletIndex, short argc, Atom *argv, Error *err);
void Port_sendInteger(Port *p, int outlet, long value);
void Port_sendSelectorAndInteger(Port *port, Symbol *selector, int value);
void MarshalSi_process(MarshalSi *self, Arguments *args, long argc, Atom *argv, Error *err);
void MarshalSi_zeroArgs(MarshalSi *self, Arguments *args);
void MarshalSii_process(MarshalSii *self, Arguments *args, long argc, Atom *argv, Error *err);
void MarshalSii_zeroArgs(MarshalSi *self, Arguments *args);
void MarshalSs_process(MarshalSs *self, Arguments *args, long argc, Atom *argv, Error *err);
void MarshalSs_zeroArgs(MarshalSi *self, Arguments *args);
Marshal *Marshal_create(int itype);
void Marshal_free(Marshal *self);
Dispatch *IncrementFrameDispatch_create(int itype);
void IncrementFrameDispatch_exec(IncrementFrameDispatch *self, Hub *hub, Arguments *args, Error *err);
Dispatch *DecrementFrameDispatch_create(int itype);
void DecrementFrameDispatch_exec(DecrementFrameDispatch *self, Hub *hub, Arguments *args, Error *err);
Dispatch *SelectNextPushedPadDispatch_create(int itype);
void SelectNextPushedPadDispatch_exec(SelectNextPushedPadDispatch *self, Hub *hub, Arguments *args, Error *err);
Dispatch *MidiFileDropDispatch_create(int itype);
void MidiFileDropDispatch_exec(MidiFileDropDispatch *self, Hub *hub, Arguments *args, Error *err);
Dispatch *ManageChokeGroupsDispatch_create(int itype);
void ManageChokeGroupsDispatch_initDispatchPtAr(int itype, DispatchPtAr *disPtAr, Error *ignored);
void ManageChokeGroupsDispatch_exec(ManageChokeGroupsDispatch *self, Hub *hub, Arguments *args, Error *err);
int Dispatch_cmp(Dispatch **leftp, Dispatch **rightp);
void Dispatch_freeDefault(Dispatch *d);
void Dispatch_initDispatchPtArDefault(int itype, DispatchPtAr *disPtAr, Error *err);
void DispatchPtAr_populate(DispatchPtAr *self, Error *err);
int Midiseq_Midiseq_convertIntFileLine(const char *src, Error *err, const char *file, int line);
Midiseq *Midiseq_new();
void Midiseq_toBinFile(Midiseq *mseq, BinFile *bf, Error *err);
Midiseq *Midiseq_fromBinFile(BinFile *bf, Error *err);
void Midiseq_fromBinFileUnititialized(Midiseq *mseq, BinFile *bf, Error *err);
Midiseq *Midiseq_newNote(int pitch);
void Midiseq_init(Midiseq *mseq);
void Midiseq_clear(Midiseq *mseq);
void Midiseq_free(Midiseq *midi);
int Midiseq_len(Midiseq *mseq);
void Midiseq_push(Midiseq *mseq, MEvent cell);
MEvent *Midiseq_get(Midiseq *mseq, int index, Error *err);
void Midiseq_setMidicsvExecPath();
void Midiseq_dblog(Midiseq *mseq);
int midiseq_tokenize(FILE *fd, int *nfields, sds **fields, Error *err);
int Midiseq_assignLength(Midiseq *mseq);
int Midiseq_insertCell(Midiseq *mseq, MEvent cell, int index, Error *err);
void Midiseq_insertEndgroup(Midiseq *mseq, Error *err);
int Midiseq_start(Midiseq *mseq, Ticks startTime, Ticks currentTime, bool useMasterClock, Error *err);
void Midiseq_stop(Midiseq *mseq);
int Midiseq_nextevent(Midiseq *mseq, Ticks until, MEvent *cell, Error *err);
int Midiseq_fastfwrd(Midiseq *mseq, long t, Error *err);
Midiseq *Midiseq_fromfile(const char *fullpath, Error *err);
void PortFind_init(PortFind *pf);
long PortFind_iterator(PortFind *pf, t_object *targetBox);
int PortFind_discover(PortFind *pf, t_object *sourceMaxObject, void *hub, Error *err);
void PortFind_clear(PortFind *pf);
Port *PortFind_findByVarname(PortFind *pf, Symbol *symbol);
Port *PortFind_findByTrack(PortFind *pf, Symbol *symbol);
Port *PortFind_findById(PortFind *pf, Symbol *symbol);
int PortFind_portCount(PortFind *pf);
Port *PortFind_findByIndex(PortFind *pf, int index, Error *err);
Pad *Pad_new();
void Pad_init(Pad *pad);
void Pad_free(Pad *pad);
void Pad_clear(Pad *pad);
void Pad_setSequence(Pad *pad, Midiseq *midi);
void Pad_toBinFile(Pad *pad, BinFile *bf, Error *err);
Pad *Pad_fromBinFile(BinFile *bf, Error *err);
void Pad_fromBinFileUninitialized(Pad *pad, BinFile *bf, Error *err);
void Pad_computeChokeGroup(Pad *pad);
PadList *PadList_new(int npads);
void PadList_init(PadList *pl, int npads);
void PadList_clear(PadList *pl);
void PadList_free(PadList *pl);
void PadList_play(PadList *pl, int padIndex, Ticks startTime, Ticks currentTime, bool useMasterClock, Error *err);
void PadList_markReleasePending(PadList *pl, int padIndex, bool pending, Error *err);
Pad *PadList_pad(PadList *pl, int index, Error *err);
void PadList_assignTrack(PadList *pl, TrackList *tl);
void PadList_toBinFile(PadList *pl, BinFile *bf, Error *err);
PadList *PadList_fromBinFile(BinFile *bf, Error *err);
void PadList_fromBinFileInitialized(PadList *pl, BinFile *bf, Error *err);
TrackList *TrackList_new(PortFind *pf);
void TrackList_init(TrackList *tl, PortFind *pf);
void TrackList_clear(TrackList *tl);
void TrackList_free(TrackList *tl);
Track *TrackList_findTrackByName(TrackList *tl, Symbol *name);
int TrackList_count(TrackList *tl);
Track *TrackList_findTrackByIndex(TrackList *tl, int index, Error *err);
TrackList *TrackList_fromBinFile(BinFile *bf, Error *err);
void TrackList_toBinFile(TrackList *tl, BinFile *bf, Error *err);
DropDown *DropDown_new(const char **table, PortRef *pr);
void DropDown_init(DropDown *dd, const char **table, PortRef *pr);
void DropDown_initCGLocalGlobal(DropDown *dd, PortRef *pr);
void DropDown_initCGInstrument(DropDown *dd, PortRef *pr);
void DropDown_initCGIndex(DropDown *dd, PortRef *pr);
void DropDown_clear(DropDown *dd);
void DropDown_free(DropDown *dd);
void DropDown_updateSelected(DropDown *dd, Error *err);
void DropDown_setSelected(DropDown *dd, int selected, Error *err);
void DropDown_initializeMenu(DropDown *dd, Error *err);
int IndexedOff_cmpPadIndex(IndexedOff *left, IndexedOff *right);
int TimedOff_cmpTime(TimedOff *left, TimedOff *right);
NoteManager *NoteManager_new(Port *port);
void NoteManager_free(NoteManager *nm);
bool NoteManager_insertNoteOff(NoteManager *manager, Ticks timestamp, int pitch, int padIndexForEndgroup);
void NoteManager_sendNoteOn(NoteManager *manager, int pitch, int velocity);
void NoteManager_flushOffs(NoteManager *manager);
void NoteManager_dblogPending(NoteManager *manager, Ticks current);
Ticks NoteManager_scheduleOffs(NoteManager *manager, Ticks current);
void NoteManager_midievent(NoteManager *manager, MEvent cell, int padIndexForEndgroup);
void NoteManager_padNoteOff(NoteManager *manager, int padIndex);
Hub *Hub_new(PortFind *pf, Error *err);
void Hub_init(Hub *hub, PortFind *pf, Error *err);
void Hub_free(Hub *hub);
void Hub_updateGuiCurrentCoordinates(Hub *hub);
void Hub_changeSelectedPad(Hub *hub, int selectedPadIndex, Error *err);
void Hub_anythingDispatch(Hub *hub, Port *port, Symbol *selector, long argc, Atom *argv);
void Hub_intDispatch(Hub *hub, Port *port, long value, long inlet);
void Hub_toBinFile(Hub *hub, BinFile *bf, Error *err);
Hub *Hub_fromBinFile(BinFile *bf, Error *err);
void Hub_fromBinFileUninitialized(Hub *hub, BinFile *bf, Error *err);
BinFile *BinFile_new();
BinFile *BinFile_newWriter(const char *file, Error *err);
BinFile *BinFile_newReader(const char *file, Error *err);
void BinFile_free(BinFile *bf);
int binFile_hexDigitToInt(char hex);
char binFile_intToHexDigit(int digit);
off_t BinFile_writeNullLength(BinFile *bf, bool spaceForFlags, Error *err);
void BinFile_writeFlags(BinFile *bf, long flags, Error *err);
void BinFile_writeBackLengthFlags(BinFile *bf, off_t location, long flags, Error *err);
void BinFile_writeLengthFlags(BinFile *bf, long length, long flags, Error *err);
long BinFile_readLengthFlags(BinFile *bf, long *flags, Error *err);
off_t BinFile_tell(BinFile *bf, Error *err);
void BinFile_fillBuffer(BinFile *bf, long size, Error *err);
void BinFile_writeInteger(BinFile *bf, long value, Error *err);
long BinFile_readInteger(BinFile *bf, Error *err);
void BinFile_writeString(BinFile *bf, sds value, Error *err);
sds BinFile_readString(BinFile *bf, Error *err);
void BinFile_writeSymbol(BinFile *bf, Symbol *value, Error *err);
Symbol *BinFile_readSymbol(BinFile *bf, Error *err);
void BinFile_writeTicks(BinFile *bf, Ticks value, Error *err);
Ticks BinFile_readTicks(BinFile *bf, Error *err);
void BinFile_writeBool(BinFile *bf, bool value, Error *err);
bool BinFile_readBool(BinFile *bf, Error *err);
void BinFile_writeTag(BinFile *bf, const char *tag, Error *err);
void BinFile_verifyTag(BinFile *bf, const char *tag, Error *err);
// *** DO NOT MODIFY THIS FILE (see src/dispatch.in.h) generated 03/16/2018 14:26:58 ***
void Marshal_process(Marshal *self, Arguments *a1, long a2, Atom *a3, Error *err);
void Marshal_zeroArgs(Marshal *self, Arguments *a1, Error *err);
void Dispatch_exec(Dispatch *self, Hub *a1, Arguments *a2, Error *err);
Dispatch *Dispatch_create(int itype, Error *err);
void Dispatch_free(Dispatch *self, Error *err);
void Dispatch_initDispatchPtAr(int itype, DispatchPtAr *a1, Error *err);
// *** DO NOT MODIFY THIS FILE (see src/midiseq.in.h) generated 03/16/2018 14:26:58 ***
