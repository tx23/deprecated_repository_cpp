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

class Log4cpp1() {
public:
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
	void logEmerg("message") {
	return myCat.emerg("this is an emerg messag");
	}
	void logFatal("message") {
	myCat.fatal("this is a fatal message");
	}
	void logAlert("message") {
	myCat.alert("this is an alert message");
	}
	void logCrit("message") {
	myCat.crit("this is an crit message");
	}
	void logError("message") {
	myCat.error("this is an error message");
	}
	void logWarn("message") {
	myCat.warn("this is a warn message");
	}
	void logNotice("message") {
	myCat.notice("this is a notice message");
	}
	void logInfo("message") {
	myCat.info("this is an info message");
	}
	void logDebug("message") {
	myCat.debug("this is an debug message");
	}

	Category::shutdown();//回收内存
};


int main(void) //添加头文件<log4cpp/FileAppender.hh>
{
	return 0;

}
