 ///
 /// @file    String.cc
 /// @author  tangxin(tangxin_sysu@foxmail.com)
 /// @date    2019-01-25 05:13:38
 ///
#include <string.h> 
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;
 
class String
{
public:
	String()//无参形式
	: _pstr(new char[1]())
	{
		cout << "String()" << endl;
	}
	
	String(const char * pstr)//char*作为参数
	: _pstr(new char[strlen(pstr)+1]())
	{
		strcpy(_pstr, pstr);
		cout << "String(const char *)" << endl;
	}
//具有复制控制语义的函数
	String(const String & rhs)//const 引用作为参数，不能区分右值
	: _pstr(new char[strlen(rhs._pstr)+1]())
	{
		strcpy(_pstr, rhs._pstr);
		cout << "String(const &)" << endl;
	}
//复制运算符函数
	String & operator=(const String & rhs)
	{
		if(this != &rhs) {
			delete[] _pstr;
			_pstr = new char[strlen(rhs._pstr)+1]();
			strcpy(_pstr, rhs._pstr);
		}
		cout << "String operator=" << endl;
		return *this;
	}
	
	//移动构造函数
	//利用原先rhs的空间，不必新开辟空间
	String(String &&rhs)
	: _pstr(rhs._pstr)
	{
		rhs._pstr = NULL;//置为空就能避免浅拷贝的危害。
		cout << "String(String&&)" << endl;
	}
	//移动赋值运算符函数
	String & operator=(String && rhs)
	{
		if(this != &rhs) {
			delete [] _pstr;
			_pstr = rhs._pstr;
			rhs._pstr = NULL;
		}
		cout << "String operator=(&&)" << endl;
		return *this;
	}

	~String()
	{
		delete [] _pstr;
		cout << "~String()" << endl;
	}

	friend std::ostream & operator << (std::ostream & os, const String & rhs);
private:
	char *_pstr;

};

std::ostream & operator << (std::ostream & os, const String & rhs)
{
	os << rhs._pstr;
	return os;
}

int main(void)
{
	vector<String> vec;
	vec.push_back("hello, world");
//	String("world");//右值
//	"world";//左值
	String s1 = "world";
	s1 = std::move(s1);	
	String s2 = s1;
}
