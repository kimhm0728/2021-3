#include <stdio.h>
#include <unistd.h>

int main() {
	printf("real user id: %d\n", getuid());
	printf("effective user id: %d\n", geteuid());
}
