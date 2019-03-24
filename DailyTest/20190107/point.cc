#include<iostream>
using std::cout;
using std::endl;


class Point
{
public:
//当类中未显示定义构造函数时，编译器会自动提供一个默认构造函数
//Point(){} 默认（无参）构造函数的形式。
	//构造函数的作用就是用来初始化数据成员的
	Point(int ix, int iy) //构造函数，类名（参数）
	{
		_ix = ix;
		_iy = iy;
		cout << "Point(int, int)" << endl;
	}

	void print()
	{
		cout << "(" << _ix
			 << "," << _iy
			 << ")" << endl;
	}
	//析构函数只有一个,无参
	~Point()
	{
		cout << "~point(int, int)" << endl;
	}

private:
	int _ix;
	int _iy;

};

int main(void)
{
	Point pt1(1, 2);
	pt1.print();

	return 0;
}
