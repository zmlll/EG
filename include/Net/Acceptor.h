#ifndef ACCEPTOR_H
#define ACCEPTOR_H
#include "Socket.h"
#include "InetAddress.h"


class Acceptor
{

private:
    //服务器监听Socket对象
    Socket _listensock;

    //设置服务器网络地址可重用
    void setReuseAddr(bool on);

    //设置服务器网络端口可重用
    size_t setReusePort(bool on);

    //绑定网络地址
    void bind();

    void listen();

public:
    Acceptor(int fd,const InetAddress &);
    //服务器监听准备
    void ready();
    //接收新连接
    int accept();

};
















#endif