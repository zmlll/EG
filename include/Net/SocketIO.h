#ifndef SOCKETIO_H
#define SOCKETIO_H
#include <string>
using namespace std;

class SocketIO
{
private:
    int _sockfd;

    //查看内核缓冲区，并获取数据
    size_t recvPeek(char *buf,size_t count);

public:
    SocketIO();
    SocketIO(int sockfd);
    //从对端读取1行数据
    size_t readline(char *buf,size_t max);
    //从对端读取count个字节的数据
    size_t readn(char* buf,size_t count);
    //从本地发送数据
    size_t writen(const char* buf,size_t count);

};

#endif