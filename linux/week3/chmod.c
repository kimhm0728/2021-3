#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc, char* argv[]) {
	int newmode;

	newmode = strtol(argv[2], (char**)NULL, 8);
	chmod(argv[1], newmode);
}
