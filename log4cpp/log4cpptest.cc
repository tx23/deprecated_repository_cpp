 ///
 /// @file    log4cpphomework.cc
 /// @author  tangxin(tangxin_sysu@foxmail.com)
 /// @date    2019-01-13 06:40:21
 ///
#include <log4cpp/Category.hh>
#include <log4cpp/Appender.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/RollingFileAppender.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/Priority.hh>
#include <iostream>
using std::cout;
using std::endl;
//封装log4cpp使输出的日志同时输出到终端和文件


class PLog
{
public:
	PLog();
	~PLog();
	void logError(const char * message);
	void logWarn(const char * message);
	void logInfo(const char * message);
	void logDebug(const char * message);
	void setPriority(void);
private:
	log4cpp::PatternLayout* pLayoutCout;
	log4cpp::PatternLayout* pLayoutFile;
	log4cpp::PatternLayout* pLayoutRollFile;


	log4cpp::OstreamAppender * osAppender;
	log4cpp::FileAppender * fileAppender;
	log4cpp::RollingFileAppender * rollfileAppender;

	log4cpp::Category & root;

};

PLog::PLog():root(log4cpp::Category::getInstance("infoCategory"))
{

//创建layout并设置成pattern模式
	cout << "PLog()" << endl;
	pLayoutCout = new log4cpp::PatternLayout();
	pLayoutCout -> setConversionPattern("%d:%p%c%x%m%n");
	pLayoutFile = new log4cpp::PatternLayout();
	pLayoutFile -> setConversionPattern("%d:%p%c%x%m%n");
	pLayoutRollFile = new log4cpp::PatternLayout();
	pLayoutRollFile -> setConversionPattern("%d:%p%c%x%m%n");
//创建Appender对象并将layout对象绑定
	osAppender = new log4cpp::OstreamAppender("osAppender", &cout);
	osAppender -> setLayout(pLayoutCout);
//将日志文件保存在固定文件夹
	fileAppender = new log4cpp::FileAppender("fileAppender", "homework.log");
	fileAppender -> setLayout(pLayoutFile);
//把日志文件大小设置成1*1024
	rollfileAppender = new log4cpp::RollingFileAppender("rollfileAppender", "rollinghw.log");
	rollfileAppender -> setLayout(pLayoutRollFile);

//将appender对象添加到category上
	root.addAppender(osAppender);
	root.addAppender(fileAppender);
	root.addAppender(rollfileAppender);
}

void PLog::setPriority()
{
	root.setPriority(log4cpp::Priority::DEBUG);
}
//设置优先级
//	void PLog::setPriority(const char* level)
//{
//	if(level == "DEBUG")
//		root.setPriority(log4cpp::Priority::DEBUG);
//	else if(level == "ERROR")
//		root.setPriority(log4cpp::Priority::ERROR);
//	else if(level == "WARN")
//		root.setPriority(log4cpp::Priority::WARN);
//	else if(level == "INFO")
//		root.setPriority(log4cpp::Priority::INFO);
//	else root.setPriority(801);
//}

void PLog::logError(const char * message)
{
	cout << "error()" << endl;
	root.error(message);
}
void PLog::logWarn(const char * message)
{
	cout << "warn()" << endl;
	root.warn(message);
}
void PLog::logInfo(const char * message)
{
	cout << "info()" << endl;
	root.info(message);
}
void PLog::logDebug(const char * message)
{
	cout << "debug()" << endl;
	root.debug(message);
}

PLog::~PLog() {
	cout << "~PLog" << endl;
	log4cpp::Category::shutdown();

}




int main(void)
{
	const char *message ="hello,log4cpp";
//	const char * priority = "ERROR";
	PLog mylog;
	//mylog.setPriority(priority);
	mylog.logError(message);
	mylog.logInfo(message);
	mylog.logInfo(message);
	mylog.logWarn(message);
	return 0;
}
