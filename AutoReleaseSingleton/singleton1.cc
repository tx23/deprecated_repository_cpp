 ///
 /// @file    singleton1.cc
 /// @author  tangxin(tangxin_sysu@foxmail.com)
 /// @date    2019-01-15 06:30:12
 ///
 
#include <iostream>
using std::cout;
using std::endl;
//单例对象自动释放：嵌套类+静态对象

class Singleton
{
public:
	static Singleton* getInstance()
	{
		if (nullptr == _pInstance)
			_pInstance = new Singleton();
		return _pInstance;
	}

	void print() const
	{ cout << "print()" << endl;}
private:
	class AutoRelease
	{
	public:
		AutoRelease()
		{ cout << "AutoRelease()" << endl;}
		~AutoRelease()
		{
			cout << "~AutoRelease()" << endl;
			if(_pInstance)
				delete _pInstance;
		}
	};
private:
	Singleton()
	{ cout << "Singleton()" << endl;}
	~Singleton() 
	{ cout << "~Singleton()" << endl;}

	static Singleton *_pInstance;
	static AutoRelease _auto;
};

Singleton *Singleton::_pInstance = getInstance();
Singleton::AutoRelease Singleton::_auto;

int main(void)
{
	Singleton * p = Singleton::getInstance();
	p -> print();

	return 0;
}


