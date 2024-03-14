#include "../../include/Cache/CacheManager.h"

CacheManager* CacheManager::_cmanager = nullptr;
pthread_once_t CacheManager::_once = PTHREAD_ONCE_INIT;

CacheManager* CacheManager::getCachemanager()
{
    pthread_once(&_once,init);
    return _cmanager;
}

void CacheManager::init()
{
    _cmanager = new CacheManager();
    atexit(destroy);
}

void CacheManager::destroy()
{
    if(_cmanager)
    {
        LRUCache& lru1 = _cmanager->getKeyWordCache(0);
        LRUCache& lru2 = _cmanager->getWebPageCache(0);

        delete _cmanager;
        _cmanager = nullptr;
    }
}


void CacheManager::initCache(size_t threadNum,string wordCacheFile,string webCacheFile)
{
    _keyWordCaches.resize(threadNum);
    _webPageCaches.resize(threadNum);

    for(auto it = _keyWordCaches.begin();it!=_keyWordCaches.end();++it)
    {
        it->readFromFile(wordCacheFile);
    }
    for(auto it = _webPageCaches.begin();it!=_webPageCaches.end();++it)
    {
        it->readFromFile(webCacheFile);
    }
}

LRUCache& CacheManager::getKeyWordCache(int idx)
{
    return _keyWordCaches[idx];
}

LRUCache& CacheManager::getWebPageCache(int idx)
{
    return _webPageCaches[idx];
}

void CacheManager::periodicUpdateCaches()
{
    map<string,string>& cmap = Configuration::getInstance()->getConfigMap();

    LRUCache& mainKeyCache = _keyWordCaches[0];
    for(int idx = 0;idx!= _keyWordCaches.size();++idx)
    {
        auto& pendingUpdateList = _keyWordCaches[idx].getPendingUpdateList();
        for(auto& iter:pendingUpdateList)
        {
            mainKeyCache.put(iter.first,iter.second);
        }
        pendingUpdateList.clear();
    }

    for(int idx = 1;idx != _keyWordCaches.size();++idx)
    {
        _keyWordCaches[idx].update(mainKeyCache);
    }

    LRUCache &mainWebCache = _webPageCaches[0];
    for(int idx =0;idx!= _webPageCaches.size();++idx)
    {
        auto& pendingUpdateList = _webPageCaches[idx].getPendingUpdateList();
        for(auto& iter :pendingUpdateList)
        {
            mainWebCache.put(iter.first,iter.second);
        }
        pendingUpdateList.clear();
    }

    mainWebCache.writeToFile(cmap["webpagecache_path"]);
    for(int idx = 1;idx != _webPageCaches.size();++idx)
    {
        _webPageCaches[idx].update(mainWebCache);
    }


}


CacheManager::CacheManager()
{
    map<string,string>& cmap = Configuration::getInstance()->getConfigMap();
    size_t threadNum = stoi(cmap["threads_num"]);
    initCache(threadNum,cmap["ketwordcache_path"],cmap["webpagecache_path"]);
}



