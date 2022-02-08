/*** arg.c ***/

#include <stdio.h>

int main(int argc, char* argv[]) {
	int n;

	printf("My input parameters(argv) are : \n");
	for(n=0;n<argc;n++)
		printf("    %2d:  '%s'\n", n, argv[n]);  
}
