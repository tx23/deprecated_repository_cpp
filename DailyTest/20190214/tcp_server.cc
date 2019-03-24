 ///
 /// @file    tcp_server.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-02-12 14:53:31
 ///

#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <iostream>
#include <functional>
#include <vector>
#include <unordered_set>
using namespace std;

#define ERROR_EXIT(msg) do{\
	::perror(msg);\
	::exit(EXIT_FAILURE);\
} while(0)


int create_tcp_socket()
{
	int listenfd = ::socket(AF_INET, SOCK_STREAM, 0);//TCP协议
	if(listenfd == -1) {
		ERROR_EXIT("socket");
	}
	return listenfd;
}

void set_reuse_addr(int fd, int on) 
{
	int reuse = on;
	if(setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(int))) {
		ERROR_EXIT("setsockopt");
	}
}

//对端口的复用，意味着linux内核可以在同一台物理主机上实现系统级别的负载均衡
void set_reuse_port(int fd, int on) 
{
	int reuse = on;
	if(setsockopt(fd, SOL_SOCKET, SO_REUSEPORT, &reuse, sizeof(int))) {
		ERROR_EXIT("setsockopt");
	}
}
int bind_inet_addr(int fd, const char * ip, unsigned short port)
{
	struct sockaddr_in serveraddr;
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = htons(port);
	serveraddr.sin_addr.s_addr = inet_addr(ip);

	int ret = bind(fd, (const struct sockaddr *)&serveraddr, sizeof(serveraddr)) ;
	if(ret == -1)
	{
		::close(fd);
		ERROR_EXIT("bind");
	}
	return ret;
}

int mylisten(int fd) 
{
	int ret = ::listen(fd, 10);
	if(-1 == ret) { 
		::close(fd);
		ERROR_EXIT("listen");
	}
	return ret;
}

int my_accept(int fd) 
{
	int peerfd = ::accept(fd, nullptr, nullptr);
	if(peerfd == -1) {
		::close(fd);
		::perror("accept");
	}
	return peerfd;
}


int handle_new_connection(int listenfd)
{
	cout << ">>> server is about to accept a new link " << endl;
	int peerfd = my_accept(listenfd);
	cout << ">>> server serve client with fd = " << peerfd << endl;
	

	return peerfd;
}

void print_connection_info(int peerfd) 
{
	struct sockaddr_in serveraddr;
	socklen_t len = sizeof(struct sockaddr_in);
	int ret = ::getsockname(peerfd, (struct sockaddr*)&serveraddr, &len);

	struct sockaddr_in clientaddr;//4.1 解析对端IP和port
	::memset(&clientaddr, 0, sizeof(struct sockaddr_in));
	ret = ::getpeername(peerfd, (struct sockaddr*)(&clientaddr), &len);

	if(ret == -1) {
		perror("getpeername");
	} else {
		cout << " clientaddr len = " << len << endl;

		string serverip(inet_ntoa(serveraddr.sin_addr));
		unsigned short serverport = ntohs(serveraddr.sin_port);
		
		string clientip(inet_ntoa(clientaddr.sin_addr));// 32位二进制的地址 ==》点分十进制IP地址
		unsigned short clientport = ntohs(clientaddr.sin_port);//大端模式 ==》 小端模式

		cout << ">>> " << serverip << ":" << serverport 
			 << " --> " << clientip << ":" << clientport;
	}
}

void handle_client_message(int peerfd, fd_set * rfds, unordered_set<int> & client_fds) 
{
	//5. 对已经建立好的连接进行数据的接收
	char buff[1024] = {0};//应用层接收缓冲区
	cout << " >>> before recv " << endl;
	int ret = ::recv(peerfd, buff, sizeof(buff), 0);//默认情况下，是阻塞函数
	cout << ">>> server recv ret = " << ret << endl;
	if(ret < 0) {
		if(ret == -1 && errno == EINTR)
			return;
		else
			::perror("recv");
	} else if(ret == 0) {//连接已经断开了
		print_connection_info(peerfd);
		cout << " has closed!!" << endl;

		::close(peerfd);
		FD_CLR(peerfd, rfds);
		client_fds.erase(peerfd);

	} else { 
		//6. 对接收的数据进行处理(业务逻辑)
		cout << ">> server gets msg from client: " << buff << endl;
		//
		//....do something (应用层操作)
		//
		//7. 得到要返回给client的结果，对数据进行发送(回显操作能够正常执行，表示服务器框架搭建完毕) 
		ret = ::send(peerfd, buff, strlen(buff), 0);//（传输层操作  对我们来说，是透明的）
		if(ret == -1) {
			::perror("send");
			::close(peerfd);
		}
	}
}

void set_non_block(int fd)
{
	int flags = ::fcntl(fd, F_GETFL, 0);
	if(flags == -1) {
		ERROR_EXIT("fcntl");
	}
	int ret = ::fcntl(fd, F_SETFL, O_NONBLOCK | flags);
	if(ret == -1) {
		ERROR_EXIT("fcntl");
	}
}

void select_fds_init(int & maxfd, fd_set * rfds, unordered_set<int> & client_fds) 
{
	for(auto & fd : client_fds) {
		FD_SET(fd, rfds);	
		if(maxfd < fd) maxfd = fd;
	}
}

int tcp_server(const string & ip, unsigned short port)
{
	int listenfd = create_tcp_socket();
	cout << " >>>> server listenfd  = " << listenfd << endl;
	set_reuse_addr(listenfd, 1);//将网络地址设置成可以重用的
	set_reuse_port(listenfd, 1);

	bind_inet_addr(listenfd, ip.data(), port);
	mylisten(listenfd);
	return listenfd;
}

void server_test()
{
	string ip("192.168.30.128");
	unsigned short port = 8888;
	int listenfd = tcp_server(ip, port);

	//并发服务器模型之IO复用select
	fd_set rfds;//读事件的fd_set
	struct timeval tv;
	int maxfd = 1024;

	unordered_set<int> client_fds;//存储的是所有已经建立连接的fd
	while(true) {
		//每次调用select前都要重新设置fd和时间,
		//因为事件发生后，fd和时间都被内核修改了
		FD_ZERO(&rfds);
		FD_SET(listenfd, &rfds);
		
		select_fds_init(maxfd, &rfds, client_fds);
		tv.tv_sec = 5;//5秒超时
		tv.tv_usec = 0;

		int ready = select(maxfd, &rfds, nullptr, nullptr, nullptr);//阻塞式函数, 一直等待，直到有连接请求过来,再返回
		//int ready = select(maxfd + 1, &rfds, nullptr, nullptr, &tv);//阻塞式函数, 指定时间，5秒之后要返回
		cout << ">>> select retval = " << ready << endl;
		if(ready == -1 && errno == EINTR) {
			continue;
		} else if(ready == -1) {
			ERROR_EXIT("select");
		} else if(ready == 0) {
			cout << ">> select timeout!" << endl;
			continue;
		} else { //ready > 0
			for(int fd = 0; fd < maxfd + 1; ++fd) {
				if(FD_ISSET(fd, &rfds) && (fd == listenfd)) {
					//处理新连接
					int peerfd = handle_new_connection(listenfd);
					set_non_block(peerfd);//设置成非阻塞的
					print_connection_info(peerfd);
					cout << "has connected!" << endl;
					FD_SET(peerfd, &rfds);
					client_fds.insert(peerfd);
				}
				if(FD_ISSET(fd, &rfds) && (fd != listenfd)) {
					//处理已经创建好的连接
					handle_client_message(fd, &rfds, client_fds);
				}
			}//end of for
		}
	}//end of while
	::close(listenfd);
	FD_CLR(listenfd, &rfds);
}
 
int main(void)
{
	server_test();
	return 0;
}
