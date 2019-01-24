 ///
 /// @file    dictionary.cc
 /// @author  tangxin(tangxin_sysu@foxmail.com)
 /// @date    2019-01-10 17:29:14
 ///
 
#include <iostream>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <string.h>

using namespace std;
//using std::cout;
//using std::endl;
//using std::string;


class dictionary
{
public:
	void read(const string & filename);
	void store(const string & filename);

private:
	vector<string> word;
	vector<int> sum;

};

void dictionary::read(const string & filename) {
	char name[100];
	strcpy(name, filename.c_str());
	ifstream readIn(name);       //打开文件

	if(!readIn.good()) {
		cout << "open file fail." << endl;
		return;
	}

	cout << "已读入文件......" << endl;

	string aword;
	while(readIn >> aword) {	
	int VectorWordSize = word.size();
	int i = 0;
	for(i = 0; i < VectorWordSize; ++i) {
		if(word[i].compare(aword) == 0)
		//word[i].compare(aword)若word[i]==aword返回1
		{
			++sum[i];
			break; //避免反复统计
		}//if
	}//for

	if(i == VectorWordSize) 
	//唯有读入的字符与之前均不同条件成立
	{
		word.push_back(aword);//将该字符存入容器
		sum.push_back(1); //相应计数器初始化为1
	}//if
	}//while

	readIn.close();//关闭文件
}



void dictionary::store(const string & filename)
{
	char name[100];
	strcpy(name, filename.c_str());
	ofstream storeOut(name);
	if(storeOut.good()==0)
	{
		cout << "open store file fail." << endl;
		return;
	}
	int n = word.size();
	for(int i = 0; i < n; ++i)
	{
		storeOut << i+1 << "  "
				 << word[i] << "----->" 
				 << sum[i] << endl;
	}

	storeOut.close();
}


int main(void)
{
	dictionary Bible;
	Bible.read("The_Holy_Bible.txt");
	Bible.store("Bible.txt");
	return 0;
}
