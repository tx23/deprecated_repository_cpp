 ///
 /// @file    singleton1.cc
 /// @author  tangxin(tangxin_sysu@foxmail.com)
 /// @date    2019-01-15 06:30:12
 ///
#include <stdlib.h> 
#include <iostream>
using std::cout;
using std::endl;
//单例对象自动释放：atexit + 饱汉模式

class Singleton
{
public:
	static Singleton* getInstance()
	{
		if (nullptr == _pInstance) {
			_pInstance = new Singleton();
			::atexit(destory);
		}
		return _pInstance;
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
};

Singleton *Singleton::_pInstance = getInstance();

int main(void)
{
	Singleton * p = Singleton::getInstance();
	p -> print();

	return 0;
}


