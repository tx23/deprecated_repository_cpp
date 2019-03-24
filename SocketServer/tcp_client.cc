 ///
 /// @file    tcp_client.cc
 /// @author  tangxin(tangxin_sysu@foxmail.com)
 /// @date    2019-02-12 05:53:13
 ///
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#include <iostream>
using std::cout;
using std::endl;
using std::string;

#define ERROR_EXIT(msg) do{\
	::perror(msg);\
	::exit(EXIT_FAILURE);\
} while(0)


void test0()
{
	//1.创建客户端套接字
	int client_fd = ::socket(AF_INET, SOCK_STREAM, 0);
	if(client_fd == -1) {
		ERROR_EXIT("socket");
		return;
	}

	struct sockaddr_in serveraddr;
	serveraddr.sin_family = AF_INET;//地址族IPV4
	serveraddr.sin_port = htons(8888);//端口号
	serveraddr.sin_addr.s_addr = ::inet_addr("192.168.30.128");
	//inet_addr返回该IP地址的对应二进制
	
	//2.客户端发起连接请求
	cout << ">>client is about to connect server" << endl;
	int ret = ::connect(
			client_fd,
			(const struct sockaddr*)&serveraddr,
			sizeof(serveraddr));
	if(ret == -1) {
		ERROR_EXIT("connect1");
		::close(client_fd);
	}

	//3.连接建立好后，发送数据
	cout << " >> client <---> server has connected" << endl;
	cout << "please input your data: " << endl;
	string data;
	std::cin >> data;

	//4.向服务器发送业务请求
	ret = ::send(client_fd, data.c_str(), data.size(), 0);
	if(ret == -1) {
		ERROR_EXIT("send");
		close(client_fd);
	}
	
	//5.接收服务器返回的数据
	char buff[1024] = {0};//客户端缓冲区
	ret = ::recv(client_fd, buff, sizeof(buff), 0);
	//recv 的返回值有三种情况，-1,出故障了，0连接断开，>0数据长度
	if(ret == -1) {
		ERROR_EXIT("recv");
		::close(client_fd);
		return;
	} else if(ret == 0) {//连接断开
		::close(client_fd);
	} else { //接收到数据
		cout << ">> client receive " << ret << "bytes data." << endl;
		cout << ">> receive data:" << buff << endl;
	}

	//6.断开连接
	::close(client_fd);
}

int main(void)
{
	test0();
	return 0;
}
