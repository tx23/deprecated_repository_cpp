 ///
 /// @file    text_query.cc
 /// @author  tangxin(tangxin_sysu@foxmail.com)
 /// @date    2019-01-26 22:12:00
 ///
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <vector>
#include <set>
#include <iostream>
using std::cout;
using std::endl;
using std::vector;
using std::ifstream;
using std::istringstream;
using std::string;
using std::map;
using std::set;
class TextQuery
{
public:
	TextQuery()
	{
		_file.reserve(100);//提前预留空间，避免多次开空间
	}
	void readfile(const string & filename);
	void query(const string & filename);
private:
	void preProcess(string & line);
private:
	vector<string> _file;
	map<string, int> _dict;
	map<string, set<int>> _word2Line;
};


void TextQuery::readfile(const string & filename)
{
	ifstream ifs(filename);
	if(!ifs) {
		cout << "open error" << endl;
		return;
	} 

	string line;
	size_t lineNumber = 0;
	while(getline(ifs, line)) 	
	{
		_file.push_back(line);//先将原文按行数保存下来，再预处理
		preProcess(line);
		istringstream iss(line);
		string word;
		while(iss >> word) {
			++_dict[word];//world为关键字，词频为键对值。
			_word2Line[word].insert(lineNumber);//容器嵌套。将行数插入set中。
		}
		++lineNumber;
	}
	ifs.close();
}


void TextQuery::query(const string & word)
{
	int count = _dict[word];
	cout << word << " occurs " << count << (count > 1 ? " times." : " time.") << endl;
	auto lines = _word2Line[word];//所在的行数。
	for(auto & elem : lines) {
		cout << "    (line " << elem + 1 << ")" << _file[elem] << endl; 
	}
}


void TextQuery::preProcess(string & line)
{
	for(auto &ch : line) {
		if(!isalpha(ch)) {//将非字母的以空格替换
			ch = ' ';
		} else if(!isupper(ch)) {//判断是否为大写
			ch = tolower(ch);//将大写改为小写
		}
	}
}

int main(void)
{

	TextQuery tq;
	string filename;
	cout << "please input a filename" << endl;
	std::cin >> filename;
	tq.readfile(filename);
	cout << "pleae input a query word:" << endl;
	string word;
	while(std::cin >> word)
		tq.query(word);

	return 0;
}
