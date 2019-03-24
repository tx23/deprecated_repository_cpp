 ///
 /// @file    stringio.cc
 /// @author  tangxin(tangxin_sysu@foxmail.com)
 /// @date    2019-01-11 05:11:22
 ///
 
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
using std::cout;
using std::endl;
using std::istringstream;
using std::ostringstream;
using std::stringstream;
using std::string;
using std::ifstream;
void test0()
{
	int number1 = 10;
	int number2 = 20;

	stringstream ss;//字符串输出流功能
	ss << "number1= " << number1 
	   << ",number2= " << number2 << endl; 
	string line = ss.str();
	cout << line;
	
	string key;
	int value;
//这里要知道ss具体的内容及格式，以空格为间隔
//第一个字符串输入至key，第二个是int输入至value
	while(ss >> key >> value, !ss.eof()) {//字符串输入流
		cout << key << "---->" << value << endl;
	}


}

string int2str(int number)//将int型转换为字符串
{
	ostringstream oss;
	oss << number;
	return oss.str();
}

void test1()
{
	int value = 1024;
	string str = int2str(value);
	cout << "str = " << str << endl;
}

void readConfig(const string & filename)//配置文件的读取
{
	ifstream ifs(filename);
	if(!ifs) {
		cout << "ifstream open error" << endl;
		return;
	}
	
	string line;
	while(getline(ifs, line)) {
	string key, value;
	istringstream iss(line);
	iss >> key >> value;
	cout << key << "---->" << value << endl;
	}

	ifs.close();
}

void test2()
{
	readConfig("my.config");

}

int main(void)
{
	//test0();

	//test1();
	test2();
}
