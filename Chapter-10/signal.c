#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

static void sig_usr(int);

int main(int argc, char const *argv[]) {
	
	if (signal(SIGUSR1, sig_usr) == SIG_ERR) {
		printf("can`t catch SIGUSR1\n");
	}
	if (signal(SIGUSR2, sig_usr) == SIG_ERR) {
		printf("can`t catch SIGUSR2\n");
	}
	for ( ; ; ) {
		pause();
	}
	return 0;
}

static void sig_usr(int signo) {

	if (signo == SIGUSR1) {
		printf("received SIGUSR1\n");
	} else if (signo == SIGUSR2) {
		printf("received SIGUSR2\n");
	} else {
		printf("received signal %d\n", signo);
	}
}
