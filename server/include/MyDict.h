 ///
 /// @file    MyDict.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2021-01-18 10:56:19
 ///

#ifndef __MYDICT_H__
#define __MYDICT_H__

#include "StrUtils.h"
#include <map>
#include <set>

using namespace std;

class MyDict
{
public:
	static MyDict* getInstance(const string &a1, const string &a2)
	{
		if(!_Instance)
		{
			_Instance = new MyDict(a1, a2);
		}
		return _Instance;
	}

	void init();
	void initDict();
	void initIndex();

	vector<pair<string, int>> &getDict()
	{
		return _dict;
	}

	map<string, set<int>> &getIndexTable()
	{
		return _index;
	}

	static void Delete()
	{
		if(_Instance)
		{
			delete _Instance;
		}
	}

private:
	MyDict(const string &cnPath, const string &enPath)
	:_enPath(enPath)
	,_cnPath(cnPath)
	{}

	~MyDict(){}

private:
	string _enPath;
	string _cnPath;
	static MyDict *_Instance;
	vector<pair<string, int>> _dict;
	map<string, set<int>> _index;
};

#endif
