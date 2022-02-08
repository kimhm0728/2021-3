#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main(int argc, char *argv[]) {
	int sock_fd, new_fd, bytes;
	struct sockaddr_in seraddr;
	char *snddata, rcvdata[1024];

		snddata = argv[2];
		sock_fd = socket(AF_INET, SOCK_STREAM, 0);

		memset(&seraddr, 0, sizeof(seraddr));
		seraddr.sin_family = AF_INET;
		seraddr.sin_addr.s_addr = inet_addr(argv[1]);
		seraddr.sin_port = htons(5050);
		connect(sock_fd, (struct sockaddr *)&seraddr, sizeof(seraddr));
		send(sock_fd, snddata, strlen(snddata), 0);
		printf("Received: ");

		bytes = recv(sock_fd, rcvdata, 1024, 0);
		rcvdata[bytes] = '\0';
		printf("%s\n", rcvdata);
		close(sock_fd);
}
