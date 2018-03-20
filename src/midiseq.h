// *** DO NOT MODIFY THIS FILE (see src/midiseq.in.h) generated 03/20/2018 10:23:21 ***

#define APIF /**/
sds stripBaseName(const char *path);

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

static inline void MEventAr_clear(MEventAr *arr) {
    Array_clear((Array*)arr);
    MEventAr zero = {0};
    *arr = zero;
}

static inline void MEventAr_fit(MEventAr *arr) {
    Array_fit((Array*)arr);
}

#define MEventAr_foreach(var, arr)  for (MEventArIt_declare(var, arr); MEventArIt_next(&var); )            

static inline MEvent MEventAr_get(MEventAr *arr, int index, Error *err) {
    MEvent v = {0};
    Array_getCheck(arr, index, v, err);
    memmove(&v, Array_get((Array*)arr, index), Array_elemSize((Array*)arr));
    return v;
}

static inline MEvent *MEventAr_getp(MEventAr *arr, int index, Error *err) {
    Array_getCheck(arr, index, NULL, err);
    return (MEvent *)Array_get((Array*)arr, index);
}

static inline void MEventAr_init(MEventAr *arr, int nelems) {
    Array_init((Array*)arr, nelems, sizeof(MEvent), (Array_clearElement)NULL);
}

static inline void MEventAr_insert(MEventAr *arr, int index, MEvent elem, Error *err) {
    Array_insertNCheck(arr, index, 1, err);
    MEvent *p = (MEvent *)Array_insertN((Array*)arr, index, 1);
    *p = elem;
}

static inline int MEventAr_last(MEventAr *arr) {
    return Array_len((Array*)arr)-1;
}            

static inline int MEventAr_len(MEventAr *arr) {
    return Array_len((Array*)arr);
}

static inline void MEventAr_push(MEventAr *arr, MEvent elem) {
    MEvent *p = (MEvent *)Array_pushN((Array*)arr, 1);
    *p = elem;
    return; 
}            

#define MEventAr_rforeach(var, arr)  for (MEventArIt_rdeclare(var, arr); MEventArIt_previous(&var); )            

#define MEventArIt_declare(var, arr)  MEventArIt var = {arr, -1, false, NULL}            

static inline bool MEventArIt_next(MEventArIt *iterator) {
    return ArrayIt_next((ArrayIt*)iterator);
}

static inline bool MEventArIt_previous(MEventArIt *iterator) {
    return ArrayIt_previous((ArrayIt*)iterator);
}            

#define MEventArIt_rdeclare(var, arr)  MEventArIt var = {arr, MEventAr_len(arr), false, NULL}            


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

static inline void PtrAr_changeLength(PtrAr *arr, int newLength) {
    Array_changeLength((Array*)arr, newLength);
}                        

static inline void PtrAr_clear(PtrAr *arr) {
    Array_clear((Array*)arr);
    PtrAr zero = {0};
    *arr = zero;
}

#define PtrAr_foreach(var, arr)  for (PtrArIt_declare(var, arr); PtrArIt_next(&var); )            

static inline void *PtrAr_get(PtrAr *arr, int index, Error *err) {
    void * v = {0};
    Array_getCheck(arr, index, v, err);
    memmove(&v, Array_get((Array*)arr, index), Array_elemSize((Array*)arr));
    return v;
}

static inline void PtrAr_init(PtrAr *arr, int nelems) {
    Array_init((Array*)arr, nelems, sizeof(void *), (Array_clearElement)NULL);
}

static inline void PtrAr_push(PtrAr *arr, void *elem) {
    void * *p = (void **)Array_pushN((Array*)arr, 1);
    *p = elem;
    return; 
}            

static inline void PtrAr_set(PtrAr *arr, int index, void *elem, Error *err) {
    Array_setCheck(arr, index, err);
    Array_set((Array*)arr, index, (char*)&elem);
}

#define PtrArIt_declare(var, arr)  PtrArIt var = {arr, -1, false, NULL}            

static inline bool PtrArIt_next(PtrArIt *iterator) {
    return ArrayIt_next((ArrayIt*)iterator);
}


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

static inline void SymbolPtrAr_clear(SymbolPtrAr *arr) {
    Array_clear((Array*)arr);
    SymbolPtrAr zero = {0};
    *arr = zero;
}

#define SymbolPtrAr_foreach(var, arr)  for (SymbolPtrArIt_declare(var, arr); SymbolPtrArIt_next(&var); )            

static inline Symbol *SymbolPtrAr_get(SymbolPtrAr *arr, int index, Error *err) {
    Symbol * v = {0};
    Array_getCheck(arr, index, v, err);
    memmove(&v, Array_get((Array*)arr, index), Array_elemSize((Array*)arr));
    return v;
}

static inline void SymbolPtrAr_init(SymbolPtrAr *arr, int nelems) {
    Array_init((Array*)arr, nelems, sizeof(Symbol *), (Array_clearElement)NULL);
}

static inline int SymbolPtrAr_len(SymbolPtrAr *arr) {
    return Array_len((Array*)arr);
}

static inline void SymbolPtrAr_push(SymbolPtrAr *arr, Symbol *elem) {
    Symbol * *p = (Symbol **)Array_pushN((Array*)arr, 1);
    *p = elem;
    return; 
}            

#define SymbolPtrArIt_declare(var, arr)  SymbolPtrArIt var = {arr, -1, false, NULL}            

static inline bool SymbolPtrArIt_next(SymbolPtrArIt *iterator) {
    return ArrayIt_next((ArrayIt*)iterator);
}


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




// *** DO NOT MODIFY THIS FILE (see src/midiseq.in.h) generated 03/20/2018 10:23:21 ***

// *** DO NOT MODIFY THIS FILE (see src/midiseq.in.h) generated 03/20/2018 10:23:21 ***
static inline int BinFile_version(BinFile *self){return self->version;}
static inline sds BinFile_filename(BinFile *self){return self->filename;}
static inline void BinFile_setFilename(BinFile *self, sds value){self->filename = value;}
static inline sds BinFile_buffer(BinFile *self){return self->buffer;}
static inline void BinFile_setBuffer(BinFile *self, sds value){self->buffer = value;}
static inline FILE *BinFile_stream(BinFile *self){return self->stream;}
static inline void BinFile_setStream(BinFile *self, FILE *value){self->stream = value;}
#define BinFile_nullLengthFieldSizeStr "11"
#define BinFile_maxLength              2147483647
#define BinFileFlag_tag                1
#define BinFile_writeBackLength(bf, location, err) BinFile_writeBackLengthFlags(bf, location, -1, err)
#define BinFile_readLength(bf, err) BinFile_readLengthFlags(bf, NULL, err)
#define BinFile_writeLength(bf, length, err) BinFile_writeLengthFlags(bf, length, -1, err)
static inline PortFind *BinFile_portFindPayload(BinFile *self){ return (self->payload == NULL ? NULL : self->payload->portFind); }
static inline void BinFile_setPayload(BinFile *self, BinFilePayload *payload) { self->payload = payload;}

const int Midiseq_notetype   = 1;
const int Midiseq_bendtype   = 2;
const int Midiseq_cctype     = 3;
const int Midiseq_cycletype  = 4;
const int Midiseq_endgrptype = 5;

// *** DO NOT MODIFY THIS FILE (see src/midiseq.in.h) generated 03/20/2018 10:23:21 ***
#define Midiseq_newUninitialized() ((Midiseq*)sysmem_newptrclear(sizeof(Midiseq)))        
static inline bool Midiseq_useMasterClock(Midiseq *self){return self->useMasterClock;}
static inline void Midiseq_setUseMasterClock(Midiseq *self, bool value){self->useMasterClock = value;}
static inline Ticks Midiseq_sequenceLength(Midiseq *self){return self->sequenceLength;}
static inline void Midiseq_setSequenceLength(Midiseq *self, Ticks value){self->sequenceLength = value;}

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
//          {"type": "array", "typeName": "NoteEventAr", "elemName": "NoteEvent"}
//       ]      
//    }
// @end

// @type
//    {  
//       "typeName":"NoteSequence",
//       "fields":[  
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


// *** DO NOT MODIFY THIS FILE (see src/midiseq.in.h) generated 03/20/2018 10:23:21 ***
#define Pad_newUninitialized() ((Pad*)sysmem_newptrclear(sizeof(Pad)))        
static inline t_symbol *Pad_trackName(Pad *self){return self->trackName;}
static inline void Pad_setTrackName(Pad *self, t_symbol *value){self->trackName = value;}
static inline int Pad_padIndex(Pad *self){return self->padIndex;}
static inline void Pad_setPadIndex(Pad *self, int value){self->padIndex = value;}
static inline Midiseq *Pad_sequence(Pad *self){return self->sequence;}
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
static inline SequenceAr *Pad_sequenceList(Pad *self){return &self->sequenceList;}
static inline bool Pad_useMasterClock(Pad *self){return self->useMasterClock;}
static inline void PadAr_clear(PadAr *arr) {
    Array_clear((Array*)arr);
    PadAr zero = {0};
    *arr = zero;
}

static inline void PadAr_fit(PadAr *arr) {
    Array_fit((Array*)arr);
}

#define PadAr_foreach(var, arr)  for (PadArIt_declare(var, arr); PadArIt_next(&var); )            

static inline Pad *PadAr_getp(PadAr *arr, int index, Error *err) {
    Array_getCheck(arr, index, NULL, err);
    return (Pad *)Array_get((Array*)arr, index);
}

static inline void PadAr_init(PadAr *arr, int nelems) {
    Array_init((Array*)arr, nelems, sizeof(Pad), (Array_clearElement)NULL);
}

static inline int PadAr_len(PadAr *arr) {
    return Array_len((Array*)arr);
}

static inline void PadAr_push(PadAr *arr, Pad elem) {
    Pad *p = (Pad *)Array_pushN((Array*)arr, 1);
    *p = elem;
    return; 
}            

#define PadArIt_declare(var, arr)  PadArIt var = {arr, -1, false, NULL}            

static inline bool PadArIt_next(PadArIt *iterator) {
    return ArrayIt_next((ArrayIt*)iterator);
}

static inline void PadPtrAr_clear(PadPtrAr *arr) {
    Array_clear((Array*)arr);
    PadPtrAr zero = {0};
    *arr = zero;
}

#define PadPtrAr_foreach(var, arr)  for (PadPtrArIt_declare(var, arr); PadPtrArIt_next(&var); )            

static inline void PadPtrAr_init(PadPtrAr *arr, int nelems) {
    Array_init((Array*)arr, nelems, sizeof(Pad *), (Array_clearElement)NULL);
}

static inline void PadPtrAr_push(PadPtrAr *arr, Pad *elem) {
    Pad * *p = (Pad **)Array_pushN((Array*)arr, 1);
    *p = elem;
    return; 
}            

static inline void PadPtrAr_remove(PadPtrAr *arr, int index, Error *err) {
    Array_removeNCheck(arr, index, 1, err);
    Array_removeN((Array*)arr, index, 1);
}    

#define PadPtrArIt_declare(var, arr)  PadPtrArIt var = {arr, -1, false, NULL}            

static inline bool PadPtrArIt_next(PadPtrArIt *iterator) {
    return ArrayIt_next((ArrayIt*)iterator);
}



// *** DO NOT MODIFY THIS FILE (see src/midiseq.in.h) generated 03/20/2018 10:23:21 ***
#define IndexedOff_declare(name, padIndex, pitch) IndexedOff name = {(padIndex), (pitch)}
static inline void IndexedOffAr_clear(IndexedOffAr *arr) {
    Array_clear((Array*)arr);
    IndexedOffAr zero = {0};
    *arr = zero;
}

#define IndexedOffAr_declareSlice(name) IndexedOffArSlice name = {0}            

#define IndexedOffAr_foreach(var, arr)  for (IndexedOffArIt_declare(var, arr); IndexedOffArIt_next(&var); )            

static inline void IndexedOffAr_init(IndexedOffAr *arr, int nelems) {
    Array_init((Array*)arr, nelems, sizeof(IndexedOff), (Array_clearElement)NULL);
}

static inline void IndexedOffAr_remove(IndexedOffAr *arr, int index, Error *err) {
    Array_removeNCheck(arr, index, 1, err);
    Array_removeN((Array*)arr, index, 1);
}    

#define IndexedOffAr_sliceEmpty(slice) (slice.data == NULL)

#define IndexedOffAr_sliceForeach(slice) for (slice.index=0, slice.var=slice.data; slice.index < slice.len; slice.index++, slice.var++)

static inline void IndexedOffAr_truncate(IndexedOffAr *arr) {
    Array_truncate((Array*)arr);
}

#define IndexedOffArIt_declare(var, arr)  IndexedOffArIt var = {arr, -1, false, NULL}            

static inline bool IndexedOffArIt_next(IndexedOffArIt *iterator) {
    return ArrayIt_next((ArrayIt*)iterator);
}

static inline void IndexedOffAr_binInsertPadIndex(IndexedOffAr *arr, IndexedOff elem) {
    int (*compare)(IndexedOff *, IndexedOff *) = IndexedOff_cmpPadIndex;
    Array_binInsert((Array*)arr, (char*)&elem, (Array_compare)compare, true);
}            

static inline void IndexedOffAr_binRemovePadIndex(IndexedOffAr *arr, IndexedOff elem) {
    int (*compare)(IndexedOff *, IndexedOff *) = IndexedOff_cmpPadIndex;
    Array_binRemove((Array*)arr, (char*)&elem, (Array_compare)compare, true);
}        

static inline IndexedOffArSlice IndexedOffAr_binSearchPadIndex(IndexedOffAr *arr, IndexedOff elem) {
    int (*compare)(IndexedOff *, IndexedOff *) = IndexedOff_cmpPadIndex;
    IndexedOffArSlice slice = {0};
    Array_binSearch((Array*)arr, (char*)&elem, (Array_compare)compare, (ArraySlice*)&slice);
    return slice;
}


// *** DO NOT MODIFY THIS FILE (see src/midiseq.in.h) generated 03/20/2018 10:23:21 ***
#define TimedOff_declare(name, time, pitch) TimedOff name = {(time), (pitch)}
static inline void TimedOffAr_clear(TimedOffAr *arr) {
    Array_clear((Array*)arr);
    TimedOffAr zero = {0};
    *arr = zero;
}

#define TimedOffAr_foreach(var, arr)  for (TimedOffArIt_declare(var, arr); TimedOffArIt_next(&var); )            

static inline void TimedOffAr_init(TimedOffAr *arr, int nelems) {
    Array_init((Array*)arr, nelems, sizeof(TimedOff), (Array_clearElement)NULL);
}

static inline int TimedOffAr_len(TimedOffAr *arr) {
    return Array_len((Array*)arr);
}

static inline void TimedOffAr_remove(TimedOffAr *arr, int index, Error *err) {
    Array_removeNCheck(arr, index, 1, err);
    Array_removeN((Array*)arr, index, 1);
}    

static inline void TimedOffAr_removeN(TimedOffAr *arr, int index, int N, Error *err) {
    Array_removeNCheck(arr, index, N, err);
    Array_removeN((Array*)arr, index, N);
}

static inline void TimedOffAr_truncate(TimedOffAr *arr) {
    Array_truncate((Array*)arr);
}

#define TimedOffArIt_declare(var, arr)  TimedOffArIt var = {arr, -1, false, NULL}            

static inline bool TimedOffArIt_next(TimedOffArIt *iterator) {
    return ArrayIt_next((ArrayIt*)iterator);
}

static inline void TimedOffAr_binInsertTime(TimedOffAr *arr, TimedOff elem) {
    int (*compare)(TimedOff *, TimedOff *) = TimedOff_cmpTime;
    Array_binInsert((Array*)arr, (char*)&elem, (Array_compare)compare, false);
}            


// *** DO NOT MODIFY THIS FILE (see src/midiseq.in.h) generated 03/20/2018 10:23:21 ***

// *** DO NOT MODIFY THIS FILE (see src/midiseq.in.h) generated 03/20/2018 10:23:21 ***
static inline void PortFindCellAr_clear(PortFindCellAr *arr) {
    Array_clear((Array*)arr);
    PortFindCellAr zero = {0};
    *arr = zero;
}

#define PortFindCellAr_foreach(var, arr)  for (PortFindCellArIt_declare(var, arr); PortFindCellArIt_next(&var); )            

static inline PortFindCell PortFindCellAr_get(PortFindCellAr *arr, int index, Error *err) {
    PortFindCell v = {0};
    Array_getCheck(arr, index, v, err);
    memmove(&v, Array_get((Array*)arr, index), Array_elemSize((Array*)arr));
    return v;
}

static inline void PortFindCellAr_init(PortFindCellAr *arr, int nelems) {
    Array_init((Array*)arr, nelems, sizeof(PortFindCell), (Array_clearElement)NULL);
}

static inline int PortFindCellAr_len(PortFindCellAr *arr) {
    return Array_len((Array*)arr);
}

static inline void PortFindCellAr_push(PortFindCellAr *arr, PortFindCell elem) {
    PortFindCell *p = (PortFindCell *)Array_pushN((Array*)arr, 1);
    *p = elem;
    return; 
}            

#define PortFindCellArIt_declare(var, arr)  PortFindCellArIt var = {arr, -1, false, NULL}            

static inline bool PortFindCellArIt_next(PortFindCellArIt *iterator) {
    return ArrayIt_next((ArrayIt*)iterator);
}


// *** DO NOT MODIFY THIS FILE (see src/midiseq.in.h) generated 03/20/2018 10:23:21 ***
static inline void *PortFind_hub(PortFind *self){return self->hub;}
static inline void PortFind_setHub(PortFind *self, void *value){self->hub = value;}
static inline Port_anythingDispatchFunc PortFind_anythingDispatch(PortFind *self){return self->anythingDispatch;}
static inline void PortFind_setAnythingDispatch(PortFind *self, Port_anythingDispatchFunc value){self->anythingDispatch = value;}
static inline Port_intDispatchFunc PortFind_intDispatch(PortFind *self){return self->intDispatch;}
static inline void PortFind_setIntDispatch(PortFind *self, Port_intDispatchFunc value){self->intDispatch = value;}
#define PortFind_declare(name) PortFind _##name; PortFind *name = &_##name; memset(name, 0, sizeof(PortFind)); PortFind_init(name)        


// *** DO NOT MODIFY THIS FILE (see src/midiseq.in.h) generated 03/20/2018 10:23:21 ***
#define PadList_newUninitialized() ((PadList*)sysmem_newptrclear(sizeof(PadList)))        
static inline PadAr *PadList_pads(PadList *self){return &self->pads;}
static inline PadPtrAr *PadList_running(PadList *self){return &self->running;}

// *** DO NOT MODIFY THIS FILE (see src/midiseq.in.h) generated 03/20/2018 10:23:21 ***
static inline void Track_setName(Track *self, Symbol *value){self->name = value;}
static inline NoteManager *Track_noteManager(Track *self){return self->noteManager;}
static inline void Track_setNoteManager(Track *self, NoteManager *value){self->noteManager = value;}
#define TrackAr_foreach(var, arr)  for (TrackArIt_declare(var, arr); TrackArIt_next(&var); )            

static inline Track *TrackAr_getp(TrackAr *arr, int index, Error *err) {
    Array_getCheck(arr, index, NULL, err);
    return (Track *)Array_get((Array*)arr, index);
}

static inline void TrackAr_init(TrackAr *arr, int nelems) {
    Array_init((Array*)arr, nelems, sizeof(Track), (Array_clearElement)NULL);
}

static inline int TrackAr_len(TrackAr *arr) {
    return Array_len((Array*)arr);
}

static inline void TrackAr_push(TrackAr *arr, Track elem) {
    Track *p = (Track *)Array_pushN((Array*)arr, 1);
    *p = elem;
    return; 
}            

#define TrackArIt_declare(var, arr)  TrackArIt var = {arr, -1, false, NULL}            

static inline bool TrackArIt_next(TrackArIt *iterator) {
    return ArrayIt_next((ArrayIt*)iterator);
}



// *** DO NOT MODIFY THIS FILE (see src/midiseq.in.h) generated 03/20/2018 10:23:21 ***
#define TrackList_newUninitialized() ((TrackList*)sysmem_newptrclear(sizeof(TrackList)))        

// *** DO NOT MODIFY THIS FILE (see src/midiseq.in.h) generated 03/20/2018 10:23:21 ***
static inline Port *PortRef_port(PortRef *self){return self->port;}
static inline int PortRef_outlet(PortRef *self){return self->outlet;}

#define PortRef_declare(name, port, outlet)    PortRef _##name = {port, outlet}; PortRef *name = &_##name
static inline void PortRef_set(PortRef *pr, Port *port, int outlet) {
   pr->port   = port;
   pr->outlet = outlet;
}
#define PortRef_send(pr, argc, argv, err)      Port_send(PortRef_port(pr), PortRef_outlet(pr), argc, argv, err)
#define PortRef_sendInteger(pr, value, err)    Port_sendInteger(PortRef_port(pr), PortRef_outlet(pr), value, err)


// *** DO NOT MODIFY THIS FILE (see src/midiseq.in.h) generated 03/20/2018 10:23:21 ***

static inline PortRef *DropDown_portRef(DropDown *dd) {
    return &dd->portRef;
}

static inline void DropDown_setPortRef(DropDown *dd, PortRef *pr) {
   dd->portRef = *pr;
}

// *** DO NOT MODIFY THIS FILE (see src/midiseq.in.h) generated 03/20/2018 10:23:21 ***
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
static inline DropDown *Hub_cgLocalGlobalMenu(Hub *self){return &self->cgLocalGlobalMenu;}
static inline DropDown *Hub_cgInstrumentMenu(Hub *self){return &self->cgInstrumentMenu;}
static inline DropDown *Hub_cgIndexMenu(Hub *self){return &self->cgIndexMenu;}
static inline int Hub_bank(Hub *self){return self->bank;}
static inline int Hub_frame(Hub *self){return self->frame;}
static inline void Hub_setFrame(Hub *self, int value){self->frame = value;}
static inline bool Hub_grabNextTappedPad(Hub *self){return self->grabNextTappedPad;}
static inline void Hub_setGrabNextTappedPad(Hub *self, bool value){self->grabNextTappedPad = value;}
static inline int Hub_selectedPad(Hub *self){return self->selectedPad;}
static inline void Hub_setSelectedPad(Hub *self, int value){self->selectedPad = value;}
static inline RecordBuffer *Hub_recordBuffer(Hub *self){return self->recordBuffer;}
static inline SequenceAr *Hub_runningSequences(Hub *self){return &self->runningSequences;}
static inline Ticks Hub_masterClock(Hub *self){return self->masterClock;}
static inline TimedAr *Hub_queue(Hub *self){return &self->queue;}

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
