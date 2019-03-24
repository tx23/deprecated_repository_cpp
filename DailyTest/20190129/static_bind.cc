 ///
 /// @file    static_bind.cc
 /// @author  tangxin(tangxin_sysu@foxmail.com)
 /// @date    2019-01-29 04:23:07
 ///
 
#include <iostream>
using std::cout;
using std::endl;
class Base
{
public:
	Base(){ cout << "Base()" << endl; }

	virtual void fun1() { cout << "Base::fun1()" << endl;}
	virtual void fun2() { cout << "Base::fun2()" << endl;}

	~Base() { cout << "~Base()" << endl; }
};

class Middle
: public Base
{
public:
	Middle()
	: Base()
	{
		cout << "Middle()" << endl; 
		fun1();//静态联编，由编译器决定
	}

	virtual void fun1() { cout << "Middle::fun1()" << endl;}
	virtual void fun2() { cout << "Middle::fun2()" << endl;}

	~Middle()
	{ cout << "~Middle()" << endl;}
};

class Derive
: public Middle
{
public:
	Derive()
	: Middle()
	{
		cout << "Derive()" << endl; 
	}

	virtual void fun1() { cout << "Middle::fun1()" << endl;}
	virtual void fun2() { cout << "Middle::fun2()" << endl;}

	~Derive()
	{ cout << "~Derive()" << endl;}
};
int main(void)
{
	Derive derive;
	return 0;
}
