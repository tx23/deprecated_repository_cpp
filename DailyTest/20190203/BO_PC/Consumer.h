 ///
 /// @file    Consumer.h
 /// @author  tangxin(tangxin_sysu@foxmail.com)
 /// @date    2019-02-09 17:44:18
 ///
#ifndef _WD_CONSUMER_H_
#define _WD_CONSUMER_H_

#include "TaskQueue.h"
#include <unistd.h>

#include <iostream>
using namespace std;

namespace wd
{
class Consumer
{
public:

	void consume(TaskQueue & taskque)
	{
		int cnt = 20;
		while(cnt--) {
			int number = taskque.pop();
			cout << ">> consumer " << pthread_self()
				 << ": consumer a number = " << number << endl;
			::sleep(1);
		}
	}
};

}
#endif
