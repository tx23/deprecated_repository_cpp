#include"list.h"
#include<iostream>

using std::cout;
using std::endl;

List::List()
	:_head(nullptr)
	,_tail(nullptr)
	,_size(0) {
	cout << "List()" << endl;
	}

List::~List() {
	while( _size > 0) {
	pop_back();
	}
	_head = nullptr;
	_tail = nullptr;
	cout << "~List()" << endl;
}

void List::push_back(int value) {
	Node* p1 = new Node();
	p1 -> next = nullptr;
	p1 -> pre = nullptr;
	p1 -> data = value;

	if(_size == 0) {
		_head = p1;
		_tail = p1;
	}
	else {
		_tail -> next = p1;
		p1 -> pre = _tail;
		_tail = p1;
	}
	cout << "在尾部加入一节点，其值为："
		 << p1 -> data << endl;
	++_size;
}

void List::push_front(int value) {
	Node* p1 = new Node();
	p1 -> data = value;
	p1 -> next = nullptr;
	p1 -> pre = nullptr;
	if(_size == 0) {
		_head = p1;
		_tail = p1;
	}
	else {
		_head -> pre = p1;
		p1 -> next = _head;
		_head = p1;
	}
	cout << "在头部加入一节点，其值为："
		 << p1 -> data << endl;
	++_size;
}

void List::pop_back() {
	if(_size == 0) {
		cout << "队列为空，pop_back出队失败。" << endl;
	}
	
	else if(_size == 1) {
		Node* p1;
		p1 = _tail;
		cout << "pop_back出队： "
			 << _tail -> data << endl;
		_size--;
		_head = nullptr;
		_tail = nullptr;
		delete p1;
	}
	else {
		Node* p1;
		p1 = _tail;
		cout << "pop_back出队：" << p1->data << endl;
		_tail = _tail -> pre;
		_tail -> next = nullptr;
		_size--;
		delete p1;
	}
}

void List::pop_front() {
	if(_size == 0) {
		cout << "队列为空，pop_front出队失败。" << endl;
	}
	else if(_size == 1) {
		Node* p1;
		p1 = _head;
		cout << "pop_front出队： "
			 << _head->data << endl;
		_head = nullptr;
		_tail = nullptr;
		delete p1;
		_size--;
	}
	else {
		Node* p1;
		p1 = _head;
		cout << "pop_front出队：" << p1->data << endl;
		_head = _head -> next;
		_head -> pre = nullptr;
		delete p1;
		_size--;
	}
}

void List::insert(Node *p1, int value) {}
void List::erase(Node *p1) {}

void List::display() {
	Node* p1 = _head;
	int n = 1;
	if(_size == 0) {
		cout << "display error,this list is empty!" << endl;
	}
	else {
		while(p1) {
			cout << "链表第" << n 
				 << "个为： " << p1->data << endl;
			p1 = p1 -> next;
			n++;
		}
	}
}










