
@type 
{
    "typeName": "NoteOutletFormater",
    "fields": [
        {
            "name": "atoms",
            "type": "Atom *"       
        }
    ]
}
@end

// This is the decimal representation of binary 10010000
#define NOTEON_COMMAND 144
APIF void NoteOutletFormater_sendNote(NoteOutletFormater *self, PortRef *ref, uint8_t pitch, uint8_t velocity) 
{
    Atom *av = self->atoms;
    atom_setsym(av + 0, gensym("midievent"));
    atom_setlong(av + 1, NOTEON_COMMAND);
    atom_setlong(av + 2, pitch);
    atom_setlong(av + 3, velocity);
    Error_declare(err);
    PortRef_send(ref, 0, 4, av, err);
    Error_maypost(err);
}

@type 
{
    "typeName": "BendOutletFormater",
    "fields": [
        {
            "name": "atoms",
            "type": "Atom *"       
        }
    ]
}
@end
// This is the decimal representation of binary 11100000
#define BEND_COMMAND 224
APIF void BendOutletFormater_sendFloat(BendOutletFormater *self, double value)
{
    int v = (int)value;
    int lsb = v & 0x7F;
    int msb = (v >> 7) & 0x7F;
    Atom *av = self->atoms;
    atom_setsym(av + 0, gensym("midievent"));
    atom_setlong(av + 1, BEND_COMMAND);
    atom_setlong(av + 2, msb);
    atom_setlong(av + 3, lsb);
    Error_declare(err);
    PortRef_send(ref, 0, 4, av, err);
    Error_maypost(err);   
}

@type 
{
    "typeName": "CCOutletFormater",
    "fields": [
        {
            "name": "cc",
            "type": "int"
        }
    ]
}
@end

// This is a decimal version of the binary number 10110000
#define CC_COMMAND 176
APIF void CCOutletFormater_sendFloat(CCOutletFormater *self, double value) 
{
    int v = (int)value;
    Atom *av = self->atoms;
    atom_setsym(av + 0, gensym("midievent"));
    atom_setlong(av + 1, CC_COMMAND);
    atom_setlong(av + 2, self->cc);
    atom_setlong(av + 3, v);
    Error_declare(err);
    PortRef_send(ref, 0, 4, av, err);
    Error_maypost(err);   
}


@type 
{
    "typeName": "VstOutletFormater",
    "fields": [],
}
@end

APIF void VstOutletFormater_sendFloat(VstOutletFormater *self, double value) 
{
}

@interface 
{
    "typeName": "OutletFormater",
    "fields": [
    ],       
    "methods": [
        {
            "name": "sendNote",
            "retVal": "void",
            "args": ["PortRef *", "uint8_t", "uint8_t"]
        },
        {
            "name": "sendFloat",
            "retVal": "void",
            "args": ["PortRef *", "double"]
        },
        {
            "name": "cmp",
            "retVal": "int",
            "compareIType": true,
            "defMethod": "OutletFormater_defaultCmp"
            "args": ["OutletFormater *"]
        },
    ]
}
@end

APIF int OutletFormater_defaultCmp(OutletFormater *self, OutletFormater *other)
{
    // This means that all OutletFormater will be compared ONLY by the itype
    return 0;
}

@type 
{
    "typeName": "OutputOutlet",
    "fields": [
        {
            "name": "portRef",
            "type": "PortRef"
        },
        {
            "name": "formater",
            "type": "OutletFormater *"
        }
    ]
}
@end

APIF int OutputOutlet_cmp(OutputOutlet *self, OutputOutlet *other) {
    int q = PortRef_cmp(self->portRef, other->portRef);
    if (q) {
        return q;
    }
    return OutletFormater_cmp(self->formater, other->formater);
}

@interface 
{
    "typeName": "Outlet",
    "fields": [
    ],       
    "methods": [
        {
            "name": "sendNote",
            "retVal": "void",
            "args": ["uint8_t", "uint8_t"]
        },
        {
            "name": "sendFloat",
            "retVal": "void",
            "args": ["double"]
        },
        {
            "name": "cmp",
            // "compareIType": true means that at the top of the interface method this is inserted
            // if (left->itype < right->itype) {return -1;}
            // else if (left->itype > right->itype) {return 1;}
            "compareIType": true,
            "retVal": "int",
            "args": ["Outlet *"]
        },
        {
            "name": "cmpDestination",
            "compareIType": true,
            "retVal": "int",
            "args": ["Outlet *"]
        },
    ]
}
@end


@type
{
  "typeName": "Timed",
  "fields": [
       {"name": "time", "type": "Ticks"},
       {"name": "version", "type": "int"},
       {"name": "sequence", "type": "Sequence *"}
   ],       
  "containers": [
       {"type": "array", "typeName": "TimedAr", "elemName": "Timed"}
   ]
}
@end

@type 
{
  "typeName": "NoteEvent",
  "fields": [
       {"name": "pitch", "type": "uint8_t"},
       {"name": "velocity", "type": "uint8_t"},
       {"name": "stime", "type": "Ticks"},
       {"name": "duration", "type": "Ticks"}
   ], 
  "containers": [
       {"type": "array", "typeName": "NoteEventAr", "elemName": "NoteEvent"}
   ]
}
@end

@type
{
  "typeName": "FloatEvent",
  "fields": [
       {"name": "stime", "type": "Ticks"},
       {"name": "value", "type": "double"}
   ],
  "containers": [
       {"type": "array", "typeName": "FloatEventAr", "elemName": "FloatEvent"}
   ]
}
@end

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
            "name":"cursor",
            "type":"int"
        },
        {  
            "name":"cycle",
            "type":"bool"
        },
        {  
            "name":"outlet",
            "type":"Outlet *"
        },
        {  
            "name":"recordBuffer",
            "type":"NoteSequence *"
        },
        {  
            "name":"offs",
            "type":"TimedOffAr"
        },
        {  
            "name":"events",
            "type":"NoteEventAr"
        }
    ]
}
@end

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
            "name":"cursor",
            "type":"int"
        },
        {  
            "name":"cycle",
            "type":"bool"
        },
        {  
            "name":"outlet",
            "type":"Outlet *"
        },
        {  
            "name":"recordBuffer",
            "type":"FloatSequence *"
        },
        {  
            "name":"events",
            "type":"FloatEventAr"
        },
        {
            "name": "restoreValue",
            "type": "double"
        }
    ]
}
@end

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
        {
            "name": "start",
            "retVal": "void",
            "args": ["Ticks", "Ticks", "TimedAr *"]
        },
        {
            "name": "drive",
            "retVal": "void",
            "args": ["Ticks", "TimedAr *"]
        },
        {
            "name": "stop",
            "retVal": "void",
            "args": ["Ticks", "TimedAr *"]
        },
        {
            "name": "padNoteOff",
            "retVal": "void",
            "args": []
        }
        {
            "name": "cmp",
            "compareIType": true,
            "retVal": "int",
            "args": ["Sequence *"]
        },
        {
            "name": "cmpDestination",
            "compareIType": true,
            "retVal": "int",
            "args": ["Sequence *"]
        },
    ],
    "containers": [
        {
            "type": "array", 
            "typeName": "SequenceAr", 
            "elemName": "Sequence *"
            "binarySearch": [
                {"compare": "Sequence_cmpPp"}, 
                {"compare": "Sequence_cmpDestinationPp", "tag": "Destination"}
            ]
        }
    ]
}
@end

APIF int Sequence_cmpPp(Sequence **left, Sequence **right) {
    return Sequence_cmp(*left, *right);
}

APIF int Sequence_cmpDestinationPp(Sequence **left, Sequence **right) {
    return Sequence_cmpDestination(*left, *right);
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


void TimedAr_enqueue(TimedAr *self, Ticks time, Sequence *s) {
	Sequence_incVersion(s);
	Timed_declare(cell, time, Sequence_version(s), s);
	TimedAr_pqPush(self, cell);
}

Sequence *TimedAr_dequeue(TimedAr *self, Ticks current) {
	Timed *peeked = TimedAr_pqPeek(self);

	while (peeked != NULL) {
		if (Timed_time(peeked) > current) {
			break;
		} 

		Timed_declare0(timed);
		TimedAr_pqPop(self, &timed);
        Sequence *seq = Timed_sequence(&timed);
		if (seq != NULL && Timed_version(&timed) == Sequence_version(seq)) {
			return Timed_sequence(&timed);
		}		
		peeked = TimedAr_pqPeek(self);
	}

	return NULL;
}

void TimedAr_invalidateSeqAr(TimedAr *self, SequencePtAr *removes) 
{
    SequencePtAr_sortPtr(removes);
    TimedAr_foreach(it, self) {
        Sequence *seq = Timed_sequence(it.var);
        if (seq == NULL) {
            continue;
        }
        if (SequencePtAr_binSearchPtr(removes, seq) != NULL) {
            Timed_setSequence(it.var, NULL);
        }
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

APIF void NoteSequence_start(NoteSequence *self, Ticks clockStart, Ticks current, TimedAr *queue, RecordBuffer *recordBuffer) {
	int nevents = NoteEventAr_len(&self->events);
	if (nevents <= 0) {
		return;
	}

	self->startTime    = self->cycle ? clockStart : current;
	self->cursor       = 0;
    self->inEndgroup   = false;
	// self->seqBase      = self->sequenceLength * ((current - self->startTime) / self->sequenceLength) + self->startTime;
	Ticks nextEvent    = 0;
	if (self->cycle) {
        while (current-self->startTime > self->sequenceLength) {
            // XXX: potential infinite loop here
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

	// These note-offs are from a previous sequence start
	TimedOffAr_foreach(it, &self->offs) {
		if (it.var->time < nextEvent) {
			nextEvent = it.var->time;
		}
		break;
	}

	self->recordingSeq = NULL;
	if (recordBuffer != NULL) {
		NoteSequence *other = NoteSequence_new();
		other->startTime    = self->startTime;
		self->recordingSeq  = other;	
		RecordBuffer_push(recordBuffer, NoteSequence_castToSequence(other));
	}

	TimedAr_enqueue(queue, nextEvent, NoteSequence_castToSequence(self));
}

APIF void NoteSequence_stop(NoteSequence *self, Ticks current, TimedAr *queue) {
    self->cursor       = NoteEventAr_len(&self->events);
    //XXX: do I need to fix up recordingSeq before I dro it
    self->recordingSeq = NULL;
    TimedOffAr_foreach(it, &self->offs) {
        Ticks nextEvent = it.var->time;
        TimedAr_enqueue(queue, nextEvent, NoteSequence_castToSequence(self));
        break;
    }
}

Ticks NoteSequence_cycleDuration   = -1;
Ticks NoteSequence_endgDuration    = -2;
Ticks NoteSequence_noteOffDuration = -3;

static inline void NoteSequence_playNoteOffs(NoteSequence *self, Ticks current) 
{
    self->nextOffEvent = -1;
    int nremoves = 0;
    TimedOffAr_foreach(it, &self->offs) {
        if (it.var->time > current) {
            self->nextOffEvent = it.var->time;
            break;
        }
        Outlet_sendNote(self->outlet, it.var->pitch, 0);
        nremoves++;
    }
    if (nremoves > 0) {
        TimedOffAr_removeN(&self->offs, 0, nremoves, err);
        Error_maypost(err);
    }
}

static inline void NoteSequence_reconcileNoteOffsWithNewNotes(NoteSequence *self, NoteEvent *ne) {
    TimedOffAr_foreach(it, &self->offs) {
        if (it.var->pitch == ne->pitch) {
            TimedOffArFIt_remove(&it);
            Outlet_sendNote(self->outlet, ne->pitch, 0);
            break;
        }
    }
}


static inline void NoteSequence_playNoteOns(NoteSequence *self, Ticks current) 
{
    self->nextOnEvent = -1;
    for (;;) {
        NoteEventAr_foreachOffset(it, &self->events, self->cursor) {
            NoteEvent *ne = it.var;
            if (ne->stime + self->starTime > current) {
                self->nextOnEvent = ne->stime + self->startTime;
                return;
            }
            if (ne->duration >= 0) {
                NoteSequence_reconcileNoteOffsWithNewNotes(self, ne);
                Outlet_sendNote(self->outlet, ne->pitch, ne->velocity);
            } else if (ne->duration == NoteSequence_endgDuration) {
                self->inEndgroup = true;
            } 
            if (self->recordingSeq != NULL && ne->duration != NoteSequence_endgDuration) {
                NoteEvent e = *ne;
                e.time      = self->recordingSeq->startTime + ne->stime;
                NoteEventAr_push(&self->recordingSeq->events, e);
            }
            self->cursor++;
        }
        if (self->cycle) {
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

APIF void NoteSequence_drive(NoteSequence *self, Ticks current, TimedAr *queue) {
    NoteSequence_playNoteOffs(self, current);
    NoteSequence_playNoteOns(self, current);
    Ticks nextEvent = NoteSequence_nextEvent(self);
    if (nextEvent >= 0) {
        TimedAr_enqueue(queue, nextEvent, NoteSequence_castToSequence(self));
    }
}

static inline void NoteManager_adjustRecSeqForEndgroup(NoteSequence *self, int pitch, Ticks current) {
    // 
    NoteEventAr_rforeach(it, &self->recordingSeq->events) {
        if (it.var->pitch == pitch) {
            it.var->duration = current - it.var->time;
            return;
        }
    }
}

APIF void NoteSequence_padNoteOff(NoteSequence *self, int padIndex, Ticks current) {
    if (self->inEndgroup) {
        TimedOffAr_foreach(it, &self->offs) {
            NoteManager_adjustRecSeqForEndgroup(self, it.var->pitch, current);
            Outlet_sendNote(self->outlet, it.var->pitch, 0);
        }
        TimedOffAr_truncate(&self->offs);
    }
}

double FloatSequence_endgMarker  = -1e40.0;
double FloatSequence_cycleMarker = -1e41.0;
APIF void FloatSequence_start(BendSequence *self, Ticks clockStart, Ticks current, TimedAr *queue, RecordBuffer *recordBuffer) {
    int nevents = FloatEventAr_len(&self->events);
    if (nevents <= 0) {
        return;
    }

    self->startTime    = self->cycle ? clockStart : current;
    self->cursor       = 0;
    self->inEndgroup   = false;
    Ticks nextEvent    = 0;
    if (self->cycle) {
        while (current-self->startTime > self->sequenceLength) {
            // XXX: potential infinite loop here
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
        BendSequence *other = FloatSequence_new();
        other->startTime    = self->startTime;
        self->recordingSeq  = other;    
        RecordBuffer_push(recordBuffer, FloatSequence_castToSequence(other));
    }

    TimedAr_enqueue(queue, nextEvent, FloatSequence_castToSequence(self));
}

APIF void FloatSequence_stop(FloatSequence *self, Ticks current, TimedAr *queue) {
    self->cursor       = FloatEventAr_len(&self->events);
    //XXX: do I need to fix up recordingSeq before I dro it
    self->recordingSeq = NULL;
    Outlet_sendFloat(self->outlet, self->restoreValue);
}

APIF void FloatSequence_drive(FloatSequence *self, Ticks current, TimedAr *queue) {
    Ticks nextOnEvent = -1;
    for (;;) {
        FloatEventAr_foreachOffset(it, &self->events, self->cursor) {
            FloatEvent *fe = it.var;
            if (fe->stime + self->starTime > current) {
                nextOnEvent = ne->stime + self->startTime;
                goto DONE;
            }
            if (fe->value == FloatSequence_endgMarker) {
                self->inEndgroup = true;
            } else if (fe->value == FloatSequence_cycleMarker) {
                // Do nothing
            } else {
                Outlet_sendFloat(fe->outlet, fe->value);
            }

            if (self->recordingSeq != NULL && fe->value != FloatSequence_endgMarker) {
                FloatEvent e = *fe;
                e.time       = self->recordingSeq->startTime + fe->stime;
                FloatEventAr_push(&self->recordingSeq->events, e);
            }
            self->cursor++;
        }
        if (self->cycle) {
            self->startTime += self->sequenceLength;
            self->cursor     = 0;
        } else {
            goto DONE;
        }
    }
   DONE:
    if (nextEvent >= 0) {
        TimedAr_enqueue(queue, nextEvent, FloatSequence_castToSequence(self));
    }
}
APIF void FloatSequence_padNoteOff(FloatSequence *self, int padIndex, Ticks current) {
    if (self->inEndgroup) {
        Outlet_sendFloat(self->outlet, self->restoreValue);
    }
}

//
//
//
APIF void Sequence_incVersion(Sequence *seq) {
	seq->version++;
}

APIF void Frontend_recievedPadHit(Hub *hub, long pitchIn, long velocityIn){
	Error_declare(err);
  int padIndex = Hub_padIndexFromInNote(x, pitchIn);
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
	TimedAr *queue = Hub_queue(hub);
	Sequence *seq = TimedAr_dequeue(queue);
	while (seq != NULL) {
		Sequence_drive(seq, now, queue);
		seq = TimedAr_dequeue(queue);
	}
}

APIF void Frontend_stop(Hub *hub) {
	SequenceAr_foreach(it, Hub_runningSequences(hub)) {
		Sequence_stop(it.var);
	}
}