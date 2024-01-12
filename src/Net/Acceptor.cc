// #include "../../include/Net/Acceptor.h"

// Acceptor::Acceptor(const string& ip,unsigned short port)
// :_sock(),_servAddr(ip,port){}




#include "../../include/Net/Acceptor.h"

Acceptor::Acceptor(const string& ip,unsigned short port):_sock(),_servAddr(ip,port){}
Acceptor(int fd,const InetAddress &);

Acceptor::Acceptor()