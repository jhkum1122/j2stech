#include<stdio.h>
#include<string.h>		//strlen
#include<stdlib.h>		//strlen
#include<unistd.h>		//write
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>		//inet_addr
#include<netinet/in.h>


#define MAX_SIZE 50

int db_insert();

int main(){
	int sock_desc;
	struct sockaddr_in serv_addr;
	char s_buff[MAX_SIZE],r_buff[MAX_SIZE];

	//create socket
	sock_desc = socket(AF_INET, SOCK_STREAM, 0);
	if(sock_desc == -1)
		printf("Could not create socket");

	puts("Socket created");

	bzero((char *)&serv_addr, sizeof(serv_addr));

	//prepare the sockaddr_in structure
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	serv_addr.sin_port = htons(3000);

	//Connect
	if(connect(sock_desc, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
		perror("connect failed to server. Error");
		return -1;
	}
	puts("Connected success - Please enter string");


	while(fgets(s_buff, MAX_SIZE, stdin) != NULL) {
		send(sock_desc, s_buff, strlen(s_buff), 0);

		if(recv(sock_desc, r_buff, MAX_SIZE, 0) == 0)
			perror("could not create thread");
		else
			fputs(r_buff, stdout);

		bzero(r_buff, MAX_SIZE);	//to clean buffer -->IMP otherwis previous word characters also came

	}

	close(sock_desc);

	return 0;
}
