#ifndef ACCEPTOR_H
#define ACCEPTOR_H
#include "Socket.h"
#include "InetAddress.h"

class Acceptor
{

private:
    Socket _sock;
    InetAdress _servAddr;

public:
    Acceptor(const string &,unsigned short);
    void ready();
    int accept();
    int fd()
    {
        return _sock.fd();

    }

private:
    //设置复用地址
    void setReuseAddr();
    //设置复用端口
    void setReusePort();
    void bind();
    void listen();

};

#endif