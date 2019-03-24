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

pthread_mutex_t mutex1;
pthread_cond_t cond1;
bool flag = true;

//全局变量，临界资源，采用互斥访问
int gNumber = 100;

void * threadFunc1(void * arg)
{	//线程1：当flag为true时，执行-1，将flag设置为true，通知线程2；
	//		 当flag为false时，将自己阻塞挂起，等待条件成立
	int cnt = 100;
	while(--cnt) {
		pthread_mutex_lock(&mutex1);//使用条件变量前，要加锁
		while(flag == false) {
			pthread_cond_wait(&cond1, &mutex1);
			//阻塞，在线程阻塞的同时会解锁，否则会死锁。
			//当其他线程发送signal后，当前wait被激活，激活之后会先加锁
		}
		--gNumber;
		printf("sub thread %lu, gNumber = %d!\n"
				, pthread_self(), gNumber);
		if(flag == true)
			flag = false;
		pthread_cond_signal(&cond1);//通知其他线程
		pthread_mutex_unlock(&mutex1);//解锁
		sleep(0.5);
	}
	return NULL;
}
 
void * threadFunc2(void * arg)
{	//线程2：当flag为false时，执行-1，将flag设置为true，通知线程2；
	//		 当flag为true时，将自己阻塞挂起，等待条件成立
	int cnt = 100;
	while(--cnt) {
		pthread_mutex_lock(&mutex1);//使用条件变量前，要加锁
		while(flag == true) {//用while以防一次执行后flag还未被设为true
			pthread_cond_wait(&cond1, &mutex1);
			//阻塞，在线程阻塞的同时会解锁，否则会死锁。
			//当其他线程发送signal后，当前wait被激活，激活之后会先加锁
		}
		--gNumber;
		printf("sub thread %lu, gNumber = %d!\n"
				, pthread_self(), gNumber);
		if(flag == false)
			flag = true;
		pthread_cond_signal(&cond1);//通知其他线程
		pthread_mutex_unlock(&mutex1);//解锁
		sleep(0.5);
	}
	return NULL;
}

int main(void)
{	
	pthread_mutex_init(&mutex1, NULL);//初始化互斥锁
	pthread_cond_init(&cond1, NULL);//初始化条件变量

	printf(">>> main thread start running!\n");
	pthread_t pthid1 = 0, pthid2 = 0;//定义线程id

	//Linux下线程的本质为进程，结构体为struct task_struct{...}
	pthread_create(&pthid1, NULL, threadFunc1, NULL);//创建线程
	pthread_create(&pthid2, NULL, threadFunc2, NULL);//对进程进行复制


	printf("main thread: %lu, child thread ids = %lu %lu \n"
			, pthread_self(), pthid1, pthid2);


	
	pthread_join(pthid1, NULL);
	pthread_join(pthid2, NULL);


	//pthread_mutex_destroy(&mutex1);
	pthread_cond_destroy(&cond1);
	printf(">>>main thread exit!\n");
	return 0;
}
