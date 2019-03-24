 ///
 /// @file    char_const.cc
 /// @author  tangxin(tangxin_sysu@foxmail.com)
 /// @date    2019-02-21 06:49:40
 ///
#include <iostream>
using std::cout;
using std::endl;
//测试转义字符 
int main(void)
{
//	cout << ">>>>>" << endl;
//	cout << "\\ \' \" \? a 6个a:aaaaaa\b \f" << endl; 
	cout << ">>>>>\r<<<<<\t>>>>>\v<<<<<" << endl;
		// << \ooo << a << "\xhh" << a << endl;
	return 0;
}
