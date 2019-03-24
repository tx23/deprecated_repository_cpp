#include "Mylogger.h"

#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;
using namespace wd;


void test0()
{
	Mylogger::getInstance()->error(prefix("this is an error message!"));
	Mylogger::getInstance()->warn("this is a warn message!");
	Mylogger::getInstance()->info("this is an info message!");
	Mylogger::getInstance()->debug("this is a debug message!");
	cout << "Mylogger::Priority::WARN = " << Mylogger::Priority::WARN << endl;
	cout << "Mylogger::Priority::ERROR = " << Mylogger::Priority::ERROR << endl;
	cout << "Mylogger::Priority::INFO = " << Mylogger::Priority::INFO << endl;
	cout << "Mylogger::Priority::DEBUG = " << Mylogger::Priority::DEBUG << endl;

	Mylogger::getInstance()->setPriority(Mylogger::Priority::WARN);
}

void test1()
{
	cout << __FILE__ << " " << __LINE__ << " " << __FUNCTION__ << endl;
}

void test2()
{
	LogError("this is a error message! ");
	LogWarn("this is a error message!");
	LogInfo("this is a error message!");
	LogDebug("this is a error message!");
}
 
void test3()
{
	int number = 10;
	const char * pstr = "hello,world";
	Mylogger::getInstance()->debug(prefix("this is a error message! number = %d, str = %s"), number, pstr);
	LogError("this is a error message! number = %d, str = %s", number, pstr);
	LogWarn("this is a error message!");
	LogInfo("this is a error message!");
	LogDebug("this is a error message!");
}
int main(void)
{
//	test0();
//	test1();
//	test2();
	test3();
	return 0;
}
