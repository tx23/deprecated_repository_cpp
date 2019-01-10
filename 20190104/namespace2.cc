
#include <iostream>
using std::cout;
using std::endl;

int number = 1;
namespace tx 
{
	int number = 10;

void display(int number)
{
	cout << "形参 number = " << number << endl;
	cout << "tx::number = " << tx::number << endl;
	cout << "全局变量number = " << ::number << endl;
}
}


int main(void)
{
	tx::display(3);
	return 0;
}
