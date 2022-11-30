#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"

extern int test();

int main(int argc, char const *argv[]) {
	// Perform unit tests if first argument is "test"
	if (argc == 2 && strcmp(argv[1], "test") == 0) {
		return test();
	}

	printf("Hello, world!\n");
	return 0;
}
