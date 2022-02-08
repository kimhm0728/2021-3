#include <stdio.h>
#include <unistd.h>

int main() {
	execl("/bin/echo", "echo", "\nMay God bless you !!!\n", NULL);
}
