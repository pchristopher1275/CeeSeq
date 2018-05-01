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
		StdRefCount *s = StdRefCount_new();
		int count = StdRefCount_refCount(s);
		StdRefCount_incRef(s);
		StdRefCount_decRef(s);
		StdRefCount_decRef(s);
	}

#   ifdef COMPILE_CHECK
	{
		// NO values have new/decRef
		StdValue *s = StdRefCount_new();
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
		StdRefCount s = {0};
		StdRefCount_init(&s);
		StdRefCount_clear(&s);
	}
	{
		// NO pointers have free
		StdRefCount *s = StdRefCount_new();
		StdRefCount_free(s);
	}
#   endif
}

Unit_declare(testBasic) {
	{
		// New is called with refCount == 1
		StdRefCount *s = StdRefCount_new();
		chk(StdRefCount_refCount(s) == 1);
		StdRefCount_decRef(s);
	}
	{
		// incRef increments ref count	
		StdRefCount *s = StdRefCount_new();
		StdRefCount_incRef(s);
		chk(StdRefCount_refCount(s) == 2);
		StdRefCount_decRef(s);
		StdRefCount_decRef(s);
	}
	{
		// decRef decrements ref count	
		StdRefCount *s = StdRefCount_new();
		StdRefCount_incRef(s);
		StdRefCount_decRef(s);
		chk(StdRefCount_refCount(s) == 1);
		StdRefCount_decRef(s);
	}
	{
		// decRef deletes object at zero count
		StdRefCount *s = StdRefCount_new();
		int a = Mem_nallocs();
		StdRefCount_decRef(s);
		chk(a-Mem_nallocs() == 1);
	}
}

Unit_declare(testTransativity) {
	{
		// Setter sets refcount
		StdRefCount2 *s2 = StdRefCount2_new();
		StdRefCount *s = StdRefCount_new();
		StdRefCount2_setR(s);

		chk(StdRefCount_refCount(s) == 2);
		StdRefCount_decRef(s);
		StdRefCount2_decRef(s2);
	}
	{
		// Object free decs refcount
		StdRefCount2 *s2 = StdRefCount2_new();
		StdRefCount *s = StdRefCount_new();
		StdRefCount2_setR(s);
		StdRefCount2_decRef(s2);
		chk(StdRefCount_refCount(s) == 1);
		StdRefCount_decRef(s2);
	}

	{
		// getter does not incrment ref count
		StdRefCount2 *s2 = StdRefCount2_new();
		StdRefCount *s = StdRefCount_new();
		StdRefCount2_setR(s);
		chk(StdRefCount_refCount(StdRefCount2_r(s2)) == 2);
		chk(StdRefCount_refCount(StdRefCount2_r(s2)) == 2);
		StdRefCount2_decRef(s2);
		StdRefCount_decRef(s);
	}
}

Unit_declare(testArray) {
	{
		// Array has refcount
		StdRefCountAr *sar = StdRefCountAr_new();
		chk(StdRefCountAr_refCount(sar) == 1);
		StdRefCount_decRef(sar);
	}
	{
		// Push incs count
		StdRefCountAr *sar = StdRefCountAr_new();
		StdRefCount *s = StdRefCount_new();
		StdRefCountAr_push(sar, s);
		chk(StdRefCountAr_refCount(s) == 2);
		StdRefCountAr_decRef(sar);
		StdRefCount_decRef(s);
	}
	{
		// Get DOES NOT inc count
		Error_declare(err);
		StdRefCountAr *sar = StdRefCountAr_new();
		StdRefCount *s = StdRefCount_new();
		StdRefCountAr_push(sar, s);
		s = StdRefCountAr_get(sar, 0, err);
		fatal(!Error_iserror(err));
		chk(StdRefCount_refCount(s) == 2);
		s = StdRefCountAr_get(sar, 0, err);
		fatal(!Error_iserror(err));
		chk(StdRefCount_refCount(s) == 2);
		StdRefCountAr_decRef(sar);
		StdRefCount_decRef(s);
	}
	{
		// Set incs and decs refcount
		Error_declare(err);
		StdRefCountAr *sar = StdRefCountAr_new();
		StdRefCount *sA = StdRefCount_new();
		StdRefCount *sB = StdRefCount_new();
		StdRefCountAr_push(sar, sA);
		StdRefCountAr_set(sar, 0, sB, err);
		fatal(!Error_iserror(err));
		chk(StdRefCount_refCount(sA) == 1);
		chk(StdRefCount_refCount(sB) == 2);
		StdRefCountAr_decRef(sar);
		StdRefCount_decRef(sA);
		StdRefCount_decRef(sB);
	}

	{
		// Pop decs refcount
		Error_declare(err);
		StdRefCountAr *sar = StdRefCountAr_new();
		StdRefCount *s = StdRefCount_new();
		StdRefCountAr_push(sar, s);
		s = StdRefCountAr_pop(sar, err);
		fatal(!Error_iserror(err));
		chk(StdRefCount_refCount(s) == 1);
		StdRefCountAr_decRef(sar);
		StdRefCount_decRef(s);
	}
}



int main(int argc, char *argv[]) {
	Unit_initialize(argc, argv);
	Unit_test(testCompileNames);
	Unit_test(testBasic);
	Unit_test(testTransativity);
	Unit_finalize();
}