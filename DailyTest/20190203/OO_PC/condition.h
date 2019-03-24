 ///
 /// @file    condition.h
 /// @author  tangxin(tangxin_sysu@foxmail.com)
 /// @date    2019-02-09 03:10:57
 ///
#ifndef _WD_CONDITION_H_
#define _WD_CONDITION_H_

#include "Noncopyable.h"

#include <pthread.h>

namespace wd
{
class MutexLock;

class Condition
: Noncopyable
{
public:
	Condition(MutexLock & mutex);
	~Condition();

	void wait();
	void notify();
	void notifyall();

private:
	MutexLock & _mutex;
	pthread_cond_t _cond;
};

}
#endif

 


 

