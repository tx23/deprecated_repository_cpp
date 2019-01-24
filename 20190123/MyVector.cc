 ///
 /// @file    MyVector.cc
 /// @author  tangxin(tangxin_sysu@foxmail.com)
 /// @date    2019-01-23 22:38:32
 ///
#include <memory>
#include <algorithm>
#include <iostream>
using std::cout;
using std::endl;

template <class T>
class Vector
{
public:
	typedef T value_type;
	typedef T* iterator;

	Vector()
	: _start(nullptr)
	, _finish(nullptr)
	, _end_of_storage(nullptr)
	{}

	~Vector();

	void push_back(const T & t);
	void pop_back();
	
	iterator begin() { return _start;}
	iterator end() { return _finish;}

	int size() const { return _finish - _start;}
	int capacity() { return _end_of_storage - _start;}

private:
	void reallocate();
private:
	static std::allocator<T> _alloc;

	T *_start;
	T *_finish;
	T *_end_of_storage;
};

template <class T>
std::allocator<T> Vector<T>::_alloc;

template <class T>
Vector<T>::~Vector()
{
	if(_start) {
		while(_finish != _start) {
			--_finish;
			_alloc.destroy(_finish);//先析构
		}
		_alloc.deallocate(_start, capacity());//再回收空间
	}
}

template <class T>
void Vector<T>::push_back(const T& t)
{
	if(size() == capacity()) {
		reallocate();
	} 
	if(size() < capacity()) {
		_alloc.construct(_finish, t);//对空间构造
		++_finish;
	}


}

template <class T>
void Vector<T>::reallocate()
{
	int oldCapacity = capacity();
	int newCapacity = oldCapacity*2 > 0 ? 2*oldCapacity : 1;
//allocate(n).申请n个T大小的空间，返回一个T类型的指针
	T* ptmp = _alloc.allocate(newCapacity);

	if(_start) {
		//在未初始化的空间上copy
		std::uninitialized_copy(_start, _finish, ptmp);
		while(_finish != _start) {//销毁原先的空间
			_alloc.destroy(--_finish);
		}
	}

	_start = ptmp;
	_finish = _start + oldCapacity;
	_end_of_storage = _start + newCapacity;
}

template <class T>
void Vector<T>::pop_back()
{
	if(size() > 0) {
		--_finish;
		_alloc.destroy(_finish);
	}
}

template<class S>
void display(S & vec)
{
	cout << "vec's size() = " << vec.size() << endl
		 << "vec's capacity() = " << vec.capacity() << endl;
}

void test0() 
{
	Vector<int> numbers;
	display(numbers);

	numbers.push_back(1);
	display(numbers);

	numbers.push_back(2);
	display(numbers);

	numbers.push_back(3);
	display(numbers);

	numbers.push_back(4);
	display(numbers);

	numbers.push_back(5);
	display(numbers);
	
	for(auto &elem : numbers) {
		cout << elem << " ";
	}
	cout << endl;
	
	numbers.pop_back();
	display(numbers);
	numbers.pop_back();
	display(numbers);
	
	for(auto &elem : numbers) {
		cout << elem << " ";
	}
	cout << endl;
}	

class Point
{
public:
	Point(int x, int y)
	: _x(x)
	, _y(y)
	{}

	~Point(){}

	void display() {
		cout << "(" << _x
			 << "," << _y
			 << ")" << endl;
	}

	//friend std::ostream & operator<<(std::ostream & os, const Point & rhs);
private:
	int _x;
	int _y;
};
void test1()
{
	Vector<Point> numbers;
	display(numbers);
	
	numbers.push_back(Point(1, 2));
	display(numbers);

	numbers.push_back(Point(2, 2));
	display(numbers);

	numbers.push_back(Point(3, 2));
	display(numbers);

	numbers.push_back(Point(4, 2));
	display(numbers);

	for(auto elem:numbers) {
		elem.display();
	}
}

int main(void)
{
	//test0();
	test1();
	return 0;
}
