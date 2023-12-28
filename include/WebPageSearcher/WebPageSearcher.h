#ifndef WEBPAGESEARCHER_H
#define WEBPAGESEARCHER_H

#include <string>
#include "TcpConnection.h"
using namespace std;


class WebPageSearcher
{

private:
    //查询关键词
    string _sought;
    TcpConnectionPtr _conn;

public:
    WebPageSearcher(string keys,const TcpConnectionPtr& conn);

    void doQuery();

};

#endif