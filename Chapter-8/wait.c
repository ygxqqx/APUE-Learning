#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void pr_exit(int status) {
	if (WIFEXITED(status)) {
		printf("normal termination, exit status = %d\n", WEXITSTATUS(status));
	} else if (WIFSIGNALED(status)) {
		printf("abnormal termination, signal number = %d%s\n", WTERMSIG(status),
#ifdef WCOREDUMP
			WCOREDUMP(status) ? "(core file gennerated)" : "");
#else
			"");
#endif					
	} else if (WIFSTOPPED(status)) {
		printf("child stopped, signal number = %d\n", WSTOPSIG(status));
	}
}

int main(int argc, char const *argv[]) {

	pid_t pid;
	int status;
	
	if ((pid = fork()) < 0) {
		printf("fork error\n");
	} else if (pid == 0) { // child
		exit(7);
	}
	if (wait(&status) != pid) {
		printf("wait error\n");
	}
	pr_exit(status);

	if ((pid = fork()) < 0) {
		printf("fork error\n");
	} else if (pid == 0) { // child
		abort();
	}
	if (wait(&status) != pid) {
		printf("wait error\n");
	}
	pr_exit(status);

	if ((pid = fork()) < 0) {
		printf("fork error\n");
	} else if (pid == 0) { // child
		status /= 0;
	}
	if (wait(&status) != pid) {
		printf("wait error\n");
	}
	pr_exit(status);
	return 0;
}





