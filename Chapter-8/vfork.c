#include <unistd.h>
#include <stdio.h>

int globvar = 6;

int main(int argc, char const *argv[]) {
	
	int var;
	pid_t pid;
	var = 88;
	printf("before vfork\n");

	if ((pid = vfork()) < 0) {
		printf("vfork error\n");
	} else if (pid == 0) {
		globvar++;
		var++;
		_exit(0);
	}
	
	// parent continues here
	printf("pid = %ld, glob = %d, var = %d\n", (long)getpid(), globvar, var);

	return 0;
}
