 ///
 /// @file    TestConditon.cc
 /// @author  tangxin(tangxin_sysu@foxmail.com)
 /// @date    2019-02-09 03:26:10
 ///
#include "Thread.h"
#include "MutexLock.h"
#include "condition.h"

#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::unique_ptr;

class Example
{
public:
	Example()
	: _number(1000)
	, _flag(true)
	, _mutex()
	, _cond(_mutex)
	{}

	void executeTask1();
	void executeTask2();

private:
	int _number;
	bool _flag;
	wd::MutexLock _mutex;
	wd::Condition _cond;

};

void Example::executeTask1()
{
	int cnt = 100;
	while(cnt--) {
		_mutex.lock();
		
		while(_flag == false) {
			_cond.wait();
		}
		--_number;
		printf("sub thread %lu, gNumber = %d\n", pthread_self(), _number);
		if(_flag == true)
			_flag = false;

		_mutex.unlock();
		_cond.notify();
		sleep(0.5);
	}
}

void Example::executeTask2()
{
	int cnt = 100;
	while(cnt--) {
		_mutex.lock();
		
		while(_flag == true) {
			_cond.wait();
		}
		--_number;
		printf("sub thread %lu, gNumber = %d\n", pthread_self(), _number);
		if(_flag == false)
			_flag = true;

		_cond.notify();
		_mutex.unlock();
		sleep(0.5);
	}
}

int test0(void)
{
	printf(">> main thread start running!\n");
	Example example;

	unique_ptr<wd::Thread> thread1(new wd::Thread(
					std::bind(&Example::executeTask1, &example)
				));
	
	unique_ptr<wd::Thread> thread2(new wd::Thread(
					std::bind(&Example::executeTask2, &example)
				));
	printf("main thread %lu, 子线程IDS= %lu, %lu\n",
			pthread_self(),
			thread1->getThreadid(),
			thread2->getThreadid()
			);
	thread1->join();
	thread2->join();

	printf(">> main thread exit!\n");
	return 0;

}
int main(void)
{
	test0();
	return 0;
}
