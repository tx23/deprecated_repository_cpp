 ///
 /// @file    virtualFunction2.cc
 /// @author  tangxin(tangxin_sysu@foxmail.com)
 /// @date    2019-01-29 03:26:34
 ///
 
#include <iostream>
using std::cout;
using std::endl;
//在成员函数中调用虚函数，表现多态的特性
class Base
{
public:
	Base() { cout << "Base()" << endl; }

	virtual void display() const
	{ cout << "Base::display()" << endl;}

	void baseFunc1()
	{ display(); }//this->display();

	void baseFunc2()
	{ Base::display(); }
};

class Derived
: public Base
{
public:
	Derived()
	: Base()
	{ cout << "Derived()" << endl; }
	
	void display() const// override
	{ cout << "Derived::display()" << endl; }

};


int main(void)
{
	cout << "sizeof(Base)" << sizeof(Base) << endl;
	cout << "sizeof(Derived)" << sizeof(Derived) << endl;
	Base base;
	Derived derived;

	Base * pbase = & base;
	pbase->baseFunc1();
	pbase->baseFunc2();

	pbase = &derived;
	pbase->baseFunc1();
	pbase->baseFunc2();
	
	return 0;
}
