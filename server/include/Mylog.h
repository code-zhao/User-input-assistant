 ///
 /// @file    Mylog.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2021-01-31 16:04:29
 ///

#ifndef __MYLOG_H__
#define __MYLOG_H__

#include <log4cpp/Category.hh>
#include <iostream>
#include <string>

using std::cout;
using std::endl;

using namespace log4cpp;

namespace zh
{
class Mylog
{
public:
	static Mylog *getInstance();
	static void destroy();

	void warn(const char* msg);
	void info(const char* msg);
	void error(const char* msg);
	void debug(const char* msg);

private:
	Mylog();
	~Mylog();

private:
	Category &_root;
	static Mylog* _pInstance;
};
}//end of namespace zh

#define prefix(msg) string("[").append(__FILE__)\
	.append(":").append(__FUNCTION__)\
	.append(":").append(std::to_string(__LINE__))\
	.append("]").append(msg).c_str()

#define LogWarn(msg) zh::Mylog::getInstance()->warn(prefix(msg))
#define LogInfo(msg) zh::Mylog::getInstance()->info(prefix(msg))
#define LogError(msg) zh::Mylog::getInstance()->error(prefix(msg))
#define LogDebug(msg) zh::Mylog::getInstance()->debug(prefix(msg))

#endif
