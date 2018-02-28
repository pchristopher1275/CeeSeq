#include "../src/core.c"
#include "../src/unit.c"
#include "../src/array.c"


typedef struct Foo_t {
	int i;
	double d;
} Foo;
#define Foo_newUninitialized() Mem_malloc(sizeof(Foo))
const int maxNumRecorded = 10;
int numRecorded          = 0;
Foo *recorded[maxNumRecorded] = {NULL};

void record_clearer(Foo *left) {
	if (numRecorded < maxNumRecorded) {
		recorded[numRecorded++] = left;
	}
}


#include "util/for_tarray.c"

#define Array_cap(arr) ((Array*)arr)->cap

Unit_declare(testNewFree) {
	IntArr *ia = IntArr_new(0);
	chk(ia != NULL);
	IntArr_free(ia);

	FooArr *fa = FooArr_new(10);
	chk(fa != NULL);
	FooArr_free(fa);

	FooPtrArr *fpa = FooPtrArr_new(100);
	chk(fpa != NULL);
	FooPtrArr_free(fpa);
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

Unit_declare(testTruncateAndClearer) {
	{
		IntArr *arr = IntArr_new(10);
		chk(IntArr_len(arr) == 10);
		chk(((Array*)arr)->cap == 10);
		IntArr_truncate(arr);
		chk(IntArr_len(arr) == 0);
		chk(((Array*)arr)->cap == 10);
	}

	{
		numRecorded = 0;
		FooArr *arr = FooArr_new(5);
		chk(FooArr_len(arr) == 5);
		chk(((Array*)arr)->cap == 5);
		chk(numRecorded == 0);
		FooArr_truncate(arr);
		chk(numRecorded == 5);
		chk(FooArr_len(arr) == 0);
		chk(((Array*)arr)->cap == 5);
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
		
		FooArr_free(arr1);
	}

	{
		Error_declare(err);
		FooArr *arr1 = FooArr_new(3);
		Foo foo = {0};

		FooArr_insert(arr1, 100, foo, err);
		fatal(Error_iserror(err));
		chk(strstr(Error_message(err), "Index out of range"));

		FooArr_insert(arr1, -1, foo, err);
		fatal(Error_iserror(err));
		chk(strstr(Error_message(err), "Index out of range"));

		FooArr_insertp(arr1, 100, &foo, err);
		fatal(Error_iserror(err));
		chk(strstr(Error_message(err), "Index out of range"));

		FooArr_insertp(arr1, -1, &foo, err);
		fatal(Error_iserror(err));
		chk(strstr(Error_message(err), "Index out of range"));

		FooArr_free(arr1);
	}

}

int main(int argc, char *argv[]) {
	Unit_initialize(argc, argv);
	Unit_test(testNewFree);
	Unit_test(testLenInitClear);
	Unit_test(testInitSurvivesNegativeInit);
	Unit_test(testTruncateAndClearer);
	Unit_test(testPushAndGet);
	Unit_test(testPushAndPop);
	Unit_test(testSet);
	Unit_test(testInsert);
	Unit_finalize();
}
