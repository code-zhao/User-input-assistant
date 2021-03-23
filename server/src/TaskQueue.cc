 ///
 /// @file    TaskQueue.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2021-01-31 17:45:14
 ///

#include "TaskQueue.h"

using namespace zh;

void TaskQueue::push(Task *t)
{
	MutexLockGuard autoLock(_mutex);

	while(full())
	{
		_notFull.wait();
	}

	_que.push(t);
	_notEmpty.notify();
}

Task *TaskQueue::pop()
{
	MutexLockGuard autoLock(_mutex);
	while(_flag && empty())
	{
		_notEmpty.wait();
	}

	if(_flag)
	{
		Task *t = _que.front();
		_que.pop();
		_notFull.notify();
		return t;
	}
	else
	{
		return NULL;
	}
}
