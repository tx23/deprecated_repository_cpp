 ///
 /// @file    global.cc
 /// @author  tangxin(tangxin_sysu@foxmail.com)
 /// @date    2019-02-21 06:20:06
 ///
 
#include <iostream>
using std::cout;
using std::endl;
//测试全局变量和局部变量同名是否会覆盖 
int a = 10;

int test(void)
{
	a = 5;
	cout << "after define a:" << a << endl;
	return 0;
}

int main() {
	cout << "未定义局部变量时：" << a << endl;
	test();
	cout << "after run the test:" << a << endl;
	return 0;
}
