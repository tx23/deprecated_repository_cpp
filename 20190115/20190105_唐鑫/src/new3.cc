#include<iostream>
#include<stdlib.h>
#include<string.h>

using std::cout;
using std::endl;

void test(void) {
	int *pArray = (int *)malloc(sizeof(int)*10);
	memset(pArray, 0, sizeof(int) * 10);
	for(int i=0; i<10; i++) {
		cout << "pArray[" << i << "] = " << pArray[i] << endl;
	}
	free(pArray);
}


int main() {
	test();
	return 0;
}
