 ///
 /// @file    TestThread.cc
 /// @author  tangxin(tangxin_sysu@foxmail.com)
 /// @date    2019-02-03 04:23:27
 ///
#include "Producer.h"
#include "Consumer.h"
#include "TaskQueue.h"

#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::unique_ptr;

void test0()
{
	cout << "main Thread " << pthread_self() << endl;
	wd::TaskQueue taskque(10);
	unique_ptr<wd::Thread> producer(new wd::Producer(taskque));
	unique_ptr<wd::Thread> consumer(new wd::Consumer(taskque));
	
	producer->start();
	consumer->start();

	producer->join();
	consumer->join();
}


int main(void)
{
	test0();
	return 0;
}
