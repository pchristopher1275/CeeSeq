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


struct Foo_t;
void record_clearer(struct Foo_t *left);
int Foo_cmp(struct Foo_t *left, struct Foo_t *right);
int Foo_cmpBoth(struct Foo_t *left, struct Foo_t *right);

#include "util/applicationFor_tarray.c"

int Foo_cmp(Foo *left, Foo *right) {
	if (left->i < right->i) {
		return -1;
	} else if (left->i > right->i) {
		return 1;
	}
	return 0;
}

int Foo_cmpBoth(Foo *left, Foo *right) {
	int q = Foo_cmp(left, right);
	if (q) {
		return q;
	}

	if (left->d < right->d) {
		return -1;
	} else if (left->d > right->d) {
		return 1;
	}

	return 0;
}

const int maxNumRecorded = 10;
int numRecorded          = 0;
Foo recorded[maxNumRecorded] = {0};


void record_zero() {
	numRecorded = 0;
	memset(recorded, 0, sizeof(Foo)*maxNumRecorded);
}

void record_clearer(Foo *left) {
	if (numRecorded < maxNumRecorded) {
		recorded[numRecorded++] = *left;
	}
}



#define Array_cap(arr) ((Array*)arr)->cap

Unit_declare(testNewFree) {
	IntArr *ia = IntArr_new(0);
	chk(ia != NULL);
	IntArr_free(ia);

	FooArr *fa = FooArr_new(10);
	chk(fa != NULL);
	FooArr_free(fa);
}

Unit_declare(testLenInitClear) {
	
	{
		IntArr ia = {0};
		IntArr_init(&ia, 10);
		chk(IntArr_len(&ia) == 10);
		chk(Array_cap(&ia) >= 10);
		IntArr_clear(&ia);
		chk(Array_cap(&ia) == 0);
	}
	{
		FooArr fa = {0};
		FooArr_init(&fa, 5);
		chk(FooArr_len(&fa) == 5);
		chk(Array_cap(&fa) >= 5);
		FooArr_clear(&fa);
		chk(Array_cap(&fa) == 0);
	}
}

Unit_declare(testInitSurvivesNegativeInit) {
	{
		IntArr *ia = IntArr_new(-100);
		chk(IntArr_len(ia) == 0);
		chk(((Array*)ia)->cap == 0);
		chk(((Array*)ia)->data == NULL);
		IntArr_free(ia);
	}

	{
		FooArr *fa = FooArr_new(-10);
		chk(FooArr_len(fa) == 0);
		chk(((Array*)fa)->cap == 0);
		chk(((Array*)fa)->data == NULL);
		FooArr_free(fa);
	}
}

Unit_declare(testTruncateClearerAndFit) {
	{
		IntArr *arr = IntArr_new(10);
		chk(IntArr_len(arr) == 10);
		chk(((Array*)arr)->cap == 10);
		IntArr_truncate(arr);
		chk(IntArr_len(arr) == 0);
		chk(((Array*)arr)->cap == 10);
		IntArr_free(arr);
	}

	{
		Error_declare(err);
		IntArr *arr = IntArr_new(0);
		for (int i = 0; i < 5; i++) {
			IntArr_push(arr, i);
		}
		
		chk(IntArr_len(arr) == 5);
		chk(((Array*)arr)->cap >= 5);
		IntArr_pop(arr, err);
		fatal(!Error_iserror(err));

		IntArr_pop(arr, err);
		fatal(!Error_iserror(err));
		chk(IntArr_len(arr) == 3);
		chk(((Array*)arr)->cap >= 5);

		IntArr_fit(arr);
		chk(IntArr_len(arr) == 3);
		chk(((Array*)arr)->cap == 3);
		for (int i = 0; i < 3; i++) {
			int k = IntArr_get(arr, i, err);
			fatal(!Error_iserror(err));
			chk(k == i);
		}
	}

	{
		Error_declare(err);
		FooArr *arr = FooArr_new(5);
		chk(FooArr_len(arr) == 5);
		chk(((Array*)arr)->cap == 5);
		FooArr_pop(arr, err);
		fatal(!Error_iserror(err));
		FooArr_pop(arr, err);
		fatal(!Error_iserror(err));
		chk(FooArr_len(arr) == 3);
		chk(((Array*)arr)->cap == 5);
		FooArr_fit(arr);
		chk(FooArr_len(arr) == 3);
		chk(((Array*)arr)->cap == 3);
	}


	{
		Error_declare(err);
		record_zero();
		FooArr *arr = FooArr_new(0);
		for (int i = 0; i < 5; i++) {
			Foo foo = {i, 2*i};
			FooArr_push(arr, foo);	
		}
		chk(FooArr_len(arr) == 5);
		chk(((Array*)arr)->cap >= 5);
		chk(numRecorded == 0);
		FooArr_truncate(arr);
		chk(numRecorded == 5);
		for (int i = 0; i < numRecorded; i++) {
			Foo foo = recorded[i];
			chk(foo.i == i);
			chk(foo.d == (double)2*i);
		}

		chk(FooArr_len(arr) == 0);
		chk(((Array*)arr)->cap >= 5);
		FooArr_fit(arr);
		chk(FooArr_len(arr) == 0);
		chk(((Array*)arr)->cap == 0);
		chk(((Array*)arr)->data == NULL);
		
		for (int i = 0; i < 5; i++) {
			Foo foo = {i, 4*i};
			FooArr_push(arr, foo);	
		}
		chk(FooArr_len(arr) == 5);
		chk(((Array*)arr)->cap > 5);
		FooArr_fit(arr);
		chk(FooArr_len(arr) == 5);
		chk(((Array*)arr)->cap == 5);
		for (int i = 0; i < 5; i++) {
			Foo foo = FooArr_get(arr, i, err);
			fatal(!Error_iserror(err));
			chk(foo.i == i);
			chk(foo.d == (double)4*i);
		}
		FooArr_free(arr);
	}
}

Unit_declare(testChangeLength) 
{
	{
		IntArr *arr = IntArr_new(0);
		IntArr_changeLength(arr, 10);
		chk(IntArr_len(arr) == 10);
		IntArr_changeLength(arr, 100);
		chk(IntArr_len(arr) == 100);
		IntArr_changeLength(arr, 2);
		chk(IntArr_len(arr) == 2);
		IntArr_free(arr);
	}

	{
		record_zero();
		FooArr *arr = FooArr_new(0);
		FooArr_changeLength(arr, 5);
		chk(FooArr_len(arr) == 5);
		chk(((Array*)arr)->cap >= 5);
		chk(numRecorded == 0);
		FooArr_changeLength(arr, 3);
		chk(numRecorded == 2);
		for (int i = 0; i < numRecorded; i++) {
			Foo foo = recorded[i];
			chk(foo.i == 0);
			chk(foo.d == (double)0);
		}

		FooArr_changeLength(arr, 100);
		chk(FooArr_len(arr) == 100);
		chk(((Array*)arr)->cap >= 100);
		FooArr_changeLength(arr, 2);
		chk(FooArr_len(arr) == 2);
		chk(((Array*)arr)->cap >= 100);
		FooArr_free(arr);	
	}
}

Unit_declare(testPushAndGet) {
	// Test IntArr for push 10 and get 10
	{
		IntArr *arr1 = IntArr_new(0);
		IntArr *arr2 = IntArr_new(0);
		for (int i = 0; i < 10; i++) {
			int k = i;
			IntArr_push(arr1, 2*i);	
			IntArr_pushp(arr2, &k);
		}
		chk(IntArr_len(arr1) == 10);
		chk(IntArr_len(arr2) == 10);
		Error_declare(err);


		for (int i = 9; i >= 0; i--){
			int *k = IntArr_getp(arr1, i, err);
			fatal(!Error_iserror(err));
			chk(*k == 2*i);
			k = IntArr_getp(arr2, i, err);
			chk(*k == i);
			fatal(!Error_iserror(err));
		}

		for (int i = 9; i >= 0; i--){
			chk(IntArr_get(arr1, i, err) == 2*i);
			fatal(!Error_iserror(err));
			chk(IntArr_get(arr2, i, err) == i);
			fatal(!Error_iserror(err));
		}

		IntArr_free(arr1);
		IntArr_free(arr2);
	}

	// Test that FooArr pushs 10, and then get 10
	{
		FooArr *arr1 = FooArr_new(0);
		FooArr *arr2 = FooArr_new(0);
		for (int i = 0; i < 10; i++) {
			Foo x = {2*i, 1.23};
			FooArr_push(arr1, x);	
			Foo y = {i, 4.56};
			FooArr_pushp(arr2, &y);
		}
		chk(FooArr_len(arr1) == 10);
		chk(FooArr_len(arr2) == 10);
		Error_declare(err);

		for (int i = 9; i >= 0; i--){
			Foo *x = FooArr_getp(arr1, i, err);
			fatal(!Error_iserror(err));
			chk(x->i == 2*i);
			chk(x->d == 1.23);
			Foo *y = FooArr_getp(arr2, i, err);
			chk(y->i == i);
			chk(y->d == 4.56);
			fatal(!Error_iserror(err));
		}

		for (int i = 9; i >= 0; i--){
			Foo xe = {2*i, 1.23};	
			Foo xg = FooArr_get(arr1, i, err);
			chk(xg.i == xe.i);
			chk(xg.d == xe.d);
			Foo ye = {i, 4.56};
			Foo yg = FooArr_get(arr2, i, err);
			fatal(!Error_iserror(err));
			chk(yg.i == ye.i);
			chk(yg.d == ye.d);
		}

		FooArr_free(arr1);
		FooArr_free(arr2);
	}

	// Test push onto existing array
	{
		Error_declare(err);
		IntArr *arr1 = IntArr_new(5);
		for (int i = 0; i < 5; i++) {
			chk(IntArr_get(arr1, i, err) == 0);
			fatal(!Error_iserror(err));
		}
		for (int i = 0; i < 5; i++) {
			IntArr_push(arr1, i+5);
		}
		for (int i = 0; i < 10; i++) {
			int e = i < 5 ? 0 : (i-5)+5;
			chk(IntArr_get(arr1, i, err) == e);
			fatal(!Error_iserror(err));	
		}
		IntArr_free(arr1);
	}

	// Test bad index
	{
		Error_declare(err);
		FooArr *arr1 = FooArr_new(0);
		Foo x = FooArr_get(arr1, 1, err);
		fatal(Error_iserror(err));
		chk(strstr(Error_message(err), "Index out of range (1, 0, 0)") != NULL);
		chk(x.i == 0);
		chk(x.d == 0.0);
		Error_clear(err);

		x = FooArr_get(arr1, -100, err);
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
		IntArr *arr1 = IntArr_new(0);
		for (int i = 0; i < 10; i++) {
			chk(IntArr_len(arr1) == i);
			IntArr_push(arr1, i);
		}
		for (int i = 9; i >= 0; i--) {
			chk(IntArr_len(arr1) == i+1);	
			IntArr_pop(arr1, err);	
			fatalm(!Error_iserror(err), Error_message(err));
		}
		IntArr_free(arr1);
	}

	{
		Error_declare(err);
		FooArr *arr1 = FooArr_new(10);
		for (int i = 9; i >= 0; i--) {
			chk(FooArr_len(arr1) == i+1);	
			FooArr_pop(arr1, err);	
			fatalm(!Error_iserror(err), Error_message(err));
		}
		FooArr_free(arr1);
	}

	{
		Error_declare(err);
		IntArr *arr1 = IntArr_new(0);
		IntArr_pop(arr1, err);	
		fatal(Error_iserror(err));
		chk(strstr(Error_message(err), "Index out of range") != NULL);
	}
}

Unit_declare(testSet) {
	{
		Error_declare(err);
		IntArr *arr1 = IntArr_new(3);
		IntArr_set(arr1, 0, 14, err);
		fatal(!Error_iserror(err));

		int k = 15;
		IntArr_setp(arr1, 1, &k, err);
		fatal(!Error_iserror(err));

		k = 16;
		IntArr_setp(arr1, 2, &k, err);
		fatal(!Error_iserror(err));

		chk(IntArr_get(arr1, 0, err) == 14);
		fatal(!Error_iserror(err));

		chk(IntArr_get(arr1, 1, err) == 15);
		fatal(!Error_iserror(err));

		chk(IntArr_get(arr1, 2, err) == 16);
		fatal(!Error_iserror(err));		
		
		IntArr_free(arr1);
	}

	{
		Error_declare(err);
		FooArr *arr1 = FooArr_new(3);
		Foo foo = {0};
		foo.i = 14;
		foo.d = 1.23;
		FooArr_set(arr1, 0, foo, err);
		fatal(!Error_iserror(err));

		foo.i = 15;
		foo.d = 4.56;
		FooArr_setp(arr1, 1, &foo, err);
		fatal(!Error_iserror(err));

		foo.i = 16;
		foo.d = 7.89;
		FooArr_set(arr1, 2, foo, err);
		fatal(!Error_iserror(err));

		foo = FooArr_get(arr1, 0, err);
		fatal(!Error_iserror(err));
		chk(foo.i == 14);
		chk(foo.d == 1.23);

		foo = FooArr_get(arr1, 1, err);
		fatal(!Error_iserror(err));
		chk(foo.i == 15);
		chk(foo.d == 4.56);
		
		foo = FooArr_get(arr1, 2, err);
		fatal(!Error_iserror(err));
		chk(foo.i == 16);
		chk(foo.d == 7.89);

		FooArr_free(arr1);
	}

	{
		Error_declare(err);
		FooArr *arr1 = FooArr_new(3);
		Foo foo = {0};
		FooArr_setp(arr1, 100, &foo, err);
		fatal(Error_iserror(err));

		FooArr_setp(arr1, -100, &foo, err);
		fatal(Error_iserror(err));

		FooArr_free(arr1);
	}
}

Unit_declare(testInsert) {
	{
		Error_declare(err);
		IntArr *arr1 = IntArr_new(3);

		IntArr_insert(arr1, 0, 1, err);
		fatal(!Error_iserror(err));

		int k = 2;
		IntArr_insertp(arr1, 2, &k, err);
		fatal(!Error_iserror(err));

		k = 3;
		IntArr_insertp(arr1, 4, &k, err);
		fatal(!Error_iserror(err));

		// Insert at last index
		IntArr_insert(arr1, IntArr_len(arr1), 111, err);
		fatal(!Error_iserror(err));

		chk(IntArr_get(arr1, 0, err) == 1);
		fatal(!Error_iserror(err));

		chk(IntArr_get(arr1, 1, err) == 0);
		fatal(!Error_iserror(err));

		chk(IntArr_get(arr1, 2, err) == 2);
		fatal(!Error_iserror(err));

		chk(IntArr_get(arr1, 3, err) == 0);
		fatal(!Error_iserror(err));

		chk(IntArr_get(arr1, 4, err) == 3);
		fatal(!Error_iserror(err));

		chk(IntArr_get(arr1, 5, err) == 0);
		fatal(!Error_iserror(err));
		
		chk(IntArr_get(arr1, IntArr_last(arr1), err) == 111);
		fatal(!Error_iserror(err));

		IntArr_free(arr1);
	}

	{
		Error_declare(err);
		FooArr *arr1 = FooArr_new(3);

		Foo foo = {0};
		foo.i = 1;
		foo.d = 1.0;
		FooArr_insert(arr1, 0, foo, err);
		fatal(!Error_iserror(err));

		foo.i = 2;
		foo.d = 2.0;
		FooArr_insertp(arr1, 2, &foo, err);
		fatal(!Error_iserror(err));

		foo.i = 3;
		foo.d = 3.0;
		FooArr_insertp(arr1, 4, &foo, err);
		fatal(!Error_iserror(err));


		foo.i = 111;
		foo.d = 111.0;
		FooArr_insertp(arr1, FooArr_len(arr1), &foo, err);
		fatal(!Error_iserror(err));


		foo = FooArr_get(arr1, 0, err);
		fatal(!Error_iserror(err));
		chk(foo.i == 1);
		chk(foo.d == 1.0);
		
		foo = FooArr_get(arr1, 1, err);
		fatal(!Error_iserror(err));
		chk(foo.i == 0);
		chk(foo.d == 0.0);

		foo = FooArr_get(arr1, 2, err);
		fatal(!Error_iserror(err));
		chk(foo.i == 2);
		chk(foo.d == 2.0);

		foo = FooArr_get(arr1, 3, err);
		fatal(!Error_iserror(err));
		chk(foo.i == 0);
		chk(foo.d == 0.0);

		foo = FooArr_get(arr1, 4, err);
		fatal(!Error_iserror(err));
		chk(foo.i == 3);
		chk(foo.d == 3.0);

		foo = FooArr_get(arr1, 5, err);
		fatal(!Error_iserror(err));
		chk(foo.i == 0);
		chk(foo.d == 0.0);
		
		foo = FooArr_get(arr1, FooArr_last(arr1), err);
		fatal(!Error_iserror(err));
		chk(foo.i == 111);
		chk(foo.d == 111.0);


		FooArr_free(arr1);
	}

	{
		Error_declare(err);
		FooArr *arr1 = FooArr_new(3);
		Foo foo = {0};

		FooArr_insert(arr1, 100, foo, err);
		fatal(Error_iserror(err));
		chk(strstr(Error_message(err), "Index out of range") != NULL);

		FooArr_insert(arr1, -1, foo, err);
		fatal(Error_iserror(err));
		chk(strstr(Error_message(err), "Index out of range") != NULL);

		FooArr_insertp(arr1, 100, &foo, err);
		fatal(Error_iserror(err));
		chk(strstr(Error_message(err), "Index out of range") != NULL);

		FooArr_insertp(arr1, -1, &foo, err);
		fatal(Error_iserror(err));
		chk(strstr(Error_message(err), "Index out of range") != NULL);

		FooArr_free(arr1);
	}

}

Unit_declare(testRemove){
	{
		Error_declare(err);
		IntArr *arr1 = IntArr_new(0);
		for (int i = 0; i < 10; i++) {
			IntArr_push(arr1, i);
		}
		chk(IntArr_len(arr1) == 10);

		IntArr_remove(arr1, 9, err); // last index
		fatal(!Error_iserror(err));

		IntArr_remove(arr1, 7, err);
		fatal(!Error_iserror(err));

		IntArr_remove(arr1, 5, err);
		fatal(!Error_iserror(err));

		IntArr_remove(arr1, 3, err);
		fatal(!Error_iserror(err));

		IntArr_remove(arr1, 1, err);
		fatal(!Error_iserror(err));

		fatal(IntArr_len(arr1) == 5);
		for (int i = 0; i < 5; i++) {
			int k = IntArr_get(arr1, i, err);
			fatal(!Error_iserror(err));
			chk(k == 2*i);
		}

		for (int i = 0; i < 5; i++) {
			IntArr_remove(arr1, IntArr_last(arr1), err);
			fatal(!Error_iserror(err));			
			chk(IntArr_len(arr1) == 5-1-i);
		}
		IntArr_free(arr1);
	}

	{
		Error_declare(err);
		FooArr *arr1 = FooArr_new(0);
		for (int i = 0; i < 10; i++) {
			Foo foo = {2*i, 4*i};
			FooArr_push(arr1, foo);
		}
		chk(FooArr_len(arr1) == 10);

		FooArr_remove(arr1, 9, err); // last index
		fatal(!Error_iserror(err));

		FooArr_remove(arr1, 7, err);
		fatal(!Error_iserror(err));

		FooArr_remove(arr1, 5, err);
		fatal(!Error_iserror(err));

		FooArr_remove(arr1, 3, err);
		fatal(!Error_iserror(err));

		FooArr_remove(arr1, 1, err);
		fatal(!Error_iserror(err));

		fatal(FooArr_len(arr1) == 5);
		for (int i = 0; i < 5; i++) {
			Foo foo = FooArr_get(arr1, i, err);
			fatal(!Error_iserror(err));
			chk(foo.i == 4*i);
			chk(foo.d == (double)8*i);
		}

		for (int i = 0; i < 5; i++) {
			FooArr_remove(arr1, FooArr_last(arr1), err);
			fatal(!Error_iserror(err));			
			chk(FooArr_len(arr1) == 5-1-i);
		}

		FooArr_free(arr1);
	}
}

Unit_declare(testForeach) {
	{
		IntArr *arr = IntArr_new(0);
		for (int i = 0; i < 5; i++) {
			IntArr_push(arr, 3*i);
		}

		int count = 0;
		IntArr_foreach(it, arr) {
			chk(*it.var == 3*count);
			count++;
		}
		chk(count == 5);

		count = 5-1;
		IntArr_rforeach(it, arr) {
			chk(*it.var == 3*count);
			count--;
		}


		IntArr_foreach(it, arr) {
			*it.var += 17;
		}

		count = 0;
		IntArr_foreach(it, arr) {
			chk(*it.var == 3*count + 17);
			count++;
		}
		chk(count == 5);

		{
			count = 0;
			IntArrFIt_declare(it, arr);
			IntArr_loop(it) {
				chk(*it.var == 3*count+17);
				count++;
				break;
			}
			while (IntArrFIt_next(&it)) {
				count++;
			}
			chk(count == 5);
		}

		{
			count = 5-1;
			IntArrRIt_declare(it, arr);
			IntArr_rloop(it) {
				chk(*it.var == 3*count+17);
				count--;
				break;
			}
			while (IntArrRIt_next(&it)) {
				chk(*it.var == 3*count+17);
				count--;
			}
			chk(count == -1);	
		}
		IntArr_free(arr);
	}

	{
		FooArr *arr = FooArr_new(0);
		for (int i = 0; i < 5; i++) {
			Foo foo = {3*i, 6*i};
			FooArr_push(arr, foo);
		}

		int count = 0;
		FooArr_foreach(it, arr) {
			chk(it.var->i == 3*count);
			chk(it.var->d == 6*count);
			count++;
		}
		chk(count == 5);

		count = 5-1;
		FooArr_rforeach(it, arr) {
			chk(it.var->i == 3*count);
			chk(it.var->d == 6*count);
			count--;
		}


		FooArr_foreach(it, arr) {
			it.var->i += 17;
		}

		count = 0;
		FooArr_foreach(it, arr) {
			chk(it.var->i == 3*count + 17);
			count++;
		}
		chk(count == 5);

		{
			count = 0;
			FooArrFIt_declare(it, arr);
			FooArr_loop(it) {
				chk(it.var->i == 3*count+17);
				count++;
				break;
			}
			while (FooArrFIt_next(&it)) {
				count++;
			}
			chk(count == 5);
		}

		{
			count = 5-1;
			FooArrRIt_declare(it, arr);
			FooArr_rloop(it) {
				chk(it.var->i == 3*count+17);
				count--;
				break;
			}
			while (FooArrRIt_next(&it)) {
				chk(it.var->i == 3*count+17);
				count--;
			}
			chk(count == -1);	
		}
		FooArr_free(arr);
	}	
}

Unit_declare(testEach) {
	{
		IntArr *arr = IntArr_new(0);
		for (int i = 0; i < 5; i++) {
			IntArr_push(arr, 3*i);
		}

		int count = 0;
		IntArr_each(it, arr) {
			chk(*it == 3*count);
			count++;
		}
		chk(count == 5);

		count = 5-1;
		IntArr_reach(it, arr) {
			chk(*it == 3*count);
			count--;
		}


		IntArr_each(it, arr) {
			*it += 17;
		}

		count = 0;
		IntArr_each(it, arr) {
			chk(*it == 3*count + 17);
			count++;
		}
		chk(count == 5);
		IntArr_free(arr);
	}

	{
		FooArr *arr = FooArr_new(0);
		for (int i = 0; i < 5; i++) {
			Foo foo = {3*i, 6*i};
			FooArr_push(arr, foo);
		}

		int count = 0;
		FooArr_each(it, arr) {
			chk(it->i == 3*count);
			chk(it->d == 6*count);
			count++;
		}
		chk(count == 5);

		count = 5;
		FooArr_reach(it, arr) {
			chk(it->i == 3*(count-1));
			chk(it->d == 6*(count-1));
			count--;
		}
		chk(count == 0);

		FooArr_each(it, arr) {
			it->i += 17;
		}

		count = 0;
		FooArr_each(it, arr) {
			chk(it->i == 3*count + 17);
			count++;
		}
		chk(count == 5);

		FooArr_free(arr);
	}	
}

Unit_declare(testIteratorRemove) {
	{
		IntArr *arr = IntArr_new(0);
		for (int i = 0; i < 5; i++) {
			IntArr_push(arr, i);
		}
		chk(IntArr_len(arr) == 5);

		int count = 0;
		int last  = -1;
		IntArr_foreach(it, arr) {
			chk(last < *it.var);
			last = *it.var;
			if (*it.var % 2 == 0) {
				IntArrFIt_remove(&it);
				chk(it.var == NULL);
			}
			count++;
		}
		chk(count == 5);
		chk(IntArr_len(arr) == 2);

		IntArr_foreach(it, arr) {
			int v = *it.var;
			chk(v == 1 || v == 3);
		}
		IntArr_free(arr);
	}
	{
		IntArr *arr = IntArr_new(0);
		for (int i = 0; i < 5; i++) {
			IntArr_push(arr, i);
		}
		chk(IntArr_len(arr) == 5);

		int count = 0;
		int last  = 100;
		IntArr_rforeach(it, arr) {
			chk(last > *it.var);
			last = *it.var;
			if (*it.var % 2 == 1) {
				IntArrRIt_remove(&it);
				chk(it.var == NULL);
			}
			count++;
		}
		chk(count == 5);
		chk(IntArr_len(arr) == 3);

		IntArr_rforeach(it, arr) {
			int v = *it.var;
			chk(v == 0 || v == 2 || v == 4);
		}
		IntArr_free(arr);
	}
}

Unit_declare(testSort) {
	{
		Error_declare(err);
		FooArr *arr = FooArr_new(0);
		for (int i = 0; i < 5; i ++) {
			Foo foo = {5-i-1, i};
			FooArr_push(arr, foo);
		}
		FooArr_foreach(it, arr) {
			chk(it.var->i == 5-it.index-1);
		}
		FooArr_sort(arr);
		FooArr_foreach(it, arr) {
			chk(it.var->i == it.index);
		}
		FooArr_free(arr);
	}
}

Unit_declare(testBinSearch) {
	{
		Error_declare(err);
		FooArr *arr = FooArr_new(0);
		for (int i = 0; i < 5; i ++) {
			Foo foo = {i, 2*i};
			FooArr_push(arr, foo);
		}
		FooArr_sort(arr);
		
		
		Foo key1 = {2};
		Foo *res1 = FooArr_binSearch(arr, key1);
		fatal(res1 != NULL);
		chk(res1->i == 2);
		chk(res1->d == 4.0);
		

		
		Foo key2 = {5};
		Foo *res2 = FooArr_binSearch(arr, key2);
		chk(res2 == NULL);
		Foo foo2 = {5, 5};
		FooArr_binInsert(arr, foo2);

		Foo key3 = {5};
		Foo *res3 = FooArr_binSearch(arr, key3);
		fatal(res3 != NULL);		
		chk(res3->i == 5);
		chk(res3->d == 5.0);

		Foo foo4 = {5, 10};
		chk(FooArr_len(arr) == 6);
		FooArr_binInsert(arr, foo4);
		chk(FooArr_len(arr) == 6);
		Foo key4 = {5};
		Foo *res4 = FooArr_binSearch(arr, key4);
		fatal(res4 != NULL);
		chk(res4->i == 5);
		chk(res4->d == 10.0);

		Foo foo5 = {-1, -10};
		FooArr_binInsert(arr, foo5);
		chk(FooArr_len(arr) == 7);
		Foo key5 = {-1};
		Foo *res5 = FooArr_binSearch(arr, key5);
		fatal(res5 != NULL);
		chk(res5->i == -1);
		chk(res5->d == -10);

		Foo key6a = key5;
		Foo key6b = {5};
		chk(FooArr_len(arr) == 7);
		FooArr_binRemove(arr, key6a);
		FooArr_binRemove(arr, key6b);
		chk(FooArr_len(arr) == 5);
		FooArr_foreach(it, arr) {
			chk(it.var->i >= 0 && it.var->i < 5);
		}

		Foo key7a = {1};
		FooArr_binRemove(arr, key7a);
		Foo key7b = {2};
		FooArr_binRemove(arr, key7b);
		chk(FooArr_len(arr) == 3);
		FooArr_foreach(it, arr) {
			chk(it.var->i != 1 && it.var->i != 2);
		}			
		
		FooArr_free(arr);
	}
}

Unit_declare(testBinMulti) {
	Error_declare(err);
	FooArr *arr = FooArr_new(0);
	for (int i = 0; i < 5; i++) {
		if (i == 2) {
			for (int j = 0; j < 4; j++) {
				Foo foo = {i, j};
				FooArr_binInsertMulti(arr, foo);
			}
		} else {
			Foo foo = {i, -i};
			FooArr_binInsertMulti(arr, foo);
		}
	}

	chk(FooArr_len(arr) == 8);

	Foo foo1 = {-1, 0};
	FooArrFIt_declare0(slice);
	slice = FooArr_binSearchMulti(arr, foo1);
	fatal(FooArrFIt_atEnd(&slice));

	Foo foo2 = {1, 0};
	slice = FooArr_binSearchMulti(arr, foo2);
	fatal(!FooArrFIt_atEnd(&slice));
	int count = 0;
	FooArr_loop(slice) {
		chk(slice.var->i == 1);
		count++;
	}
	chk(count == 1);
	
	Foo foo3 = {2, 0};
	slice = FooArr_binSearchMulti(arr, foo3);
	fatal(!FooArrFIt_atEnd(&slice));
	count = 0;
	FooArr_loop(slice) {
		chk(slice.var->i == 2);
		chk(slice.var->d == slice.index-slice.lBound);
		count++;
	}
	chk(count == 4);

	Foo foo4  = {2, 0};
	Foo *res4 = FooArr_binSearch(arr, foo4);
	fatal(res4 != NULL);
	chk(res4 == slice.arr->data + slice.lBound);

	Foo foo5 = {1, 0};
	Foo *res5 = FooArr_binSearch(arr, foo5);
	chk(res5 != NULL);
	FooArr_binRemove(arr, foo5);
	res5 = FooArr_binSearch(arr, foo5);
	chk(res5 == NULL);

	Foo foo6 = {2, 0};
	FooArrFIt_declare0(res6);
	res6 = FooArr_binSearchMulti(arr, foo6);
	chk(!FooArrFIt_atEnd(&res6));
	FooArr_binRemoveMulti(arr, foo6);
	res6 = FooArr_binSearchMulti(arr, foo6);
	chk(FooArrFIt_atEnd(&res6));
	
	FooArr_free(arr);
}

Unit_declare(testMixedBinary) {
	FooArr *arr = FooArr_new(0);
	for (int i = 0; i < 10; i++) {
		Foo foo = {0, -i};
		// Insert into the table using both i and d
		FooArr_binInsertBoth(arr, foo);
	}

	// Do a search using just i, and verify that all the elements come out.
	Foo foo1 = {0, 0};
	FooArrFIt_declare0(slice);
	slice = FooArr_binSearchMulti(arr, foo1);
	fatal(!FooArrFIt_atEnd(&slice));
	int count = 9;
	FooArr_loop(slice) {
		chk(slice.var->i == 0);
		chk(slice.var->d == -count);
		count--;
	}

	FooArr_free(arr);
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
	Unit_finalize();
}
