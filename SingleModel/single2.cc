#include<iostream>
using namespace std;
//单例模式
class single
{
public:
	static single *getInstance() {
		if(nullptr == _pInstance) {
			_pInstance = new single();
		}
		return _pInstance;
	}

	static void destroy()
	{
		if(_pInstance) {
			delete _pInstance;
		}
	}

private:
	single(){}
	~single(){}
	static single* _pInstance;
};

single *single::_pInstance = nullptr;//静态成员初始化

int main() {
	single *p1 = single::getInstance();
	single *p2 = single::getInstance();
	cout << "p1 = " << p1 << endl
		 << "p2 = " << p2 << endl;
	single::destroy;
	return 0;
}
