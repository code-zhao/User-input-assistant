 ///
 /// @file    TaskQueue.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2021-01-31 17:03:16
 ///

#ifndef __ZH_TASKQUEUE_H__
#define __ZH_TASKQUEUE_H__

#include "MutexLock.h"
#include "Condition.h"
#include <queue>

namespace zh
{
class Task;

class TaskQueue
{
public:
	TaskQueue(size_t queSize)
	:_queSize(queSize)
	,_mutex()
	,_notFull(_mutex)
	,_notEmpty(_mutex)
	,_flag(true)
	{}

	void push(Task *);
	Task* pop();

	bool empty() const
	{
		return _que.size() == 0;
	}

	bool full() const
	{
		return _que.size() == _queSize;
	}

	void wakeup()
	{
		_flag = false;
		_notEmpty.notifyAll();
	}
private:
	size_t _queSize;
	std::queue<Task *> _que;
	MutexLock _mutex;
	Condition _notFull;
	Condition _notEmpty;
	bool _flag;
};
}//end of namespace zh
#endif
