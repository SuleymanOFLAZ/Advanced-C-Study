#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#include "sockfunc.h"

void inc_data(int *x);
void dec_data(int *x);

int main(int argc, char *argv[]){
	int value = 0, act = 0, rcv_int= 0;
	int sock_desc;
	int clientLen = 0;
	int sock = 0;

	struct sockaddr_in client;

	//Create socket
	sock_desc = socketCreate();
	if(sock_desc == -1){
		printf("Could not create socket ");
		return 1;
	}
	printf("Socket Created.\n");

	//Bind
	if(bindCreatedSocket(sock_desc) < 0){
		perror("Bind Failed!");
		return 1;
	}
	printf("Bind DONE! \n");

	//Listen
	listen(sock_desc, 3);

	//Accept and incoming connection
	while(1){
		printf("Waiting for incoming connections...\n");
		clientLen = sizeof(struct sockaddr_in);

		// Accept connection from any incoming client
		sock = accept(sock_desc, (struct sockaddr*)&client, (socklen_t *)&clientLen);

		if(sock < 0){
			perror("Accept Failed.");
			return 1;
		}
		printf("Connection Accepted.\n");

		//Receive a reply from the client
		if(recv(sock, &act, sizeof(int), 0) < 0){
			printf("Recv Failed.");
			return 1;
		}
		printf("Data received: %i\n", act);


		/*----- Actions -----*/

		if(act == 1){
			inc_data(&value);
		}
		else if(act == 2){
			dec_data(&value);
		}
		else if(act == 3){
			if(recv(sock, &rcv_int, sizeof(int), 0) < 0){
				printf("Recv Failed.");
				return 1;
			}

			value = rcv_int;
		}
		else{
			printf("The Commant did't Recognize !!!\n");
		}
		/* ------------------*/

		//Send Some Data
		if(send(sock, &value, sizeof(int), 0) < 0){
			printf("Send Failed");
			return 1;
		}
		printf("Data sended\n");

		close(sock);

		sleep(1);
	}
}

void inc_data(int *x){
	*x += 1;
}

void dec_data(int *x){
	*x -= 1;
}
