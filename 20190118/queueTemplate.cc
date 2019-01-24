 ///
 /// @file    queueTemplate.cc
 /// @author  tangxin(tangxin_sysu@foxmail.com)
 /// @date    2019-01-20 05:34:06
 ///
#include <string> 
#include <iostream>
using std::cout;
using std::endl;
using std::string;
template <class T, size_t mSize = 10>
class Queue
{
public:
	Queue()
	: _size(mSize)
	, _head(0)
	, _tail(0)
	, _data(new T [_size]())
	{ cout << "Queue()" << endl;}

	~Queue()
	{ delete []_data;}//注意销毁数组，否则断错误

	bool empty() const
	{
		return _head == _tail;
	}

	bool full() const
	{
		return (_tail+1)%_size == _head;
	}
	
	void push(T number)
	{
		if(full()) {
			cout << "queue is full, push error." << endl;
		} else {
			_data[_tail++] = number;
			_tail %= _size;
		}
	}

	void pop()
	{
		if(empty()) {
			cout << "queue is empty, pop error." << endl;
		} else {
		//	_head = (_head+1)%_size;
			++_head;
			_head %= _size;
		}
	}
	

	T front() const
	{
		return _data[_head]; 
	}

	T back()
	{
		return _data[_tail-1];
	}

private:
	int _size;
	int _head;
	int _tail;
	T *_data;
};


int test0(void)
{
	Queue<string, 9> queue1;
	cout << "此时队列是否为空： " << queue1.empty() << endl;
	queue1.push("aa");
	cout << "此时队列是否为空： " << queue1.empty() << endl;
	for(int n = 1; n != 12; ++n) {
		queue1.push(string(2, 'a'+n));
	}
	cout << "此时队列是否已满： " << queue1.full() << endl;

	queue1.pop();
	queue1.pop();
	cout << "此时队列是否已满： " << queue1.full() << endl;
	while(!queue1.empty()) {
		cout << queue1.front() << endl;
		queue1.pop();
	}	
	return 0;
}

void test1(void)
{
	Queue<int, 9> queue1;
	cout << "此时队列是否为空： " << queue1.empty() << endl;
	queue1.push(1);
	cout << "此时队列是否为空： " << queue1.empty() << endl;
	for(int n = 1; n != 12; ++n) {
		queue1.push(n+1);
	}
	cout << "此时队列是否已满： " << queue1.full() << endl;

	queue1.pop();
	queue1.pop();
	cout << "此时队列是否已满： " << queue1.full() << endl;
	while(!queue1.empty()) {
		cout << queue1.front() << endl;
		queue1.pop();
	}	
}

int main()
{
	test0();
	test1();
	return 0;
}
