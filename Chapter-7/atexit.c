#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


static void exit_01(void);
static void exit_02(void);

int main(int argc, char const *argv[]) {
	
	if (atexit(exit_01) != 0) {
		printf("register exit_01 error\n");
	}

	if (atexit(exit_02) != 0) {
		printf("register exit_02 error\n");
	}

	if (atexit(exit_02) != 0) {
		printf("register exit_02 error\n");
	}

	printf("main is done\n");
	return 0;
}

static void exit_01(void) {
	printf("first exit handler\n");
}

static void exit_02(void) {
	printf("second exit handler\n");
}

