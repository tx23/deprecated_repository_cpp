 ///
 /// @file    virtualTable.cc
 /// @author  tangxin(tangxin_sysu@foxmail.com)
 /// @date    2019-01-29 23:40:28
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Base
{
public:
	Base()
	: _data(10)
	{ cout << "Base()" << endl; }

	virtual void a() { cout << "Base::a()" << endl; }
	virtual void b() { cout << "Base::b()" << endl; }
	virtual void c() { cout << "Base::c()" << endl; }
private:
	long _data;
};

class Derived
: public Base
{
public:
	Derived()
	: _data2(100)
	{ cout << "Derived()" << endl; }

	virtual void a() { cout << "Derived::a()" << endl; }
	virtual void b() { cout << "Derived::b()" << endl; }
	virtual void c() { cout << "Derived::c()" << endl; }
private:
	long _data2;
};

int main(void)
{
	cout << "sizeof(long) = " << sizeof(long) << endl; 
	Derived derived;

	long ** p = (long **)&derived;//二级指针指向derived的地址。
//	p[0][1];//虚表第二个地址，函数的入口地址。
	typedef void(*Function)();//return void, 无参
	Function f = (Function)p[0][0];
	f();
	f = (Function)p[0][1];
	f();
	f = (Function)p[0][2];
	f();
	long *p2 = (long*)&derived;
	cout << p2[2] << endl;
	cout << p2[1] << endl;

	return 0;

}
