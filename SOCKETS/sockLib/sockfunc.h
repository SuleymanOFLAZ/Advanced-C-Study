#ifndef SOCKFUNC_H_INCLUDED
#define SOCKFUNC_H_INCLUDED

int socketCreate(void);
int bindCreatedSocket(int hSocket);
int socketConnect(int hSocket);
int socketSend(int hSocket, int *Rqst);
int socketReceive(int hSocket, int *Rsp);

#endif // SOCKFUNC_H_INCLUDED