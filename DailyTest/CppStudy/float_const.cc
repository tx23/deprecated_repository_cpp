 ///
 /// @file    float_const.cc
 /// @author  tangxin(tangxin_sysu@foxmail.com)
 /// @date    2019-02-21 06:38:04
 ///
 
#include <iostream>
using std::cout;
using std::endl;
//测试浮点常量 
int main(void)
{
	const float a = .1;
//	const float b = 1E;error
	float c = 1.2f;
	cout << 2.1E2 << endl;//210
	return 0;
}
