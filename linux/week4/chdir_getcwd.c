#include <stdio.h>
#include <unistd.h>
#define BUF_SIZE 64

int main(int argc, char* argv[]) {
	char buf[BUF_SIZE];
	getcwd(buf, BUF_SIZE);
	printf("%s\n", buf);
	chdir(argv[1]);
	getcwd(buf, BUF_SIZE);
	printf("%s\n", buf);
}
