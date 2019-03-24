 ///
 /// @file    RssTinyxml.cc
 /// @author  tangxin(tangxin_sysu@foxmail.com)
 /// @date    2019-01-16 06:21:58
 ///
#include "tinyxml2.h"
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
using namespace tinyxml2;
//using std::cout;
//using std::endl;
//using std::string;
using namespace std;

class information
{
public:
	string title;
	string link;
	string description;
	string content;
	string language;
	string copyright;
	string pubdate;
	string guid;
	string dccreator;
};

void traverse(vector<information> * _vector)
{
	ofstream _ostream("pagelib.dat", ios::app);

	vector<information>::iterator _begin = _vector->begin();
	vector<information>::iterator _end = _vector->end();
	
	++_begin;

	while(_begin != _end) {
		_ostream << "<doc>" << endl;
		_ostream << "<title>" << _begin->title << "</title>" << endl;
		_ostream << "<link>" << _begin->link << "</link>" << endl;
	_ostream << "<description>" << _begin->description << "</description>" << endl;
		_ostream << "</doc>" << endl;
		++_begin;
	}
}

void test(void)
{
	vector<information> information_vector;
	XMLDocument doc;
	doc.LoadFile("36kr.xml");//载入一个XML文件
	
//	cout << doc.Error() << endl;
	if(0 != doc.Error()) {//判断读取XML是否成功
		cout << "loadfile error!" << endl;
		return;
	}
	
	XMLElement* root = doc.RootElement();//跟节点
	XMLElement* channel = root->FirstChildElement("channel");
	if(nullptr == channel) {//获取第一个子节点
		cout << "get first child element error!" << endl;
		return;
	}

	XMLElement* title = channel->FirstChildElement("title");
	cout << title->GetText() << endl;
	cout << title->Name() << endl;
	//NextSiblingElement获取下一个相邻节点，用来遍历
	XMLElement* description = title->NextSiblingElement();
	cout << description->GetText() << endl;
	cout << description->Name() << endl;

	XMLElement* language = description->NextSiblingElement();
	cout << language->GetText() << endl;
	cout << language->Name() << endl;

	XMLElement* copyright = language->NextSiblingElement();
	cout << copyright->GetText() << endl;
	cout << copyright->Name() << endl;

	XMLElement* pubDate = copyright->NextSiblingElement();
	cout << pubDate->GetText() << endl;
	cout << pubDate->Name() << endl;
	XMLElement * item = pubDate->NextSiblingElement();
	
	//遍历比较，若有不同则更新
	while(item) {
		information tmp;
		XMLElement *item_child = item->FirstChildElement();
		while(item_child) {
			cout << item_child->GetText() << endl;
			if(strcmp(item_child->Name(), "title") == 0) {
				tmp.title.clear();
				tmp.title.append(item_child->GetText());
				cout << "title--------------" << endl;
			} else if(strcmp(item_child->Name(), "link") == 0) {
				tmp.link.clear();
				tmp.link.append(item_child->GetText());
				cout << "link--------------" << endl;
			} else if(strcmp(item_child->Name(), "description") == 0) {
				tmp.description.clear();
				tmp.description.append(item_child->GetText());
				cout << "description--------------" << endl;	
			} else if(strcmp(item_child->Name(), "content") == 0) {
				tmp.content.clear();
				tmp.content.append(item_child->GetText());
				cout << "content--------------" << endl;	
			} else if(strcmp(item_child->Name(), "dccreator") == 0) {
				tmp.dccreator.clear();
				tmp.dccreator.append(item_child->GetText());
				cout << "dccreator--------------" << endl;	
			} else if(strcmp(item_child->Name(), "pubDate") == 0) {
				tmp.pubdate.clear();
				tmp.pubdate.append(item_child->GetText());
				cout << "pubDate--------------" << endl;
			} else if(strcmp(item_child->Name(), "guid") == 0) {
				tmp.guid.clear();
				tmp.guid.append(item_child->GetText());
				cout << "guid--------------" << endl;
			}
			item_child = item_child->NextSiblingElement();
		}
		information_vector.push_back(tmp);
		item = item->NextSiblingElement();
	}
	traverse(&information_vector);//输出
}

int main(void)
{
	test();
	return 0;
}
