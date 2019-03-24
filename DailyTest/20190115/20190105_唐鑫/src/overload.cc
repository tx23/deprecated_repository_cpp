#include<iostream>
using std::cout;
using std::endl;

int add(int x, int y, int z) {
	return x + y + z;
}


int add(int x, int y) {
	return x + y;
}

void test0() {
	int a = 2, b = 3, c = 4;
	cout << "a + b = " << add(a,b) << endl;
	cout << "a + b + c = " << add(a,b,c) << endl;

}

int main() {
	test0();
	return 0;
}
