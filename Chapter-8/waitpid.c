#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>



int main(int argc, char const *argv[]) {
	
	pid_t pid;
	if ((pid = fork()) < 0) {
		printf("fork error\n");
	} else if (pid == 0) {
		if ((pid = fork()) < 0) {
			printf("fork error\n");
		} else if (pid > 0) {
			exit(0);
		}
		sleep(2);
		printf("second child, parent pid = %ld\n", (long)getppid());
		exit(0);
	}

	if (waitpid(pid, NULL, 0) != pid) {
		// wait for first child
		printf("waitpid error\n");
	}
	return 0;
}

