#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main() {
	int sock_fd, new_fd, bytes, len;
	struct sockaddr_in seraddr, cliaddr;
	char data[1024];

		sock_fd = socket(AF_INET, SOCK_STREAM, 0);

		memset(&seraddr, 0, sizeof(seraddr));
		seraddr.sin_family = AF_INET;
		seraddr.sin_addr.s_addr = htonl(INADDR_ANY);
		seraddr.sin_port = htons(5050);
		bind(sock_fd, (struct sockaddr *)&seraddr, sizeof(seraddr));

		listen(sock_fd, 10);
		len = sizeof(cliaddr);
		while(1) {
			new_fd = accept(sock_fd,
					(struct sockaddr *)&cliaddr, &len);
			bytes = recv(new_fd, data, 1024, 0);
			send(new_fd, data, bytes, 0);
			close(new_fd);
		}
		close(sock_fd);
}
