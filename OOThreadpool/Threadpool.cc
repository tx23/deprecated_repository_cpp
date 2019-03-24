 ///
 /// @file    Threadpool.cc
 /// @author  tangxin(tangxin_sysu@foxmail.com)
 /// @date    2019-02-10 06:26:30
 ///
#include "Threadpool.h"
#include "WorkerThread.h"

#include <unistd.h>

namespace wd
{
Threadpool::Threadpool(size_t threadNum, size_t queSize)
: _threadNum(threadNum)
, _threads()
, _queSize(queSize)
, _taskque(_queSize)
, _isExit(false)
{
	_threads.reserve(threadNum);
}

Threadpool::~Threadpool()
{
	if(!_isExit)
		stop();
}

void Threadpool::start()
{
	for(size_t idx = 0; idx != _threadNum; ++idx) {
		unique_ptr<Thread> up(new WorkerThread(*this));
		_threads.push_back(std::move(up));
	}

	for(auto & threadPtr : _threads)
		threadPtr->start();
}
//添加任务
void Threadpool::addTask(Task * ptask)
{
	_taskque.push(ptask);
}

//获取任务
Task * Threadpool::getTask()
{ return _taskque.pop(); }

//每个子线程执行的任务：不断的去任务队列中获取任务并执行
void Threadpool::threadFunc()
{
	while(!_isExit) {
		Task * ptask = getTask();//获取任务
		if(ptask)
			ptask->process();//执行任务
	}
}

//停止线程池
void Threadpool::stop()
{
	cout << ">>> main thread Threadpool::stop() entering" << endl;
	if(!_isExit) {
	//退出线程池之前，要确保所有任务执行完
	
		while(!_taskque.empty()) {
		//bug:休眠过程中，所有子线程已经将任务执行完毕，并阻塞在getTask上
		//即使将_isExit设置为true，子线程也无法正常退出
			::usleep(100);//防止CPU空转，让线程休眠100微秒
		}
		//退出while循环，表示所有的任务都被子线程取走，不能确定是否执行完毕
		_isExit = true;
		//唤醒所有子线程
		_taskque.wakeup();
		//回收每一个子线程的资源
		for(auto & threadPtr : _threads) {
			threadPtr->join();//等待每个子线程执行完毕
		}
	}

}


}

