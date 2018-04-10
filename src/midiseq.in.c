
#define APIF /**/
String *stripBaseName(const char *path);

@container 
{
    "type": "array",
    "typeName": "StringPtAr",
    "elemName": "String *",
    "clearer":  "String_freep"
}
@end

APIF void String_split(String *src, const char *delim, StringPtAr *stringPtAr)
{
    static StringBody *buffer = NULL;
    if (buffer == NULL) {
        buffer = String_toStringBody(String_empty());
    }
    StringBody *body = String_toStringBody(src);
    if (buffer->len < body->len) {
        String *s = buffer->ch;
        String_resize(&s, body->len);
        buffer = String_toStringBody(s);
    }
    strncpy(buffer->ch, body->ch, body->len+1);
    StringPtAr_truncate(stringPtAr);   
    char *string = buffer->ch;
    char *token  = NULL;
    while ((token = strsep(&string, delim)) != NULL) {
        StringPtAr_push(stringPtAr, String_fmt("%s", token));
    }
    return;
}

@container    
   {       
       "type": "array",
       "typeName": "SymbolPtAr", 
       "elemName": "Symbol *",
       "binarySearch": [
           {"compare": "Symbol_cmpUnderlying", "tag": "Underlying"}
        ]   
   }
@end

APIF int Symbol_cmpUnderlying(Symbol **left, Symbol **right) 
{
    return strcmp(Symbol_cstr(*left), Symbol_cstr(*right)); 
}

#ifdef TEST_BUILD
SymbolPtAr *gSymbols = NULL;

Symbol *Symbol_gen(const char *word) 
{
    if (gSymbols == NULL) {
        gSymbols = SymbolPtAr_new(0);
    }
    Symbol s  = {word};
    Symbol **rp = SymbolPtAr_binSearchUnderlying(gSymbols, &s);
    if (rp != NULL) {
        return *rp;
    }
    Symbol *n = Mem_calloc(sizeof(Symbol));
    n->name = strdup(word);
    SymbolPtAr_binInsertUnderlying(gSymbols, n);
    return n;
}

void Symbol_freeAll() 
{
    SymbolPtAr_foreach(it, gSymbols) {
        Mem_free(*it.var);
    }
    SymbolPtAr_truncate(gSymbols);
}

#endif

@container    
   {       
       "type": "array",
       "typeName": "AtomAr", 
       "elemName": "Atom"
   }
@end

@type
{
   "typeName": "Port",
   "fields": [
         {"name": "obj",              "type": "MaxObject"},
         {"name": "inletnum",         "type": "long"},
         {"name": "proxy",            "type": "PtrAr"},
         {"name": "outlet",           "type": "PtrAr"},
         {"name": "track",            "type": "Symbol *"},
         {"name": "id",               "type": "Symbol *"},
         {"name": "intInlets",        "type": "long"},
         {"name": "intOutlets",       "type": "long"},
         {"name": "hub",              "type": "void *"},
         {"name": "anythingDispatch", "type": "Port_anythingDispatchFunc"},
         {"name": "intDispatch",      "type": "Port_intDispatchFunc"}
   ],
   "lifecycle": "manual"
}
@end


Port Port_nullImpl =
{
    {
        0
    }
};

#define Port_null (&Port_nullImpl)

APIF Port *Port_new() 
{
    return Port_null;
}
APIF void Port_init(Port *p)
{
    *p = Port_nullImpl;
}

APIF void Port_free(Port *p)
{
}

APIF void Port_clear(Port *p)
{
}


// Will parse id's of the form ev\d+ and return the \d+ number. Returns -1 otherwise
APIF int port_parseEvSymbol(Symbol *id)
{
    int r = -1;
    int consumed = 0;
    if (id == NULL) {
        return -1;
    }

    if (sscanf(Symbol_cstr(id), "ev%d%n", &r, &consumed) != 1) {
        return -1;
    }
    if (strlen(Symbol_cstr(id)) != consumed) {
        return -1;
    }
    return r;
}

APIF void Port_send(Port *self, int outletIndex, short argc, Atom *argv, Error *err)
{   
    if (self == Port_null) {
        return;
    }
#   ifndef TEST_BUILD
    Symbol *selector = Atom_toSymbol(argv + 0);
    void *out = PtrAr_get(&self->outlet, outletIndex, err);
    Error_returnVoidOnError(err);
    outlet_anything(out, selector, argc-1, argv+1);  
#   endif 
}

APIF void Port_sendInteger(Port *self, int outlet, long value) 
{
    if (self == Port_null) {
        return;
    }
#   ifndef TEST_BUILD
    Error_declare(err);
    void *out = PtrAr_get(&self->outlet, outlet, err);
    if (Error_maypost(err)) {
        return;
    }
    outlet_int(out, value);   
#   endif
}

@container    
{       
   "type": "array",
   "typeName": "MEventAr", 
   "elemName": "MEvent"   
}
@end

@container    
{       
   "type": "array",
   "typeName": "PtrAr", 
   "elemName": "void *"   
}
@end

@container    
{       
   "type": "array",
   "typeName": "SymbolPtrAr", 
   "elemName": "Symbol *"   
}
@end

@container    
{       
   "type": "array",
   "typeName": "IntAr", 
   "elemName": "int"   
}
@end



@type
{  
  "typeName": "BinFilePayload",
  "fields":[  
     {  
        "getter":"none",
        "name":"portFind",
        "setter":"none",
        "type":"PortFind *"
     }
  ]
}
@end

@type
   {  
      "typeName": "BinFile",
      "fields":[  
         {  
            "name":"version",
            "type":"int"
         },
         {  
            "name":"filename",
            "type":"String *"
         },
         {  
            "name":"buffer",
            "type":"String *"
         },
         {  
            "name":"stream",
            "type":"FILE *"
         },
         {  
            "getter":"none",
            "name":"payload",
            "setter":"none",
            "type":"BinFilePayload *"
         }
      ]
   }
@end
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

@type
   {  
      "typeName":"Midiseq",
      "fields":[  
         {  
            "name":"useMasterClock",
            "type":"bool"
         },
         {  
            "name":"sequenceLength",
            "type":"Ticks"
         },
         {  
            "name":"events",
            "type":"MEventAr"
         },
         {  
            "comment":[  
               "startTime is the time offset that t = 0 that is stored in the sequence corresponds too.",
               "Specifically, if useMasterClock is true, the startTime is updated whenever the ptr rolls",
               "off the end of the sequence, and raps around back to the beginning."
            ],
            "name":"startTime",
            "type":"Ticks"
         },
         {  
            "name":"ptr",
            "type":"int"
         }
      ]      
   }
@end


@type
   {  
      "typeName": "Pad",
      "fields":[  
         {  
            "name":"trackName",
            "type":"Symbol *"
         },
         {  
            "name":"padIndex",
            "type":"int"
         },
         {  
            "name":"sequence",
            "setter":"none",
            "type":"Midiseq *"
         },
         {  
            "name":"chokeGroupGlobal",
            "type":"bool"
         },
         {  
            "name":"chokeGroupInstrument",
            "type":"int"
         },
         {  
            "name":"chokeGroupIndex",
            "type":"int"
         },
         {  
            "name":"chokeGroup",
            "type":"int64_t"
         },
         {  
            "name":"noteReleasePending",
            "type":"bool"
         },
         {  
            "name":"inEndgroup",
            "type":"bool"
         },
         {  
            "name":"track",
            "type":"Track *"
         },
         
         // {  
         //    "name":"sequenceList",
         //    "type":"SequenceAr",
         //    "getterReturn":"pointer",
         //    "setter":"none"
         // },
         {  
            "name":"useMasterClock",
            "type":"bool"
         }
      ],
      "containers": [
         {"type": "array", "typeName": "PadAr", "elemName": "Pad"},
         //, "clearer": "Pad_clear"},
         {"type": "array", "typeName": "PadPtrAr", "elemName": "Pad *"}
      ]
   }
@end


@type
   {  
      "typeName": "IndexedOff",
      "argDeclare": 1,
      "fields":[  
         {  
            "name":"padIndex",
            "type":"int"
         },
         {  
            "name":"pitch",
            "type":"int"
         }
      ],
      "containers": [
         {
            "type": "array",
            "typeName": "IndexedOffAr", 
            "elemName": "IndexedOff",
            "binarySearch": [
               {"compare": "IndexedOff_cmpPadIndex", "multi": true, "tag": "PadIndex"}
            ]
         }
      ]
   }
@end

@type
   {  
      "typeName":"TimedOff",
      "argDeclare":1,
      "fields":[  
         {  
            "name":"time",
            "type":"Ticks"
         },
         {  
            "name":"pitch",
            "type":"int"
         }
      ],
      "containers": [
         {
            "type": "array",
            "typeName": "TimedOffAr", 
            "elemName": "TimedOff",
            "binarySearch": [
               {"compare": "TimedOff_cmpTime", "multi": true, "tag": "Time"}
            ]
         }
      ]
   }
@end

@type
   {  
      "typeName":"NoteManager",
      "fields":[  
         {  
            "name":"pending",
            "type":"TimedOffAr"
         },
         {  
            "name":"endgroups",
            "type":"IndexedOffAr"
         },
         {  
            "name":"output",
            "type":"Port *"
         },
         {  
            "name":"atoms",
            "type":"Atom *"
         }
      ]
   }
@end


@type
   {  
      "typeName": "PadList",
      "fields":[  
         {  
            "getterReturn":"pointer",
            "name":"pads",
            "setter":"none",
            "type":"PadAr"
         },
         {  
            "getterReturn":"pointer",
            "name":"running",
            "setter":"none",
            "type":"PadPtrAr"
         }
      ]
   }
@end

@type
   {  
      "typeName": "Track",
      "fields":[  
         {  
            "name":"name",
            "type":"Symbol *"
         },
         {  
            "name":"noteManager",
            "type":"NoteManager *"
         }
      ],
      "containers": [
         {
            "type": "array",
            "typeName": "TrackAr", 
            "elemName": "Track"
            //,
            //"clearer": "Track_clear"
         }
      ]
   }
@end


@type
   {  
      "typeName": "TrackList",
      "fields":[  
         {  
            "getterReturn":"pointer",
            "name":"list",
            "setter":"none",
            "type":"TrackAr"
         }
      ]
   }
@end

@type
   {  
      "typeName": "PortRef",
      "fields":[  
         {  
            "name":"port",
            "type":"Port *",
            "lifecycle": "unmanaged"
         },
         {  
            "name":"outlet",
            "type":"int"
         }
      ]
   }
@end

#define PortRef_declare(name, port, outlet)    PortRef _##name = {port, outlet}; PortRef *name = &_##name
static inline void PortRef_set(PortRef *pr, Port *port, int outlet) {
   pr->port   = port;
   pr->outlet = outlet;
}
#define PortRef_send(pr, argc, argv, err)      Port_send(PortRef_port(pr), PortRef_outlet(pr), argc, argv, err)
#define PortRef_sendInteger(pr, value, err)    Port_sendInteger(PortRef_port(pr), PortRef_outlet(pr), value, err)
PortRef PortRef_nullImpl = {Port_null, 0};
#define PortRef_null  &PortRef_nullImpl
APIF static inline Symbol *PortRef_track(PortRef *self)
{ 
    return Port_track(self->port);
}


APIF int PortRef_cmp(PortRef *left, PortRef *right) 
{
    if (left->port < right->port) {
        return -1;
    } else if (left->port > right->port) {
        return 1;
    } else if (left->outlet < right->outlet) {
        return -1;
    } else if (left->outlet > right->outlet) {
        return 1;
    }
    return 0;
}



@type
   {  
      "typeName": "DropDown",
      "fields":[  
         {  
            "getterReturn":"pointer",
            "name":"table",
            "setter":"none",
            "type":"SymbolPtrAr"
         },
         {  
            "name":"selected",
            "setter":"none",
            "type":"int"
         },
         {  
            "getter":"none",
            "name":"portRef",
            "setter":"none",
            "type":"PortRef"
         }
      ]
   }
@end

static inline PortRef *DropDown_portRef(DropDown *dd) {
    return &dd->portRef;
}

static inline void DropDown_setPortRef(DropDown *dd, PortRef *pr) {
   dd->portRef = *pr;
}

//
// D R O P   D O W N
//

APIF void DropDown_build(DropDown *dd, const char **table, PortRef *pr) {
    SymbolPtrAr_init(&dd->table, 0);
    const char **ptr = table;
    while (*ptr) {
        Symbol *s = Symbol_gen(*ptr);
        SymbolPtrAr_push(&dd->table, s);
        ptr++;
    }
    DropDown_setPortRef(dd, pr);
    return;
}

APIF void DropDown_buildCGLocalGlobal(DropDown *dd, PortRef *pr) {
    const char *t[] = {
        "local",
        "global",
        NULL
    };
    DropDown_build(dd, t, pr);
}

APIF void DropDown_buildCGInstrument(DropDown *dd, PortRef *pr) {
    const char *t[] = {
        "none",
        "lead",
        "rhythm",
        "piano",
        "bass",
        "drums",
        NULL,
    };
    DropDown_build(dd, t, pr);
}

APIF void DropDown_buildCGIndex(DropDown *dd, PortRef *pr) {
    const char *t[] = {
        "none",
        "1",
        "2",
        "3",
        "4",
        "5",
        "6",
        "7",
        "8",
        "9",
        "10",
        "11",
        "12",
        "13",
        "14",
        "15",
        "16",
        NULL
    };
    DropDown_build(dd, t, pr);
}

// APIF void DropDown_clear(DropDown *dd) {
//     SymbolPtrAr_clear(&dd->table);
// }

// APIF void DropDown_free(DropDown *dd) {
//     DropDown_clear(dd);
//     Mem_free(dd);
// }

APIF void DropDown_updateSelected(DropDown *dd, Error *err) {
    Symbol *s = SymbolPtrAr_get(&dd->table, dd->selected, err);
    Error_returnVoidOnError(err);
    Atom a[2] = {
        Atom_fromSymbol(Symbol_gen("set")),
        Atom_fromSymbol(s)
    };
    PortRef_send(DropDown_portRef(dd), 2, a, err);
}

APIF void DropDown_setSelected(DropDown *dd, int selected, Error *err) {
    if (selected < 0 || selected >= SymbolPtrAr_len(&dd->table)) {
        Error_format(err, "Index out of range (%d, %d)", selected, SymbolPtrAr_len(&dd->table));
        return;
    }
    dd->selected = selected;
}

APIF void DropDown_initializeMenu(DropDown *dd, Error *err) {
    Atom clear = Atom_fromSymbol(Symbol_gen("clear"));
    Atom append = Atom_fromSymbol(Symbol_gen("append"));

    PortRef_send(&dd->portRef, 1, &clear, err);
    Error_returnVoidOnError(err);

    SymbolPtrAr_foreach(it, &dd->table) {
        Atom a[2] = {append, Atom_fromSymbol(*it.var)};
        PortRef_send(&dd->portRef, 2, a, err);
        Error_returnVoidOnError(err);        
    }
}
@type
   {  
      "typeName": "Hub",
      "fields":[  
         {  
            "name":"padList",
            "type":"PadList *"
         },
         {  
            "name":"trackList",
            "type":"TrackList *"
         },
         {  
            "name":"currBankPort",
            "type":"Port *"
         },
         {  
            "name":"currFramePort",
            "type":"Port *"
         },
         {  
            "name":"selBankPort",
            "type":"Port *"
         },
         {  
            "name":"selFramePort",
            "type":"Port *"
         },
         {  
            "name":"selPadPort",
            "type":"Port *"
         },
         {  
            "name":"chokeGroupPort",
            "type":"Port *"
         },
         {  
            "getterReturn":"pointer",
            "name":"cgLocalGlobalMenu",
            "setter":"none",
            "type":"DropDown"
         },
         {  
            "getterReturn":"pointer",
            "name":"cgInstrumentMenu",
            "setter":"none",
            "type":"DropDown"
         },
         {  
            "getterReturn":"pointer",
            "setter":"none",
            "name":"cgIndexMenu",
            "type":"DropDown"
         },
         {  
            // bank varies from 0-infinity
            "name":"bank",
            "type":"int"
         },
         {  
            // frame varies from 0-7
            "name":"frame",
            "type":"int"
         },
         {  
            // true if the next padIndex tapped should be written into selectedPad
            "name":"grabNextTappedPad",
            "type":"bool"
         },
         {  
            "comment":"which pad has been selected",
            "name":"selectedPad",
            "type":"int"
         },
         {
            "name": "arguments",
            "type": "Arguments"
         },
         {
            "name": "dispatcher",
            "type": "DispatchPtAr",
            "getterReturn":"pointer",
            "setter":"none"
         },

         // {
         //    "name": "recordBuffer",
         //    "type": "RecordBuffer *"
         // },
         
         // {
         //    "name": "runningSequences",
         //    "type": "SequenceAr",
         //    "getterReturn":"pointer",
         //    "setter":"none"
         // },
         {
            "name": "masterClock",
            "type": "Ticks"
         }
         //,
         // {
         //    "name":"queue",
         //    "type":"TimedAr",
         //    "getterReturn":"pointer",
         //    "setter":"none"
         // }
         
      ]
   }

@end

@header
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
// #include "shared.c"
@end

//
// Memory allocation Notes. These are the functions that are used in sdsalloc.h
//

// malloc
//          t_ptr sysmem_newptr	(long size)
// realloc
//          t_ptr sysmem_resizeptr	(void *ptr, long newsize)
// calloc
//          t_ptr sysmem_newptrclear(long size)
// free
//          void sysmem_freeptr	(	void * 	ptr	)

//
// U t i l i t y
//
APIF int Midiseq_convertIntFileLine(const char *src, Error *err, const char *function, const char *file, int line)
{
    errno = 0;
    long v = strtol(src, NULL, 10);
    if (errno != 0) {
        Error_formatFileLine(err, function, file, line,
            String_fmt("Failed to convert int error code %s",
            (errno == EINVAL ? "EINVAL" : errno == ERANGE ? "ERANGE" : "Unknown")));

    }
    return v;
}


#define Midiseq_convertInt(src, err) Midiseq_convertIntFileLine(src, err, __func__, __FILE__, __LINE__)

//
// M I D I S E Q
//
#define Midiseq_maxLineLength 1024

// Create new empty midi sequence

APIF void Midiseq_userInit(Midiseq *self)
{
    self->sequenceLength = 480*4;

    MEvent cell = {0};
    cell.t = 0;
    cell.type = Midiseq_endgrptype;
    MEventAr_push(&self->events, cell);
    
    cell.t = self->sequenceLength;
    cell.type = Midiseq_cycletype;
    MEventAr_push(&self->events, cell);

    MEventAr_fit(&self->events);
}



APIF void Midiseq_toBinFile(Midiseq *mseq, BinFile *bf, Error *err) {
    BinFile_writeTag(bf, "midiseq", err);
    Error_returnVoidOnError(err);

    BinFile_writeBool(bf, Midiseq_useMasterClock(mseq), err);
    Error_returnVoidOnError(err);

    BinFile_writeTicks(bf, Midiseq_sequenceLength(mseq), err);
    Error_returnVoidOnError(err);

    BinFile_writeInteger(bf, MEventAr_len(&mseq->events), err);
    Error_returnVoidOnError(err);

    BinFile_writeTag(bf, "midiseq_start_data", err);
    Error_returnVoidOnError(err);

    MEventAr_foreach(it, &mseq->events) {
        MEvent cell = *it.var;
        if (fprintf(BinFile_stream(bf), " %u %u %lld", MEvent_type(cell), MEvent_bendValue(cell), MEvent_t(cell)) < 0) {
            Error_format(err, "Midiseq_toBinFile failed at fprintf[1] while writing %s", BinFile_filename(bf));
            return;
        }

        if (MEvent_type(cell) == Midiseq_notetype) {
            if (fprintf(BinFile_stream(bf), " %lld", MEvent_noteDuration(cell)) < 0) {
                Error_format(err, "Midiseq_toBinFile failed at fprintf[2] while writing %s", BinFile_filename(bf));
                return;       
            }
        }
    }
    BinFile_writeTag(bf, "midiseq_end_data", err);
    Error_returnVoidOnError(err);
}


APIF Midiseq *Midiseq_fromBinFile(BinFile *bf, Error *err) {
    Midiseq *mseq = Midiseq_new();
    Midiseq_fromBinFileUnititialized(mseq, bf, err);
    if (Error_iserror(err)) {
        Mem_free(mseq);
        return NULL;
    }
    return mseq;
}

APIF void Midiseq_fromBinFileUnititialized(Midiseq *mseq, BinFile *bf, Error *err) {
    BinFile_verifyTag(bf, "midiseq", err);
    Error_returnVoidOnError(err);

    Midiseq_setUseMasterClock(mseq, BinFile_readBool(bf, err));
    Error_returnVoidOnError(err);

    Midiseq_setSequenceLength(mseq, BinFile_readTicks(bf,  err));
    Error_returnVoidOnError(err);

    long length = BinFile_readInteger(bf, err);
    Error_returnVoidOnError(err);

    BinFile_verifyTag(bf, "midiseq_start_data", err);
    Error_returnVoidOnError(err);

    MEventAr_init(&mseq->events, 0);
    for (int i = 0; i < length; i++) {
        MEvent cell = {0};
        unsigned int type = 0, bendVal = 0;
        if (fscanf(BinFile_stream(bf), " %u %u %lld", &type, &bendVal, &MEvent_t(cell)) != 3) {
            Error_format(err, "Midiseq_fromBinFile failed at fscanf[1] while reading %s", BinFile_filename(bf));
            goto END;
        }
        MEvent_type(cell)      = type;
        MEvent_bendValue(cell) = bendVal;

        if (MEvent_type(cell) == Midiseq_notetype) {
            if (fscanf(BinFile_stream(bf), " %lld", &MEvent_noteDuration(cell)) != 1) {
                Error_format(err, "Midiseq_fromBinFile failed at fscanf[2] while reading %s", BinFile_filename(bf));
                goto END;
            }
        }
        MEventAr_push(&mseq->events, cell);
    }
    MEventAr_fit(&mseq->events);
    BinFile_verifyTag(bf, "midiseq_end_data", err);
    Error_gotoLabelOnError(err, END);
    return;

  END:
    MEventAr_clear(&mseq->events);
    return;
}

APIF Midiseq *Midiseq_newNote(int pitch)
{
    Midiseq *mseq = Midiseq_new();
    MEventAr_truncate(&mseq->events);

    mseq->sequenceLength = 480*4;
    
    MEvent zero = {
        0
    }
    , cell = {
        0
    };

    MEvent_t(cell)    = 0;
    MEvent_type(cell) = Midiseq_endgrptype;
    MEventAr_push(&mseq->events, cell);

    cell = zero;
    MEvent_t(cell)            = 0;
    MEvent_type(cell)         = Midiseq_notetype;
    MEvent_notePitch(cell)    = pitch;
    MEvent_noteVelocity(cell) = 90;
    MEvent_noteDuration(cell) = 480;
    MEventAr_push(&mseq->events, cell);

    cell              = zero;
    MEvent_t(cell)    = mseq->sequenceLength;
    MEvent_type(cell) = Midiseq_cycletype;
    MEventAr_push(&mseq->events, cell);

    MEventAr_fit(&mseq->events);

    return mseq;
}

APIF int Midiseq_len(Midiseq *mseq)
{
    // REMEMBER: because of cycle and endgroup, every midi sequence has at least 2 elements.
    return MEventAr_len(&mseq->events);
}


APIF void Midiseq_push(Midiseq *mseq, MEvent cell)
{
    MEventAr_push(&mseq->events, cell);
}


APIF MEvent *Midiseq_get(Midiseq *mseq, int index, Error *err)
{
    return MEventAr_getp(&mseq->events, index, err);
}


bool Midiseq_pathsAllocated = false;
String *Midiseq_midiCsvExecPath = NULL;
String *Midiseq_csvMidiExecPath = NULL;

APIF void Midiseq_setMidicsvExecPath()
{
    if (!Midiseq_pathsAllocated) {
        Midiseq_midiCsvExecPath = String_fmt("%s/packages/midicsv-1.1/midicsv", CSEQ_HOME);
        Midiseq_csvMidiExecPath = String_fmt("%s/packages/midicsv-1.1/csvmidi", CSEQ_HOME);
        Midiseq_pathsAllocated = true;
    }
}


APIF void Midiseq_dblog(Midiseq *mseq)
{
    dblog("Midiseq %p", mseq);
    MEventAr_foreach(it, &mseq->events) {
        MEvent cell = *it.var;
        switch (MEvent_type(cell)) {
            case Midiseq_notetype:
                dblog("    %15lld note %15ld %15ld %15ld", MEvent_t(cell),
                    (long)MEvent_notePitch(cell), (long)MEvent_noteVelocity(cell), (long)MEvent_noteDuration(cell));
                break;
            case Midiseq_bendtype:
                dblog("    %15lld bend", MEvent_t(cell));
                break;
            case Midiseq_cctype:
                dblog("    %15lld cc", MEvent_t(cell));
                break;
            case Midiseq_endgrptype:
                dblog("    %15lld endgroup", MEvent_t(cell));
                break;
            case Midiseq_cycletype:
                dblog("    %15lld cycle", MEvent_t(cell));
                break;
        }
    }
    return;
}

//
// F R O M     F I L E
//
APIF int midiseq_tokenize(FILE *fd, StringPtAr **ret, Error *err)
{
    static String *buffer       = NULL;
    static StringPtAr *arBuffer = NULL;
    if (buffer == NULL) {
        buffer   = String_empty();
        arBuffer = StringPtAr_new(0);
    }
    if (!String_readline(&buffer, fd, err)) {
        return 0;
    }
    String_split(buffer, ",", arBuffer);
    StringPtAr_foreach(it, arBuffer) {
        String_trim(it.var);
    }
    *ret = arBuffer;
    return 1;
}


APIF int Midiseq_assignLength(Midiseq *mseq)
{
    const long ppqn = 480;
    const long measureLength = ppqn*4;
    if (Midiseq_len(mseq) == 0) {
        mseq->sequenceLength = measureLength;
        return 0;
    }

    Ticks end = 0;
    MEventAr_foreach(it, &mseq->events) {
        long t = it.var->t;
        if (it.var->type == Midiseq_notetype) {
            t += it.var->duration;
        }
        if (t > end) {
            end = t;
        }
    }

    mseq->sequenceLength = (end/measureLength)*measureLength + (end % measureLength == 0 ? 0 : measureLength);
    return 0;
}


APIF int Midiseq_insertCell(Midiseq *mseq, MEvent cell, int index, Error *err)
{
    MEventAr_insert(&mseq->events, index, cell, err);
    if (Error_iserror(err)) {
        return 1;
    }
    return 0;
}


APIF void Midiseq_insertEndgroup(Midiseq *mseq, Error *err)
{
    MEvent cell = {0};
    cell.type = Midiseq_endgrptype;

    if (MEventAr_len(&mseq->events) < 2) {
        cell.t = mseq->sequenceLength;
        MEventAr_rforeach(it, &mseq->events) {
            if (it.var->type == Midiseq_notetype) {
                cell.t = it.var->t;
                MEventAr_insert(&mseq->events, 0, cell, err);
                return;   
            }
        }
        MEventAr_push(&mseq->events, cell);
        return;
    }

    MEventAr_rforeach(it, &mseq->events) {
        if (it.var->type == Midiseq_notetype) {
            cell.t = it.var->t;
            int index = it.index;
            while (MEventArRIt_next(&it)) {
                if (cell.t != it.var->t) {
                    break;
                }
                index++;
            }
            if (index < 0) {
                index = 0;
            }
            Midiseq_insertCell(mseq, cell, index, err);
            return;
        }
    }

    MEvent e = MEventAr_get(&mseq->events, 0, err);
    Error_returnVoidOnError(err);
    cell.t = e.t;
    Midiseq_insertCell(mseq, cell, 0, err);
    Error_returnVoidOnError(err);
    return;
}


APIF int Midiseq_start(Midiseq *mseq, Ticks startTime, Ticks currentTime, bool useMasterClock, Error *err)
{
    if (startTime > currentTime) {
        Error_format0(err, "INTERNAL ERROR");
        return 1;
    }
    Ticks adj            = mseq->sequenceLength*((currentTime-startTime)/mseq->sequenceLength);
    mseq->startTime      = startTime + adj;
    mseq->useMasterClock = useMasterClock;
    mseq->ptr            = 0;
    if (useMasterClock) {
        if (Midiseq_fastfwrd(mseq, currentTime, err)) {
            return 1;
        }
    }
    return 0;
}


APIF void Midiseq_stop(Midiseq *mseq)
{
    mseq->startTime = 0;
    return;
}


enum
{
    Midiseq_nextEventErrored  = 1,
    Midiseq_nextEventComplete = 2,
    Midiseq_nextEventContinue = 3,
    Midiseq_nextEventBreak    = 4,
};

// Midiseq_nextevent always writes the current cell into the cell pointer. If the event
// stored in cell happened before until, then (a) the sequence is advanced and (b) the
// function returns 1. Otherwise 0 is returned and the sequence is left alone.
APIF int Midiseq_nextevent(Midiseq *mseq, Ticks until, MEvent *cell, Error *err)
{
    if (mseq->startTime == 0) {
        Error_format0(err, "Called nextevent on stoped sequence");
        return Midiseq_nextEventErrored;
    }
    if (mseq->ptr >= Midiseq_len(mseq)) {
        // This is the case when the entire sequence has been played, and this
        // is NOT a useMasterClock sequence. If useMasterClock is true mseq->ptr should
        // never satisfy the if criterion.
        *cell = MEventAr_get(&mseq->events, MEventAr_last(&mseq->events), err);
        if (Error_iserror(err)) {
            return Midiseq_nextEventErrored;
        }
        return Midiseq_nextEventComplete;
    }

    MEvent c = MEventAr_get(&mseq->events, mseq->ptr, err);
    if (Error_iserror(err)) {
        return Midiseq_nextEventErrored;
    }

    Ticks t = c.t + mseq->startTime;
    Ticks diff = t-until >= 0 ? t-until : until-t;

    if ( (diff-1)/mseq->sequenceLength > 0) {
        Error_format(err, "INTERNAL ERROR %lld %lld %lld", diff, mseq->sequenceLength, diff/mseq->sequenceLength);
        return Midiseq_nextEventErrored;
    }

    *cell = c;
    cell->t = t;
    if (t > until) {
        return Midiseq_nextEventBreak;
    }

    mseq->ptr++;
    if (mseq->ptr >= Midiseq_len(mseq) && mseq->useMasterClock) {
        mseq->ptr        = 0;
        mseq->startTime += mseq->sequenceLength;
    }
    return Midiseq_nextEventContinue;
}


APIF int Midiseq_fastfwrd(Midiseq *mseq, long t, Error *err)
{
    if (mseq->startTime == 0) {
        return 1;
    }

    MEventAr_foreach(it, &mseq->events) {
        if (it.var->t + mseq->startTime >= t) {
            mseq->ptr = it.index;
            return 0;
        }
    }

    mseq->ptr = 0;
    return 0;
}


APIF Midiseq *Midiseq_fromfile(const char *fullpath, Error *err)
{
    char tempfile[] = "/tmp/MidiseqMaxMSPXXXXXX";
    FILE *fd = NULL;
    bool allOK = false;
    Midiseq *mseq = (Midiseq*)Mem_calloc(sizeof(Midiseq));
    Midiseq_init(mseq);
    MEventAr_truncate(&mseq->events);

    // Call midicsv. To do this we create a new destination file, then route our output to it
    String *buffer = NULL;
    int tempFd = mkstemp(tempfile);
    if (tempFd < 0) {
        Error_format0(err, "Failed to create temp file");
        goto END;
    }
    close(tempFd);

    buffer = String_fmt("'%s' '%s' > '%s'", Midiseq_midiCsvExecPath, fullpath, tempfile);    
    int exitCode = system(buffer);
    if (exitCode != 0) {
        Error_format(err, "Failed '%s' with exit code %d", buffer, exitCode);
        goto END;
    }

    // Open the result file and parse away
    fd = fopen(tempfile, "r");
    if (fd == NULL) {
        Error_format(err, "Failed to open temp file '%s'", tempfile);
        goto END;
    }

    int desiredPPQN = 480;
    float tickFactor = 1.0;

    // ons[i] holds the index-1 of the last note-on of pitch i. Or zero if there is no pending note-on
    int ons[128] = {0};
    int linenum = 0;
    while (true) {
        StringPtAr *fieldsAr = NULL;
        if (!midiseq_tokenize(fd, &fieldsAr, err)) {
            if (Error_iserror(err)) {
                goto END;
            }
            break;
        }
        linenum++;

        if (StringPtAr_len(fieldsAr) < 3) {
            Error_format(err, "Not enough fields in midicsv file '%s' line %d", tempfile, linenum);
            goto END;
        }

        int nfields   = StringPtAr_len(fieldsAr);

        // THIS IS AWEFUL. IMPORTANT you can't touch fields after you call _push or any other method that might reallocate.
        char **fields = (char**)fieldsAr->data;
        if (Error_iserror(err)) {
            goto END;
        }

        MEvent cell = {0};
        cell.t = (long)(tickFactor*Midiseq_convertInt(fields[1], err));
        if (Error_iserror(err)) {
            goto END;
        }

        const char *typ = fields[2];

        bool isOn = strcmp(typ, "Note_on_c") == 0;
        bool isOff = strcmp(typ, "Note_off_c") == 0;
        if ( isOn || isOff ) {
            if (nfields < 6) {
                Error_format(err, "Bad Note_on_c file '%s' line %d", tempfile, linenum);
                goto END;
            }
            long pitch    = Midiseq_convertInt(fields[4], err);
            long velocity = Midiseq_convertInt(fields[5], err);
            if (Error_iserror(err)) {
                goto END;
            }
            if (velocity == 0) {
                isOn = false;
                isOff = true;
            }

            if (isOn) {
                cell.type = Midiseq_notetype;
                cell.b.b[0]  = (uint8_t)pitch;
                cell.b.b[1]  = (uint8_t)velocity;
                if (ons[pitch] != 0) {
                    Error_format(err, "Found an unbalanced NOTE-ON: while working on` file '%s' line %d", tempfile, linenum);
                    goto END;
                }
                Midiseq_push(mseq, cell);
                ons[pitch] = Midiseq_len(mseq);
            }
            else {
                if (ons[pitch] == 0) {
                    Error_format(err, "Found an unmatched note-off: while working on` file '%s' line %d", tempfile, linenum);
                    goto END;
                }
                int index = ons[pitch]-1;
                if (index >= Midiseq_len(mseq)) {
                    Error_format0(err, "INTERNAL ERROR");
                    goto END;
                }
                MEvent *c = Midiseq_get(mseq, index, err);
                if (Error_iserror(err)) {
                    goto END;
                }
                c->duration = cell.t - c->t;
                ons[pitch] = 0;
            }
        }
        else if (strcmp(typ, "Pitch_bend_c") == 0) {
            if (nfields < 5) {
                Error_format(err, "Bad Pitch_bend_c file '%s' line %d", tempfile, linenum);
                goto END;
            }
            long value = Midiseq_convertInt(fields[4], err);
            if (Error_iserror(err)) {
                goto END;
            }
            cell.type   = Midiseq_bendtype;
            cell.b.bend = value;
            Midiseq_push(mseq, cell);
        }
        else if (strcmp(typ, "Control_c") == 0) {
            if (nfields < 5) {
                Error_format(err, "Bad Control_c file '%s' line %d", tempfile, linenum);
                goto END;
            }
            long cc = Midiseq_convertInt(fields[4], err);
            long val  = Midiseq_convertInt(fields[5], err);
            if (Error_iserror(err)) {
                goto END;
            }
            cell.type = Midiseq_cctype;
            cell.b.b[0]  = (uint8_t)cc;
            cell.b.b[1]  = (uint8_t)val;
            Midiseq_push(mseq, cell);
        }
        else if (strcmp(typ, "Header") == 0) {
            if (nfields < 6) {
                Error_format(err, "Bad Header file '%s' line %d", tempfile, linenum);
                goto END;
            }
            long ppqn = Midiseq_convertInt(fields[5], err);
            if (Error_iserror(err)) {
                goto END;
            }
            tickFactor = (float)(desiredPPQN)/(float)(ppqn);
        }
        fields = NULL;
        nfields = 0;
    }

    // Compute length and install cycle and end group
    Midiseq_assignLength(mseq);
    MEvent cycle = {0};
    cycle.t = mseq->sequenceLength;
    cycle.type = Midiseq_cycletype;
    Midiseq_push(mseq, cycle);
    Midiseq_insertEndgroup(mseq, err);
    if (Error_iserror(err)) {
        Error_clear(err);
        goto END;
    }
    allOK = true;

    END:
    if (buffer != NULL) {
        String_free(buffer);
    }
    if (fd != NULL) {
        fclose(fd);
    }
    
    unlink(tempfile);

    if (allOK) {
        return mseq;
    }


    // Error state
    Midiseq_free(mseq);
    return NULL;
}

//
// P A T C H E R    F I N D
//
@type
   {  
      "typeName":"PortFindCell",
      "fields":[  
         {  
            "name":"reciever",
            "type":"Port *"
         },
         {  
            "name":"varname",
            "type":"Symbol *"
         }
      ],
      "containers": [
         {
            "type": "array",
            "typeName": "PortFindCellAr", 
            "elemName": "PortFindCell"
         }
      ]
   }
@end

@type
   {  
      "typeName": "PortFind",
      "fields":[  
         {  
            "name":"objects",
            "type":"PortFindCellAr"
         },
         {  
            "name":"hub",
            "type":"void *"
         },
         {  
            "name":"anythingDispatch",
            "type":"Port_anythingDispatchFunc"
         },
         {  
            "name":"intDispatch",
            "type":"Port_intDispatchFunc"
         }
      ]
   }
@end

#define PortFind_declare(name) PortFind _##name; PortFind *name = &_##name; memset(name, 0, sizeof(PortFind)); PortFind_init(name)        


#ifndef TEST_BUILD
APIF long PortFind_iterator(PortFind *pf, MaxObject *targetBox)
{
    MaxObject *obj = jbox_get_object(targetBox);
    if (Symbol_gen("Port") != object_classname(obj)) {
        return 0;
    }

    Symbol *varname = object_attr_getsym(targetBox, Symbol_gen("varname"));
    if (varname == NULL) {
        varname = Symbol_gen("unknown");
    }

    PortFindCell pfc = {0};
    Port *port          = (Port*)obj;
    pfc.reciever        = port;
    pfc.varname         = varname;
    PortFindCellAr_push(&pf->objects, pfc);

    Port_setHub(port, PortFind_hub(pf));
    Port_setAnythingDispatch(port, PortFind_anythingDispatch(pf));
    Port_setIntDispatch(port, PortFind_intDispatch(pf));

    return 0;
}

APIF int PortFind_discover(PortFind *pf, MaxObject *sourceMaxObject, void *hub, Error *err)
{
    PortFind_setHub(pf, hub);
    PortFind_setAnythingDispatch(pf, (Port_anythingDispatchFunc)Hub_anythingDispatch);
    PortFind_setIntDispatch(pf, (Port_intDispatchFunc)Hub_intDispatch);

    MaxObject *patcher = NULL;
    long result       = 0;
    t_max_err maxErr = object_obex_lookup(sourceMaxObject, Symbol_gen("#P"), &patcher);
    if (maxErr != MAX_ERR_NONE) {
        Error_format(err, "Failed object_obex_lookup (%s)", Error_maxErrToString(maxErr));
        return 0;
    }
    object_method(patcher, Symbol_gen("iterate"), PortFind_iterator, (void *)pf, PI_WANTBOX | PI_DEEP, &result);

    PortFind_setHub(pf, NULL);
    PortFind_setAnythingDispatch(pf, NULL);
    PortFind_setIntDispatch(pf, NULL);

    return 0;
}

#else 
APIF long PortFind_iterator(PortFind *pf, MaxObject *targetBox)
{
    return 0;
}
APIF int PortFind_discover(PortFind *pf, MaxObject *sourceMaxObject, void *hub, Error *err)
{
    return 0;
}
#endif

#ifdef TEST_BUILD
APIF void PortFind_pushPortFindCell(PortFind *self, PortFindCell cell)
{
    PortFindCellAr_push(&self->objects, cell);
}
#endif

APIF Port *PortFind_findByVarname(PortFind *pf, Symbol *symbol)
{
    PortFindCellAr_foreach(it, &pf->objects) {
        if (it.var->varname == symbol) {
            return it.var->reciever;
        }
    }
    return Port_null;
}


APIF Port *PortFind_findByTrack(PortFind *pf, Symbol *symbol)
{
    PortFindCellAr_foreach(it, &pf->objects){
        if (it.var->reciever->track == symbol) {
            return it.var->reciever;
        }
    }
    return Port_null;
}


APIF Port *PortFind_findById(PortFind *pf, Symbol *symbol)
{
    PortFindCellAr_foreach(it, &pf->objects){
        if (Port_id(it.var->reciever) == symbol) {
            return it.var->reciever;
        }
    }
    return Port_null;
}


APIF int PortFind_portCount(PortFind *pf)
{
    return PortFindCellAr_len(&pf->objects);
}


APIF Port *PortFind_findByIndex(PortFind *pf, int index, Error *err)
{
    PortFindCell cell = PortFindCellAr_get(&pf->objects, index, err);
    if (Error_iserror(err)) {
        return Port_null;
    }
    
    return cell.reciever;
}

APIF Outlet *PortFind_createOutlet(PortFind *self, OutletSpecifier *spec) 
{
    Port *port = PortFind_findByTrack(self, spec->track);

    if (spec->parameter == Symbol_gen("*note")) {
        NoteOutlet *outlet = NoteOutlet_newBuild(port);
        return NoteOutlet_castToOutlet(outlet);
    } else if (spec->parameter == Symbol_gen("*bend")) {
        BendOutlet *outlet = BendOutlet_newBuild(port);
        return BendOutlet_castToOutlet(outlet);
    } else if (spec->parameter == Symbol_gen("*cc")) {
        CcOutlet *outlet = CcOutlet_newBuild(port, spec->paramIndex);
        return CcOutlet_castToOutlet(outlet);
    }
    
    return NullOutlet_castToOutlet(NullOutlet_new());
}


//
// P A D
//

APIF void Pad_setSequence(Pad *pad, Midiseq *midi)
{
    if (Pad_sequence(pad) != NULL) {
        Midiseq_free(Pad_sequence(pad));
    }
    pad->sequence = midi;
}

APIF void Pad_toBinFile(Pad *pad, BinFile *bf, Error *err) {
    BinFile_writeSymbol(bf, Pad_trackName(pad), err);
    Error_returnVoidOnError(err);    

    BinFile_writeInteger(bf, Pad_padIndex(pad), err);
    Error_returnVoidOnError(err);    

    Midiseq_toBinFile(Pad_sequence(pad), bf, err);
    Error_returnVoidOnError(err);

    BinFile_writeBool(bf, Pad_chokeGroupGlobal(pad), err);
    Error_returnVoidOnError(err);

    BinFile_writeInteger(bf, Pad_chokeGroupInstrument(pad), err);
    Error_returnVoidOnError(err);

    BinFile_writeInteger(bf, Pad_chokeGroupIndex(pad), err);
    Error_returnVoidOnError(err);
}

APIF Pad *Pad_fromBinFile(BinFile *bf, Error *err) {
    Pad *pad = Pad_new();
    Pad_fromBinFileUninitialized(pad, bf, err);
    if (Error_iserror(err)) {
        Mem_free(pad);
        return NULL;
    }
    return pad;
}

APIF void Pad_fromBinFileUninitialized(Pad *pad, BinFile *bf, Error *err) {
    Pad_setTrackName(pad, BinFile_readSymbol(bf, err));
    Error_returnVoidOnError(err);

    Pad_setPadIndex(pad, BinFile_readInteger(bf, err));
    Error_returnVoidOnError(err);

    Pad_setSequence(pad, Midiseq_fromBinFile(bf, err));
    Error_returnVoidOnError(err);    

    Pad_setChokeGroupGlobal(pad, BinFile_readBool(bf, err));
    Error_returnVoidOnError(err);

    Pad_setChokeGroupInstrument(pad, BinFile_readInteger(bf, err));
    Error_returnVoidOnError(err);

    Pad_setChokeGroupIndex(pad, BinFile_readInteger(bf, err));
    Error_returnVoidOnError(err);
}

APIF void Pad_computeChokeGroup(Pad *pad) {
    if (!Pad_chokeGroupGlobal(pad) && Pad_chokeGroupInstrument(pad) == 0 && Pad_chokeGroupIndex(pad) == 0) {
        Pad_setChokeGroup(pad, 0);
        return;    
    }

    int64_t value = 0;
    if (!Pad_chokeGroupGlobal(pad)) {

        int64_t bank  = hub_padIndexToBank(Pad_padIndex(pad));
        int64_t frame = hub_padIndexToFrame(Pad_padIndex(pad));

        //Hubbank;
        value |= bank & 0x7FFFFFFF;        // 32 bit for bank
        value |= (frame & 0xFF) << 32;     // 8 bit for frame
    }
    int64_t instrument = Pad_chokeGroupInstrument(pad);
    int64_t index      = Pad_chokeGroupIndex(pad);

    value |= (instrument & 0xFF) << 40; // 8 bits for instrument
    value |= (index & 0xFF)      << 48; // 8 bits for index
    Pad_setChokeGroup(pad, value);
}

//
// P A D   L I S T
//
APIF PadList *PadList_newN(int npads)
{
    PadList *self = PadList_new();
    PadAr_changeLength(&self->pads, npads);
    PadAr_foreach(it, &self->pads) {
        Pad_init(it.var);
    }
    return self;
}

APIF void PadList_play(PadList *self, int padIndex, Ticks startTime, Ticks currentTime, bool useMasterClock, Error *err)
{
    Pad *pad = PadAr_getp(&self->pads, padIndex, err);
    Error_returnVoidOnError(err);

    // Since we're starting to play, we just recieved a Note-on for this pad. Reset the pad
    Pad_setInEndgroup(pad, false);
    Pad_setNoteReleasePending(pad, true);

    // Now let's find a place to stick this pad into the running array
    PadPtrAr_foreach(it, &self->running) {
        Pad *p = *it.var;
        if (Pad_chokeGroup(pad) != 0 && Pad_chokeGroup(pad) == Pad_chokeGroup(p)) {
            PadPtrAr_remove(&self->running, it.index, err);
            Error_returnVoidOnError(err);
            break;
        }
    }

    PadPtrAr_push(&self->running, pad);

   Midiseq_start(Pad_sequence(pad), startTime, currentTime, false, err);
}


APIF void PadList_markReleasePending(PadList *self, int padIndex, bool pending, Error *err)
{
    Pad *pad = PadAr_getp(&self->pads, padIndex, err);
    Error_returnVoidOnError(err);
    Pad_setNoteReleasePending(pad, pending);
    if (!pending) {
        // We recieved a note-off. So cancel any pending endgroups
        NoteManager_padNoteOff(Track_noteManager(Pad_track(pad)), padIndex);
    }
}

APIF Pad *PadList_pad(PadList *pl, int index, Error *err)
{
    return PadAr_getp(&pl->pads, index, err);
}


APIF void PadList_assignTrack(PadList *pl, TrackList *tl)
{
    PadAr_foreach(it, &pl->pads) {
        Pad *pad = it.var;
        Pad_setTrack(pad, TrackList_findTrackByName(tl, Pad_trackName(pad)));
    }
}

APIF void PadList_toBinFile(PadList *pl, BinFile *bf, Error *err) {
    BinFile_writeTag(bf, "padlist_start", err);
    Error_returnVoidOnError(err);

    BinFile_writeInteger(bf, PadAr_len(&pl->pads), err);
    Error_returnVoidOnError(err);

    PadAr_foreach(it, &pl->pads) {
        Pad_toBinFile(it.var, bf, err);
        Error_returnVoidOnError(err);                
    }

    BinFile_writeTag(bf, "padlist_end", err);
    Error_returnVoidOnError(err);
}

APIF PadList *PadList_fromBinFile(BinFile *bf, Error *err) {
    PadList *pl = PadList_newN(0);
    PadList_fromBinFileInitialized(pl, bf, err);
    if (Error_iserror(err)) {
        PadList_free(pl);
        return NULL;
    }
    return pl;
}

// Remember the rul is that if there is an error, the PadList passed in remains uninitialized.
APIF void PadList_fromBinFileInitialized(PadList *pl, BinFile *bf, Error *err) {
    BinFile_verifyTag(bf, "padlist_start", err);
    Error_returnVoidOnError(err);

    long len = BinFile_readInteger(bf, err);
    Error_returnVoidOnError(err);
            
    for (int i = 0; i < len; i++) {
        Pad pad = {0};
        Pad_fromBinFileUninitialized(&pad, bf, err);
        Error_returnVoidOnError(err);
        PadAr_push(&pl->pads, pad);
    }
    BinFile_verifyTag(bf, "padlist_end", err);
    PadAr_fit(&pl->pads);
}

//
// T R A C K
//

APIF TrackList *TrackList_newBuild(PortFind *pf)
{
    TrackList *tl = TrackList_new();
    TrackList_build(tl, pf);
    return tl;
}

APIF void TrackList_build(TrackList *tl, PortFind *pf) {

    {
        // Insert the null track at position 1 of the tracklist
        Track t = {0};
        t.name  = Symbol_gen("null");
        t.noteManager = NoteManager_newFromPort(Port_null);
        TrackAr_push(&tl->list, t);
    }

    Error_declare(err);
    for (int i = 0; i < PortFind_portCount(pf); i++) {
        // Notice I don't handle any error that occures. I assume none do since I bound findByIndex by portCount
        Port *p = PortFind_findByIndex(pf, i, err);
        if (Error_maypost(err)) {
            continue;
        }
        Track t = {0};
        Track_setName(&t, Port_track(p));
        Track_setNoteManager(&t, NoteManager_newFromPort(p));
        TrackAr_push(&tl->list, t);
    }
    Error_clear(err);
    return;
}

APIF Track *TrackList_findTrackByName(TrackList *tl, Symbol *name)
{
    TrackAr_foreach(it, &tl->list) {
        if (it.var->name == name) {
            return it.var;
        }
    }

    // Always return the Null track if didn't find.
    Error_declare(err);
    Track *t = TrackAr_getp(&tl->list, 0, err);
    Error_clear(err);
    return t;        
}


APIF int TrackList_count(TrackList *tl)
{
    return TrackAr_len(&tl->list);
}


APIF Track *TrackList_findTrackByIndex(TrackList *tl, int index, Error *err)
{
    return TrackAr_getp(&tl->list, index, err);
}

// NOTE: currently nothing is actually stored in the output file. The complete tracklist comes from a port find payload in the BinFile instance.
APIF TrackList *TrackList_fromBinFile(BinFile *bf, Error *err)
{
    PortFind *pf = BinFile_portFindPayload(bf);
    if (pf == NULL) {
        Error_format0(err, "Expected portFindPayload on BinFile, but didn't see one");
        return NULL;
    }

    return TrackList_newBuild(pf);
}

APIF void TrackList_toBinFile(TrackList *tl, BinFile *bf, Error *err) {
    // NO-op since nothing in the tracklist is written to file.
}



//
// I N D E X E D   AND   T I M E D   O F F
//

APIF int IndexedOff_cmpPadIndex(IndexedOff *left, IndexedOff *right) {
    if (left->padIndex < right->padIndex) {
        return -1;
    } else if (left->padIndex > right->padIndex) {
        return 1;
    }
    return 0;
}

APIF int TimedOff_cmpTime(TimedOff *left, TimedOff *right) {
    if (left->time < right->time) {
        return -1;
    } else if (left->time > right->time) {
        return 1;
    }
    return 0;   
}



//
// N O T E   M A N A G E R
//

const int NoteManager_atomcount = 4;


APIF NoteManager *NoteManager_newFromPort(Port *port)
{
    NoteManager *self = NoteManager_new();
    self->output      = port;
    return self;
}

APIF void NoteManager_userInit(NoteManager *self)
{
    self->atoms = Mem_calloc(sizeof(Atom) * NoteManager_atomcount);    
}

APIF void NoteManager_userClear(NoteManager *self) 
{
    Mem_free(self->atoms);
    self->atoms = NULL;
}

// insert a note off, and remove any single pitch that is already there. Return true if a note-off was removed
APIF bool NoteManager_insertNoteOff(NoteManager *manager, Ticks timestamp, int pitch, int padIndexForEndgroup)
{
    Error_declare(ignored);
    bool q = false;
    IndexedOffAr_foreach(it, &manager->endgroups) {
        if (it.var->pitch == pitch) {
            IndexedOffAr_remove(&manager->endgroups, it.index, ignored);
            q = true;
            break;
        }
    }

    TimedOffAr_foreach(it, &manager->pending) {
        if (it.var->pitch == pitch) {
            TimedOffAr_remove(&manager->pending, it.index, ignored);
            q = true;
            break;
        }   
    }


    if (padIndexForEndgroup >= 0) {
        // Mark this pitch as endgroup
        IndexedOff_declare(off, padIndexForEndgroup, pitch);
        IndexedOffAr_binInsertPadIndex(&manager->endgroups, off);
    }
    else {
        TimedOff_declare(off, timestamp, pitch);
        TimedOffAr_binInsertTime(&manager->pending, off);
    }

    Error_maypost(ignored);

    return q;
}


// This is 10010000 which is a note-on (1001), on channel 0 (0000)
const int NOTEON_COMMAND = 144;

APIF void NoteManager_sendNoteOn(NoteManager *manager, int pitch, int velocity)
{
    Atom *av = manager->atoms;
    av[0] = Atom_fromSymbol(Symbol_gen("midievent"));
    av[1] = Atom_fromInteger(NOTEON_COMMAND);
    av[2] = Atom_fromInteger(pitch);
    av[3] = Atom_fromInteger(velocity);
    Error_declare(err);
    Port_send(manager->output, 0, 4, av, err);
    Error_maypost(err);
}


APIF void NoteManager_flushOffs(NoteManager *manager)
{
    IndexedOffAr_foreach(it, &manager->endgroups) {
        NoteManager_sendNoteOn(manager, it.var->pitch, 0);
    }
    IndexedOffAr_truncate(&manager->endgroups);

    TimedOffAr_foreach(it, &manager->pending) {
        NoteManager_sendNoteOn(manager, it.var->pitch, 0);   
    }
    TimedOffAr_truncate(&manager->pending);
}

APIF void NoteManager_allOff(NoteManager *manager)
{
    for (int i = 0; i < 128; i++) {
        NoteManager_sendNoteOn(manager, i, 0);      
    }
}

APIF void NoteManager_dblogPending(NoteManager *manager, Ticks current)
{
    dblog("dbPending %lld:", current);
    TimedOffAr_foreach(it, &manager->pending) {
        dblog("  %lld %d", it.var->time-current, it.var->pitch); 
    }
}


APIF Ticks NoteManager_scheduleOffs(NoteManager *manager, Ticks current)
{
    Error_declare(err);
    int count = 0;
    TimedOffAr_foreach(it, &manager->pending) {
        if (it.var->time > current) {
            break;
        }
        NoteManager_sendNoteOn(manager, it.var->pitch , 0);
        count++;
    }
    if (count > 0) {
        TimedOffAr_removeN(&manager->pending, 0, count, err);
        Error_maypost(err);
    }
    
    TimedOffAr_foreach(it, &manager->pending) {
        return it.var->time-current;
    }

    return -1;
}


// padIndexForEndgroup should be -1 if this cell is not in an endgroup
APIF void NoteManager_midievent(NoteManager *manager, MEvent cell, int padIndexForEndgroup)
{
    if (MEvent_type(cell) == Midiseq_notetype) {
        int pitch     = MEvent_notePitch(cell);
        int velocity  = MEvent_noteVelocity(cell);
        Ticks offtime = MEvent_t(cell) + MEvent_noteDuration(cell);

        if (NoteManager_insertNoteOff(manager, offtime, pitch, padIndexForEndgroup)) {
            NoteManager_sendNoteOn(manager, pitch, 0);
        }
        NoteManager_sendNoteOn(manager, pitch, velocity);
    }
}


APIF void NoteManager_padNoteOff(NoteManager *manager, int padIndex)
{
    IndexedOff_declare(off, padIndex, 0);
    IndexedOffArFIt_declare0(slice);
    slice = IndexedOffAr_binSearchPadIndex(&manager->endgroups, off);
    if (IndexedOffArFIt_atEnd(&slice)) {
        return;
    }
    IndexedOffAr_loop(slice) {
        NoteManager_sendNoteOn(manager, slice.var->pitch, 0);
    }
    IndexedOffAr_binRemovePadIndex(&manager->endgroups, off);
    return;
}

//
// H U B
//

APIF Hub *Hub_newBuild(PortFind *pf, Error *err) {
    Hub *self = Hub_new();
    Hub_build(self, pf, err);
    if (Error_iserror(err)) {
        Hub_free(self);
        return NULL;
    }
    return self;
}

APIF void Hub_build(Hub *hub, PortFind *pf, Error *err) {
    Hub_setCurrBankPort(hub, PortFind_findById(pf, Symbol_gen("currBank")));
    Hub_setCurrFramePort(hub, PortFind_findById(pf, Symbol_gen("currFrame")));
    Hub_setSelBankPort(hub, PortFind_findById(pf, Symbol_gen("selBank")));
    Hub_setSelFramePort(hub, PortFind_findById(pf, Symbol_gen("selFrame")));
    Hub_setSelPadPort(hub, PortFind_findById(pf, Symbol_gen("selPad")));

    Port *cg = PortFind_findById(pf, Symbol_gen("chokeGroup"));
    PortRef_declare(portRef, cg, 0);
    DropDown_buildCGLocalGlobal(Hub_cgLocalGlobalMenu(hub), portRef);

    PortRef_set(portRef, cg, 1);
    DropDown_buildCGInstrument(Hub_cgInstrumentMenu(hub), portRef);

    PortRef_set(portRef, cg, 2);
    DropDown_buildCGIndex(Hub_cgIndexMenu(hub), portRef);

    DropDown_initializeMenu(Hub_cgLocalGlobalMenu(hub), err);
    Error_returnVoidOnError(err);

    DropDown_initializeMenu(Hub_cgInstrumentMenu(hub), err);
    Error_returnVoidOnError(err);

    DropDown_initializeMenu(Hub_cgIndexMenu(hub), err);
    Error_returnVoidOnError(err);    

    Atom a[2] = {Atom_fromSymbol(Symbol_gen("cantchange")), Atom_fromInteger(1)};
    Port_send(Hub_currBankPort(hub), 0, 2, a, err);
    Error_returnVoidOnError(err);

    Port_send(Hub_currFramePort(hub), 0, 2, a, err);
    Error_returnVoidOnError(err);
    
    Port_send(Hub_selBankPort(hub), 0, 2, a, err);
    Error_returnVoidOnError(err);
    
    Port_send(Hub_selFramePort(hub), 0, 2, a, err);
    Error_returnVoidOnError(err);

    Port_send(Hub_selPadPort(hub), 0, 2, a, err);
    Error_returnVoidOnError(err);

    DispatchPtAr_init(&hub->dispatcher, 0);
    DispatchPtAr_populate(&hub->dispatcher, err);
    Error_returnVoidOnError(err);
}

APIF void Hub_updateGuiCurrentCoordinates(Hub *hub) 
{
    Port_sendInteger(Hub_currBankPort(hub),  0, Hub_bank(hub));
    Port_sendInteger(Hub_currFramePort(hub), 0, Hub_frame(hub));
}

APIF void Hub_changeSelectedPad(Hub *hub, int selectedPadIndex, Error *err) {
    Hub_setSelectedPad(hub, selectedPadIndex);
    Pad *pad = PadList_pad(Hub_padList(hub), selectedPadIndex, err);
    Error_returnVoidOnError(err);

    // choke group set
    DropDown_setSelected(Hub_cgLocalGlobalMenu(hub), Pad_chokeGroupGlobal(pad) ? 1 : 0, err);
    Error_returnVoidOnError(err);
    DropDown_setSelected(Hub_cgInstrumentMenu(hub), Pad_chokeGroupInstrument(pad), err);
    Error_returnVoidOnError(err);
    DropDown_setSelected(Hub_cgIndexMenu(hub), Pad_chokeGroupIndex(pad), err);
    Error_returnVoidOnError(err);

    // Choke Group GUI
    DropDown_updateSelected(Hub_cgLocalGlobalMenu(hub), err);
    Error_returnVoidOnError(err);
    DropDown_updateSelected(Hub_cgInstrumentMenu(hub), err);
    Error_returnVoidOnError(err);
    DropDown_updateSelected(Hub_cgIndexMenu(hub), err);
    Error_returnVoidOnError(err);

    // Selected coordinates
    Port_sendInteger(Hub_selBankPort(hub),  0, (long)Hub_selectedBank(hub));
    Port_sendInteger(Hub_selFramePort(hub), 0, (long)Hub_selectedFrame(hub));  
    Port_sendInteger(Hub_selPadPort(hub),   0, (long)Hub_relativeSelectedPad(hub));
}

APIF void Hub_anythingDispatch(Hub *hub, Port *port, Symbol *selector, long argc, Atom *argv)
{

    Error_declare(err);

    Dispatch_declare(cell, Undefined_itype, selector, Port_id(port), 0, NULL);
    Dispatch **dis = DispatchPtAr_binSearch(&hub->dispatcher, &cell);

    if (dis == NULL) {
        return;
    }
    
    Marshal *marshal = Dispatch_marshal(*dis);
    if (marshal != NULL) {
        Marshal_process(marshal, &hub->arguments, argc, argv, err);
        if (Error_maypost(err)) {
            return;
        }
    }
    
    Dispatch_exec(*dis, hub, &hub->arguments, err);
    if (Error_maypost(err)) {
        return;
    }
    if (marshal != NULL) {
        Marshal_zeroArgs(marshal, &hub->arguments, err);
        if (Error_maypost(err)) {
            return;
        }
    }

    return;
}



APIF void Hub_intDispatch(Hub *hub, Port *port, long value, long inlet)
{
    Error_declare(err);
    Dispatch_declare(cell, Undefined_itype, NULL, Port_id(port), (int)inlet, NULL);
    Dispatch **dis = DispatchPtAr_binSearch(&hub->dispatcher, &cell);
    if (dis == NULL) {
        return;
    }

    Arguments_setIvalue(&hub->arguments, value);
    Arguments_setInlet(&hub->arguments, inlet);
    Dispatch_exec(*dis, hub, &hub->arguments, err);
    if (Error_maypost(err)) {
        return;
    }
    Arguments_setIvalue(&hub->arguments, 0);
    Arguments_setInlet(&hub->arguments, 0);

    /*
    Hub *hub = (Hub*)hub_in;
    int ev = port_parseEvSymbol(Port_id(port));
    if (ev >= 0) {
        dblog("Ev sent to %d: inlet %ld", ev, inlet);
    } else if (Port_id(port) == Symbol_gen("chokeGroup")) {
        Error_declare(err);
        Hub_manageChokeGroups(hub, value, inlet, err);
        if (Error_maypost(err)) {
            // Reset pad b/c the drop down is now not consistent with the Pad
            Hub_changeSelectedPad(hub, Hub_selectedPad(hub), err);
            Error_maypost(err);
        }
    }
    */
}

APIF void Hub_toBinFile(Hub *hub, BinFile *bf, Error *err) {
    BinFile_writeTag(bf, "hub_start", err);
    Error_returnVoidOnError(err);

    PadList_toBinFile(Hub_padList(hub), bf, err);
    Error_returnVoidOnError(err);

    TrackList_toBinFile(Hub_trackList(hub), bf, err);
    Error_returnVoidOnError(err);

    BinFile_writeTag(bf, "hub_end", err);    
    Error_returnVoidOnError(err);
}

APIF Hub *Hub_fromBinFile(BinFile *bf, Error *err) {
    // Hub *hub = Hub_newUninitialized();
    // Hub_fromBinFileUninitialized(hub, bf, err);
    // if (Error_iserror(err)) {
    //     Hub_free(hub);
    //     return NULL;
    // }
    // return hub;
    return NULL;
}

APIF void Hub_fromBinFileUninitialized(Hub *hub, BinFile *bf, Error *err) {
    BinFile_verifyTag(bf, "hub_start", err);
    Error_returnVoidOnError(err);

    Hub_setPadList(hub, PadList_fromBinFile(bf, err));
    Error_returnVoidOnError(err);
    
    Hub_setTrackList(hub, TrackList_fromBinFile(bf, err));
    Error_returnVoidOnError(err);

    BinFile_verifyTag(bf, "hub_end", err);    
    Error_returnVoidOnError(err);
}


//
// B I N    F I L E
//

// APIF BinFile *BinFile_new() {
//     BinFile *bf = Mem_calloc(sizeof(BinFile));
//     bf->filename = String_empty();
//     bf->buffer   = String_empty();
//     return bf;
// }

APIF BinFile *BinFile_newWriter(const char *file, Error *err) {
    BinFile *bf =  BinFile_new();
    BinFile_setStream(bf, fopen(file, "w"));
    if (BinFile_stream(bf) == NULL) {
        Error_format(err, "Failed to open file %s", file);
        BinFile_free(bf);
        return NULL;
    }
    String_free(bf->filename);
    bf->filename = String_fmt("%s", file);

    if (fprintf(BinFile_stream(bf), "%d ", BinFile_version(bf)) < 0) {
        Error_format(err, "Failed to write version number to file %s", file);
        BinFile_free(bf);
        return NULL;
    }

    return bf;
}

APIF BinFile *BinFile_newReader(const char *file, Error *err) {
    BinFile *bf =  BinFile_new();
    BinFile_setStream(bf, fopen(file, "r"));
    if (BinFile_stream(bf) == NULL) {
        Error_format(err, "Failed to open file %s", file);
        BinFile_free(bf);
        return NULL;
    }
    bf->filename = String_fmt("%s", file);
    if (fscanf(BinFile_stream(bf), "%d ", &bf->version)) {
        Error_format(err, "Failed to read version number from file  %s", file);
        BinFile_free(bf);
        return NULL;
    }
    return bf;
}

// APIF void BinFile_free(BinFile *bf) {
//     if (BinFile_stream(bf) != NULL) {
//         fclose(BinFile_stream(bf));
//         BinFile_setStream(bf, NULL);
//     }
//     String_free(bf->filename);
//     String_free(bf->buffer);
//     Mem_free(bf);
// }

APIF void BinFile_userClear(BinFile *bf) {
    if (BinFile_stream(bf) != NULL) {
        fclose(BinFile_stream(bf));
        BinFile_setStream(bf, NULL);
    }
}


APIF int binFile_hexDigitToInt(char hex) {
    switch (hex) {
        case '0': return 0;
        case '1': return 1;
        case '2': return 2;
        case '3': return 3;
        case '4': return 4;
        case '5': return 5;
        case '6': return 6;
        case '7': return 7;
        case '8': return 8;
        case '9': return 9;
        case 'a': return 10;
        case 'b': return 11;
        case 'c': return 12;
        case 'd': return 13;
        case 'e': return 14;
        case 'f': return 15;
    }
    return 0;
}
APIF char binFile_intToHexDigit(int digit) {
    switch (digit) {
        case 0: return '0';
        case 1: return '1';
        case 2: return '2';
        case 3: return '3';
        case 4: return '4';
        case 5: return '5';
        case 6: return '6';
        case 7: return '7';
        case 8: return '8';
        case 9: return '9';
        case 10: return 'a';
        case 11: return 'b';
        case 12: return 'c';
        case 13: return 'd';
        case 14: return 'e';
        case 15: return 'f';
    }
    return 0;
}

APIF off_t BinFile_writeNullLength(BinFile *bf, bool spaceForFlags, Error *err) {
    errno = 0;
    off_t start = BinFile_tell(bf, err);
    Error_returnZeroOnError(err);

    const char *format = ("%" BinFile_nullLengthFieldSizeStr "s ");
    if (fprintf(BinFile_stream(bf), format, "") < 0) {
        Error_format(err, "Failed fprintf while writing %s", BinFile_filename(bf));
        return 0;
    }
    if (spaceForFlags) {
        if (fprintf(BinFile_stream(bf), "0000 ") < 0) {
            Error_format(err, "Failed fprintf while writing %s", BinFile_filename(bf));
            return 0;
        }
    }
    return start;
} 

APIF void BinFile_writeFlags(BinFile *bf, long flags, Error *err) {
    char hex[4] = {
        binFile_intToHexDigit((flags)       & 0xFF),
        binFile_intToHexDigit((flags >> 8)  & 0xFF),
        binFile_intToHexDigit((flags >> 16) & 0xFF),
        binFile_intToHexDigit((flags >> 24) & 0xFF),
    };
    if (fprintf(BinFile_stream(bf), "%c%c%c%c ", hex[0], hex[1], hex[2], hex[3]) < 0) {
        Error_format(err, "Failed fprintf while writing %s", BinFile_filename(bf));
        return;
    }
}

APIF void BinFile_writeBackLengthFlags(BinFile *bf, off_t location, long flags, Error *err) {
    off_t end = BinFile_tell(bf, err);
    Error_returnVoidOnError(err);

    long length = (long)(end-location);
    if (length > BinFile_maxLength) {
        Error_format(err, "Length is too large (%ld) while writing %s", length, BinFile_filename(bf));
        return;
    }
    if (fseeko(BinFile_stream(bf), location, SEEK_SET) != 0){
        Error_format(err, "Failed fseeko[1] while writing %s", BinFile_filename(bf));
        return;
    }

    if (flags >= 0) {
        length = -length;
    }

    const char *format = ("%" BinFile_nullLengthFieldSizeStr "ld ");
    if (fprintf(BinFile_stream(bf), format, length) < 0) {
        Error_format(err, "Failed fprintf while writing %s", BinFile_filename(bf));
        return;
    }

    if (flags >= 0) {
        BinFile_writeFlags(bf, flags, err);
    }

    if (fseeko(BinFile_stream(bf), end, SEEK_SET) != 0){
        Error_format(err, "Failed fseeko[2] while writing %s", BinFile_filename(bf));
        return;
    }
    
    return;
}

APIF void BinFile_writeLengthFlags(BinFile *bf, long length, long flags, Error *err) {
    if (length > BinFile_maxLength) {
        Error_format(err, "Length is too large (%ld) while writing %s", length, BinFile_filename(bf));
        return;
    }
    if (flags >= 0) {
        length = -length;
    }
    if (fprintf(BinFile_stream(bf), "%ld ", length) < 0) {
        Error_format(err, "Failed fprintf while writing %s", BinFile_filename(bf));
        return;
    }
    if (flags >= 0) {
        BinFile_writeFlags(bf, flags, err);
    }

}

APIF long BinFile_readLengthFlags(BinFile *bf, long *flags, Error *err) {
    long length;
    char space;
    if (fscanf(BinFile_stream(bf), " %ld%c", &length, &space) != 2 || space != ' ') {
        Error_format(err, "Failed sscanf[1] while reading %s", BinFile_filename(bf));
        return 0;   
    }
    if (length < 0) {
        length = -length;
        char f[4] = "\0\0\0\0";
        if (fscanf(BinFile_stream(bf), "%c%c%c%c%c", f+0, f+1, f+2, f+3, &space) != 5 || space != ' ') {
            Error_format(err, "Failed sscanf[2] while reading %s", BinFile_filename(bf));
            return 0;   
        }   
        if (flags != NULL) {
            *flags = 0;
            for (int i = 0; i < 4; i++) {
                int v = binFile_hexDigitToInt(f[i]) << i*8;
                *flags = *flags | v;
            }
        }
    }
    return length;
}

APIF off_t BinFile_tell(BinFile *bf, Error *err) {
    errno = 0;
    off_t location = ftello(BinFile_stream(bf));
    if (errno != 0) {
        Error_format(err, "Failed ftello while working with %s", BinFile_filename(bf));
        return 0;
    }
    return location;
}

APIF void BinFile_fillBuffer(BinFile *bf, long size, Error *err) {
    // Want buffer to contain size+1 characters INCLUDING the null byte
    if (String_len(bf->buffer) < size) {
        // NOTE: I verified that this call DOES NOT shrink the buffer.
        // NOTE: sdsMakeRoomFor always allocates sdslen()+1 bytes  
        String_resize(&bf->buffer, size);
    }
    
    if (fread((char*)bf->buffer, size, 1, BinFile_stream(bf)) != size) {
        Error_format(err, "Failed fread while working with %s", BinFile_filename(bf));
        return;   
    }
    // NOTE: this means that the buffer can be used like a string in the correct context. IT DOES NOT say that there aren't
    // other nulls embedded in the string. I think that the way I'm preparing this string, there might be 2 nulls at the end
    // of it. 
    char *p = (char*)bf->buffer;
    p[size] = '\0';
}

APIF void BinFile_writeInteger(BinFile *bf, long value, Error *err) {
    // XXX: BORKEN
    // sdsclear(BinFile_buffer(bf));
    // sdscatprintf(BinFile_buffer(bf), "%ld", value);
    


    BinFile_writeLength(bf, String_len(BinFile_buffer(bf)), err);
    Error_returnVoidOnError(err);

    if (fwrite(BinFile_buffer(bf), String_len(BinFile_buffer(bf)), 0, BinFile_stream(bf)) != String_len(BinFile_buffer(bf))) {
        Error_format(err, "Failed fwrite while writing %s", BinFile_filename(bf));
        return;
    }
}

APIF long BinFile_readInteger(BinFile *bf, Error *err) {
    long length = BinFile_readLength(bf, err);
    Error_returnZeroOnError(err);
    
    BinFile_fillBuffer(bf, length, err);
    Error_returnZeroOnError(err);
    
    long value = 0;
    if (sscanf(BinFile_buffer(bf), "%ld", &value) != 1) {
        Error_format(err, "Failed sscanf while reading %s", BinFile_filename(bf));
        return 0;
    }
    return value;
}

APIF void BinFile_writeString(BinFile *bf, String *value, Error *err) {
    BinFile_writeLength(bf, String_len(value), err);
    Error_returnVoidOnError(err);

    if (fwrite(BinFile_buffer(bf), String_len(BinFile_buffer(bf)), 1, BinFile_stream(bf)) != String_len(BinFile_buffer(bf))) {
        Error_format(err, "Failed fprintf while writing %s", BinFile_filename(bf));
        return;
    }

}

// must call sdsfree on any non-NULL return value
APIF String *BinFile_readString(BinFile *bf, Error *err) {
    uint32_t length = BinFile_readLength(bf, err);
    Error_returnNullOnError(err);

    BinFile_fillBuffer(bf, length, err);
    Error_returnNullOnError(err);    
    
    return String_dup(BinFile_buffer(bf));
}

APIF void BinFile_writeSymbol(BinFile *bf, Symbol *value, Error *err) {
    BinFile_writeString(bf, Symbol_cstr(value), err);
    return;
}

APIF Symbol *BinFile_readSymbol(BinFile *bf, Error *err) {
    long length = BinFile_readLength(bf, err);
    Error_returnNullOnError(err);

    BinFile_fillBuffer(bf, length, err);
    Error_returnNullOnError(err);
    
    return Symbol_gen(BinFile_buffer(bf));
}

APIF void BinFile_writeTicks(BinFile *bf, Ticks value, Error *err) {
    // XXX: BORKEN
    // sdsclear(BinFile_buffer(bf));
    // sdscatprintf(BinFile_buffer(bf), "%lld", value);

    BinFile_writeLength(bf, String_len(BinFile_buffer(bf)), err);
    Error_returnVoidOnError(err);

    if (fwrite(BinFile_buffer(bf), String_len(BinFile_buffer(bf)), 1, BinFile_stream(bf)) != String_len(BinFile_buffer(bf))) {
        Error_format(err, "Failed fprintf while writing %s", BinFile_filename(bf));
        return;
    }
}

APIF Ticks BinFile_readTicks(BinFile *bf, Error *err) {
    uint32_t length = BinFile_readLength(bf, err);
    Error_returnZeroOnError(err);
    
    BinFile_fillBuffer(bf, length, err);
    Error_returnZeroOnError(err);
    
    Ticks value = 0;
    if (sscanf(BinFile_buffer(bf), "%lld", &value) != 1) {
        Error_format(err, "Failed sscanf while reading %s", BinFile_filename(bf));
        return 0;
    }
    return value;
}

APIF void BinFile_writeBool(BinFile *bf, bool value, Error *err) {
    BinFile_writeInteger(bf, value ? 1 : 0, err);
}

APIF bool BinFile_readBool(BinFile *bf, Error *err) {
    return BinFile_readInteger(bf, err) ? true : false;
}

APIF void BinFile_writeTag(BinFile *bf, const char *tag, Error *err) {
    int len = strlen(tag);
    BinFile_writeLengthFlags(bf, len, BinFileFlag_tag, err);
    Error_returnVoidOnError(err);

    if (fwrite(tag, len, 1, BinFile_stream(bf)) != len) {
        Error_format(err, "Failed fwrite while writing %s", BinFile_filename(bf));
        return;
    }
}

APIF void BinFile_verifyTag(BinFile *bf, const char *tag, Error *err) {
    long flags  = 0;
    long length = BinFile_readLengthFlags(bf, &flags, err);
    Error_returnVoidOnError(err);
    if (flags & BinFileFlag_tag) {
        Error_format0(err, "Expected flag marked with BinFileFlag_tag");
        return;
    }
    BinFile_fillBuffer(bf, length, err);
    if (strcmp(tag, BinFile_buffer(bf)) != 0) {
        Error_format(err, "Expected tag '%s', but found '%s'", tag, BinFile_buffer(bf));
        return;
    }
    return;
}





