 ///
 /// @file    vectortest.cc
 /// @author  tangxin(tangxin_sysu@foxmail.com)
 /// @date    2019-01-11 03:37:15
 ///
 
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;
//类似动态数组，可自动扩容
//策略：1.未知空间大小时， 当达到容器容积时，自动开辟原空间两倍大小的空间
//		将原数据复制到新空间后，回收原空间。
//		2.若已知空间大小，可先开空间，避免反复开辟复制回收
//		.reserve(60);
void printVectorCapacity(const vector<int> & vec)
{
	//.size已存大小
	//.capacity容器体积
	cout << "vec's size = " << vec.size() << endl
		 << "vec's capacity = " 
		 << vec.capacity() << endl << endl;
		
}
int main(void)
{
	vector<int> numbers;
	numbers.reserve(10);//提前开辟空间
	//numbers[idx] = 10; idx [0，size）
	for(int i = 1; i <= 8; ++i) {
	numbers.push_back(1);
	printVectorCapacity(numbers);
	}

	return 0;
}
