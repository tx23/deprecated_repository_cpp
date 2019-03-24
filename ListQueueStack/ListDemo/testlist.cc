#include"list.h"
#include<iostream>
using std::cout;
using std::endl;

int main(void) {
	List test;
//	test.push_front(3);
	test.push_front(2);
	test.push_front(1);

//	test.display();

//	test.push_back(1);
	test.push_back(2);
	test.push_back(3);

	test.display();

	test.pop_back();
	
//	test.display();

	test.pop_front();

	test.display();

	return 0;
}
