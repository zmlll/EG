#ifndef DICTPRODUCER_H
#define DICTPRODUCER_H
#include <string>
#include <vector>
#include <map>

using namespace std;

class DictProducer
{
public:
    //构造函数
    DictProducer(const string& dir);
    //构造函数，用于中文处理
    DictProducer(const string & dir,SplitTool * splitTool);
    //创建英文词典
    void buildEnDdict();
    //创建中文词典
    void buildCnDict();
    //将词典写入文件
    void storeDict(const char* filepath);
    //查看文件路径，作为测试用
    void showFiles() const;
    //查看词典，作为测试用
    void showDict() const;
    //获取文件的绝对路径
    void getFiles();
    //存储某个单词
    void pushDict(const string& word);

private:
    //语料库文件的绝对路径集合
    vector<string> _files;

    //词典
    vector<pair<string,int>> _dict;

    //分词工具
    SplitTool * splitTool;

    //词典索引
    Map<string,set<int>> _index;

};



















#endif