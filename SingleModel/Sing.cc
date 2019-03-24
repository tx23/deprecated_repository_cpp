#include<iostream>
using std::cout;
using std::endl;
//单例模式，通过该类只能创建一个对象
//1.不能是栈对象
//2.只能是堆对象
//应用：
//只要出现全局变量都可以用单例模式替代
//对于全局唯一的资源，可以使用单例模式
//  >对于配置文件的读取
//	>对于词典，字典类
//	>对于日志系统的写日志的对象 
class Singleton
{
public:	
	static Singleton *getInstance()
	{
	if(nullptr == _pInstance) {
	_pInstance = new Singleton();
	}
	return _pInstance;
	}

	static void destroy()//回收空间
	{
	if(_pInstance)
		delete _pInstance;
	}

private:
	Singleton(){ cout << "Singleton()" <<endl; }
	~Singleton(){cout << "~Singleton()" <<endl; }
	static Singleton * _pInstance;//保存指针
};

Singleton * Singleton::_pInstance = nullptr;//静态变量初始化

int main(void) 
{
//	Singleton *ps1 = new Singleton();类之外不能正常调用
	Singleton * ps1 = Singleton::getInstance();
	Singleton * ps2 = Singleton::getInstance();
	cout << "ps1 = " << ps1 << endl
		 << "ps2 = " << ps2 << endl;
	Singleton::destroy();
	return 0;}
