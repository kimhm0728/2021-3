#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void alarmHandler(int signo) {
	printf("Wake up!!!\n");
	exit(0);
}

int main() {
	int sec = 0;
	signal(SIGALRM, alarmHandler);
	alarm(5);
	for(;;) {
		sleep(1);
		printf("%d sec\n", ++sec);
	}
}
