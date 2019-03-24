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
class Task;
using TaskType = Task*;

class TaskQueue
{
public:
	TaskQueue(size_t size);
	bool full() const;
	bool empty() const;
	void push(const TaskType & t);
	TaskType pop();
	
	void wakeup();//激活所有等待 _notEmpty条件变量的线程
private:
	size_t _queSize;
	std::queue<TaskType> _que;
	MutexLock _mutex;
	Condition _notFull;
	Condition _notEmpty;
	bool _used;
};

}//end of namespace wd


#endif
