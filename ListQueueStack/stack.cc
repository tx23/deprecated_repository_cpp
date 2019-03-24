#include<iostream>
using std::cout;
using std::endl;

class Stack
{
public:
	Stack()             //构造函数
	: num(0)
	{
	num = 0;
	}                  

	~Stack(){}          //析构函数

	bool empty()        //判空
	{
		return num == 0;
	}

	bool full()         //判满
	{
	return num == max;
	}

	bool push(int n);   //入栈
	
	bool pop();          //出栈

	bool top();           //读出栈顶元素

private:
	static const size_t max = 10; //栈的最大容量为10
	int elem[max];
	size_t num;    //当前栈的深度
};



	bool Stack::push(int n)   //入栈
	{
		if(full()) {
			cout << "栈已满，入栈失败。" << endl;
			return false;
		}
		else {
		elem[num] = n;
		cout << "入栈：" << elem[num] << endl;
		num++;
		return true;
		}
	}// bool push
	
	bool Stack::pop()           //出栈
	{
		if(empty()) {
			cout << "栈已空，出栈失败。" << endl;
			return false;
		}
		else {
//			cout << "出栈： " << elem[num-1] << endl; 不需要输出
			num--;
		}
	}//bool pop

	bool Stack::top()           //读出栈顶元素
	{
		if(empty()) {
			cout << "栈空，无栈顶元素" << endl;
			return false;
		}
		else {
			cout << "栈顶元素：" << elem[num-1] <<endl;
		}
	}//bool top


int main(void)
{
	Stack test; //建栈
	test.push(10); //10入栈
	test.push(10); //10入栈
	test.push(10); //10入栈
	test.push(10); //10入栈
	test.push(12); //12入栈
	test.push(14); //14入栈
	test.push(12); //12入栈
	test.push(14); //14入栈
	test.push(12); //12入栈
	test.push(14); //14入栈
	test.push(12); //12入栈
	test.push(14); //14入栈

	test.top(); //read the top
	test.pop(); //pop
	test.top(); //read the top

	return 0;
}
