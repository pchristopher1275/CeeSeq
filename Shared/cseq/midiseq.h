#define APIF /**/
sds stripBaseName(const char *path);

//
// B I N    F I L E
//
struct PortFind_t;
typedef struct 
{
    struct PortFind_t *portFind;
} BinFilePayload;

typedef struct 
{
    int version;
    sds filename;
    sds buffer;
    FILE *stream;  
    BinFilePayload *payload;
} BinFile;

// #define BinFile_lengthFieldSize         11

// This is the most positive integer in a 4 byte int. NOTE the number of digits in this number should be one-less
// than BinFile_lengthFieldSizeStr
#define BinFile_nullLengthFieldSizeStr "11"
#define BinFile_maxLength      2147483647
#define BinFile_version(bf)    (bf)->version
#define BinFile_filename(bf)   (bf)->filename
#define BinFile_stream(bf)     (bf)->stream
#define BinFile_buffer(bf)     (bf)->buffer
#define BinFileFlag_tag        1

#define BinFile_portFindPayload(bf) ((bf)->payload == NULL ? NULL : (bf)->payload->portFind)



#define BinFile_writeBackLength(bf, location, err) BinFile_writeBackLengthFlags(bf, location, -1, err)
#define BinFile_readLength(bf, err) BinFile_readLengthFlags(bf, NULL, err)
#define BinFile_writeLength(bf, length, err) BinFile_writeLengthFlags(bf, length, -1, err)

BinFile *BinFile_new();
BinFile *BinFile_newWriter(const char *file, Error *err);
BinFile *BinFile_newReader(const char *file, Error *err);
void BinFile_free(BinFile *bf);
off_t BinFile_writeNullLength(BinFile *bf, bool spaceForFlags, Error *err);
void BinFile_writeBackLengthFlags(BinFile *bf, off_t location, long flags, Error *err);
off_t BinFile_tell(BinFile *bf, Error *err);
long BinFile_readLengthFlags(BinFile *bf, long *flags, Error *err);
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

//
// M I D I S E Q
//
typedef struct
{
    uint8_t type;
    union
    {
        uint8_t b[2];
        uint16_t bend;
    } b;
    Ticks t;
    Ticks duration;
} MidiseqCell;

const int Midiseq_notetype   = 1;
const int Midiseq_bendtype   = 2;
const int Midiseq_cctype     = 3;
const int Midiseq_cycletype  = 4;
const int Midiseq_endgrptype = 5;

#define MidiseqCell_type(cell) ((cell).type)
#define MidiseqCell_t(cell) ((cell).t)
#define MidiseqCell_notePitch(cell) ((cell).b.b[0])
#define MidiseqCell_noteVelocity(cell) ((cell).b.b[1])
#define MidiseqCell_noteDuration(cell) ((cell).duration)
#define MidiseqCell_ccNumber(cell) ((cell).b.b[0])
#define MidiseqCell_ccValue(cell) ((cell).b.b[1])
#define MidiseqCell_bendValue(cell) ((cell).b.bend)


typedef struct
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
} Midiseq;

#define Midiseq_data(mseq)           ((mseq)->data)
#define Midiseq_useMasterClock(mseq) ((mseq)->useMasterClock)
#define Midiseq_sequenceLength(mseq) ((mseq)->sequenceLength)

#define Midiseq_newUninitialized() ((Midiseq*)sysmem_newptrclear(sizeof(Midiseq)))
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

struct Track_t;
typedef struct
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
    struct Track_t *track;
} Pad;

#define Pad_chokeGroup(pad)           (pad)->chokeGroup
#define Pad_chokeGroupGlobal(pad)     (pad)->chokeGroupGlobal
#define Pad_chokeGroupInstrument(pad) (pad)->chokeGroupInstrument
#define Pad_chokeGroupIndex(pad)      (pad)->chokeGroupIndex
static inline Midiseq *Pad_sequence(Pad *pad) {return pad->sequence;}
void Pad_setSequence(Pad *pad, Midiseq *midi);
#define Pad_trackName(pad)  (pad)->trackName
#define Pad_track(pad)      (pad)->track
#define Pad_padIndex(pad)   (pad)->padIndex
#define Pad_noteReleasePending(pad)  (pad)->noteReleasePending
#define Pad_inEndgroup(pad) (pad)->inEndgroup

#define Pad_newUninitialized() ((Pad*)sysmem_newptrclear(sizeof(Pad)))
Pad *Pad_new();
void Pad_init(Pad *pad);
void Pad_free(Pad *pad);
void Pad_clear(Pad *pad);
void Pad_setSequence(Pad *pad, Midiseq *midi);
void Pad_toBinFile(Pad *pad, BinFile *bf, Error *err);
Pad *Pad_fromBinFile(BinFile *bf, Error *err);
void Pad_fromBinFileUninitialized(Pad *pad, BinFile *bf, Error *err);
void Pad_computeChokeGroup(Pad *pad);

typedef struct PendingNoteOff_t 
{
    struct PendingNoteOff_t *next;
    union {
        Ticks timestamp;
        int padIndex;
    } ticksOrPadIndex;
    int pitch;
} PendingNoteOff;

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

typedef struct NoteManager_t
{
    PendingNoteOff *pending;
    PendingNoteOff *endgroups;
    Port *output;
    t_atom *atoms;
    int *removedPitches;
} NoteManager;

#define NoteManager_pending(noteManager) (noteManager)->pending
#define NoteManager_endgroups(noteManager) (noteManager)->endgroups

NoteManager *NoteManager_new(Port *port);
void NoteManager_free(NoteManager *nm);
bool NoteManager_insertNoteOff(NoteManager *manager, Ticks timestamp, int pitch, int padIndexForEndgroup);
void NoteManager_sendNoteOn(NoteManager *manager, int pitch, int velocity);
void NoteManager_flushOffs(NoteManager *manager);
void NoteManager_dblogPending(NoteManager *manager, Ticks current);
Ticks NoteManager_scheduleOffs(NoteManager *manager, Ticks current);
void NoteManager_midievent(NoteManager *manager, MidiseqCell cell, int padIndexForEndgroup);
void NoteManager_padNoteOff(NoteManager *manager, int padIndex);


typedef struct
{
    Port *reciever;
    t_symbol *varname;
} PortFindCell;

typedef struct PortFind_t
{
    PortFindCell *objectsFound;
    void *hub;
    Port_anythingDispatchFunc anythingDispatch;
    Port_intDispatchFunc intDispatch;
} PortFind;

#define PortFind_hub(p)              ((p)->hub)
#define PortFind_anythingDispatch(p) ((p)->anythingDispatch)
#define PortFind_intDispatch(p)      ((p)->intDispatch)

long PortFind_iterator(PortFind *pf, t_object *targetBox);
int PortFind_discover(PortFind *pf, t_object *sourceMaxObject, void *hub, Error *err);
#define PortFind_declare(name) PortFind _##name = {0}; PortFind *name = &_##name
void PortFind_clear(PortFind *pf);
Port *PortFind_findByVarname(PortFind *pf, t_symbol *symbol);
Port *PortFind_findByTrack(PortFind *pf, t_symbol *symbol);
Port *PortFind_findById(PortFind *pf, t_symbol *symbol);
int PortFind_portCount(PortFind *pf);
Port *PortFind_findByIndex(PortFind *pf, int index, Error *err);


typedef struct {int index;} PadListIterator;
#define PadListIterator_declare(name) PadListIterator _##name = {-1}; PadListIterator *name = &_##name

typedef struct
{
    Pad *pads;
    Pad **running;
} PadList;

#define PadList_pads(plst)    ((plst)->pads)
#define PadList_running(plst) ((plst)->running)

#define PadList_newUninitialized() (PadList*)sysmem_newptrclear(sizeof(PadList))
PadList *PadList_new(int npads);
void PadList_free(PadList *llst);
int PadList_play(PadList *llst, int padIndex, Ticks startTime, Ticks currentTime, bool useMasterClock, Error *err);
void PadList_markReleasePending(PadList *llst, int padIndex, bool pending, Error *err);
int PadList_runningLength(PadList *llst);
bool PadList_iterateRunning(PadList *llst, PadListIterator *iterator, Pad **pad);
void PadList_clearRunning(PadList *llst, PadListIterator *iterator);
int PadList_padsLength(PadList *llst);
Pad *PadList_pad(PadList *llst, int index, Error *err);
struct TrackList_t;
void PadList_assignTrack(PadList *llst, struct TrackList_t *tl);
void PadList_toBinFile(PadList *llst, BinFile *bf, Error *err);
PadList *PadList_fromBinFile(BinFile *bf, Error *err);
void PadList_fromBinFileUninitialized(PadList *llst, BinFile *bf, Error *err);


typedef struct Track_t
{
    t_symbol *name;
    NoteManager *noteManager;
} Track;
#define Track_noteManager(t) ((t)->noteManager)
#define Track_name(t) ((t)->name)

typedef struct TrackList_t {} TrackList;

Track *TrackList_findTrackByName(TrackList *tl_in, t_symbol *name);
Track *TrackList_findTrackByIndex(TrackList *tl_in, int index, Error *err);
TrackList *TrackList_new(PortFind *pf);
void TrackList_free(TrackList *tl_in);
Track *TrackList_findTrackByName(TrackList *tl_in, t_symbol *name);
int TrackList_count(TrackList *tl_in);
Track *TrackList_findTrackByIndex(TrackList *tl_in, int index, Error *err);
TrackList *TrackList_fromBinFile(BinFile *bf, Error *err);
void TrackList_toBinFile(TrackList *tl, BinFile *bf, Error *err);

//
// P O R T   R E F
//
typedef struct PortRef_t 
{
    Port *port;
    int outlet;
} PortRef;

#define PortRef_port(pr)   (pr)->port
#define PortRef_outlet(pr) (pr)->outlet

#define PortRef_noNew 1
#define PortRef_noInit 1
#define PortRef_noFree 1

#define PortRef_declare(name, port, outlet)    PortRef _##name = {port, outlet}; PortRef *name = &_##name
#define PortRef_set(pr, portIn, outletIn) (pr)->port = (portIn); (pr)->outlet = (outletIn)
#define PortRef_value(pr)                      (*pr)
#define PortRef_clear(pr)                      /**/
#define PortRef_send(pr, argc, argv, err)      Port_send(PortRef_port(pr), PortRef_outlet(pr), argc, argv, err)
#define PortRef_sendInteger(pr, value, err)    Port_sendInteger(PortRef_port(pr), PortRef_outlet(pr), value, err)

//
// D R O P   D O W N
//

typedef struct DropDown_t
{
    t_symbol **table;
    int selected;
    PortRef portRef;
} DropDown;

static inline PortRef *DropDown_portRef(DropDown *dd) {
    return &dd->portRef;
}

#define DropDown_setPortRef(dd, pr) (dd)->portRef = *pr
#define DropDown_table(dd)          (dd)->table

static inline int DropDown_selected(DropDown *dd) {
    return dd->selected;
}

void DropDown_setSelected(DropDown *dd, int selected, Error *err);
DropDown *DropDown_new(const char **table, PortRef *pr);
void DropDown_init(DropDown *dd, const char **table, PortRef *pr);
void DropDown_clear(DropDown *dd);
void DropDown_free(DropDown *dd);
void DropDown_updateSelected(DropDown *dd, Error *err);
void DropDown_initializeMenu(DropDown *dd, Error *err);
void DropDown_initCGLocalGlobal(DropDown *dd, PortRef *pr);
void DropDown_initCGInstrument(DropDown *dd, PortRef *pr);
void DropDown_initCGIndex(DropDown *dd, PortRef *pr);

//
// H U B
//
typedef struct 
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


    // bank varies from 0 - infinity
    int bank;

    // frame varies from 0 - 7
    int frame;

    // true if the next padIndex tapped should be written into selectedPad
    bool grabNextTappedPad;

    // which pad has been selected
    int selectedPad;

    
} Hub;

#define Hub_padList(hub)           ((hub)->padList)
#define Hub_trackList(hub)         ((hub)->trackList)
#define Hub_bank(hub)              ((hub)->bank)
#define Hub_frame(hub)             ((hub)->frame)
#define Hub_selectedPad(hub)       ((hub)->selectedPad)
#define Hub_grabNextTappedPad(hub) ((hub)->grabNextTappedPad)
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
#define Hub_currBankPort(hub)  (hub)->currBankPort
#define Hub_currFramePort(hub) (hub)->currFramePort
#define Hub_selBankPort(hub)   (hub)->selBankPort
#define Hub_selFramePort(hub)  (hub)->selFramePort
#define Hub_selPadPort(hub)    (hub)->selPadPort

#define Hub_cgLocalGlobalMenu(hub) &((hub)->cgLocalGlobalMenu)
#define Hub_cgInstrumentMenu(hub)  &((hub)->cgInstrumentMenu)
#define Hub_cgIndexMenu(hub)       &((hub)->cgIndexMenu)

Hub *Hub_new(PortFind *pf, Error *err);
void Hub_init(Hub *hub, PortFind *pf, Error *err);
void Hub_free(Hub *hub);
void Hub_incrementFrame(Hub *hub);
void Hub_decrementFrame(Hub *hub);
void Hub_selectNextPushedPad(Hub *hub);
void Hub_anythingDispatch(void *hub_in, struct Port_t *port, t_symbol *msg, long argc, t_atom *argv);
void Hub_intDispatch(void *hub, struct Port_t *port, long value, long inlet);
void Hub_toBinFile(Hub *hub, BinFile *bf, Error *err);
Hub *Hub_fromBinFile(BinFile *bf, Error *err);
void Hub_fromBinFileUninitialized(Hub *hub, BinFile *bf, Error *err);
void Hub_updateGuiCurrentCoordinates(Hub *hub);

