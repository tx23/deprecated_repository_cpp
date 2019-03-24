 ///
 /// @file    figure_OOP.cc
 /// @author  tangxin(tangxin_sysu@foxmail.com)
 /// @date    2019-01-29 05:40:54
 ///
 
#include <iostream>
using std::cout;
using std::endl;
//面向对象设计原则
//对扩展开放，对修改关闭
//
//动态多态的实现：继承+虚函数

class Figure
{
public:
	virtual void display() const = 0;
	virtual double area() = 0;
};

void display(Figure & fig)
{
	fig.display();
	cout << "'s area is: " << fig.area() << endl;
}

class Circle
: public Figure
{
public:
	Circle(double radius)
	: _radius(radius)
	{}

	void display() const
	{ cout << "the circle"; }

	double area()
	{ return 3.14*_radius*_radius; }
private:
	double _radius;
};

int main(void)
{
	Circle circle(3); 
	display(circle);
}
