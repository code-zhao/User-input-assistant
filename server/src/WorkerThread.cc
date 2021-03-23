 ///
 /// @file    WorkerThread.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2021-02-01 13:47:27
 ///

#include "WorkerThread.h"
#include "Threadpool.h"

using namespace zh;

void WorkerThread::run()
{
	_threadpool.threadFunc();
}
