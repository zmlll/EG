#ifndef LRUCACHE_H
#define LRUCACHE_H
#include <unordered_map>
#include <list>
#include <string>
using namespace std;


class LRUCache
{
private:
    //采用hashTable进行查找
    unordered_map<string,string> _hashMap;

    //保存键值对
    list<string,string> _resultsList;

    //等待更新的节点信息
    list<string,string> _pendingUpdateList;

    //缓存节点的容量
    int _capacity;

public:
    
    LRUCache(int num = 100);

    LRUCache(const Cache& cache);

    //往缓存中添加数据
    void addElement(const string& key,const string& value);

    //从文件中读取缓存信息
    void readFromFile(const string & filename);

    //将缓存信息写入文件中
    void writeToFile(const string& filename);

    //获取待更新的节点List
    list<string,string>& getPendingUpdateList();

    //更新缓存信息
    void update(const Cache& rhs);











};




















#endif