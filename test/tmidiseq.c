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
#include "../src/core.c"
#include "../src/unit.c"
#include "../src/application.c"

Unit_declare(testStringSplit) {
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

int main(int argc, char *argv[]) {
	Unit_initialize(argc, argv);
	Unit_test(testStringSplit);
	Unit_finalize();
}