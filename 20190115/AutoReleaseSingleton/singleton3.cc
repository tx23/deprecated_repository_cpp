 ///
 /// @file    singleton1.cc
 /// @author  tangxin(tangxin_sysu@foxmail.com)
 /// @date    2019-01-15 06:30:12
 ///
#include <pthread.h>
#include <stdlib.h> 
#include <iostream>
using std::cout;
using std::endl;
//单例对象自动释放：atexit + pthread_once

class Singleton
{
public:
	static Singleton* getInstance()
	{
		pthread_once(&_once, init);
		return _pInstance;
	}
	
	static void init()
	{
		_pInstance = new Singleton();
		::atexit(destory);
	}

	static void destory()
	{
		if(_pInstance)
			delete _pInstance;
	}
	void print() const
	{ cout << "print()" << endl;}
private:
	Singleton()
	{ cout << "Singleton()" << endl;}
	~Singleton() 
	{ cout << "~Singleton()" << endl;}

	static Singleton *_pInstance;
	static pthread_once_t _once;
};

Singleton *Singleton::_pInstance = nullptr;
pthread_once_t Singleton::_once = PTHREAD_ONCE_INIT;

int main(void)
{
	Singleton * p = Singleton::getInstance();
	p -> print();

	return 0;
}
