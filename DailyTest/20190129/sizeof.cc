 ///
 /// @file    sizeof.cc
 /// @author  tangxin(tangxin_sysu@foxmail.com)
 /// @date    2019-01-29 04:36:51
 ///
 
#include <iostream>
using std::cout;
using std::endl;
#pragma pack(8)//按8字节对齐

class Example
{
public:
	Example(int &ref)
	: _ref(ref)
	{}

	virtual void display() const
	{ cout << "Example::display()" << endl; }

private://内存布局与系统位数有关，大的放前面
	double _dd;   //8
	int & _ref;   //8
	short _sc[6]; //12
	int _ia;      //4
	char _cb;     //1
	static float _fe;//4
};

int main(void)
{
	cout << "sizeof(Example) = " << sizeof(Example) << endl; 
	return 0;
}
