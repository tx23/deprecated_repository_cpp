 ///
 /// @file    destructor.cc
 /// @author  tangxin(tangxin_sysu@foxmail.com)
 /// @date    2019-01-29 06:51:46
 ///
 
#include <iostream>
using std::cout;
using std::endl;
//将基类的析构函数设为虚函数，可避免在用基类指针指向派生类
//函数后发生的内存泄漏。

class Base
{
public:
	Base()
	: _pdata(new int(0))
	{ cout << "Base()" << endl;}

	virtual void display() const
	{ cout << "Base::display() *_pdata = " << *_pdata << endl;}

	virtual ~Base()
	{
		cout << "~Base()" << endl;
		delete _pdata;
	}

private:
	int * _pdata;
};

class Derived
: public Base
{
public:
	Derived(int data)
	: Base()
	, _pdata2(new int(data))
	{ cout << "Derived()" << endl; }
//将基类的析构函数设置为虚函数后，派生类析构函数会自动成为虚函数
	~Derived()
	{
		cout << "~Derived()" << endl;
		delete _pdata2;
	}
private:
	int *_pdata2;
};

int main(void)
{
	Base *p = new Derived(101);
	p->display();
	delete p;
	return 0;
}
