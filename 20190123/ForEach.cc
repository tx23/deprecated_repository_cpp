 ///
 /// @file    ForEach.cc
 /// @author  tangxin(tangxin_sysu@foxmail.com)
 /// @date    2019-01-23 05:51:36
 ///
#include <vector> 
#include <iostream>
#include <algorithm>
using std::cout;
using std::endl;
using std::vector;
using std::for_each;


void test0()
{
	static int sum = 0;//实现求和
	vector<int> numbers{1, 2, 3, 4, 5};
	for_each(numbers.begin(), numbers.end(), [](int & n)
	//传入引用方可改变容器中的值,lambda表达式（匿名函数）
			{
			sum+=n;
		//	cout << sum << " ";
			});
	cout << sum;
	cout << endl;
//等价于for(int idx=numbers.begin();idx!=numbers.end();++idx)
	for(auto&elem : numbers)
		cout << elem << " ";
	cout << endl;
	
}

void display(int &n)
{
	cout << n << " ";
}

void test1()//查找
{
	vector<int> numbers{1, 2, 3, 6, 2, 4, 2, 9, 7, 8};
	std::sort(numbers.begin(), numbers.end());
	for_each(numbers.begin(), numbers.end(), display);
	//默认为一个参数传入display
	cout << endl;
	//可查找无序的，O(N)
	int ret1 = std::count(numbers.begin(), numbers.end(), 2);//查找2的个数
	cout << ret1 << endl;
	//有序，二分查找O(logN),返回bool类型
	bool ret2 = std::binary_search(numbers.begin(), numbers.end(), 2);
	cout << ret2 << endl;
	auto ret3 = std::lower_bound(numbers.begin(), numbers.end(), 5);
	cout << *ret3 << endl;
	for_each(numbers.begin(), numbers.end(), display);
	cout << endl;

	//O(N)find返回value第一次出现的位置
	auto it = std::find(numbers.begin(), numbers.end(), 3);
	++*it;
	cout << *it << endl;
	for(auto&elem : numbers)
		cout << elem << " ";
	cout << endl;

	
}


int main(void)
{
	//test0();
	test1();
	return 0;
}
