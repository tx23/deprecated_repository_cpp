 ///
 /// @file    file_io.cc
 /// @author  tangxin(tangxin_sysu@foxmail.com)
 /// @date    2019-01-11 03:12:45
 ///
 
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::ifstream;
using std::ofstream;
using std::fstream;//文件输入输出流

void test0()//从文件中读取保存到容器然后输出到终端
{
	ifstream ifs;
	ifs.open("cin.cc"); //文件流操作在open后要记得close
	if(!ifs.good()) {
		cout << "ifstream open file error" << endl;
		return;
	}
	
	vector<string> lines;//定义一个lines容器

	string str;
//	while(ifs >> str) {//输入流运算符用空格进行分隔
	while(getline(ifs, str)) {//从ifs存至str，一行
		//cout << str << endl;
		lines.push_back(str);//将str存至lines中
	}

	for(size_t idx = 0; idx != lines.size(); ++idx) {
		cout << lines[idx] << endl;
	}

	ifs.close();
}

void test1()//文件中读取保存到另一文件
{
	ifstream ifs("cin.cc");
	if(!ifs) {//ifs.good
		cout << "ifstream open error" << endl;
		return;
	}
	//对文件输入流而言，打开的文件必须存在
	//对文件输出流而言，文件若不存在则创建该文件
	//若文件存在，则会清空该文件再输入。
	//当想要在文件末尾加数据而不是清空
	//	
	string file("fileio.txt");
	ofstream ofs(file);
	//	ofstream ofs(file, std::ios::app);
	if(!ofs) { //判断流是否准备好了
		cout << "ofstream open error." << endl;
	}

	
	string line;//内存中
	while(getline(ifs, line)) {
		ofs << line << '\n';
	}

	ofs.close();

}

void test2()//终端获取写到文件，再从文件读取到终端
{
	string file("fileiotest.txt");
	fstream fs(file);
	if(!fs) {
	cout << "fstream open " << file << "error" << endl;
	return;
	}

	int number = 0;

	for(size_t idx = 0; idx != 10; ++idx) {
		std::cin >> number;
		fs << number << " ";//文件输出流的功能
	}

//	cout << "查看流的状态：" << endl;
//	cout << "fs's badbit = " << fs.bad() << endl
//	     << "fs's failbit = " << fs.fail() << endl
//	     << "fs's eofbit = " << fs.eof() << endl
//		 << "fs's goodbit = " << fs.good() << endl;
	
	size_t pos = fs.tellg(); //文件游针的位置
	fs.seekg(0);//绝对位置
	fs.seekg(0, std::ios::beg);//相对位置，end cur.

	cout << "pos = " << pos << endl;
	for(size_t idx = 0; idx != 10; ++idx) {
		fs >> number;//文件输入流的功能
		cout << number << " ";
	}
	cout << endl;
	fs.close();

}

void test3()
{
	string file("test.txt");
	ofstream ofs(file, std::ios::app);//app是针对输出流，
	if(!ofs) {
		cout << "ofstream open error" << endl;
	}
	
	cout << "pos = " << ofs.tellp() << endl;

	ofs << "a new line.\n";

	ofs.close();


}

int main(void)
{
//	test0();
//	test1();
//	test2();
	test3();
	return 0;
}
