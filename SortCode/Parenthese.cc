 ///
 /// @file    Parenthese.cc
 /// @author  tangxin(tangxin_sysu@foxmail.com)
 /// @date    2019-01-22 04:35:19
 ///
#include <string>
#include <iostream>
#include <stack>
//using std::cout;
//using std::endl;
//using std::string;
using namespace std;
class Solution {
public:
	bool isValid(string s) {
		stack <char> _s;
		for(int i = 0; i < (int)s.size(); ++i) {
			if(s[i] == '(' || s[i] == '[' || s[i] == '{')
				_s.push(s[i]);
			else if(s[i]==')'||s[i]==']'||s[i]=='}') {
				if(_s.empty())
					return false;
				else {
				if(s[i] == ')') {
					if(_s.top() == '(')
						_s.pop();
					else return false;
				} else if(s[i] == ']') {
					if(_s.top() == '[') {
						_s.pop();
					}
					else return false;
				} else if(s[i] == '}') {
					if(_s.top() == '{')
						_s.pop();
					else return false;
				}
				}
			}
			}
		return _s.empty();
		}
};
int main(void)
{
	Solution string1;
	int a = -1; 
	a = string1.isValid("]");
	cout << a << endl;
	return 0;
}
