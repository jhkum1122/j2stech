#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define MAX_SIZE 50

int db_insert();

int main() { 
	int sock_desc;
	struct sockaddr_in serv_addr;
	char s_buff[MAX_SIZE], r_buff[MAX_SIZE];

	sock_desc = socket(AF_INET, SOCK_STREAM, 0);

	if(sock_desc == -1)
		printf("Couldn't create socket!\n");

	printf("Socket created\n");

	memset((char *)&serv_addr, 0x00, sizeof(serv_addr));

	//prepare the sockaddr_in structure
	//
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	serv_addr.sin_port = htons(3000);

	//connect
	if (connect (sock_desc, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
		printf("connect failed to server. Error\n");

		return -1;
	}

	printf("Connect success - Please enter String!\n");

	while(fgets(s_buff, MAX_SIZE, stdin) != NULL) {
		send(sock_desc, s_buff, strlen(s_buff), 0);

		if (recv(sock_desc, r_buff, MAX_SIZE, 0) == 0)
			printf("Couldn't create thread!\n");

		else 
			printf("recv messages : %s", r_buff);
		//to clean buff --> IMP otherwise previous word characters also came
			memset(r_buff, 0x00, MAX_SIZE);
	}

	close(sock_desc);

	return 0;
}
