 ///
 /// @file    Timer.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2021-02-05 11:20:41
 ///

#ifndef __ZH_TIMER_H__
#define __ZH_TIMER_H__

#include <functional>

namespace zh
{
class Timer
{
public:
	using TimerCallback = std::function<void()>;

	Timer(int initialTime, int intervalTime, TimerCallback && cb);

	~Timer();

	void start();
	void stop();
private:
	int createTimerFd();
	void setTimerfd(int initialTime, int intervalTime);
	void handleRead();

private:
	int _fd;
	int _initialTime;
	int _intervalTime;
	TimerCallback _cb;
	bool _isStarted;
};

}//end of namespace zh

#endif
