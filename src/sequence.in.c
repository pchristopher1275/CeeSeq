
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
    // printf("OUTLET pitch=%d velocity=%d\n", pitch, velocity);
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

COVER void OutletSpecifier_dbPrint(OutletSpecifier *self)
{
    printf("OutletSpecifier %s %d %s %d\n", Symbol_cstr(self->track), self->pluginIndex, Symbol_cstr(self->parameter), self->paramIndex);
}

COVER OutletSpecifier OutletSpecifier_makeCC(Symbol *track, int cc) {
    OutletSpecifier selfValue = {0}, *self = &selfValue;
    OutletSpecifier_init(self);
    self->track       = track;
    self->pluginIndex = 0;
    self->parameter   = Symbol_gen("*cc");
    self->paramIndex  = cc;
    return selfValue;
}

COVER OutletSpecifier OutletSpecifier_makeBend(Symbol *track) {
    OutletSpecifier selfValue = {0}, *self = &selfValue;
    OutletSpecifier_init(self);
    self->track       = track;
    self->pluginIndex = 0;
    self->parameter   = Symbol_gen("*bend");
    self->paramIndex  = 0;
    return selfValue;
}

COVER OutletSpecifier OutletSpecifier_makeNote(Symbol *track) {
    OutletSpecifier selfValue = {0}, *self = &selfValue;
    OutletSpecifier_init(self);
    self->track       = track;
    self->pluginIndex = 0;
    self->parameter   = Symbol_gen("*note");
    self->paramIndex  = 0;
    return selfValue;
}

COVER OutletSpecifier OutletSpecifier_makeVst(Symbol *track, int pluginIndex, Symbol *parameter) {
    OutletSpecifier selfValue = {0}, *self = &selfValue;
    OutletSpecifier_init(self);
    self->track       = track;
    self->pluginIndex = pluginIndex;
    self->parameter   = parameter;
    self->paramIndex  = 0;
    return selfValue;
}

COVER OutletSpecifier OutletSpecifier_makeAudio() {
    // Every audio sequence sorts equal. So every audio sequence shares the same config for OutletSpecifier
    OutletSpecifier selfValue = {0}, *self = &selfValue;
    OutletSpecifier_init(self);
    self->track       = Symbol_gen("*audio");
    self->pluginIndex = 0;
    self->parameter   = Symbol_gen("*audio");
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

Ticks NoteSequence_cycleDuration   = -1;
Ticks NoteSequence_endgDuration    = -2;
Ticks NoteSequence_noteOffDuration = -3;

APIF int NoteEvent_cmp(NoteEvent *left, NoteEvent *right)
{
    if (left->stime < right->stime) {
        return -1;
    } else if (left->stime > right->stime) {
        return 1;
    } 

    // This sorts cycle to the end of equal time, and endgroup to the begining of equal time.
    Coverage_off;
    Ticks leftDuration = left->duration >= 0 ? left->duration : 
                         left->duration == NoteSequence_cycleDuration ? Ticks_maxTime :
                         left->duration == NoteSequence_endgDuration ? -Ticks_maxTime : left->duration;
    Ticks rightDuration = right->duration >= 0 ? right->duration : 
                          right->duration == NoteSequence_cycleDuration ? Ticks_maxTime :
                          right->duration == NoteSequence_endgDuration ? -Ticks_maxTime : right->duration;
    Coverage_on;
    if (leftDuration < rightDuration) {
        return -1;
    } else if (leftDuration > rightDuration) {
        return 1;
    }

    if (left->pitch < right->pitch) {
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
            "name":"outletSpecifier",
            "type":"OutletSpecifier"
        },
        {  
            "name":"sequenceLength",
            "type":"Ticks"
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

#define NoteSequence_isMarkerValue(v) (v < 0)
#define Sequence_minSequenceLength 5

APIF NoteSequence *NoteSequence_newTrack(Symbol *track, PortFind *portFind)
{
    // XXX: I don't know if this should be a legal new! 
    NoteSequence *self    = NoteSequence_new();
    self->outletSpecifier = OutletSpecifier_makeNote(track);
    self->outlet          = PortFind_createOutlet(portFind, &self->outletSpecifier);
    return self;
}

APIF NoteSequence *NoteSequence_newFromEvents(Symbol *track, PortFind *portFind, int argc, NoteEvent *argv, Error *err)
{
    if (argc <= 0) {
        Error_format0(err, "Bad argc passed to newFromEvents");
        goto END;
    }

    NoteSequence *self = NoteSequence_newTrack(track, portFind);
    NoteEventAr_truncate(&self->events);
    for (int i = 0; i < argc; i++) {
        NoteEventAr_push(&self->events, argv[i]);
    }
    NoteEventAr_sort(&self->events);

    NoteEvent last = NoteEventAr_get(&self->events, NoteEventAr_last(&self->events), err);
    Error_returnNullOnError(err);

    if (last.duration != NoteSequence_cycleDuration) {
        Error_format0(err, "Called newFromEvents without proper cycle marker");
        goto END;
    }
    self->sequenceLength = last.stime;
    NoteSequence_makeConsistent(self, err);

  END:
    if (Error_iserror(err)) {
        NoteSequence_free(self);
        return NULL;
    }
    return self;
}

COVER static inline void NoteSequence_playNoteOffs(NoteSequence *self, Ticks current, Error *err) 
{
    self->nextOffEvent = Ticks_maxTime;
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

COVER static inline void NoteSequence_playEvents(NoteSequence *self, Ticks current, Error *err) 
{
    self->nextOnEvent = Ticks_maxTime;
    for (;;) {
        NoteEventAr_foreachOffset(it, &self->events, self->cursor) {
            NoteEvent *ne = it.var;
            if (ne->stime + self->startTime > current) {
                self->nextOnEvent = ne->stime + self->startTime;
                return;
            }
            if (!NoteSequence_isMarkerValue(ne->duration)) {
                // Queue the note off
                TimedOff off = {.time = self->startTime + ne->stime + ne->duration, .pitch = ne->pitch};
                TimedOffAr_binInsertTime(&self->offs, off);
                if (self->nextOffEvent > off.time) {
                    self->nextOffEvent = off.time;
                }

                // Play the note on
                Outlet_sendNote(self->outlet, ne->pitch, ne->velocity, err);
            } else if (ne->duration == NoteSequence_endgDuration && !self->cycle) {
                self->inEndgroup = true;
            } 

            if (self->recordingSeq != NULL && !NoteSequence_isMarkerValue(ne->duration)) {
                NoteEventAr_push(&self->recordingSeq->events, *ne);
            }
            self->cursor++;
        }
        if (self->cycle) {
            if (self->sequenceLength <= Sequence_minSequenceLength) {
               self->sequenceLength = Sequence_minSequenceLength;
            }
            self->startTime += self->sequenceLength;
            self->cursor     = 0;
        } else {
            return;
        }
    }
}

COVER static inline Ticks NoteSequence_nextEvent(NoteSequence *self) {
    bool maxOff = self->nextOffEvent == Ticks_maxTime;
    bool maxOn  = self->nextOnEvent  == Ticks_maxTime;
    if (maxOff && maxOn) {
        return -1;
    } else if (maxOff) {
        return self->nextOnEvent;
    } else if (maxOn) {
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
        if (self->sequenceLength <= Sequence_minSequenceLength) {
            self->sequenceLength = Sequence_minSequenceLength;
        }
        while (current - self->startTime > self->sequenceLength) {
            self->startTime += self->sequenceLength;
        }

        NoteEventAr_foreach(it, &self->events) {
            if (it.var->stime + self->startTime >= current) {
                nextEvent = it.var->stime + self->startTime;
                break;
            }
            self->cursor++;
        }
        if (self->cursor >= nevents) {
            Error_format0(err, "INTERNAL ERROR: cursor found to be >= nevents");
            return;
        }
    } else {
        NoteEventAr_foreach(it, &self->events) {
            nextEvent = it.var->stime + self->startTime;
            break;
        }
    }
    self->recordingSeq = NULL;
    if (recordBuffer != NULL) {
        NoteSequence *other = NoteSequence_castFromSequence(NoteSequence_compactNew(self, self->startTime));
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
                    noteIt.var->duration = current - (self->startTime + noteIt.var->stime);
                    if (noteIt.var->duration <= 0) {
                        // Silently ignore this condition
                        NoteEventArRIt_remove(&noteIt);
                    }
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
    NoteSequence_playEvents(self, current, err);
    Ticks nextEvent = NoteSequence_nextEvent(self);
    if (nextEvent >= 0) {
        TimedPq_enqueue(queue, nextEvent, NoteSequence_castToSequence(self));
    }
}

APIF void NoteSequence_padNoteOff(NoteSequence *self, Ticks current, Error *err) 
{
    if (self->inEndgroup && !self->cycle) {
        NoteSequence_stop(self, current, err);
    }
}

APIF void NoteSequence_makeConsistent(NoteSequence *self, Error *err)
{
    if (NoteEventAr_len(&self->events) < 1) {
        Error_format0(err, "Called makeConsistent on empty sequence");
        return;
    }

    NoteEventAr_sort(&self->events);

    NoteEvent last = NoteEventAr_get(&self->events, NoteEventAr_last(&self->events), err);
    Error_returnVoidOnError(err);

    if (last.duration != NoteSequence_cycleDuration) {
        Error_format0(err, "Called makeConsistent without proper cycle marker");
        return;
    }

    if (last.stime != self->sequenceLength) {
        Error_format0(err, "Called cycle marker and sequenceLength are inconsistent");
        return;
    }

    int timeNextNoteStart[128] = {0};
    for (int i = 0; i < 128; i++) {
        timeNextNoteStart[i] = INT_MAX;
    }
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
    return;
}

APIF Sequence *NoteSequence_compactNew(NoteSequence *self, Ticks recordStart)
{
    NoteSequence *other    = NoteSequence_new();
    // WHen we create a compact sequence, we always set it's startTime to the recordStart which is <= than all the startTimes in the RecordBuffer
    other->startTime       = recordStart;
    other->outletSpecifier = self->outletSpecifier;
    other->outlet          = self->outlet;
    return NoteSequence_castToSequence(other);
}

APIF void NoteSequence_compactConcat(NoteSequence *self, Sequence *otherSeq, Error *err)
{
    NoteSequence *other = NoteSequence_castFromSequence(otherSeq);
    if (other == NULL) {
        Error_format(err, "NoteSequence_compactConcat was passed a sequence of type %s", Interface_toString(Interface_itype(otherSeq)));
        return;
    }
    NoteEventAr_foreach(it, &other->events) {
        NoteEvent e = *it.var;
        if (NoteSequence_isMarkerValue(e.duration)) {
            continue;
        }
        // Rememver in RecordBuffer_compact we're gauranteed that self->startTime < other->startTime
        e.stime += (other->startTime - self->startTime);
        NoteEventAr_push(&self->events, e); 
    }
}

APIF void NoteSequence_compactSortEvents(NoteSequence *self)
{
    NoteEventAr_sort(&self->events);
}

// Return the time that endgroup should be inserted, or -1 if no endgroup applies.
// Note we return absolute time.
APIF Ticks NoteSequence_computeEndgroupTime(NoteSequence *self)
{
    // Endgroup is the 
    Ticks endgroupTime = -1;
    NoteEventAr_rforeach(it, &self->events) {
        if (NoteSequence_isMarkerValue(it.var->duration)) {
            continue;
        }
        endgroupTime = self->startTime + it.var->stime;
        break;
    }
    return endgroupTime;
}

APIF Ticks NoteSequence_compactComputeSequenceLength(NoteSequence *self)
{
    Ticks lastTime = Sequence_minSequenceLength;
    NoteEventAr_rforeach(it, &self->events) {
        if (NoteSequence_isMarkerValue(it.var->duration)) {
            continue;
        }
        Ticks end = it.var->stime + it.var->duration;
        if (end > lastTime) {
            lastTime = end;
        }
    }

    MusicalContext_declareDefault(musicalContext);
    Ticks mlen   = musicalContext.quarterNotesPerMeasure*musicalContext.ticksPerQuarterNote;
    Ticks seqLen = (lastTime/mlen)*mlen + (lastTime % mlen == 0 ? 0 : mlen);
    if (seqLen < Sequence_minSequenceLength) {
        seqLen = Sequence_minSequenceLength;
    }

    return seqLen;
}

APIF void NoteSequence_compactFinish(NoteSequence *self, Ticks endgroupTime, Ticks sequenceLength, Error *err)
{
    if (endgroupTime >= 0) {
        int index = NoteEventAr_len(&self->events) > 0 ? 0 : -1;
        NoteEventAr_rforeach(it, &self->events) {
            if (NoteSequence_isMarkerValue(it.var->duration)) {
                continue;
            }
            if (self->startTime + it.var->stime < endgroupTime) {
                index = it.index + 1;
                break;
            }
        }
        if (index >= 0) {
            NoteEvent newEv = {.stime = endgroupTime, .duration = NoteSequence_endgDuration, .pitch = 0, .velocity = 0};
            NoteEventAr_insert(&self->events, index, newEv, err);
            Error_returnVoidOnError(err);
        }
    }


    self->sequenceLength = sequenceLength;
    NoteEvent newEv = {.stime = sequenceLength, .duration = NoteSequence_cycleDuration, .pitch = 0, .velocity = 0};
    NoteEventAr_push(&self->events, newEv);
    NoteSequence_makeConsistent(self, err);
    return;
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
            "name":"outletSpecifier",
            "type":"OutletSpecifier"
        },
        {  
            "name":"sequenceLength",
            "type":"Ticks"
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
#define FloatSequence_isMarkerValue(v) (v < -1.0e10)

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
        if (self->sequenceLength <= Sequence_minSequenceLength) {
            self->sequenceLength = Sequence_minSequenceLength;
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
        FloatSequence *other = FloatSequence_castFromSequence(FloatSequence_compactNew(self, self->startTime));        
        self->recordingSeq  = other;    
        RecordBuffer_push(recordBuffer, FloatSequence_castToSequence(other));
    }

    TimedPq_enqueue(queue, nextEvent, FloatSequence_castToSequence(self));
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
            if (self->sequenceLength <= Sequence_minSequenceLength) {
                self->sequenceLength = Sequence_minSequenceLength;
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

APIF void FloatSequence_stop(FloatSequence *self, Ticks current, Error *err) {
    self->cursor       = FloatEventAr_len(&self->events);
    self->version++;
    self->recordingSeq = NULL;
    Outlet_sendFloat(self->outlet, self->restoreValue, err);
}

APIF void FloatSequence_padNoteOff(FloatSequence *self, Ticks current, Error *err) {
    if (self->inEndgroup && !self->cycle) {
        FloatSequence_stop(self, current, err);
    }
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

APIF Sequence *FloatSequence_compactNew(FloatSequence *self, Ticks recordStart)
{
    FloatSequence *other   = FloatSequence_new();
    other->startTime       = recordStart;
    other->outletSpecifier = self->outletSpecifier;
    other->outlet          = self->outlet;
    return FloatSequence_castToSequence(other);
}

APIF void FloatSequence_compactConcat(FloatSequence *self, Sequence *otherSeq, Error *err)
{
    FloatSequence *other = FloatSequence_castFromSequence(otherSeq);
    if (other == NULL) {
        Error_format(err, "FloatSequence_compactConcat was passed a sequence of type %s", Interface_toString(Interface_itype(otherSeq)));
        return;
    }
    FloatEventAr_foreach(it, &other->events) {
        FloatEvent e = *it.var;
        if (FloatSequence_isMarkerValue(e.value)) {
            continue;
        }
        // Remember that self->startTime == recordStart
        e.stime += (other->startTime - self->startTime);
        FloatEventAr_push(&self->events, e); 
    }
    return;
}

APIF void FloatSequence_compactSortEvents(FloatSequence *self)
{
    FloatEventAr_sort(&self->events);
}

APIF Ticks FloatSequence_compactComputeSequenceLength(FloatSequence *self)
{
    Ticks lastTime = -1;
    FloatEventAr_rforeach(it, &self->events) {
        lastTime = it.var->stime;
        break;
    }

    MusicalContext_declareDefault(musicalContext);
    Ticks mlen   = musicalContext.quarterNotesPerMeasure*musicalContext.ticksPerQuarterNote;
    Ticks seqLen = (lastTime/mlen)*mlen + (lastTime % mlen == 0 ? 0 : mlen);
    if (seqLen < Sequence_minSequenceLength) {
        seqLen = Sequence_minSequenceLength;
    }
    return seqLen;
}

APIF void FloatSequence_compactFinish(FloatSequence *self, Ticks endgroupTime, Ticks sequenceLength, Error *err)
{
    if (endgroupTime >= 0) {
        int index = FloatEventAr_len(&self->events) > 0 ? 0 : -1;
        FloatEventAr_rforeach(it, &self->events) {
            if (FloatSequence_isMarkerValue(it.var->value)) {
                continue;
            }
            if (self->startTime + it.var->stime < endgroupTime) {
                index = it.index + 1;
                break;
            }
        }
        if (index >= 0) {
            FloatEvent newEv = {.stime = endgroupTime, .value = FloatSequence_endgMarker};
            FloatEventAr_insert(&self->events, index, newEv, err);
            Error_returnVoidOnError(err);
        }
    }

    self->sequenceLength = sequenceLength;
    FloatEvent newEv = {.stime = sequenceLength, .value = FloatSequence_cycleMarker};
    FloatEventAr_push(&self->events, newEv);
    FloatSequence_makeConsistent(self);
    return;
}

@interface
{
    "typeName": "Sequence",
    "fields": [
        {
            "name": "version", 
            "type": "long"
        },
        {
            "name": "startTime", 
            "type": "Ticks"
        },
        {  
            "name":"outletSpecifier",
            "type":"OutletSpecifier"
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
            "args": ["Ticks", "Error *"]
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

        // Compaction
        {
            "name": "compactNew",
            "retVal": "Sequence *",
            "args": ["Ticks"],

            // This is temporary
            "absentOk": true
        },
        {
            "name": "compactConcat",
            "retVal": "void",
            "args": ["Sequence *", "Error *"],

            // This is temporary
            "absentOk": true
        },
        {
            "name": "compactSortEvents",
            "retVal": "void",
            "args": [],

            // This is temporary
            "absentOk": true
        },  
        {
            "name": "compactComputeSequenceLength",
            "retVal": "Ticks",
            "args": [],

            // This is temporary
            "absentOk": true
        },   
        {
            "name": "compactFinish",
            "retVal": "void",
            "args": ["Ticks", "Ticks", "Error *"],

            // This is temporary
            "absentOk": true
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

// APIF void SequenceAr_truncateNoClear(SequenceAr *self) {
//     SequenceAr_foreach(it, self) {
//         *it.var = NULL;
//     }
//     SequenceAr_truncate(self);
// }

APIF void Sequence_freePpErrless(Sequence **s)
{
    Error_declare(err);
    Sequence_free(*s, err);
    Error_maypost(err);
}

// Sort into unique OutletSpecifiers, and sort by startTime within the same OutletSpecifier.
APIF int Sequence_cmp(Sequence *leftSeq, Sequence *rightSeq) 
{
    OutletSpecifier *left  = &leftSeq->outletSpecifier;
    OutletSpecifier *right = &rightSeq->outletSpecifier;
    int q = Symbol_cmp(OutletSpecifier_track(left), OutletSpecifier_track(right));
    if (q) {
        return q;
    }

    // Want to sort NoteSequence to the front of the array. We could do this by looking for *note in parameter name, but I like this better.
    bool noteLeft  = Interface_itype(leftSeq)  == NoteSequence_itype;
    bool noteRight = Interface_itype(rightSeq) == NoteSequence_itype;
    if (noteLeft && !noteRight) {
        return -1;
    } else if (!noteLeft && noteRight) {
        return 1;
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
            // Couple things to remember. 
            //    (1) recordStart is absolute time ALWAYS
            //    (2) The stime fields in the sequences are relative to that sequences startTime ALWAYS
            //    (3) All startTimes in sequences are absolute time WHILE RECORDING
            //        - This means that after record is done all members of sequences have to have their startTimes adjusted
            "name": "recordStart", 
            "type": "Ticks"
        },
        {
            // During a recording session, each sequence that is playing will record all of the events that it plays during a given 
            // Sequence_start/Sequence_stop pair. The resulting events are pushed onto this sequence array.
            "name": "sequences", 
            "type": "SequenceAr",
            "getterReturn":"pointer",
            "setter": "none"
        }
    ]
}
@end
APIF RecordBuffer *RecordBuffer_newStart(Ticks recordStart)
{
    RecordBuffer *self = RecordBuffer_new();
    self->recordStart = recordStart;
    return self;
}

APIF void RecordBuffer_push(RecordBuffer *self, Sequence *sequence)
{
    SequenceAr_push(&self->sequences, sequence);
}

APIF void RecordBuffer_compact(RecordBuffer *self, SequenceAr *output, Error *err)
{
    SequenceAr_sort(&self->sequences);
    SequenceAr_truncate(output);

    // Compact all the sequences we can
    Sequence *current = NULL;
    SequenceAr_foreach(it, &self->sequences) {
        if (current == NULL || Sequence_cmp(*it.var, current) != 0) {
            current = Sequence_compactNew(*it.var, self->recordStart, err);
            Error_gotoLabelOnError(err, END);
            SequenceAr_push(output, current);
        } 
        Sequence_compactConcat(current, *it.var, err);
        Error_gotoLabelOnError(err, END); 
    }

    Ticks sequenceLength = -1;
    SequenceAr_foreach(it, output) {
        Sequence *s = *it.var;
        Sequence_compactSortEvents(s, err);
        Error_gotoLabelOnError(err, END); 
        Ticks len = Sequence_compactComputeSequenceLength(s, err);
        Error_gotoLabelOnError(err, END);
        if (len > sequenceLength) {
            sequenceLength = len;
        }
    }

    // We assign the endgroup for a collection of sequences by looking at the first and only noteSequence for a given track. If no noteSequence
    // exists for this track, endgroup is unassigned.
    Ticks currentEndgroupTime = -1;
    Symbol *track = NULL;
    SequenceAr_foreach(it, output) {
        Sequence *s = *it.var;

        if (track != s->outletSpecifier.track) {
            track = s->outletSpecifier.track;
            NoteSequence *ns = NoteSequence_castFromSequence(s);
            if (ns == NULL) {
                currentEndgroupTime = -1;
            } else {
                currentEndgroupTime = NoteSequence_computeEndgroupTime(ns);
            }
        }
        Sequence_compactFinish(s, currentEndgroupTime, sequenceLength, err);
        Error_gotoLabelOnError(err, END);
    }

  END:
    if (Error_iserror(err)) {
        SequenceAr_truncate(output);
    }
    return;
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

COVER MidiEvent Midi_getNextEvent(FILE *pipe, Error *err)
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
    Ticks endgroupTime = -1;
    if (noteSeq != NULL) {
        endgroupTime = NoteSequence_computeEndgroupTime(noteSeq);  
    }

    //
    // Compute length
    //
    Ticks sequenceLength = -1;
    if (noteSeq != NULL) {
        sequenceLength = NoteSequence_compactComputeSequenceLength(noteSeq);
    }
    if (bendSeq != NULL) {
        Ticks len = FloatSequence_compactComputeSequenceLength(bendSeq);
        if (sequenceLength < len) {
            sequenceLength = len;
        }
    }
    for (int i = 0; i < 128; i++) {
        if (ccSeqs[i] != NULL) {
            Ticks len = FloatSequence_compactComputeSequenceLength(ccSeqs[i]);
            if (sequenceLength < len) {
                sequenceLength = len;
            }       
        }
    }

    //
    // Finish sequences off
    //
    if (noteSeq != NULL) {
        NoteSequence_compactFinish(noteSeq, endgroupTime, sequenceLength, err);
        Error_gotoLabelOnError(err, END);
    }
    if (bendSeq != NULL) {
        FloatSequence_compactFinish(bendSeq, endgroupTime, sequenceLength, err);
        Error_gotoLabelOnError(err, END);
    }
    for (int i = 0; i < 128; i++) {
        if (ccSeqs[i] != NULL) {
            FloatSequence_compactFinish(ccSeqs[i], endgroupTime, sequenceLength, err);
            Error_gotoLabelOnError(err, END);
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
        SequenceAr_push(output, NoteSequence_castToSequence(noteSeq));
    }
    if (bendSeq != NULL) {
        SequenceAr_push(output, FloatSequence_castToSequence(bendSeq));
    }
    for (int i = 0; i < 128; i++) {
        if (ccSeqs[i] != NULL) {
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