 ///
 /// @file    Threadpool.h
 /// @author  tangxin(tangxin_sysu@foxmail.com)
 /// @date    2019-02-10 06:20:55
 ///
#ifndef _WD_THREADPOOL_H_
#define _WD_THREADPOOL_H_

#include "Task.h"
#include "TaskQueue.h"
#include <vector>
#include <memory>
using namespace std;

namespace wd
{
class Thread;
class Threadpool
{
	friend class WorkerThread;
public:
	Threadpool(size_t threadNum, size_t queSize);
	~Threadpool();

	void addTask(Task *);
	void start();//开启线程池
	void stop();//停止线程池
private:
	void threadFunc();
	Task * getTask();
private:
	size_t _threadNum;
	vector<unique_ptr<Thread>> _threads;
	size_t _queSize;
	TaskQueue _taskque;
	bool _isExit;
};

}
#endif
