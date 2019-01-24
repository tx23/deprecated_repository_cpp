#include<iostream>
using std::cout;
using std::endl;

int add(int x = 1, int y = 10, int z = 1) {
	return x + y + z;
}

int main() {
	int a = 2, b = 3, c = 4;
	cout << "add(a) = " << add(a) << endl;
	cout << "add(a, b) = " << add(a, b) << endl;
	cout << "add(a, b, c) = " << add(a, b, c) << endl;
	return 0;

}
