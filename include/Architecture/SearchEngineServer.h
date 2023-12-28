#ifndef SEARCHENGINESERVER_H
#define SEARCHENGINESERVER_H
#include "TcpServer.h"
#include "ThreadPool.h"
#include "WebPageSearcher.h"
#include "KeyRecommander.h"
#include "ProtocolParser.h"

class SearchEngineServer
{
private:
    TcpServer _tcpServer;
    ThreadPool _pool;
    Keyrecommander _keyrecommander;
    WebPageSearcher _webSearcher;
    ProtocolParser _protocolParse;

public:
    SearchEngineServer(const string& ip,short port);
    void start();
    void onConnection(const TcpConnectionPtr& conn);
    void onMessage(const TcpConnectionPtr& conn);
    void onClose(const TcpConnectionPtr& conn);
    void doTaskThread(const TcpConnectionPtr& conn,const string& msg);

};





















#endif