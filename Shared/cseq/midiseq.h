sds stripBaseName(const char *path);
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef struct
{
    uint8 type;
    union
    {
        uint8 b[2];
        uint16 bend;
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
    MidiseqCell *data;                            // This is an stretchy_buffer
    int ptr;
    bool useMasterClock;

    Ticks sequenceLength;

    // startTime is the time offset that t = 0 that is stored in the sequence corresponds too.
    // Specifically, if useMasterClock is true, the startTime is updated whenever the ptr rolls
    // off the end of the sequence, and raps around back to the beginning.
    Ticks startTime;
} Midiseq;

int Midiseq_fastfwrd(Midiseq *midi, long t, Error *err);

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

} Gui;


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
#define Hub_firstMidiNote          48
#define Hub_padIndexFromInNote(hub, inputNote) (Hub_bank(hub)*8*Hub_padsPerFrame + Hub_frame(hub)*Hub_padsPerFrame + (inputNote - Hub_firstMidiNote))
void Hub_anythingDispatch(void *hub, struct Port_t *port, t_symbol *msg, long argc, t_atom *argv);
void Hub_intDispatch(void *hub, struct Port_t *port, long value, long inlet);

