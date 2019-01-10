
#include <iostream>
namespace tx1
{
	using namespace std;
	void display()
	{
		cout << "using 编译指令实现" << endl;
	}
}

namespace tx2
{
	using std::cout;
	using std::endl;
	void display()
	{
		cout << "using 声明机制实现" << endl;
	}
}

namespace tx3
{
	void display()
	{
		std::cout << "作用域限定符实现" << std::endl;
	}
}
int main()
{
	tx1::display();
	tx2::display();
	tx3::display();
	return 0;
}
