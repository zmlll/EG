#ifndef KEYRECOMMANDER_H
#define KEYRECOMMANDER_H

#include <string>
#include <queue>
#include <vector>
#include <set>
#include "TcpConnection.h"
using namespace std;

class Keyrecommander
{
private:
    //等查询的单词
    string _queryWord;

    //与客户端进行连接的文件描述符
    TcpConnectionPtr _conn;

    //保存候选结果集的优先级队列
    priority_queue<MyResult,vector<MyResult>,MyCompare> _resultQue;

public:
    Keyrecommander(string& query,const TcpConnectionPtr&);

    //执行查询
    void execute();

    //查询索引
    void queryIndexTable();

    //进行计算
    void statistic(set<int>& iset);

    //计算最小编辑距离
    int distance(const string& rhs);

    //响应客户端的请求
    void response();


};
























#endif