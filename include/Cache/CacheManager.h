#ifndef CACHEMANAGER_H
#define CACHEMANAGER_H
#include "LRUCache.h"
#include "../SearchEngineServer/Configuration.h"
#include <pthread.h>
#include <string.h>

class CacheManager
{
public:
    static CacheManager* getCachemanager();
    static void init();
    static void destroy();
    void initCache(size_t threadNum,string filename1,string  filename2);
    
    //从磁盘文件中读取缓存信息
    LRUCache& getKeyWordCache(int);
    LRUCache& getWebPageCache(int);

    //定时更新所有的缓存
    void periodicUpdateCaches();

private:
    CacheManager();
    ~CacheManager(){}
    static CacheManager* _cmanager;
    static pthread_once_t _once;
    vector<LRUCache> _keyWordCaches;
    vector<LRUCache> _webPageCaches;
};


#endif