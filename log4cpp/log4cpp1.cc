 ///
 /// @file    log4cpp1.cc
 /// @author  tangxin(tangxin_sysu@foxmail.com)
 /// @date    2019-01-12 06:13:02
 ///
 
#include <iostream>
#include <log4cpp/Category.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/RollingFileAppender.hh>
using std::cout;
using std::endl;
using namespace log4cpp;
void test0() {//打印到终端

	//控制日志输出格式
	PatternLayout * patternLayout = new PatternLayout();
	patternLayout -> setConversionPattern("%d %c [%p] %m %n");

	//指定日志输出的目的地
	OstreamAppender * ostreamAppender = new OstreamAppender("console", &cout);//取名字，输出流
	ostreamAppender->setLayout(patternLayout);

	//日志记录器
	Category & myCat = Category::getRoot();
	myCat.setAppender(ostreamAppender);
	myCat.setPriority(Priority::DEBUG);
	//执行记录日志的操作
	myCat.emerg("this is an emerg message");
	myCat.fatal("this is a fatal message");
	myCat.alert("this is an alert message");
	myCat.error("this is an error message");
	myCat.info("this is an info message");
	myCat.crit("this is an crit message");
	myCat.debug("this is an debug message");

	Category::shutdown();//回收内存
}

void test1() {

	//控制日志输出格式
	PatternLayout * patternLayout1 = new PatternLayout();
	patternLayout1 -> setConversionPattern("%d %c [%p] %m %n");

	PatternLayout * patternLayout2 = new PatternLayout();
	patternLayout2 -> setConversionPattern("%d %c [%p] %m %n");

	//指定日志输出的目的地,每一个目的地都得设置格式
	OstreamAppender * ostreamAppender = new OstreamAppender("console", &cout);//取名字，输出流
	ostreamAppender->setLayout(patternLayout1);

	FileAppender * fileAppender = new FileAppender("fileAppender", "wd.log");
	fileAppender -> setLayout(patternLayout2);


	//日志记录器
	Category & myCat = Category::getRoot().getInstance("myCat");
	myCat.addAppender(ostreamAppender);
	myCat.addAppender(fileAppender);
	myCat.setPriority(Priority::DEBUG);//categort 的优先级
//只有当category的优先级大于日志的优先级时才会记录，否则忽略。日志的过滤作用


	//执行记录日志的操作
	myCat.emerg("this is an emerg message");//每一条日志的优先级
	myCat.fatal("this is a fatal message");
	myCat.alert("this is an alert message");
	myCat.error("this is an error message");
	myCat.info("this is an info message");
	myCat.crit("this is an crit message");
	myCat.debug("this is an debug message");

	Category::shutdown();//回收内存
}

void test2() {//设置大小，超过空间时把最早的覆盖掉

	//控制日志输出格式
	PatternLayout * patternLayout1 = new PatternLayout();
	patternLayout1 -> setConversionPattern("%d %c [%p] %m %n");

	PatternLayout * patternLayout2 = new PatternLayout();
	patternLayout2 -> setConversionPattern("%d %c [%p] %m %n");

	//指定日志输出的目的地,每一个目的地都得设置格式
	OstreamAppender * ostreamAppender = new OstreamAppender("console", &cout);//取名字，输出流
	ostreamAppender->setLayout(patternLayout1);

	RollingFileAppender * rollingFileAppender =
		new RollingFileAppender("rollingFileAppender", 
				"rollingwd.log",
				5*1024,
				3);
	rollingFileAppender -> setLayout(patternLayout2);


	//日志记录器
	Category & myCat = Category::getRoot().getInstance("myCat");
	myCat.addAppender(ostreamAppender);
	myCat.addAppender(rollingFileAppender);
	myCat.setPriority(Priority::DEBUG);//categort 的优先级
//只有当category的优先级大于日志的优先级时才会记录，否则忽略。日志的过滤作用


	//执行记录日志的操作
	for(int idx = 0; idx != 100; ++idx) {
	myCat.emerg("this is an emerg message");//每一条日志的优先级
	myCat.fatal("this is a fatal message");
	myCat.alert("this is an alert message");
	myCat.error("this is an error message");
	myCat.info("this is an info message");
	myCat.crit("this is an crit message");
	myCat.debug("this is an debug message");
	}
	Category::shutdown();//回收内存
}

int main(void) //添加头文件<log4cpp/FileAppender.hh>
{
	//test0();
	//test1();
	test2();
	return 0;

}
