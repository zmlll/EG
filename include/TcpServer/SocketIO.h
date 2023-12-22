#ifndef SOCKETIO_H
#define SOCKETIO_H
#include <sys/socket.h>
#include <sys/types.h>
#include <stdio.h>
#include <errno.h>


class SocketIO
{
public:
    SocketIO(int);
    int recvn(char* ,int);
    int readline(char*,int);
    int sendn(const char* ,int);
    int readjson(char*,int); 

private:
    int fd;
};
#endif