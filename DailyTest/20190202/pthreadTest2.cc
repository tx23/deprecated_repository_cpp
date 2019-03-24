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
//线程有各自的栈空间
//
//
pthread_mutex_t mutex1;
//全局变量，临界资源，采用互斥访问
int gNumber = 100;
void * threadFunc1(void * arg)
{	
	int cnt = 999999;
	while(--cnt) {
		pthread_mutex_lock(&mutex1);//加锁
		--gNumber;
		printf("sub thread %lu, gNumber = %d!\n"
				, pthread_self(), gNumber);//当前线程的id,类似this
		pthread_mutex_unlock(&mutex1);//解锁
		sleep(2);
	}
	return NULL;
}
 
void * threadFunc2(void * arg)
{	
	int cnt = 3;
	while(--cnt) {
		pthread_mutex_lock(&mutex1);
		--gNumber;
		printf("sub thread %lu, gNumber = %d!\n"
				, pthread_self(), gNumber);//当前线程的id,类似this
		pthread_mutex_unlock(&mutex1);
		sleep(0.5);
	}
	return NULL;
}
int main(void)
{	
	pthread_mutex_init(&mutex1, NULL);//动态初始化互斥锁
	printf(">>> main thread start running!\n");
	pthread_t pthid1 = 0, pthid2 = 0;//定义线程id
	pthread_t pthid3 = 0, pthid4 = 0;//定义线程id
	//Linux下线程的本质为进程，结构体为struct task_struct{...}
	pthread_create(&pthid1, NULL, threadFunc1, NULL);//创建线程
	pthread_create(&pthid2, NULL, threadFunc1, NULL);//对进程进行复制
	pthread_create(&pthid3, NULL, threadFunc2, NULL);//
	pthread_create(&pthid4, NULL, threadFunc2, NULL);//
	printf("main thread: %lu, child thread ids = %lu %lu \n"
			, pthread_self(), pthid1, pthid2);

//	int cnt = 30;
	
	pthread_join(pthid1, NULL);
	pthread_join(pthid2, NULL);
	pthread_join(pthid3, NULL);
	pthread_join(pthid4, NULL);
	pthread_mutex_destroy(&mutex1);
	printf(">>>main thread exit!\n");
	return 0;
}
