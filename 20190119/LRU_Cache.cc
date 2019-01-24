 ///
 /// @file    LRU_Cache.cc
 /// @author  tangxin(tangxin_sysu@foxmail.com)
 /// @date    2019-01-21 07:06:16
 ///
 
#include <iostream>
#include<string.h>
using std::cout;
using std::endl;
using std::string;

class LRUCache
{
public:
	LRUCache(int capacity1) 
	: _capacity(capacity1)
	, CacheSize(new int[strlen(_capacity)]())
	{}


private:
	struct CacheNode {
		int key;
		int value;
		CacheNode(int k, int v)
		: key(k)
		, value(v) {}
	};
	int _capacity;
	int *CacheSize;
};
int main(void)
{
 
}
