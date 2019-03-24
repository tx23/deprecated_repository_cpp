 ///
 /// @file    Circle.cc
 /// @author  tangxin(tangxin_sysu@foxmail.com)
 /// @date    2019-01-28 06:41:13
 ///
 
#include <iostream>
using std::cout;
using std::endl;
#define PI 3.14

class Circle
{
public:
	Circle()
	: _r(0)
	{ cout << "Circle()" << endl; }
	
	Circle(double r = 0)
	: _r(r)
	{ cout << "Circle(double)" << endl; }

	double getArea() const//获取圆的面积
	{
		return PI*_r*_r;
	}

	double getPerimeter() const
	{
		return 2*PI*_r;
	}

	void show()
	{
		cout << "the radius is: " << _r << endl
			 << "rhe area is: " << getArea() << endl
			 << "the perimeter is: " << getPerimeter() << endl;
	}
private:
	double _r;
};

class Cylinder
: public Circle
{
public:
	Cylinder(double r=0, double h=0)
	: Circle(r)
	, _h(h)
	{ cout << "Cylinder(double, double)" << endl;}
	
	double getVolume() const
	{
		return _h*getArea();
	}

	void showVolume() const 
	{
		cout << "the volume is: " << getVolume() << endl;
	}

private:
	double _h;
};
int main(void)
{
	Cylinder p(1, 1);
	p.show();
	p.showVolume();
	return 0;
}
