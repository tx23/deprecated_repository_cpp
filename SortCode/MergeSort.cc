 ///
 /// @file    MergeSort.cc
 /// @author  tangxin(tangxin_sysu@foxmail.com)
 /// @date    2019-01-22 06:02:59
 ///
#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::string;
//二路归并排序
//1、申请空间。
//2、设两个指针，分别指向其头部。
//3、比较指针处，小的放入新空间中。
//4、当一个遍历完后，将剩下的放进去。
//
void merge(int *arr, int l, int m, int r)
{
	int n1 = m-l+1;
	int n2 = r-m;
	int L[n1+1], R[n2+1];
	int k = 0;
	for (int i = l; i <= m; ++i) {
		L[k] = arr[i];
		++k;
	}
	k=0;
	for (int i = m+1; i <= r; ++i) {
		R[k] = arr[i];
		++k;
	}
	int i = 0, j = 0;
	L[n1] = R[n2] = 9999999;
	for (int k = l; k <= r; ++k) {
		arr[k] = L[i] <= R[j] ? L[i++] : R[j++];
	}
}


void MergeSort(int *arr, int l, int r) {
	if (l < r) {
		int m = (l+r)/2;
		MergeSort(arr, l, m);
		MergeSort(arr, m+1, r);
		merge(arr, l, m, r);
	}
}
int main(void)
{
	int a[] = {1, 9, 2, -3, 4, 8, 5, 7};
	int length;
	length = sizeof(a)/sizeof(a[0])+1;
	MergeSort(a, 0, length);
	for(size_t i = 0; i < length-1; ++i) {
		cout << a[i] << " ";
	}
	cout << endl;
}
