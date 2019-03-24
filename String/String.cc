 ///
 /// @file    String.cc
 /// @author  tangxin(tangxin_sysu@foxmail.com)
 /// @date    2019-01-14 04:50:21
 ///
#include <stdlib.h>
#include <stdio.h>
#include <sstream>
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;
using namespace std; 
class String {
public:
	String();
	String(const char *);//自定义复制构造函数
	String(const String &);//复制构造函数
	~String();
	String & operator = (const String &);//赋值运算符
	String & operator = (const char *);
	
	String & operator += (const String &);//复合赋值
	String & operator += (const char *);
	
	char & operator[] (size_t index);//下标运算符
	const char &operator[](size_t index) const;

	size_t size() const;//返回长度
	const char* c_str() const;

	friend bool operator == (const String &, const String &);
	friend bool operator != (const String &, const String &);
	friend bool operator <= (const String &, const String &);
	friend bool operator >= (const String &, const String &);
	friend bool operator < (const String &, const String &);
	friend bool operator > (const String &, const String &);

	friend ostream&operator << (ostream &os, const String &s);
	friend istream&operator >> (istream &is, String &s);



private:
	char *_pstr;
};
String operator + (const String &, const String &);
String operator + (const String &, const char *);
String operator + (const char *, const String &);

String::String()
{
	cout << "String()" << endl;
	_pstr = new char[2];
	strcpy(_pstr, " ");
}

String::~String()
{
	cout << "~String" << endl;
	delete []_pstr;
}

String::String(const char *pstr)
{
	cout << "String(const char *)" << endl;
	_pstr = new char[strlen(pstr) + 1];
	strcpy(_pstr, pstr);
}

String::String(const String &ss)
{
	cout << "String(const string &)" << endl;
	_pstr = new char[strlen(ss._pstr) + 1];
	strcpy(_pstr, ss._pstr);
}

String&String::operator=(const String & ss)
{
	cout << "operator = (cosnt string &)" << endl;
	this -> ~String();
	_pstr = new char[strlen(ss._pstr) + 1];
	strcpy(_pstr, ss._pstr);
	return *this;
}

String&String::operator=(const char*ss)
{
	cout << "operator = (const char*)" << endl;
	this -> ~String();
	_pstr = new char[strlen(ss) + 1];
	strcpy(_pstr, ss);
	return *this;
}

String & String::operator+=(const String &ss)
{
	cout << "operator+=(const string &)" << endl;
	String tmp;
	tmp._pstr = new char[strlen(this->_pstr)+1]();
	strcpy(tmp._pstr, this->_pstr);
	delete [] this->_pstr;
	this -> _pstr = new char[strlen(tmp._pstr)+strlen(ss._pstr)+1]();
	sprintf(this->_pstr,"%s%s", tmp._pstr, ss._pstr);
	return *this;
}


String & String::operator+=(const char*ss) {
	String tmp(_pstr);
	*this += tmp;
	return *this;
}


ostream&operator<<(ostream & os, const String &ss)
{
	cout << endl <<"operator << " << endl;
	os << ss._pstr;
	return os;
}

istream&operator>>(istream & is, String &ss)
{
	cout << endl << "operator >> " << endl;
	is >> ss._pstr;
	return is;
}

char&String::operator[](size_t index)
{
	cout << "operator[]" << endl;
	int len = strlen(this->_pstr);
	char *a= (char*)calloc(len, sizeof(char));
	strcpy(a, _pstr);
	return a[index];
}

const char& String::operator[](size_t index) const
{
	cout << "operator[]const" << endl;
	int len = strlen(this->_pstr);
	char *a=(char*)calloc(len, sizeof(char));
	strcpy(a, _pstr);
	return a[index];
}

size_t String::size()const
{
	cout << "size()const" << endl;
	int len = strlen(this->_pstr);
	return len;
}

const char*String::c_str()const
{
	cout << "c_str()" << endl;
	int len = strlen(this->_pstr + 1);
	char *a=(char*)calloc(len, sizeof(char));

	strcpy(a, _pstr);
	return a;
}

bool operator == (const String & a1, const String & a2)
{
	cout << "operator ==" << endl;
//	return a1 == a2;
	if((strcmp(a1.c_str(), a2.c_str()))==0)
		return 1;
	else
		return 0;

}
bool operator != (const String & a1, const String & a2)
{
	cout << "operator !=" << endl;
	if((strcmp(a1.c_str(), a2.c_str()))!=0)
		return 1;
	else
		return 0;

}

bool operator < (const String & a1, const String & a2)
{
	cout << "operator <" << endl;
	if((strcmp(a1.c_str(), a2.c_str()))<0)
		return 1;
	else
		return 0;

}

bool operator > (const String & a1, const String & a2)
{
	cout << "operator >" << endl;
	if((strcmp(a1.c_str(), a2.c_str()))>0)
		return 1;
	else
		return 0;

}

bool operator <= (const String & a1, const String & a2)
{
	cout << "operator <=" << endl;
	if((strcmp(a1.c_str(), a2.c_str()))<=0)
		return 1;
	else
		return 0;

}

bool operator >= (const String & a1, const String & a2)
{
	cout << "operator >=" << endl;
	if((strcmp(a1.c_str(), a2.c_str()))>=0)
		return 1;
	else
		return 0;

}

String operator + (const String &a1, const String &a2)
{
	cout << "operator + (const String&, const String&)" << endl;
	String pstr(a1);
	pstr += a2;
	return pstr;
}

String operator + (const String &a1, const char*a2)
{
	cout << "operator + (const String&, const char*)" << endl;
	String pstr = a1;
	pstr += a2;
	return pstr;
}


String operator + (const char*a1, const String&a2)
{
	cout << "operator + (const char*, const String&)" << endl;
	String pstr(a1);
	pstr+=a2;
	return pstr;
}

int main(void) {
	String test1;//test1 = null
	cout << "test1 = " << test1 << endl;
	String test2("hello");//test2 = hello
	cout << "test2 = " << test2 << endl;
	String test3(test2);//test3 = hello
	cout << "test3 = " << test3 << endl;
	String test4 = "wuhan";//test4 = wuhan
	cout << "test4 = " << test4 << endl;
	String test5 = test4;//test5 = wuhan
	cout << "test5 = " << test5 << endl;
	test2 += "wuhan";//test2 = hello wuhan
	cout << "test2 = " << test2 << endl;
	test3 += test4;//test3 = hello wuhan
	cout << "test3 = " << test3 << endl;
	cout << "test2[2] = " << test2[2] <<endl;
	cout << "test2.size() = " << test2.size() << endl;
	int a = (test2 == test3);
	cout << "test2 == test3" << a << endl;
	int b = (test2 != test3);
	cout << "test2 != test3" << b << endl;
	int c = (test2 > test3);
	cout << "test2 != test3" << c << endl;


}
