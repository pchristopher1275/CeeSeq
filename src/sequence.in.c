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
         }
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
         {"name": "time", "type": "Ticks"},
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
            "name":"sequenceLength",
            "type":"Ticks"
         },
         {  
            "name":"startTime",
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
      ],
      "containers": [
         {"type": "array", "typeName": "SequenceAr", "elemName": "Sequence *"}
      ]
   }
@end

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
		TimedAr_pqPop(self, timed);
		if (Timed_version(timed) == Sequence_version(Timed_sequence(timed))) {
			return Timed_sequence(timed);
		}		
		peeked = TimedAr_pqPeek(self);
	}

	return NULL;
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

	self->startTime    = clockStart;
	self->cursor       = 0;
	Ticks seqBase      = self->sequenceLength * ((current - clockStart) / self->sequenceLength) + clockStart;
	Ticks nextEvent    = 0;
	if (self->cycle) {
		Ticks seqTime = (current-clockStart) % self->sequenceLength;
		NoteEventAr_foreach(it, &self->events) {
			if (it.var->stime > seqTime) {
				nextEvent = it.var->stime + seqBase;
				break;
			}
			self->cursor++;
		}
		if (self->cursor >= nevents) {
			nextEvent = sequenceLength + seqBase;
			self->cursor = 0;
		}
	} else {
		NoteEventAr_foreach(it, &self->events) {
			nextEvent = it.var->stime;
			break;
		}
	}

	// These note-offs are from a previous sequence start
	TimedOffAr_foreach(it, &self->offs) {
		Ticks time = it.var->time + seqBase;
		if (time < nextEvent) {
			nextEvent = time;
		}
		break;
	}

	self->recordingSeq = NULL;
	if (recordBuffer != NULL) {
		NoteSequence *other = NoteSequence_new();
		other->startTime    = self->startTime;
		self->recordingSeq  = other;	
		RecordBuffer_push(recordBuffer, other);
	}

	TimedAr_enqueue(queue, nextEvent, NoteSequence_castToSequence(self));
}

APIF void NoteSequence_stop(NoteSequence *self, Ticks current, TimedAr *queue) {
	self->cursor       = NoteEventAr_len(&self->events);
    self->recordingSeq = NULL;
	Ticks seqBase      = self->sequenceLength * ((current - self->startTime) / self->sequenceLength) + self->startTime;
    TimedOffAr_foreach(it, &self->offs) {
		Ticks nextEvent = it.var->time + seqBase;
		TimedAr_enqueue(queue, nextEvent, NoteSequence_castToSequence(self));
		break;
	}
}

APIF void NoteSequence_drive(NoteSequence *self, Ticks current, TimedAr *queue) {
	// Ticks seqTime      = (current-self->startTime) % self->sequenceLength;
	Ticks seqBase      = self->sequenceLength * ((current - self->startTime) / self->sequenceLength) + self->startTime;

	int nremoves = 0;
	TimedOffAr_foreach(it, &self->offs) {
        if (it.var->time > current) {
        	nextOffEvent = it.var->time;
            break;
        }
        Outlet_sendNote(self->outlet, it.var->pitch, 0);
        nremoves++;
    }
    if (nremoves > 0) {
        TimedOffAr_removeN(&self->offs, 0, nremoves, err);
        Error_maypost(err);
    }

    int nevents = NoteEventAr_len(&self->events);
    if (self->cursor >= nevents && self->cycle) {
    	self->cursor = 0;
    }

	Ticks nextOnEvent = self->sequenceLength + seqBase;
	bool loop = true;
	for (;;) {
		NoteEventAr_foreachOffset(it, &self->events, self->cursor) {
			NoteEvent *ne = it.var;
			if (ne->stime + seqBase > current) {
				nextOnEvent = ne->stime + seqBase;
				break;
			}
			self->cursor++;
			if (self->recordingSeq != NULL) {
				NoteEvent e = *ne;
				e.stime     = e.stime + seqBase;
				NoteEventAr_push(&self->recordingSeq->events, e);
			}
			if (ne->duration == NoteSequence_durationCycle) {
				continue;
			}
			TimedOffAr_foreach(it2, &self->offs) {
				if (it2.var->pitch == ne->pitch) {
					Error_declare(err);
					TimedOffAr_remove(&self->offs, it2.index, err);
					Error_maypost(err);
					break;
				}
			}
			Outlet_sendNote(self->outlet, ne->pitch, ne->velocity);
			TimedOff_declare(off, ne->stime + seqBase + ne->duration, ne->pitch);
	        TimedOffAr_binInsertTime(&self->offs, off);
		}
		if (self->cursor >= nevents && self->cycle) {
			self->cursor     = 0;
			self->startTime += self->sequenceLength;
			Ticks seqBase    = self->sequenceLength * ((current - self->startTime) / self->sequenceLength) + self->startTime;
			if (loop) {
				loop = false;
				continue;
			}
		}
		break;
	}

	Ticks nextOffEvent = 0;
	TimedOffAr_foreach(it, &self->offs) {
		nextOffEvent = it.var->time;
		break;
    }

	if (self->cursor >= nevents && self->cycle) {	
		self->cursor = 0;			
	}
	if (self->cursor < nevents || TimedOffAr_len(&self->offs) > 0) {
		Ticks nextEvent = nextOffEvent > 0 && nextOffEvent < nextOnEvent ? nextOffEvent : nextOnEvent;
		TimedAr_enqueue(queue, nextEvent, NoteSequence_castToSequence(self));
	}
}

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