 ///
 /// @file    singleton.h
 /// @author  tangxin(tangxin_sysu@foxmail.com)
 /// @date    2019-01-21 03:04:13
 ///
#ifndef _TEMPLATE_SINGLETON_H
#define _TEMPLATE_SINGLETON_H

#include <iostream>
using std::cout;
using std::endl;
 
template <class T>
class Singleton
{
public:
	template <class... Args>
	static T* getInstance(Args... args)
	{
		if(nullptr == _pInstance) {
			_pInstance = new T(args...);
			_ar;//将类模板实例化
		}
		return _pInstance;
	}



private:
	class AutoRelease {
	public:
		AutoRelease() {cout << "AutoRelease()" << endl;}
		~AutoRelease() {
			if(_pInstance) {
				delete _pInstance;
				cout << "~AutoRelease()" << endl;
			}
		}
	};

private:
	Singleton() {cout << "Singleton()" << endl;}
	~Singleton() {cout << "~Singleton()" << endl; }
private:
	static T *_pInstance;
	static AutoRelease _ar;
};

template <class T>
T *Singleton<T>::_pInstance = nullptr;

template <class T>
class Singleton<T>::AutoRelease Singleton<T>::_ar;

#endif
