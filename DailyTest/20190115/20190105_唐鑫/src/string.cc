#include <stdio.h>    //C的头文件放在C++的前面。
#include <string.h>   //自定义的头文件放最前面
#include <string>
#include <iostream>
using std::cout;
using std::endl;

void test0() {
	char str1[] = "hello";  //字符数组
	char str2[] = "world";
	str2[0] = 'W';            //将w改为W，可以改
//  str1 = 0x1111; //error 数组名本身为常量不可修改
	int len1 = sizeof(str1);   //get str1's length
	int len2 = sizeof(str2);
	printf("str1's len = %d, str2's len = %d\n", len1, len2);
	
	int len = len1 + len2 - 1;
	char *p1 =(char *) malloc (len);
	memset(p1, 0, len);
	strcpy(p1, str1);//将str1复制到p1，返回char*类型。
	strcat(p1, str2);//将p1和str2拼接到一起，p1要足够大。
    printf("p1 = %s\n", p1);

	const char *p2 = "hello,world"; //常量字符串位于文字常量区
//	*p2 = 'H'; error,断错误不能更改其值
    printf("p2 = %s\n", p2);
   
	printf("p1 = %p\n", p1);   //输出各个地址
    printf("p2 = %p\n", p2);
    printf("str1 = %p\n", str1);
    printf("str2 = %p\n", str2);

	free(p1);

}

void test1() {                 //C++风格的字符串
	std::string s1 = "hello "; // const char*类型
	std::string s2 = "world";
	std::string s3 = s1 + s2;

	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;
	cout << "s3 = " << s3 << endl;

	const char* pstr = s3.c_str();//C++风格字符串转换成C风格字符串
	cout << "pstr = " << pstr << endl;


	size_t len1 = s1.size(); //获取字符串的长度，size=length
	size_t len2 = s2.length();
	cout << "len1 = " << len1 << endl;
	cout << "len2 = " << len2 << endl;

	//遍历std::string 的元素
	for(size_t i = 0; i != s3.size(); ++i) {
		cout << s3[i] << endl;
	}
	std::string s4 = s3 + "TX "; //添加字符串
		cout <<"s4 = " << s4 << endl;

	std::string s5 = s4 + 'A'; //添加字母
		cout <<"s5 = " << s5 << endl;
	
	s5.append(s1);//拼接
		cout <<"s5(new) = " << s5 << endl;

	size_t pos = s5.find("TX");//返回无符号整型

	//截子串
	std::string s6 = s5.substr(pos, 4); //从哪里截，截几个。默认从头到尾
		cout <<"s6 = " << s6 << endl;
}


int main(void) {
	
//	test0();
	test1();
	return 0;
}


