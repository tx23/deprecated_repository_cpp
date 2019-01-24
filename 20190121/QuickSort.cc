 ///
 /// @file    QuickSort.cc
 /// @author  tangxin(tangxin_sysu@foxmail.com)
 /// @date    2019-01-21 07:17:41
 ///
 
#include <iostream>
using std::cout;
using std::endl;
//以第一个元素作为枢纽
void Qsort(int a[], int low, int high)
{
	if(low > high)
		return;
	int head = low;
	int tail = high;
	int key = a[head];
	while(head < tail) {
		while(a[tail]>=key && head < tail) 
			--tail;
		a[head] = a[tail];
		a[tail] = key;
		while(a[head]<=key && head < tail)
			++head;
		a[tail] = a[head];
		a[head] = key;
	}
	Qsort(a, low, head-1);
	Qsort(a, head+1, high);
}

int main(void)
{
	int a[] {23, 11, 32, 10, 6, 9, 2};
	Qsort(a, 0, 6);
	for(int i=0; i != 7; ++i) {
		cout << a[i] << endl;
	}	
	return 0;
}
