 ///
 /// @file    TestThread.cc
 /// @author  tangxin(tangxin_sysu@foxmail.com)
 /// @date    2019-02-03 04:23:27
 ///
#include "Thread.h"

#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::unique_ptr;

class Task
{
public:
	void process()
	{
		int cnt = 10;
		::srand(::clock());
		while(cnt--) {
			int number = ::rand() % 100;
			cout << "sub Thread " << pthread_self()
				 << ": getNumber = " << number << endl;
			::sleep(1);
		}
	
	}
};

void test0(void)
{
	cout << "main Thread " << pthread_self() << endl;
	Task task;
	unique_ptr<wd::Thread> mythread(new wd::Thread(
				std::bind(&Task::process, &task)
				));
	mythread->start();
	mythread->join();
	
}

void process()
{
	int cnt = 10;
	::srand(::clock());
	while(cnt--) {
		int number = ::rand() % 100;
		cout << "sub Thread " << pthread_self()
			 << ": getNumber = " << number << endl;
		::sleep(1);
	}
}

void test1()
{
	cout <<"main Thread " << pthread_self() << endl;
	wd::Thread mythread(process);
	mythread.start();
	mythread.join();

}

int main(void)
{
//	test0();
	test1();
	return 0;
}
