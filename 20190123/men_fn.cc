 ///
 /// @file    men_fn.cc
 /// @author  tangxin(tangxin_sysu@foxmail.com)
 /// @date    2019-01-23 07:26:42
 ///
#include <functional>
#include <vector>
#include <algorithm>
#include <iostream>
using std::cout;
using std::endl;
using std::vector;
using std::for_each;
//删除偶数以及质数
class Number
{
public:
	Number(size_t data = 0)
	: _data(data)
	{}

	void display() const 
	{	cout << _data << " " ;	}

	bool isEven()  const
	{
		return (_data % 2 == 0);
	}

	bool isPrime() const
	{
		if(_data == 1)
		return false;

		for(size_t idx = 2; idx <= _data / 2; ++idx) 
		{
			if(_data % idx == 0)
				return false;
		}
		return true;
	}
							
private:
	size_t _data;
};
 
int main(void)
{
	vector<Number> numbers;
	for(size_t idx = 1; idx != 10; ++idx)
		numbers.push_back(Number(idx));

	//对于自定义类类型，如通过迭代器的方式进行访问，可以使用mem_fn来进行适配
	for_each(numbers.begin(), numbers.end(), std::mem_fn(&Number::display));
	cout << endl;

	numbers.erase(remove_if(numbers.begin(), numbers.end(), std::mem_fn(&Number::isEven)),
				  numbers.end());
	for_each(numbers.begin(), numbers.end(), std::mem_fn(&Number::display));
	cout << endl;

	numbers.erase(remove_if(numbers.begin(), numbers.end(), std::mem_fn(&Number::isPrime)),
			     numbers.end());
	for_each(numbers.begin(), numbers.end(), std::mem_fn(&Number::display));
	cout << endl;
	return 0;								
}

 
