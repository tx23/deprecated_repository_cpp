#include<iostream>
using std::cout;
using std::endl;

int main()
{
	int value1 = 100;
	int const* p1 = &value1; // const 在*左边为常量指针
//	*p1 = 101;
	cout << "*p1 = " << *p1 << endl;// 指针所指值不能改

	int value2 = 100;
	const int* p2 = &value2; // const 在*左边为常量指针
//	*p2 = 102;
	cout << "*p2 = " << *p2 << endl;//同上

	int value3 = 100;
	int* const p3 = &value3; // const 在*右边为指针常量
	*p3 = 103;
	cout << "*p3 = " << *p3 << endl;//指针所指值可以通过指针改

	return 0;
}
