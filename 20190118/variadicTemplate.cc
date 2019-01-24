 ///
 /// @file    variadicTemplate.cc
 /// @author  tangxin(tangxin_sysu@foxmail.com)
 /// @date    2019-01-18 03:34:30
 ///
#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::string;

template <typename... Args>//Args 模板参数包
void printf(Args... args)  //args函数参数包
{
	cout << "sizeof...(Args) = " << sizeof...(Args) << endl;
	cout << "sizeof...(args) = " << sizeof...(Args) << endl;
}

void display()
{
	cout << endl;//递归出口，要在递归前定义
}
template <class T, class...Args>
void display(T t, Args... args)//声明时...在参数包左边
{
	cout << t << " ";
	display(args...);//当...在参数包右边时，表示展开参数包
}//递归打印，压栈到出栈的过程


//递归求和
template<class T>
	T sum(T t)
	{ return t;}

	template <class T, class...Args>
	T sum(T t, Args ...args)
	{
		return t + sum(args...);
	}

int test2(void) {
	
	cout << "sum(1, 2, 3, 4, 5, 6, 7)"
		 << sum(1, 2, 3, 4, 5, 6, 7) << endl;
	return 0;
}
int test0(void)
{
	string s1 = "hello";
	printf();
	printf(1, 2.2);
	printf('a', true, s1);
	printf(1, 3.2, 's', "world");
	return 0;
}

int test1(void)
{
	string s1 = "hello";
	display(1);
	display(1, 2.2);
	display('a', true, s1);
	display(1, 3.2, 's', "world");
	return 0;
}
int main()
{
	test2();
	//test1();
	return 0;
}

