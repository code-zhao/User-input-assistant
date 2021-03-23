 ///
 /// @file    WorkerThread.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2021-02-01 13:40:56
 ///

#ifndef __ZH_WORKERTHREAD_H__
#define __ZH_WORKERTHREAD_H__

#include "Thread.h"
#include <iostream>
using namespace std;

namespace zh
{

class Threadpool;

class WorkerThread
:public Thread
{
public:
	WorkerThread(Threadpool &threadpool)
	:_threadpool(threadpool)
	{
		LogWarn("A new workerthread was created.");
		cout << "WorkerThread()" << endl;
	}

	~WorkerThread()
	{
		cout << "~WorkerThread()" << endl;
	}

private:
	void run();
	Threadpool &_threadpool;
};
}//end of namespace zh


#endif
