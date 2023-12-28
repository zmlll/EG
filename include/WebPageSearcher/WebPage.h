#ifndef WEBPAGE_H
#define WEBPAGE_H

#include <string>
#include <map>
#include <vector>
#include "Configuration.h"
#include "Jieba.hpp"
using namespace std;

class WebPage
{
private:
    const static int TOPK_NUMBER =20;
    int _docId;
    string _docTitle;
    string _docUrl;
    string _docContent;
    //文档摘要，需自动生成，不是固定的
    string _docSummary;
    vector<string> _topWords;
    //保存每篇文档的所有词语和词频，不包括停用词
    map<string,int> _wordsMap;


public:
    WebPage(string& doc,Configuration &config,WordSegmentation& jieba);

    int getDocId();

    string getTile();

    string summary(const vector<string> &queryWords);

    map<string,int> &getWordsMap();

    void processDoc(const string &doc,Configuration &config,WordSegmentation&);

    void calcTopK(vector<string>& wordsVec,int k,set<string>& stopWordList);

    friend bool operator==(const WebPage &lhs,const WebPage &rhs);
    friend bool operator<(const WebPage &lhs,const WebPage &rhs);

    


};





















#endif