 ///
 /// @file    cowString.cc
 /// @author  tangxin(tangxin_sysu@foxmail.com)
 /// @date    2019-01-15 19:34:29
 ///
#include <stdio.h>
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;
//写时复制实现string
//复制构造函数&重载赋值运算符时共享内存（计数器+1）
//共享内存的内容改变时发生写时复制
//如：[] = += +
class String
{
public:
	String()
	: _pstr(new char[5]() + 4)//此时_pstr位于内容处
	{
		cout << "String" << endl;
		initRefcount();
	}

	String(const char * pstr)
	: _pstr(new char[strlen(pstr) + 5]() + 4)
	{
		strcpy(_pstr, pstr);
		initRefcount();
		cout << "String(const char*)" << endl;
	}

	String(const String & rhs)
	: _pstr(rhs._pstr)
	{
		increaseRefcount();
		cout << "String(const String &)" << endl;
	}

	String & operator = (const String & rhs)
	{
		cout << "String & operator = (const String &)" << endl;
		if(this != &rhs) {
			release();

			_pstr = rhs._pstr;
			increaseRefcount();
		}
		return *this;
	}

	void release()
	{
		decreaseRefcount();
		if(refcount() == 0) {
			delete [] (_pstr-4);
			cout << "delete heap data." << endl;
		}
	}

	~String()
	{
		release();
		cout << "~String()" << endl;
	}

	int refcount() const
	{ return *(int*)(_pstr - 4);}

	const char * c_str() const
	{ return _pstr; }

	size_t size() const
	{ return strlen(_pstr); }
private:
	//代理模式
	class CharProxy
	{
	public:
		CharProxy(String & self, size_t idx)
		: _self(self)
		, _idx(idx)
		{}

		char & operator = (const char & ch);

		operator char()
		{ return _self._pstr[_idx]; }
	private:
		String & _self;
		size_t _idx;
	};
	friend std::ostream & operator << (std::ostream & os, const String & rhs);
public:
	CharProxy operator[](size_t idx)
	{ return CharProxy(*this, idx);}
private:
	void initRefcount()//类内部的函数均为inline
						// 
	{
		*(int*)(_pstr - 4) = 1;
	}

	void increaseRefcount()
	{
		++*(int *)(_pstr - 4);
	}

	void decreaseRefcount()
	{
		--*(int *)(_pstr - 4);	
	}

private:
	char * _pstr;
};

std::ostream & operator << (std::ostream &os, const String &rhs)
{
	os << rhs._pstr;
	return os;
}

char & String::CharProxy::operator=(const char & ch)
{
	if(_idx < _self.size()) {
		if(_self.refcount() > 1) {
			char *ptmp = new char[_self.size() + 5]() + 4;
			strcpy(ptmp, _self._pstr);

			_self.decreaseRefcount();
			_self._pstr = ptmp;
			_self.initRefcount();
		}
		_self._pstr[_idx] = ch;
		return _self._pstr[_idx];
	} else {
		static char nullchar = '\0';
		return nullchar;
	}
}

int main(void)
{
	String s1("hello"); 
	String s2 = s1;
	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;
	cout << "s1' refcount = " << s1.refcount() << endl;
	cout << "s2' refcount = " << s2.refcount() << endl;
	printf("s1's address = %p\n", s1.c_str());
	printf("s2's address = %p\n", s2.c_str());
	
	String s3("World");
	cout << endl << "after s3 = s1:" << endl;
	s3 = s1;// operator=()
	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;
	cout << "s3 = " << s3 << endl;
	cout << "s1' refcount = " << s1.refcount() << endl;
	cout << "s2' refcount = " << s2.refcount() << endl;
	cout << "s3' refcount = " << s3.refcount() << endl;
	printf("s1's address = %p\n", s1.c_str());
	printf("s2's address = %p\n", s2.c_str());
	printf("s3's address = %p\n", s3.c_str());

	cout << endl << "afther write s3[0]:" << endl;
	s3[0] = 'H';
	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;
	cout << "s3 = " << s3 << endl;
	cout << "s1' refcount = " << s1.refcount() << endl;
	cout << "s2' refcount = " << s2.refcount() << endl;
	cout << "s3' refcount = " << s3.refcount() << endl;
	printf("s1's address = %p\n", s1.c_str());
	printf("s2's address = %p\n", s2.c_str());
	printf("s3's address = %p\n", s3.c_str());

	cout << endl << "afther read s3[0]:" << endl;
	cout << "s1[0] = " << s1[0] << endl;
	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;
	cout << "s3 = " << s3 << endl;
	cout << "s1' refcount = " << s1.refcount() << endl;
	cout << "s2' refcount = " << s2.refcount() << endl;
	cout << "s3' refcount = " << s3.refcount() << endl;
	printf("s1's address = %p\n", s1.c_str());
	printf("s2's address = %p\n", s2.c_str());
	printf("s3's address = %p\n", s3.c_str());
	
	return 0;
}
