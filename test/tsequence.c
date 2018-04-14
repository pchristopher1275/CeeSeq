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

Unit_declare(testNoteSequence) {
	{
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

	{
		// Start a one-shot
		PortFind *portFind = PortFind_createStandardSpoof();
		const int nnotes = 5;
		NoteEvent notes[nnotes] = {
			{.pitch = 60, .velocity = 100, .stime = 200,     .duration = 480},
			{.pitch = 61, .velocity = 101, .stime = 241,     .duration = 480},
			{.pitch = 0,  .velocity = 0,   .stime = 242,     .duration = NoteSequence_endgDuration},
			{.pitch = 62, .velocity = 102, .stime = 242,     .duration = 480},
			{.pitch = 0,  .velocity = 0,   .stime = 242+480, .duration = NoteSequence_cycleDuration},
		};
		NoteSequence *noteSequence = NoteSequence_newFromEvents(Symbol_gen("piano"), portFind, nnotes, notes);
		TimedPq *timedPq = TimedPq_new(0);
		
		Error_declare(err);
		NoteSequence_start(noteSequence, 100, 100, timedPq, NULL, err);
		fatal(!Error_iserror(err));
		chk(noteSequence->startTime == 100);
		chk(noteSequence->cursor    == 0);


		// Make sure this sequence was queued
		chk(TimedPq_len(timedPq) == 1);

		// Make sure that no sequence is returned until the first sequence event at 300
		Sequence *seq = TimedPq_dequeue(timedPq, 150);
		chk(seq == NULL);

		// Now fetch the sequence event
		seq = TimedPq_dequeue(timedPq, 300);
		fatal(seq != NULL);
		fatal((void*)seq == (void*)noteSequence);

		TimedPq_free(timedPq);
		NoteSequence_free(noteSequence);
		PortFind_free(portFind);	
	}

	{
		// Start a master-clock
		PortFind *portFind = PortFind_createStandardSpoof();
		const int nnotes = 5;
		NoteEvent notes[nnotes] = {
			{.pitch = 60, .velocity = 100, .stime = 200,     .duration = 480},
			{.pitch = 61, .velocity = 101, .stime = 241,     .duration = 480},
			{.pitch = 0,  .velocity = 0,   .stime = 242,     .duration = NoteSequence_endgDuration},
			{.pitch = 62, .velocity = 102, .stime = 242,     .duration = 480},
			{.pitch = 0,  .velocity = 0,   .stime = 242+480, .duration = NoteSequence_cycleDuration},
		};
		NoteSequence *noteSequence = NoteSequence_newFromEvents(Symbol_gen("piano"), portFind, nnotes, notes);
		NoteSequence_setCycle(noteSequence, true);
		TimedPq *timedPq = TimedPq_new(0);
		
		Error_declare(err);
		NoteSequence_start(noteSequence, 0, 241, timedPq, NULL, err);
		fatal(!Error_iserror(err));
		chk(noteSequence->startTime == 0);
		chk(noteSequence->cursor    == 2);


		// Make sure this sequence was queued
		chk(TimedPq_len(timedPq) == 1);

		// Make sure that no sequence is returned until the first sequence event at 300
		Sequence *seq = TimedPq_dequeue(timedPq, 241);
		chk(seq == NULL);

		// Now fetch the sequence event
		seq = TimedPq_dequeue(timedPq, 242);
		fatal(seq != NULL);
		fatal((void*)seq == (void*)noteSequence);

		TimedPq_free(timedPq);
		NoteSequence_free(noteSequence);
		PortFind_free(portFind);	
	}

	return;
	{
		// drive on-shot
		PortFind *portFind = PortFind_createStandardSpoof();
		const int nnotes = 5;
		NoteEvent notes[nnotes] = {
			{.pitch = 60, .velocity = 100, .stime = 200,     .duration = 100},
			{.pitch = 61, .velocity = 101, .stime = 300,     .duration = 100},
			{.pitch = 0,  .velocity = 0,   .stime = 400,     .duration = NoteSequence_endgDuration},
			{.pitch = 62, .velocity = 102, .stime = 400,     .duration = 100},
			{.pitch = 0,  .velocity = 0,   .stime = 400,     .duration = NoteSequence_cycleDuration},
		};
		TimedPq *timedPq = TimedPq_new(0);
		NoteSequence *noteSequence = NoteSequence_newFromEvents(Symbol_gen("piano"), portFind, nnotes, notes);
		Outlet *ol = noteSequence->outlet;
		NoteOutlet *nol = NoteOutlet_castFromOutlet(ol);
		fatal(nol != NULL); 
		
		Error_declare(err);
		NoteSequence_start(noteSequence, 0, 0, timedPq, NULL, err);
		fatal(!Error_iserror(err));

		for (int i = 0; i < nnotes; i++) {
			NoteOutlet_dbRewindSent();
			Sequence *seq = TimedPq_dequeue(timedPq, notes[i].stime);
			fatal(seq != NULL);
			fatal((void*)seq == (void*)noteSequence);
			NoteSequence_drive(noteSequence, notes[i].stime, timedPq, err);
			fatal(!Error_iserror(err));

		}

		

		TimedPq_free(timedPq);
		NoteSequence_free(noteSequence);
		PortFind_free(portFind);	
	}
}

int main(int argc, char *argv[]) {
	Unit_initialize(argc, argv);
	Unit_test(testNoteSequence);
	Unit_finalize();
}