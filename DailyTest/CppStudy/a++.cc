 ///
 /// @file    a++.cc
 /// @author  tangxin(tangxin_sysu@foxmail.com)
 /// @date    2019-03-04 19:00:00
 ///
 
#include <iostream>
using std::cout;
using std::endl;
 
int main(void)
{
	int a = 1, b = 1;
	int c, d;
	c = a++;
	d = ++b;
	cout << "a = 1 :" << endl;
	cout << "a++ = " << c << endl;
	cout << "++a = " << d << endl;
}
