#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char* argv[]) {
	if(argc != 2) {
		printf("argument error\n");
		exit(-1);
	}
	int fd = open(argv[1], O_RDONLY);
	char buf;

	if(fd == -1) {
		printf("open() error\n");
		exit(-1);
	}
	while(read(fd, &buf, 1))
		write(1, &buf, 1);  
	close(fd);
}
