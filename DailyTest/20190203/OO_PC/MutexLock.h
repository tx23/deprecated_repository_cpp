 ///
 /// @file    MutexLock.h
 /// @author  tangxin(tangxin_sysu@foxmail.com)
 /// @date    2019-02-09 01:36:16
 ///
#ifndef _WD_MUTEXLOCK_H_
#define _WD_MUTEXLOCK_H_

#include "Noncopyable.h"
#include <pthread.h>
namespace wd 
{

class MutexLock
: Noncopyable
{
public:
	MutexLock();
	~MutexLock();
	void lock();
	void unlock();

	pthread_mutex_t * getMutexLockPtr() { return &_mutex;}
private:
	pthread_mutex_t _mutex;
};


class MutexLockGuard
{
public:
	MutexLockGuard(MutexLock & mutex)
	: _mutex(mutex)
	{
		_mutex.lock();
	}

	~MutexLockGuard() { _mutex.unlock(); }
private:
	MutexLock &_mutex;
};

}

#endif
