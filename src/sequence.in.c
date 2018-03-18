
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

void NoteSequence_start(NoteSequence *self, Ticks clockStart, Ticks current, TimedAr *queue, RecordBuffer *recordBuffer) {
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
	TimedOffAr_foreach(it, &self->offs) {
		Ticks stime = it.var->time + seqBase;
		if (stime < nextEvent) {
			nextEvent = stime;
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

void NoteSequence_stop(NoteSequence *self) {
	self->cursor = NoteEventAr_len(&self->events);
    self->recordingSeq = NULL;
}

void NoteSequence_drive(NoteSequence *self, Ticks current, TimedAr *queue) {
	Ticks seqTime      = (current-self->startTime) % self->sequenceLength;
	Ticks seqBase      = self->sequenceLength * ((current - self->startTime) / self->sequenceLength) + self->startTime;
	Ticks nextOffEvent = 0;
	Ticks nextOnEvent  = self->sequenceLength + seqBase;

	int nremoves = 0;
	TimedOffAr_foreach(it, &self->offs) {
        if (it.var->time > seqTime) {
        	nextOffEvent = it.var->time + seqBase;
            break;
        }
        Outlet_sendNote(self->outlet, it.var->pitch, 0);
        nremoves++;
    }
    if (nremoves > 0) {
        TimedOffAr_removeN(&self->offs, 0, nremoves, err);
        Error_maypost(err);
    }

	NoteEventAr_foreachOffset(it, &self->events, self->cursor) {
		NoteEvent *ne = it.var;
		if (ne->time > seqTime) {
			nextOnEvent = ne->stime + seqBase;
			break;
		}
		self->cursor++;
		if (self->recordingSeq != NULL) {
			NoteEvent e = *ne;
			e.stime     = e.stime + seqBase;
			NoteEventAr_push(&self->recordingSeq->events, e);
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
		TimedOff_declare(off, ne->stime + ne->duration, ne->pitch);
        TimedOffAr_binInsertTime(&self->offs, off);
	}

	int nevents = NoteEventAr_len(&self->events);
	if (self->cursor >= nevents && self->cycle) {	
		self->cursor = 0;			
	}
	if (self->cursor < nevents || TimedOffAr_len(&self->offs) > 0) {
		Ticks nextEvent = nextOffEvent > 0 && nextOffEvent < nextOnEvent ? nextOffEvent : nextOnEvent;
		TimedAr_enqueue(queue, nextEvent, NoteSequence_castToSequence(self));
	}
}

// void NoteSequence_startRecord(NoteSequence *self, Ticks recordStartTime) {
// 	NoteSequence *other = self->recordBuffer;
// 	if (other != NULL) {
// 		NoteSequence_free(r);
// 	}
// 	other              = NoteSequence_new();
// 	other->startTime   = self->startTime;
// 	self->recordBuffer = other;

// 	return;
// }

// Sequence *NoteSequence_stopRecord(NoteSequence *self) {
// 	NoteSequence *other = self->recordBuffer;
// 	if (other == NULL) {
// 		return NULL;
// 	}
// 	self->recordBuffer = NULL;

// 	NoteEventAr_foreach(it, &r->events) {
// 		it.var->stime -= other->startTime;
// 	}

// 	Ticks length = 480;
// 	NoteEventAr_rforeach(it, &r->events) {
// 		length = other->startTime + it.var->stime + it.var->duration;
// 		break;
// 	}
// 	other->sequenceLength = length;
// 	return other;
// }

void Sequence_incVersion(Sequence *seq) {
	seq->version++;
}

//void NoteSequence_start(NoteSequence *self, Ticks clockStart, Ticks current, TimedAr *queue) {
void Faux_queueSequences(Hub *hub, Ticks masterClockStart, Ticks current, SequenceAr *toAdd, bool recordActive) {
	SequenceAr *recordedSequences = XXX;

	TimedAr *queue = Hub_queue(hub);
	SequenceAr_foreach(it, toAdd) {
		Sequence_start(it.var, masterClockStart, current, queue);
		if (recordActive) {
			Sequence_startRecord(it.var);
			SequenceAr_binInsertPtCmp(recordedSequences, it.var);
		}
	}

	Faux_loop(hub, current);
}

void Faux_stopRecording(Hub *hub, Ticks recordStartTime) {
	SequenceAr *recordedSequences = XXX;

	RecordBuffer *buffer = RecordBuffer_new();
	SequenceAr_foreach(it, recordedSequences) {
		Sequence *seq = Sequence_stopRecord(it.var);
		if (seq != NULL) {
			RecordBuffer_push(buffer, seq);
		}
	}
	// First we sort by startTime which is the time when the pad was hit
	RecordBuffer_sortByStartTime(buffer);

}


void Faux_loop(Hub *hub, Ticks current) {
	TimedAr *queue = Hub_queue(hub);
	Sequence *seq  = TimedAr_dequeue(queue, current);
	while (seq != NULL) {
		Sequence_drive(seq, current, queue);
		seq = TimedAr_dequeue(queue, current);
	}
}


