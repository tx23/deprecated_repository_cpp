#include<iostream>
using namespace std;

void test() 
{
	int * pInt = new int(10);  //表达式而非库函数
	cout << "*pInt = " << *pInt << endl; //
	cout << "pInt = " << pInt << endl;	//pInt所指变量的地址
	cout << "&pInt = " << &pInt << endl;//pInt指针的的地址
	
	delete pInt;              //同new
}

void test1() 
{
	int * pArray = new int[6]();
	pArray[3] = 3;
	for(int i = 0; i < 6; i++) {
	cout << "pArray[" << i << "] = " << pArray[i] << endl;
	}
	delete [] pArray;
}
int main(void) {
	//test();
	test1();
	return 0;
}
