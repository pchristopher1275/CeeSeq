#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdarg.h>
#include <ctype.h>
#include <errno.h>
#include <unistd.h> 
#include <stdint.h>
#include <limits.h>
#include "../src/core.c"
#include "../src/unit.c"
#include "application.c"

void testNoteSequenceStartFixture(Ticks clockStart, Ticks current, Ticks expStartTime, int expCursor, bool useCycle, Ticks noteDuration)
{
	// Start a one-shot
	PortFind *portFind = PortFind_createStandardSpoof();
	const int nnotes = 5;
	NoteEvent notes[nnotes] = {
		{.pitch = 60, .velocity = 100, .stime = 200,              .duration = noteDuration},
		{.pitch = 61, .velocity = 101, .stime = 241,              .duration = noteDuration},
		{.pitch = 0,  .velocity = 0,   .stime = 242,              .duration = NoteSequence_endgDuration},
		{.pitch = 62, .velocity = 102, .stime = 242,              .duration = noteDuration},
		{.pitch = 0,  .velocity = 0,   .stime = 242+noteDuration, .duration = NoteSequence_cycleDuration},
	};
	NoteSequence *noteSequence = NoteSequence_newFromEvents(Symbol_gen("piano"), portFind, nnotes, notes);
	NoteSequence_setCycle(noteSequence, useCycle);
	TimedPq *timedPq = TimedPq_new(0);
	
	Error_declare(err);
	NoteSequence_start(noteSequence, clockStart, current, timedPq, NULL, err);
	fatal(!Error_iserror(err));
	chk(noteSequence->startTime == expStartTime);
	chk(noteSequence->cursor    == expCursor);


	// Make sure this sequence was queued
	chk(TimedPq_len(timedPq) == 1);

	// Make sure that no sequence is returned until the first sequence event at 300
	Sequence *seq = TimedPq_dequeue(timedPq, expStartTime + 150);
	chk(seq == NULL);

	// Now fetch the sequence event
	seq = TimedPq_dequeue(timedPq, expStartTime+300);
	fatal(seq != NULL);
	fatal((void*)seq == (void*)noteSequence);

	TimedPq_free(timedPq);
	NoteSequence_free(noteSequence);
	PortFind_free(portFind);
}
void testNoteSequenceDriveFixture(Ticks clockStart, Ticks current, int noteCursor, int realNoteCount, bool useCycle, Ticks noteDuration, Ticks timeStop)
{
	PortFind *portFind = PortFind_createStandardSpoof();
	const int nnotes = 5;
	NoteEvent notes[nnotes] = {
		{.pitch = 60, .velocity = 100, .stime = 200,     .duration = noteDuration},
		{.pitch = 61, .velocity = 101, .stime = 300,     .duration = noteDuration},
		{.pitch = 0,  .velocity = 0,   .stime = 400,     .duration = NoteSequence_endgDuration},
		{.pitch = 62, .velocity = 102, .stime = 400,     .duration = noteDuration},
		{.pitch = 0,  .velocity = 0,   .stime = 400,     .duration = NoteSequence_cycleDuration},
	};
	TimedPq *timedPq = TimedPq_new(0);
	NoteSequence *noteSequence = NoteSequence_newFromEvents(Symbol_gen("piano"), portFind, nnotes, notes);
	NoteSequence_setCycle(noteSequence, useCycle);
	Outlet *ol = noteSequence->outlet;
	NoteOutlet *nol = NoteOutlet_castFromOutlet(ol);
	fatal(nol != NULL); 
	
	Error_declare(err);
	NoteSequence_start(noteSequence, clockStart, current, timedPq, NULL, err);
	fatal(!Error_iserror(err));

	const int maxIterations = 1000;
	Ticks maxTime = maxIterations*25;
	if (timeStop > maxTime) {
		timeStop = maxTime;
	}
	
	for (int i = 0; i < maxIterations; i++){
		if (i*25 > timeStop) {
			break;
		}
		Ticks_dbSetNow(i*25);

		Sequence *seq = TimedPq_dequeue(timedPq, Ticks_dbNow());
		if (seq == NULL) {
			if (TimedPq_len(timedPq) <= 0) {
				break;
			}
			continue;
		}
		fatal((void*)seq == (void*)noteSequence);
		NoteSequence_drive(noteSequence, Ticks_dbNow(), timedPq, err);
		fatal(!Error_iserror(err));
	}

	NoteEventAr *res = NoteEventAr_new(0);
	NoteOutlet_dbGetResults(res);
	fatal(NoteEventAr_len(res) == realNoteCount);
	int nptr = noteCursor;
	Ticks tdelta = 0;
	NoteEventAr_foreach(it, res) {
		if (NoteSequence_isMarkerValue(notes[nptr].duration)) {
			if (notes[nptr].duration == NoteSequence_cycleDuration) {
				tdelta += 400;
			}
			nptr = (nptr + 1) % nnotes;
		}
		chk(it.var->pitch == notes[nptr].pitch);
		chk(it.var->velocity == notes[nptr].velocity);
		chk(it.var->stime == notes[nptr].stime + tdelta);
		chk(it.var->duration == notes[nptr].duration);
		nptr = (nptr + 1) % nnotes;
	}

	NoteEventAr_free(res);
	TimedPq_free(timedPq);
	NoteSequence_free(noteSequence);
	PortFind_free(portFind);	
}

Unit_declare(testNoteSequence) {
	// Unit_setUseCase(true);

	Unit_case(0) {
		// Outlet initialization
		PortFind *portFind = PortFind_createStandardSpoof();
		NoteSequence *noteSequence = NoteSequence_newTrack(Symbol_gen("piano"), portFind);
		Outlet *ol = noteSequence->outlet;
		NoteOutlet *nol = NoteOutlet_castFromOutlet(ol);
		fatal(nol != NULL);
		chk(nol->port->track == Symbol_gen("piano"));
		NoteSequence_free(noteSequence);
		PortFind_free(portFind);
	}

	Unit_case(0) {
		// Start a one-shot
		Unit_call(testNoteSequenceStartFixture(100, 100, 100, 0, false, 480));
	}

	Unit_case(0) {
		// Start a master-clock
		Unit_call(testNoteSequenceStartFixture(0, 241, 0, 2, true, 480));	
	}

	Unit_case(0) {
		// Start a master-clock where start time is after sequence end
		Unit_call(testNoteSequenceStartFixture(0, 242+480+1, 242+480, 0, true, 480));	
	}

	Unit_case(0) {
		// Start a one-shot short duration
		Unit_call(testNoteSequenceStartFixture(100, 100, 100, 0, false, 480/16));
	}

	Unit_case(0) {
		// Start a master-clock short duration
		Unit_call(testNoteSequenceStartFixture(0, 241, 0, 2, true, 480/16));	
	}

	Unit_case(0) {
		// Start a master-clock where start time is after sequence end short duration
		Unit_call(testNoteSequenceStartFixture(0, 242+480/16+1, 242+480/16, 0, true, 480/16));	
	}

	Unit_case(0) { 
		// drive on-shot
		Unit_call(testNoteSequenceDriveFixture(0, 0, 0, 3, false, 250, Ticks_maxTime));	
	}

	Unit_case(0) { 
		// drive on-shot short duration
		Unit_call(testNoteSequenceDriveFixture(0, 0, 0, 3, false, 50, Ticks_maxTime));	
	}

	Unit_case(0) { 
		// drive master clock
		Unit_call(testNoteSequenceDriveFixture(0, 350, 3, 4, true, 250, 1200));	
	}	
}

int main(int argc, char *argv[]) {
	Unit_initialize(argc, argv);
	Unit_test(testNoteSequence);
	Unit_finalize();
}