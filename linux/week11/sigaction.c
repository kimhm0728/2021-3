#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int sec = 0;
struct sigaction new, old;

void alarmHandler(int signo) {
	if(sec == 4) sigaction(SIGALRM, &old, NULL);
}

int main() {
	new.sa_handler = alarmHandler;
	sigaction(SIGALRM, &new, &old);
	for(;;) {
		alarm(1);
		printf("%d sec\n", ++sec);
		sleep(1);
	}
}
