 ///
 /// @file    sequenceContainer1.cc
 /// @author  tangxin(tangxin_sysu@foxmail.com)
 /// @date    2019-01-18 07:00:01
 ///
#include <vector>
#include <deque>
#include <list>
#include <iostream>
using std::cout;
using std::endl;
using std::vector;
using std::deque;
using std::list;


void test0()
{
	//vector<int> numbers(10, 1);方法一
	
	//int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};方法二
	//vector<int> numbers(array, array + 10);
	
	vector<int> numbers{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};//法三
	cout << "numbers's size = " 
		 << numbers.size() << endl;
	cout << "numbers's capacity = " 
		 << numbers.capacity() << endl;
//迭代器，相当于一个指针。迭代器方式遍历
//	vector<int>::const_iterator cit;//可不加const 
//	for(cit = numbers.begin(); cit != numbers.end(); ++cit)
//	{ cout << *cit << " ";}
//	cout << endl;
	
	//C++11 要进行引用，不引用
	for(auto & elem:numbers) {
		cout << elem << " ";
	}
	cout << endl;
	//auto 自动推导，可用来简写迭代器
	auto it = numbers.begin();
	for(; it != numbers.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
}

 
void test1()
{
	int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	deque<int> numbers(array, array + 10);
	//deque<int> numbers(10, 1);
	cout << "numbers's size = " 
		 << numbers.size() << endl;
//	cout << "numbers's capacity = " 
//		 << numbers.capacity() << endl;//deque无capacity
//
//迭代器，相当于一个指针
	deque<int>::const_iterator cit;//可不加const 
	for(cit = numbers.begin(); cit != numbers.end(); ++cit)
	{
		cout << *cit << " ";
	}
	cout << endl;

}
void test2()
{
	int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	list<int> numbers(array, array + 10);
	//list<int> numbers(10, 1);
	cout << "numbers's size = " 
		 << numbers.size() << endl;
//	cout << "numbers's capacity = " 
//		 << numbers.capacity() << endl;//list无capacity
//
//迭代器，相当于一个指针
	list<int>::const_iterator cit;//可不加const 
	for(cit = numbers.begin(); cit != numbers.end(); ++cit)
	{
		cout << *cit << " ";
	}
	cout << endl;

}
 
int main(void)
{
	cout << endl << ">>>>vector:" << endl;
	test0();
	cout << endl << ">>>>deque:" << endl;
	test1();
	cout << endl << ">>>>list:" << endl;
	test2();

	return 0;
}
