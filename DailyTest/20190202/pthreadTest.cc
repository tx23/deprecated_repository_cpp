 ///
 /// @file    pthreadTest.cc
 /// @author  tangxin(tangxin_sysu@foxmail.com)
 /// @date    2019-02-02 04:11:05
 ///
#include <stdio.h>
#include <unistd.h>//sleep()
#include <pthread.h>
#include <iostream>
using std::cout;
using std::endl;
//线程的执行在进程的空间里面
//如果进程执行结束，线程将无法执行。
void * threadFunc(void * arg)
{
	int cnt = 30;
	while(--cnt) {
		printf("sub thread %lu!\n", pthread_self());//当前线程的id,类似this
		sleep(0.1);
	}
	return NULL;
}
 
int main(void)
{
	printf(">>> main thread start running!\n");
	pthread_t pthid = 0;
	pthread_create(&pthid, NULL, threadFunc, NULL);//创建线程
	printf("main thread: %lu, child thread id = %lu\n", pthread_self(), pthid);

	int cnt = 30;
	while(--cnt) {
		printf("main thread %lu!\n", pthread_self());
		sleep(0.1);
	}

	pthread_join(pthid, NULL);
	//等待线程pthid执行结束, 阻塞(线程挂起，不再占用CPU)
	//while(1); 使用死循环时，还是有CPU调度，还会占用CPU的时间片。
	printf(">>>main thread exit!\n");
	return 0;
}
