#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
	int fd;
	    fd = open(argv[1], O_RDONLY);
	    if(fd > 0) {
		    printf("open() & close() %s !!!\n", argv[1]);
		    close(fd);
	    }
	    else 
		    printf("open() fail\n");
}
