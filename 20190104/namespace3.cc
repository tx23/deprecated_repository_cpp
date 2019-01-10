#include<iostream>
using std::cout;
using std::endl;

#define Mul(x,y) ((x)*(y))
#define Mul2(x,y) x*y
#define M 1024

int const Max =10;
int const Min =1;

int main()
{
	cout << "M = " << M << endl;
	cout << "Max = " << Max << endl;
	cout << "Min = " << Min << endl;
	cout << "Mul(1+2,3+4) = " << Mul(1+2,3+4) << endl;
	cout << "Mul2(1+2,3+4) = " << Mul2(1+2,3+4) << endl;
	cout << "Min = " << Min << endl;
	return 0;
}

