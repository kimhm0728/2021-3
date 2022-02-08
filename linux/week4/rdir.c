#include <stdio.h>
#include <dirent.h>

int main(int argc, char* argv[]) {
	DIR *dir;
	struct dirent *dp;

	dir = opendir(argv[1]);
	while(dp = readdir(dir))
		printf("%d : %s\n", (int)dp->d_ino, dp->d_name);
	closedir(dir);
}
