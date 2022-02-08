#include <stdio.h>
#include <unistd.h>

char* argv[] = {"echo", "\nMay God bless you !!!\n", NULL};

int main() {
	execvp("echo", argv);
}
