// *** DO NOT MODIFY THIS FILE (see header_build.pl) ***
#define APIF /**/
sds stripBaseName(const char *path);


struct BinFilePayload_t;
typedef struct BinFilePayload_t BinFilePayload;
struct BinFile_t;
typedef struct BinFile_t BinFile;
struct MidiseqCell_t;
typedef struct MidiseqCell_t MidiseqCell;
struct Midiseq_t;
typedef struct Midiseq_t Midiseq;
struct Pad_t;
typedef struct Pad_t Pad;
struct PendingNoteOff_t;
typedef struct PendingNoteOff_t PendingNoteOff;
struct NoteManager_t;
typedef struct NoteManager_t NoteManager;
struct PortFindCell_t;
typedef struct PortFindCell_t PortFindCell;
struct PortFind_t;
typedef struct PortFind_t PortFind;
struct PadListIterator_t;
typedef struct PadListIterator_t PadListIterator;
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


// *** DO NOT MODIFY THIS FILE (see header_build.pl) ***
struct BinFilePayload_t
{
    // ** not persisted **
    PortFind *portFind;
};
#define BinFilePayload_newUninitialized() ((BinFilePayload*)sysmem_newptrclear(sizeof(BinFilePayload)))

// *** DO NOT MODIFY THIS FILE (see header_build.pl) ***
struct BinFile_t
{
    // ** not persisted **
    int version;
    sds filename;
    sds buffer;
    FILE *stream;
    BinFilePayload *payload;
};
#define BinFile_newUninitialized() ((BinFile*)sysmem_newptrclear(sizeof(BinFile)))
#define BinFile_nullLengthFieldSizeStr "11"
#define BinFile_maxLength              2147483647
#define BinFileFlag_tag                1
static inline PortFind *BinFile_portFindPayload(BinFile *self){ return (self->payload == NULL ? NULL : self->payload->portFind); }
static inline void BinFile_setPayload(BinFile *self, BinFilePayload *payload) { self->payload = payload;}
#define BinFile_writeBackLength(bf, location, err) BinFile_writeBackLengthFlags(bf, location, -1, err)
#define BinFile_readLength(bf, err) BinFile_readLengthFlags(bf, NULL, err)
#define BinFile_writeLength(bf, length, err) BinFile_writeLengthFlags(bf, length, -1, err)
static inline int BinFile_version(BinFile *self){return self->version;}
static inline void BinFile_setVersion(BinFile *self, int value){self->version = value;}
static inline sds BinFile_filename(BinFile *self){return self->filename;}
static inline void BinFile_setFilename(BinFile *self, sds value){self->filename = value;}
static inline sds BinFile_buffer(BinFile *self){return self->buffer;}
static inline void BinFile_setBuffer(BinFile *self, sds value){self->buffer = value;}
static inline FILE *BinFile_stream(BinFile *self){return self->stream;}
static inline void BinFile_setStream(BinFile *self, FILE *value){self->stream = value;}
BinFile *BinFile_new();
BinFile *BinFile_newWriter(const char *file, Error *err);
BinFile *BinFile_newReader(const char *file, Error *err);
void BinFile_free(BinFile *bf);
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
void BinFile_writeSymbol(BinFile *bf, t_symbol *value, Error *err);
t_symbol *BinFile_readSymbol(BinFile *bf, Error *err);
void BinFile_writeTicks(BinFile *bf, Ticks value, Error *err);
Ticks BinFile_readTicks(BinFile *bf, Error *err);
void BinFile_writeBool(BinFile *bf, bool value, Error *err);
bool BinFile_readBool(BinFile *bf, Error *err);
void BinFile_writeTag(BinFile *bf, const char *tag, Error *err);
void BinFile_verifyTag(BinFile *bf, const char *tag, Error *err);

// *** DO NOT MODIFY THIS FILE (see header_build.pl) ***
struct MidiseqCell_t
{
    uint8_t type;
    union
    {
        uint8_t b[2];
        uint16_t bend;
    } b;
    Ticks t;
    Ticks duration;
};
#define MidiseqCell_newUninitialized() ((MidiseqCell*)sysmem_newptrclear(sizeof(MidiseqCell)))
#define MidiseqCell_type(cell) ((cell).type)
#define MidiseqCell_t(cell) ((cell).t)
#define MidiseqCell_notePitch(cell) ((cell).b.b[0])
#define MidiseqCell_noteVelocity(cell) ((cell).b.b[1])
#define MidiseqCell_noteDuration(cell) ((cell).duration)
#define MidiseqCell_ccNumber(cell) ((cell).b.b[0])
#define MidiseqCell_ccValue(cell) ((cell).b.b[1])
#define MidiseqCell_bendValue(cell) ((cell).b.bend)

// *** DO NOT MODIFY THIS FILE (see header_build.pl) ***
struct Midiseq_t
{
    // ** PERSISTED **
    bool useMasterClock;
    Ticks sequenceLength;
    MidiseqCell *data;
    // ** not persisted **
    // startTime is the time offset that t = 0 that is stored in the sequence corresponds too.
    // Specifically, if useMasterClock is true, the startTime is updated whenever the ptr rolls
    // off the end of the sequence, and raps around back to the beginning.
    Ticks startTime;
    int ptr;
};
#define Midiseq_newUninitialized() ((Midiseq*)sysmem_newptrclear(sizeof(Midiseq)))
const int Midiseq_notetype   = 1;
const int Midiseq_bendtype   = 2;
const int Midiseq_cctype     = 3;
const int Midiseq_cycletype  = 4;
const int Midiseq_endgrptype = 5;
static inline bool Midiseq_useMasterClock(Midiseq *self){return self->useMasterClock;}
static inline void Midiseq_setUseMasterClock(Midiseq *self, bool value){self->useMasterClock = value;}
static inline Ticks Midiseq_sequenceLength(Midiseq *self){return self->sequenceLength;}
static inline void Midiseq_setSequenceLength(Midiseq *self, Ticks value){self->sequenceLength = value;}
static inline MidiseqCell *Midiseq_data(Midiseq *self){return self->data;}
static inline void Midiseq_setData(Midiseq *self, MidiseqCell *value){self->data = value;}
static inline Ticks Midiseq_startTime(Midiseq *self){return self->startTime;}
static inline void Midiseq_setStartTime(Midiseq *self, Ticks value){self->startTime = value;}
static inline int Midiseq_ptr(Midiseq *self){return self->ptr;}
static inline void Midiseq_setPtr(Midiseq *self, int value){self->ptr = value;}
Midiseq *Midiseq_new();
void Midiseq_toBinFile(Midiseq *mseq, BinFile *bf, Error *err);
Midiseq *Midiseq_fromBinFile(BinFile *bf, Error *err);
void Midiseq_fromBinFileUnititialized(Midiseq *mseq, BinFile *bf, Error *err);
Midiseq *Midiseq_newNote(int pitch);
void Midiseq_init(Midiseq *midi);
void Midiseq_clear(Midiseq *midi);
void Midiseq_free(Midiseq *midi);
int Midiseq_len(Midiseq *midi);
void Midiseq_push(Midiseq *midi, MidiseqCell cell);
MidiseqCell *Midiseq_get(Midiseq *midi, int index, Error *err);
void Midiseq_setMidicsvExecPath();
void Midiseq_dblog(Midiseq *midi);
int Midiseq_assignLength(Midiseq *midi);
int Midiseq_insertCell(Midiseq *midi, MidiseqCell cell, int index, Error *err);
int Midiseq_insertEndgroup(Midiseq *midi, Error *err);
int Midiseq_start(Midiseq *midi, Ticks startTime, Ticks currentTime, bool useMasterClock, Error *err);
void Midiseq_stop(Midiseq *midi);
int Midiseq_nextevent(Midiseq *midi, Ticks until, MidiseqCell *cell, Error *err);
int Midiseq_fastfwrd(Midiseq *midi, long t, Error *err);
Midiseq *Midiseq_fromfile(const char *fullpath, Error *err);

// *** DO NOT MODIFY THIS FILE (see header_build.pl) ***
struct Pad_t
{
    // ** PERSISTED **
    t_symbol *trackName;
    int padIndex;
    Midiseq *sequence;
    bool chokeGroupGlobal;
    int chokeGroupInstrument;
    int chokeGroupIndex;
    // ** not persisted **
    int64_t chokeGroup;
    bool noteReleasePending;
    bool inEndgroup;
    Track *track;
};
#define Pad_newUninitialized() ((Pad*)sysmem_newptrclear(sizeof(Pad)))
static inline t_symbol *Pad_trackName(Pad *self){return self->trackName;}
static inline void Pad_setTrackName(Pad *self, t_symbol *value){self->trackName = value;}
static inline int Pad_padIndex(Pad *self){return self->padIndex;}
static inline void Pad_setPadIndex(Pad *self, int value){self->padIndex = value;}
static inline Midiseq *Pad_sequence(Pad *self){return self->sequence;}
void Pad_setSequence(Pad *self, Midiseq *value);
static inline bool Pad_chokeGroupGlobal(Pad *self){return self->chokeGroupGlobal;}
static inline void Pad_setChokeGroupGlobal(Pad *self, bool value){self->chokeGroupGlobal = value;}
static inline int Pad_chokeGroupInstrument(Pad *self){return self->chokeGroupInstrument;}
static inline void Pad_setChokeGroupInstrument(Pad *self, int value){self->chokeGroupInstrument = value;}
static inline int Pad_chokeGroupIndex(Pad *self){return self->chokeGroupIndex;}
static inline void Pad_setChokeGroupIndex(Pad *self, int value){self->chokeGroupIndex = value;}
static inline int64_t Pad_chokeGroup(Pad *self){return self->chokeGroup;}
static inline void Pad_setChokeGroup(Pad *self, int64_t value){self->chokeGroup = value;}
static inline bool Pad_noteReleasePending(Pad *self){return self->noteReleasePending;}
static inline void Pad_setNoteReleasePending(Pad *self, bool value){self->noteReleasePending = value;}
static inline bool Pad_inEndgroup(Pad *self){return self->inEndgroup;}
static inline void Pad_setInEndgroup(Pad *self, bool value){self->inEndgroup = value;}
static inline Track *Pad_track(Pad *self){return self->track;}
static inline void Pad_setTrack(Pad *self, Track *value){self->track = value;}
Pad *Pad_new();
void Pad_init(Pad *pad);
void Pad_free(Pad *pad);
void Pad_clear(Pad *pad);
void Pad_toBinFile(Pad *pad, BinFile *bf, Error *err);
Pad *Pad_fromBinFile(BinFile *bf, Error *err);
void Pad_fromBinFileUninitialized(Pad *pad, BinFile *bf, Error *err);
void Pad_computeChokeGroup(Pad *pad);

// *** DO NOT MODIFY THIS FILE (see header_build.pl) ***
struct PendingNoteOff_t 
{
    struct PendingNoteOff_t *next;
    union {
        Ticks timestamp;
        int padIndex;
    } ticksOrPadIndex;
    int pitch;
};
#define PendingNoteOff_newUninitialized() ((PendingNoteOff*)sysmem_newptrclear(sizeof(PendingNoteOff)))
#define PendingNoteOff_next(pno)      (pno)->next
#define PendingNoteOff_timestamp(pno) (pno)->ticksOrPadIndex.timestamp
#define PendingNoteOff_padIndex(pno)  (pno)->ticksOrPadIndex.padIndex 
#define PendingNoteOff_pitch(pno)     (pno)->pitch
#define PendingNoteOff_increment(pno) do { \
    if (pno) { \
        (pno) = PendingNoteOff_next(pno); \
    } \
} while (0)
PendingNoteOff *PendingNoteOff_new();
void PendingNoteOff_free(PendingNoteOff *node);
bool PendingNoteOff_removePitch(PendingNoteOff **head, int pitch);
void PendingNoteOff_removePadIndexed(PendingNoteOff **head, int padIndex, int **pitchesRemoved);
void PendingNoteOff_insertTimestamped(PendingNoteOff **head, int pitch, Ticks timestamp);
void PendingNoteOff_insertPadIndexed(PendingNoteOff **head, int pitch, int padIndex);
void PendingNoteOff_pop(PendingNoteOff **head);
void PendingNoteOff_freeAll(PendingNoteOff *start);

// *** DO NOT MODIFY THIS FILE (see header_build.pl) ***
struct NoteManager_t
{
    // ** not persisted **
    PendingNoteOff *pending;
    PendingNoteOff *endgroups;
    Port *output;
    t_atom *atoms;
    int *removedPitches;
};
#define NoteManager_newUninitialized() ((NoteManager*)sysmem_newptrclear(sizeof(NoteManager)))
static inline PendingNoteOff *NoteManager_pending(NoteManager *self){return self->pending;}
static inline void NoteManager_setPending(NoteManager *self, PendingNoteOff *value){self->pending = value;}
static inline PendingNoteOff *NoteManager_endgroups(NoteManager *self){return self->endgroups;}
static inline void NoteManager_setEndgroups(NoteManager *self, PendingNoteOff *value){self->endgroups = value;}
static inline Port *NoteManager_output(NoteManager *self){return self->output;}
static inline void NoteManager_setOutput(NoteManager *self, Port *value){self->output = value;}
static inline t_atom *NoteManager_atoms(NoteManager *self){return self->atoms;}
static inline void NoteManager_setAtoms(NoteManager *self, t_atom *value){self->atoms = value;}
static inline int *NoteManager_removedPitches(NoteManager *self){return self->removedPitches;}
static inline void NoteManager_setRemovedPitches(NoteManager *self, int *value){self->removedPitches = value;}
NoteManager *NoteManager_new(Port *port);
void NoteManager_free(NoteManager *nm);
bool NoteManager_insertNoteOff(NoteManager *manager, Ticks timestamp, int pitch, int padIndexForEndgroup);
void NoteManager_sendNoteOn(NoteManager *manager, int pitch, int velocity);
void NoteManager_flushOffs(NoteManager *manager);
void NoteManager_dblogPending(NoteManager *manager, Ticks current);
Ticks NoteManager_scheduleOffs(NoteManager *manager, Ticks current);
void NoteManager_midievent(NoteManager *manager, MidiseqCell cell, int padIndexForEndgroup);
void NoteManager_padNoteOff(NoteManager *manager, int padIndex);

// *** DO NOT MODIFY THIS FILE (see header_build.pl) ***
struct PortFindCell_t
{
    // ** not persisted **
    Port *reciever;
    t_symbol *varname;
};
#define PortFindCell_newUninitialized() ((PortFindCell*)sysmem_newptrclear(sizeof(PortFindCell)))
static inline Port *PortFindCell_reciever(PortFindCell *self){return self->reciever;}
static inline void PortFindCell_setReciever(PortFindCell *self, Port *value){self->reciever = value;}
static inline t_symbol *PortFindCell_varname(PortFindCell *self){return self->varname;}
static inline void PortFindCell_setVarname(PortFindCell *self, t_symbol *value){self->varname = value;}

// *** DO NOT MODIFY THIS FILE (see header_build.pl) ***
struct PortFind_t
{
    // ** not persisted **
    PortFindCell *objectsFound;
    void *hub;
    Port_anythingDispatchFunc anythingDispatch;
    Port_intDispatchFunc intDispatch;
};
#define PortFind_newUninitialized() ((PortFind*)sysmem_newptrclear(sizeof(PortFind)))
static inline PortFindCell *PortFind_objectsFound(PortFind *self){return self->objectsFound;}
static inline void PortFind_setObjectsFound(PortFind *self, PortFindCell *value){self->objectsFound = value;}
static inline void *PortFind_hub(PortFind *self){return self->hub;}
static inline void PortFind_setHub(PortFind *self, void *value){self->hub = value;}
static inline Port_anythingDispatchFunc PortFind_anythingDispatch(PortFind *self){return self->anythingDispatch;}
static inline void PortFind_setAnythingDispatch(PortFind *self, Port_anythingDispatchFunc value){self->anythingDispatch = value;}
static inline Port_intDispatchFunc PortFind_intDispatch(PortFind *self){return self->intDispatch;}
static inline void PortFind_setIntDispatch(PortFind *self, Port_intDispatchFunc value){self->intDispatch = value;}
#define PortFind_declare(name) PortFind _##name = {0}; PortFind *name = &_##name			
long PortFind_iterator(PortFind *pf, t_object *targetBox);
int PortFind_discover(PortFind *pf, t_object *sourceMaxObject, void *hub, Error *err);
void PortFind_clear(PortFind *pf);
Port *PortFind_findByVarname(PortFind *pf, t_symbol *symbol);
Port *PortFind_findByTrack(PortFind *pf, t_symbol *symbol);
Port *PortFind_findById(PortFind *pf, t_symbol *symbol);
int PortFind_portCount(PortFind *pf);
Port *PortFind_findByIndex(PortFind *pf, int index, Error *err);

// *** DO NOT MODIFY THIS FILE (see header_build.pl) ***
struct PadListIterator_t
{
    int index;
};
#define PadListIterator_newUninitialized() ((PadListIterator*)sysmem_newptrclear(sizeof(PadListIterator)))
#define PadListIterator_declare(name) PadListIterator _##name = {-1}; PadListIterator *name = &_##name
static inline int PadListIterator_index(PadListIterator *self){return self->index;}
static inline void PadListIterator_setIndex(PadListIterator *self, int value){self->index = value;}

// *** DO NOT MODIFY THIS FILE (see header_build.pl) ***
struct PadList_t
{
    Pad *pads;
    Pad **running;
};
#define PadList_newUninitialized() ((PadList*)sysmem_newptrclear(sizeof(PadList)))
#define PadListIterator_declare(name) PadListIterator _##name = {-1}; PadListIterator *name = &_##name
static inline Pad *PadList_pads(PadList *self){return self->pads;}
static inline void PadList_setPads(PadList *self, Pad *value){self->pads = value;}
static inline Pad **PadList_running(PadList *self){return self->running;}
static inline void PadList_setRunning(PadList *self, Pad **value){self->running = value;}
PadList *PadList_new(int npads);
void PadList_free(PadList *llst);
int PadList_play(PadList *llst, int padIndex, Ticks startTime, Ticks currentTime, bool useMasterClock, Error *err);
void PadList_markReleasePending(PadList *llst, int padIndex, bool pending, Error *err);
int PadList_runningLength(PadList *llst);
bool PadList_iterateRunning(PadList *llst, PadListIterator *iterator, Pad **pad);
void PadList_clearRunning(PadList *llst, PadListIterator *iterator);
int PadList_padsLength(PadList *llst);
Pad *PadList_pad(PadList *llst, int index, Error *err);
void PadList_assignTrack(PadList *llst, TrackList *tl);
void PadList_toBinFile(PadList *llst, BinFile *bf, Error *err);
PadList *PadList_fromBinFile(BinFile *bf, Error *err);
void PadList_fromBinFileUninitialized(PadList *llst, BinFile *bf, Error *err);

// *** DO NOT MODIFY THIS FILE (see header_build.pl) ***
struct Track_t
{
    t_symbol *name;
    NoteManager *noteManager;
};
#define Track_newUninitialized() ((Track*)sysmem_newptrclear(sizeof(Track)))
static inline t_symbol *Track_name(Track *self){return self->name;}
static inline void Track_setName(Track *self, t_symbol *value){self->name = value;}
static inline NoteManager *Track_noteManager(Track *self){return self->noteManager;}
static inline void Track_setNoteManager(Track *self, NoteManager *value){self->noteManager = value;}

// *** DO NOT MODIFY THIS FILE (see header_build.pl) ***
struct TrackList_t
{
};
TrackList *TrackList_new(PortFind *pf);
void TrackList_free(TrackList *tl_in);
Track *TrackList_findTrackByName(TrackList *tl_in, t_symbol *name);
int TrackList_count(TrackList *tl_in);
Track *TrackList_findTrackByIndex(TrackList *tl_in, int index, Error *err);
TrackList *TrackList_fromBinFile(BinFile *bf, Error *err);
void TrackList_toBinFile(TrackList *tl, BinFile *bf, Error *err);

// *** DO NOT MODIFY THIS FILE (see header_build.pl) ***
struct PortRef_t
{
    Port *port;
    int outlet;
};
static inline Port *PortRef_port(PortRef *self){return self->port;}
static inline void PortRef_setPort(PortRef *self, Port *value){self->port = value;}
static inline int PortRef_outlet(PortRef *self){return self->outlet;}
static inline void PortRef_setOutlet(PortRef *self, int value){self->outlet = value;}
#define PortRef_noNew 1
#define PortRef_noInit 1
#define PortRef_noFree 1
#define PortRef_declare(name, port, outlet)    PortRef _##name = {port, outlet}; PortRef *name = &_##name
static inline void PortRef_set(PortRef *pr, Port *port, int outlet) {
	pr->port   = port;
	pr->outlet = outlet;
}
//#define PortRef_value(pr)                      (*pr)
//#define PortRef_clear(pr)                      /**/
#define PortRef_send(pr, argc, argv, err)      Port_send(PortRef_port(pr), PortRef_outlet(pr), argc, argv, err)
#define PortRef_sendInteger(pr, value, err)    Port_sendInteger(PortRef_port(pr), PortRef_outlet(pr), value, err)

// *** DO NOT MODIFY THIS FILE (see header_build.pl) ***
struct DropDown_t
{
    t_symbol **table;
    int selected;
    PortRef portRef;
};
#define DropDown_newUninitialized() ((DropDown*)sysmem_newptrclear(sizeof(DropDown)))
static inline t_symbol **DropDown_table(DropDown *self){return self->table;}
static inline void DropDown_setTable(DropDown *self, t_symbol **value){self->table = value;}
static inline int DropDown_selected(DropDown *self){return self->selected;}
static inline PortRef *DropDown_portRef(DropDown *dd) {
    return &dd->portRef;
}
static inline void DropDown_setPortRef(DropDown *dd, PortRef *pr) {
	dd->portRef = *pr;
}
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

// *** DO NOT MODIFY THIS FILE (see header_build.pl) ***
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
    // bank varies from 0-infinity
    int bank;
    // frame varies from 0-7
    int frame;
    // true if the next padIndex tapped should be written into selectedPad
    bool grabNextTappedPad;
    // which pad has been selected
    int selectedPad;
};
#define Hub_newUninitialized() ((Hub*)sysmem_newptrclear(sizeof(Hub)))
static inline PadList *Hub_padList(Hub *self){return self->padList;}
static inline void Hub_setPadList(Hub *self, PadList *value){self->padList = value;}
static inline TrackList *Hub_trackList(Hub *self){return self->trackList;}
static inline void Hub_setTrackList(Hub *self, TrackList *value){self->trackList = value;}
static inline Port *Hub_currBankPort(Hub *self){return self->currBankPort;}
static inline void Hub_setCurrBankPort(Hub *self, Port *value){self->currBankPort = value;}
static inline Port *Hub_currFramePort(Hub *self){return self->currFramePort;}
static inline void Hub_setCurrFramePort(Hub *self, Port *value){self->currFramePort = value;}
static inline Port *Hub_selBankPort(Hub *self){return self->selBankPort;}
static inline void Hub_setSelBankPort(Hub *self, Port *value){self->selBankPort = value;}
static inline Port *Hub_selFramePort(Hub *self){return self->selFramePort;}
static inline void Hub_setSelFramePort(Hub *self, Port *value){self->selFramePort = value;}
static inline Port *Hub_selPadPort(Hub *self){return self->selPadPort;}
static inline void Hub_setSelPadPort(Hub *self, Port *value){self->selPadPort = value;}
static inline Port *Hub_chokeGroupPort(Hub *self){return self->chokeGroupPort;}
static inline void Hub_setChokeGroupPort(Hub *self, Port *value){self->chokeGroupPort = value;}
static inline DropDown *Hub_cgLocalGlobalMenu(Hub *self){return &self->cgLocalGlobalMenu;}
static inline DropDown *Hub_cgInstrumentMenu(Hub *self){return &self->cgInstrumentMenu;}
static inline DropDown *Hub_cgIndexMenu(Hub *self){return &self->cgIndexMenu;}
static inline int Hub_bank(Hub *self){return self->bank;}
static inline void Hub_setBank(Hub *self, int value){self->bank = value;}
static inline int Hub_frame(Hub *self){return self->frame;}
static inline void Hub_setFrame(Hub *self, int value){self->frame = value;}
static inline bool Hub_grabNextTappedPad(Hub *self){return self->grabNextTappedPad;}
static inline void Hub_setGrabNextTappedPad(Hub *self, bool value){self->grabNextTappedPad = value;}
static inline int Hub_selectedPad(Hub *self){return self->selectedPad;}
static inline void Hub_setSelectedPad(Hub *self, int value){self->selectedPad = value;}
#define Hub_padsPerFrame           24
#define Hub_framesPerBank           8
#define Hub_padsPerBank            (Hub_padsPerFrame*Hub_framesPerBank)
#define Hub_firstMidiNote          48

#define hub_padIndexToBank(index)         (index / Hub_padsPerBank)
#define hub_padIndexToFrame(index)        (index / Hub_framesPerBank)
#define hub_padIndexToRelativePad(index)  (index % Hub_padsPerFrame)

#define Hub_selectedBank(hub)        hub_padIndexToBank(Hub_selectedPad(hub))
#define Hub_selectedFrame(hub)       hub_padIndexToFrame(Hub_selectedPad(hub))
#define Hub_relativeSelectedPad(hub) hub_padIndexToRelativePad(Hub_selectedPad(hub))

#define Hub_padIndexFromInNote(hub, inputNote) (Hub_bank(hub)*Hub_padsPerBank + Hub_frame(hub)*Hub_padsPerFrame + (inputNote - Hub_firstMidiNote))
Hub *Hub_new(PortFind *pf, Error *err);
void Hub_init(Hub *hub, PortFind *pf, Error *err);
void Hub_free(Hub *hub);
void Hub_incrementFrame(Hub *hub);
void Hub_decrementFrame(Hub *hub);
void Hub_selectNextPushedPad(Hub *hub);
void Hub_updateGuiCurrentCoordinates(Hub *hub);
void Hub_midiFileDrop(Hub *hub, t_atom *pathAtom);
void Hub_manageChokeGroups(Hub *hub, long value, long inlet, Error *err);
void Hub_changeSelectedPad(Hub *hub, int selectedPadIndex, Error *err);
void Hub_anythingDispatch(void *hub_in, Port *port, t_symbol *msg, long argc, t_atom *argv);
void Hub_intDispatch(void *hub_in, Port *port, long value, long inlet);
void Hub_toBinFile(Hub *hub, BinFile *bf, Error *err);
Hub *Hub_fromBinFile(BinFile *bf, Error *err);
void Hub_fromBinFileUninitialized(Hub *hub, BinFile *bf, Error *err);

