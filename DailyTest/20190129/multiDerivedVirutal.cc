#include <iostream>
using std::cout;
using std::endl;
//重复定义，可画图观察是否覆盖，基类A的指针只能控制派生类的A部分。
//当出现继承两个基类同名函数且自身未重定义时发生二义性。可通过类名指定相应函数
class A
{
public:
	virtual void a() {	cout << "A::a()" << endl;	}
	virtual void b() {	cout << "A::b()" << endl;	}
	virtual void c() {	cout << "A::c()" << endl;	}
};
 
class B
{
public:
	virtual void a() {	cout << "B::a()" << endl;	}
	virtual void b() {	cout << "B::b()" << endl;	}
	void c() {	cout << "B::c()" << endl;	}
	void d() {	cout << "B::d()" << endl;	}
};

class C
: public A
, public B
{
public:
	virtual void a() {	cout << "C::a()" << endl;	}
	void c() {	cout << "C::c()" << endl;	}
	void d() {	cout << "C::d()" << endl;	}
};

int main(void)
{
	A a;
	B b;

	C c;
	A * pA = &c;
	cout << "pA = " << pA << endl;
	pA->a();//C::a()
	pA->b();//A::b()
	pA->c();//C::c()
	cout << endl;

	B * pB = &c;
	cout << "pB = " << pB << endl;
	pB->a();//C::a()
	pB->b();//B::b()
	pB->c();//B::b()
	pB->d();//B::d()
	cout << endl;

	C * pC = &c;
	cout << "pC = " << pC << endl;
	pC->a();//C::a()
	//pC->b();//error二义性
	pC->A::b();
	pC->B::b();
	pC->c();//C::c()
	pC->d();//C::d()

	return 0;
}
