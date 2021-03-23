 ///
 /// @file    TimerThread.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2021-02-06 15:32:18
 ///

#include "TimerThread.h"

using namespace zh;

TimerThread::TimerThread(int initialTime, int intervalTime, TimerCallback && cb)
:_timer(initialTime, intervalTime, std::move(cb))
,_subThread(std::bind(&Timer::start, &_timer))
,_isStarted(false)
{}

void TimerThread::start()
{
	_subThread.start();
	_isStarted = true;
}

void TimerThread::stop()
{
	if(_isStarted)
	{
		_timer.stop();
		_subThread.join();
		_isStarted = false;
	}
}

TimerThread::~TimerThread()
{
	if(_isStarted)
		stop();
}
