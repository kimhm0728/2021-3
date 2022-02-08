#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
	pid_t ret;
	int status;

	printf("Current PID = %d\n", getpid());
	ret = fork();

	if(ret == 0) // Child Process
		printf("[%d]Parent PID = %d\n", getpid(), getppid());
	else if(ret > 0) { // Parent Process
		wait(&status);
		printf("[%d]Child PID = %d\n", getpid(), ret);
	}
	else
		printf("Error");
}
