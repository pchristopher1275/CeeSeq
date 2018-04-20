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
	Error_declare(err);
	PortFind *portFind = PortFind_createStandardSpoof();
	const int nnotes = 5;
	NoteEvent notes[nnotes] = {
		{.pitch = 60, .velocity = 100, .stime = 200,              .duration = noteDuration},
		{.pitch = 61, .velocity = 101, .stime = 241,              .duration = noteDuration},
		{.pitch = 0,  .velocity = 0,   .stime = 242,              .duration = NoteSequence_endgDuration},
		{.pitch = 62, .velocity = 102, .stime = 242,              .duration = noteDuration},
		{.pitch = 0,  .velocity = 0,   .stime = 242+noteDuration, .duration = NoteSequence_cycleDuration},
	};
	NoteSequence *noteSequence = NoteSequence_newFromEvents(Symbol_gen("piano"), portFind, nnotes, notes, err);
	fatal(!Error_iserror(err));
	NoteSequence_setCycle(noteSequence, useCycle);
	TimedPq *timedPq = TimedPq_new(0);
	
	
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
void testNoteSequenceDriveFixture(Ticks clockStart, Ticks current, int noteCursor, int realNoteCount, bool useCycle, Ticks noteDuration, Ticks timeStop, Ticks tdeltaStart)
{
	Error_declare(err);
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
	NoteSequence *noteSequence = NoteSequence_newFromEvents(Symbol_gen("piano"), portFind, nnotes, notes, err);
	fatal(!Error_iserror(err));
	NoteSequence_setCycle(noteSequence, useCycle);
	Outlet *ol = noteSequence->outlet;
	NoteOutlet *nol = NoteOutlet_castFromOutlet(ol);
	fatal(nol != NULL); 
	
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
	Ticks tdelta = tdeltaStart;
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

Unit_declare(testNoteSequenceStartAndDrive) {
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
		Unit_call(testNoteSequenceStartFixture(0, 241, 0, 1, true, 480));	
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
		Unit_call(testNoteSequenceStartFixture(0, 241, 0, 1, true, 480/16));	
	}

	Unit_case(0) {
		// Start a master-clock where start time is after sequence end short duration
		Unit_call(testNoteSequenceStartFixture(0, 242+480/16+1, 242+480/16, 0, true, 480/16));	
	}

	Unit_case(0) { 
		// drive on-shot
		Unit_call(testNoteSequenceDriveFixture(0, 0, 0, 3, false, 250, Ticks_maxTime, 0));	
	}

	Unit_case(0) { 
		// drive on-shot short duration
		Unit_call(testNoteSequenceDriveFixture(0, 0, 0, 3, false, 50, Ticks_maxTime, 0));	
	}

	Unit_case(0) { 
		// drive master clock
		Unit_call(testNoteSequenceDriveFixture(0, 350, 3, 4, true, 250, 1200, 0));	
	}

	Unit_case(0) { 
		// drive master clock start later
		Unit_call(testNoteSequenceDriveFixture(0, 600, 0, 3, true, 250, 1200, 400));	
	}	
}

Unit_declare(testNoteSequenceStopAndEndgroup)
{
	{
		// Test NoteSequence_stop
		Error_declare(err);
		PortFind *portFind = PortFind_createStandardSpoof();
		const int nnotes = 2;
		NoteEvent notes[nnotes] = {
			{.pitch = 0,  .velocity = 0,   .stime = 400,     .duration = NoteSequence_endgDuration},
			{.pitch = 0,  .velocity = 0,   .stime = 400,     .duration = NoteSequence_cycleDuration}
		};
		NoteSequence *noteSequence = NoteSequence_newFromEvents(Symbol_gen("piano"), portFind, nnotes, notes, err);
		fatal(!Error_iserror(err));
		Outlet *ol = noteSequence->outlet;
		NoteOutlet *nol = NoteOutlet_castFromOutlet(ol);
		fatal(nol != NULL); 

		const int noffPitches = 3;
		int offPitches[noffPitches] = {60, 61, 62};
		for (int i = noffPitches-1; i >= 0; i--) {
			// I don't know why I have to add these in reverse order. But I don't much care.
			TimedOff t = {.time = Ticks_maxTime, .pitch = offPitches[i]};
			TimedOffAr_push(&noteSequence->offs, t);
		}
		fatal(TimedOffAr_len(&noteSequence->offs) == 3);
		chk(noteSequence->version == 0);
		chk(noteSequence->cursor  == 0);

		NoteSequence_stop(noteSequence, Ticks_maxTime, err);
		fatal(!Error_iserror(err));

		chk(TimedOffAr_len(&noteSequence->offs) == 0);
		chk(noteSequence->version == 1);
		chk(noteSequence->cursor  == NoteEventAr_len(&noteSequence->events));

		NoteEventAr *res = NoteEventAr_new(0);
		NoteOutlet_dbReportNoteOffs(res);
		fatal(NoteEventAr_len(res) == noffPitches);
		NoteEvent *evs = res->data;
		for (int i = 0; i < noffPitches; i++) {
			chk(evs[i].pitch == offPitches[i]);
		}
		NoteEventAr_free(res);
		PortFind_free(portFind);
		NoteSequence_free(noteSequence);
	}

	{
		// Test NoteSequence_padNoteOff
		Error_declare(err);
		PortFind *portFind = PortFind_createStandardSpoof();
		const int nnotes = 2;
		NoteEvent notes[nnotes] = {
			{.pitch = 0,  .velocity = 0,   .stime = 400,     .duration = NoteSequence_endgDuration},
			{.pitch = 0,  .velocity = 0,   .stime = 400,     .duration = NoteSequence_cycleDuration}
		};
		NoteSequence *noteSequence = NoteSequence_newFromEvents(Symbol_gen("piano"), portFind, nnotes, notes, err);
		fatal(!Error_iserror(err));
		Outlet *ol = noteSequence->outlet;
		NoteOutlet *nol = NoteOutlet_castFromOutlet(ol);
		fatal(nol != NULL); 

		const int noffPitches = 3;
		int offPitches[noffPitches] = {60, 61, 62};
		for (int i = noffPitches-1; i >= 0; i--) {
			// I don't know why I have to add these in reverse order. But I don't much care.
			TimedOff t = {.time = Ticks_maxTime, .pitch = offPitches[i]};
			TimedOffAr_push(&noteSequence->offs, t);
		}
		fatal(TimedOffAr_len(&noteSequence->offs) == 3);
		noteSequence->inEndgroup = true;
	
		
		NoteSequence_padNoteOff(noteSequence, 0, Ticks_maxTime, err);
		chk(TimedOffAr_len(&noteSequence->offs) == 0);

		NoteEventAr *res = NoteEventAr_new(0);
		NoteOutlet_dbReportNoteOffs(res);
		fatal(NoteEventAr_len(res) == noffPitches);
		NoteEvent *evs = res->data;
		for (int i = 0; i < noffPitches; i++) {
			chk(evs[i].pitch == offPitches[i]);
		}
		NoteEventAr_free(res);
		PortFind_free(portFind);
		NoteSequence_free(noteSequence);
	}

	{
		// Test setting of noteSequence->inEndgroup
		Error_declare(err);
		PortFind *portFind = PortFind_createStandardSpoof();
		const int nnotes = 2;
		NoteEvent notes[nnotes] = {
			{.pitch = 0,  .velocity = 0,   .stime = 200,     .duration = NoteSequence_endgDuration},
			{.pitch = 0,  .velocity = 0,   .stime = 400,     .duration = NoteSequence_cycleDuration}
		};
		NoteSequence *noteSequence = NoteSequence_newFromEvents(Symbol_gen("piano"), portFind, nnotes, notes, err);
		fatal(!Error_iserror(err));
		TimedPq *timedPq = TimedPq_new(0);

		noteSequence->inEndgroup = true;

		NoteSequence_start(noteSequence, 0, 0, timedPq, NULL, err);
		fatal(!Error_iserror(err));
		chk(noteSequence->inEndgroup == false);
		
		NoteSequence_drive(noteSequence, 200, timedPq, err);
		fatal(!Error_iserror(err));
		chk(noteSequence->inEndgroup == true);					

		TimedPq_free(timedPq);
		PortFind_free(portFind);
		NoteSequence_free(noteSequence);
	}

	{
		// Test NoteSequence_makeConsistent
		// Start a one-shot
		Error_declare(err);
		PortFind *portFind = PortFind_createStandardSpoof();
		const int nnotes = 4;
		NoteEvent notes[nnotes] = {
			{.pitch = 60, .velocity = 100, .stime = 200, .duration = 300},
			{.pitch = 0,  .velocity = 0,   .stime = 200, .duration = NoteSequence_endgDuration},
			{.pitch = 60, .velocity = 100, .stime = 100, .duration = 300},
			{.pitch = 0,  .velocity = 0,   .stime = 400, .duration = NoteSequence_cycleDuration},
		};
		NoteSequence *noteSequence = NoteSequence_newFromEvents(Symbol_gen("piano"), portFind, nnotes, notes, err);
		fatal(NoteEventAr_len(&noteSequence->events) == 4);
		NoteEvent *evs = noteSequence->events.data;
		chk(evs[0].stime == 100);
		chk(evs[0].pitch == 60);
		chk(evs[0].duration == 100);
		
		chk(evs[2].stime == 200);
		chk(evs[2].pitch == 60);
		chk(evs[2].duration == 300);

		chk(evs[3].stime == 400);
		chk(evs[3].duration == NoteSequence_cycleDuration);
		chk(noteSequence->sequenceLength == 400);

		NoteSequence_free(noteSequence);
		PortFind_free(portFind);
	}
}

int main(int argc, char *argv[]) {
	Unit_initialize(argc, argv);
	Unit_test(testNoteSequenceStartAndDrive);
	Unit_test(testNoteSequenceStopAndEndgroup);
	Unit_finalize();
}