#ifndef SOCKET_H
#define SOCKET_H
#include <sys/socket.h>
#include <stdio.h>
#include <unistd.h>

class Socket
{
public:
    Socket();
    explicit Socket(int fd);
    int fd() const;
    void shutdownWrite();
    ~Socket();


private:
    int _sockfd;

};














#endif