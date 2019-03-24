 ///
 /// @file    WorkThread.h
 /// @author  tangxin(tangxin_sysu@foxmail.com)
 /// @date    2019-02-10 06:54:06
 ///
#ifndef _WD_WORKERTHREAD_H_
#define _WD_WORKERTHREAD_H_

#include "Thread.h"

namespace wd
{
class Threadpool;

class WorkerThread
:public Thread
{
public:
	WorkerThread(Threadpool & Threadpool);

private:
	void run() override;
private:
	Threadpool & _threadpool;
};

}
#endif
