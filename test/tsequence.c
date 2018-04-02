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
#include "../src/application.c"

Unit_declare(testSeq) {
	
}

int main(int argc, char *argv[]) {
	Unit_initialize(argc, argv);
	Unit_test(testSeq);
	Unit_finalize();
}