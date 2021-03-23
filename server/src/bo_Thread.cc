 ///
 /// @file    bo_Thread.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2021-02-06 15:21:57
 ///

#include "bo_Thread.h"
#include <iostream>

using std::cout;
using std::endl;
using namespace zh;

boThread::boThread(boThreadCallback && cb)
:_pthid(0)
,_isRunning(false)
,_cb(std::move(cb))
{
	cout << "boThread(cb)" << endl;
}

void boThread::start()
{
	pthread_create(&_pthid, NULL, threadFunc, this);
	_isRunning = true;
}

void *boThread::threadFunc(void *arg)
{
	boThread *pthread = static_cast<boThread*>(arg);
	if(pthread)
	{
		pthread->_cb();
	}
	return NULL;
}

void boThread::join()
{
	pthread_join(_pthid, NULL);
	_isRunning = false;
}

boThread::~boThread()
{
	if(_isRunning)
	{
		pthread_detach(_pthid);
		_isRunning = false;
	}
	cout << "~boThread()" << endl;
}
