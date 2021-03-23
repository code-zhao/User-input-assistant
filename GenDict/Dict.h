 ///
 /// @file    Dict.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2021-01-15 18:36:38
 ///

#ifndef __ZH_DICT_H__
#define __ZH_DICT_H__
#include "trie.h"
#include <string>
#include <map>

using std::string;
using std::map;

const string DICT_PATH = "/home/zhaohao/linuxlearn/GenDict/dict/jieba.dict.utf8";
const string HMM_PATH = "/home/zhaohao/linuxlearn/GenDict/dict/hmm_model.utf8";
const string USER_DICT_PATH = "/home/zhaohao/linuxlearn/GenDict/dict/user.dict.utf8";
const string IDF_PATH = "/home/zhaohao/linuxlearn/GenDict/dict/idf.utf8";
const string STOP_WORD_PATH = "/home/zhaohao/linuxlearn/GenDict/dict/stop_words.utf8";

class Dict
{
public:
	Dict(const string &libpath, const string &outpath)
	:_libpath(libpath)
	,_outpath(outpath)
	{}

	void genEn();

	void genCN();

	void output();

private:
	string _libpath;
	string _outpath;
	Trie _enDict;
	map<string, int> _cnDict;
};



#endif
