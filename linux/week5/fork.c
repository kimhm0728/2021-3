#include <stdio.h>
#include <unistd.h>

int main() {
	pid_t ret;

	ret = fork();
	if(ret == 0) // Child Process
		while(1) printf("X");
	else if(ret > 0) // Parent Process
		while(1) printf("O");
	else
		printf("Error");
}
