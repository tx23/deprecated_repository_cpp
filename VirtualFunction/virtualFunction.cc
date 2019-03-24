 ///
 /// @file    virtualFunction.cc
 /// @author  tangxin(tangxin_sysu@foxmail.com)
 /// @date    2019-01-29 03:00:52
 ///
 
#include <iostream>
using std::cout;
using std::endl;
//虚函数，实现对display的多态

class Base
{
public:
	Base() 
	: _dbase(0)
	{ cout << "Base()" << endl; }

	virtual
	void display() const
	{
		cout << "Base::display _dbase = " << _dbase << endl;
	}
private:
	double _dbase;
};

class Derived1
: public Base
{
public:
	Derived1()
	: _derived1(10)
	{ cout << "Derived1" << endl;}

	virtual
	void display() const//重定义虚函数
	{ cout << "Derived1::display() _drived1 = " << _derived1 << endl;}

private:
	double _derived1;
};

class Derived2
: public Base
{
public:
	Derived2()
	: _derived2(100)
	{ cout << "Derived2" << endl;}

	virtual
	void display() const
	{ cout << "Derived2::display() _drived2 = " << _derived2 << endl;}

private:
	double _derived2;
};

void display(Base * pbase)//Base指针可指向派生类对象
{ pbase->display(); }//同一指令对不同对象产生不同的行为

void display2(Base & pbase)
{ pbase.display(); }//引用也可提现多态机制

void test0(void)
{
	Base base;
	Derived1 derived1;
	Derived2 derived2;

	display(&base);
	display(&derived1);
	display(&derived2);
}

void test1(void)
{
	Base base;
	Derived1 derived1;
	Derived2 derived2;

	display2(base);
	display2(derived1);
	display2(derived2);
}
int main(void)
{
	//test0();
	test1();
	return 0;
}


