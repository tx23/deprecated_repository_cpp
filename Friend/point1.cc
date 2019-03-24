 ///
 /// @file    pointFriend.cc
 /// @author  tangxin(tangxin_sysu@foxmail.com)
 /// @date    2019-01-13 03:04:22
 ///
#include <math.h>
#include <iostream>
using std::cout;
using std::endl;


//友元之普通函数

class Point{
//友元不受访问权限的限制
	friend float distance(const Point & lhs, const Point &rhs);
public:
	Point(int ix=0, int iy=0)	
	: _ix(ix)
	, _iy(iy)
	{
	cout << "Point(int, int)" << endl;
	}

	void print() const
	{
		cout << "(" << _ix
			 << "," << _iy
			 << ")" ;
	}
private:
	int _ix;
	int _iy;
};

float distance(const Point & lhs, const Point & rhs)
{	
	return hypot(lhs._ix - rhs._ix, lhs._iy - rhs._iy);
}


int main(void)
{
	Point pt1(1, 2);
	Point pt2(2, 3);

	pt1.print();
	cout << "到" ;
	pt2.print();
	cout << "的距离:" << distance(pt1, pt2) << endl;
	return 0;
}
