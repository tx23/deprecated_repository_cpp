 ///
 /// @file    TestThreadpol.cc
 /// @author  tangxin(tangxin_sysu@foxmail.com)
 /// @date    2019-02-10 07:12:52
 ///
#include "Threadpool.h"

#include <unistd.h>
#include <stdlib.h>

#include <iostream>
#include <memory>
using namespace std;
using namespace wd;

class MyTask
: public Task
{
public:
	void process()
	{
		::srand(::time(NULL));
		int number = ::rand() % 100;
		cout << "pthid " << pthread_self() << ", number" << number << endl;
	}
};

void test()//test方法运行在主线程
{
	unique_ptr<Task> up(new MyTask());
	unique_ptr<Threadpool> threadpoolPtr(new Threadpool(4, 10));
	threadpoolPtr->start();
	int cnt = 20;
	while(cnt--) {
		threadpoolPtr->addTask(up.get());
	}

	cout << ">> test(): exit while (cnt--)" << endl;
	threadpoolPtr->stop();
}

int main()
{
	test();
	return 0;
}
