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

class MyThread
: public wd::Thread
{
public:
	~MyThread() { cout << "~MyThread" << endl; }
private:
	void run() override
	{
		int cnt = 10;
		::srand(::clock());
		while(cnt--) {
			int number = ::rand()%100;
			cout << "sub Thread " << pthread_self()
				 << ": getNumber = " << number << endl;
			::sleep(1);
		}	
	}
};

void test0(void)
{
	cout << "main Thread " << pthread_self() << endl;
	unique_ptr<wd::Thread> myThread(new MyThread());
	myThread->start();
	myThread->join();

}

void test1()
{
	cout << "main Thread " << pthread_self() << endl;
	MyThread myThread;
	myThread.start();
	myThread.join();

	//MyThread myThread2(myThread);//应当被禁止.
}
int main(void)
{
//	test0();
	test1();
}
