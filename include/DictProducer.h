#ifndef DICTPRODUCER_H
#define DICTPRODUCER_H
#include <vector>
#include <string>
#include "SplitTool.h"
#include <map>
using namespace std;


//词典创建类
class DictProducer:SplitTool
{

private:
    //语料库文件的绝对路径集合
    vector<string> _files;
    //词典
    vector<pair<string,int>> _dict;
    //分词工具
    SplitTool* _splitTool;

    //词典索引
    map<string,set<int>> _index;

    //获取文件的绝对路径
    void getFiles();

    //存储某个单词
    void pushDict(const string &word);

public:
    //构造函数
    DictProducer(const string &dir);

    //构造函数，专为中文处理
    DictProducer(const string &dir,SplitTool* SplitTool);

    //创建英文字典
    void buildEnDict();

    //创建中文字典
    void buildCnDict();

    //将词典写入文件
    void storeDict(const char * filepath);

    //查看文件路径，作为测试用
    void showFiles() const;

    //查看词典，作为测试用
    void showDict() const;

};





















#endif
