 ///
 /// @file    Noncopyable.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2021-01-18 15:26:28
 ///

#ifndef __ZH_NONCOPYABLE_H__
#define __ZH_NONCOPYABLE_H__
namespace zh
{
class Noncopyable
{
protected:
	Noncopyable(){}

	~Noncopyable(){}

private:
	Noncopyable(const Noncopyable&) = delete;
	Noncopyable &operator = (const Noncopyable&) = delete;
};

}//end of namespace zh


#endif
