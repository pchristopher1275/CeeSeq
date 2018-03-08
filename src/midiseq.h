// *** DO NOT MODIFY THIS FILE (see src/midiseq.in.h) ***
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

#define APIF /**/
sds stripBaseName(const char *path);

// *** DO NOT MODIFY THIS FILE (see src/midiseq.in.h) ***
struct BinFilePayload_t
{
    // ** not persisted **
    PortFind *portFind;
};
#define BinFilePayload_newUninitialized() ((BinFilePayload*)sysmem_newptrclear(sizeof(BinFilePayload)))



#define BinFile_nullLengthFieldSizeStr "11"
#define BinFile_maxLength              2147483647
#define BinFileFlag_tag                1
#define BinFile_writeBackLength(bf, location, err) BinFile_writeBackLengthFlags(bf, location, -1, err)
#define BinFile_readLength(bf, err) BinFile_readLengthFlags(bf, NULL, err)
#define BinFile_writeLength(bf, length, err) BinFile_writeLengthFlags(bf, length, -1, err)

// *** DO NOT MODIFY THIS FILE (see src/midiseq.in.h) ***
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
void BinFile_writeSymbol(BinFile *bf, Symbol *value, Error *err);
Symbol *BinFile_readSymbol(BinFile *bf, Error *err);
void BinFile_writeTicks(BinFile *bf, Ticks value, Error *err);
Ticks BinFile_readTicks(BinFile *bf, Error *err);
void BinFile_writeBool(BinFile *bf, bool value, Error *err);
bool BinFile_readBool(BinFile *bf, Error *err);
void BinFile_writeTag(BinFile *bf, const char *tag, Error *err);
void BinFile_verifyTag(BinFile *bf, const char *tag, Error *err);



static inline PortFind *BinFile_portFindPayload(BinFile *self){ return (self->payload == NULL ? NULL : self->payload->portFind); }
static inline void BinFile_setPayload(BinFile *self, BinFilePayload *payload) { self->payload = payload;}

typedef struct MEvent_t
{
    uint8_t type;
    union
    {
        uint8_t b[2];
        uint16_t bend;
    } b;
    Ticks t;
    Ticks duration;
} MEvent;

#define MEvent_newUninitialized() ((MEvent*)sysmem_newptrclear(sizeof(MEvent)))
#define MEvent_type(cell) ((cell).type)
#define MEvent_t(cell) ((cell).t)
#define MEvent_notePitch(cell) ((cell).b.b[0])
#define MEvent_noteVelocity(cell) ((cell).b.b[1])
#define MEvent_noteDuration(cell) ((cell).duration)
#define MEvent_ccNumber(cell) ((cell).b.b[0])
#define MEvent_ccValue(cell) ((cell).b.b[1])
#define MEvent_bendValue(cell) ((cell).b.bend)
#include "mEventAr.h"

const int Midiseq_notetype   = 1;
const int Midiseq_bendtype   = 2;
const int Midiseq_cctype     = 3;
const int Midiseq_cycletype  = 4;
const int Midiseq_endgrptype = 5;

// *** DO NOT MODIFY THIS FILE (see src/midiseq.in.h) ***
struct Midiseq_t
{
    // ** PERSISTED **
    bool useMasterClock;
    Ticks sequenceLength;
    MEventAr events;
    // ** not persisted **
    // startTime is the time offset that t = 0 that is stored in the sequence corresponds too.
    // Specifically, if useMasterClock is true, the startTime is updated whenever the ptr rolls
    // off the end of the sequence, and raps around back to the beginning.
    Ticks startTime;
    int ptr;
};
#define Midiseq_newUninitialized() ((Midiseq*)sysmem_newptrclear(sizeof(Midiseq)))
static inline bool Midiseq_useMasterClock(Midiseq *self){return self->useMasterClock;}
static inline void Midiseq_setUseMasterClock(Midiseq *self, bool value){self->useMasterClock = value;}
static inline Ticks Midiseq_sequenceLength(Midiseq *self){return self->sequenceLength;}
static inline void Midiseq_setSequenceLength(Midiseq *self, Ticks value){self->sequenceLength = value;}
static inline MEventAr Midiseq_events(Midiseq *self){return self->events;}
static inline void Midiseq_setEvents(Midiseq *self, MEventAr value){self->events = value;}
static inline Ticks Midiseq_startTime(Midiseq *self){return self->startTime;}
static inline void Midiseq_setStartTime(Midiseq *self, Ticks value){self->startTime = value;}
static inline int Midiseq_ptr(Midiseq *self){return self->ptr;}
static inline void Midiseq_setPtr(Midiseq *self, int value){self->ptr = value;}
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
int Midiseq_assignLength(Midiseq *mseq);
int Midiseq_insertCell(Midiseq *mseq, MEvent cell, int index, Error *err);
void Midiseq_insertEndgroup(Midiseq *mseq, Error *err);
int Midiseq_start(Midiseq *mseq, Ticks startTime, Ticks currentTime, bool useMasterClock, Error *err);
void Midiseq_stop(Midiseq *mseq);
int Midiseq_nextevent(Midiseq *mseq, Ticks until, MEvent *cell, Error *err);
int Midiseq_fastfwrd(Midiseq *mseq, long t, Error *err);
Midiseq *Midiseq_fromfile(const char *fullpath, Error *err);



// @type
//    {  
//       "typeName":"NoteEvent",
//       "fields":[  
//          {  
//             "name":"type",
//             "type":"uint8_t"
//          },
//          {  
//             "name":"pitch",
//             "type":"uint8_t"
//          },
//          {  
//             "name":"velocity",
//             "type":"uint8_t"
//          },
//          {  
//             "name":"t",
//             "type":"Ticks"
//          },
//          {  
//             "name":"duration",
//             "type":"Ticks"
//          },
//       ],
//       "containers": [
//          {"type": "array", "typename": "NoteEventAr", "elemname": "NoteEvent"}
//       ]      
//    }
// @end

// @type
//    {  
//       "typeName":"NoteSequence",
//       "fields":[  
//          {  
//             "group":"persist"
//          },
//          {  
//             "name":"useMasterClock",
//             "type":"bool"
//          },
//          {  
//             "name":"sequenceLength",
//             "type":"Ticks"
//          },
//          {  
//             "name":"events",
//             "type":"NoteEventAr"
//          },
//          {  
//             "group":"noPersist"
//          },
//          {  
//             "name":"startTime",
//             "type":"Ticks"
//          },
//          {  
//             "name":"ptr",
//             "type":"int"
//          }
//       ]      
//    }
// @end


// *** DO NOT MODIFY THIS FILE (see src/midiseq.in.h) ***
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

typedef struct PadAr_t {
    Array body;
} PadAr;

static inline PadAr *PadAr_new(int nelems) {
    return (PadAr*)Array_new(nelems, sizeof(Pad), (Array_clearElement)NULL);
}

static inline void PadAr_init(PadAr *arr, int nelems) {
    Array_init((Array*)arr, nelems, sizeof(Pad), (Array_clearElement)NULL);
}

static inline void PadAr_clear(PadAr *arr) {
    Array_clear((Array*)arr);
    PadAr zero = {{0}};
    *arr = zero;
}

static inline void PadAr_free(PadAr *arr) {
    Array_free((Array*)arr);
}

static inline void PadAr_truncate(PadAr *arr) {
    Array_truncate((Array*)arr);
}

static inline int PadAr_len(PadAr *arr) {
    return Array_len((Array*)arr);
}

static inline Pad PadAr_get(PadAr *arr, int index, Error *err) {
    Pad v = {0};
    Array_getCheck(arr, index, v, err);
    memmove(&v, Array_get((Array*)arr, index), Array_elemSize((Array*)arr));
    return v;
}

static inline Pad *PadAr_getp(PadAr *arr, int index, Error *err) {
    Array_getCheck(arr, index, NULL, err);
    return (Pad *)Array_get((Array*)arr, index);
}


static inline void PadAr_set(PadAr *arr, int index, Pad elem, Error *err) {
    Array_setCheck(arr, index, err);
    Array_set((Array*)arr, index, (char*)&elem);
}

static inline void PadAr_setp(PadAr *arr, int index, Pad *elem, Error *err) {
    Array_setCheck(arr, index, err);
    Array_set((Array*)arr, index, (char*)elem);
}

static inline void PadAr_pop(PadAr *arr, Error *err) {
    Array_popNCheck(arr, 1, err);
    Array_popN((Array*)arr, 1);
}

static inline void PadAr_push(PadAr *arr, Pad elem) {
    Pad *p = (Pad *)Array_pushN((Array*)arr, 1);
    *p = elem;
    return; 
}

static inline void PadAr_pushp(PadAr *arr, Pad *elem) {
    Pad *p = (Pad *)Array_pushN((Array*)arr, 1);
    *p = *elem;
    return; 
}

static inline void PadAr_insert(PadAr *arr, int index, Pad elem, Error *err) {
    Array_insertNCheck(arr, index, 1, err);
    Pad *p = (Pad *)Array_insertN((Array*)arr, index, 1);
    *p = elem;
}

static inline void PadAr_insertp(PadAr *arr, int index, Pad *elem, Error *err) {
    Array_insertNCheck(arr, index, 1, err);
    Pad *p = (Pad *)Array_insertN((Array*)arr, index, 1);
    *p = *elem;
}


static inline void PadAr_remove(PadAr *arr, int index, Error *err) {
    Array_removeNCheck(arr, index, 1, err);
    Array_removeN((Array*)arr, index, 1);
}

static inline void PadAr_removeN(PadAr *arr, int index, int N, Error *err) {
    Array_removeNCheck(arr, index, N, err);
    Array_removeN((Array*)arr, index, N);
}

static inline void PadAr_fit(PadAr *arr) {
    Array_fit((Array*)arr);
}

static inline int PadAr_last(PadAr *arr) {
    return Array_len((Array*)arr)-1;
}

static inline void PadAr_changeLength(PadAr *arr, int newLength) {
    Array_changeLength((Array*)arr, newLength);
}

typedef struct PadArIter_t {
   PadAr *arr;
   int index;
   bool last;
   Pad *var;
} PadArIter;

static inline bool PadArIter_next(PadArIter *iterator) {
    return ArrayIter_next((ArrayIter*)iterator);
}

static inline bool PadArIter_previous(PadArIter *iterator) {
    return ArrayIter_previous((ArrayIter*)iterator);
}

#define PadArIter_declare(var, arr)  PadArIter var = {arr, -1, false, NULL}
#define PadArIter_rdeclare(var, arr)  PadArIter var = {arr, PadAr_len(arr), false, NULL}
#define PadAr_foreach(var, arr)  for (PadArIter_declare(var, arr); PadArIter_next(&var); )
#define PadAr_rforeach(var, arr)  for (PadArIter_rdeclare(var, arr); PadArIter_previous(&var); )
#define PadAr_loop(var, arr)    PadArIter_declare(var, arr); while (PadArIter_next(&var)) 
#define PadAr_rloop(var, arr)    PadArIter_rdeclare(var, arr); while (PadArIter_previous(&var)) 

typedef struct PadPtrAr_t {
    Array body;
} PadPtrAr;

static inline PadPtrAr *PadPtrAr_new(int nelems) {
    return (PadPtrAr*)Array_new(nelems, sizeof(Pad *), (Array_clearElement)NULL);
}

static inline void PadPtrAr_init(PadPtrAr *arr, int nelems) {
    Array_init((Array*)arr, nelems, sizeof(Pad *), (Array_clearElement)NULL);
}

static inline void PadPtrAr_clear(PadPtrAr *arr) {
    Array_clear((Array*)arr);
    PadPtrAr zero = {{0}};
    *arr = zero;
}

static inline void PadPtrAr_free(PadPtrAr *arr) {
    Array_free((Array*)arr);
}

static inline void PadPtrAr_truncate(PadPtrAr *arr) {
    Array_truncate((Array*)arr);
}

static inline int PadPtrAr_len(PadPtrAr *arr) {
    return Array_len((Array*)arr);
}

static inline Pad *PadPtrAr_get(PadPtrAr *arr, int index, Error *err) {
    Pad * v = {0};
    Array_getCheck(arr, index, v, err);
    memmove(&v, Array_get((Array*)arr, index), Array_elemSize((Array*)arr));
    return v;
}

static inline Pad **PadPtrAr_getp(PadPtrAr *arr, int index, Error *err) {
    Array_getCheck(arr, index, NULL, err);
    return (Pad **)Array_get((Array*)arr, index);
}


static inline void PadPtrAr_set(PadPtrAr *arr, int index, Pad *elem, Error *err) {
    Array_setCheck(arr, index, err);
    Array_set((Array*)arr, index, (char*)&elem);
}

static inline void PadPtrAr_setp(PadPtrAr *arr, int index, Pad **elem, Error *err) {
    Array_setCheck(arr, index, err);
    Array_set((Array*)arr, index, (char*)elem);
}

static inline void PadPtrAr_pop(PadPtrAr *arr, Error *err) {
    Array_popNCheck(arr, 1, err);
    Array_popN((Array*)arr, 1);
}

static inline void PadPtrAr_push(PadPtrAr *arr, Pad *elem) {
    Pad * *p = (Pad **)Array_pushN((Array*)arr, 1);
    *p = elem;
    return; 
}

static inline void PadPtrAr_pushp(PadPtrAr *arr, Pad **elem) {
    Pad * *p = (Pad **)Array_pushN((Array*)arr, 1);
    *p = *elem;
    return; 
}

static inline void PadPtrAr_insert(PadPtrAr *arr, int index, Pad *elem, Error *err) {
    Array_insertNCheck(arr, index, 1, err);
    Pad * *p = (Pad **)Array_insertN((Array*)arr, index, 1);
    *p = elem;
}

static inline void PadPtrAr_insertp(PadPtrAr *arr, int index, Pad **elem, Error *err) {
    Array_insertNCheck(arr, index, 1, err);
    Pad * *p = (Pad **)Array_insertN((Array*)arr, index, 1);
    *p = *elem;
}


static inline void PadPtrAr_remove(PadPtrAr *arr, int index, Error *err) {
    Array_removeNCheck(arr, index, 1, err);
    Array_removeN((Array*)arr, index, 1);
}

static inline void PadPtrAr_removeN(PadPtrAr *arr, int index, int N, Error *err) {
    Array_removeNCheck(arr, index, N, err);
    Array_removeN((Array*)arr, index, N);
}

static inline void PadPtrAr_fit(PadPtrAr *arr) {
    Array_fit((Array*)arr);
}

static inline int PadPtrAr_last(PadPtrAr *arr) {
    return Array_len((Array*)arr)-1;
}

static inline void PadPtrAr_changeLength(PadPtrAr *arr, int newLength) {
    Array_changeLength((Array*)arr, newLength);
}

typedef struct PadPtrArIter_t {
   PadPtrAr *arr;
   int index;
   bool last;
   Pad **var;
} PadPtrArIter;

static inline bool PadPtrArIter_next(PadPtrArIter *iterator) {
    return ArrayIter_next((ArrayIter*)iterator);
}

static inline bool PadPtrArIter_previous(PadPtrArIter *iterator) {
    return ArrayIter_previous((ArrayIter*)iterator);
}

#define PadPtrArIter_declare(var, arr)  PadPtrArIter var = {arr, -1, false, NULL}
#define PadPtrArIter_rdeclare(var, arr)  PadPtrArIter var = {arr, PadPtrAr_len(arr), false, NULL}
#define PadPtrAr_foreach(var, arr)  for (PadPtrArIter_declare(var, arr); PadPtrArIter_next(&var); )
#define PadPtrAr_rforeach(var, arr)  for (PadPtrArIter_rdeclare(var, arr); PadPtrArIter_previous(&var); )
#define PadPtrAr_loop(var, arr)    PadPtrArIter_declare(var, arr); while (PadPtrArIter_next(&var)) 
#define PadPtrAr_rloop(var, arr)    PadPtrArIter_rdeclare(var, arr); while (PadPtrArIter_previous(&var)) 



// *** DO NOT MODIFY THIS FILE (see src/midiseq.in.h) ***
struct IndexedOff_t
{
    int padIndex;
    int pitch;
};
#define IndexedOff_newUninitialized() ((IndexedOff*)sysmem_newptrclear(sizeof(IndexedOff)))
static inline int IndexedOff_padIndex(IndexedOff *self){return self->padIndex;}
static inline void IndexedOff_setPadIndex(IndexedOff *self, int value){self->padIndex = value;}
static inline int IndexedOff_pitch(IndexedOff *self){return self->pitch;}
static inline void IndexedOff_setPitch(IndexedOff *self, int value){self->pitch = value;}
#define IndexedOff_declare(name, padIndex, pitch) IndexedOff name = {(padIndex), (pitch)}
int IndexedOff_cmpPadIndex(IndexedOff *left, IndexedOff *right);

typedef struct IndexedOffAr_t {
    Array body;
} IndexedOffAr;

static inline IndexedOffAr *IndexedOffAr_new(int nelems) {
    return (IndexedOffAr*)Array_new(nelems, sizeof(IndexedOff), (Array_clearElement)NULL);
}

static inline void IndexedOffAr_init(IndexedOffAr *arr, int nelems) {
    Array_init((Array*)arr, nelems, sizeof(IndexedOff), (Array_clearElement)NULL);
}

static inline void IndexedOffAr_clear(IndexedOffAr *arr) {
    Array_clear((Array*)arr);
    IndexedOffAr zero = {{0}};
    *arr = zero;
}

static inline void IndexedOffAr_free(IndexedOffAr *arr) {
    Array_free((Array*)arr);
}

static inline void IndexedOffAr_truncate(IndexedOffAr *arr) {
    Array_truncate((Array*)arr);
}

static inline int IndexedOffAr_len(IndexedOffAr *arr) {
    return Array_len((Array*)arr);
}

static inline IndexedOff IndexedOffAr_get(IndexedOffAr *arr, int index, Error *err) {
    IndexedOff v = {0};
    Array_getCheck(arr, index, v, err);
    memmove(&v, Array_get((Array*)arr, index), Array_elemSize((Array*)arr));
    return v;
}

static inline IndexedOff *IndexedOffAr_getp(IndexedOffAr *arr, int index, Error *err) {
    Array_getCheck(arr, index, NULL, err);
    return (IndexedOff *)Array_get((Array*)arr, index);
}


static inline void IndexedOffAr_set(IndexedOffAr *arr, int index, IndexedOff elem, Error *err) {
    Array_setCheck(arr, index, err);
    Array_set((Array*)arr, index, (char*)&elem);
}

static inline void IndexedOffAr_setp(IndexedOffAr *arr, int index, IndexedOff *elem, Error *err) {
    Array_setCheck(arr, index, err);
    Array_set((Array*)arr, index, (char*)elem);
}

static inline void IndexedOffAr_pop(IndexedOffAr *arr, Error *err) {
    Array_popNCheck(arr, 1, err);
    Array_popN((Array*)arr, 1);
}

static inline void IndexedOffAr_push(IndexedOffAr *arr, IndexedOff elem) {
    IndexedOff *p = (IndexedOff *)Array_pushN((Array*)arr, 1);
    *p = elem;
    return; 
}

static inline void IndexedOffAr_pushp(IndexedOffAr *arr, IndexedOff *elem) {
    IndexedOff *p = (IndexedOff *)Array_pushN((Array*)arr, 1);
    *p = *elem;
    return; 
}

static inline void IndexedOffAr_insert(IndexedOffAr *arr, int index, IndexedOff elem, Error *err) {
    Array_insertNCheck(arr, index, 1, err);
    IndexedOff *p = (IndexedOff *)Array_insertN((Array*)arr, index, 1);
    *p = elem;
}

static inline void IndexedOffAr_insertp(IndexedOffAr *arr, int index, IndexedOff *elem, Error *err) {
    Array_insertNCheck(arr, index, 1, err);
    IndexedOff *p = (IndexedOff *)Array_insertN((Array*)arr, index, 1);
    *p = *elem;
}


static inline void IndexedOffAr_remove(IndexedOffAr *arr, int index, Error *err) {
    Array_removeNCheck(arr, index, 1, err);
    Array_removeN((Array*)arr, index, 1);
}

static inline void IndexedOffAr_removeN(IndexedOffAr *arr, int index, int N, Error *err) {
    Array_removeNCheck(arr, index, N, err);
    Array_removeN((Array*)arr, index, N);
}

static inline void IndexedOffAr_fit(IndexedOffAr *arr) {
    Array_fit((Array*)arr);
}

static inline int IndexedOffAr_last(IndexedOffAr *arr) {
    return Array_len((Array*)arr)-1;
}

static inline void IndexedOffAr_changeLength(IndexedOffAr *arr, int newLength) {
    Array_changeLength((Array*)arr, newLength);
}

typedef struct IndexedOffArIter_t {
   IndexedOffAr *arr;
   int index;
   bool last;
   IndexedOff *var;
} IndexedOffArIter;

static inline bool IndexedOffArIter_next(IndexedOffArIter *iterator) {
    return ArrayIter_next((ArrayIter*)iterator);
}

static inline bool IndexedOffArIter_previous(IndexedOffArIter *iterator) {
    return ArrayIter_previous((ArrayIter*)iterator);
}

#define IndexedOffArIter_declare(var, arr)  IndexedOffArIter var = {arr, -1, false, NULL}
#define IndexedOffArIter_rdeclare(var, arr)  IndexedOffArIter var = {arr, IndexedOffAr_len(arr), false, NULL}
#define IndexedOffAr_foreach(var, arr)  for (IndexedOffArIter_declare(var, arr); IndexedOffArIter_next(&var); )
#define IndexedOffAr_rforeach(var, arr)  for (IndexedOffArIter_rdeclare(var, arr); IndexedOffArIter_previous(&var); )
#define IndexedOffAr_loop(var, arr)    IndexedOffArIter_declare(var, arr); while (IndexedOffArIter_next(&var)) 
#define IndexedOffAr_rloop(var, arr)    IndexedOffArIter_rdeclare(var, arr); while (IndexedOffArIter_previous(&var)) 

typedef struct IndexedOffArSlice_t {
    int len;
    IndexedOff *data;
    int index;
    IndexedOff *var;
} IndexedOffArSlice;
#define IndexedOffAr_declareSlice(name) IndexedOffArSlice name = {0}
#define IndexedOffAr_sliceEmpty(slice) (slice.data == NULL)
#define IndexedOffAr_sliceForeach(slice) for (slice.index=0, slice.var=slice.data; slice.index < slice.len; slice.index++, slice.var++)

#define IndexedOffAr_rsliceForeach(slice) for (slice.index=slice.len-1, slice.var = slice.data + slice.index*sizeof(IndexedOff); \
                                              slice.index >= 0; slice.index--, slice.var--)

static inline void IndexedOffAr_binInsertPadIndex(IndexedOffAr *arr, IndexedOff elem) {
    Array_binInsert((Array*)arr, (char*)&elem, (Array_compare)IndexedOff_cmpPadIndex, true);
}

static inline void IndexedOffAr_binRemovePadIndex(IndexedOffAr *arr, IndexedOff elem) {
    Array_binRemove((Array*)arr, (char*)&elem, (Array_compare)IndexedOff_cmpPadIndex, true);
}

static inline void IndexedOffAr_sortPadIndex(IndexedOffAr *arr) {
    Array_sort((Array*)arr, (Array_compare)IndexedOff_cmpPadIndex);
}

static inline IndexedOffArSlice IndexedOffAr_binSearchPadIndex(IndexedOffAr *arr, IndexedOff elem) {
    IndexedOffArSlice slice = {0};
    Array_binSearch((Array*)arr, (char*)&elem, (Array_compare)IndexedOff_cmpPadIndex, (ArraySlice*)&slice);
    return slice;
}


// *** DO NOT MODIFY THIS FILE (see src/midiseq.in.h) ***
struct TimedOff_t
{
    Ticks time;
    int pitch;
};
#define TimedOff_newUninitialized() ((TimedOff*)sysmem_newptrclear(sizeof(TimedOff)))
static inline Ticks TimedOff_time(TimedOff *self){return self->time;}
static inline void TimedOff_setTime(TimedOff *self, Ticks value){self->time = value;}
static inline int TimedOff_pitch(TimedOff *self){return self->pitch;}
static inline void TimedOff_setPitch(TimedOff *self, int value){self->pitch = value;}
#define TimedOff_declare(name, time, pitch) TimedOff name = {(time), (pitch)}
int TimedOff_cmpTime(TimedOff *left, TimedOff *right);

typedef struct TimedOffAr_t {
    Array body;
} TimedOffAr;

static inline TimedOffAr *TimedOffAr_new(int nelems) {
    return (TimedOffAr*)Array_new(nelems, sizeof(TimedOff), (Array_clearElement)NULL);
}

static inline void TimedOffAr_init(TimedOffAr *arr, int nelems) {
    Array_init((Array*)arr, nelems, sizeof(TimedOff), (Array_clearElement)NULL);
}

static inline void TimedOffAr_clear(TimedOffAr *arr) {
    Array_clear((Array*)arr);
    TimedOffAr zero = {{0}};
    *arr = zero;
}

static inline void TimedOffAr_free(TimedOffAr *arr) {
    Array_free((Array*)arr);
}

static inline void TimedOffAr_truncate(TimedOffAr *arr) {
    Array_truncate((Array*)arr);
}

static inline int TimedOffAr_len(TimedOffAr *arr) {
    return Array_len((Array*)arr);
}

static inline TimedOff TimedOffAr_get(TimedOffAr *arr, int index, Error *err) {
    TimedOff v = {0};
    Array_getCheck(arr, index, v, err);
    memmove(&v, Array_get((Array*)arr, index), Array_elemSize((Array*)arr));
    return v;
}

static inline TimedOff *TimedOffAr_getp(TimedOffAr *arr, int index, Error *err) {
    Array_getCheck(arr, index, NULL, err);
    return (TimedOff *)Array_get((Array*)arr, index);
}


static inline void TimedOffAr_set(TimedOffAr *arr, int index, TimedOff elem, Error *err) {
    Array_setCheck(arr, index, err);
    Array_set((Array*)arr, index, (char*)&elem);
}

static inline void TimedOffAr_setp(TimedOffAr *arr, int index, TimedOff *elem, Error *err) {
    Array_setCheck(arr, index, err);
    Array_set((Array*)arr, index, (char*)elem);
}

static inline void TimedOffAr_pop(TimedOffAr *arr, Error *err) {
    Array_popNCheck(arr, 1, err);
    Array_popN((Array*)arr, 1);
}

static inline void TimedOffAr_push(TimedOffAr *arr, TimedOff elem) {
    TimedOff *p = (TimedOff *)Array_pushN((Array*)arr, 1);
    *p = elem;
    return; 
}

static inline void TimedOffAr_pushp(TimedOffAr *arr, TimedOff *elem) {
    TimedOff *p = (TimedOff *)Array_pushN((Array*)arr, 1);
    *p = *elem;
    return; 
}

static inline void TimedOffAr_insert(TimedOffAr *arr, int index, TimedOff elem, Error *err) {
    Array_insertNCheck(arr, index, 1, err);
    TimedOff *p = (TimedOff *)Array_insertN((Array*)arr, index, 1);
    *p = elem;
}

static inline void TimedOffAr_insertp(TimedOffAr *arr, int index, TimedOff *elem, Error *err) {
    Array_insertNCheck(arr, index, 1, err);
    TimedOff *p = (TimedOff *)Array_insertN((Array*)arr, index, 1);
    *p = *elem;
}


static inline void TimedOffAr_remove(TimedOffAr *arr, int index, Error *err) {
    Array_removeNCheck(arr, index, 1, err);
    Array_removeN((Array*)arr, index, 1);
}

static inline void TimedOffAr_removeN(TimedOffAr *arr, int index, int N, Error *err) {
    Array_removeNCheck(arr, index, N, err);
    Array_removeN((Array*)arr, index, N);
}

static inline void TimedOffAr_fit(TimedOffAr *arr) {
    Array_fit((Array*)arr);
}

static inline int TimedOffAr_last(TimedOffAr *arr) {
    return Array_len((Array*)arr)-1;
}

static inline void TimedOffAr_changeLength(TimedOffAr *arr, int newLength) {
    Array_changeLength((Array*)arr, newLength);
}

typedef struct TimedOffArIter_t {
   TimedOffAr *arr;
   int index;
   bool last;
   TimedOff *var;
} TimedOffArIter;

static inline bool TimedOffArIter_next(TimedOffArIter *iterator) {
    return ArrayIter_next((ArrayIter*)iterator);
}

static inline bool TimedOffArIter_previous(TimedOffArIter *iterator) {
    return ArrayIter_previous((ArrayIter*)iterator);
}

#define TimedOffArIter_declare(var, arr)  TimedOffArIter var = {arr, -1, false, NULL}
#define TimedOffArIter_rdeclare(var, arr)  TimedOffArIter var = {arr, TimedOffAr_len(arr), false, NULL}
#define TimedOffAr_foreach(var, arr)  for (TimedOffArIter_declare(var, arr); TimedOffArIter_next(&var); )
#define TimedOffAr_rforeach(var, arr)  for (TimedOffArIter_rdeclare(var, arr); TimedOffArIter_previous(&var); )
#define TimedOffAr_loop(var, arr)    TimedOffArIter_declare(var, arr); while (TimedOffArIter_next(&var)) 
#define TimedOffAr_rloop(var, arr)    TimedOffArIter_rdeclare(var, arr); while (TimedOffArIter_previous(&var)) 

static inline void TimedOffAr_binInsertTime(TimedOffAr *arr, TimedOff elem) {
    Array_binInsert((Array*)arr, (char*)&elem, (Array_compare)TimedOff_cmpTime, false);
}

static inline void TimedOffAr_binRemoveTime(TimedOffAr *arr, TimedOff elem) {
    Array_binRemove((Array*)arr, (char*)&elem, (Array_compare)TimedOff_cmpTime, false);
}

static inline void TimedOffAr_sortTime(TimedOffAr *arr) {
    Array_sort((Array*)arr, (Array_compare)TimedOff_cmpTime);
}

static inline TimedOff *TimedOffAr_binSearchTime(TimedOffAr *arr, TimedOff elem) {
    return (TimedOff *)Array_binSearch((Array*)arr, (char*)&elem, (Array_compare)TimedOff_cmpTime, NULL);
}


// *** DO NOT MODIFY THIS FILE (see src/midiseq.in.h) ***
struct NoteManager_t
{
    // ** not persisted **
    TimedOffAr pending;
    IndexedOffAr endgroups;
    Port *output;
    t_atom *atoms;
};
#define NoteManager_newUninitialized() ((NoteManager*)sysmem_newptrclear(sizeof(NoteManager)))
static inline TimedOffAr NoteManager_pending(NoteManager *self){return self->pending;}
static inline void NoteManager_setPending(NoteManager *self, TimedOffAr value){self->pending = value;}
static inline IndexedOffAr NoteManager_endgroups(NoteManager *self){return self->endgroups;}
static inline void NoteManager_setEndgroups(NoteManager *self, IndexedOffAr value){self->endgroups = value;}
static inline Port *NoteManager_output(NoteManager *self){return self->output;}
static inline void NoteManager_setOutput(NoteManager *self, Port *value){self->output = value;}
static inline t_atom *NoteManager_atoms(NoteManager *self){return self->atoms;}
static inline void NoteManager_setAtoms(NoteManager *self, t_atom *value){self->atoms = value;}
NoteManager *NoteManager_new(Port *port);
void NoteManager_free(NoteManager *nm);
bool NoteManager_insertNoteOff(NoteManager *manager, Ticks timestamp, int pitch, int padIndexForEndgroup);
void NoteManager_sendNoteOn(NoteManager *manager, int pitch, int velocity);
void NoteManager_flushOffs(NoteManager *manager);
void NoteManager_dblogPending(NoteManager *manager, Ticks current);
Ticks NoteManager_scheduleOffs(NoteManager *manager, Ticks current);
void NoteManager_midievent(NoteManager *manager, MEvent cell, int padIndexForEndgroup);
void NoteManager_padNoteOff(NoteManager *manager, int padIndex);



// *** DO NOT MODIFY THIS FILE (see src/midiseq.in.h) ***
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

typedef struct PortFindCellAr_t {
    Array body;
} PortFindCellAr;

static inline PortFindCellAr *PortFindCellAr_new(int nelems) {
    return (PortFindCellAr*)Array_new(nelems, sizeof(PortFindCell), (Array_clearElement)NULL);
}

static inline void PortFindCellAr_init(PortFindCellAr *arr, int nelems) {
    Array_init((Array*)arr, nelems, sizeof(PortFindCell), (Array_clearElement)NULL);
}

static inline void PortFindCellAr_clear(PortFindCellAr *arr) {
    Array_clear((Array*)arr);
    PortFindCellAr zero = {{0}};
    *arr = zero;
}

static inline void PortFindCellAr_free(PortFindCellAr *arr) {
    Array_free((Array*)arr);
}

static inline void PortFindCellAr_truncate(PortFindCellAr *arr) {
    Array_truncate((Array*)arr);
}

static inline int PortFindCellAr_len(PortFindCellAr *arr) {
    return Array_len((Array*)arr);
}

static inline PortFindCell PortFindCellAr_get(PortFindCellAr *arr, int index, Error *err) {
    PortFindCell v = {0};
    Array_getCheck(arr, index, v, err);
    memmove(&v, Array_get((Array*)arr, index), Array_elemSize((Array*)arr));
    return v;
}

static inline PortFindCell *PortFindCellAr_getp(PortFindCellAr *arr, int index, Error *err) {
    Array_getCheck(arr, index, NULL, err);
    return (PortFindCell *)Array_get((Array*)arr, index);
}


static inline void PortFindCellAr_set(PortFindCellAr *arr, int index, PortFindCell elem, Error *err) {
    Array_setCheck(arr, index, err);
    Array_set((Array*)arr, index, (char*)&elem);
}

static inline void PortFindCellAr_setp(PortFindCellAr *arr, int index, PortFindCell *elem, Error *err) {
    Array_setCheck(arr, index, err);
    Array_set((Array*)arr, index, (char*)elem);
}

static inline void PortFindCellAr_pop(PortFindCellAr *arr, Error *err) {
    Array_popNCheck(arr, 1, err);
    Array_popN((Array*)arr, 1);
}

static inline void PortFindCellAr_push(PortFindCellAr *arr, PortFindCell elem) {
    PortFindCell *p = (PortFindCell *)Array_pushN((Array*)arr, 1);
    *p = elem;
    return; 
}

static inline void PortFindCellAr_pushp(PortFindCellAr *arr, PortFindCell *elem) {
    PortFindCell *p = (PortFindCell *)Array_pushN((Array*)arr, 1);
    *p = *elem;
    return; 
}

static inline void PortFindCellAr_insert(PortFindCellAr *arr, int index, PortFindCell elem, Error *err) {
    Array_insertNCheck(arr, index, 1, err);
    PortFindCell *p = (PortFindCell *)Array_insertN((Array*)arr, index, 1);
    *p = elem;
}

static inline void PortFindCellAr_insertp(PortFindCellAr *arr, int index, PortFindCell *elem, Error *err) {
    Array_insertNCheck(arr, index, 1, err);
    PortFindCell *p = (PortFindCell *)Array_insertN((Array*)arr, index, 1);
    *p = *elem;
}


static inline void PortFindCellAr_remove(PortFindCellAr *arr, int index, Error *err) {
    Array_removeNCheck(arr, index, 1, err);
    Array_removeN((Array*)arr, index, 1);
}

static inline void PortFindCellAr_removeN(PortFindCellAr *arr, int index, int N, Error *err) {
    Array_removeNCheck(arr, index, N, err);
    Array_removeN((Array*)arr, index, N);
}

static inline void PortFindCellAr_fit(PortFindCellAr *arr) {
    Array_fit((Array*)arr);
}

static inline int PortFindCellAr_last(PortFindCellAr *arr) {
    return Array_len((Array*)arr)-1;
}

static inline void PortFindCellAr_changeLength(PortFindCellAr *arr, int newLength) {
    Array_changeLength((Array*)arr, newLength);
}

typedef struct PortFindCellArIter_t {
   PortFindCellAr *arr;
   int index;
   bool last;
   PortFindCell *var;
} PortFindCellArIter;

static inline bool PortFindCellArIter_next(PortFindCellArIter *iterator) {
    return ArrayIter_next((ArrayIter*)iterator);
}

static inline bool PortFindCellArIter_previous(PortFindCellArIter *iterator) {
    return ArrayIter_previous((ArrayIter*)iterator);
}

#define PortFindCellArIter_declare(var, arr)  PortFindCellArIter var = {arr, -1, false, NULL}
#define PortFindCellArIter_rdeclare(var, arr)  PortFindCellArIter var = {arr, PortFindCellAr_len(arr), false, NULL}
#define PortFindCellAr_foreach(var, arr)  for (PortFindCellArIter_declare(var, arr); PortFindCellArIter_next(&var); )
#define PortFindCellAr_rforeach(var, arr)  for (PortFindCellArIter_rdeclare(var, arr); PortFindCellArIter_previous(&var); )
#define PortFindCellAr_loop(var, arr)    PortFindCellArIter_declare(var, arr); while (PortFindCellArIter_next(&var)) 
#define PortFindCellAr_rloop(var, arr)    PortFindCellArIter_rdeclare(var, arr); while (PortFindCellArIter_previous(&var)) 



// *** DO NOT MODIFY THIS FILE (see src/midiseq.in.h) ***
struct PortFind_t
{
    // ** not persisted **
    PortFindCellAr objects;
    void *hub;
    Port_anythingDispatchFunc anythingDispatch;
    Port_intDispatchFunc intDispatch;
};
#define PortFind_newUninitialized() ((PortFind*)sysmem_newptrclear(sizeof(PortFind)))
static inline PortFindCellAr PortFind_objects(PortFind *self){return self->objects;}
static inline void PortFind_setObjects(PortFind *self, PortFindCellAr value){self->objects = value;}
static inline void *PortFind_hub(PortFind *self){return self->hub;}
static inline void PortFind_setHub(PortFind *self, void *value){self->hub = value;}
static inline Port_anythingDispatchFunc PortFind_anythingDispatch(PortFind *self){return self->anythingDispatch;}
static inline void PortFind_setAnythingDispatch(PortFind *self, Port_anythingDispatchFunc value){self->anythingDispatch = value;}
static inline Port_intDispatchFunc PortFind_intDispatch(PortFind *self){return self->intDispatch;}
static inline void PortFind_setIntDispatch(PortFind *self, Port_intDispatchFunc value){self->intDispatch = value;}
void PortFind_init(PortFind *pf);
long PortFind_iterator(PortFind *pf, t_object *targetBox);
int PortFind_discover(PortFind *pf, t_object *sourceMaxObject, void *hub, Error *err);
void PortFind_clear(PortFind *pf);
Port *PortFind_findByVarname(PortFind *pf, Symbol *symbol);
Port *PortFind_findByTrack(PortFind *pf, Symbol *symbol);
Port *PortFind_findById(PortFind *pf, Symbol *symbol);
int PortFind_portCount(PortFind *pf);
Port *PortFind_findByIndex(PortFind *pf, int index, Error *err);


#define PortFind_declare(name) PortFind _##name; PortFind *name = &_##name; memset(name, 0, sizeof(PortFind)); PortFind_init(name)        


// *** DO NOT MODIFY THIS FILE (see src/midiseq.in.h) ***
struct PadList_t
{
    PadAr pads;
    PadPtrAr running;
};
#define PadList_newUninitialized() ((PadList*)sysmem_newptrclear(sizeof(PadList)))
static inline PadAr *PadList_pads(PadList *self){return &self->pads;}
static inline PadPtrAr *PadList_running(PadList *self){return &self->running;}
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



// *** DO NOT MODIFY THIS FILE (see src/midiseq.in.h) ***
struct Track_t
{
    Symbol *name;
    NoteManager *noteManager;
};
#define Track_newUninitialized() ((Track*)sysmem_newptrclear(sizeof(Track)))
static inline Symbol *Track_name(Track *self){return self->name;}
static inline void Track_setName(Track *self, Symbol *value){self->name = value;}
static inline NoteManager *Track_noteManager(Track *self){return self->noteManager;}
static inline void Track_setNoteManager(Track *self, NoteManager *value){self->noteManager = value;}

typedef struct TrackAr_t {
    Array body;
} TrackAr;

static inline TrackAr *TrackAr_new(int nelems) {
    return (TrackAr*)Array_new(nelems, sizeof(Track), (Array_clearElement)NULL);
}

static inline void TrackAr_init(TrackAr *arr, int nelems) {
    Array_init((Array*)arr, nelems, sizeof(Track), (Array_clearElement)NULL);
}

static inline void TrackAr_clear(TrackAr *arr) {
    Array_clear((Array*)arr);
    TrackAr zero = {{0}};
    *arr = zero;
}

static inline void TrackAr_free(TrackAr *arr) {
    Array_free((Array*)arr);
}

static inline void TrackAr_truncate(TrackAr *arr) {
    Array_truncate((Array*)arr);
}

static inline int TrackAr_len(TrackAr *arr) {
    return Array_len((Array*)arr);
}

static inline Track TrackAr_get(TrackAr *arr, int index, Error *err) {
    Track v = {0};
    Array_getCheck(arr, index, v, err);
    memmove(&v, Array_get((Array*)arr, index), Array_elemSize((Array*)arr));
    return v;
}

static inline Track *TrackAr_getp(TrackAr *arr, int index, Error *err) {
    Array_getCheck(arr, index, NULL, err);
    return (Track *)Array_get((Array*)arr, index);
}


static inline void TrackAr_set(TrackAr *arr, int index, Track elem, Error *err) {
    Array_setCheck(arr, index, err);
    Array_set((Array*)arr, index, (char*)&elem);
}

static inline void TrackAr_setp(TrackAr *arr, int index, Track *elem, Error *err) {
    Array_setCheck(arr, index, err);
    Array_set((Array*)arr, index, (char*)elem);
}

static inline void TrackAr_pop(TrackAr *arr, Error *err) {
    Array_popNCheck(arr, 1, err);
    Array_popN((Array*)arr, 1);
}

static inline void TrackAr_push(TrackAr *arr, Track elem) {
    Track *p = (Track *)Array_pushN((Array*)arr, 1);
    *p = elem;
    return; 
}

static inline void TrackAr_pushp(TrackAr *arr, Track *elem) {
    Track *p = (Track *)Array_pushN((Array*)arr, 1);
    *p = *elem;
    return; 
}

static inline void TrackAr_insert(TrackAr *arr, int index, Track elem, Error *err) {
    Array_insertNCheck(arr, index, 1, err);
    Track *p = (Track *)Array_insertN((Array*)arr, index, 1);
    *p = elem;
}

static inline void TrackAr_insertp(TrackAr *arr, int index, Track *elem, Error *err) {
    Array_insertNCheck(arr, index, 1, err);
    Track *p = (Track *)Array_insertN((Array*)arr, index, 1);
    *p = *elem;
}


static inline void TrackAr_remove(TrackAr *arr, int index, Error *err) {
    Array_removeNCheck(arr, index, 1, err);
    Array_removeN((Array*)arr, index, 1);
}

static inline void TrackAr_removeN(TrackAr *arr, int index, int N, Error *err) {
    Array_removeNCheck(arr, index, N, err);
    Array_removeN((Array*)arr, index, N);
}

static inline void TrackAr_fit(TrackAr *arr) {
    Array_fit((Array*)arr);
}

static inline int TrackAr_last(TrackAr *arr) {
    return Array_len((Array*)arr)-1;
}

static inline void TrackAr_changeLength(TrackAr *arr, int newLength) {
    Array_changeLength((Array*)arr, newLength);
}

typedef struct TrackArIter_t {
   TrackAr *arr;
   int index;
   bool last;
   Track *var;
} TrackArIter;

static inline bool TrackArIter_next(TrackArIter *iterator) {
    return ArrayIter_next((ArrayIter*)iterator);
}

static inline bool TrackArIter_previous(TrackArIter *iterator) {
    return ArrayIter_previous((ArrayIter*)iterator);
}

#define TrackArIter_declare(var, arr)  TrackArIter var = {arr, -1, false, NULL}
#define TrackArIter_rdeclare(var, arr)  TrackArIter var = {arr, TrackAr_len(arr), false, NULL}
#define TrackAr_foreach(var, arr)  for (TrackArIter_declare(var, arr); TrackArIter_next(&var); )
#define TrackAr_rforeach(var, arr)  for (TrackArIter_rdeclare(var, arr); TrackArIter_previous(&var); )
#define TrackAr_loop(var, arr)    TrackArIter_declare(var, arr); while (TrackArIter_next(&var)) 
#define TrackAr_rloop(var, arr)    TrackArIter_rdeclare(var, arr); while (TrackArIter_previous(&var)) 




// *** DO NOT MODIFY THIS FILE (see src/midiseq.in.h) ***
struct TrackList_t
{
    TrackAr list;
};
#define TrackList_newUninitialized() ((TrackList*)sysmem_newptrclear(sizeof(TrackList)))
static inline TrackAr *TrackList_list(TrackList *self){return &self->list;}
TrackList *TrackList_new(PortFind *pf);
void TrackList_init(TrackList *tl, PortFind *pf);
void TrackList_clear(TrackList *tl);
void TrackList_free(TrackList *tl);
Track *TrackList_findTrackByName(TrackList *tl, Symbol *name);
int TrackList_count(TrackList *tl);
Track *TrackList_findTrackByIndex(TrackList *tl, int index, Error *err);
TrackList *TrackList_fromBinFile(BinFile *bf, Error *err);
void TrackList_toBinFile(TrackList *tl, BinFile *bf, Error *err);



// *** DO NOT MODIFY THIS FILE (see src/midiseq.in.h) ***
struct PortRef_t
{
    Port *port;
    int outlet;
};
static inline Port *PortRef_port(PortRef *self){return self->port;}
static inline void PortRef_setPort(PortRef *self, Port *value){self->port = value;}
static inline int PortRef_outlet(PortRef *self){return self->outlet;}
static inline void PortRef_setOutlet(PortRef *self, int value){self->outlet = value;}



#define PortRef_declare(name, port, outlet)    PortRef _##name = {port, outlet}; PortRef *name = &_##name
static inline void PortRef_set(PortRef *pr, Port *port, int outlet) {
   pr->port   = port;
   pr->outlet = outlet;
}
#define PortRef_send(pr, argc, argv, err)      Port_send(PortRef_port(pr), PortRef_outlet(pr), argc, argv, err)
#define PortRef_sendInteger(pr, value, err)    Port_sendInteger(PortRef_port(pr), PortRef_outlet(pr), value, err)


// *** DO NOT MODIFY THIS FILE (see src/midiseq.in.h) ***
struct DropDown_t
{
    SymbolPtrAr table;
    int selected;
    PortRef portRef;
};
#define DropDown_newUninitialized() ((DropDown*)sysmem_newptrclear(sizeof(DropDown)))
static inline SymbolPtrAr *DropDown_table(DropDown *self){return &self->table;}
static inline int DropDown_selected(DropDown *self){return self->selected;}
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



static inline PortRef *DropDown_portRef(DropDown *dd) {
    return &dd->portRef;
}

static inline void DropDown_setPortRef(DropDown *dd, PortRef *pr) {
   dd->portRef = *pr;
}

// *** DO NOT MODIFY THIS FILE (see src/midiseq.in.h) ***
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
void Hub_anythingDispatch(void *hub_in, Port *port, Symbol *msg, long argc, t_atom *argv);
void Hub_intDispatch(void *hub_in, Port *port, long value, long inlet);
void Hub_toBinFile(Hub *hub, BinFile *bf, Error *err);
Hub *Hub_fromBinFile(BinFile *bf, Error *err);
void Hub_fromBinFileUninitialized(Hub *hub, BinFile *bf, Error *err);



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
