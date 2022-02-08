#include <stdio.h>
#include<sys/stat.h>

int main(int argc, char* argv[]) {
	struct stat info;

	stat(argv[1], &info);
	printf("File name: %s\n", argv[1]);
	printf("Device number: %d\n", (unsigned int)info.st_dev);
        printf("Inode number: %d\n", (int)info.st_ino);
        printf("File mode: %o\n", info.st_mode);
	if(S_ISREG(info.st_mode))
		printf("\t%s is a regular file !!!\n", argv[1]);
	if(S_ISDIR(info.st_mode))
		printf("\t%s is a directory file !!!\n", argv[1]);

}
