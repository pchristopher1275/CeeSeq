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



#define Array_cap(arr) ((Array*)arr)->cap

Unit_declare(testNewFree) {
	IntAr *ia = IntAr_new(0);
	chk(ia != NULL);
	IntAr_free(ia);

	FooAr *fa = FooAr_new(10);
	chk(fa != NULL);
	FooAr_free(fa);
}

Unit_declare(testLenInitClear) {
	
	{
		IntAr ia = {0};
		IntAr_init(&ia, 10);
		chk(IntAr_len(&ia) == 10);
		chk(Array_cap(&ia) >= 10);
		IntAr_clear(&ia);
		chk(Array_cap(&ia) == 0);
	}
	{
		FooAr fa = {0};
		FooAr_init(&fa, 5);
		chk(FooAr_len(&fa) == 5);
		chk(Array_cap(&fa) >= 5);
		FooAr_clear(&fa);
		chk(Array_cap(&fa) == 0);
	}
}

Unit_declare(testInitSurvivesNegativeInit) {
	{
		IntAr *ia = IntAr_new(-100);
		chk(IntAr_len(ia) == 0);
		chk(((Array*)ia)->cap == 0);
		chk(((Array*)ia)->data == NULL);
		IntAr_free(ia);
	}

	{
		FooAr *fa = FooAr_new(-10);
		chk(FooAr_len(fa) == 0);
		chk(((Array*)fa)->cap == 0);
		chk(((Array*)fa)->data == NULL);
		FooAr_free(fa);
	}
}

Unit_declare(testTruncateClearerAndFit) {
	{
		IntAr *arr = IntAr_new(10);
		chk(IntAr_len(arr) == 10);
		chk(((Array*)arr)->cap == 10);
		IntAr_truncate(arr);
		chk(IntAr_len(arr) == 0);
		chk(((Array*)arr)->cap == 10);
		IntAr_free(arr);
	}

	{
		Error_declare(err);
		IntAr *arr = IntAr_new(0);
		for (int i = 0; i < 5; i++) {
			IntAr_push(arr, i);
		}
		
		chk(IntAr_len(arr) == 5);
		chk(((Array*)arr)->cap >= 5);
		IntAr_pop(arr, err);
		fatal(!Error_iserror(err));

		IntAr_pop(arr, err);
		fatal(!Error_iserror(err));
		chk(IntAr_len(arr) == 3);
		chk(((Array*)arr)->cap >= 5);

		IntAr_fit(arr);
		chk(IntAr_len(arr) == 3);
		chk(((Array*)arr)->cap == 3);
		for (int i = 0; i < 3; i++) {
			int k = IntAr_get(arr, i, err);
			fatal(!Error_iserror(err));
			chk(k == i);
		}
	}

	{
		Error_declare(err);
		FooAr *arr = FooAr_new(5);
		chk(FooAr_len(arr) == 5);
		chk(((Array*)arr)->cap == 5);
		FooAr_pop(arr, err);
		fatal(!Error_iserror(err));
		FooAr_pop(arr, err);
		fatal(!Error_iserror(err));
		chk(FooAr_len(arr) == 3);
		chk(((Array*)arr)->cap == 5);
		FooAr_fit(arr);
		chk(FooAr_len(arr) == 3);
		chk(((Array*)arr)->cap == 3);
	}


	{
		Error_declare(err);
		Foo_zeroRecord();
		FooAr *arr = FooAr_new(0);
		for (int i = 0; i < 5; i++) {
			Foo foo = {i, 2*i};
			FooAr_push(arr, foo);	
		}
		chk(FooAr_len(arr) == 5);
		chk(((Array*)arr)->cap >= 5);
		chk(numRecorded == 0);
		FooAr_truncate(arr);
		chk(numRecorded == 5);
		for (int i = 0; i < numRecorded; i++) {
			Foo foo = recorded[i];
			chk(foo.i == i);
			chk(foo.d == (double)2*i);
		}

		chk(FooAr_len(arr) == 0);
		chk(((Array*)arr)->cap >= 5);
		FooAr_fit(arr);
		chk(FooAr_len(arr) == 0);
		chk(((Array*)arr)->cap == 0);
		chk(((Array*)arr)->data == NULL);
		
		for (int i = 0; i < 5; i++) {
			Foo foo = {i, 4*i};
			FooAr_push(arr, foo);	
		}
		chk(FooAr_len(arr) == 5);
		chk(((Array*)arr)->cap > 5);
		FooAr_fit(arr);
		chk(FooAr_len(arr) == 5);
		chk(((Array*)arr)->cap == 5);
		for (int i = 0; i < 5; i++) {
			Foo foo = FooAr_get(arr, i, err);
			fatal(!Error_iserror(err));
			chk(foo.i == i);
			chk(foo.d == (double)4*i);
		}
		FooAr_free(arr);
	}
}

Unit_declare(testChangeLength) 
{
	{
		IntAr *arr = IntAr_new(0);
		IntAr_changeLength(arr, 10);
		chk(IntAr_len(arr) == 10);
		IntAr_changeLength(arr, 100);
		chk(IntAr_len(arr) == 100);
		IntAr_changeLength(arr, 2);
		chk(IntAr_len(arr) == 2);
		IntAr_free(arr);
	}

	{
		Foo_zeroRecord();
		FooAr *arr = FooAr_new(0);
		FooAr_changeLength(arr, 5);
		chk(FooAr_len(arr) == 5);
		chk(((Array*)arr)->cap >= 5);
		chk(numRecorded == 0);
		FooAr_changeLength(arr, 3);
		chk(numRecorded == 2);
		for (int i = 0; i < numRecorded; i++) {
			Foo foo = recorded[i];
			chk(foo.i == 0);
			chk(foo.d == (double)0);
		}

		FooAr_changeLength(arr, 100);
		chk(FooAr_len(arr) == 100);
		chk(((Array*)arr)->cap >= 100);
		FooAr_changeLength(arr, 2);
		chk(FooAr_len(arr) == 2);
		chk(((Array*)arr)->cap >= 100);
		FooAr_free(arr);	
	}
}

Unit_declare(testPushAndGet) {
	// Test IntAr for push 10 and get 10
	{
		IntAr *arr1 = IntAr_new(0);
		IntAr *arr2 = IntAr_new(0);
		for (int i = 0; i < 10; i++) {
			int k = i;
			IntAr_push(arr1, 2*i);	
			IntAr_pushp(arr2, &k);
		}
		chk(IntAr_len(arr1) == 10);
		chk(IntAr_len(arr2) == 10);
		Error_declare(err);


		for (int i = 9; i >= 0; i--){
			int *k = IntAr_getp(arr1, i, err);
			fatal(!Error_iserror(err));
			chk(*k == 2*i);
			k = IntAr_getp(arr2, i, err);
			chk(*k == i);
			fatal(!Error_iserror(err));
		}

		for (int i = 9; i >= 0; i--){
			chk(IntAr_get(arr1, i, err) == 2*i);
			fatal(!Error_iserror(err));
			chk(IntAr_get(arr2, i, err) == i);
			fatal(!Error_iserror(err));
		}

		IntAr_free(arr1);
		IntAr_free(arr2);
	}

	// Test that FooAr pushs 10, and then get 10
	{
		FooAr *arr1 = FooAr_new(0);
		FooAr *arr2 = FooAr_new(0);
		for (int i = 0; i < 10; i++) {
			Foo x = {2*i, 1.23};
			FooAr_push(arr1, x);	
			Foo y = {i, 4.56};
			FooAr_pushp(arr2, &y);
		}
		chk(FooAr_len(arr1) == 10);
		chk(FooAr_len(arr2) == 10);
		Error_declare(err);

		for (int i = 9; i >= 0; i--){
			Foo *x = FooAr_getp(arr1, i, err);
			fatal(!Error_iserror(err));
			chk(x->i == 2*i);
			chk(x->d == 1.23);
			Foo *y = FooAr_getp(arr2, i, err);
			chk(y->i == i);
			chk(y->d == 4.56);
			fatal(!Error_iserror(err));
		}

		for (int i = 9; i >= 0; i--){
			Foo xe = {2*i, 1.23};	
			Foo xg = FooAr_get(arr1, i, err);
			chk(xg.i == xe.i);
			chk(xg.d == xe.d);
			Foo ye = {i, 4.56};
			Foo yg = FooAr_get(arr2, i, err);
			fatal(!Error_iserror(err));
			chk(yg.i == ye.i);
			chk(yg.d == ye.d);
		}

		FooAr_free(arr1);
		FooAr_free(arr2);
	}

	// Test push onto existing array
	{
		Error_declare(err);
		IntAr *arr1 = IntAr_new(5);
		for (int i = 0; i < 5; i++) {
			chk(IntAr_get(arr1, i, err) == 0);
			fatal(!Error_iserror(err));
		}
		for (int i = 0; i < 5; i++) {
			IntAr_push(arr1, i+5);
		}
		for (int i = 0; i < 10; i++) {
			int e = i < 5 ? 0 : (i-5)+5;
			chk(IntAr_get(arr1, i, err) == e);
			fatal(!Error_iserror(err));	
		}
		IntAr_free(arr1);
	}

	// Test bad index
	{
		Error_declare(err);
		FooAr *arr1 = FooAr_new(0);
		Foo x = FooAr_get(arr1, 1, err);
		fatal(Error_iserror(err));
		chk(strstr(Error_message(err), "Index out of range (1, 0, 0)") != NULL);
		chk(x.i == 0);
		chk(x.d == 0.0);
		Error_clear(err);

		x = FooAr_get(arr1, -100, err);
		fatal(Error_iserror(err));
		chk(strstr(Error_message(err), "Index out of range (-100, 0, 0)") != NULL);
		chk(x.i == 0);
		chk(x.d == 0.0);
		Error_clear(err);
	}

}

Unit_declare(testPushAndPop) {
	{
		Error_declare(err);
		IntAr *arr1 = IntAr_new(0);
		for (int i = 0; i < 10; i++) {
			chk(IntAr_len(arr1) == i);
			IntAr_push(arr1, i);
		}
		for (int i = 9; i >= 0; i--) {
			chk(IntAr_len(arr1) == i+1);	
			IntAr_pop(arr1, err);	
			fatalm(!Error_iserror(err), Error_message(err));
		}
		IntAr_free(arr1);
	}

	{
		Error_declare(err);
		FooAr *arr1 = FooAr_new(10);
		for (int i = 9; i >= 0; i--) {
			chk(FooAr_len(arr1) == i+1);	
			FooAr_pop(arr1, err);	
			fatalm(!Error_iserror(err), Error_message(err));
		}
		FooAr_free(arr1);
	}

	{
		Error_declare(err);
		IntAr *arr1 = IntAr_new(0);
		IntAr_pop(arr1, err);	
		fatal(Error_iserror(err));
		chk(strstr(Error_message(err), "Index out of range") != NULL);
	}
}

Unit_declare(testSet) {
	{
		Error_declare(err);
		IntAr *arr1 = IntAr_new(3);
		IntAr_set(arr1, 0, 14, err);
		fatal(!Error_iserror(err));

		int k = 15;
		IntAr_setp(arr1, 1, &k, err);
		fatal(!Error_iserror(err));

		k = 16;
		IntAr_setp(arr1, 2, &k, err);
		fatal(!Error_iserror(err));

		chk(IntAr_get(arr1, 0, err) == 14);
		fatal(!Error_iserror(err));

		chk(IntAr_get(arr1, 1, err) == 15);
		fatal(!Error_iserror(err));

		chk(IntAr_get(arr1, 2, err) == 16);
		fatal(!Error_iserror(err));		
		
		IntAr_free(arr1);
	}

	{
		Error_declare(err);
		FooAr *arr1 = FooAr_new(3);
		Foo foo = {0};
		foo.i = 14;
		foo.d = 1.23;
		FooAr_set(arr1, 0, foo, err);
		fatal(!Error_iserror(err));

		foo.i = 15;
		foo.d = 4.56;
		FooAr_setp(arr1, 1, &foo, err);
		fatal(!Error_iserror(err));

		foo.i = 16;
		foo.d = 7.89;
		FooAr_set(arr1, 2, foo, err);
		fatal(!Error_iserror(err));

		foo = FooAr_get(arr1, 0, err);
		fatal(!Error_iserror(err));
		chk(foo.i == 14);
		chk(foo.d == 1.23);

		foo = FooAr_get(arr1, 1, err);
		fatal(!Error_iserror(err));
		chk(foo.i == 15);
		chk(foo.d == 4.56);
		
		foo = FooAr_get(arr1, 2, err);
		fatal(!Error_iserror(err));
		chk(foo.i == 16);
		chk(foo.d == 7.89);

		FooAr_free(arr1);
	}

	{
		Error_declare(err);
		FooAr *arr1 = FooAr_new(3);
		Foo foo = {0};
		FooAr_setp(arr1, 100, &foo, err);
		fatal(Error_iserror(err));

		FooAr_setp(arr1, -100, &foo, err);
		fatal(Error_iserror(err));

		FooAr_free(arr1);
	}
}

Unit_declare(testInsert) {
	{
		Error_declare(err);
		IntAr *arr1 = IntAr_new(3);

		IntAr_insert(arr1, 0, 1, err);
		fatal(!Error_iserror(err));

		int k = 2;
		IntAr_insertp(arr1, 2, &k, err);
		fatal(!Error_iserror(err));

		k = 3;
		IntAr_insertp(arr1, 4, &k, err);
		fatal(!Error_iserror(err));

		// Insert at last index
		IntAr_insert(arr1, IntAr_len(arr1), 111, err);
		fatal(!Error_iserror(err));

		chk(IntAr_get(arr1, 0, err) == 1);
		fatal(!Error_iserror(err));

		chk(IntAr_get(arr1, 1, err) == 0);
		fatal(!Error_iserror(err));

		chk(IntAr_get(arr1, 2, err) == 2);
		fatal(!Error_iserror(err));

		chk(IntAr_get(arr1, 3, err) == 0);
		fatal(!Error_iserror(err));

		chk(IntAr_get(arr1, 4, err) == 3);
		fatal(!Error_iserror(err));

		chk(IntAr_get(arr1, 5, err) == 0);
		fatal(!Error_iserror(err));
		
		chk(IntAr_get(arr1, IntAr_last(arr1), err) == 111);
		fatal(!Error_iserror(err));

		IntAr_free(arr1);
	}

	{
		Error_declare(err);
		FooAr *arr1 = FooAr_new(3);

		Foo foo = {0};
		foo.i = 1;
		foo.d = 1.0;
		FooAr_insert(arr1, 0, foo, err);
		fatal(!Error_iserror(err));

		foo.i = 2;
		foo.d = 2.0;
		FooAr_insertp(arr1, 2, &foo, err);
		fatal(!Error_iserror(err));

		foo.i = 3;
		foo.d = 3.0;
		FooAr_insertp(arr1, 4, &foo, err);
		fatal(!Error_iserror(err));


		foo.i = 111;
		foo.d = 111.0;
		FooAr_insertp(arr1, FooAr_len(arr1), &foo, err);
		fatal(!Error_iserror(err));


		foo = FooAr_get(arr1, 0, err);
		fatal(!Error_iserror(err));
		chk(foo.i == 1);
		chk(foo.d == 1.0);
		
		foo = FooAr_get(arr1, 1, err);
		fatal(!Error_iserror(err));
		chk(foo.i == 0);
		chk(foo.d == 0.0);

		foo = FooAr_get(arr1, 2, err);
		fatal(!Error_iserror(err));
		chk(foo.i == 2);
		chk(foo.d == 2.0);

		foo = FooAr_get(arr1, 3, err);
		fatal(!Error_iserror(err));
		chk(foo.i == 0);
		chk(foo.d == 0.0);

		foo = FooAr_get(arr1, 4, err);
		fatal(!Error_iserror(err));
		chk(foo.i == 3);
		chk(foo.d == 3.0);

		foo = FooAr_get(arr1, 5, err);
		fatal(!Error_iserror(err));
		chk(foo.i == 0);
		chk(foo.d == 0.0);
		
		foo = FooAr_get(arr1, FooAr_last(arr1), err);
		fatal(!Error_iserror(err));
		chk(foo.i == 111);
		chk(foo.d == 111.0);


		FooAr_free(arr1);
	}

	{
		Error_declare(err);
		FooAr *arr1 = FooAr_new(3);
		Foo foo = {0};

		FooAr_insert(arr1, 100, foo, err);
		fatal(Error_iserror(err));
		chk(strstr(Error_message(err), "Index out of range") != NULL);

		FooAr_insert(arr1, -1, foo, err);
		fatal(Error_iserror(err));
		chk(strstr(Error_message(err), "Index out of range") != NULL);

		FooAr_insertp(arr1, 100, &foo, err);
		fatal(Error_iserror(err));
		chk(strstr(Error_message(err), "Index out of range") != NULL);

		FooAr_insertp(arr1, -1, &foo, err);
		fatal(Error_iserror(err));
		chk(strstr(Error_message(err), "Index out of range") != NULL);

		FooAr_free(arr1);
	}

}

Unit_declare(testRemove){
	{
		Error_declare(err);
		IntAr *arr1 = IntAr_new(0);
		for (int i = 0; i < 10; i++) {
			IntAr_push(arr1, i);
		}
		chk(IntAr_len(arr1) == 10);

		IntAr_remove(arr1, 9, err); // last index
		fatal(!Error_iserror(err));

		IntAr_remove(arr1, 7, err);
		fatal(!Error_iserror(err));

		IntAr_remove(arr1, 5, err);
		fatal(!Error_iserror(err));

		IntAr_remove(arr1, 3, err);
		fatal(!Error_iserror(err));

		IntAr_remove(arr1, 1, err);
		fatal(!Error_iserror(err));

		fatal(IntAr_len(arr1) == 5);
		for (int i = 0; i < 5; i++) {
			int k = IntAr_get(arr1, i, err);
			fatal(!Error_iserror(err));
			chk(k == 2*i);
		}

		for (int i = 0; i < 5; i++) {
			IntAr_remove(arr1, IntAr_last(arr1), err);
			fatal(!Error_iserror(err));			
			chk(IntAr_len(arr1) == 5-1-i);
		}
		IntAr_free(arr1);
	}

	{
		Error_declare(err);
		FooAr *arr1 = FooAr_new(0);
		for (int i = 0; i < 10; i++) {
			Foo foo = {2*i, 4*i};
			FooAr_push(arr1, foo);
		}
		chk(FooAr_len(arr1) == 10);

		FooAr_remove(arr1, 9, err); // last index
		fatal(!Error_iserror(err));

		FooAr_remove(arr1, 7, err);
		fatal(!Error_iserror(err));

		FooAr_remove(arr1, 5, err);
		fatal(!Error_iserror(err));

		FooAr_remove(arr1, 3, err);
		fatal(!Error_iserror(err));

		FooAr_remove(arr1, 1, err);
		fatal(!Error_iserror(err));

		fatal(FooAr_len(arr1) == 5);
		for (int i = 0; i < 5; i++) {
			Foo foo = FooAr_get(arr1, i, err);
			fatal(!Error_iserror(err));
			chk(foo.i == 4*i);
			chk(foo.d == (double)8*i);
		}

		for (int i = 0; i < 5; i++) {
			FooAr_remove(arr1, FooAr_last(arr1), err);
			fatal(!Error_iserror(err));			
			chk(FooAr_len(arr1) == 5-1-i);
		}

		FooAr_free(arr1);
	}
}

Unit_declare(testForeach) {
	{
		IntAr *arr = IntAr_new(0);
		for (int i = 0; i < 5; i++) {
			IntAr_push(arr, 3*i);
		}

		int count = 0;
		IntAr_foreach(it, arr) {
			chk(*it.var == 3*count);
			count++;
		}
		chk(count == 5);

		count = 5-1;
		IntAr_rforeach(it, arr) {
			chk(*it.var == 3*count);
			count--;
		}


		IntAr_foreach(it, arr) {
			*it.var += 17;
		}

		count = 0;
		IntAr_foreach(it, arr) {
			chk(*it.var == 3*count + 17);
			count++;
		}
		chk(count == 5);

		{
			count = 0;
			IntArFIt_declare(it, arr, 0);
			IntAr_loop(it) {
				chk(*it.var == 3*count+17);
				count++;
				break;
			}
			while (IntArFIt_next(&it)) {
				count++;
			}
			chk(count == 5);
		}

		{
			count = 5-1;
			IntArRIt_declare(it, arr, 0);
			IntAr_rloop(it) {
				chk(*it.var == 3*count+17);
				count--;
				break;
			}
			while (IntArRIt_next(&it)) {
				chk(*it.var == 3*count+17);
				count--;
			}
			chk(count == -1);	
		}
		IntAr_free(arr);
	}

	{
		FooAr *arr = FooAr_new(0);
		for (int i = 0; i < 5; i++) {
			Foo foo = {3*i, 6*i};
			FooAr_push(arr, foo);
		}

		int count = 0;
		FooAr_foreach(it, arr) {
			chk(it.var->i == 3*count);
			chk(it.var->d == 6*count);
			count++;
		}
		chk(count == 5);

		count = 5-1;
		FooAr_rforeach(it, arr) {
			chk(it.var->i == 3*count);
			chk(it.var->d == 6*count);
			count--;
		}


		FooAr_foreach(it, arr) {
			it.var->i += 17;
		}

		count = 0;
		FooAr_foreach(it, arr) {
			chk(it.var->i == 3*count + 17);
			count++;
		}
		chk(count == 5);

		{
			count = 0;
			FooArFIt_declare(it, arr, 0);
			FooAr_loop(it) {
				chk(it.var->i == 3*count+17);
				count++;
				break;
			}
			while (FooArFIt_next(&it)) {
				count++;
			}
			chk(count == 5);
		}

		{
			count = 5-1;
			FooArRIt_declare(it, arr, 0);
			FooAr_rloop(it) {
				chk(it.var->i == 3*count+17);
				count--;
				break;
			}
			while (FooArRIt_next(&it)) {
				chk(it.var->i == 3*count+17);
				count--;
			}
			chk(count == -1);	
		}
		FooAr_free(arr);
	}	
}

Unit_declare(testEach) {
	{
		IntAr *arr = IntAr_new(0);
		for (int i = 0; i < 5; i++) {
			IntAr_push(arr, 3*i);
		}

		int count = 0;
		IntAr_each(it, arr) {
			chk(*it == 3*count);
			count++;
		}
		chk(count == 5);

		count = 5-1;
		IntAr_reach(it, arr) {
			chk(*it == 3*count);
			count--;
		}


		IntAr_each(it, arr) {
			*it += 17;
		}

		count = 0;
		IntAr_each(it, arr) {
			chk(*it == 3*count + 17);
			count++;
		}
		chk(count == 5);
		IntAr_free(arr);
	}

	{
		FooAr *arr = FooAr_new(0);
		for (int i = 0; i < 5; i++) {
			Foo foo = {3*i, 6*i};
			FooAr_push(arr, foo);
		}

		int count = 0;
		FooAr_each(it, arr) {
			chk(it->i == 3*count);
			chk(it->d == 6*count);
			count++;
		}
		chk(count == 5);

		count = 5;
		FooAr_reach(it, arr) {
			chk(it->i == 3*(count-1));
			chk(it->d == 6*(count-1));
			count--;
		}
		chk(count == 0);

		FooAr_each(it, arr) {
			it->i += 17;
		}

		count = 0;
		FooAr_each(it, arr) {
			chk(it->i == 3*count + 17);
			count++;
		}
		chk(count == 5);

		FooAr_free(arr);
	}	
}

Unit_declare(testIteratorRemove) {
	{
		IntAr *arr = IntAr_new(0);
		for (int i = 0; i < 5; i++) {
			IntAr_push(arr, i);
		}
		chk(IntAr_len(arr) == 5);

		int count = 0;
		int last  = -1;
		IntAr_foreach(it, arr) {
			chk(last < *it.var);
			last = *it.var;
			if (*it.var % 2 == 0) {
				IntArFIt_remove(&it);
				chk(it.var == NULL);
			}
			count++;
		}
		chk(count == 5);
		chk(IntAr_len(arr) == 2);

		IntAr_foreach(it, arr) {
			int v = *it.var;
			chk(v == 1 || v == 3);
		}
		IntAr_free(arr);
	}
	{
		IntAr *arr = IntAr_new(0);
		for (int i = 0; i < 5; i++) {
			IntAr_push(arr, i);
		}
		chk(IntAr_len(arr) == 5);

		int count = 0;
		int last  = 100;
		IntAr_rforeach(it, arr) {
			chk(last > *it.var);
			last = *it.var;
			if (*it.var % 2 == 1) {
				IntArRIt_remove(&it);
				chk(it.var == NULL);
			}
			count++;
		}
		chk(count == 5);
		chk(IntAr_len(arr) == 3);

		IntAr_rforeach(it, arr) {
			int v = *it.var;
			chk(v == 0 || v == 2 || v == 4);
		}
		IntAr_free(arr);
	}
}

Unit_declare(testSort) {
	{
		Error_declare(err);
		FooAr *arr = FooAr_new(0);
		for (int i = 0; i < 5; i ++) {
			Foo foo = {5-i-1, i};
			FooAr_push(arr, foo);
		}
		FooAr_foreach(it, arr) {
			chk(it.var->i == 5-it.index-1);
		}
		FooAr_sort(arr);
		FooAr_foreach(it, arr) {
			chk(it.var->i == it.index);
		}
		FooAr_free(arr);
	}
}

Unit_declare(testBinSearch) {
	{
		Error_declare(err);
		FooAr *arr = FooAr_new(0);
		for (int i = 0; i < 5; i ++) {
			Foo foo = {i, 2*i};
			FooAr_push(arr, foo);
		}
		FooAr_sort(arr);
		
		
		Foo key1 = {2};
		Foo *res1 = FooAr_binSearch(arr, key1);
		fatal(res1 != NULL);
		chk(res1->i == 2);
		chk(res1->d == 4.0);
		

		
		Foo key2 = {5};
		Foo *res2 = FooAr_binSearch(arr, key2);
		chk(res2 == NULL);
		Foo foo2 = {5, 5};
		FooAr_binInsert(arr, foo2);

		Foo key3 = {5};
		Foo *res3 = FooAr_binSearch(arr, key3);
		fatal(res3 != NULL);		
		chk(res3->i == 5);
		chk(res3->d == 5.0);

		Foo foo4 = {5, 10};
		chk(FooAr_len(arr) == 6);
		FooAr_binInsert(arr, foo4);
		chk(FooAr_len(arr) == 6);
		Foo key4 = {5};
		Foo *res4 = FooAr_binSearch(arr, key4);
		fatal(res4 != NULL);
		chk(res4->i == 5);
		chk(res4->d == 10.0);

		Foo foo5 = {-1, -10};
		FooAr_binInsert(arr, foo5);
		chk(FooAr_len(arr) == 7);
		Foo key5 = {-1};
		Foo *res5 = FooAr_binSearch(arr, key5);
		fatal(res5 != NULL);
		chk(res5->i == -1);
		chk(res5->d == -10);

		Foo key6a = key5;
		Foo key6b = {5};
		chk(FooAr_len(arr) == 7);
		FooAr_binRemove(arr, key6a);
		FooAr_binRemove(arr, key6b);
		chk(FooAr_len(arr) == 5);
		FooAr_foreach(it, arr) {
			chk(it.var->i >= 0 && it.var->i < 5);
		}

		Foo key7a = {1};
		FooAr_binRemove(arr, key7a);
		Foo key7b = {2};
		FooAr_binRemove(arr, key7b);
		chk(FooAr_len(arr) == 3);
		FooAr_foreach(it, arr) {
			chk(it.var->i != 1 && it.var->i != 2);
		}			
		
		FooAr_free(arr);
	}
}

Unit_declare(testBinMulti) {
	Error_declare(err);
	FooAr *arr = FooAr_new(0);
	for (int i = 0; i < 5; i++) {
		if (i == 2) {
			for (int j = 0; j < 4; j++) {
				Foo foo = {i, j};
				FooAr_binInsertMulti(arr, foo);
			}
		} else {
			Foo foo = {i, -i};
			FooAr_binInsertMulti(arr, foo);
		}
	}

	chk(FooAr_len(arr) == 8);

	Foo foo1 = {-1, 0};
	FooArFIt_declare0(slice);
	slice = FooAr_binSearchMulti(arr, foo1);
	fatal(FooArFIt_atEnd(&slice));

	Foo foo2 = {1, 0};
	slice = FooAr_binSearchMulti(arr, foo2);
	fatal(!FooArFIt_atEnd(&slice));
	int count = 0;
	FooAr_loop(slice) {
		chk(slice.var->i == 1);
		count++;
	}
	chk(count == 1);
	
	Foo foo3 = {2, 0};
	slice = FooAr_binSearchMulti(arr, foo3);
	fatal(!FooArFIt_atEnd(&slice));
	count = 0;
	FooAr_loop(slice) {
		chk(slice.var->i == 2);
		chk(slice.var->d == slice.index-slice.lBound);
		count++;
	}
	chk(count == 4);

	Foo foo4  = {2, 0};
	Foo *res4 = FooAr_binSearch(arr, foo4);
	fatal(res4 != NULL);
	chk(res4 == slice.arr->data + slice.lBound);

	Foo foo5 = {1, 0};
	Foo *res5 = FooAr_binSearch(arr, foo5);
	chk(res5 != NULL);
	FooAr_binRemove(arr, foo5);
	res5 = FooAr_binSearch(arr, foo5);
	chk(res5 == NULL);

	Foo foo6 = {2, 0};
	FooArFIt_declare0(res6);
	res6 = FooAr_binSearchMulti(arr, foo6);
	chk(!FooArFIt_atEnd(&res6));
	FooAr_binRemoveMulti(arr, foo6);
	res6 = FooAr_binSearchMulti(arr, foo6);
	chk(FooArFIt_atEnd(&res6));
	
	FooAr_free(arr);
}

Unit_declare(testMixedBinary) {
	FooAr *arr = FooAr_new(0);
	for (int i = 0; i < 10; i++) {
		Foo foo = {0, -i};
		// Insert into the table using both i and d
		FooAr_binInsertBoth(arr, foo);
	}

	// Do a search using just i, and verify that all the elements come out.
	Foo foo1 = {0, 0};
	FooArFIt_declare0(slice);
	slice = FooAr_binSearchMulti(arr, foo1);
	fatal(!FooArFIt_atEnd(&slice));
	int count = 9;
	FooAr_loop(slice) {
		chk(slice.var->i == 0);
		chk(slice.var->d == -count);
		count--;
	}

	FooAr_free(arr);
}	

Unit_declare(testPq) 
{
	{
		// pqPop, pqPeek, pqSort
		NoteSequence *seq1 = NoteSequence_new();
		Ticks time1        = 400;
		NoteSequence *seq2 = NoteSequence_new();
		Ticks time2        = 500;
		NoteSequence *seq3 = NoteSequence_new();
		Ticks time3        = 200;
		TimedPq *arr = TimedPq_new(0);
		Timed t1 = {.time = time1, .version = 0, .sequence = NoteSequence_castToSequence(seq1)};
		TimedPq_push(arr, t1);
		Timed t2 = {.time = time2, .version = 0, .sequence = NoteSequence_castToSequence(seq2)};
		TimedPq_push(arr, t2);
		Timed t3 = {.time = time3, .version = 0, .sequence = NoteSequence_castToSequence(seq3)};
		TimedPq_push(arr, t3);
		chk(TimedPq_len(arr) == 3);

		TimedPq_pqSort(arr);

		Timed *res = TimedPq_pqPeek(arr);
		fatal(res != NULL);
		chk((void*)res->sequence == (void*)seq3);
		chk(res->time            == time3);

		Timed resValue = {0};
		chk(TimedPq_pqPop(arr, &resValue));
		chk((void*)resValue.sequence == (void*)seq3);
		chk(resValue.time            == time3);

		chk(TimedPq_pqPop(arr, &resValue));
		chk((void*)resValue.sequence == (void*)seq1);
		chk(resValue.time            == time1);

		chk(TimedPq_pqPop(arr, &resValue));
		chk((void*)resValue.sequence == (void*)seq2);
		chk(resValue.time            == time2);

		chk(TimedPq_len(arr) == 0);
		chk(!TimedPq_pqPop(arr, &resValue));
		TimedPq_free(arr);
	}

	{
		// pqPush
		NoteSequence *seq1 = NoteSequence_new();
		Ticks time1        = 400;
		NoteSequence *seq2 = NoteSequence_new();
		Ticks time2        = 500;
		NoteSequence *seq3 = NoteSequence_new();
		Ticks time3        = 200;
		TimedPq *arr = TimedPq_new(0);
		Timed t1 = {.time = time1, .version = 0, .sequence = NoteSequence_castToSequence(seq1)};
		TimedPq_pqPush(arr, t1);
		Timed t2 = {.time = time2, .version = 0, .sequence = NoteSequence_castToSequence(seq2)};
		TimedPq_pqPush(arr, t2);
		Timed t3 = {.time = time3, .version = 0, .sequence = NoteSequence_castToSequence(seq3)};
		TimedPq_pqPush(arr, t3);
		chk(TimedPq_len(arr) == 3);

		Timed *res = TimedPq_pqPeek(arr);
		fatal(res != NULL);
		chk((void*)res->sequence == (void*)seq3);
		chk(res->time            == time3);

		Timed resValue = {0};
		chk(TimedPq_pqPop(arr, &resValue));
		chk((void*)resValue.sequence == (void*)seq3);
		chk(resValue.time            == time3);

		chk(TimedPq_pqPop(arr, &resValue));
		chk((void*)resValue.sequence == (void*)seq1);
		chk(resValue.time            == time1);

		chk(TimedPq_pqPop(arr, &resValue));
		chk((void*)resValue.sequence == (void*)seq2);
		chk(resValue.time            == time2);

		chk(TimedPq_len(arr) == 0);
		chk(!TimedPq_pqPop(arr, &resValue));
		TimedPq_free(arr);
	}
}

Unit_declare(testPqQueue) 
{
	{
		// enqueue and dequeue
		TimedPq *queue = TimedPq_new(0);
		NoteSequence *seq = NoteSequence_new();
		for (int i = 0; i < 3; i++) {
			// Enqueue the same sequence 3 times.
			TimedPq_enqueue(queue, 100+i, NoteSequence_castToSequence(seq));
		}	
		chk(TimedPq_len(queue) == 3);
		for (int t = 0; t < 2; t++) {
			int count = 0;
			for (;;) {
				Sequence *s = TimedPq_dequeue(queue, 200*t);
				if (s == NULL) {
					break;
				}
				chk((void*)s == (void*)seq);
				count++;
			}
			if (t == 0) {
				// Nothing comes out when t == 0
				chk(count == 0);
				chk(TimedPq_len(queue) == 3);
			} else {
				// All 3 elements pop off for t == 1
				chk(count == 1);
				chk(TimedPq_len(queue) == 0);
			}
		}
		TimedPq_free(queue);
	}

	{
		// enqueue and dequeue many
		TimedPq *queue = TimedPq_new(0);
		SequenceAr *seqAr = SequenceAr_new(0);
		SequenceAr *got   = SequenceAr_new(0);
		got->clearer      = NULL;
		for (int i = 0; i < 10; i++) {
			NoteSequence *seq = NoteSequence_new();
			SequenceAr_push(seqAr, NoteSequence_castToSequence(seq));
			TimedPq_enqueue(queue, 100+i, NoteSequence_castToSequence(seq));
		}	
		SequenceAr_sortPointer(seqAr);

		chk(TimedPq_len(queue) == 10);
		int count = 0;
		for (;;) {
			Sequence *s = TimedPq_dequeue(queue, 2000);
			if (s == NULL) {
				break;
			}
			
			Sequence **p = SequenceAr_binSearchPointer(seqAr, s);
			fatal(p != NULL);
			fatal(*p != NULL);
			count++;
			SequenceAr_binInsertPointer(got, *p);
		}
		chk(TimedPq_len(queue) == 0);
		chk(count == 10);
		chk(SequenceAr_len(got) == 10);
		TimedPq_free(queue);
		SequenceAr_free(seqAr);
		SequenceAr_free(got);
	}
}


Unit_declare(testPqQueueEnqueue) 
{
	{
		// enqueue and dequeue
		TimedPq *queue = TimedPq_new(0);
		NoteSequence *seq = NoteSequence_new();
		for (int i = 0; i < 3; i++) {
			// Enqueue the same sequence 3 times.
			TimedPq_enqueue(queue, 100+i, NoteSequence_castToSequence(seq));
		}	
		chk(TimedPq_len(queue) == 3);
		for (int t = 0; t < 2; t++) {
			int count = 0;
			for (;;) {
				Sequence *s = TimedPq_dequeue(queue, 200*t);
				if (s == NULL) {
					break;
				}
				chk((void*)s == (void*)seq);
				count++;
			}
			if (t == 0) {
				// Nothing comes out when t == 0
				chk(count == 0);
				chk(TimedPq_len(queue) == 3);
			} else {
				// All 3 elements pop off for t == 1
				chk(count == 1);
				chk(TimedPq_len(queue) == 0);
			}
		}
		TimedPq_free(queue);
	}
}

int main(int argc, char *argv[]) {
	Unit_initialize(argc, argv);
	Unit_test(testNewFree);
	Unit_test(testLenInitClear);
	Unit_test(testInitSurvivesNegativeInit);
	Unit_test(testTruncateClearerAndFit);
	Unit_test(testChangeLength);
	Unit_test(testPushAndGet);
	Unit_test(testPushAndPop);
	Unit_test(testSet);
	Unit_test(testInsert);
	Unit_test(testRemove);
	Unit_test(testForeach);
	Unit_test(testEach);
	Unit_test(testIteratorRemove);
	Unit_test(testSort);
	Unit_test(testBinSearch);
	Unit_test(testBinMulti);
	Unit_test(testMixedBinary);
	Unit_test(testPq);
	Unit_test(testPqQueue);
	Unit_test(testPqQueueEnqueue);
	Unit_finalize();
}
