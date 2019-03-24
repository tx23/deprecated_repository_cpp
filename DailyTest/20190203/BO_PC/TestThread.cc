 ///
 /// @file    TestThread.cc
 /// @author  tangxin(tangxin_sysu@foxmail.com)
 /// @date    2019-02-03 04:23:27
 ///
#include "Thread.h"
#include "Producer.h"
#include "Consumer.h"

#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::unique_ptr;
using namespace wd;

void test0()
{
	cout << "main Thread " << pthread_self() << endl;
	wd::TaskQueue taskque(10);
	unique_ptr<wd::Thread> producer(new wd::Thread(
				std::bind(&Producer::produce, Producer(), std::ref(taskque))
				));
	unique_ptr<wd::Thread> consumer(new wd::Thread(
				std::bind(&Consumer::consume, Consumer(), std::ref(taskque))
				));
	
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
