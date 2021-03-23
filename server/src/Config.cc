 ///
 /// @file    Config.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2021-01-31 14:16:51
 ///

#include "Config.h"

Config* Config::_Instance = NULL;

Config::Config(const string& path)
{
	ifstream ifs(path);
	string section;
	string content;
	while(ifs >> section >> content)
	{
		_configMap.insert(make_pair(section, content));
	}
	ifs.close();
}
