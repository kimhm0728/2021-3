#include <stdio.h>
#include <unistd.h>

int main() {
	pid_t ret;

	ret = fork();
	if(ret == 0) // Child Process
		printf("[%d]My PPID = %d\n", getpid(), getppid());
	else if(ret > 0) { // Parent Process
		printf("[%d]My PPID = %d\n", getpid(), getppid());
		printf("[%d]My CPID = %d\n", getpid(), ret);
	}
	else
		printf("Error");
}
