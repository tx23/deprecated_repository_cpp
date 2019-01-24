 ///
 /// @file    classTemplate.cc
 /// @author  tangxin(tangxin_sysu@foxmail.com)
 /// @date    2019-01-18 04:49:54
 ///
#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::string;
//实现栈中可放任意元素（类模板）

template <class T, size_t kSize = 10>
class Stack
{
public:
	Stack();//在类中实现与正常类一致
	~Stack();
	bool empty() const;
	bool full() const;
	void push(const T & t);
	void pop();
	T top();

private:
	int _top;
	T *_data;
};

template <class T, size_t kSize>
Stack<T, kSize>::Stack()
	: _top(-1)
	, _data(new T[kSize]())
{}

template <class T, size_t kSize>
Stack<T, kSize>::~Stack()
{
	delete []_data;
}

template <class T, size_t kSize>
bool Stack<T, kSize>::empty() const
{
	return _top == -1;
}

template <class T, size_t kSize>
bool Stack<T, kSize>::full() const
{
	return _top == (kSize - 1);
}


template <class T, size_t kSize>
void Stack<T, kSize>::push(const T & t)
{
	if(!full()) {
		_data[++_top] = t;
	} else {
		cout << "stack is full, push error." << endl;
	}
}

template <class T, size_t kSize>
void Stack<T, kSize>::pop()
{
	if(!empty()) {
		--_top;
	} else {
		cout << "stack is empty, pop error." << endl;
	}
}

template <class T, size_t kSize>
T Stack<T, kSize>::top()
{
	return _data[_top];		
}

int test0(void)
{
	Stack<int,9> stack1;
	cout << "此时栈是否为空" << stack1.empty() << endl;
	stack1.push(1);
	cout << "此时栈是否为空" << stack1.empty() << endl;
	int n = 2;
	while(!stack1.full()) {
		stack1.push(n);
		++n;
	}
	cout << "此时栈是否已满" << stack1.full() << endl;
	
	stack1.pop();
	stack1.pop();
	cout << "此时栈是否已满" << stack1.full() << endl;
	while(!stack1.empty()) {
		cout << stack1.top() << endl;
		stack1.pop();
	}
	
	return 0;
}


int test1(void)
{
	Stack<string,9> stack1;
	cout << "此时栈是否为空" << stack1.empty() << endl;
	stack1.push("aa");
	cout << "此时栈是否为空" << stack1.empty() << endl;
	for(int n=1; n != 12; ++n) {
		stack1.push(string(2, 'a' + n));//2个元素，a+1=b
	}
	cout << "此时栈是否已满" << stack1.full() << endl;
	
	stack1.pop();
	stack1.pop();
	cout << "此时栈是否已满" << stack1.full() << endl;
	while(!stack1.empty()) {
		cout << stack1.top() << endl;
		stack1.pop();
	}
	
	return 0;
}
int main() 
{
	test1();
	return 0;
}

