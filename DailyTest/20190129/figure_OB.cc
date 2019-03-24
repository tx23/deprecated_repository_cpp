 ///
 /// @file    figure_OOP.cc
 /// @author  tangxin(tangxin_sysu@foxmail.com)
 /// @date    2019-01-29 05:40:54
 ///
 
#include <iostream>
#include <functional>
using std::cout;
using std::endl;
using std::function;
using std::bind;
using std::move;
//基于对象
//std::function + std::bind 结合实现多态
//
//在使用上更灵活多变，限制更少

class Figure//具体类
{
public:
	void setDisplay(function<void()> && a)
	{ _display = move(a);}

	void setArea(function<double()> && b)
	{ _area = move(b);}

	void handleDisplay() const
	{
		if(_display)
			_display();
	}

	double handleArea() const
	{
		if(_area)
			return _area();
		else return 0;
	}

	function<void()> _display;//返回为void类型无参的函数
	function<double()> _area;//返回为double类型无参的函数
};


class Circle
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
void display(const Figure & fig)
{
	fig.handleDisplay();
	cout << "'s area is: " << fig.handleArea() << endl;
}

int main(void)
{
	Circle circle(3);

	Figure figure;
	figure.setDisplay(bind(&Circle::display, &circle));
	figure.setArea(bind(&Circle::area, &circle));
	display(figure);
	return 0;
}
