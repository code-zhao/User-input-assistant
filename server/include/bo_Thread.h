 ///
 /// @file    bo_Thread.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2021-02-06 15:16:00
 ///

#ifndef __ZH_BO_THREAD_H__
#define __ZH_BO_THREAD_H__

#include "Noncopyable.h"
#include <pthread.h>
#include <functional>
using std::function;

namespace zh
{
class boThread
:Noncopyable
{
	using boThreadCallback = function<void()>;
public:
	boThread(boThreadCallback && cb);
	~boThread();

	void start();
	void join();

	bool isRunning() const 
	{
		return _isRunning;
	}

private:
	static void *threadFunc(void *);
private:
	pthread_t _pthid;
	bool _isRunning;
	boThreadCallback _cb;
};
}//end of namespace zh


#endif
