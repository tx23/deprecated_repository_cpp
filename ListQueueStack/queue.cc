#include<iostream>
//有瑕疵的队列，不能循环，更新见queue2.cc
using namespace std;

class Queue
{
public:
	Queue()
	:_front(0)
	,_tail(0)
	{
	cout << "Queue" << endl;
	}

	~Queue() {
	cout << "~Queue" << endl;
	}

	void test0() {
	cout << "_front = " << _front << endl
		 << "_tail = " << _tail << endl;
	}

	bool empty() {
		if(_front == _tail) 
		cout << "当前队列为空" << endl;
		else cout << "当前队列非空" << endl;
		return _front == _tail;
	}

	bool full() {
		if(_tail == max)
		cout << "当前队满" << endl;
		else cout << "当前队列未满" << endl;
		return _tail == max;
	}

	bool front(void) {
		if(_front == _tail) {
			cout << "队空，无法读取队头元素" << endl;
			return 0;
		}
		else {
			cout <<" 队头元素:" << elem[_front] << endl;
			return 1;
		}
	}

	bool back(void) {
		if(_front == _tail) {
			cout << "队空，无法读取队尾元素" << endl;
			return 0;
		}
		else {
			cout << "队尾元素:" << elem[_tail-1] << endl;
			return 1;
		}
	}

	void push(int n) {//元素入队
		if(_tail == max) {
			cout << "队满,入队失败" << endl;
		}
		else {
			elem[_tail] = n;
			cout << "入队：" << elem[_tail] << endl;
			_tail++;
		}
	}
	
	void pop() {//出队
		if(_front == _tail) {
			cout << "队空，出队失败" << endl;
		}
		else {
			cout << "出队：" << elem[_front] << endl;
			_front++;
		}
	}


private:
	static const size_t max = 9;//队列最大长度为10
	int elem[max];
	int _front;//头
	int _tail;//尾
};


int main() {
	Queue test;
	test.push(10);
//	test.test0();// 测试头尾指针值
	test.push(11);
//	test.test0();// 测试头尾指针值
	test.push(12);
//	test.test0();// 测试头尾指针值
	test.push(13);
//	test.test0();// 测试头尾指针值
	test.front();
	test.empty();
	test.full();
	test.back();
	test.pop();
//	test.test0(); 测试初始值是否为0
	return 0;
}
