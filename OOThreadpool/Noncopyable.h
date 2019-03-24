 ///
 /// @file    Noncopyable.h
 /// @author  tangxin(tangxin_sysu@foxmail.com)
 /// @date    2019-02-08 23:41:35
 ///
#ifndef _WD_NONCOPYABLE_H_
#define _WD_NONCOPYABLE_H_
namespace wd
{
class Noncopyable
{
protected:
	Noncopyable() {}
	~Noncopyable() {}

	Noncopyable( const Noncopyable &) = delete;
	Noncopyable & operator=(const Noncopyable &) = delete;
};
}

#endif
