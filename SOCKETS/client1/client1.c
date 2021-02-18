#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#include "sockfunc.h"

int main(int argc, char *argv[]){
	int hSocket = 0, act = 0, value= 0, send_val = 0;

	//Create Socket
	hSocket = socketCreate();
	if(hSocket == -1){
		printf("Could not create socket ");
		return 1;
	}
	printf("Socket Created.\n");

	printf("What do you want with data that in the server?\n");
	printf("  1 - Increase the data by 1\n  2 - Decrease the data by 1\n  3 - Iitialize it to the value that will be entered\n");
	printf(" Your select : \n");
	scanf("%i", &act);

	if(act == 3){
		printf("Please enter an integer value to sent to the server.\n");
		scanf("%i", &send_val);
	}

	//Connnect to remote server
	if(socketConnect(hSocket) < 0){
		perror("Connect Failed.");
		return 1;
	}
	printf("Successfully connected with server.\n");

	socketSend(hSocket, &act);

	if(act == 3){
		socketSend(hSocket, &send_val);
		printf("%i sended to server\n", send_val);
	}

	//Recieve data from server
	socketReceive(hSocket, &value);

	printf("Data readed from server %d\n", value);

	close(hSocket);

	return 0;
}
