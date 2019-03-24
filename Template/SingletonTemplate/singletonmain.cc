 ///
 /// @file    singletonmain.cc
 /// @author  tangxin(tangxin_sysu@foxmail.com)
 /// @date    2019-01-21 03:28:33
 ///
#include "singleton.h" 
#include <iostream>
using std::cout;
using std::endl;
 
class Point
{
public:
	Point(int x = 0, int y = 0)
	: _x(x)
	, _y(y)
	{ cout << "Point(int=0, int=0)" << endl;}

	~Point() {
		cout << "~Point" << endl;
	}

	void print() const
	{
		cout << "(" << _x
			 << "," << _y
			 << ")" << endl;
	}

private:
	int _x;
	int _y;
};


int main(void)
{
	Point *p1 = Singleton<Point>::getInstance(1, 2);
	Point *p2 = Singleton<Point>::getInstance(2, 4);
	p1->print();
	p2->print();

	cout << "p1 = " << p1 << endl
		 << "p2 = " << p2 << endl;
	
	int *pt1 = Singleton<int>::getInstance(1);
	int *pt2 = Singleton<int>::getInstance(2);

	cout << "p1 = " << pt1 << endl
		 << "p2 = " << pt2 << endl;
	return 0;
}
