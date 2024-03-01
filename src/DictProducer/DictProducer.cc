#include "../../include/DictProducer/DictProducer.h"
#include "../../include/SearchEngineServer/Configuration.h"
DictProducer::DictProducer()
    :_config(Configuration::getInstance()->getConfigMap()),
    _cuttor(nullptr),_dict(),_dict_index(),_index()
    {
        buildEnDict();
        createIndex();
    }

DictProducer::DictProducer(SplitTool *cuttor)
    :_config(Configuration::getInstance()->getConfigMap()),
    _cuttor(cuttor),_dict(),_dict_index(),_index()
    {
        buildCnDict();
        createIndex();
    }

void DictProducer::buildEnDict()
{
    unordered_set<string> stop_word;
    Configuration *config = Configuration::getInstance();
    stop_word = config->getStopWordList();
    string englishPage(_config["englishpage"]);
    ifstream str(englishPage.c_str());
    if(!str.is_open())
    {
        cerr<< "englishPath Open Error !" <<endl;
    }
    str.seekg(std::ios_base::beg);
    string sentence;
    while(getline(str,sentence))
    {
        istringstream ss(sentence);
        string words;
        while(ss >> words)
        {
            for(int c = 0;c <words.size();++c)
            {
                if(words[c] >= 'A' && words[c] <= 'Z')
                {
                    words[c] = tolower(words[c]);
                }
                if(!isalpha(words[c]))
                {
                    words.erase(c);
                }
            }
            auto stop = stop_word.find(words);
            if(stop != stop_word.end())
            {
                continue;
            }
            else
            {
                auto exist = _dict_index.find(words);
                if(exist != _dict_index.end())
                {
                    ++(_dict[exist->second].second);
                }
                else
                {
                    _dict.push_back(pair<string,int>(words,1));
                    _dict_index.insert(pair<string,int>(words,_dict.size()));
                }
            }
        }

    }
}



