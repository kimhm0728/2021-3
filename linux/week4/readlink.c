#include <stdio.h>
#include <unistd.h>

char buf[1024];

int main(int argc, char* argv[]) {
	readlink(argv[1], buf, 1024);
	printf("%s\n", buf);
}
