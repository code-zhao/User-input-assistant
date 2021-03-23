 ///
 /// @file    MyDict.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2021-01-18 11:00:36
 ///

#include "QueryTask.h"
#include "Mylog.h"
#include <fstream>

MyDict *MyDict::_Instance = NULL;

void MyDict::init()
{
	initDict();
	initIndex();
	LogInfo("Dict Initialize");
}

void MyDict::initDict()
{
	string words;
	int freq;
	{//enDict
		ifstream enifs(_enPath);
		while(enifs >> words >> freq)
		{
			_dict.push_back(pair<string, int>(words, freq));
		}
		enifs.close();
	}

	{//cnDict
		ifstream cnifs(_cnPath);
		while(cnifs >> words >> freq)
		{
			_dict.push_back(pair<string, int>(words, freq));
		}
		cnifs.close();
	}
}

void MyDict::initIndex()
{
	int num = 0;
	for(auto c : _dict)
	{
		string word = c.first;
		if(isUTF8(word))
		{
			for(string::size_type col = 0; col < word.size(); col+=3)
			{
				string sing = word.substr(col, 3);
				_index[sing].insert(num);
			}
		}
		else
		{
			for(string::size_type col = 0; col < word.size(); ++col)
			{
				string sing = word.substr(col, 1);
				_index[sing].insert(num);
			}
		}
		++num;
	}
}

