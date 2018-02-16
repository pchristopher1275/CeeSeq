sds stripBaseName(const char *path);

//
// B I N    F I L E
//
typedef struct 
{
    int version;
    sds filename;
    sds buffer;
    int mostRecentFlags;
    FILE *stream;  
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

#define BinFile_mostRecentFlags(bf)     (bf)->mostRecentFlags


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
    // ** Persisted **
    MidiseqCell *data;
    bool useMasterClock;
    Ticks sequenceLength;


    // ** NOT Persisted **
    // startTime is the time offset that t = 0 that is stored in the sequence corresponds too.
    // Specifically, if useMasterClock is true, the startTime is updated whenever the ptr rolls
    // off the end of the sequence, and raps around back to the beginning.
    Ticks startTime;

    int ptr;
} Midiseq;
#define Midiseq_data(mseq)           ((mseq)->data)
#define Midiseq_useMasterClock(mseq) ((mseq)->useMasterClock)
#define Midiseq_sequenceLength(mseq) ((mseq)->sequenceLength)

int Midiseq_fastfwrd(Midiseq *midi, long t, Error *err);
void Midiseq_free(Midiseq *midi);

struct Track_t;

typedef struct
{
    t_symbol *chokeGroup;
    Midiseq *sequence;
    t_symbol *trackName;
    int padIndex;
    bool noteReleasePending;
    bool inEndgroup;
    struct Track_t *track;
} Pad;

#define Pad_chokeGroup(pad) (pad)->chokeGroup
#define Pad_trackName(pad)  (pad)->trackName
#define Pad_track(pad)      (pad)->track
#define Pad_padIndex(pad)   (pad)->padIndex
#define Pad_noteReleasePending(pad)  (pad)->noteReleasePending
#define Pad_inEndgroup(pad) (pad)->inEndgroup

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
void NoteManager_padNoteOff(NoteManager *manager, int padIndex);

typedef struct
{
    Port *reciever;
    t_symbol *varname;
} PortFindCell;

typedef struct
{
    PortFindCell *objectsFound;
    void *hub;
    Port_anythingDispatchFunc anythingDispatch;
    Port_intDispatchFunc intDispatch;
} PortFind;

#define PortFind_hub(p)              ((p)->hub)
#define PortFind_anythingDispatch(p) ((p)->anythingDispatch)
#define PortFind_intDispatch(p)      ((p)->intDispatch)

typedef struct
{
    Pad *pads;
    Pad **running;
} PadList;
int PadList_padsLength(PadList *padList);

typedef struct Track_t
{
    t_symbol *name;
    NoteManager *noteManager;
} Track;
#define Track_noteManager(t) ((t)->noteManager)
#define Track_name(t) ((t)->name)


typedef struct {} TrackList;
Track *TrackList_findTrackByName(TrackList *tl_in, t_symbol *name);
Track *TrackList_findTrackByIndex(TrackList *tl_in, int index, Error *err);

typedef struct {
    Port *currBank;
    Port *currFrame;
    Port *selBank;
    Port *selFrame;
    Port *selPad;
} Gui;
#define Gui_currBank(gui)  (gui)->currBank
#define Gui_currFrame(gui) (gui)->currFrame
#define Gui_selBank(gui)   (gui)->selBank
#define Gui_selFrame(gui)  (gui)->selFrame
#define Gui_selPad(gui)    (gui)->selPad

//
// H U B
//
typedef struct 
{
    PadList *padList;
    TrackList *trackList;

    // bank varies from 0 - infinity
    int bank;

    // frame varies from 0 - 7
    int frame;

    // true if the next padIndex tapped should be written into selectedPad
    bool grabNextTappedPad;

    // which pad has been selected
    int selectedPad;

    Gui *gui;
} Hub;

#define Hub_padList(hub)           ((hub)->padList)
#define Hub_trackList(hub)         ((hub)->trackList)
#define Hub_bank(hub)              ((hub)->bank)
#define Hub_frame(hub)             ((hub)->frame)
#define Hub_selectedPad(hub)       ((hub)->selectedPad)
#define Hub_grabNextTappedPad(hub) ((hub)->grabNextTappedPad)
#define Hub_gui(hub)               ((hub)->gui)
#define Hub_padsPerFrame           24
#define Hub_framesPerBank           8
#define Hub_padsPerBank            (Hub_padsPerFrame*Hub_framesPerBank)
#define Hub_firstMidiNote          48
#define Hub_relativeSelectedPad(hub) (Hub_selectedPad(hub) % Hub_padsPerFrame)
#define Hub_padIndexFromInNote(hub, inputNote) (Hub_bank(hub)*Hub_padsPerBank + Hub_frame(hub)*Hub_padsPerFrame + (inputNote - Hub_firstMidiNote))
void Hub_anythingDispatch(void *hub, struct Port_t *port, t_symbol *msg, long argc, t_atom *argv);
void Hub_intDispatch(void *hub, struct Port_t *port, long value, long inlet);

