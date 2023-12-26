#ifndef TCPCONNECTION_H
#define TCPCONNECTION_H
#include "InetAddress.h"
#include "Socket.h"
#include "SocketIO.h"
#include <functional>
#include <memory>
#include <string>
#include <sstream>

using TcpConnectionPtr = std::shared_ptr<TcpConnection>;
using TcpConnectionCallback = std::function<void(const 
TcpConnectionPtr &)>;
class TcpConnection
{
private:
    Socket _sockfd;
    SocketIO _sockIO;
    const InetAddress _localAddr;
    const InetAddress _peerAddr;
    bool _isShutdownWrite;
    //EpollPoller *loop;
    TcpConnectionCallback &_onConnectionCb;
    TcpConnectionCallback &_onCloseCb;

public:
    typedef function<void(const TcpConnectionPtr&)> TcpConnectionCallback ;
    TcpConnection(int sockfd);
    ~TcpConnection();
    string receive();
    void send(const string &msg);
    //将数据交给IO线程发送
    void sendInLoop(const string &msg);
    //发送数据，并关闭连接，针对网页服务
    void sendAndClose(const string &msg);

    void shutdown();
    //设置回调函数
    void setConnectionCallback(TcpConnectionCallback cb);
    void setMessageCallback(TcpConnectionCallback cb);
    void setCloseCallback(TcpConnectionCallback cb);
    void handleConnectionCallback();
    void handleMessageCallback();
    void handleCloseCallback();
    string toString();




    



};





















#endif