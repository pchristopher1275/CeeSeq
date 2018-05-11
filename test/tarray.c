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
		FooAr *fa = FooAr_new();
		chk(fa != NULL);
		FooAr_decRef(fa);
	}
}

Unit_declare(testLen) {
	{
		// Array starts with zero length
		FooAr *fa = FooAr_new();
		chk(FooAr_len(fa) == 0);
		FooAr_decRef(fa);
	}
	{
		// Array keeps track of length on push
		FooAr *fa = FooAr_new10();
		chk(FooAr_len(fa) == 10);
		FooAr_decRef(fa);
	}
	{
		// Array keeps track of length on pop
		Error_declare(err);
		FooAr *fa = FooAr_new10();
		FooAr_popDecRef(fa, err);
		fatal(!Error_iserror(err));
		chk(FooAr_len(fa) == 9);
		FooAr_decRef(fa);
	}

	{
		// Truncate changes length
		FooAr *fa = FooAr_new10();
		FooAr_truncate(fa, 5);
		chk(FooAr_len(arr) == 5);
		FooAr_decRef(fa);
	}

	{
		// Truncate does not increase size
		FooAr *fa = FooAr_new10();
		FooAr_truncate(fa, 50);
		chk(FooAr_len(arr) == 10);
		FooAr_decRef(fa);
	}

	{
		// Fit sets cap to length
		FooAr *fa = FooAr_new10();
		chk(FooAr_cap(fa) > 10);
		FooAr_fit(fa);
		chk(FooAr_cap(fa) == 10);
		FooAr_decRef(fa);
	}
}

Unit_declare(testGetSetPushPop) {
	Error_declare(err);

	{
		// Get returns correct element
		FooAr *fa = FooAr_new10();
		Foo *f = FooAr_get(fa, 5, err);
		fatal(!Error_iserror(err));
		chk(f->i == 5);
		FooAr_decRef(fa);
	}

	{
		// Get gaurds < 0 index
		FooAr *fa = FooAr_new10();
		Foo *f = FooAr_get(fa, -1, err);
		chk(Error_iserror(err));
		Error_clear(err);
		FooAr_decRef(fa);
	}

	{
		// Get gaurds >= len 
		FooAr *fa = FooAr_new10();
		Foo *f = FooAr_get(fa, 10, err);
		chk(Error_iserror(err));
		Error_clear(err);
		FooAr_decRef(fa);
	}

	{
		// Set works on correct element
		FooAr *fa = FooAr_new10();
		FooAr_set(fa, 5, Foo_newBuild(1005, 10005), err);
		fatal(!Error_iserror(err));
		chk(FooAr_at(fa, 5)->i == 1005);
		FooAr_decRef(fa);
	}

	{
		// Set guards negative index
		FooAr *fa = FooAr_new10();
		FooAr_set(fa, -1, 1005, err);
		chk(Error_iserror(err));
		Error_clear(err);
		FooAr_decRef(fa);
	}

	{
		// Set guards greater than length index
		FooAr *fa = FooAr_new10();
		FooAr_set(fa, 10, 1005, err);
		chk(Error_iserror(err));
		Error_clear(err);
		FooAr_decRef(fa);
	}

	{
		// pop gets correct element
		FooAr *fa = FooAr_new10();
		for (int i = 0; i < 10; i++) {
			Foo *f = FooAr_pop(fa, err);
			fatal(!Error_iserror(err));
			chk(f->i == i);
		}
		FooAr_decRef(fa);
	}

	{
		// pop errors for no element
		FooAr *fa = FooAr_new();
		Foo *f = FooAr_pop(fa, err);
		chk(Error_iserror(err));
		Error_clear(err);
		FooAr_decRef(fa);
	}

	{
		// popDecRef gets correct element
		FooAr *fa = FooAr_new10();
		for (Foo *f = 0; i < 10; i++) {
			FooAr_popDecRef(fa, err);
			fatal(!Error_iserror(err));
			chk(FooAr_len(fa) == 9 - i);
		}
		FooAr_decRef(fa);
	}

	{
		// pop errors for no element
		FooAr *fa = FooAr_new();
		FooAr_pop(fa, err);
		chk(Error_iserror(err));
		Error_clear(err);
		FooAr_decRef(fa);
	}

}

Unit_declare(testInsertRemove) {
	Error_declare(err);
	{
		// Insert element correctly
		FooAr *fa = FooAr_new10();
		FooAr_insert(fa, 9, FooAr_newBuild(1005, 0), err);
		fatal(!Error_iserror(fa));
		fatal(FooAr_len(fa) == 11);
		chk(FooAr_at(fa, 9)->i == 1005);
		FooAr_decRef(fa);
	}
	{
		// Insert guards negative index
		FooAr *fa = FooAr_new10();
		Foo *f = Foo_newBuild(0,0);
		FooAr_insert(fa, -1, f, err);
		chk(Error_iserror(err));
		Error_clear(err);
		FooAr_decRef(fa);
		Foo_decRef(f);
	}
	{
		// Insert guards >= len index
		FooAr *fa = FooAr_new10();
		Foo *f = Foo_newBuild(0,0);
		FooAr_insert(fa, 10, f, err);
		chk(Error_iserror(err));
		Error_clear(err);
		FooAr_decRef(fa);
		Foo_decRef(f);
	}
	{
		// Remove element correctly
		FooAr *fa = FooAr_new10();
		FooAr_remove(fa, 8, err);
		fatal(!Error_iserror(fa));
		fatal(FooAr_len(fa) == 9);
		chk(FooAr_at(fa, 8) == 9);
		FooAr_decRef(fa);	
	}
	{
		// Remove guards negative index
		FooAr *fa = FooAr_new10();
		FooAr_remove(fa, -1, err);
		chk(Error_iserror(err));
		Error_clear(err);
		FooAr_decRef(fa);
	}
	{
		// Remove guards >= len index
		FooAr *fa = FooAr_new10();
		FooAr_insert(fa, 10, err);
		chk(Error_iserror(err));
		Error_clear(err);
		FooAr_decRef(fa);
	}	
}

Unit_declare(testForeach) {
	{
		// foreach works
		FooAr *fa = FooAr_new10();
		int i = 0;
		FooAr_foreach(it, fa) {
			chk(*it.var->i == i);
			i++;
		}
		FooAr_decRef(fa);
	}

	{
		// foreachOffset works correctly
		FooAr *fa = FooAr_new10();
		int i = 4;
		FooAr_foreachOffset(it, fa, i) {
			chk(it.var->i == i);
			i++;
		}
		FooAr_decRef(fa);
	}

	{
		// foreach can remove
		FooAr *fa = FooAr_new10();
		int i = 0;
		FooAr_foreach(it, fa) {
			if (it.index % 2 == 0) {
				it.remove = true;
			}
		}
		chk(FooAr_len(fa) == 5);
		FooAr_decRef(fa);
	}

	{
		// rforeach works correctly
		FooAr *fa = FooAr_new10();
		int i = 9;
		FooAr_rforeach(it, fa) {
			chk(it.var->i == i);
			i--;
		}
		FooAr_decRef(fa);
	}

	{
		// rforeach can remove
		FooAr *fa = FooAr_new10();
		FooAr_rforeach(it, fa) {
			if (it.index % 2 == 0) {
				it.remove = true;
			}
		}
		chk(FooAr_len(fa) == 5);
		FooAr_decRef(fa);
	}
}

Unit_declare(testSort) {
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
		// binSearch fails if key not present
		FooAr *fa = FooAr_new10();
		FooAr_sort(fa);
		Foo *key = Foo_newBuild(10, 10);
		Foo *f = FooAr_binSearch(fa, 10, err);
		chk(Error_iserror(err));
		Error_clear(err):
		FooAr_decRef(fa);
		Foo_decRef(key);
	}

	{
		// binContains works correctly
		FooAr *fa = FooAr_new10();
		FooAr_sortReverseI(fa);
		Foo *key1 = Foo_newBuild(5, 5);
		Foo *key2 = Foo_newBuild(10, 10);
		chk(FooAr_binContainsReverseI(fa, key1));
		chk(!FooAr_binContainsReverseI(fa, key2));
		FooAr_decRef(fa);
		Foo_decRef(key1);
		Foo_decRef(key2);
	}
}

Unit_declare(testBinInsert) {
	Error_declare(err);
	{
		// binInsert works correctly
		FooAr *fa = FooAr_new();
		Foo *f1 = Foo_newBuild(10, 10.0);
		Foo *f2 = Foo_newBuild(2, 2.0);
		FooAr_binInsert(fa, f1);
		FooAr_binInsert(fa, f2);
		chk(FooAr_pop(fa, err) == f2); 
		fatal(!Error_iserror(err));
		chk(FooAr_pop(fa, err) == f1);
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
		chk(FooAr_pop(fa, err) == f1);
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
		FooAr *fa = FooAr_new();
		Foo *f1 = Foo_newBuild(10, 10.0);
		Foo *f2 = Foo_newBuild(2, 2.0);
		Foo *f3 = Foo_newBuild(10, 10.0);
		FooAr_binInsert(fa, f1);
		FooAr_binInsert(fa, f2);
		FooAr_binRemove(fa, f3, err);
		fatal(!Error_iserror(err));
		chk(FooAr_len(fa) == 1);
		Foo_decRef(f1);
		Foo_decRef(f2);
		Foo_decRef(f3);
		FooAr_decRef(fa);
	}
	
	{
		// binRemove errors correctly
		FooAr *fa = FooAr_new();
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
	// {
	// 	// pqPush works correctly
	// 	FooAr *fa = FooAr_new();
	// 	FooAr_pqPush(fa, 10);
	// 	FooAr_pqPush(fa, 2);
	// 	FooAr_foreach(it, fa) {
	// 		if (it.index == 0) {
	// 			chk(*it.var == 2);
	// 		} else {
	// 			chk(*it.var == 10);
	// 		}
	// 	}
	// 	FooAr_decRef(fa);
	// }

	// {
	// 	// pqPop works correctly
	// 	FooAr *fa = FooAr_new();
	// 	FooAr_pqPush(fa, 10);
	// 	FooAr_pqPush(fa, 2);

	// 	FooAr_pqPop(fa, err);
	// 	fatal(!Error_iserror(err));
	// 	chk(FooAr_len(fa) == 2);

	// 	FooAr_pqPop(fa, err);
	// 	fatal(!Error_iserror(err));
	// 	chk(FooAr_len(fa) == 1);

	// 	FooAr_pqPop(fa, err);
	// 	fatal(!Error_iserror(err));
	// 	chk(FooAr_len(fa) == 0);
	// 	FooAr_decRef(fa);
	// }

	// {
	// 	// pqPopVal works correctly
	// 	FooAr *fa = FooAr_new();
	// 	FooAr_pqPush(fa, 10);
	// 	FooAr_pqPush(fa, 2);
	// 	int v = FooAr_pqPopVal(fa, err);
	// 	fatal(!Error_iserror(err));
	// 	chk(v == 2);
	// 	v = FooAr_pqPopVal(fa, err);
	// 	fatal(!Error_iserror(err));
	// 	chk(v == 10);
	// 	FooAr_decRef(fa);
	// }
	// {
	// 	// pqPopVal errors correctly
	// 	FooAr *fa = FooAr_new();
	// 	int v = FooAr_pqPopVal(fa, err);
	// 	chk(Error_iserror(err));
	// 	Error_clear(err);
	// 	FooAr_decRef(fa);
	// }
	// {
	// 	// pqSort works correctly
	// 	FooAr *fa = FooAr_new();
	// 	FooAr_push(fa, 5);
	// 	FooAr_push(fa, 10);
	// 	FooAr_push(fa, 2);
	// 	FooAr_pqSort(fa);
	// 	int v = FooAr_pqPopVal(fa, err);
	// 	fatal(!Error_iserror(err));
	// 	chk(v == 2);
	// 	v = FooAr_pqPopVal(fa, err);
	// 	fatal(!Error_iserror(err));
	// 	chk(v == 5);
	// 	v = FooAr_pqPopVal(fa, err);
	// 	fatal(!Error_iserror(err));
	// 	chk(v == 10);
	// 	FooAr_decRef(fa);
	// }

	// {
	// 	// pqPeek returns value that is at the top of heap, and sets passed bool to true
	// 	FooAr *fa = FooAr_new();
	// 	FooAr_push(fa, 7);
	// 	bool q = false;
	// 	int v = FooAr_pqPeek(fa, &q);
	// 	chk(q);
	// 	chk(v == 7);
	// 	FooAr_decRef(fa);
	// }

	// {
	// 	// pqPeek returns zero and sets q to false if pq is empty.
	// 	FooAr *fa = FooAr_new();
	// 	bool q = true;
	// 	int v = FooAr_pqPeek(fa, &q);
	// 	chk(q);
	// 	chk(v == 7);
	// 	FooAr_decRef(fa);
	// }



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
				chk(it.var == f1);
			}
		}
		FooAr_decRef(fa);
		Foo_decRef(f1);
		Foo_decRef(f2);
	}

	{
		// pqPop works correctly
		FooAr *fa = FooAr_new();
		Foo *f1 = Foo_newBuild(10, 10.0);
		Foo *f2 = Foo_newBuild(2, 2.0);
		FooAr_pqPush(fa, f1);
		FooAr_pqPush(fa, f2);
		Foo *v = FooAr_pqPop(fa, err);
		fatal(!Error_iserror(err));
		Foo_decRef(v);
		chk(v == f2);

		v = FooAr_pqPopVal(fa, err);
		fatal(!Error_iserror(err));
		Foo_decRef(v);
		chk(v == f1);

		FooAr_decRef(fa);
		Foo_decRef(f1);
		Foo_decRef(f2);
	}
	{
		// pqPop errors correctly
		FooAr *fa = FooAr_new();
		Foo *v = FooAr_pqPop(fa, err);
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
		Foo *v = FooAr_pqPop(fa, err);
		fatal(!Error_iserror(err));
		Foo_decRef(v);
		chk(v == f3);

		v = FooAr_pqPopVal(fa, err);		
		fatal(!Error_iserror(err));
		chk(v == f1);
		Foo_decRef(v);

		v = FooAr_pqPop(fa, err);		
		fatal(!Error_iserror(err));
		chk(v == f2);
		Foo_decRef(v);
		
		FooAr_decRef(fa);
		Foo_decRef(f1);
		Foo_decRef(f2);
		Foo_decRef(f3);
	}

	{
		// pqPeek returns value that is at the top of heap, and sets passed bool to true
		FooAr *fa = FooAr_new();
		Foo *f1 = Foo_newBuild(7, 7.0);
		FooAr_push(fa, f1);
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
	Unit_initfalize(argc, argv);
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
