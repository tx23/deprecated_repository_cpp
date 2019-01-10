#include <iostream>
using std::cout;
using std::endl;
//带命名空间的函数声明
//namespace tx2   
//{
//	void printf();
//}

namespace tx1  
{
	void show()
	{
		tx2::printf;
		cout << "tx1" << endl;
	}
}


namespace tx2
{
	void printf()
	{
		tx1::show;
		cout << "tx2" << endl;
	}
}

int main()
{

	return 0;
}
