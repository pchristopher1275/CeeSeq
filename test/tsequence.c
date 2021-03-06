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
#include <sys/types.h>
#include <sys/stat.h>
#include <fts.h>
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
/*
Unit_declare(testNoteSequenceStart) {
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
		// Start one-shot
		Error_declare(err);
		Ticks noteDuration = 480;
		NoteSequenceFixture *fix = NoteSequenceFixture_newBuild1(Symbol_gen("piano"), noteDuration, err);
		fatal(!Error_iserror(err));

		Ticks clockStart = 100;
		Ticks current    = 100;
		NoteSequence_start(fix->seq1, clockStart, current, fix->queue, NULL, err);
		fatal(!Error_iserror(err));
		
		chk(fix->seq1->startTime == current);
		chk(fix->seq1->cursor    == 0);
		chk(TimedPq_len(fix->queue) == 1);
		chk(TimedPq_at(fix->queue, 0).time == 300);
		chk(TimedPq_at(fix->queue, 0).sequence->itype == NoteSequence_itype);
		NoteSequenceFixture_free(fix);
	}

	Unit_case(0) {
		// Start a master-clock
		Error_declare(err);
		Ticks noteDuration = 480;
		NoteSequenceFixture *fix = NoteSequenceFixture_newBuild1(Symbol_gen("piano"), noteDuration, err);
		fatal(!Error_iserror(err));
		NoteSequence_setCycle(fix->seq1, true);

		Ticks clockStart = 0;
		Ticks current    = 220;
		NoteSequence_start(fix->seq1, clockStart, current, fix->queue, NULL, err);
		fatal(!Error_iserror(err));
		chk(fix->seq1->startTime == 0);
		chk(fix->seq1->cursor    == 1);
		chk(TimedPq_len(fix->queue) == 1);
		chk(TimedPq_at(fix->queue, 0).time == 241);
		chk(TimedPq_at(fix->queue, 0).sequence->itype == NoteSequence_itype);
		
		NoteSequenceFixture_free(fix);
	}

	Unit_case(0) {
		// Start a master-clock where start time is after sequence end
		Error_declare(err);
		Ticks noteDuration = 480;
		NoteSequenceFixture *fix = NoteSequenceFixture_newBuild1(Symbol_gen("piano"), noteDuration, err);
		fatal(!Error_iserror(err));
		NoteSequence_setCycle(fix->seq1, true);

		Ticks clockStart = 0;
		Ticks current    = 242+480+1;
		NoteSequence_start(fix->seq1, clockStart, current, fix->queue, NULL, err);
		fatal(!Error_iserror(err));
		chk(fix->seq1->startTime == 242+480);
		chk(fix->seq1->sequenceLength == 242+480);
		chk(fix->seq1->cursor    == 0);
		chk(TimedPq_len(fix->queue) == 1);
		chk(TimedPq_at(fix->queue, 0).time == 242+480+200);
		chk(TimedPq_at(fix->queue, 0).sequence->itype == NoteSequence_itype);
		
		NoteSequenceFixture_free(fix);
	}

	Unit_case(0) {
		// Start a one-shot short duration
		Error_declare(err);
		Ticks noteDuration = 480/16;
		NoteSequenceFixture *fix = NoteSequenceFixture_newBuild1(Symbol_gen("piano"), noteDuration, err);
		fatal(!Error_iserror(err));

		Ticks clockStart = 100;
		Ticks current    = 100;
		NoteSequence_start(fix->seq1, clockStart, current, fix->queue, NULL, err);
		fatal(!Error_iserror(err));
		chk(fix->seq1->startTime == 100);
		chk(fix->seq1->cursor    == 0);
		chk(TimedPq_len(fix->queue) == 1);
		chk(TimedPq_at(fix->queue, 0).time == 300);
		chk(TimedPq_at(fix->queue, 0).sequence->itype == NoteSequence_itype);
	
		NoteSequenceFixture_free(fix);
	}

	Unit_case(0) {
		// Start a master-clock short duration
		Error_declare(err);
		Ticks noteDuration = 480/16;
		NoteSequenceFixture *fix = NoteSequenceFixture_newBuild1(Symbol_gen("piano"), noteDuration, err);
		fatal(!Error_iserror(err));
		NoteSequence_setCycle(fix->seq1, true);

		Ticks clockStart = 0;
		Ticks current    = 241;
		NoteSequence_start(fix->seq1, clockStart, current, fix->queue, NULL, err);
		fatal(!Error_iserror(err));
		chk(fix->seq1->startTime == 0);
		chk(fix->seq1->cursor    == 1);
		chk(TimedPq_len(fix->queue) == 1);
		chk(TimedPq_at(fix->queue, 0).time == 241);
		chk(TimedPq_at(fix->queue, 0).sequence->itype == NoteSequence_itype);
	
		NoteSequenceFixture_free(fix);
	}
}
*/
/*
Unit_declare(testNoteSequenceDrive) {
	Unit_case(1) { 
		// drive on-shot
		Error_declare(err);
		Ticks noteDuration = 250;
		NoteSequenceFixture *fix = NoteSequenceFixture_newBuild2(Symbol_gen("piano"), noteDuration, err);
		fatal(!Error_iserror(err));
	
		NoteSequenceFixture_driveToCompletion2(fix, 0, 0, err);
		fatal(!Error_iserror(err));

		const int nnotes = 3;
		NoteEvent notes[nnotes] = {
			{.pitch = 60, .velocity = 100, .stime = 200,     .duration = noteDuration},
			{.pitch = 61, .velocity = 101, .stime = 300,     .duration = noteDuration},
			{.pitch = 62, .velocity = 102, .stime = 400,     .duration = noteDuration},
		};
	
		fatal(NoteEventAr_len(fix->results) == nnotes);
		NoteEventAr_foreach(it, fix->results) {
			if (NoteSequence_isMarkerValue(notes[it.index].duration) || NoteSequence_isMarkerValue(it.var->duration)) {
				chk(notes[it.index].duration == it.var->duration);
				continue;
			}

			chk(it.var->pitch == notes[it.index].pitch);
			chk(it.var->velocity == notes[it.index].velocity);
			chk(it.var->stime == notes[it.index].stime);
			chk(it.var->duration == notes[it.index].duration);
		}
	}

	Unit_case(0) { 
		// drive on-shot short duration
		Error_declare(err);
		Ticks noteDuration = 50;
		NoteSequenceFixture *fix = NoteSequenceFixture_newBuild2(Symbol_gen("piano"), noteDuration, err);
		fatal(!Error_iserror(err));
	
		NoteSequenceFixture_driveToCompletion2(fix, 0, 0, err);
		fatal(!Error_iserror(err));

		const int nnotes = 3;
		NoteEvent notes[nnotes] = {
			{.pitch = 60, .velocity = 100, .stime = 200,     .duration = noteDuration},
			{.pitch = 61, .velocity = 101, .stime = 300,     .duration = noteDuration},
			{.pitch = 62, .velocity = 102, .stime = 400,     .duration = noteDuration},
		};
	
		fatal(NoteEventAr_len(fix->results) == nnotes);
		NoteEventAr_foreach(it, fix->results) {
			if (NoteSequence_isMarkerValue(notes[it.index].duration) || NoteSequence_isMarkerValue(it.var->duration)) {
				chk(notes[it.index].duration == it.var->duration);
				continue;
			}

			chk(it.var->pitch == notes[it.index].pitch);
			chk(it.var->velocity == notes[it.index].velocity);
			chk(it.var->stime == notes[it.index].stime);
			chk(it.var->duration == notes[it.index].duration);
		}	
	}

	Unit_case(1) { 
		// drive master clock
		printf("TOP\n");
		Error_declare(err);
		Ticks noteDuration = 250;
		NoteSequenceFixture *fix = NoteSequenceFixture_newBuild2(Symbol_gen("piano"), noteDuration, err);
		fatal(!Error_iserror(err));
	
		NoteSequenceFixture_driveToCompletion2(fix, 0, 350, err);
		fatal(!Error_iserror(err));

		const int nnotes = 4;
		NoteEvent notes[nnotes] = {
			{.pitch = 62, .velocity = 102, .stime = 400,     .duration = noteDuration},
			{.pitch = 60, .velocity = 100, .stime = 600,     .duration = noteDuration},
			{.pitch = 61, .velocity = 101, .stime = 700,     .duration = noteDuration},
			{.pitch = 62, .velocity = 102, .stime = 800,     .duration = noteDuration},
		};
	
		NoteEventAr_foreach(it, fix->results) {
			printf("%15d %15d %15d %15lld %15lld\n", it.index, it.var->pitch, it.var->velocity, it.var->stime, it.var->duration);
		}

		fatal(NoteEventAr_len(fix->results) == nnotes);
		NoteEventAr_foreach(it, fix->results) {
			if (NoteSequence_isMarkerValue(notes[it.index].duration) || NoteSequence_isMarkerValue(it.var->duration)) {
				chk(notes[it.index].duration == it.var->duration);
				continue;
			}

			chk(it.var->pitch == notes[it.index].pitch);
			chk(it.var->velocity == notes[it.index].velocity);
			chk(it.var->stime == notes[it.index].stime);
			chk(it.var->duration == notes[it.index].duration);
		}
		printf("YES\n");
		// Unit_call(testNoteSequenceDriveFixture(0, 350, 3, 4, true, 250, 1200, 0));	
	}

	Unit_case(0) { 
		// drive master clock start later
		// Unit_call(testNoteSequenceDriveFixture(0, 600, 0, 3, true, 250, 1200, 400));	
	}	
}
*/

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
	
		
		NoteSequence_padNoteOff(noteSequence, Ticks_maxTime, err);
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
		Error_declare(err);
		PortFind *portFind = PortFind_createStandardSpoof();
		const int nnotes = 6;
		NoteEvent notes[nnotes] = {
			{.pitch = 0,  .velocity = 0,   .stime = 400, .duration = NoteSequence_cycleDuration},
			{.pitch = 61, .velocity = 102, .stime = 400, .duration = 100},
			{.pitch = 61, .velocity = 102, .stime = 400, .duration = 100},
			{.pitch = 60, .velocity = 100, .stime = 200, .duration = 300},
			{.pitch = 60, .velocity = 100, .stime = 100, .duration = 300},
			{.pitch = 0,  .velocity = 0,   .stime = 200, .duration = NoteSequence_endgDuration},
		};
		// NoteSequence_makeConsistent is called in newFromEvents
		NoteSequence *noteSequence = NoteSequence_newFromEvents(Symbol_gen("piano"), portFind, nnotes, notes, err);
		fatal(!Error_iserror(err));

		// Notice that this is 1 less than nnotes b/c one of the notes above is removed.
		fatal(NoteEventAr_len(&noteSequence->events) == nnotes-1);
		NoteEvent *evs = noteSequence->events.data;
		chk(evs[0].stime == 100);
		chk(evs[0].pitch == 60);
		chk(evs[0].duration == 100);
		
		chk(evs[2].stime == 200);
		chk(evs[2].pitch == 60);
		chk(evs[2].duration == 300);

		chk(evs[4].stime == 400);
		chk(evs[4].duration == NoteSequence_cycleDuration);
		chk(noteSequence->sequenceLength == 400);

		NoteSequence_free(noteSequence);
		PortFind_free(portFind);
	}
}




Unit_declare(testNoteSequenceRecord) 
{
	{
		// Test basic record
		Error_declare(err);
		PortFind *portFind         = PortFind_createStandardSpoof();
		RecordBuffer *recordBuffer = RecordBuffer_newStart(0);

		const int nfullNotes = 5;
		NoteEvent fullNotes[nfullNotes] = {
			{.pitch = 60, .velocity = 100, .stime = 0,     .duration = 100},
			{.pitch = 61, .velocity = 101, .stime = 200,   .duration = 100},
			{.pitch = 0,  .velocity = 0,   .stime = 400,   .duration = NoteSequence_endgDuration},
			{.pitch = 62, .velocity = 102, .stime = 400,   .duration = 100},
			{.pitch = 0,  .velocity = 0,   .stime = 400,   .duration = NoteSequence_cycleDuration}
		};
	
		const int nnotes = 3;
		NoteEvent notes[nnotes] = {
			{.pitch = 60, .velocity = 100, .stime = 0,     .duration = 100},
			{.pitch = 61, .velocity = 101, .stime = 200,   .duration = 100},
			{.pitch = 62, .velocity = 102, .stime = 400,   .duration = 100},
		};

		const int ndirectives = 2;
		SequenceDriveDirective directives[ndirectives] = {
			{.time = 0,   .directive = SequenceDrive_play, .sequences = NULL},
			{.time = 400, .directive = SequenceDrive_play, .sequences = NULL}
		};

		NoteSequence *seq1 = NoteSequence_newFromEvents(Symbol_gen("piano"), portFind, nfullNotes, fullNotes, err);
		fatal(!Error_iserror(err));
		NoteSequence *seq2 = NoteSequence_newFromEvents(Symbol_gen("piano"), portFind, nfullNotes, fullNotes, err);
		fatal(!Error_iserror(err));

		SequenceAr *seqAr1 = SequenceAr_new(0);
		SequenceAr *seqAr2 = SequenceAr_new(0);
		SequenceAr_push(seqAr1, NoteSequence_castToSequence(seq1));
		SequenceAr_push(seqAr2, NoteSequence_castToSequence(seq2));
		directives[0].sequences = seqAr1;
		directives[1].sequences = seqAr2;
		
		SequenceDrive *seqDrive = SequenceDrive_newBuild(ndirectives, directives, recordBuffer);
		SequenceDrive_toCompletion(seqDrive, err);
		fatal(!Error_iserror(err));
		fatal(SequenceAr_len(RecordBuffer_sequences(recordBuffer)) == 2);
		NoteSequence *out1 = NoteSequence_castFromSequence(SequenceAr_at(RecordBuffer_sequences(recordBuffer), 0));
		NoteSequence *out2 = NoteSequence_castFromSequence(SequenceAr_at(RecordBuffer_sequences(recordBuffer), 1));
		fatal(out1 != NULL);
		fatal(out2 != NULL);
	
		chk(NoteSequence_tableNotesEqual(out1, nnotes, notes, true));
		chk(NoteSequence_tableNotesEqual(out2, nnotes, notes, false));
		chk(out1->startTime == 0);
		chk(out2->startTime == 400);

		SequenceAr_free(seqAr1);
		SequenceAr_free(seqAr2);
		SequenceDrive_free(seqDrive);
		RecordBuffer_free(recordBuffer);
		PortFind_free(portFind);

	}

	{
		// Test interupted record
		Error_declare(err);
		PortFind *portFind         = PortFind_createStandardSpoof();
		RecordBuffer *recordBuffer = RecordBuffer_newStart(0);

		const int nfullNotes = 5;
		NoteEvent fullNotes[nfullNotes] = {
			{.pitch = 60, .velocity = 100, .stime = 0,     .duration = 100},
			{.pitch = 61, .velocity = 101, .stime = 200,   .duration = 100},
			{.pitch = 0,  .velocity = 0,   .stime = 400,   .duration = NoteSequence_endgDuration},
			{.pitch = 62, .velocity = 102, .stime = 400,   .duration = 100},
			{.pitch = 0,  .velocity = 0,   .stime = 400,   .duration = NoteSequence_cycleDuration}
		};
	

		NoteSequence *seq1 = NoteSequence_newFromEvents(Symbol_gen("piano"), portFind, nfullNotes, fullNotes, err);
		fatal(!Error_iserror(err));
		NoteSequence *seq2 = NoteSequence_newFromEvents(Symbol_gen("piano"), portFind, nfullNotes, fullNotes, err);
		fatal(!Error_iserror(err));

		SequenceAr *seqAr1 = SequenceAr_new(0);
		SequenceAr_push(seqAr1, NoteSequence_castToSequence(seq1));
		
		const int ndirectives = 4;
		SequenceDriveDirective directives[ndirectives] = {
			{.time = 0,    .directive = SequenceDrive_play, .sequences = seqAr1},
			{.time = 250,  .directive = SequenceDrive_stop, .sequences = seqAr1},
			{.time = 600,  .directive = SequenceDrive_play, .sequences = seqAr1},
			{.time = 1050, .directive = SequenceDrive_stop, .sequences = seqAr1},
		};

		const int nnotes1 = 2;
		NoteEvent notes1[nnotes1] = {
			{.pitch = 60, .velocity = 100, .stime = 0,     .duration = 100},
			{.pitch = 61, .velocity = 101, .stime = 200,   .duration = 50}
		};

		const int nnotes2 = 3;
		NoteEvent notes2[nnotes2] = {
			{.pitch = 60, .velocity = 100, .stime = 0,     .duration = 100},
			{.pitch = 61, .velocity = 101, .stime = 200,   .duration = 100},
			{.pitch = 62, .velocity = 102, .stime = 400,   .duration = 50}
		};

		SequenceDrive *seqDrive = SequenceDrive_newBuild(ndirectives, directives, recordBuffer);
		SequenceDrive_toCompletion(seqDrive, err);
		fatal(!Error_iserror(err));
		fatal(SequenceAr_len(RecordBuffer_sequences(recordBuffer)) == 2);
		NoteSequence *out1 = NoteSequence_castFromSequence(SequenceAr_at(RecordBuffer_sequences(recordBuffer), 0));
		NoteSequence *out2 = NoteSequence_castFromSequence(SequenceAr_at(RecordBuffer_sequences(recordBuffer), 1));
		fatal(out1 != NULL);
		fatal(out2 != NULL);
	
		chk(NoteSequence_tableNotesEqual(out1, nnotes1, notes1, false));
		chk(NoteSequence_tableNotesEqual(out2, nnotes2, notes2, false));
		chk(out1->startTime == 0);
		chk(out2->startTime == 600);

		SequenceAr_free(seqAr1);
		SequenceDrive_free(seqDrive);
		RecordBuffer_free(recordBuffer);
		PortFind_free(portFind);
	}

	{
		// Test RecordBuffer_compact
		Error_declare(err);
		PortFind *portFind         = PortFind_createStandardSpoof();
		RecordBuffer *recordBuffer = RecordBuffer_newStart(0);
		const int nnotes = 3;
		NoteEvent notes[nnotes] = {
			{.pitch = 60, .velocity = 100, .stime = 0,     .duration = 100},
			{.pitch = 61, .velocity = 101, .stime = 200,   .duration = 100},
			{.pitch = 62, .velocity = 102, .stime = 400,   .duration = 100}
		};
		NoteSequence *seq1 = NoteSequence_newTrack(Symbol_gen("piano"), portFind);
		NoteSequence *seq2 = NoteSequence_newTrack(Symbol_gen("piano"), portFind);
		NoteSequence *seq3 = NoteSequence_newTrack(Symbol_gen("piano"), portFind);
		seq1->startTime = 0;
		seq2->startTime = 1000;
		seq3->startTime = 2000;

		for (int i = 0; i < nnotes; i++) {
			NoteEventAr_push(&seq1->events, notes[i]);
			NoteEventAr_push(&seq2->events, notes[i]);
			NoteEventAr_push(&seq3->events, notes[i]);
		}

		SequenceAr_push(&recordBuffer->sequences, NoteSequence_castToSequence(seq1));
		SequenceAr_push(&recordBuffer->sequences, NoteSequence_castToSequence(seq2));
		SequenceAr_push(&recordBuffer->sequences, NoteSequence_castToSequence(seq3));

		const int nfullNotes = 11;
		NoteEvent fullNotes[nfullNotes] = {
			{.pitch = 60, .velocity = 100, .stime = 0,     .duration = 100},
			{.pitch = 61, .velocity = 101, .stime = 200,   .duration = 100},
			{.pitch = 62, .velocity = 102, .stime = 400,   .duration = 100},

			{.pitch = 60, .velocity = 100, .stime = 1000+0,     .duration = 100},
			{.pitch = 61, .velocity = 101, .stime = 1000+200,   .duration = 100},
			{.pitch = 62, .velocity = 102, .stime = 1000+400,   .duration = 100},

			{.pitch = 60, .velocity = 100, .stime = 2000+0,     .duration = 100},
			{.pitch = 61, .velocity = 101, .stime = 2000+200,   .duration = 100},
			{.pitch = 0,  .velocity = 0,   .stime = 2000+400,   .duration = NoteSequence_endgDuration},
			{.pitch = 62, .velocity = 102, .stime = 2000+400,   .duration = 100},
			{.pitch = 0,  .velocity = 0,   .stime = 2000+400,   .duration = NoteSequence_cycleDuration}
		};
		NoteSequence *expected = NoteSequence_newFromEvents(Symbol_gen("piano"), portFind, nfullNotes, fullNotes, err);
		fatal(!Error_iserror(err));

		SequenceAr *output = SequenceAr_new(0);
		RecordBuffer_compact(recordBuffer, output, err);
		fatal(!Error_iserror(err));

		fatal(SequenceAr_len(output) == 1);
		Sequence *outputSeq = NULL;
		SequenceAr_foreach(it, output) {
			outputSeq = *it.var;
			break;
		}
		NoteSequence *outputNSeq = NoteSequence_castFromSequence(outputSeq);
		fatal(outputNSeq != NULL);
		chk(NoteSequence_tableNotesEqual(outputNSeq, nfullNotes, fullNotes, false));
	}
}
Unit_declare(testFloatSequence) 
{
	// {
	// 	// Test start one-shot
	// 	Error_declare(err);
	// 	PortFind *portFind = PortFind_createStandardSpoof();
	// 	TimedPq *timedPq = TimedPq_new(0);
	// 	RecordBuffer *recordBuffer = RecordBuffer_newStart(0);
	// 	const int nevents  = 1;
	// 	FloatEvent events[nevents] = {
	// 		{.stime = 100, .value = 0},
	// 		{.stime = 200, .value = 60},
	// 		{.stime = 300, .value = 127}
	// 	};

	// 	int cc = 10;
	// 	FloatSequence *seq1 = FloatSequence_newFromEvents(Symbol_gen("piano"), cc, portFind, nevents, events);
	// 	FloatSequence_start(seq1, 50, 50, timedPq, recordBuffer, err);
	// 	chk(seq1->cursor == 0);
	// 	chk(seq1->recordingSeq != NULL);
	// 	chk(SequenceAr_len(&recordBuffer->sequences) == 1);
	// 	fatal(TimedPq_len(timedPq) == 1);
	// 	chk(TimedPq_at(timedPq, 0).time == 100);

	// 	PortFind_free(portFind);
	// 	TimedPq_free(timedPq);
	// 	RecordBuffer_free(recordBuffer);
	// }
} 
int main(int argc, char *argv[]) {
	Unit_initialize(argc, argv);
	// Unit_test(testNoteSequenceStart);
	// Unit_test(testNoteSequenceDrive);
	Unit_test(testNoteSequenceStartAndDrive);
	Unit_test(testNoteSequenceStopAndEndgroup);
	Unit_test(testNoteSequenceRecord);
	Unit_test(testFloatSequence);
	Unit_finalize();
}