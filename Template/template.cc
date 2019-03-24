 ///
 /// @file    template.cc
 /// @author  tangxin(tangxin_sysu@foxmail.com)
 /// @date    2019-01-18 03:11:56
 ///
#include <iostream>
using std::cout;
using std::endl;

	
class Point
{
public:
	Point(double ix = 0, double iy = 0)
	: _ix(ix)
	, _iy(iy)
	{}

	template <class T = int>
	T fun() 
	{
		return (T)_ix;
	}
	
	friend std::ostream & operator << (std::ostream & os, const Point & rhs);

private:
	double _ix;
	double _iy;
};

std::ostream & operator << (std::ostream & os, const Point & rhs)
{
	os << "(" << rhs._ix
	   << "," << rhs._iy
	   << ")" << endl;
	return os;
}

int main(void)
{
	Point pt(1.2, 2.1);
	cout << "pt.fun() = " << pt.fun<int>() << endl;
	cout << "pt.fun() = " << pt.fun() << endl;
	return 0;
}
