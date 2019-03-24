#include<stdlib.h> // man malloc 可查看malloc 在哪个头文件中
#include<string.h> // menset 的头文件
#include<iostream>
using namespace std;

int* test0(void) 
{
	int *pInt = (int *)malloc(sizeof(int));//开辟动态空间
	memset(pInt, 0, sizeof(int));//给空间初始化（名字，初始值，大小）
	*pInt = 10;                 //赋值
	cout << "*pInt = " << *pInt << endl;
	cout << "pInt = " << pInt << endl;
	cout << "&pInt = " << &pInt << endl;
	
//	free(pInt);                //释放空间

	return pInt;

	free(pInt);                //释放空间
}

int main(void) {
	int *p1 = test0();
	cout << "*p1 = " << *p1 << endl;
	cout << "p1 = " << p1 << endl;
	cout << "&p1 = " << &p1 << endl;
//	free(p1);                //释放空间

	return 0;
}
