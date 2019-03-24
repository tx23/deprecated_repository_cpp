 ///
 /// @file    queue2.cc
 /// @author  tangxin(tangxin_sysu@foxmail.com)
 /// @date    2019-01-12 04:03:03
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Queue
{
public:
//	explicit//预防隐式转换
	Queue(int size = 10)
	: _size(size)
	, _front(0)
	, _rare(0)
	, _data(new int[size]())
	{}

	~Queue() {
		delete [] _data;
	}


	bool empty() const {
		if(_front == _rare) {
//			cout << "队列为空" << endl;
			return true;
		} else {
//			cout << "队列非空" << endl;
			return false;
		}
	}

	bool full() const {
		if((_rare+1)%_size == _front) {
//			cout << "队列已满" << endl;
			return true;
		} else {
//			cout << "队列未满" << endl;
			return false;
		}
	}

	void push(int number) {
		if(full()) {
			cout << "queue is full, push fail!" << endl;
		} else {
			_data[_rare++] = number;
			_rare %= _size;
		}
	}

	void pop() {
		if(!empty()) {
		++_front;
		_front = _front%_size;
		} else 
			cout << "queue is empty" << endl;
	}

	int front() const {
	    return _data[_front];
	}

	int back() const {
	    return _data[(_rare-1+_size)%_size];
	}

private:
	int _size;
	int *_data;
	int _front;
	int _rare;
};

int main(void)
{
	Queue queue;
	cout << "此时queue是否为空: " << queue.empty() << endl;
	queue.push(1);
	cout << "此时queue是否为空: " << queue.empty() << endl;
	
	for(int i = 2; i != 11; i++) {
		queue.push(i);
	}
	cout << "此时queue是否已满" << queue.full() << endl;

	while(!queue.empty()) {
		cout <<queue.front() << endl;
		queue.pop();
	}

	cout << "此时queue是否为空" << queue.empty() << endl;
	return 0;
}
