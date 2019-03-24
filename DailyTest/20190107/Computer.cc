#include<string.h>
#include<iostream>
using std::cout;
using std::endl;

class Computer//对于class而言，默认访问权限为private。
{             //对于struct而言，默认访问权限为public。
public:
	void setBrand(const char* brand)
	{
		strcpy(_brand, brand);
	}

	void setPrice(float price)
	{
		_price = price;
	}

	void print()
	{
		cout << "brand = " << _brand << endl
			 << "price = " << _price << endl;
	}
private: //可多次定义
protected:
private://类外部不能直接访问。
	char _brand[20]; //成员变量常用写法 brand_ m_brand。
	float _price;

};

int main() 
{
	Computer computer;
	computer.setBrand("Lenovo");
	computer.setPrice(5555);
	computer.print();
//	computer._brand = "Thinkpad";error 私有成员不能在类之外访问
	return 0;
}
