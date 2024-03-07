#ifndef LRUCACHE_H
#define LRUCACHE_H
#include <unordered_map>
#include <list>
#include <string>
#include "CandidateResult.h"
#include "../time.h"
#include "../ProtocolParser.h"
using nlohmann::json;
using namespace std;



class LRUCache
{
public:
    friend class CacheManger;
    friend class KeyRecommander;
    LRUCache(int capacity =3):_capacity(capacity),_isUpdating(false){}
    LRUCache(const LRUCache& cache);

    bool get(string key,json& value);
    void put(string key,json& value);

    void writeToFile(string filename);
    void writeToFile(string filename,string key,json value);
    void readFromFile(string filename);
    void update(const LRUCache&);
    void show();

    list<pair<string,json>> &getPendingUpdateList();
    list<pair<string,json>> &getResultList();



private:
    //采用hashTable进行查找
    unordered_map<string,list<pair<string,json>>::iterator> _umap;
    //保存键值对
    list<pair<string,json>> _resultList;
    //等待更新的节点信息
    list<pair<string,json>> _pendingUpdateList;
    int _capacity;
    bool _isUpdating;

};



#endif