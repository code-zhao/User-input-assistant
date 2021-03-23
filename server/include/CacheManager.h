 ///
 /// @file    CacheManager.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2021-02-05 14:37:46
 ///

#ifndef __CACHEMANAGER_H__
#define __CACHEMANAGER_H__

#include "Cache.h"
#include "Mylog.h"
class CacheManager
{
public:
	CacheManager(const string& path)
	:_cacheDiskPath(path)
	{}

	void initCache();
	Cache<> &getCache();
	string &getPath()
	{
		return _cacheDiskPath;
	}

	void periodUpdate();

private:
	vector<Cache<>> _cacheList;
	map<pthread_t, size_t> _Thread2Cache;
	string _cacheDiskPath;
};


#endif
