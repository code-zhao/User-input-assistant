 ///
 /// @file    Config.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2021-01-31 14:10:11
 ///

#ifndef __CONFIG_H__
#define __CONFIG_H__

#include <iostream>
#include <fstream>
#include <map>
#include <string>
using namespace std;

class Config
{
public:
	static Config* getInstance(const string& rhs)
	{
		if(!_Instance)
		{
			_Instance = new Config(rhs);
		}
		return _Instance;
	}

	void Delete()
	{
		if(_Instance)
		{
			delete _Instance;
		}
	}

	map<string, string> &getConfigMap()
	{
		return _configMap;
	}

private:
	Config(const string&);
	~Config(){}

private:
	static Config* _Instance;
	string _filepath;
	map<string,string> _configMap;
};

#endif
