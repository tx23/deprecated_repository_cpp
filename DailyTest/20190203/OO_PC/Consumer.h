 ///
 /// @file    Consumer.h
 /// @author  tangxin(tangxin_sysu@foxmail.com)
 /// @date    2019-02-09 17:44:18
 ///
#ifndef _WD_CONSUMER_H_
#define _WD_CONSUMER_H_

#include "Thread.h"
#include "TaskQueue.h"

namespace wd
{
class Consumer
: public Thread
{
public:
	Consumer(TaskQueue & taskque)
	: _taskque(taskque) {}

private:
	void run() override
	{
		int cnt = 20;
		while(cnt--) {
			int number = _taskque.pop();
			cout << ">> consumer " << pthread_self()
				 << ": consumer a number = " << number << endl;
		}
	}
private:
	TaskQueue & _taskque;
};

}
#endif
