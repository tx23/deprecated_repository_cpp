 ///
 /// @file    test.cc
 /// @author  tangxin(tangxin_sysu@foxmail.com)
 /// @date    2019-01-17 03:53:51
 ///
#include "tinyxml2.h" 
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;
using namespace tinyxml2;
bool getXMLDeclaration(const char* xmlPath, string& strDecl)
{
	XMLDocument doc;
	if(0 != doc.LoadFile(xmlPath)) {
		cout << "LoadFile error" << endl;
		return false;
	}
	XMLNode* decl = doc.FirstChild();
	if(nullptr != decl) {
		XMLDeclaration* declaration = decl->ToDeclaration();
		if(nullptr != declaration) {
			strDecl = declaration->Value();
			return true;
		}
	}
	return false;
}
 
int main(void)
{
	string strDecl;
	if(getXMLDeclaration("./36kr.xml", strDecl)) {
		cout << "declaration" << strDecl << endl;
	}
	return 0;
}
