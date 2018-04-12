
@type
{
    "typeName": "MusicalContext",
    "fields": [
        {
            "name": "ticksPerQuarterNote",
            "type": "Ticks"       
        },
        {
            "name": "quarterNotesPerMeasure",
            "type": "Ticks"       
        }
    ]
}
@end

#define MusicalContext_declareDefault(name) MusicalContext name = {.ticksPerQuarterNote = 480, .quarterNotesPerMeasure = 4}

@type 
{
    "typeName": "NoteOutlet",
    "fields": [
        {
            "name": "atoms",
            "type": "AtomAr"       
        },       
        {
            "name": "port",
            "type": "Port *"
        }
    ],
    "implements": ["Outlet"]
}
@end

// This is the decimal representation of binary 10010000
#define NOTEON_COMMAND 144


APIF void NoteOutlet_sendNote(NoteOutlet *self, uint8_t pitch, uint8_t velocity)
{
#   ifdef TEST_BUILD
    NoteOutlet_dbRecordEvent(pitch, velocity);
#   endif

    AtomAr_changeLength(&self->atoms, 4);
    Atom *av = self->atoms.data;
    av[0] = Atom_fromSymbol(Symbol_gen("midievent"));
    av[1] = Atom_fromInteger(NOTEON_COMMAND);
    av[2] = Atom_fromInteger(pitch);
    av[3] = Atom_fromInteger(velocity);
    Error_declare(err);
    Port_send(self->port, 0, 4, av, err);
    Error_maypost(err);
}

APIF NoteOutlet *NoteOutlet_newBuild(Port *port)
{
    NoteOutlet *self = NoteOutlet_new();
    self->port       = port;
    AtomAr_changeLength(&self->atoms, 4);
    return self;
}

@type 
{
    "typeName": "CcOutlet",
    "fields": [
        {
            "name": "cc",
            "type": "int"
        },
        {
            "name": "atoms",
            "type": "AtomAr"       
        },       
        {
            "name": "port",
            "type": "Port *"
        }
    ],
    "implements": ["Outlet"]
}
@end

#ifdef TEST_BUILD
FloatEventAr *CcOutlet_dbSent = NULL;
APIF void CcOutlet_dbRewindSent() 
{
    if (CcOutlet_dbSent != NULL) {
        FloatEventAr_truncate(CcOutlet_dbSent);    
    }
}
#endif

// This is a decimal version of the binary number 10110000
#define CC_COMMAND 176
APIF void CcOutlet_sendFloat(CcOutlet *self, double value) 
{
#   ifdef TEST_BUILD
    if (CcOutlet_dbSent == NULL) {
        CcOutlet_dbSent = FloatEventAr_new(0);
    }
    FloatEvent e = {.stime = Ticks_dbCurrent, .value = value};
    FloatEventAr_push(CcOutlet_dbSent, e);
#   else
    int v = (int)value;
    AtomAr_changeLength(&self->atoms, 4);
    Atom *av = self->atoms.data;
    av[0] = Atom_fromSymbol(Symbol_gen("midievent"));
    av[1] = Atom_fromInteger(CC_COMMAND);
    av[2] = Atom_fromInteger(self->cc);
    av[3] = Atom_fromInteger(v);
    Error_declare(err);
    Port_send(self->port, 0, 4, av, err);
    Error_maypost(err);   
#   endif
}

APIF CcOutlet *CcOutlet_newBuild(Port *port, int cc)
{
    CcOutlet *self = CcOutlet_new();
    self->port = port;
    self->cc   = cc;
    AtomAr_changeLength(&self->atoms, 4);
    return self;
}

@type 
{
    "typeName": "BendOutlet",
    "fields": [
        {
            "name": "atoms",
            "type": "AtomAr"       
        },       
        {
            "name": "port",
            "type": "Port *"
        }
    ],
    "implements": ["Outlet"]
}
@end

#ifdef TEST_BUILD
FloatEventAr *BendOutlet_dbSent = NULL;
APIF void BendOutlet_dbRewindSent() 
{
    if (BendOutlet_dbSent != NULL) {
        FloatEventAr_truncate(BendOutlet_dbSent);    
    }
}
#endif

#define BEND_COMMAND 224
APIF void BendOutlet_sendFloat(BendOutlet *self, double value)
{
#   ifdef TEST_BUILD
    if (BendOutlet_dbSent == NULL) {
        BendOutlet_dbSent = FloatEventAr_new(0);
    }
    FloatEvent e = {.stime = Ticks_dbCurrent, .value = value};
    FloatEventAr_push(BendOutlet_dbSent, e);
#   else
    int v = (int)value;
    int lsb = v & 0x7F;
    int msb = (v >> 7) & 0x7F;
    AtomAr_changeLength(&self->atoms, 4);
    Atom *av = self->atoms.data;
    av[0] = Atom_fromSymbol(Symbol_gen("midievent"));
    av[1] = Atom_fromInteger(BEND_COMMAND);
    av[2] = Atom_fromInteger(msb);
    av[3] = Atom_fromInteger(lsb);
    Error_declare(err);
    Port_send(self->port, 0, 4, av, err);
    Error_maypost(err);   
#   endif
}

APIF BendOutlet *BendOutlet_newBuild(Port *port)
{
    BendOutlet *self = BendOutlet_new();
    self->port = port;
    AtomAr_changeLength(&self->atoms, 4);
    return self;
}


@type 
{
    "typeName": "VstOutlet",
    "fields": [
        {
            "name": "atoms",
            "type": "AtomAr"       
        },       
        {
            "name": "port",
            "type": "Port *"
        }
    ],
    "implements": ["Outlet"]
}
@end

APIF void VstOutlet_sendFloat(VstOutlet *self, double value)
{
}

@type
{
    "typeName": "NullOutlet",
    "fields": [
        {
            "name": "unused",
            "type": "int"
        }
    ],
    "implements": ["Outlet"]
}
@end


@interface 
{
    "typeName": "Outlet",
    "fields": [
    ],       
    "methods": [
        {
            "name": "sendNote",
            "retVal": "void",
            "args": ["uint8_t", "uint8_t"],
            "absentOk": true
        },
        {
            "name": "sendFloat",
            "retVal": "void",
            "args": ["double"],
            "absentOk": true
        }
    ]
}
@end

@type
{
    "typeName": "OutletSpecifier",
    "fields": [
        {"name": "track",        "type": "Symbol *"},
        {"name": "pluginIndex",  "type": "int"},
        {"name": "parameter",    "type": "Symbol *"},
        {"name": "paramIndex",   "type": "int"}
    ]
}
@end

OutletSpecifier OutletSpecifier_makeCC(Symbol *track, int cc) {
    OutletSpecifier selfValue = {0}, *self = &selfValue;
    OutletSpecifier_init(self);
    self->track       = track;
    self->pluginIndex = 0;
    self->parameter   = Symbol_gen("*cc");
    self->paramIndex  = cc;
    return selfValue;
}

OutletSpecifier OutletSpecifier_makeBend(Symbol *track) {
    OutletSpecifier selfValue = {0}, *self = &selfValue;
    OutletSpecifier_init(self);
    self->track       = track;
    self->pluginIndex = 0;
    self->parameter   = Symbol_gen("*bend");
    self->paramIndex  = 0;
    return selfValue;
}

OutletSpecifier OutletSpecifier_makeNote(Symbol *track) {
    OutletSpecifier selfValue = {0}, *self = &selfValue;
    OutletSpecifier_init(self);
    self->track       = track;
    self->pluginIndex = 0;
    self->parameter   = Symbol_gen("*note");
    self->paramIndex  = 0;
    return selfValue;
}

OutletSpecifier OutletSpecifier_makeVst(Symbol *track, int pluginIndex, Symbol *parameter) {
    OutletSpecifier selfValue = {0}, *self = &selfValue;
    OutletSpecifier_init(self);
    self->track       = track;
    self->pluginIndex = pluginIndex;
    self->parameter   = parameter;
    self->paramIndex  = 0;
    return selfValue;
}


@type
{
  "typeName": "Timed",
  "fields": [
       {"name": "time", "type": "Ticks"},
       {"name": "version", "type": "int"},
       {"name": "sequence", "type": "Sequence *"}
   ],       
  "containers": [
       {
            "type": "array", 
            "typeName": "TimedPq", 
            "elemName": "Timed",
            "binarySearch": [
                {"compare": "Timed_cmp"}
            ]
        }
   ]
}
@end

APIF int Timed_cmp(Timed *left, Timed *right)
{
    if (left->time < right->time) {
        return -1;
    } else if (left->time > right->time) {
        return 1;
    }
    return 0;
}

APIF void TimedPq_enqueue(TimedPq *self, Ticks time, Sequence *s) {
    Sequence_incVersion(s);
    Timed cell = {.time = time, .version = Sequence_version(s), .sequence = s};
    TimedPq_pqPush(self, cell);
}

APIF Sequence *TimedPq_dequeue(TimedPq *self, Ticks current) {
    Timed *peeked = TimedPq_pqPeek(self);

    while (peeked != NULL) {
        if (Timed_time(peeked) > current) {
            break;
        } 

        Timed timed = {0};
        TimedPq_pqPop(self, &timed);
        Sequence *seq = Timed_sequence(&timed);
        if (seq != NULL && Timed_version(&timed) == Sequence_version(seq)) {
            return Timed_sequence(&timed);
        }       
        peeked = TimedPq_pqPeek(self);
    }

    return NULL;
}

APIF void TimedPq_invalidateSequence(TimedPq *self, SequenceAr *removes) 
{
    SequenceAr_sortPointer(removes);
    TimedPq_foreach(it, self) {
        Sequence *seq = Timed_sequence(it.var);
        if (seq == NULL) {
            continue;
        }
        if (SequenceAr_binSearchPointer(removes, seq) != NULL) {
            Timed_setSequence(it.var, NULL);
        }
    }
}



@type 
{
    "typeName": "NoteEvent",
    // DO NOT change order of these fields! This b/c we use argDeclare
    "fields": [
       {"name": "pitch", "type": "uint8_t"},
       {"name": "velocity", "type": "uint8_t"},
       {"name": "stime", "type": "Ticks"},
       {"name": "duration", "type": "Ticks"}
    ], 
    "containers": [
        {
            "type": "array", 
            "typeName": "NoteEventAr", 
            "elemName": "NoteEvent", 
            "binarySearch": [
                {"compare": "NoteEvent_cmp"}
            ]
        }
    ]
}
@end

APIF int NoteEvent_cmp(NoteEvent *left, NoteEvent *right)
{
    if (left->stime < right->stime) {
        return -1;
    } else if (left->stime > right->stime) {
        return 1;
    } else if (left->pitch < right->pitch) {
        return -1;
    } else if (left->pitch > right->pitch) {
        return 1;
    }
    return 0;
}

@type 
{
    "typeName": "NoteSequence",
    "fields":[  
        {
            "name": "version", 
            "type": "long"
        },
        {  
            "name":"startTime",
            "type":"Ticks"
        },
        {  
            "name":"sequenceLength",
            "type":"Ticks"
        },
        {  
            "name":"outletSpecifier",
            "type":"OutletSpecifier"
        },
        {  
            "name":"cursor",
            "type":"int"
        },
        {  
            "name":"cycle",
            "type":"bool"
        },
        {  
            "name":"nextOffEvent",
            "type":"Ticks"
        },
        {  
            "name":"nextOnEvent",
            "type":"Ticks"
        },
        {  
            "name":"inEndgroup",
            "type":"bool"
        },
        
        {  
            "name":"outlet",
            "type":"Outlet *"
        },
        {  
            "name":"recordingSeq",
            "type":"NoteSequence *",
            "lifecycle": "unmanaged"
        },
        {  
            "name":"offs",
            "type":"TimedOffAr"
        },
        {  
            "name":"events",
            "type":"NoteEventAr"
        }
    ],
    "implements": ["Sequence"]
}
@end

APIF NoteSequence *NoteSequence_newTrack(Symbol *track, PortFind *portFind)
{
    NoteSequence *self    = NoteSequence_new();
    self->outletSpecifier = OutletSpecifier_makeNote(track);
    self->outlet          = PortFind_createOutlet(portFind, &self->outletSpecifier);
    return self;
}

APIF NoteSequence *NoteSequence_newFromEvents(Symbol *track, PortFind *portFind, int argc, NoteEvent *argv)
{
    NoteSequence *self = NoteSequence_newTrack(track, portFind);
    NoteEventAr_truncate(&self->events);
    for (int i = 0; i < argc; i++) {
        NoteEventAr_push(&self->events, argv[i]);
    }
    NoteSequence_makeConsistent(self);
    NoteEventAr_rforeach(it, &self->events) {
        self->sequenceLength = it.var->stime;
        break;
    }
    return self;
}

Ticks NoteSequence_cycleDuration      = -1;
Ticks NoteSequence_endgDuration       = -2;
Ticks NoteSequence_noteOffDuration    = -3;
#define NoteSequence_isMarkerValue(v) (v < 0)
#define NoteSequence_minSequenceLength 5
static inline void NoteSequence_playNoteOffs(NoteSequence *self, Ticks current, Error *err) 
{
    self->nextOffEvent = -1;
    int nremoves = 0;
    TimedOffAr_foreach(it, &self->offs) {
        if (it.var->time > current) {
            self->nextOffEvent = it.var->time;
            break;
        }
        Outlet_sendNote(self->outlet, it.var->pitch, 0, err);
        nremoves++;
    }
    if (nremoves > 0) {
        TimedOffAr_removeN(&self->offs, 0, nremoves, err);
        Error_maypost(err);
    }
}

static inline void NoteSequence_playNoteOns(NoteSequence *self, Ticks current, Error *err) 
{
    self->nextOnEvent = -1;
    for (;;) {
        NoteEventAr_foreachOffset(it, &self->events, self->cursor) {
            NoteEvent *ne = it.var;
            if (ne->stime + self->startTime > current) {
                self->nextOnEvent = ne->stime + self->startTime;
                return;
            }
            if (!NoteSequence_isMarkerValue(ne->duration)) {
                TimedOff off = {.time = self->startTime + ne->stime + ne->duration, .pitch = ne->pitch};
                TimedOffAr_binInsertTime(&self->offs, off);
                Outlet_sendNote(self->outlet, ne->pitch, ne->velocity, err);
            } else if (ne->duration == NoteSequence_endgDuration) {
                self->inEndgroup = true;
            } 

            if (self->recordingSeq != NULL && !NoteSequence_isMarkerValue(ne->duration)) {
                NoteEvent e = *ne;
                e.stime     = self->recordingSeq->startTime + ne->stime;
                NoteEventAr_push(&self->recordingSeq->events, e);
            }
            self->cursor++;
        }
        if (self->cycle) {
            if (self->sequenceLength <= NoteSequence_minSequenceLength) {
               self->sequenceLength = NoteSequence_minSequenceLength;
            }
            self->startTime += self->sequenceLength;
            self->cursor     = 0;
        } else {
            return;
        }
    }
}

static inline Ticks NoteSequence_nextEvent(NoteSequence *self) {
    if (self->nextOnEvent < 0 && self->nextOffEvent < 0) {
        return -1;
    } else if (self->nextOffEvent < 0) {
        return self->nextOnEvent;
    } else if (self->nextOnEvent < 0) {
        return self->nextOffEvent;
    } else {
        return self->nextOffEvent < self->nextOnEvent ? self->nextOffEvent : self->nextOnEvent;
    }
}

//
// time and seqTime are related by
//      seqTime = (time-sequenceStartTime) % sequenceLength
//      seqBase = sequenceLength * ((time - sequenceStartTime)/ sequenceLength) + sequenceStartTime
//      time    = seqTime + seqBase 
// Then write 
//      seqTime + seqBase = (time-sequenceStartTime) % sequenceLength + sequenceLength * ((time - sequenceStartTime)/ sequenceLength) + sequenceStartTime
//                        = (time-sequenceStartTime) + sequenceStartTime
//                        = time
// Where the last relation is due to the integer relation
//      n       = n % len + (n/len)*len

APIF void NoteSequence_start(NoteSequence *self, Ticks clockStart, Ticks current, TimedPq *queue, RecordBuffer *recordBuffer, Error *err) 
{
    int nevents = NoteEventAr_len(&self->events);
    if (nevents <= 0) {
        return;
    }

    self->startTime    = self->cycle ? clockStart : current;
    self->cursor       = 0;
    self->inEndgroup   = false;
    Ticks nextEvent    = 0;
    if (self->cycle) {
        if (self->sequenceLength <= NoteSequence_minSequenceLength) {
            self->sequenceLength = NoteSequence_minSequenceLength;
        }
        while (current - self->startTime > self->sequenceLength) {
            self->startTime += self->sequenceLength;
        }

        NoteEventAr_foreach(it, &self->events) {
            if (it.var->stime + self->startTime > current) {
                nextEvent = it.var->stime + self->startTime;
                break;
            }
            self->cursor++;
        }
        if (self->cursor >= nevents) {
            self->startTime += self->sequenceLength;
            nextEvent        = self->startTime;
            self->cursor     = 0;
        }
    } else {
        NoteEventAr_foreach(it, &self->events) {
            nextEvent = it.var->stime + self->startTime;
            break;
        }
    }

    self->recordingSeq = NULL;
    if (recordBuffer != NULL) {
        NoteSequence *other = NoteSequence_recordClone(self);
        other->startTime    = self->startTime;
        self->recordingSeq  = other; 
        RecordBuffer_push(recordBuffer, NoteSequence_castToSequence(other));
    }

    TimedPq_enqueue(queue, nextEvent, NoteSequence_castToSequence(self));
}

APIF void NoteSequence_stop(NoteSequence *self, Ticks current, Error *err) {
    self->cursor       = NoteEventAr_len(&self->events);
    self->version++;

    if (self->recordingSeq != NULL) {
        // In the recording sequence Adjust the duration of all the pending note-offs
        TimedOffAr_foreach(offIt, &self->offs) {
            NoteEventAr_rforeach(noteIt, &self->recordingSeq->events) {
                if (noteIt.var->pitch == offIt.var->pitch) {
                    noteIt.var->duration = current - noteIt.var->stime;
                    break;
                }
            }
        } 
        self->recordingSeq = NULL;
    }
    
    NoteSequence_playNoteOffs(self, Ticks_maxTime, err);
}

APIF void NoteSequence_drive(NoteSequence *self, Ticks current, TimedPq *queue, Error *err) 
{
    NoteSequence_playNoteOffs(self, current, err);
    NoteSequence_playNoteOns(self, current, err);
    Ticks nextEvent = NoteSequence_nextEvent(self);
    if (nextEvent >= 0) {
        TimedPq_enqueue(queue, nextEvent, NoteSequence_castToSequence(self));
    }
}

APIF void NoteSequence_padNoteOff(NoteSequence *self, int padIndex, Ticks current, Error *err) 
{
    if (self->inEndgroup && !self->cycle) {
        NoteSequence_stop(self, current, err);
    }
}

APIF OutletSpecifier *NoteSequence_outSpec(NoteSequence *self)
{
    return &self->outletSpecifier;
}

APIF NoteSequence *NoteSequence_recordClone(NoteSequence *self)
{
    NoteSequence *other    = NoteSequence_new();
    other->outletSpecifier = self->outletSpecifier;
    other->outlet          = NullOutlet_castToOutlet(NullOutlet_new());
    return other;
}   

APIF void NoteSequence_makeConsistent(NoteSequence *self)
{
    int timeNextNoteStart[128] = {0};
    for (int i = 0; i < 128; i++) {
        timeNextNoteStart[i] = INT_MAX;
    }
    NoteEventAr_sort(&self->events);
    NoteEventAr_rforeach(it, &self->events) {
        if (it.var->stime + it.var->duration > timeNextNoteStart[it.var->pitch]) {
            it.var->duration = timeNextNoteStart[it.var->pitch] - it.var->stime;
            if (it.var->duration <= 0) {
                // This is the case when the same note is played at the same time. Notice we
                NoteEventArRIt_remove(&it);
                continue;        
            }
        }
        timeNextNoteStart[it.var->pitch] = it.var->stime;
    }
}

@type
{
    "typeName": "FloatEvent",
    // DO NOT change order of these fields! This b/c we use argDeclare
    "fields": [
       {"name": "stime", "type": "Ticks"},
       {"name": "value", "type": "double"}
    ],
    "containers": [
        {
            "type": "array", 
            "typeName": "FloatEventAr", 
            "elemName": "FloatEvent",
            "binarySearch": [
                {"compare": "FloatEvent_cmp"}
            ]
        }
    ]
}
@end

APIF int FloatEvent_cmp(FloatEvent *left, FloatEvent *right)
{
    if (left->stime < right->stime) {
        return -1;
    } else if (left->stime > right->stime) {
        return 1;
    }
    return 0;
}

@type 
{
    "typeName": "FloatSequence",
    "fields":[  
        {
            "name": "version", 
            "type": "long"
        },
        {  
            "name":"startTime",
            "type":"Ticks"
        },
        {  
            "name":"sequenceLength",
            "type":"Ticks"
        },
        {  
            "name":"outletSpecifier",
            "type":"OutletSpecifier"
        },
        {  
            "name":"cursor",
            "type":"int"
        },
        {  
            "name":"cycle",
            "type":"bool"
        },
        {  
            "name":"inEndgroup",
            "type":"bool"
        },
        {  
            "name":"outlet",
            "type":"Outlet *"
        },
        {  
            "name":"recordingSeq",
            "type":"FloatSequence *",
            "lifecycle": "unmanaged"
        },
        {  
            "name":"events",
            "type":"FloatEventAr"
        },
        {
            "name": "restoreValue",
            "type": "double"
        }
    ], 
    "implements": ["Sequence"]
}
@end

APIF FloatSequence *FloatSequence_newCc(Symbol *track, int cc, PortFind *portFind) 
{
    FloatSequence *self   = FloatSequence_new();
    self->outletSpecifier = OutletSpecifier_makeCC(track, cc);
    self->outlet          = PortFind_createOutlet(portFind, &self->outletSpecifier);
    return self;
}

APIF FloatSequence *FloatSequence_newBend(Symbol *track, PortFind *portFind) 
{
    FloatSequence *self   = FloatSequence_new();
    self->outletSpecifier = OutletSpecifier_makeBend(track);
    self->outlet          = PortFind_createOutlet(portFind, &self->outletSpecifier);
    return self;
}

APIF FloatSequence *FloatSequence_newFromEvents(Symbol *track, int ccOrNegForBend, PortFind *portFind, int argc, FloatEvent *argv) 
{
    FloatSequence *self = NULL;
    if (ccOrNegForBend >= 0) {
        self = FloatSequence_newCc(track, ccOrNegForBend, portFind);
    } else {
        self = FloatSequence_newBend(track, portFind);
    }
    FloatEventAr_truncate(&self->events);
    for (int i = 0; i < argc; i++) {
        FloatEventAr_push(&self->events, argv[i]);
    }
    FloatSequence_makeConsistent(self);
    return self;
}


double FloatSequence_endgMarker  = -1.0e40;
double FloatSequence_cycleMarker = -1.0e41;
#define FloatSequence_isMarkerValue(v) (v < 1e10)

APIF void FloatSequence_start(FloatSequence *self, Ticks clockStart, Ticks current, TimedPq *queue, RecordBuffer *recordBuffer, Error *err) {
    int nevents = FloatEventAr_len(&self->events);
    if (nevents <= 0) {
        return;
    }

    self->startTime    = self->cycle ? clockStart : current;
    self->cursor       = 0;
    self->inEndgroup   = false;
    Ticks nextEvent    = 0;
    if (self->cycle) {
        if (self->sequenceLength <= NoteSequence_minSequenceLength) {
            self->sequenceLength = NoteSequence_minSequenceLength;
        }
        while (current-self->startTime > self->sequenceLength) {
            self->startTime += self->sequenceLength;
        }

        FloatEventAr_foreach(it, &self->events) {
            if (it.var->stime + self->startTime > current) {
                nextEvent = it.var->stime + self->startTime;
                break;
            }
            self->cursor++;
        }
        if (self->cursor >= nevents) {
            self->startTime += self->sequenceLength;
            nextEvent        = self->startTime;
            self->cursor     = 0;
        }
    } else {
        FloatEventAr_foreach(it, &self->events) {
            nextEvent = it.var->stime + self->startTime;
            break;
        }
    }

    self->recordingSeq = NULL;
    if (recordBuffer != NULL) {
        FloatSequence *other = FloatSequence_recordClone(self);
        other->startTime    = self->startTime;
        self->recordingSeq  = other;    
        RecordBuffer_push(recordBuffer, FloatSequence_castToSequence(other));
    }

    TimedPq_enqueue(queue, nextEvent, FloatSequence_castToSequence(self));
}

APIF void FloatSequence_stop(FloatSequence *self, Ticks current, Error *err) {
    self->cursor       = FloatEventAr_len(&self->events);
    self->recordingSeq = NULL;
    Outlet_sendFloat(self->outlet, self->restoreValue, err);
}

APIF void FloatSequence_drive(FloatSequence *self, Ticks current, TimedPq *queue, Error *err) {
    Ticks nextEvent = -1;
    for (;;) {
        FloatEventAr_foreachOffset(it, &self->events, self->cursor) {
            FloatEvent *fe = it.var;
            if (fe->stime + self->startTime > current) {
                nextEvent = fe->stime + self->startTime;
                goto DONE;
            }
            if (fe->value == FloatSequence_endgMarker) {
                self->inEndgroup = true;
            } else if (fe->value == FloatSequence_cycleMarker) {
                // Do nothing
            } else {
                Outlet_sendFloat(self->outlet, fe->value, err);
            }

            if (self->recordingSeq != NULL && !FloatSequence_isMarkerValue(fe->value)) {
                FloatEvent e = *fe;
                e.stime      = self->recordingSeq->startTime + fe->stime;
                FloatEventAr_push(&self->recordingSeq->events, e);
            }
            self->cursor++;
        }
        if (self->cycle) {
            if (self->sequenceLength <= NoteSequence_minSequenceLength) {
                self->sequenceLength = NoteSequence_minSequenceLength;
            }
            self->startTime += self->sequenceLength;
            self->cursor     = 0;
        } else {
            goto DONE;
        }
    }
   DONE:
    if (nextEvent >= 0) {
        TimedPq_enqueue(queue, nextEvent, FloatSequence_castToSequence(self));
    }
}

APIF void FloatSequence_padNoteOff(FloatSequence *self, int padIndex, Ticks current, Error *err) {
    if (self->inEndgroup) {
        Outlet_sendFloat(self->outlet, self->restoreValue, err);
    }
}

APIF OutletSpecifier *FloatSequence_outSpec(FloatSequence *self)
{
    return &self->outletSpecifier;
}

APIF FloatSequence *FloatSequence_recordClone(FloatSequence *self)
{
    FloatSequence *other   = FloatSequence_new();
    other->outletSpecifier = self->outletSpecifier;
    other->outlet          = NullOutlet_castToOutlet(NullOutlet_new());
    return other;
}

APIF void FloatSequence_makeConsistent(FloatSequence *self)
{
    FloatEventAr_sort(&self->events);
    double seen = -1;
    FloatEventAr_rforeach(it, &self->events) {
        if (seen == it.var->stime) {
            FloatEventArRIt_remove(&it);
        }
        seen = it.var->stime;
    }
}


@interface
{
    "typeName": "Sequence",
    "fields": [
        {
            "name": "version", 
            "type": "long"
        }
    ],
    "methods": [

        // Methods to play sequences
        {
            "name": "start",
            "retVal": "void",
            "args": ["Ticks", "Ticks", "TimedPq *", "RecordBuffer *", "Error *"]
        },
        {
            "name": "drive",
            "retVal": "void",
            "args": ["Ticks", "TimedPq *", "Error *"]
        },
        {
            "name": "stop",
            "retVal": "void",
            "args": ["Ticks", "Error *"]
        },
        {
            "name": "padNoteOff",
            "retVal": "void",
            "args": ["int", "Ticks", "Error *"]
        },

        // Configure sequence
        {
            "name": "setCycle",
            "retVal": "void",
            "args": ["bool"]
        },

        // Lifecycle
        {
            "name": "free",
            "retVal": "void",
            "args": []
        },

        // Comparison helper
        {
            "name": "outSpec",
            "retVal": "OutletSpecifier *",
            "args": []
        }


    ],
    "containers": [
        {
            "type": "array", 
            "typeName": "SequenceAr", 
            "elemName": "Sequence *",
            "clearer": "Sequence_freePpErrless",
            "binarySearch": [
                {"compare": "Sequence_cmpPp"},
                {"compare": "Sequence_cmpPointerPp", "tag": "Pointer"}
            ]
        }
    ]
}
@end

APIF void Sequence_freePpErrless(Sequence **s)
{
    Error_declare(err);
    Sequence_free(*s, err);
    Error_maypost(err);
}

APIF int Sequence_cmp(Sequence *leftSeq, Sequence *rightSeq) {
    Error_declare(err);
    OutletSpecifier *left  = Sequence_outSpec(leftSeq, err);
    OutletSpecifier *right = Sequence_outSpec(rightSeq, err);
    Error_clear(err);

    int q = Symbol_cmp(OutletSpecifier_track(left), OutletSpecifier_track(right));
    if (q) {
        return q;
    }

    int leftPi  = OutletSpecifier_pluginIndex(left);
    int rightPi = OutletSpecifier_pluginIndex(right);
    if (leftPi < rightPi) {
        return -1;
    } else if (leftPi > rightPi) {
        return 1;
    }

    q = Symbol_cmp(OutletSpecifier_parameter(left), OutletSpecifier_parameter(right));
    if (q) {
        return q;
    }    

    leftPi  = OutletSpecifier_paramIndex(left);
    rightPi = OutletSpecifier_paramIndex(right);
    if (leftPi < rightPi) {
        return -1;
    } else if (leftPi > rightPi) {
        return 1;
    }    

    return 0;
}

APIF int Sequence_cmpPointer(Sequence *leftSeq, Sequence *rightSeq) {
    if (leftSeq < rightSeq) {
        return -1;
    }  else if (leftSeq > rightSeq) {
        return 1;
    }

    return 0;
}

APIF int Sequence_cmpPp(Sequence **left, Sequence **right) {
    return Sequence_cmp(*left, *right);
}

APIF int Sequence_cmpPointerPp(Sequence **left, Sequence **right)
{
    return Sequence_cmpPointer(*left, *right);
}

APIF void Sequence_incVersion(Sequence *seq) {
    seq->version++;
}

@type
{
    "typeName": "RecordBuffer",
    "fields": [
        {
            "name": "recordStart", 
            "type": "Ticks"
        },
        {
            "name": "sequences", 
            "type": "SequenceAr"
        }
    ]
}
@end

APIF void RecordBuffer_push(RecordBuffer *self, Sequence *sequence)
{
    SequenceAr_push(&self->sequences, sequence);
}


enum {
    Midi_noteEventType   = 1,
    Midi_ccEventType     = 2,
    Midi_bendEventType   = 3,
    Midi_headerEventType = 4,
    Midi_eofEventType    = 5
};

typedef struct MidiEvent_t {
    int type;
    Ticks time;
    long arg1;
    long arg2;
} MidiEvent;

MidiEvent Midi_getNextEvent(FILE *pipe, Error *err)
{
    static String *buffer       = NULL;
    static StringPtAr *arBuffer = NULL;
    if (buffer == NULL) {
        buffer   = String_empty();
        arBuffer = StringPtAr_new(0);
    }
    
    MidiEvent event = {0}, zero = {0};
    for (;;) {
        event      = zero;
        event.type = Midi_eofEventType;
        if (!String_readline(&buffer, pipe, err)) {
            return event;
        }

        String_split(buffer, ",", arBuffer);
        StringPtAr_foreach(it, arBuffer) {
            String_trim(it.var);
        }

        if (StringPtAr_len(arBuffer) < 3) {
            Error_format0(err, "Not enough fields in midicsv file");
            return event;
        }

        String *timeString = StringPtAr_get(arBuffer, 1, err);
        Error_returnValueOnError(err, event);
        event.time = String_toInteger(timeString, err);
        Error_returnValueOnError(err, event);

        String *type = StringPtAr_get(arBuffer, 2, err);
        Error_returnValueOnError(err, event);

        if (String_cequal(type, "Note_off_c") || String_cequal(type, "Note_on_c")) {
            event.type = Midi_noteEventType;
            if (StringPtAr_len(arBuffer) < 6) {
                Error_format0(err, "Bad Note_off/on_c");
                return event;
            }
        } else if (String_cequal(type, "Pitch_bend_c")) {
            event.type = Midi_bendEventType;
            if (StringPtAr_len(arBuffer) < 5) {
                Error_format0(err, "Bad Pitch_bend_c");
                return event;
            }
        } else if (String_cequal(type, "Control_c")) {
            event.type = Midi_ccEventType;
            if (StringPtAr_len(arBuffer) < 6) {
                Error_format0(err, "Bad Control_c");
                return event;
            }
        } else if (String_cequal(type, "Header")) {
            if (StringPtAr_len(arBuffer) < 6) {
                Error_format0(err, "Bad Control_c");
                return event;
            }
        } else {
            continue;
        }

        break;
    }
    
    String *arg1 = StringPtAr_get(arBuffer, 4, err);
    Error_returnValueOnError(err, event);
    event.arg1 = String_toInteger(arg1, err); 
    
    if (event.type != Midi_bendEventType) {
        String *arg2 = StringPtAr_get(arBuffer, 5, err);
        Error_returnValueOnError(err, event);
        event.arg2 = String_toInteger(arg2, err); 
    }

    return event;
}

APIF void Midi_fromfile(const char *midiFilePath, SequenceAr *output, Symbol *defaultTrack, PortFind *portFind, Error *err)
{
    static String *midiCsvExecPath = NULL;
    if (midiCsvExecPath == NULL) {
        midiCsvExecPath = String_fmt("%s/packages/midicsv-1.1/midicsv", CSEQ_HOME);
    }

    String *buffer = String_fmt("'%s' '%s'", midiCsvExecPath, midiFilePath);    
    FILE *pipe = popen(buffer, "r");
    if (pipe == NULL) {
        Error_format(err, "Failed to create pipe for command `%s`", midiCsvExecPath);
        return;
    }
//NullOutlet_castToOutlet(NullOutlet_new());
    //
    // Loop and collect events. Write them into each sequence type
    //
    MusicalContext_declareDefault(musicalContext);
    float tickFactor = 1.0;
    NoteSequence *noteSeq   = NULL;
    FloatSequence *bendSeq   = NULL;
    FloatSequence *ccSeqs[128] = {NULL};
    for (;;) {
        MidiEvent ev = Midi_getNextEvent(pipe, err);
        Error_returnVoidOnError(err);

        if (ev.type == Midi_eofEventType) {
            break;
        }

        switch (ev.type) {
            case Midi_noteEventType: {
                if (noteSeq == NULL) {
                    noteSeq = NoteSequence_newTrack(defaultTrack, portFind);
                }
                if (ev.arg2 == 0) {
                    bool found = false;
                    NoteEventAr_rforeach(it, &noteSeq->events) {
                        if (it.var->pitch == ev.arg1) {
                            if (it.var->duration != NoteSequence_noteOffDuration) {
                                Error_format(err, "Found unpaired note-off at %lld", ev.time);
                                goto END;
                            }
                            it.var->duration = ev.time-it.var->stime;
                            found            = true;
                            break;
                        }
                    }
                    if (!found) {
                        Error_format(err, "Failed to find paired note-on for note-off at %lld", ev.time);
                        goto END;
                    }
                } else {
                    NoteEvent newEv = {.pitch = ev.arg1, .velocity = ev.arg2, .stime = ev.time, .duration = NoteSequence_noteOffDuration};
                    NoteEventAr_push(&noteSeq->events, newEv);
                }
                break;
            }
            case Midi_bendEventType: {
                if (bendSeq == NULL) {
                    bendSeq = FloatSequence_newBend(defaultTrack, portFind);
                }
                FloatEvent newEv = {.stime = ev.time, .value = (double)ev.arg1};
                FloatEventAr_push(&bendSeq->events, newEv);
                break;
            }
            case Midi_ccEventType: {
                if (ccSeqs[ev.arg1] == NULL) {
                    ccSeqs[ev.arg1] = FloatSequence_newCc(defaultTrack, ev.arg1, portFind);
                }
                FloatEvent newEv = {.stime = ev.time, .value = (double)ev.arg2};
                FloatEventAr_push(&(ccSeqs[ev.arg1])->events, newEv);
                break;
            }
            case Midi_headerEventType: {
                long ppqn = ev.arg2;
                tickFactor = (float)(musicalContext.ticksPerQuarterNote)/(float)(ppqn);
                break;    
            }
        }
    }


    //
    // Try and compute endgroup
    //
    Ticks endGroupTime = 0;
    if (noteSeq != NULL) {
        NoteEventAr_rforeach(it, &noteSeq->events) {
            if (it.var->duration == NoteSequence_noteOffDuration) {
                Error_format(err, "Unpaired note-on at %lld", it.var->stime);
                goto END;
            }
        }

        // Install endgroup
        Ticks endTime = -1;
        int endIndex  = -1;
        NoteEventAr_rforeach(it, &noteSeq->events) {
            if (endTime < 0) {
                endTime  = it.var->stime;
                endIndex = it.index;
                continue;
            } else if (it.var->stime != endTime) {
                break;
            } else {
                endIndex = it.index;
            }
        }
        if (endTime >= 0) {
            NoteEvent newEv = {.stime = endTime, .duration = NoteSequence_endgDuration, .pitch = 0, .velocity = 0};
            NoteEventAr_insert(&noteSeq->events, endIndex, newEv, err);
            Error_gotoLabelOnError(err, END);
            endGroupTime = endTime;
        } 
    }

    
    if (bendSeq != NULL) {
        int insertIndex = 0;
        FloatEventAr_rforeach(it, &bendSeq->events) {
            if (it.var->stime > endGroupTime) {
                insertIndex = it.index;
            } else {
                break;
            }
        }
        FloatEvent newEv = {.stime = endGroupTime, .value = FloatSequence_endgMarker};
        FloatEventAr_insert(&bendSeq->events, insertIndex, newEv, err);
    }
    for (int i = 0; i < 128; i++) {
        if (ccSeqs[i] != NULL) {
            int insertIndex = 0;
            FloatEventAr_rforeach(it, &bendSeq->events) {
                if (it.var->stime > endGroupTime) {
                    insertIndex = it.index;
                } else {
                    break;
                }
            }
            FloatEvent newEv = {.stime = endGroupTime, .value = FloatSequence_endgMarker};
            FloatEventAr_insert(&(ccSeqs[i]->events), insertIndex, newEv, err);
            Error_gotoLabelOnError(err, END);       
        }
    }


    //
    // Compute length
    //
    Ticks lastTime = 0;
    if (noteSeq != NULL) {
        NoteEventAr_rforeach(it, &noteSeq->events) {
            if (it.var->stime > lastTime) {
                lastTime = it.var->stime;
            }
            break;
        }
    }
    if (bendSeq != NULL) {
        FloatEventAr_rforeach(it, &bendSeq->events) {
            if (it.var->stime > lastTime) {
                lastTime = it.var->stime;
            }
            break;
        }
    }
    for (int i = 0; i < 128; i++) {
        if (ccSeqs[i] != NULL) {
            FloatEventAr_rforeach(it, &(ccSeqs[i]->events)) {
                if (it.var->stime > lastTime) {
                    lastTime = it.var->stime;
                }
                break;
            }       
        }
    }

    Ticks mlen   = musicalContext.quarterNotesPerMeasure*musicalContext.ticksPerQuarterNote;
    Ticks seqLen = (lastTime/mlen)*mlen + (lastTime % mlen == 0 ? 0 : mlen);
    if (seqLen < NoteSequence_minSequenceLength) {
        seqLen = NoteSequence_minSequenceLength;
    }
    //
    // Set each sequence length
    //
    if (noteSeq != NULL) {
        noteSeq->sequenceLength = seqLen;
        NoteEvent newEv = {.stime = seqLen, .duration = NoteSequence_cycleDuration, .pitch = 0, .velocity = 0};
        NoteEventAr_push(&noteSeq->events, newEv);
    }
    if (bendSeq != NULL) {
        bendSeq->sequenceLength = seqLen;
        FloatEvent newEv = {.stime = seqLen, .value = FloatSequence_cycleMarker};
        FloatEventAr_push(&bendSeq->events, newEv);
    }
    for (int i = 0; i < 128; i++) {
        if (ccSeqs[i] != NULL) {
            ccSeqs[i]->sequenceLength = seqLen;
            FloatEvent newEv = {.stime = seqLen, .value = FloatSequence_cycleMarker};
            FloatEventAr_push(&(ccSeqs[i]->events), newEv);       
        }
    }

  END:
    if (pipe != NULL) {
        pclose(pipe);
    }
    if (Error_iserror(err)) {
        if (noteSeq != NULL) {
            NoteSequence_free(noteSeq);
        }
        if (bendSeq != NULL) {
            FloatSequence_free(bendSeq);
        }
        for (int i = 0; i < 128; i++) {
            if (ccSeqs[i] != NULL) {
                FloatSequence_free(ccSeqs[i]);
            }
        }
        return;
    }

    //
    // Populate output array
    //
    SequenceAr_truncate(output);
    if (noteSeq != NULL) {
        NoteSequence_makeConsistent(noteSeq);
        SequenceAr_push(output, NoteSequence_castToSequence(noteSeq));
    }
    if (bendSeq != NULL) {
        FloatSequence_makeConsistent(bendSeq);
        SequenceAr_push(output, FloatSequence_castToSequence(bendSeq));
    }
    for (int i = 0; i < 128; i++) {
        if (ccSeqs[i] != NULL) {
            FloatSequence_makeConsistent(ccSeqs[i]);
            SequenceAr_push(output, FloatSequence_castToSequence(ccSeqs[i]));
        }
    }
    SequenceAr_sort(output);
}

//
//
//
/*
APIF void Frontend_recievedPadHit(Hub *hub, long pitchIn, long velocityIn){
	Error_declare(err);
    int padIndex = Hub_padIndexFromInNote(hub, pitchIn);
    if (padIndex >= PadAr_len(PadList_pads(Hub_padList(hub)))) {
        post("Bad padIndex %d", padIndex);
        return;
    }

    if (velocityIn == 0) {
        Pad *pad = PadList_pad(Hub_padList(x), padIndex, err);
        if (Error_maypost(err)) {
            return;
        }
        Pad_setNoteReleasePending(pad, false);
        SequenceAr_foreach(it, Pad_sequenceList(pad)) {
        Sequence_padNoteOff(it.var);
    }
    return;
    }

    if (Hub_grabNextTappedPad(hub)) {
      Hub_setGrabNextTappedPad(hub, false); 
      Hub_changeSelectedPad(hub, padIndex, err);
      Error_maypost(err);
    }


    Ticks now = Ticks_now();
    Ticks clockStart = Pad_useMasterClock(pad) ? Hub_masterClock(hub) : now;
    SequenceAr_foreach(it, Pad_sequenceList(pad)) {
       SequenceAr_binInsertSeqPt(Hub_runningSequences(hub), it.var);
       Sequence_start(it.var, clockStart, now, Hub_queue(hub), Hub_recordBuffer(hub));
    }

    Error_clear(err);
}

APIF void Frontend_drive(Hub *hub) {
	Ticks now = Ticks_now();
	TimedPq *queue = Hub_queue(hub);
	Sequence *seq = TimedPq_dequeue(queue);
	while (seq != NULL) {
		Sequence_drive(seq, now, queue);
		seq = TimedPq_dequeue(queue);
	}
}

APIF void Frontend_stop(Hub *hub) {
	SequenceAr_foreach(it, Hub_runningSequences(hub)) {
		Sequence_stop(it.var);
	}
}
*/