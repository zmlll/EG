#ifndef TCPSERVER_H
#define TCPSERVER_H
#include "Acceptor.h"
#include "EventLoop.h"
class TcpServer
{
private:
    Acceptor _acceptor;
    EventLoop _epollfd;
public:
    typedef TcpConnection::TcpConnectionCallback TcpServerCallback;
    TcpServer(unsigned short port);
    TcpServer(const char *ip,unsigned short port);
    void start();
    void stop();
    void setConnectionCallback(TcpServerCallback cb);
    void setMessageCallback(TcpServerCallback cb);
    void setCloseCallback(TcpServerCallback cb);

};

#endif