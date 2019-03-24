#ifndef _LIST_H_
#define _LIST_H_

class Node
{
public:
	int data;
	Node *pre;
	Node *next;
};

class List
{
private:
	Node * _head;
	Node *_tail;
	int _size;

public:
	List();
	~List();
	void push_back(int value);
	void push_front(int value);
	void pop_back();
	void pop_front();
	void insert(Node *,int value);
	void erase(Node *);
	void display();
};
#endif
