#include "../src/unit.c"
#include "../src/array.c"

Unit_declare(foo) {
	
}

Unit_declare(bar) {
	
}

int main(int argc, char *argv[]) {
	Unit_initialize(argc, argv);
	Unit_finalize();
}
