

APIF Port *Port_newTrackId(Symbol *track, Symbol *id)
{
	Port *self = Mem_calloc(sizeof(Port));
	self->obj.utilityPointer = AtomArAr_new(0);
	self->track              = track;
	self->id                 = id;
	return self;
}

APIF void Port_free(Port *self)
{
	if (self->obj.utilityPointer != NULL) {
		AtomArAr_free(self->obj.utilityPointer);
	}
	Mem_free(self);
}

APIF PortFind *PortFind_newFromTable(int argc, PortFindCell *cells)
{
    PortFind *self = PortFind_new();
    for (int i = 0; i < argc; i++) {
        PortFindCellAr_push(&self->objects, cells[i]);       
    }
    return self;
}

APIF PortFind *PortFind_createStandardSpoof(void)
{
	const int ncells = 3;
	Coverage_off;
	PortFindCell cells[ncells] = {
		{.reciever = Port_newTrackId(Symbol_gen("piano"),  Symbol_gen("idPiano")),  .varname = Symbol_gen("unknown")},
		{.reciever = Port_newTrackId(Symbol_gen("guitar"), Symbol_gen("idGuitar")), .varname = Symbol_gen("unknown")},
		{.reciever = Port_newTrackId(Symbol_gen("drums"),  Symbol_gen("idDrums")),  .varname = Symbol_gen("unknown")},
	};
	Coverage_on;
	return PortFind_newFromTable(ncells, cells);
}

APIF void PortFind_userClear(PortFind *self)
{
	PortFindCellAr_foreach(it, &self->objects) {
		Port_free(it.var->reciever);
	}
}

NoteEventAr *NoteOutlet_dbSent = NULL;

APIF void NoteOutlet_dbRewindSent() 
{
    if (NoteOutlet_dbSent != NULL) {
        NoteEventAr_truncate(NoteOutlet_dbSent);    
    }
}

APIF void NoteOutlet_dbRecordEvent(int pitch, int velocity) 
{
   	if (NoteOutlet_dbSent == NULL) {
        NoteOutlet_dbSent = NoteEventAr_new(0);
    }
    NoteEvent e = {.pitch = pitch, .velocity = velocity, .stime = Ticks_dbCurrent, .duration = 0};
    NoteEventAr_push(NoteOutlet_dbSent, e);
}
APIF void NoteOutlet_dbGetResults(NoteEventAr *arr)
{
	if (NoteOutlet_dbSent == NULL) {
		return;
	}
	NoteEventAr_truncate(arr);

	Ticks offTime[128] = {0};
	NoteEventAr_rforeach(it, NoteOutlet_dbSent) {
		if (it.var->velocity == 0) {
			offTime[it.var->pitch] = it.var->stime;
		} else {
			NoteEvent e = *it.var;
			if (offTime[e.pitch] == 0) {
				// This is the case when we have a note-on without a closing note-off. For better or worse
				// I handle this case by ignoring all notes that don't have a note off.
				continue;
			}
			e.duration  = offTime[e.pitch] - e.stime;
			NoteEventAr_push(arr, e);
		}
	}
	// reverse arr
	int N = NoteEventAr_len(arr);
	NoteEvent *d = arr->data;
	for (int i = 0; i < N/2; i++) {
		NoteEvent h = d[i];
		d[i] = d[N-i-1];
		d[N-i-1] = h;
	}
	NoteOutlet_dbRewindSent();
}

APIF void NoteOutlet_dbReportNoteOffs(NoteEventAr *arr)
{
	if (NoteOutlet_dbSent == NULL) {
		return;
	}
	NoteEventAr_truncate(arr);

	NoteEventAr_foreach(it, NoteOutlet_dbSent) {
		if (it.var->velocity == 0) {
			NoteEvent e = *it.var;
			NoteEventAr_push(arr, e);
		}
	}
	// reverse arr
	int N = NoteEventAr_len(arr);
	NoteEvent *d = arr->data;
	for (int i = 0; i < N/2; i++) {
		NoteEvent h = d[i];
		d[i] = d[N-i-1];
		d[N-i-1] = h;
	}
	NoteOutlet_dbRewindSent();
}

Coverage_off;
#define VERB(i, m) do {\
	if (verbose) {\
		printf("%s [%d]: %s\n", __func__, i, m);\
	}\
	return false;\
} while (0)
Coverage_on;

APIF bool NoteSequence_tableNotesEqual(NoteSequence *self, int argc, NoteEvent *argv, bool verbose)
{
	if (argc != NoteEventAr_len(&self->events)) {
		VERB(-1, "unequal events length");
	}

	int i = 0;
	NoteEventAr_foreach(it, &self->events) {
		if (NoteSequence_isMarkerValue(it.var->duration) || NoteSequence_isMarkerValue(argv[i].duration)) {
			if (it.var->duration != argv[i].duration) {
				VERB(i, "marker element mismatch");
				return false;			
			}
		} else {
       		if (it.var->pitch != argv[i].pitch) {
       			VERB(i, "pitch mismatch");
       		}
       		if (it.var->velocity != argv[i].velocity) {
       			VERB(i, "velocity mismatch");
       		}
       		if (it.var->stime != argv[i].stime) {
       			VERB(i, "stime mismatch");
       		}
       		if (it.var->duration != argv[i].duration) {
       			printf(">>>> %lld %lld\n", it.var->duration, argv[i].duration);
       			VERB(i, "duration mismatch");
       		}
		}
		i++;
	}
	return true;
}

#undef VERB

@type
{
	"typeName": "SequenceDriveDirective",
	"fields": [
		{"name": "time",      "type": "Ticks"},
		{"name": "directive", "type": "int"},
		{"name": "sequences", "type": "SequenceAr *"}
	],
  	"containers": [
        {
            "type": "array", 
            "typeName": "SequenceDriveDirectivePq", 
            "elemName": "SequenceDriveDirective",
            "binarySearch": [
                {"compare": "SequenceDriveDirective_cmp"}
            ]
        }
   ]
}
@end

APIF int SequenceDriveDirective_cmp(SequenceDriveDirective *left, SequenceDriveDirective *right)
{
	if (left->time < right->time) {
		return -1;
	} else if (left->time > right->time) {
		return 1;
	}
	return 0;
}

@type
{
	"typeName": "SequenceDrive",
	"fields": [
		{"name": "directives",        "type": "SequenceDriveDirectivePq"},
		{"name": "queue",             "type": "TimedPq *"},
		{"name": "timeStop",          "type": "Ticks"},
		{"name": "timeDelta",         "type": "Ticks"},
		{"name": "maxIterations",     "type": "int"},
		{"name": "recordBuffer",      "type": "RecordBuffer *", "lifecycle": "unmanaged"}
	]
}
@end

#define SequenceDrive_play        9
#define SequenceDrive_stop       10
#define SequenceDrive_padNoteOff 11

APIF SequenceDrive *SequenceDrive_newBuild(int argc, SequenceDriveDirective *argv, RecordBuffer *recordBuffer)
{
	SequenceDrive *self = SequenceDrive_new();
	self->maxIterations = 1000;
	self->timeStop      = Ticks_maxTime;
	self->timeDelta     = 480/8; // 32nd note resolution
	for (int i = 0; i < argc; i++) {
		SequenceDriveDirectivePq_push(&self->directives, argv[i]);
	}
	SequenceDriveDirectivePq_pqSort(&self->directives);	
	if (recordBuffer != NULL) {
		self->recordBuffer = recordBuffer;
	}
	return self;
}

APIF void SequenceDrive_toCompletion(SequenceDrive *self, Error *err)
{
	Ticks now     = 0;
	int iteration = 0;
	for (;;) {

		// Grab directives
		SequenceDriveDirective *peeked = SequenceDriveDirectivePq_pqPeek(&self->directives);
	    while (peeked != NULL) {
	        if (SequenceDriveDirective_time(peeked) > now) {
	            break;
	        } 

	        SequenceDriveDirective timed = {0};
	        SequenceDriveDirectivePq_pqPop(&self->directives, &timed);

	        int directive     = SequenceDriveDirective_directive(&timed);
	        SequenceAr *seqAr = SequenceDriveDirective_sequences(&timed);
	        if (directive == SequenceDrive_play) {
	        	SequenceAr_foreach(it, seqAr) {
	        		// NOTE: this start call implies that the master clock starts at time 0
	        		Sequence_start(*it.var, 0, timed.time, self->queue, self->recordBuffer, err);
	        		Error_returnVoidOnError(err);
	        	}
	        } else if (directive == SequenceDrive_stop) {
	        	SequenceAr_foreach(it, seqAr) {
	        		Sequence_stop(*it.var, timed.time, err);
	        		Error_returnVoidOnError(err);
	        	}
	        } else if (directive == SequenceDrive_padNoteOff) {
	        	SequenceAr_foreach(it, seqAr) {
	        		Sequence_padNoteOff(*it.var, now, err);
	        		Error_returnVoidOnError(err);
	        	}
	        } else {
	        	Error_format(err, "Unknown directive %d\n", directive);
	        }
  
	        peeked = SequenceDriveDirectivePq_pqPeek(&self->directives);
	    }

	    // Drive 
	    for (;;) {
	    	Sequence *seq = TimedPq_dequeue(self->queue, now);
	    	if (seq == NULL) {
	    		break;
	    	}
	    	Sequence_drive(seq, now, self->queue, err);
	    	Error_returnVoidOnError(err);
		}

	    // Time book keeping
	    if (iteration > self->maxIterations) {
	    	Error_format(err, "Exceeded maxIterations (%d)", iteration);
	    	return;
	    }
	    now += self->timeDelta;
	    if (now > self->timeStop) {
	    	return;
	    }

	    if (TimedPq_len(self->queue) == 0 && SequenceDriveDirectivePq_len(&self->directives) == 0) {
	    	return;
	    }
	}
}

