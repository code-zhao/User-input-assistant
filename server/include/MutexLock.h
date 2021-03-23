 ///
 /// @file    MutexLock.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2021-01-31 17:04:22
 ///

#ifndef __ZH_MUTEXLOCK_H__
#define __ZH_MUTEXLOCK_H__

#include "Noncopyable.h"
#include <pthread.h>

namespace zh
{
class MutexLock
:Noncopyable
{
public:
	MutexLock();
	~MutexLock();
	void lock();
	void unlock();

	bool isLocking() const;
	pthread_mutex_t* getMutexLockPtr();

private:
	pthread_mutex_t _mutex;
	bool _isLocking;
};

class MutexLockGuard
{
public:
	MutexLockGuard(MutexLock &mutex)
	:_mutex(mutex)
	{
		_mutex.lock();
	}

	~MutexLockGuard()
	{
		_mutex.unlock();
	}
private:
	MutexLock &_mutex;
};
}//end of namespace zh


#endif
