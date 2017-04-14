#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <errno.h>

#define MAXLINE 1024

void make_temp(char *template);

int main(int argc, char const *argv[]) {
	
	char good_template[] = "/tmp/dirXXXXXX"; // right way
	char *bad_template = "/tmp/dirXXXXXX"; // wrong way
	printf("trying to create first temp file...\n");
	make_temp(good_template);
	printf("trying to create second temp file...\n");
	make_temp(bad_template);
	return 0;
}

void make_temp(char *template) {

	int fd;
	struct stat sbuf;

	if ((fd = mkstemp(template)) < 0) {
		printf("can not create temp file\n");
	}
	printf("temp name = %s\n", template);
	close(fd);

	if (stat(template, &sbuf) < 0) {
		if (errno == ENOENT) {
			printf("file do not exist\n");
		} else {
			printf("stat failed\n");
		}
	} else {
		printf("file exists\n");
		unlink(template);
	}
}




