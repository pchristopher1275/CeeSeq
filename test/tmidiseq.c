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

Unit_declare(testStringSplit) 
{
	{
		// big split
		StringPtAr *stringPtAr = StringPtAr_new(0);
		String *buffer = String_fmt("a,b,c,d,e");		
		String_split(buffer, ",", stringPtAr);
		chk(StringPtAr_len(stringPtAr) == 5);
		const char *exp[] = {"a", "b", "c", "d", "e"};
		StringPtAr_foreach(it, stringPtAr) {
			fatal(it.index < 5);
			chk(String_cequal(*it.var, exp[it.index]));
		}
		StringPtAr_free(stringPtAr);
	}

	{
		// Smaller split
		StringPtAr *stringPtAr = StringPtAr_new(0);
		String *buffer = String_fmt("a");		
		String_split(buffer, ",", stringPtAr);
		chk(StringPtAr_len(stringPtAr) == 1);
		const char *exp[] = {"a"};
		StringPtAr_foreach(it, stringPtAr) {
			fatal(it.index < 1);
			chk(String_cequal(*it.var, exp[it.index]));
		}
		StringPtAr_free(stringPtAr);	
	}

	{
		// Empty split should return a single element list with just the empty string
		StringPtAr *stringPtAr = StringPtAr_new(0);
		String *buffer = String_fmt("");		
		String_split(buffer, ",", stringPtAr);
		chk(StringPtAr_len(stringPtAr) == 1);
		StringPtAr_foreach(it, stringPtAr) {
			fatal(it.index < 1);
			chk(String_cequal(*it.var, ""));
		}
		StringPtAr_free(stringPtAr);	
	}	
}

Unit_declare(testSymbol) 
{
	{
		// Test basic gen
		Symbol *sym = Symbol_gen("foo");
		chk(sym != NULL);
		chk(strcmp(Symbol_cstr(sym), "foo") == 0);
		chk(SymbolPtAr_len(gSymbols) == 1);
		Symbol_freeAll();
		chk(SymbolPtAr_len(gSymbols) == 0);
	}

	{
		// Test gen
		Symbol *sym1 = Symbol_gen("foo");
		Symbol *sym2 = Symbol_gen("foo");
		chk(sym1 == sym2);
		chk(strcmp(Symbol_cstr(sym1), "foo") == 0);
		chk(SymbolPtAr_len(gSymbols) == 1);
		Symbol_freeAll();
	}

	{
		// Test gen multi
		Symbol *foo = Symbol_gen("foo");
		Symbol *bar = Symbol_gen("bar");
		chk(foo != bar);
		chk(strcmp(Symbol_cstr(foo), "foo") == 0);
		chk(strcmp(Symbol_cstr(bar), "bar") == 0);
		chk(SymbolPtAr_len(gSymbols) == 2);
		Symbol_freeAll();
		chk(SymbolPtAr_len(gSymbols) == 0);
	}
}

Unit_declare(testMidiseq) 
{
	Midiseq_setMidicsvExecPath();
	{
		Error_declare(err);
		Midiseq *mseq = Midiseq_fromfile("test/data/midiseqFromfile.mid", err);
		fatal(!Error_iserror(err));
		fatal(mseq != NULL);
		Ticks expTimes[4] = {
			0, 480, 960, 1440
		};
		int expPitch[4] = {
			60, 61, 62, 63
		};
		int expVelocity[4] = {
			100, 101, 102, 103
		};
		
		fatal(MEventAr_len(&mseq->events) == 6);

		int noteCount = 0;
		MEventAr_foreach(it, &mseq->events) {
			MEvent cell = *it.var;
			if (MEvent_type(cell) == Midiseq_notetype) {
				fatal(noteCount < 4);
				chk(MEvent_noteDuration(cell) == 480);
				chk(MEvent_t(cell) == expTimes[noteCount]);
				chk(MEvent_notePitch(cell) == expPitch[noteCount]);
				chk(MEvent_noteVelocity(cell) == expVelocity[noteCount]);
				noteCount++;
			} else if (MEvent_type(cell) == Midiseq_endgrptype) {
				chk(MEvent_t(cell) == 1440);
			} else if (MEvent_type(cell) == Midiseq_cycletype) {
				chk(MEvent_t(cell) == 1920);
			} else {
				fatal(false);
			}
		}
		Midiseq_free(mseq);
	}
}

int main(int argc, char *argv[]) {
	Unit_initialize(argc, argv);
	Unit_test(testStringSplit);
	Unit_test(testSymbol);
	Unit_test(testMidiseq);
	Unit_finalize();
}