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

#define Unit_tab0 ""
#define Unit_tab1 "    "
#define Unit_tab2 "        "

#define Unit_initialize(argc, argv) do {\
	if (argc > 1) {\
		Unit_shouldRun = sdsempty();\
		for (int i = 1; i < argc; i++) {\
			Unit_shouldRun = sdscat(Unit_shouldRun, argv[i]);\
			Unit_shouldRun = sdscat(Unit_shouldRun, " ");\
		}\
	}\
	printf("Testing file %s with arguments '%s'\n", __FILE__, Unit_shouldRun);\
} while (0)

#define Unit_finalize() do {\
	if (Unit_numTestFails > 0) {\
		printf(Unit_tab0 "FAILED TESTS in file %s: %d tests failed out of %d tests\n", __FILE__, Unit_numTestFails, Unit_numTests);\
		exit(1);\
	} else {\
		printf(Unit_tab0 "Test file %s ok\n", __FILE__);\
		exit(0);\
	}\
} while (0)

#define Unit_declare(testName) void testName(void)

#define Unit_test(func) do {\
	if (Unit_shouldRun == NULL || strstr(Unit_shouldRun, #func) != NULL) {\
		Unit_numTests++;\
		printf(Unit_tab1 "Testing function %s\n", #func);\
		func();\
		if (Unit_numFails > 0) {\
			Unit_numTestFails++;\
			printf(Unit_tab1 "Test %s had %d failures out of %d asserts\n", #func, Unit_numFails, Unit_numAsserts);\
		} else {\
			printf(Unit_tab1 "Test %s ok\n", #func);\
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
		printf(Unit_tab2 "%s %s failed (%s, %d)", fatal ? "Fatal assert" : "Assert", #expr, __FILE__, __LINE__);\
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

