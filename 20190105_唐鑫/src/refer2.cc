#include<iostream>
using std::cout;
using std::endl;
 // 引用作为函数返回值

int Value[10] = {0, 1, 2, 3};

int & getValue(int Index) { 
	return Value[Index];
}

void test1() {
	cout << "getvalue(0) = " << getValue(0) << endl;
	getValue(0) = 100;
	cout << "getvalue(0) = " << getValue(0) << endl;
	cout << "value(0) = " << Value[0] << endl;


}

int main() {
	test1();
	return 0;
}
