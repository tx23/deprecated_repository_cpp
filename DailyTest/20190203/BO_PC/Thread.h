 ///
 /// @file    Thread.cc
 /// @author  tangxin(tangxin_sysu@foxmail.com)
 /// @date    2019-02-02 06:51:21
 ///
#ifndef _WD_THREAD_H_
#define _WD_THREAD_H_
#include "Noncopyable.h"
#include <iostream>
#include <pthread.h>
#include <functional>

using std::cout;
using std::endl;

namespace wd
{

class Thread
: Noncopyable
{//具有对象语义的类， 不能被复制
public:
	using ThreadCallback = std::function<void()>;
	Thread(ThreadCallback && callback);
	
	~Thread();

	void start();//开启子线程
	void join();//关闭子线程

	bool isRunning() const { return _isRunning; }
	
	pthread_t getThreadid() const {return _pthid; }
private:
	static void * threadFunc(void *);//非static成员函数会有一个this参数，不能用于线程创建
private:
	ThreadCallback _callback;
	pthread_t _pthid;
	bool _isRunning;
};

}



#endif
