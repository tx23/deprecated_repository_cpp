 ///
 /// @file    point3d.cc
 /// @author  tangxin(tangxin_sysu@foxmail.com)
 /// @date    2019-01-28 04:12:49
 ///
 
#include <iostream>
using std::cout;
using std::endl;
class Point
{
public:
	Point(int x = 0,  int y = 0)
	: _x(x)
	, _y(y)
	{
		cout << "Point(int = 0, int = 0)" << endl;
	}

	int getY() const
	{ return _y; }

protected://对其派生类开发
	int _x;
private://私有成员只有在本类内部访问
	int _y;
};

class Point3d
: public Point//public继承===》借口继承
{
public:
	Point3d(int x = 0, int y = 0, int z = 0)
	: Point(x, y)
	, _z(z)
	{
		cout << "Point(int=0, int=0, int=0)" << endl;
	} 

	void display() const
	{
		cout << "(" << _x
			 << "," << getY()
			 << "," << _z 
			 << ")" << endl;
	}
private:
	int _z;
};

int main(void)
{
	Point3d pt3d(1, 1, 2);
	//pt3d._y;//error对派生类对象而言不能访问基类的私有及保护成员。
	pt3d.getY();
	//对public派生类对象而言，只能访问基类成员的public成员
	pt3d.display();
}
