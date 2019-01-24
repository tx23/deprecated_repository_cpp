#include<iostream>
using std::cout;
using std::endl;



void swap1(int *px, int *py) { //用指针作为参数
	int temp = *px;
	*px = *py;
	*py = temp;

}

void test1() {
	int a = 2, b = 3;
	cout << "交换之前:" << endl
	 << "a = " << a << endl
	 << "b = " << b << endl;
	swap1(&a, &b);
	cout << "交换之后:" << endl
	 << "a = " << a << endl
	 << "b = " << b << endl;
}

void swap2(int &px, int &py) { //用引用作为参数
	int temp = px;
	px = py;
	py = temp;

}

void test2() {
	int a = 20, b = 30;
	cout << "交换之前:" << endl
	 << "a = " << a << endl
	 << "b = " << b << endl;
	swap2(a, b);
	cout << "交换之后:" << endl
	 << "a = " << a << endl
	 << "b = " << b << endl;
}
int main() {
//	test0();
	test1();
	test2();
	return 0;
}
