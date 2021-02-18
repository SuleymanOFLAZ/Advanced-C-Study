#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

// Create a Socket for communication
int socketCreate(void){
	short hSocket;
	printf("Create the socket\n");
	hSocket = socket(AF_INET, SOCK_STREAM, 0);
	return hSocket;
}

// Bind
int bindCreatedSocket(int hSocket){
	int iRetval = -1;
	int clientPort = 12345;
	struct sockaddr_in remote = {0};
	
	/* Internet address family */
	remote.sin_family = AF_INET;

	/* Any incoming interface */
	remote.sin_addr.s_addr = htonl(INADDR_ANY);
	remote.sin_port = htons(clientPort);

	iRetval= bind(hSocket, (struct sockaddr *)&remote, sizeof(remote));

	return iRetval;
}

// Try to connect with server
int socketConnect(int hSocket){
	int iRetval = -1;
	int serverPort = 12345;
	struct sockaddr_in remote = {0};
	
	remote.sin_family = AF_INET;
	remote.sin_addr.s_addr = inet_addr("127.0.0.1");
	remote.sin_port = htons(serverPort);

	iRetval= connect(hSocket, (struct sockaddr *)&remote, sizeof(remote));

	return iRetval;
}

// Send the data to the server and set the timeout of 20 seconds
int socketSend(int hSocket, int *Rqst){
	int shortRetval = -1;
	struct timeval tv;
	tv.tv_sec=20; // 20 Sens Timeout
	tv.tv_usec=0;

	if(setsockopt(hSocket, SOL_SOCKET, SO_SNDTIMEO, (char *)&tv, sizeof(tv)) < 0){
		printf("Time Out");
		return -1;
	}

	shortRetval = send(hSocket, Rqst, sizeof(int), 0);
	return shortRetval;
}


// Receive the data from the server
int socketReceive(int hSocket, int *Rsp){
	int shortRetval = -1;
	struct timeval tv;
	tv.tv_sec=20; // 20 Sens Timeout
	tv.tv_usec=0;

	if(setsockopt(hSocket, SOL_SOCKET, SO_RCVTIMEO, (char *)&tv, sizeof(tv)) < 0){
		printf("Time Out");
		return -1;
	}

	shortRetval = recv(hSocket, Rsp, sizeof(int), 0);
	return shortRetval;
}