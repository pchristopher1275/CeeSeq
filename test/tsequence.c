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