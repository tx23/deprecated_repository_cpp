 ///
 /// @file    pure_virtual.cc
 /// @author  tangxin(tangxin_sysu@foxmail.com)
 /// @date    2019-01-29 04:57:04
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class A
{//抽象类作为借口而存在，并不能直接创建对象
public:
	virtual void display() = 0;//声明了纯虚函数的类称为抽象类，抽象类不能创建对象。
	virtual void print()=0;
};

class B
: public A
{
public:
	void display()
	{ cout << "B::display()" << endl;}
};

class C
: public B
{//对派生类而言，只要有一个纯虚函数没有实现，该派生类也会成为抽象类，从而不能创建对象
public:
	void print() { cout << "C::print()" << endl; }
};
int main(void)
{
	//A a;
	//B b;
	C c;
	c.display();
	c.print();
	return 0;
}
