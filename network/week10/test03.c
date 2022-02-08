#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>

int main(int argc, char *argv[])
{	
	int sock = socket(PF_INET, SOCK_STREAM, 0);   
	pid_t pid = fork();
	if(pid > 0) 
		printf("file descriptor number by parent process : %d\n", sock);
	else if(pid == 0) 
		printf("file descriptor number by child process : %d\n", sock);
	close(sock);
	return 0;
}
