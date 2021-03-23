 ///
 /// @file    Thread.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2021-01-31 16:51:03
 ///

#include "Thread.h"
#include <iostream>

using std::cout;
using std::endl;
using namespace zh;

Thread::Thread()
:_pthid(0)
,_isRunning(false)
{}

void Thread::start()
{
	pthread_create(&_pthid, NULL, threadFunc, this);
	_isRunning = true;
}

void *Thread::threadFunc(void* arg)
{
	Thread* pthread = static_cast<Thread*>(arg);//将arg强制转换为Thread类型
	if(pthread)
		pthread->run();
	return NULL;
}

void Thread::join()
{
	pthread_join(_pthid, NULL);
	_isRunning = false;
}

Thread::~Thread()
{
	if(_isRunning)
	{
		pthread_detach(_pthid);
		_isRunning = false;
	}
}
