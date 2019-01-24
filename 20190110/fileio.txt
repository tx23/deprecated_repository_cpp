 ///
 /// @file    cin.cc
 /// @author  tangxin(tangxin_sysu@foxmail.com)
 /// @date    2019-01-10 07:16:20
 ///
 
#include <iostream>
#include <string>
#include <limits>
using std::cout;
using std::cin;
using std::endl;
using std::string;

void printCinStat() 
{
	cout << "cin's badbit = " << cin.bad() << endl
		 << "cin's failbit = " << cin.fail() << endl
		 << "cin's eofbit = " << cin.eof() << endl
		 << "cin's goodbit = " << cin.good() << endl;
}

void test0() 
{
	int number = 0;
	printCinStat();
	while(cin >> number)//, !cin.eof())  //直到输入的不是int
	{
	cout << "number = " << number << endl;
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	printCinStat();
	}

	cin.clear(); //重置流的状态
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				//未清空会将之前错误信息输出
	cout << "重置流状态后" << endl;
	printCinStat();

	string s1;
	cin >> s1;
	cout << "s1 = " << s1 << endl;
}
int main(void)
{
	test0();
	return 0;
}
