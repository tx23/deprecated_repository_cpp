 ///
 /// @file    remove.cc
 /// @author  tangxin(tangxin_sysu@foxmail.com)
 /// @date    2019-01-23 06:41:50
 ///
#include <algorithm>
#include <vector>
#include <iterator>
#include <iostream>
using std::vector;
using std::ostream_iterator;
using std::remove_if;
using std::cout;
using std::endl;
 
bool func(int number)
{
	return number > 3;
}

void test0()
{
	vector<int> n{1, 3, 4, 2, 4, 6, 7, 9};
	std::copy(n.begin(), n.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	//remove_if 将满足func的往后移
	auto it = remove_if(n.begin(), n.end(), func);
	std::copy(n.begin(), n.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	//erase-remove惯用法
	n.erase(it, n.end());
	std::copy(n.begin(), n.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

}

void test1()
{//迭代器失效，底层扩容时，将原空间销毁可迭代器未更新
	vector<int> n;
	n.push_back(1);
	bool flag = true;
	for (auto it = n.begin(); it != n.end(); ++ it)
	{
	cout << *it << " ";
	if(flag) {
		n.push_back(2);
		flag = false;
		it = n.begin();//需要重置迭代器
	}
	}
}

int main(void)
{
	//test0();
	test1();
	return 0;
}
