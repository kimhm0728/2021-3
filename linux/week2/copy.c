#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
	int fd1, fd2, len;
	char buf[1024];

	fd1 = open(argv[1], O_RDONLY);
	    printf("fd1 = %d\n", fd1);
	fd2 = open(argv[2], O_WRONLY|O_CREAT, 0666);
	    printf("fd2 = %d\n", fd2);
	do {
	    len = read(fd1, buf, 1024);
	    write(fd2, buf, len);
	}while(len);

	close(fd1);
	close(fd2);
}
