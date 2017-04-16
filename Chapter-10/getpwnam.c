#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <pwd.h>
#include <uuid/uuid.h>
#include <string.h>

static void my_alarm(int signo) {

	struct passwd *rootptr;
	printf("in signal handler\n");
	if ((rootptr = getpwnam("luoxupan")) == NULL) {
		printf("getpwnam(luoxupan)error \n");
		return ;
	}
	alarm(1);
}

int main(int argc, char const *argv[]) {

	struct passwd *ptr;
	signal(SIGALRM, my_alarm);
	alarm(1);
	for ( ; ; ) {

		if ((ptr = getpwnam("root")) == NULL) {
			printf("getpwnam error \n");
			return 0;
		}

		if (strcmp(ptr->pw_name, "root") != 0) {
			printf("return value corrupted!, pw_name = %s\n", ptr->pw_name);
		} else {
			printf("return value correct!, pw_name = %s, pw_dir = %s\n", ptr->pw_name, ptr->pw_dir);
		}
	}
	return 0;
}


