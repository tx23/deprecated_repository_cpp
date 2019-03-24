 ///
 /// @file    Produce.h
 /// @author  tangxin(tangxin_sysu@foxmail.com)
 /// @date    2019-02-09 07:27:22
 ///
#ifndef _WD_PRODUCER_H_
#define _WD_PRODUCER_H_

#include "Thread.h"
#include "TaskQueue.h"
#include <stdlib.h>

namespace wd
{
class Producer
: public Thread
{
public:
	Producer(TaskQueue & taskque)
	: _taskque(taskque)
	{}

private:
	void run() override
	{
		::srand(::clock());
		int cnt = 20;
		while(cnt--) {
			int number = ::rand() % 100;
			_taskque.push(number);
			cout << ">> producer " << pthread_self()
				 << ": produce a number = " << number << endl; 
		}
	}
private:
	TaskQueue & _taskque;
};

}
#endif
