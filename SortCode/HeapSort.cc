 ///
 /// @file    HeapSort.cc
 /// @author  tangxin(tangxin_sysu@foxmail.com)
 /// @date    2019-01-22 03:39:17
 ///
 
#include <iostream>
#include <algorithm>
using std::cout;
using std::endl;
using std::swap;
//堆排序：
//建堆函数

void Max_heap(int a[], int low, int high)
{
	int dad = low;
	int son = 2*dad+1;
	while(son <= high) {
		if(son + 1 <= high && a[son] < a[son+1])
			++son;
		if(a[dad] > a[son])
			return;
		else {
			swap(a[dad], a[son]);
			dad = son;
			son = 2*dad + 1;
		}
	}
}

//堆排序
void HeapSort(int a[], int len) 
{
	//自下而上建堆
	for(int i = len/2 -1; i >= 0; --i)
		Max_heap(a, i, len-1);
	//将堆顶元素与末尾元素换位，对剩下元素堆排。
	//自上而下建堆
	for(int i = len -1; i > 0;--i) {
		swap(a[0], a[i]);
		Max_heap(a, 0, i-1);
	}
}
//升序
int main(void)
{
	int arry[]{3, 5, 3, 0, 8
		, 6, 1, 5, 8, 6, 2, 4
		, 9, 4, 7, 0, 1, 8, 9
		, 7, 3, 1, 2, 5, 9, 7
		, 4, 0, 2, 6, 11, 8};
	int len = (int)sizeof(arry)/sizeof(*arry);
	HeapSort(arry, len);
	for(int i = 0; i < len; ++i) {
		cout << arry[i] << ' ';
	}
	cout << endl;
	return 0;
}
