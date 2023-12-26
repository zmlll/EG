#ifndef INETADDRESS_H
#define INETADDRESS_H
#include <sys/socket.h>
#include <string>
using namespace std;

class InetAddress
{
private:
    struct sockaddr_in &_addr;

public:
    InetAddress(unsigned short);
    InetAddress(const char *ip,unsigned short);
    InetAddress(const struct sockaddr_in &addr);
    string ip() const;
    unsigned short port() const;


};
















#endif