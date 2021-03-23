 ///
 /// @file    Threadpool.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2021-02-01 13:39:09
 ///

#include "Threadpool.h"
#include "WorkerThread.h"

#include <unistd.h>

using namespace zh;

void Threadpool::start()
{
	for(size_t idx = 0; idx < _threadNum; ++idx)
	{
		shared_ptr<Thread> pThread(new WorkerThread(*this));
		_threads.push_back(std::move(pThread));
	}

	for(auto &pThread : _threads)
	{
		pThread->start();
	}
}

void Threadpool::stop()
{
	if(!_isExit)
	{
		while(!_taskQue.empty())
		{
			::sleep(1);
			cout << ">>>Threadpool sleep 1 s" << endl;
		}
		_isExit = true;
		cout << ">>>Threadpool->stop:_isEixt = " << _isExit << endl;

		_taskQue.wakeup();

		for(auto &pthread : _threads)
		{
			pthread->join();
		}
	}
}

Threadpool::~Threadpool()
{
	if(!_isExit)
	{
		stop();
	}
}

void Threadpool::addTask(Task *ptask)
{
	_taskQue.push(ptask);
}

Task *Threadpool::getTask()
{
	return _taskQue.pop();
}

void Threadpool::threadFunc()
{
	while(!_isExit)
	{
		Task *ptask = getTask();
		if(ptask)
		{
			ptask->process();
			delete ptask;
		}
	}
}
