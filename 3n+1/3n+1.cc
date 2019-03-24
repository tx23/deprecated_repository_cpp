 ///
 /// @file    3n+1.cc
 /// @author  tangxin(tangxin_sysu@foxmail.com)
 /// @date    2019-01-20 22:22:46
 ///
 
#include <iostream>
using namespace std;
int main(void)
{
	int n = -1;
	cin >> n;
	int i = 0;
	while (n != 1) {
		if(n%2 == 0) {
			n /= 2;
			++i;
		} else {
			n = (3*n + 1)/2;
			++i;
		}
	}
	cout << i << endl;
	return 0;
}
