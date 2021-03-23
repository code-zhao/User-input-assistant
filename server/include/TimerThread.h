 ///
 /// @file    TimerThread.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2021-02-06 15:13:55
 ///

#ifndef __ZH_TIMERTHREAD_H__
#define __ZH_TIMERTHREAD_H__

#include "Timer.h"
#include "bo_Thread.h"
#include <functional>

namespace zh
{
class TimerThread
{
public:
	using TimerCallback = std::function<void()>;
	TimerThread(int, int, TimerCallback && cb);

	void start();
	void stop();

	~TimerThread();

private:
	Timer _timer;
	boThread _subThread;
	bool _isStarted;
};
}//end of namespace zh

#endif
