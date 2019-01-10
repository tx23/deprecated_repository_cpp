#include<stdio.h>
#include<string.h>
#include<iostream>
using std::cout;
using std::endl;

int a; //全局变量会自动初始化为0
char* p1;//全局变量自动初始化为null
static int c = 1;

int main() {
	int b;//位于栈中，未初始化
	char s[] = "123456";//位于栈区
	char* p2 ;//野指针
	char* p3 = "123456";//位于文字常量区
	p1 = new char[10]();
	p2 = new char[5]();
	strcpy(p1,"123456");

	
	printf("&a = %p\n", &a);
	printf("&p1 = %p\n", &p1);
	printf("p1 = %p\n", p1);
	printf("a = %d\n", a);
	cout << endl;

	printf("&b = %p\n", &b);
	printf("&p2 = %p\n", &p2);
	printf("p2 = %p\n", p2);
	printf("b = %d\n", b);
	printf("s = %p\n", s);
	printf("&p3 = %p\n", &p3);
	printf("p3 = %p\n", p3);
//	*p3 = 'X';文字常量区不可更改。
	
	printf("&main = %p\n", &main);
	printf("&c = %p\n", &c);
	printf("c = %d\n", c);

	printf("&123456 = %p\n", &"123456");
	
	delete p1;
	delete p2;
	return 0;

}
