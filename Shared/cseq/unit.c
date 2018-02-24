
#include <stdio.h>

#define Unit_colorCode 0x1b
#define Unit_red "[1;31m"
#define Unit_green "[1;32m"
#define Unit_colorReset "[0m"

// Unit test variables
int Unit_numAsserts;
int Unit_numFailures;
int Unit_numTests;
const char *Unit_testsToRun = NULL;

// Declare test function
// e.g
// Unit_declare(testThisStuff) {
//     ....
// }
#define Unit_declare(func) void func(void)

// Call that test function. E.g.
//
// int main() {
//      ...
//      Unit_test(testThisStuff);
// }
//
#define Unit_test(test) \
  { \
    if (Unit_testsToRun = NULL || strcmp(Unit_testsToRun, #test) == 0) {\
        int f = Unit_numFailures; \
        Unit_numTests++; \
        test(); \
        Unit_printTest(#test, (f == Unit_numFailures)); \
    }\
  }

#define Unit_printFail(file, line, expr) \
  printf("        %s:%u: failed assertion `%s'\n", file, line, expr)

#define Unit_printTest(test, passed) \
  printf("    %-10s ... %c%s%c%s\n", test, Unit_colorCode, \
    (passed) ? Unit_green "pass" : Unit_red "fail", \
    Unit_colorCode, Unit_colorReset)

#define Unit_printResults() \
  printf("Tests in file %s\n", __FILE__);
  if (Unit_numFailures) { \
    printf("    %c%sFAILED%c%s (failed: %d, passed: %d, total: %d)\n", \
      Unit_colorCode, Unit_red, Unit_colorCode, Unit_colorReset, \
      Unit_numFailures, Unit_numAsserts - Unit_numFailures, Unit_numAsserts); \
  } else { \
    printf("    %c%sPASSED%c%s (total asserts: %d)\n", \
      Unit_colorCode, Unit_green, Unit_colorCode, Unit_colorReset, Unit_numAsserts); \
  }

#define Unit_assert(expr) \
  { \
    Unit_numAsserts++; \
    if(!(expr)) { \
      ++Unit_numFailures; \
      Unit_printFail(__FILE__, __LINE__, #expr); \
    } \
  }

#define mu_test(test) \
  { \
    int f = Unit_numFailures; \
    ++Unit_numTests; \
    test(); \
    Unit_printTest(#test, (f == Unit_numFailures)); \
  }



