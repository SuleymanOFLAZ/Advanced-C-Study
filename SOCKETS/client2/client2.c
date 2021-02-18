#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#include "sockfunc.h"

int main(int argc, char *argv[]){
	int hSocket = 0, act = 2, value= 0;

	//Create Socket
	hSocket = socketCreate();
	if(hSocket == -1){
		printf("Could not create socket ");
		return 1;
	}
	printf("Socket Created.\n");

	//Connnect to remote server
	if(socketConnect(hSocket) < 0){
		perror("Connect Failed.");
		return 1;
	}
	printf("Successfully connected with server.\n");

	// Send data to server
	socketSend(hSocket, &act);

	//Recieve data from server
	socketReceive(hSocket, &value);

	printf("Data readed from server %d\n", value);

	close(hSocket);

	return 0;
}