#include <stdio.h>
#include <unistd.h>

int main() {
	execlp("echo", "echo", "\nMay God bless you !!!\n", NULL);
}
