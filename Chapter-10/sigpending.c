#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <errno.h>

static void sig_quit(int);

int main(int argc, char const *argv[]) {
	
	sigset_t newmask, oldmask, pendmask;
	if (signal(SIGQUIT, sig_quit) == SIG_ERR) {
		printf("can`t catch SIGQUIT\n");
		exit(1);
	}
	sigemptyset(&newmask);
	sigaddset(&newmask, SIGQUIT);

	// 对newmask进行SIG_BLOCK操作，返回oldmask
	if (sigprocmask(SIG_BLOCK, &newmask, &oldmask) < 0) {
		printf("SIG_BLOCK error\n");
		exit(1);
	}

	sleep(5);

	if (sigpending(&pendmask) < 0) {
		printf("sigpending error\n");
		exit(1);
	}
	if (sigismember(&pendmask, SIGQUIT)) {
		printf("SIGQUIT pending\n");
	}
	if (sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0) {
		printf("SIG_SETMASK error\n");
		exit(1);
	}
	printf("SIG_SETMASK unblocked\n");
	sleep(2);
	return 0;
}


static void sig_quit(int signo) {
	printf("caught SIGQUIT\n");
	// A SIG_DFL resets the default action
	if (signal(SIGQUIT, SIG_DFL) == SIG_ERR) {
		printf("can`t reset SIGQUIT\n");
		exit(1);
	}
}







