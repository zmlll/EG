#ifndef CACHEMANAGER_H
#define CACHEMANAGER_H

#include <vector>
#include <string>
#include "LRUCache.h"
using namespace std;

class CacheManager
{

private:
    //缓存的数量与线程个数一致
    vector<Cache> _cacheList;

public:
    //从磁盘文件中读取缓存信息
    void initCache(size_t,const string& filename);

    //获取某个缓存
    LRUCache& getCache(size_t idx);

    //定时更新所有的缓存
    void periodicUpdateCahes();








};
























#endif