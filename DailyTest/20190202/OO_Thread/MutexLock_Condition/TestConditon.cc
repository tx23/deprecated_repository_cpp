 ///
 /// @file    TestConditon.cc
 /// @author  tangxin(tangxin_sysu@foxmail.com)
 /// @date    2019-02-09 03:26:10
 ///
#include "MutexLock.h"
#include "condition.h"

#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

#include <iostream>
using std::cout;
using std::endl;

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
		sleep(1);
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
		sleep(1);
	}
}

int main(void)
{
	printf(">> main thread start running!\n");
	Example example;

	pthread_create(&pthid1, NULL, threadFunc1, NULL);
	pthread_create(&pthid1, NULL, threadFunc1, NULL);
	
	
	
	return 0;

}

