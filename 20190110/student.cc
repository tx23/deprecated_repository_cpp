 ///
 /// @file    student.cc
 /// @author  tangxin(tangxin_sysu@foxmail.com)
 /// @date    2019-01-10 05:14:21
 ///
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

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

	void * operator new(size_t size)
	{
		void *pret = malloc(size);
		cout << "void *operator new(size_t)" << endl;
		return pret;
	}

	void operator delete(void *pret)
	{
		free(pret);
		cout << "void operator delete(void*)" << endl;
	}

private:
	int _id;
	char * _name;

};


int main(void)
{
	student * pstu = new student(100, "小明");
	pstu->print();

	delete pstu;
	return 0;
}
