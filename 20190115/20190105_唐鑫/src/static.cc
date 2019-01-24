#include<iostream>
using std::cout;
using std::endl;

void test0() {
	int n1= 10;
	float n2 =3.999;
	float n3(5.12);
	cout << "n3 = " << n3 << endl;

	n3 = static_cast<int>(n2);
	cout << "n3 = " << n3 << endl;

}

int main() {
	test0();
	return 0;

}

