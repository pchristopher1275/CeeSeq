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

Unit_declare(testTypeLifecycle) {
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

Unit_declare(testGetterSetter) {
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
		Bar_decRef(s);
	}

	{
		// getter does not inc ref count
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
		BarAr_decRef(sar);
	}

	{
		// Push incs count
		BarAr *ba = BarAr_new();
		Bar *b = Bar_new();
		BarAr_push(ba, b);
		chk(Bar_refCount(b) == 2);
		BarAr_decRef(ba);
		Bar_decRef(b);
	}

	{
		// Get DOES NOT inc count
		Error_declare(err);
		BarAr *ba = BarAr_new();
		Bar *b = Bar_new();
		BarAr_push(ba, b);

		b = BarAr_get(ba, 0, err);
		fatal(!Error_iserror(err));
		chk(Bar_refCount(b) == 2);
		b = BarAr_get(sar, 0, err);
		fatal(!Error_iserror(err));
		chk(Bar_refCount(b) == 2);
		BarAr_decRef(ba);
		Bar_decRef(b);
	}

	{
		// Set incs and decs refcount
		Error_declare(err);
		BarAr *ba = BarAr_new();
		Bar *b1 = Bar_new();
		Bar *b2 = Bar_new();
		BarAr_push(sar, b1);

		BarAr_set(ba, 0, b2, err);
		fatal(!Error_iserror(err));
		chk(Bar_refCount(b1) == 1);
		chk(Bar_refCount(b2) == 2);
		BarAr_decRef(ba);
		Bar_decRef(b1);
		Bar_decRef(b2);
	}

	{
		// pop DOES NOT dec refcount
		Error_declare(err);
		BarAr *ba = BarAr_new();
		Bar *b = Bar_new();
		BarAr_push(ba, b);
		b = BarAr_pop(ba, err);
		fatal(!Error_iserror(err));
		chk(Bar_refCount(b) == 2);
		BarAr_decRef(ba);
		Bar_decRef(b);
		Bar_decRef(b);
	}

	{
		// popDecRef decs refcount
		Error_declare(err);
		BarAr *ba = BarAr_new();
		Bar *b = Bar_new();
		BarAr_push(ba, b);
		BarAr_popDecRef(ba, err);
		fatal(!Error_iserror(err));
		chk(Bar_refCount(b) == 1);
		BarAr_decRef(ba);
		Bar_decRef(b);
	}

	{
		// insert incs refcount
		Error_declare(err);
		BarAr *ba = BarAr_new();
		Bar *b = Bar_new();
		BarAr_insert(ba, 0, b, err);
		fatal(!Error_iserror(err));
		chk(Bar_refCount(b) == 2);
		BarAr_decRef(ba);
		Bar_decRef(b);
	}

	{
		// remove decs refcount
		Error_declare(err);
		BarAr *ba = BarAr_new();
		Bar *b = Bar_new();
		BarAr_push(ba, b);
		BarAr_remove(ba, 0, err);
		fatal(!Error_iserror(err));
		chk(Bar_refCount(b) == 1);
		BarAr_decRef(ba);
		Bar_decRef(b);
	}

	{
		// pqPush incs refcount
		Error_declare(err);
		BarAr *ba = BarAr_new();
		Bar *b = Bar_new();
		BarAr_pqPush(ba, b);
		chk(Bar_refCount(b) == 2);
		BarAr_decRef(ba);
		Bar_decRef(b);
	}

	{
		// pqPop DOES NOT dec refcount
		Error_declare(err);
		BarAr *ba = BarAr_new();
		Bar *b = Bar_new();
		BarAr_pqPush(ba, b);
		b = BarAr_pqPop(ba, err);
		fatal(!Error_iserror(err));
		chk(Bar_refCount(b) == 2);
		BarAr_decRef(ba);
		Bar_decRef(b);
		Bar_decRef(b);
	}

	{
		// pqPopDecRef decs refcount
		Error_declare(err);
		BarAr *ba = BarAr_new();
		Bar *b = Bar_new();
		BarAr_pqPush(ba, b);
		BarAr_pqPopDecRef(ba, err);
		fatal(!Error_iserror(err));
		chk(Bar_refCount(b) == 1);
		BarAr_decRef(ba);
		Bar_decRef(b);
	}

	{
		// pqPeek doesn't change refcount
		Error_declare(err);
		BarAr *ba = BarAr_new();
		Bar *b = Bar_new();
		BarAr_pqPush(ba, b);
		bool q = false;
		chk(Bar_refCount(BarAr_pqPeek(ba, &q)) == 1);
		chk(Bar_refCount(BarAr_pqPeek(ba, &q)) == 1);
		BarAr_decRef(ba);
		Bar_decRef(b);
	}

	{
		// binInsert incs refcount
		Error_declare(err);
		BarAr *ba = BarAr_new();
		Bar *b = Bar_new();
		BarAr_binInsert(ba, b);
		chk(Bar_refCount(b) == 2);
		BarAr_decRef(ba);
		Bar_decRef(b);
	}

	{
		// binRemove incs refcount
		Error_declare(err);
		BarAr *ba = BarAr_new();
		Bar *b = Bar_new();
		BarAr_push(ba, b);
		BarAr_binRemove(ba, b);
		chk(Bar_refCount(b) == 1);
		BarAr_decRef(ba);
		Bar_decRef(b);
	}
}

Unit_declare(testClone) {
	{
		// All references have clone
		Bar *b = Bar_new();
		b->i = 1234;
		Bar *c = Bar_clone(b);
		chk(c != b);
		chk(c->i == 1234);
		chk(Bar_refCount(c) == 1);
		Bar_decRef(b);
		Bar_decRef(c);
	}

	{
		// All arrays have clone
		BarAr *ba = BarAr_new();
		Bar *b = Bar_new();
		b->i = 1234;
		BarAr_push(ba, b);
		BarAr *ca = BarAr_clone(ba);
		chk(ba != ca);
		fatal(BarAr_len(ca) == 1);
		Bar *c = BarAr_at(ba, 0);
		chk(c != b);
		chk(c->i == 1234);
		BarAr_decRef(ba);
		BarAr_decRef(ca);
		Bar_decRef(b);
		Bar_decRef(c);
	}
}


int main(int argc, char *argv[]) {
	Unit_initialize(argc, argv);
	Unit_test(testCompileNames);
	Unit_test(testBasic);
	Unit_test(testTransativity);
	Unit_finalize();
}