#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define MAX_SIZE 50

int main() {

	int sock_desc;
	struct sockaddr_in serv_addr;
	char s_buff[MAX_SIZE], r_buff[MAX_SIZE];

	sock_desc = socket(AF_INET, SOCK_STREAM, 0);

	if (sock_desc == -1)
		printf("Couldn't create socket\n");

	printf("Socket created\n");

	bzero((char *)&serv_addr , sizeof(serv_addr));

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	serv_addr.sin_port = htons(8080);

	if(connect(sock_desc, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {

		printf("Connect failed to server. Error\n");
		return -1;
	}

	printf("Connected success - Enter string\n");

	while (fgets(s_buff, MAX_SIZE, stdin) != NULL) {
		send(sock_desc, s_buff, strlen(s_buff), 0);

		if(recv(sock_desc, r_buff, MAX_SIZE, 0) == 0)
			printf("Couldn't create thread!!\n");
		else
			printf("%s", r_buff);

		bzero(r_buff, MAX_SIZE);

	}

	close(sock_desc);

	return 0;
}
