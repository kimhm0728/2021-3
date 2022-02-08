#include <stdio.h>
#include <sys/uio.h>
#define BUF_SIZE 100

int main(int argc, char *argv[])
{
	struct iovec vec[3];
	char buf1[BUF_SIZE]={0,};
	char buf2[BUF_SIZE]={0,};
	char buf3[BUF_SIZE]={0,};
	int str_len;

	vec[0].iov_base=buf1;
	vec[0].iov_len=10;
	vec[1].iov_base=buf2;
	vec[1].iov_len=9;
	vec[2].iov_base=buf3;
	vec[2].iov_len=BUF_SIZE;

	readv(0, vec, 3);
	printf("First message: %s \n", buf1);
	printf("Second message: %s \n", buf2);
	printf("Third message: %s", buf3);
	return 0;
}

