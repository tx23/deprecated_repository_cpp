 ///
 /// @file    leetcodeWordLadder.cc
 /// @author  tangxin(tangxin_sysu@foxmail.com)
 /// @date    2019-01-24 03:54:21
 ///
#include <unordered_set>
#include <set>
#include <iostream>
#include <vector>
#include <string>
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::set;
using std::unordered_set;
class Solution {
public:
	int ladderlength(string beginWord, string endWord, const set<string>& wordList) {
		unordered_set<string> wordDict(wordList.begin(), wordList.end());//将字典转存至无序关联容器中
		if(wordDict.find(endWord) == wordDict.end()) {
			return 0;//endword并未在词典中出现
		}
		
		unordered_set<string> beginSet{beginWord};
		int step = 0;
		while(beginSet.find(endWord) == beginSet.end()) {
			unordered_set<string> tempSet;
			for(auto elem:beginSet) {//将同一层的单词依次出队
				for(size_t i=0; i<elem.size(); ++i) {//从第一个字母开始换
					for(char c = 'a'; c <= 'z'; ++c) {//一次换一个字母，比较
					string str = elem;
					str[i] = c;
					if(wordDict.find(str) != wordDict.end()) {
						wordDict.erase(str);//从字典中删除，插入至tempSet，以免死循环
						tempSet.insert(str);//将与elem差一个字母的单词全存进tempSet。
					}
					}
				}
			}
			if(tempSet.empty())//若为空，即无与该单词差一个字母的单词
				return 0;
			beginSet = tempSet;
			++step;//一层队列加一
		}
		return step+1;
	}


};

void test1()
{
	Solution a;
	const set<string> wordlist{
		"hot", "dot", "dog", "lot", "log", "cog"};
	string beginWord = "hit";
	string endWord = "cog";
	int n = 0;
	n =	a.ladderlength(beginWord, endWord, wordlist);
	cout << n << endl;
}
int main(void)
{
	test1();
	return 0;
}
