
#define APIF /**/
String *stripBaseName(const char *path);

@container 
{
    "type": "array",
    "typeName": "StringAr",
    "refName": "String",
    "binarySearch": [
        {"compare": "String_cmp"}
    ]   

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
       "typeName": "SymbolAr", 
       "refName": "Symbol",
       "binarySearch": [
           {"compare": "Symbol_cmpUnderlying", "tag": "Underlying"}
        ]   
   }
@end

APIF int Symbol_cmpUnderlying(Symbol *left, Symbol *right) 
{
    return strcmp(Symbol_cstr(left), Symbol_cstr(right)); 
}

#ifdef TEST_BUILD
SymbolPtAr *gSymbols = NULL;

APIF Symbol *Symbol_gen(const char *word) 
{
    if (gSymbols == NULL) {
        gSymbols = SymbolAr_new();
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

APIF void Symbol_freeAll() 
{
    SymbolPtAr_foreach(it, gSymbols) {
        Mem_free(*it.var);
    }
    SymbolPtAr_truncate(gSymbols);
}

#endif

@type
{
    "typeName": "AtomRf",
    "fields": [
        {"valName": "a", "type": "Atom"}
    ]
}
@end

@container    
{       
   "type": "array",
   "typeName": "AtomAr", 
   "refName": "AtomRf"
}
@end

@container    
{       
   "type": "array",
   "typeName": "AtomArAr", 
   "refName": "AtomAr"
}
@end

@type
{
   "typeName": "Port",
   "fields": [
         {"valName": "obj",              "type": "MaxObject"},
         {"valName": "inletnum",         "type": "long"},
         {"refName": "proxy",            "type": "PtrAr"},
         {"refName": "outlet",           "type": "PtrAr"},
         {"valName": "track",            "type": "Symbol *"},
         {"valName": "id",               "type": "Symbol *"},
         {"valName": "intInlets",        "type": "long"},
         {"valName": "intOutlets",       "type": "long"},
         {"valName": "hub",              "type": "void *"},
         {"valName": "anythingDispatch", "type": "Port_anythingDispatchFunc"},
         {"valName": "intDispatch",      "type": "Port_intDispatchFunc"}
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

#ifndef TEST_BUILD
APIF void Port_free(Port *p)
{
}

APIF void Port_clear(Port *p)
{
}
#endif

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
    
#ifndef TEST_BUILD
    Symbol *selector = Atom_toSymbol(argv + 0);
    void *out = PtrAr_get(&self->outlet, outletIndex, err);
    Error_returnVoidOnError(err);
    outlet_anything(out, selector, argc-1, argv+1);  
#else
    AtomArAr *arr = self->obj.utilityPointer;
    if (arr != NULL) {
        AtomAr subAr;
        AtomAr_init(&subAr, 0);
        for (int i = 0; i < argc; i++){
            AtomAr_push(&subAr, argv[i]);
        }
        AtomArAr_push(arr, subAr);
        // Explicitly DO NOT deallocate subAr
    }
#endif
}

APIF void Port_sendInteger(Port *self, int outlet, long value, Error *err) 
{
    if (self == Port_null) {
        return;
    }

    void *out = PtrAr_get(&self->outlet, outlet, err);
    Error_returnVoidOnError(err); 
#ifndef TEST_BUILD
    outlet_int(out, value);  
#else
    AtomArAr *arr = self->obj.utilityPointer;
    if (arr != NULL) {
        AtomAr subAr;
        AtomAr_init(&subAr, 0);
        AtomAr_push(&subAr, Atom_fromInteger(value));
        AtomArAr_push(arr, subAr);
        // Explicitly DO NOT deallocate subAr
    }
#endif
}

@type
{
    "typeName": "Ptr",
    "fields": [
        {"valName": "p", "type": "void *"}
    ]
}
@end

@container    
{       
   "type": "array",
   "typeName": "PtrAr", 
   "refName": "Ptr"   
}
@end

@container    
{       
   "type": "array",
   "typeName": "SymbolAr", 
   "refName": "Symbol"   
}
@end

@type
{
    "typeName": "Int",
    "fields": [
        {"valName": "i", "type": "int"}
    ]
}
@end
APIF int Int_cmp(Int *left, Int *right)
{
    if (left->i < right->i) {
        return -1;
    } else if (left->i > right->i) {
        return 1;
    }
    return 0;
}

@container    
{       
   "type": "array",
   "typeName": "IntAr", 
   "refName":  "Int",
   "binarySearch": [
        {"compare": "Int_cmp"}
    ]  
}
@end

@type
   {  
      "typeName": "Pad",
      "fields":[  
         {  
            "valName":"trackName",
            "type":"Symbol *"
         },
         {  
            "valName":"padIndex",
            "type":"int"
         },
         {  
            "refName":"SequenceAr",
            "type":"Sequence"
         },
         {  
            "valName":"chokeGroupGlobal",
            "type":"bool"
         },
         {  
            "valName":"chokeGroupInstrument",
            "type":"int"
         },
         {  
            "valName":"chokeGroupIndex",
            "type":"int"
         },
         {  
            "valName":"chokeGroup",
            "type":"int64_t"
         },
         {  
            "valName":"noteReleasePending",
            "type":"bool"
         },
         {  
            "valName":"inEndgroup",
            "type":"bool"
         },
         {  
            "refName":"track",
            "type":"Track"
         },
         {  
            "valName":"useMasterClock",
            "type":"bool"
         }
      ],
      "containers": [
         {"type": "array", "typeName": "PadAr", "refName": "Pad"}
      ]
   }
@end

@type
   {  
      "typeName":"TimedOff",
      "argDeclare":1,
      "fields":[  
         {  
            "valName":"time",
            "type":"Ticks"
         },
         {  
            "valName":"pitch",
            "type":"int"
         }
      ],
      "containers": [
         {
            "type": "array",
            "typeName": "TimedOffAr", 
            "refName": "TimedOff",
            "binarySearch": [
               {"compare": "TimedOff_cmpTime", "multi": true, "tag": "Time"}
            ]
         }
      ]
   }
@end

@type
   {  
      "typeName": "Track",
      "fields":[  
         {  
            "valName":"name",
            "type":"Symbol *"
         }
      ],
      "containers": [
         {
            "type": "array",
            "typeName": "TrackAr", 
            "refName": "Track"
         }
      ]
   }
@end

@type
   {  
      "typeName": "PortRef",
      "fields":[  
         {  
            "valName":"port",
            "type":"Port *"
         },
         {  
            "valName":"outlet",
            "type":"int"
         }
      ]
   }
@end

#define PortRef_declare(name, port, outlet)    PortRef _##name = {port, outlet}; PortRef *name = &_##name
COVER static inline void PortRef_set(PortRef *pr, Port *port, int outlet) {
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
            "refName":"table",            
            "type":"SymbolAr"
         },
         {  
            "valName": "selected",
            "type": "int"
         },
         {  
            "refName":"outlet",
            "type":"Outlet"
         }
      ]
   }
@end

//
// D R O P   D O W N
//

APIF void DropDown_build(DropDown *self, const char **table, Outlet *outlet) {
    const char **ptr = table;
    while (*ptr) {
        Symbol *s = Symbol_gen(*ptr);
        SymbolAr_push(self->table, s);
        ptr++;
    }
    DropDown_setOutlet(self, outlet);
    return;
}

APIF DropDown *DropDown_newCGLocalGlobal(Outlet *outlet) {
    Coverage_off;
    const char *t[] = {
        "local",
        "global",
        NULL
    };
    Coverage_on;
    DropDown *self = DropDown_new();
    DropDown_build(self, t, outlet);
    return self;
}

APIF DropDown *DropDown_newCGInstrument(Outlet *outlet) {
    Coverage_off;
    const char *t[] = {
        "none",
        "lead",
        "rhythm",
        "piano",
        "bass",
        "drums",
        NULL,
    };
    Coverage_on;
    DropDown *self = DropDown_new();
    DropDown_build(self, t, outlet);
    return self;
}

APIF DropDown *DropDown_newCGIndex(DropDown *dd, Outlet *outlet) {
    Coverage_off;
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
    Coverage_on;
    DropDown *self = DropDown_new();
    DropDown_build(self, t, outlet);
    return self;
}

// APIF void DropDown_clear(DropDown *dd) {
//     SymbolPtrAr_clear(&dd->table);
// }

// APIF void DropDown_free(DropDown *dd) {
//     DropDown_clear(dd);
//     Mem_free(dd);
// }

APIF DropDown *DropDown_updateSelected(DropDown *dd, Error *err) {
    Symbol *s = SymbolPtrAr_get(&dd->table, dd->selected, err);
    Error_returnVoidOnError(err);

    Atom a[2] = {Atom_fromSymbol(Symbol_gen("set")), Atom_fromSymbol(s)};
    // PortRef_send(DropDown_portRef(dd), 2, a, err);
}

APIF DropDown *DropDown_setSelected(DropDown *dd, int selected, Error *err) {
    if (selected < 0 || selected >= SymbolPtrAr_len(&dd->table)) {
        Error_format(err, "Index out of range (%d, %d)", selected, SymbolPtrAr_len(&dd->table));
        return;
    }
    dd->selected = selected;
}

APIF DropDown *DropDown_initializeMenu(DropDown *dd, Error *err) {
    Atom clear = Atom_fromSymbol(Symbol_gen("clear"));
    Atom append = Atom_fromSymbol(Symbol_gen("append"));

    // PortRef_send(&dd->portRef, 1, &clear, err);
    Error_returnVoidOnError(err);

    SymbolAr_foreach(it, &dd->table) {
        Atom a[2] = {append, Atom_fromSymbol(*it.var)};
        // PortRef_send(&dd->portRef, 2, a, err);
        Error_returnVoidOnError(err);        
    }
}
@type
{  
    "typeName": "Hub",
    "fields": [ 
        {  
            "refName": "padList",
            "type": "PadAr"
        },
        {  
            "refName": "trackList",
            "type": "TrackAr"
        },
        {  
            "refName": "currBankPort",
            "type": "Port"
        },
        {  
            "refName": "currFramePort",
            "type": "Port"
        },
        {  
            "refName": "selBankPort",
            "type": "Port"
        },
        {  
            "refName": "selFramePort",
            "type": "Port"
        },
        {  
            "refName": "selPadPort",
            "type": "Port"
        },
        {  
            "refName": "chokeGroupPort",
            "type": "Port"
        },
        {              
            "refName": "cgLocalGlobalMenu",
            "type": "DropDown"
        },
        {              
            "refName": "cgInstrumentMenu",
            "type": "DropDown"
        },
        {  
            "refName": "cgIndexMenu",
            "type": "DropDown"
        },
        {  
            // bank varies from 0-infinity
            "valName": "bank",
            "type": "int"
        },
        {  
            // frame varies from 0-7
            "valName": "frame",
            "type": "int"
        },
        {  
            // true if the next padIndex tapped should be written into selectedPad
            "valName": "grabNextTappedPad",
            "type": "bool"
        },
        {  
            "valName": "selectedPad",
            "type": "int"
        },
        {
            "refName": "arguments",
            "type": "Arguments"
        },
        {
            "refName": "dispatcher",
            "type": "DispatchAr"
        },
        {
            "valName": "masterClock",
            "type": "Ticks"
        }
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

@end

//
// U t i l i t y
//

// APIF int Midiseq_convertIntFileLine(const char *src, Error *err, const char *function, const char *file, int line)
// {
//     errno = 0;
//     long v = strtol(src, NULL, 10);
//     if (errno != 0) {
//         Coverage_off;
//         Error_formatFileLine(err, function, file, line, String_fmt("Failed to convert int error code %s", 
//           (errno == EINVAL ? "EINVAL" : errno == ERANGE ? "ERANGE" : "Unknown")));
//         Coverage_on;

//     }
//     return v;
// }


#define Midiseq_convertInt(src, err) Midiseq_convertIntFileLine(src, err, __func__, __FILE__, __LINE__)

// APIF Midiseq *Midiseq_newNote(int pitch)
// {
//     Midiseq *mseq = Midiseq_new();
//     MEventAr_truncate(&mseq->events);

//     mseq->sequenceLength = 480*4;
    
//     MEvent zero = {0}, cell = {0};

//     MEvent_t(cell)    = 0;
//     MEvent_type(cell) = Midiseq_endgrptype;
//     MEventAr_push(&mseq->events, cell);

//     cell = zero;
//     MEvent_t(cell)            = 0;
//     MEvent_type(cell)         = Midiseq_notetype;
//     MEvent_notePitch(cell)    = pitch;
//     MEvent_noteVelocity(cell) = 90;
//     MEvent_noteDuration(cell) = 480;
//     MEventAr_push(&mseq->events, cell);

//     cell              = zero;
//     MEvent_t(cell)    = mseq->sequenceLength;
//     MEvent_type(cell) = Midiseq_cycletype;
//     MEventAr_push(&mseq->events, cell);

//     MEventAr_fit(&mseq->events);

//     return mseq;
// }

//
// P A T C H E R    F I N D
//
@type
   {  
      "typeName":"PortFindCell",
      "fields":[  
         {  
            "valName": "reciever",
            "type": "Port"
         },
         {  
            "valName": "varname",
            "type": "Symbol *"
         }
      ],
      "containers": [
         {
            "type": "array",
            "typeName": "PortFindCellAr", 
            "refName": "PortFindCell"
         }
      ]
   }
@end

@type
   {  
      "typeName": "PortFind",
      "fields":[  
         {  
            "refName":"objects",
            "type":"PortFindCellAr"
         },
         {  
            "valName":"hub",
            "type":"void *"
         },
         {  
            "valName":"anythingDispatch",
            "type":"Port_anythingDispatchFunc"
         },
         {  
            "valName":"intDispatch",
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

    /*
    Outlet *broken = NULL;
    // Port *cg = PortFind_findById(pf, Symbol_gen("chokeGroup"));
    Hub_setCgLogcalGlobalMenu(hub, DropDown_newCGLocalGlobal(broken));
    Hub_setCgInstru(hub, DropDown_newCGInstrument(broken));

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
    */
}

APIF void Hub_updateGuiCurrentCoordinates(Hub *hub) 
{
    Error_declare(err);
    Port_sendInteger(Hub_currBankPort(hub),  0, Hub_bank(hub), err);
    Error_maypost(err);
    Port_sendInteger(Hub_currFramePort(hub), 0, Hub_frame(hub), err);
    Error_maypost(err);
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
    Port_sendInteger(Hub_selBankPort(hub),  0, (long)Hub_selectedBank(hub), err);
    Error_returnVoidOnError(err);
    Port_sendInteger(Hub_selFramePort(hub), 0, (long)Hub_selectedFrame(hub), err);  
    Error_returnVoidOnError(err);
    Port_sendInteger(Hub_selPadPort(hub),   0, (long)Hub_relativeSelectedPad(hub), err);
    Error_returnVoidOnError(err);
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
}
