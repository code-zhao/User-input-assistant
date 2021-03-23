 ///
 /// @file    Thread.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2021-01-31 16:03:18
 ///
#ifndef __ZH_THREAD_H__
#define __ZH_THREAD_H__

#include "Noncopyable.h"
#include "Mylog.h"
#include <string>
#include <pthread.h>

using std::string;

namespace zh
{
class Thread
:Noncopyable
{
public:
	Thread();
	virtual ~Thread();

	void start();
	void join();

	bool isRunning() const
	{
		return _isRunning;
	}

private:
	virtual void run() = 0; //纯虚函数

	static void *threadFunc(void *);
private:
	pthread_t _pthid;
	bool _isRunning;
};
}//end of namespace zh

#endif
