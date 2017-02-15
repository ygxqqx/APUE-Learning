#include <stdio.h>
#include <unistd.h>

#define MAXLINE 1024

int main(int argc, char const *argv[]) {
	
	char buf[MAXLINE];
	while (fgets(buf, MAXLINE, stdin) != NULL) {
		if (fputs(buf, stdout) == EOF) {
			printf("output error\n");
		}
	}
	if (ferror(stdin)) {
		printf("input error\n");
	}
	return 0;
}
