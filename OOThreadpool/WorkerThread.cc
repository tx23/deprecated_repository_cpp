 ///
 /// @file    WorkThread.cc
 /// @author  tangxin(tangxin_sysu@foxmail.com)
 /// @date    2019-02-10 06:57:38
 ///
#include "WorkerThread.h"
#include "Threadpool.h"

namespace wd
{
WorkerThread::WorkerThread(Threadpool & threadpool)
: _threadpool(threadpool)
{}

void WorkerThread::run()
{
	_threadpool.threadFunc();
}

}

