 ///
 /// @file    MutexLock.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2021-01-31 17:15:36
 ///

#include "MutexLock.h"

#include <iostream>

using std::cout;
using std::endl;

namespace zh
{
MutexLock::MutexLock()
:_isLocking(false)
{
	if(pthread_mutex_init(&_mutex,NULL))
	{
		cout << "error:create mutex failed!" << endl;
	}
}

MutexLock::~MutexLock()
{
	if(pthread_mutex_destroy(&_mutex))
	{
		cout << "error:destroy mutex failed!" << endl;
	}
}

void MutexLock::lock()
{
	pthread_mutex_lock(&_mutex);
	_isLocking = true;
}

void MutexLock::unlock()
{
	pthread_mutex_unlock(&_mutex);
	_isLocking = false;
}

bool MutexLock::isLocking() const
{
	return _isLocking;
}

pthread_mutex_t *MutexLock::getMutexLockPtr()
{
	return &_mutex;
}
}//end of namespace zh
