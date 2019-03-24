 ///
 /// @file    testAuto.cc
 /// @author  tangxin(tangxin_sysu@foxmail.com)
 /// @date    2019-01-19 04:48:43
 ///
#include <string>
#include <iostream>

using std::cout;
using std::endl;
using std::string; 
int main(void)
{
	string s("hello world");
	for(auto elem:s)
		elem = 'a';
	cout << s << endl;
	for(auto &elem:s)
		elem = 'a';
	cout << s << endl;
	return 0;
}
