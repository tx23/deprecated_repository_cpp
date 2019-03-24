 ///
 /// @file    bind.cc
 /// @author  tangxin(tangxin_sysu@foxmail.com)
 /// @date    2019-01-23 07:03:21
 ///
#include <functional> 
#include <iostream>
using std::cout;
using std::endl;
using std::bind;
int add(int x, int y)
{
	cout << "int add(int, int)" << endl;
	return x+y;
}

class Add
{
public:
	int add(int x, int y)
	{
		cout << "Add::add(int , int)" << endl;
		return x+y;
	}

	int data = 1024;
};

void test0(void)
{
	auto f1 = bind(add, 1, 2);
	cout << "f1() = " << f1() << endl;

	Add e1;
	auto f2 = bind(&Add::add, &e1, 1, 2);
	cout << "f2() = " << f2() << endl;

	//占位符
	using namespace::std::placeholders;
	auto f3 = bind(add, _1, 2);
	cout << "f3(1) = " << f3(1) << endl;
}

//C 用函数指针的方法实现回调函数
int func() { return 5; }
void test1(void)
{
	typedef int(*Function)();
	Function f1 = &func;//注册回调函数
	cout << "f1() = " << f1() << endl;//执行回调函数
	

}

void func2(int x1, int x2, int x3, int x4, const int& x5)
{
	cout << "(" << x1
		 << "," << x2
		 << "," << x3
		 << "," << x4
		 << "," << x5
		 << ")" << endl;
}
void test2(void)
{
	using namespace std::placeholders;
	int n = 100;
	auto f = bind(func2, 1, _4, _2, n, std::cref(n));
//占位符的位置决定形参的位置，数字决定调用哪个实参。
	n = 200;
	f(23, 32, 55, 66, 77, 88, 90);
}

int main(void)
{
	//test0();
	//test1();
	test2();
	return 0;
}
