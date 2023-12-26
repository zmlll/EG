#ifndef SOCKET_H
#define SOCKET_H

#include <sys/socket.h>

class Socket
{
public:
    Socket();
    Socket(int sockfd);
    //设置fd为非阻塞模式
    void nonblock();
    //关闭套接字的写端
    void shutdownWrite();
    //返回sockfd
    int fd();

private:
    int _sockfd;

};

#endif