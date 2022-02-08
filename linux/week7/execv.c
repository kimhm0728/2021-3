#include <stdio.h>
#include <unistd.h>

char* argv[] = {"echo", "\nMay God bless you !!!\n", NULL};

int main() {
	execv("/bin/echo", argv);
}
