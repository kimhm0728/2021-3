#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

void sigHandler(int signo) {
	printf("Child reveives signal[%d]\n", signo);
}

int main() {
	int pid, n;
	struct sigaction act;
	pid = fork();
	if(pid > 0) {
		for(n=1;n<12;n++) {
			sleep(1);
			kill(pid, n);
			printf("Parent sends signal[%d]\n", n);
		}
	}
	else if(pid == 0) {
		act.sa_handler = sigHandler;
		for(n=1;n<12;n++)
			sigaction(n, &act, NULL);
		for(;;)
			;
	}
}
