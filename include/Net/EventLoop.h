#ifndef EVENTLOOP_H
#define EVENTLOOP_H
#include <vector>
#include <map>
#include "TcpConnection.h"






using namespace std;


class EventLoop
{
private:
    int _epollfd;
    int _eventfd;
    int _listenfd;
    bool _isLooping;
    typedef vector<struct epoll_event> EventList;
    EventList _eventList;
    typedef map<int,TcpConnectionPtr> ConnectionMap;
    ConnectionMap _connMap;
    typedef TcpConnection::TcpConnectionCallback EpollCallback;
    EpollCallback &_onConnectionCb;
    EpollCallback &_onMessageCb;
    EpollCallback &_onCloseCb;
    void doPendingFunctors();
    void waitEpollfd();
    void handleConnection();
    void handleMessage(int peerfd);

public:
    typedef std::function<void()> Functor;

private:
    vector<Functor> _pendingFunctors;

public:
    EventLoop(int listenfd);
    ~EventLoop();
    void loop();
    void unloop();
    void runInloop(const Functor &cb);
    void wakeup();
    void handleRead();
    void setConnectionCallback(EpollCallback cb);
    void setMessageCallback(EpollCallback cb);
    void setCloseCallback(EpollCallback cb);
    void 

    
    






};


















#endif