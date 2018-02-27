#include "../src/unit.c"


Unit_declare(baz) {
	int i = 1;
	chk(i == 1);
	chkm(i == 1, "Message");
}

Unit_declare(bang) {
	chk(1 == 1);
}

int main(int argc, char *argv[]) {
	Unit_initialize(argc, argv);
	Unit_test(baz);
	Unit_test(bang);
	Unit_finalize();
}
