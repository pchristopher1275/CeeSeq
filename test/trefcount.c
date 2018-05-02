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



Unit_declare(testCompileNames) {
	{
		// ALL pointers have new/incRef/decRef
		Bar *s = Bar_new();
		int count = Bar_refCount(s);
		Bar_incRef(s);
		Bar_decRef(s);
		Bar_decRef(s);
	}

#   ifdef COMPILE_CHECK
	{
		// NO values have new/decRef
		StdValue *s = Bar_new();
		StdValue_decRef(s);
	}
	{
		// NO values have init/clear
		StdValue v = {0};
		StdValue_init(&v);
		StdValue_clear(&v);
	}
	{
		// NO pointers have init/clear
		Bar s = {0};
		Bar_init(&s);
		Bar_clear(&s);
	}
	{
		// NO pointers have free
		Bar *s = Bar_new();
		Bar_free(s);
	}
#   endif
}

Unit_declare(testBasic) {
	{
		// New is called with refCount == 1
		Bar *s = Bar_new();
		chk(Bar_refCount(s) == 1);
		Bar_decRef(s);
	}
	{
		// incRef increments ref count	
		Bar *s = Bar_new();
		Bar_incRef(s);
		chk(Bar_refCount(s) == 2);
		Bar_decRef(s);
		Bar_decRef(s);
	}
	{
		// decRef decrements ref count	
		Bar *s = Bar_new();
		Bar_incRef(s);
		Bar_decRef(s);
		chk(Bar_refCount(s) == 1);
		Bar_decRef(s);
	}
	{
		// decRef deletes object at zero count
		Bar *s = Bar_new();
		int a = Mem_nallocs();
		Bar_decRef(s);
		chk(a-Mem_nallocs() == 1);
	}
}

Unit_declare(testTransativity) {
	{
		// Setter sets refcount
		Bar2 *s2 = Bar2_new();
		Bar *s = Bar_new();
		Bar2_setR(s);

		chk(Bar_refCount(s) == 2);
		Bar_decRef(s);
		Bar2_decRef(s2);
	}
	{
		// Object free decs refcount
		Bar2 *s2 = Bar2_new();
		Bar *s = Bar_new();
		Bar2_setR(s);
		Bar2_decRef(s2);
		chk(Bar_refCount(s) == 1);
		Bar_decRef(s2);
	}

	{
		// getter does not incrment ref count
		Bar2 *s2 = Bar2_new();
		Bar *s = Bar_new();
		Bar2_setR(s);
		chk(Bar_refCount(Bar2_r(s2)) == 2);
		chk(Bar_refCount(Bar2_r(s2)) == 2);
		Bar2_decRef(s2);
		Bar_decRef(s);
	}
}

Unit_declare(testArray) {
	{
		// Array has refcount
		BarAr *sar = BarAr_new();
		chk(BarAr_refCount(sar) == 1);
		Bar_decRef(sar);
	}
	{
		// Push incs count
		BarAr *sar = BarAr_new();
		Bar *s = Bar_new();
		BarAr_push(sar, s);
		chk(BarAr_refCount(s) == 2);
		BarAr_decRef(sar);
		Bar_decRef(s);
	}
	{
		// Get DOES NOT inc count
		Error_declare(err);
		BarAr *sar = BarAr_new();
		Bar *s = Bar_new();
		BarAr_push(sar, s);
		s = BarAr_get(sar, 0, err);
		fatal(!Error_iserror(err));
		chk(Bar_refCount(s) == 2);
		s = BarAr_get(sar, 0, err);
		fatal(!Error_iserror(err));
		chk(Bar_refCount(s) == 2);
		BarAr_decRef(sar);
		Bar_decRef(s);
	}
	{
		// Set incs and decs refcount
		Error_declare(err);
		BarAr *sar = BarAr_new();
		Bar *sA = Bar_new();
		Bar *sB = Bar_new();
		BarAr_push(sar, sA);
		BarAr_set(sar, 0, sB, err);
		fatal(!Error_iserror(err));
		chk(Bar_refCount(sA) == 1);
		chk(Bar_refCount(sB) == 2);
		BarAr_decRef(sar);
		Bar_decRef(sA);
		Bar_decRef(sB);
	}

	{
		// Pop decs refcount
		Error_declare(err);
		BarAr *sar = BarAr_new();
		Bar *s = Bar_new();
		BarAr_push(sar, s);
		s = BarAr_pop(sar, err);
		fatal(!Error_iserror(err));
		chk(Bar_refCount(s) == 1);
		BarAr_decRef(sar);
		Bar_decRef(s);
	}
}



int main(int argc, char *argv[]) {
	Unit_initialize(argc, argv);
	Unit_test(testCompileNames);
	Unit_test(testBasic);
	Unit_test(testTransativity);
	Unit_finalize();
}