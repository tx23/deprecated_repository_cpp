 ///
 /// @file    abstract_class.cc
 /// @author  tangxin(tangxin_sysu@foxmail.com)
 /// @date    2019-01-29 06:47:32
 ///
 
#include <iostream>
using std::cout;
using std::endl;
//定义了protected型构造函数的类也称为抽象类
class Base
{
protected:
	Base()
	{ cout << "Base()" << endl; }
};

class Derived
:public Base
{
public:
	Derived()
	: Base()
	{ cout << "Derived()" << endl; }

	void display()
	{ cout << "Derived::display()" << endl; }

};
int main(void)
{
	//Base base;
	Derived d;
	d.display();
	return 0;
}
