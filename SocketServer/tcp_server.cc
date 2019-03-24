 ///
 /// @file    tcp_server.cc
 /// @author  tangxin(tangxin_sysu@foxmail.com)
 /// @date    2019-02-12 06:26:51
 ///
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <iostream>
#include <functional>
using namespace std;
 
int test0()
{
#define ERROR_EXIT(msg) do{\
	::perror(msg);\
	::exit(EXIT_FAILURE);\
} while(0)

	//1.创建套接字
	int listenfd = ::socket(AF_INET, SOCK_STREAM, 0);//IPV4, TCP
	if(listenfd == -1) {
		::perror("socket");
		::exit(EXIT_FAILURE);
	}
	cout << ">>>> server listenfd = " << listenfd << endl; 
	
	//网络地址=> 大端模式
	unsigned short port = 8888;
	string ip("192.168.30.128");
	struct sockaddr_in serveraddr;
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = htons(port);
	serveraddr.sin_addr.s_addr = inet_addr(ip.data());

	//2.绑定网络地址
	if(-1 == bind(listenfd,
				(const struct sockaddr *)&serveraddr,
				sizeof(serveraddr)))
	{
		::close(listenfd);
		ERROR_EXIT("bind");
	}

	//3.对新连接请求进行监听,设置处于半连接数的最大值为10
	if(-1 == ::listen(listenfd, 10)) {
		::close(listenfd);
		ERROR_EXIT("listen");
	}


	//并发服务器模型之循环（迭代）服务器
	while(1) {
	//4.建立新连接
	cout << "server is about to accept a new link" << endl;
	int peerfd = ::accept(listenfd, nullptr, nullptr);
	if(peerfd == -1) {
		::close(listenfd);
		ERROR_EXIT("accept");
	}
	cout << ">>>> server serve client with fd = " << peerfd << endl;

	struct sockaddr_in clientaddr;//解析对端IP&PORT
	::memset(&clientaddr, 0, sizeof(struct sockaddr_in));
	socklen_t len = sizeof(struct sockaddr_in);
	
	int ret = ::getpeername(peerfd, (struct sockaddr*)(&clientaddr), &len);
	if(ret == -1) {
		perror("getpeername");
	} else {
		cout << "clientaddr len = " << len << endl;
		string clientip(inet_ntoa(clientaddr.sin_addr));
		unsigned short clientport = ntohs(clientaddr.sin_port);
		cout << ">>> server " << ip << ":" << port << "--->"
			 << " client" << clientip << ":" << clientport
			 <<  " has connected!" << endl;
	}
	

	//5.进行数据接收
	char buff[1024] = {0};//接收缓冲区
	cout << ">>> before recv" << endl;
	ret = ::recv(peerfd, buff, sizeof(buff), 0);//默认情况为阻塞式函数
	cout << ">>> server recv ret = " << ret << endl;
	if(ret < 0) {
		if(ret == -1 && errno == EINTR)
			continue;
		else
			ERROR_EXIT("recv");
	} else if(ret == 0) {//连接已断开
		::close(peerfd);
	} else {//ret > 0,ret 为接收到对端所发送的数据的长度
		//6.对接收到的数据处理
		//。。。
		cout << ">> server gets msg from client: " << buff << endl;

		//7.进行数据的发送。（回显操作）
		ret = ::send(peerfd, buff, strlen(buff), 0);
		if(ret == -1) {
			ERROR_EXIT("send");
			::close(peerfd);
		}

		//8.断开连接
		::sleep(0.3);
		::close(peerfd);//关闭连接
	}
	}
	//关闭服务器的监听文件描述符（有限）
	::close(listenfd);

}

int main(void)
{
	test0();
	return 0;
}
