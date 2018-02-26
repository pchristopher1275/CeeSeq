#include "../src/unit.c"


Unit_declare(foo) {
	int i = 1;
	chk(i == 1);
	chkm(i == 2, "Message");
	fatal(i == 1);
	fatalm(i == 1, "More message");
	fatalm(i == 2, "More message");
	printf("FOO BAR WOnt be seen\n");
}

int main(int argc, char *argv[]) {
	Unit_initialize(argc, argv);
	Unit_test(foo);
	Unit_finalize();
}