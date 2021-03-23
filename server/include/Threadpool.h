 ///
 /// @file    Threadpool.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2021-01-31 17:01:11
 ///

#ifndef __ZH_THREADPOOL_H__
#define __ZH_THREADPOOL_H__

#include "TaskQueue.h"

#include <vector>
#include <memory>
using namespace std;

namespace zh
{
class Task
{
public:
	virtual void process() = 0;
	virtual ~Task(){};
};

class Thread;
class WorkerThread;

class Threadpool
{
friend WorkerThread;
public:
	Threadpool(size_t threadNum, size_t queSize)
	:_threadNum(threadNum)
	,_queSize(queSize)
	,_taskQue(_queSize)
	,_isExit(false)
	{
		_threads.reserve(_threadNum);
	}

	~Threadpool();

	void start();
	void stop();
	void addTask(Task *);

private:
	void threadFunc();
	Task *getTask();
private:
	size_t _threadNum;
	size_t _queSize;
	vector<shared_ptr<Thread>> _threads;
	TaskQueue _taskQue;
	bool _isExit;
};
}//end of namespace zh

#endif
