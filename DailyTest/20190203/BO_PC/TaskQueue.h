 ///
 /// @file    TaskQueue.h
 /// @author  tangxin(tangxin_sysu@foxmail.com)
 /// @date    2019-02-09 07:34:09
 ///
#ifndef _WD_TASKQUEUE_H__
#define _WD_TASKQUEUE_H__

#include "MutexLock.h"
#include "condition.h"

#include <queue>

namespace wd
{

class TaskQueue
{
public:
	TaskQueue(size_t size);
	bool full() const;
	bool empty() const;
	void push(int number);
	int pop();

private:
	size_t _queSize;
	std::queue<int> _que;
	MutexLock _mutex;
	Condition _notFull;
	Condition _notEmpty;
};

}//end of namespace wd


#endif
