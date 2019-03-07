#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

void *connect_handler(void *);

int main (int argc, char *argv[]) {
	int socket_desc, client_sock, c, *new_sock;
	struct sockaddr_in server, client;

	//create socket
	socket_desc = socket(AF_INET, SOCK_STREAM, 0);
	if (socket_desc == -1)
		printf("Could not create socket");

	printf("Socket created\n");

	//prepare the sockaddr_in structure
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(3000);

	//bind
	if (bind(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0) {
		printf("bind failed. Error\n");
		return 1;
	}

	printf("Bind done\n");

	//listen
	listen(socket_desc, 3);

	//Accept and incoming connection
	printf("Waiting for incoming connection!\n");

	c = sizeof(struct sockaddr_in);

	while (client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t *) &c)) {
		printf("Connection accepted\n");

		pthread_t sniffer_thread;
		new_sock = malloc(1);
		*new_sock = client_sock;

		if (pthread_create(&sniffer_thread, NULL, connect_handler, (void *) new_sock) < 0) {
			printf("Couldn't create thread\n");

			return 1;
		}

		printf("Handler assigned\n");
	}

	if(client_sock < 0) {
		printf("accept failed\n");

		return 1;
	}

	return 0;
}


void *connect_handler(void *socket_desc) {
	//Get the socket descriptor
	int n, sock = *(int *)socket_desc;
	char send_buff[100], client_message[20000];

	while((n = recv(sock, client_message, 20000, 0)) > 0) {
		//kjh db insert
		//
		//
		send(sock, client_message, n, 0);

	}

	close(sock);

	if (n == 0)
		printf("Client Disconnected!\n");
	else
		printf("recv failed\n");

	return 0;
}
