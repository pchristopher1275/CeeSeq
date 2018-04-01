#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdarg.h>
#include <ctype.h>
#include "../src/core.c"
#include "../src/unit.c"

Unit_declare(testString) {
	{
		// Basic format
		String *s = String_fmt("foo bar");
		chk(String_cequal(s, "foo bar"));
		String_free(s);
	}

	{
		// Expansion format
		String *s = String_fmt("foo %d bar %s baz %.1f", 2, "three", 4.5);
		chk(String_cequal(s, "foo 2 bar three baz 4.5"));
		String_free(s);
	}

	{
		// String length
		String *s = String_fmt("0123456789");
		chk(String_len(s) == 10);
		String_free(s);
	}

	{
		// String trim
		String *s = String_fmt("     0123456789     ");
		String_trim(&s);
		chk(String_cequal(s, "0123456789"));
		String_free(s);
	}

	{
		// String empty
		String *s = String_empty();
		chk(String_len(s) == 0);
		chk(*s == '\0');
		String_free(s);
	}

	{
		// String cmp
		String *s1 = String_fmt("a");
		String *s2 = String_fmt("b");
		chk(String_cmp(s1, s2) < 0);
		String_free(s1);
		String_free(s2);
	}

	{
		// String dup and equal
		String *s1 = String_fmt("foo");
		String *s2 = String_dup(s1);
		chk(String_equal(s1, s2));
		chk(s1 != s2);
		String_free(s1);
		String_free(s2);
	}

	{
		// String resize
		String *s = String_fmt("0123456789");
		chk(String_len(s) == 10);
		
		String_resize(&s, 5);
		chk(String_len(s) == 5);
		chk(String_cequal(s, "01234"));

		String_resize(&s, 25);
		chk(String_len(s) == 25);
		chk(String_cequal(s, "01234"));

		String_free(s);
	}

	{
		// String readline
		Error_declare(err);
		FILE *fd = fopen("test/data/stringReadline.txt", "r");
		fatal(fd != NULL);
		String *s = String_empty();

		int count = 0;
		while (String_readline(&s, fd, err)) {
			fatal(!Error_iserror(err));
			int i = -1;
			fatal(sscanf(s, "%d", &i) == 1);
			chk(count == i);
			count++;
			chk(strcmp(s+2, "0123456789") == 0);
		}
		fatal(!Error_iserror(err));
		String_free(s);
		fclose(fd);
	}
}

int main(int argc, char *argv[]) {
	Unit_initialize(argc, argv);
	Unit_test(testString);
	Unit_finalize();
}