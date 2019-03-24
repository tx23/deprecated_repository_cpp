 ///
 /// @file    Thread.cc
 /// @author  tangxin(tangxin_sysu@foxmail.com)
 /// @date    2019-02-02 07:06:01
 ///
#include "Thread.h" 
namespace wd 
{

Thread::Thread(ThreadCallback && callback)
: _callback(std::move(callback))
, _pthid(0)
, _isRunning(false)
{}

void Thread::start()
{
	pthread_create(&_pthid, NULL, threadFunc, this);//this 为创建的对象
	_isRunning = true;
}

void * Thread::threadFunc(void * arg)//传入的为this
{
	Thread * p = static_cast<Thread *> (arg);//将this装为Thread类型	
	if(p)
		p->_callback();//执行回调函数
	return NULL;
}

void Thread::join()
{
	if(_isRunning) {
		pthread_join(_pthid, NULL);
		_isRunning = false;
	}
}

Thread::~Thread()
{
	if(_isRunning) {
		pthread_detach(_pthid);
		_isRunning = false;
	}
	cout << "~Thread()" << endl;
}

}
