#include <stdio.h>
#include "../src/sds.c"



typedef struct Unit_t {
	// How many asserts tried in this test
	int numAsserts;

	// How many asserts failed in this test
	int numFails;

	// How many tests are run.
	int numTests;

	// How many tests failed.
	int numTestFails;

	// Which tests to run in this file
	sds shouldRun;

} Unit;



Unit Unit_instanceStruct = {0};
Unit *Unit_instance = &Unit_instanceStruct;

#define Unit_numFails     Unit_instance->numFails
#define Unit_numAsserts   Unit_instance->numAsserts
#define Unit_numTests     Unit_instance->numTests
#define Unit_numTestFails Unit_instance->numTestFails

#define Unit_shouldRun  Unit_instance->shouldRun


#define Unit_initialize(argc, argv) do {\
	printf("Testing FILE %s\n", __FILE__);\
	if (argc > 0) {\
		Unit_shouldRun = sdsempty();\
		for (int i = 0; i < argc; i++) {\
			Unit_shouldRun = sdscat(Unit_shouldRun, argv[i]);\
			Unit_shouldRun = sdscat(Unit_shouldRun, " ");\
		}\
	}\
} while (0)

#define Unit_finalize() do {\
	if (Unit_numTestFails > 0) {\
		printf("FAILED TESTS in %s: %d test functions failed out of %d test functions\n", __FILE__, Unit_numTestFails, Unit_numTests);\
	} else {\
		printf("Test file %s ok\n", __FILE__);\
	}\
} while (0)

#define Unit_declare(testName) void testName(void)

#define Unit_test(func) do {\
	if (Unit_shouldRun == NULL || strcmp(#func, Unit_shouldRun)) {\
		Unit_numTests++;\
		printf("    Testing function %s\n", #func);\
		func();\
		if (Unit_numFails > 0) {\
			Unit_numTestFails++;\
			printf("    test %s had %d failures out of %d asserts\n", #func, Unit_numFails, Unit_numAsserts);\
		}\
		Unit_numFails   = 0;\
		Unit_numAsserts = 0;\
	}\
} while (0)

#define Unit_assert(expr, message, fatal) do {\
	Unit_numAsserts++;\
	const char *m = (message);\
	if (!(expr)) {\
		Unit_numFails++;\
		printf("        %s %s failed (%s, %d)", fatal ? "Fatal assert" : "Assert", #expr, __FILE__, __LINE__);\
		if (m != NULL) {\
			printf(": %s\n", message);\
		} else {\
			printf("\n");\
		}\
		if (fatal) {\
			return;\
		}\
	}\
} while (0)

#define chk(e)        Unit_assert(e, NULL, 0)
#define chkm(e, m)    Unit_assert(e, m, 0)
#define fatal(e)      Unit_assert(e, NULL, 1)
#define fatalm(e, m)  Unit_assert(e, m, 1)

