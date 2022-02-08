#include <stdio.h>
#include <arpa/inet.h>

int main(int argc, char* argv[]) {
	printf("==================================\n");
	char* addr = "192.168.3.4";
	struct sockaddr_in inet;

	if(!inet_aton(addr, &inet.sin_addr))
		printf("Error occured!\n");
	else 
		printf("Network ordered integer addr: %#x\n", inet.sin_addr.s_addr);

	char* str_ptr = inet_ntoa(inet.sin_addr);
	printf("Dotted-Decimal notation: %s\n", str_ptr);
	printf("==================================\n");
	return 0;
}
