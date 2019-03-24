 ///
 /// @file    fstream.cc
 /// @author  tangxin(tangxin_sysu@foxmail.com)
 /// @date    2019-01-24 06:06:12
 ///
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::istringstream;
using std::ofstream;
int main(void)
{
	ifstream ifs("test.txt");
	string line;
	while(getline(ifs, line)) {
	cout << line << endl;
	string word;
	istringstream iss(line);
	while(iss >> word) {
	cout << word << endl;
	}
	}
	return 0;
}
