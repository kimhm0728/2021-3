#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main() {
	int pid, status, n;
	int fd1[2]; // 부모: 쓰기, 자식: 읽기
	int fd2[2]; // 부모: 읽기, 자식: 쓰기
	char *msg = "God bless you !!!";
	int len = strlen(msg)+1;
	char msgbuf[100]; 

	pipe(fd1);
	pipe(fd2);
	pid = fork();
	if(pid > 0) {
		close(fd1[0]);
		close(fd2[1]);
		write(fd1[1], msg, len);
		read(fd2[0], msgbuf, len);
		printf("Message by child : %s\n", msgbuf);
		wait(&status);
	}
	else if(pid == 0) {
		close(fd1[1]);
		close(fd2[0]);
		sleep(1);
		read(fd1[0], msgbuf, len);
		write(fd2[1], msgbuf, len);
		printf("Message by parent : %s\n", msgbuf);
	}
}
