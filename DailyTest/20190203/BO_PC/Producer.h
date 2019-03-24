 ///
 /// @file    Produce.h
 /// @author  tangxin(tangxin_sysu@foxmail.com)
 /// @date    2019-02-09 07:27:22
 ///
#ifndef _WD_PRODUCER_H_
#define _WD_PRODUCER_H_

#include "TaskQueue.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

namespace wd
{

class Producer
{
public:
	void produce(TaskQueue & taskque)
	{
		::srand(::clock());
		int cnt = 20;
		while(cnt--) {
			int number = ::rand() % 100;
			taskque.push(number);
			cout << ">> producer " << pthread_self()
				 << ": produce a number = " << number << endl; 
		}
	}
};

}
#endif
