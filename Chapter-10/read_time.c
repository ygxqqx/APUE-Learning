#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

#define MAXLINE 1024



static void sig_alrm(int signo) {
	printf("sig_alrm signo: %d\n", signo);
	kill(getpid(), SIGKILL);
}

// 当read执行超过5秒时直接返回
int main(int argc, char const *argv[]) {
	
	int n;
	char line[MAXLINE];
	if (signal(SIGALRM, sig_alrm) == SIG_ERR) {
		printf("signal(SIGALRM) error\n");
		return -1;
	}
	alarm(5);
	if ((n = read(STDIN_FILENO, line, MAXLINE)) < 0) {
		printf("read error\n");
		return -1;
	}
	alarm(0);
	write(STDOUT_FILENO, line, n);
	return 0;
}
