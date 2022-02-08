#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
	if(access(argv[1], R_OK) != -1)
		printf("%s is readable!\n", argv[1]);
	if(access(argv[1], W_OK) != -1)
                printf("%s is writable!\n", argv[1]);
        if(access(argv[1], X_OK) != -1)
                printf("%s is executable!\n", argv[1]);

}
