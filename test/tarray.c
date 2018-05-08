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

Unit_declare(testNewFree) {
	{
		// Array has new
		IntAr *ia = IntAr_new();
		chk(ia != NULL);
		IntAr_decRef(ia);
	}

	{
		// Array has new
		FooAr *fa = FooAr_new();
		chk(fa != NULL);
		FooAr_decRef(fa);
	}
}

Unit_declare(testLen) {
	{
		// Array starts with zero length
		IntAr *ia = IntAr_new();
		chk(IntAr_len(ia) == 0);
		IntAr_decRef(ia);
	}
	{
		// Array keeps track of length on push
		IntAr *ia = IntAr_new10();
		chk(IntAr_len(ia) == 10);
		IntAr_decRef(ia);
	}
	{
		// Array keeps track of length on pop
		Error_declare(err);
		IntAr *ia = IntAr_new10();
		int i = IntAr_pop(ia, err);
		fatal(!Error_iserror(err));
		chk(IntAr_len(ia) == 9);
		IntAr_decRef(ia);
	}

	{
		// Truncate makes length 0
		IntAr *ia = IntAr_new10();
		IntAr_truncate(ia, 5);
		chk(IntAr_len(arr) == 5);
		IntAr_decRef(ia);
	}

	{
		// Fit sets cap to length
		IntAr *ia = IntAr_new10();
		chk(IntAr_cap(ia) > 10);
		IntAr_fit(ia);
		chk(IntAr_cap(ia) == 10);
		IntAr_decRef(ia);
	}
}

Unit_declare(testGetSetPushPop) {
	Error_declare(err);

	{
		// Get returns correct element
		IntAr *ia = IntAr_new10();
		int i = IntAr_get(ia, 5, err);
		fatal(!Error_iserror(err));
		chk(i == 5);
		IntAr_decRef(ia);
	}

	{
		// Get gaurds < 0 index
		IntAr *ia = IntAr_new10();
		int i = IntAr_get(ia, -1, err);
		chk(Error_iserror(err));
		Error_clear(err);
		IntAr_decRef(ia);
	}

	{
		// Get gaurds > len 
		IntAr *ia = IntAr_new10();
		int i = IntAr_get(ia, 10, err);
		chk(Error_iserror(err));
		Error_clear(err);
		IntAr_decRef(ia);
	}

	{
		// Set works on correct element
		IntAr *ia = IntAr_new10();
		IntAr_set(ia, 5, 1005, err);
		fatal(!Error_iserror(err));
		chk(IntAr_at(ia, 5) == 1005);
		IntAr_decRef(ia);
	}

	{
		// Set guards negative index
		IntAr *ia = IntAr_new10();
		IntAr_set(ia, -1, 1005, err);
		chk(Error_iserror(err));
		Error_clear(err);
		IntAr_decRef(ia);
	}

	{
		// Set guards greater than length index
		IntAr *ia = IntAr_new10();
		IntAr_set(ia, 10, 1005, err);
		chk(Error_iserror(err));
		Error_clear(err);
		IntAr_decRef(ia);
	}

	{
		// popVal gets correct element
		IntAr *ia = IntAr_new10();
		for (int i = 0; i < 10; i++) {
			int i2 = IntAr_popVal(ia, err);
			fatal(!Error_iserror(err));
			chk(i == i2);
		}
		IntAr_decRef(ia);
	}

	{
		// popVal errors for no element
		IntAr *ia = IntAr_new();
		int i2 = IntAr_popVal(ia, err);
		chk(Error_iserror(err));
		Error_clear(err);
		IntAr_decRef(ia);
	}

	{
		// pop gets correct element
		IntAr *ia = IntAr_new10();
		for (int i = 0; i < 10; i++) {
			IntAr_pop(ia, err);
			fatal(!Error_iserror(err));
			chk(IntAr_len(ia) == 9 - i);
		}
		IntAr_decRef(ia);
	}

	{
		// pop errors for no element
		IntAr *ia = IntAr_new();
		IntAr_pop(ia, err);
		chk(Error_iserror(err));
		Error_clear(err);
		IntAr_decRef(ia);
	}

}

Unit_declare(testInsertRemove) {
	Error_declare(err);
	{
		// Insert element correctly
		IntAr *ia = IntAr_new10();
		IntAr_insert(ia, 9, 1005, err);
		fatal(!Error_iserror(ia));
		fatal(IntAr_len(ia) == 11);
		chk(IntAr_at(ia, 9) == 1005);
		IntAr_decRef(ia);
	}
	{
		// Insert guards negative index
		IntAr *ia = IntAr_new10();
		IntAr_insert(ia, -1, 1005, err);
		chk(Error_iserror(err));
		Error_clear(err);
		IntAr_decRef(ia);
	}
	{
		// Insert guards >= len index
		IntAr *ia = IntAr_new10();
		IntAr_insert(ia, 10, 1005, err);
		chk(Error_iserror(err));
		Error_clear(err);
		IntAr_decRef(ia);
	}
	{
		// Remove element correctly
		IntAr *ia = IntAr_new10();
		IntAr_remove(ia, 8, err);
		fatal(!Error_iserror(ia));
		fatal(IntAr_len(ia) == 9);
		chk(IntAr_at(ia, 8) == 9);
		IntAr_decRef(ia);	
	}
	{
		// Remove guards negative index
		IntAr *ia = IntAr_new10();
		IntAr_remove(ia, -1, err);
		chk(Error_iserror(err));
		Error_clear(err);
		IntAr_decRef(ia);
	}
	{
		// Remove guards >= len index
		IntAr *ia = IntAr_new10();
		IntAr_insert(ia, 10, err);
		chk(Error_iserror(err));
		Error_clear(err);
		IntAr_decRef(ia);
	}	
}

Unit_declare(testForeach) {
	{
		// foreach on value types works: var is a pointer to the underlying data
		IntAr *ia = IntAr_new10();
		int i = 0;
		IntAr_foreach(it, ia) {
			chk(*it.var == i);
			i++;
			*it.var = -it.index;
		}
		IntAr_foreach(it, ia) {
			chk(*it.var == -it.index);
		}
		IntAr_decRef(ia);
	}

	{
		// foreachOffset works correctly
		IntAr *ia = IntAr_new10();
		int i = 4;
		IntAr_foreachOffset(it, ia, i) {
			chk(it.var == i);
			i++;
		}
		IntAr_decRef(ia);
	}

	{
		// foreach can remove
		IntAr *ia = IntAr_new10();
		int i = 0;
		IntAr_foreach(it, ia) {
			if (it.index % 2 == 0) {
				it.remove = true;
			}
		}
		chk(IntAr_len(ia) == 5);
		IntAr_decRef(ia);
	}

	{
		// rforeach works correctly
		IntAr *ia = IntAr_new10();
		int i = 9;
		IntAr_rforeach(it, ia) {
			chk(*it.var == i);
			i--;
		}
		IntAr_decRef(ia);
	}

	{
		// rforeach can remove
		IntAr *ia = IntAr_new10();
		int i = 0;
		IntAr_rforeach(it, ia) {
			if (it.index % 2 == 0) {
				it.remove = true;
			}
		}
		chk(IntAr_len(ia) == 5);
		IntAr_decRef(ia);
	}

	{
		// foreach works correctly with reference type: it.var is a reference
		FooAr *fa = FooAr_new10();
		FooAr_foreach(it, fa) {
			chk(it.var->i == it.index);
		}
		
		FooAr_decRef(fa);
	}

	{
		// rforeach works correctly with reference type: it.var is a reference
		FooAr *fa = FooAr_new10();
		int i = 9;
		FooAr_rforeach(it, fa) {
			chk(it.var->i == i);
			i--;
		}
		FooAr_decRef(fa);
	}
}

Unit_declare(testSort) {
	{
		// Sort value type
		IntAr *ia = IntAr_new();
		for (int i = 9; i >= 0; i--) {
			IntAr_push(ia, i);
		}
		IntAr_sort(ia);
		fatal(IntAr_len(ia) == 10);
		for (int i = 0; i < 10; i++) {
			chk(i == IntAr_at(ia, i));
		}
		IntAr_decRef(ia);
	}
	{
		// Sort works for references
		FooAr *fa = FooAr_new10();
		FooAr_sortReverseI(fa);
		FooAr_foreach(it, fa) {
			chk(it.index == it.var->i);
		}
		FooAr_decRef(fa);
	}

	{
		// Alternative sorts
		FooAr *fa = FooAr_new25();
		FooAr_sort(fa);
		double last = -1;
		FooAr_foreach(it, fa) {
			chk(last <= it.var->d);
			last = it.var->d;
		}
		FooAr_decRef(fa);	
	}

}

Unit_declare(testBinSearch) {
	Error_declare(err);
	{
		// binSearch for value types
		IntAr *ia = IntAr_new10();
		IntAr_sort(ia);
		int v = IntAr_binSearch(ia, 5, err);
		fatal(!Error_iserror(err));
		chk(v == 5);
		IntAr_decRef(ia);
	}

	{
		// binSearch fails if key not present
		IntAr *ia = IntAr_new10();
		IntAr_sort(ia);
		int v = IntAr_binSearch(ia, 10, err);
		chk(Error_iserror(err));
		Error_clear(err):
		IntAr_decRef(ia);
	}

	{
		// binContains works correctly
		IntAr *ia = IntAr_new10();
		IntAr_sort(ia);
		chk(IntAr_binContains(ia, 5));
		chk(!IntAr_binContains(ia, 10));
		IntAr_decRef(ia);
	}

	{
		// binSearch for reference types
		FooAr *fa = FooAr_new10();
		FooAr_sort(fa);
		Foo *key = Foo_newBuild(5, 5.0);
		Foo *foo = FooAr_binSearch(fa, key, err);
		fatal(!Error_iserror(err));
		chk(foo->i == 5);
		FooAr_decRef(fa);
		Foo_decRef(key);
	}

	{
		// binSearch for reference types: error correctly
		FooAr *fa = FooAr_new10();
		FooAr_sort(fa);
		Foo *key = Foo_newBuild(10, 10.0);
		Foo *foo = FooAr_binSearch(fa, key, err);
		chk(foo == NULL);
		chk(Error_iserror(err));
		Error_clear(err);
		FooAr_decRef(fa);
		Foo_decRef(fa);
	}

	{
		// binSearch for reference types: alt sort function
		FooAr *fa = FooAr_new10();
		FooAr_sortReverseI(fa);
		Foo *key = Foo_newBuild(5, 5.0);
		Foo *foo = FooAr_binSearchReverseI(fa, key, err);
		fatal(!Error_iserror(err));
		chk(foo->i == 5);
		FooAr_decRef(key);
	}
}

Unit_declare(testBinInsert) {
	Error_declare(err);
	{
		// binInsert value works correctly
		IntAr *ia = IntAr_new();
		IntAr_binInsert(ia, 10);
		IntAr_binInsert(ia, 2);
		IntAr_binInsert(ia, 5);
		chk(IntAr_popVal(ia, err) == 2);
		fatal(!Error_iserror(err));
		chk(IntAr_popVal(ia, err) == 5);
		fatal(!Error_iserror(err));
		chk(IntAr_popVal(ia, err) == 10);
		fatal(!Error_iserror(err));
		IntAr_decRef(ia);
	}

	{
		// binInsert value can insert the same key
		IntAr *ia = IntAr_new();
		IntAr_binInsert(ia, 10);
		IntAr_binInsert(ia, 10);
		IntAr_binInsert(ia, 10);
		chk(IntAr_len(ia) == 1);
		chk(IntAr_popVal(ia, err) == 10);
		fatal(!Error_iserror(err));
		IntAr_decRef(ia);
	}

	{
		// binInsert reference works correctly
		FooAr *fa = FooAr_new();
		Foo *f1 = Foo_newBuild(10, 10.0);
		Foo *f2 = Foo_newBuild(2, 2.0);
		FooAr_binInsert(fa, f1);
		FooAr_binInsert(fa, f2);
		chk(FooAr_popVal(fa, err) == f2); // remember popVal does NOT decrement
		fatal(!Error_iserror(err));
		chk(FooAr_popVal(fa, err) == f1);
		fatal(!Error_iserror(err));
		FooAr_decRef(fa);
		Foo_decRef(f1); 
		Foo_decRef(f1);
		Foo_decRef(f2);
		Foo_decRef(f2);
	}

	{
		// binInsert reference can insert the same key
		FooAr *fa = FooAr_new();
		Foo *f1 = Foo_newBuild(10, 10.0);
		FooAr_binInsert(fa, f1);
		FooAr_binInsert(fa, f1);
		chk(FooAr_len(fa) == 1);
		chk(FooAr_popVal(fa, err) == f1);
		fatal(!Error_iserror(err));
		FooAr_decRef(fa);
		Foo_decRef(f1);
		Foo_decRef(f1);
	}

}

Unit_declare(testBinRemove) {
	Error_declare(err);
	{
		// binRemove correctly removes
		IntAr *ia = IntAr_new();
		IntAr_binInsert(ia, 10);
		IntAr_binInsert(ia, 2);
		IntAr_binRemove(ia, 2, err);
		fatal(!Error_iserror(err));
		chk(IntAr_len(ia) == 1);
		IntAr_decRef(ia);
	}

	{
		// binRemove errors correctly
		IntAr *ia = IntAr_new();
		IntAr_binInsert(ia, 10);
		IntAr_binInsert(ia, 2);
		IntAr_binRemove(ia, 4, err);
		chk(Error_iserror(err));
		Error_clear(err);
		chk(IntAr_len(ia) == 2);
		IntAr_decRef(ia);
	}

	{
		// binRemove correctly removes
		FooAr *fa = FooAr_new();
		Foo *f1 = Foo_newBuild(10, 10.0);
		Foo *f2 = Foo_newBuild(2, 2.0);
		FooAr_binInsert(fa, f1);
		FooAr_binInsert(fa, f2);
		FooAr_binRemove(fa, f1, err);
		fatal(!Error_iserror(err));
		chk(FooAr_len(fa) == 1);
		Foo_decRef(f1);
		Foo_decRef(f2);
		FooAr_decRef(fa);
	}
	
	{
		// binRemove errors correctly
		FooAr *ia = FooAr_new();
		Foo *f1 = Foo_newBuild(10, 10.0);
		Foo *f2 = Foo_newBuild(2, 2.0);
		Foo *key = Foo_newBuild(4, 4.0);
		FooAr_binInsert(fa, f1);
		FooAr_binInsert(fa, f2);
		FooAr_binRemove(fa, key, err);
		chk(Error_iserror(err));
		Error_clear(err);
		Foo_decRef(f1);
		Foo_decRef(f2);
		Foo_decRef(key);
		FooAr_decRef(fa);
	}
}

Unit_declare(testPq) 
{
	{
		// pqPush works correctly
		IntAr *ia = IntAr_new();
		IntAr_pqPush(ia, 10);
		IntAr_pqPush(ia, 2);
		IntAr_foreach(it, ia) {
			if (it.index == 0) {
				chk(*it.var == 2);
			} else {
				chk(*it.var == 10);
			}
		}
		IntAr_decRef(ia);
	}

	{
		// pqPop works correctly
		IntAr *ia = IntAr_new();
		IntAr_pqPush(ia, 10);
		IntAr_pqPush(ia, 2);

		IntAr_pqPop(ia, err);
		fatal(!Error_iserror(err));
		chk(IntAr_len(ia) == 2);

		IntAr_pqPop(ia, err);
		fatal(!Error_iserror(err));
		chk(IntAr_len(ia) == 1);

		IntAr_pqPop(ia, err);
		fatal(!Error_iserror(err));
		chk(IntAr_len(ia) == 0);
		IntAr_decRef(ia);
	}

	{
		// pqPopVal works correctly
		IntAr *ia = IntAr_new();
		IntAr_pqPush(ia, 10);
		IntAr_pqPush(ia, 2);
		int v = IntAr_pqPopVal(ia, err);
		fatal(!Error_iserror(err));
		chk(v == 2);
		v = IntAr_pqPopVal(ia, err);
		fatal(!Error_iserror(err));
		chk(v == 10);
		IntAr_decRef(ia);
	}
	{
		// pqPopVal errors correctly
		IntAr *ia = IntAr_new();
		int v = IntAr_pqPopVal(ia, err);
		chk(Error_iserror(err));
		Error_clear(err);
		IntAr_decRef(ia);
	}
	{
		// pqSort works correctly
		IntAr *ia = IntAr_new();
		IntAr_push(ia, 5);
		IntAr_push(ia, 10);
		IntAr_push(ia, 2);
		IntAr_pqSort(ia);
		int v = IntAr_pqPopVal(ia, err);
		fatal(!Error_iserror(err));
		chk(v == 2);
		v = IntAr_pqPopVal(ia, err);
		fatal(!Error_iserror(err));
		chk(v == 5);
		v = IntAr_pqPopVal(ia, err);
		fatal(!Error_iserror(err));
		chk(v == 10);
		IntAr_decRef(ia);
	}

	{
		// pqPeek returns value that is at the top of heap, and sets passed bool to true
		IntAr *ia = IntAr_new();
		IntAr_push(ia, 7);
		bool q = false;
		int v = IntAr_pqPeek(ia, &q);
		chk(q);
		chk(v == 7);
		IntAr_decRef(ia);
	}

	{
		// pqPeek returns zero and sets q to false if pq is empty.
		IntAr *ia = IntAr_new();
		bool q = true;
		int v = IntAr_pqPeek(ia, &q);
		chk(q);
		chk(v == 7);
		IntAr_decRef(ia);
	}

	{
		// pqPush works correctly
		FooAr *fa = FooAr_new();
		Foo *f1 = Foo_newBuild(10, 10.0);
		Foo *f2 = Foo_newBuild(2, 2.0);
		FooAr_pqPush(fa, f1);
		FooAr_pqPush(fa, f2);
		FooAr_foreach(it, fa) {
			if (it.index == 0) {
				chk(it.var == f2);
			} else {
				chk(*it.var == f1);
			}
		}
		FooAr_decRef(fa);
		Foo_decRef(f1);
		Foo_decRef(f2);
	}

	{
		// pqPop works correctly
		FooAr *ia = FooAr_new();
		Foo *f1 = Foo_newBuild(10, 10.0);
		Foo *f2 = Foo_newBuild(2, 2.0);
		FooAr_pqPush(fa, f1);
		FooAr_pqPush(fa, f2);
		Foo *v = FooAr_pqPopVal(fa, err);
		Foo_decRef(v);
		fatal(!Error_iserror(err));
		chk(v == f2);
		v = FooAr_pqPopVal(ia, err);
		Foo_decRef(v);
		fatal(!Error_iserror(err));
		chk(v == f1);
		FooAr_decRef(ia);
		Foo_decRef(f1);
		Foo_decRef(f2);
	}
	{
		// pqPop errors correctly
		FooAr *fa = FooAr_new();
		Foo *v = FooAr_pqPopVal(fa, err);
		chk(Error_iserror(err));
		chk(v == NULL);
		Error_clear(err);
		FooAr_decRef(fa);
	}
	{
		// pqSort works correctly
		FooAr *fa = FooAr_new();
		Foo *f1 = Foo_newBuild(5, 5.0);
		Foo *f2 = Foo_newBuild(10, 10.0);
		Foo *f3 = Foo_newBuild(2, 2.0);
		FooAr_push(fa, f1);
		FooAr_push(fa, f2);
		FooAr_push(fa, f3);
		FooAr_pqSort(fa);
		Foo *v = FooAr_pqPopVal(ia, err);
		Foo_decRef(v);
		fatal(!Error_iserror(err));
		chk(v == f3);
		v = FooAr_pqPopVal(ia, err);
		Foo_decRef(v);
		fatal(!Error_iserror(err));
		chk(v == f1);
		v = FooAr_pqPop(ia, err);
		Foo_decRef(v);
		fatal(!Error_iserror(err));
		chk(v == f2);
		FooAr_decRef(fa);
		Foo_decRef(f1);
		Foo_decRef(f2);
		Foo_decRef(f3);
	}

	{
		// pqPeek returns value that is at the top of heap, and sets passed bool to true
		FooAr *fa = FooAr_new();
		Foo *f1 = Foo_newBuild(7, 7.0);
		FooAr_push(ia, f1);
		bool q = false;
		chk(FooAr_pqPeek(fa, &q) == f1);
		chk(q);
		FooAr_decRef(fa);
		Foo_decRef(f1);
	}

	{
		// pqPeek returns zero and sets q to false if pq is empty.
		FooAr *fa = FooAr_new();
		bool q = true;
		chk(FooAr_pqPeek(fa, &q) == NULL);
		chk(q);
		FooAr_decRef(fa);
	}
}

int main(int argc, char *argv[]) {
	Unit_initialize(argc, argv);
	Unit_test(testNewFree);
	Unit_test(testLen);
	Unit_test(testGetSetPushPop);
	Unit_test(testInsertRemove);
	Unit_test(testForeach);
	Unit_test(testSort);
	Unit_test(testBinSearch);
	Unit_test(testPq);
	Unit_finalize();
}
