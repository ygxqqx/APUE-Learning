#include <unistd.h>
#include <stdio.h>
// #include <unistd.h>

void pr_stdio(const char *, FILE *);
int is_unbuffered(FILE *);
int is_linebuffered(FILE *);
int buffer_size(FILE *);

int main(int argc, char const *argv[]) {

	FILE *fp;
	fputs("enter any character\n", stderr);

	if (getchar() == EOF) {
		printf("getchar error\n");
	}

	

	return 0;
}




