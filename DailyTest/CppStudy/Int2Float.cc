 ///
 /// @file    Int2Float.cc
 /// @author  tangxin(tangxin_sysu@foxmail.com)
 /// @date    2019-03-04 20:08:55
 ///
//类型转换测试 
#include <iostream>
using std::cout;
using std::endl;
 
int main(void)
{
	int b = 4;
	cout << sizeof(b) << endl;
	int a(char) = 1;
	cout << sizeof(a) << endl;
	return 0;
}
