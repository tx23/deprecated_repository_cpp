 ///
 /// @file    student.cc
 /// @author  tangxin(tangxin_sysu@foxmail.com)
 /// @date    2019-01-10 05:14:21
 ///
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;
//只能生成栈对象
class student {
public:
	student(int id, const char * name)
	:_id(id)
	,_name(new char[strlen(name) + 1]())
	{
		cout << "student(int, const char*)" << endl;
		strcpy(_name, name);
	}

	void print() const
	{
		cout << "id:" << _id << endl
			 << "name:" << _name << endl;
	}
	~student()
	{
		delete [] _name;
		cout << "~student()" << endl;
	}
private:
	void * operator new(size_t size);

	void operator delete(void *pret);

private:
	int _id;
	char * _name;

};


int main(void)
{
//	student * pstu = new student(100, "小明");
	student s1(101, "杨超越");
	s1.print();

//	delete pstu;
	return 0;
}
