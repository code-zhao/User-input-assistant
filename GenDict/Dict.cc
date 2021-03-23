 ///
 /// @file    Dict.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2021-01-15 18:43:43
 ///

#include "Dict.h"
#include "include/cppjieba/Jieba.hpp"
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <fstream>
#include <vector>

using std::ifstream;
using std::ofstream;
using std::endl;
using std::vector;

void Dict::genCN()
{
	string cn = _libpath + "cn/";
	chdir(cn.c_str());
	DIR *cur = opendir(".");
	struct dirent *entry;
	while((entry = readdir(cur)) != NULL)
	{
		string filename = entry->d_name;
		if(filename != "." && filename != "..")
		{
			cppjieba::Jieba jieba(DICT_PATH,
					HMM_PATH,
					USER_DICT_PATH,
					IDF_PATH,
					STOP_WORD_PATH);
			vector<string> words;
			string line;
			ifstream ifs(filename);
			while(ifs)
			{
				getline(ifs, line);
				jieba.CutAll(line, words);
				for(auto c = words.begin(); c != words.end(); ++c)
				{
					if(c->size() > 3)
					{
						_cnDict[*c]++;
					}
				}
			}
			ifs.close();
		}
	}
	closedir(cur);
	chdir("../..");
}

void Dict::genEn()
{
	string en = _libpath + "en/";
	chdir(en.c_str());
	DIR *cur = opendir(".");
	struct dirent *entry;
	while((entry = readdir(cur)) != NULL)
	{
		string filename = entry->d_name;
		if(filename != "." && filename != "..")
		{
			_enDict.read(filename);
		}
	}
	chdir("../..");
	closedir(cur);
}

void Dict::output()
{
	{//CnDict
		string cnFilepath = _outpath + "cnDict.dat";
		ofstream ofs(cnFilepath);
		auto it = _cnDict.cbegin();
		while(it != _cnDict.cend())
		{
			ofs << it->first << " " << it->second << endl;
			++it;
		}
		ofs.close();
	}

	{//enDict
		string enFilepath = _outpath + "enDict.dat";
		_enDict.list(enFilepath);
	}
}

