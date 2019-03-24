 ///
 /// @file    Line.h
 /// @author  tangxin(tangxin_sysu@foxmail.com)
 /// @date    2019-01-15 04:21:15
 ///
#ifndef _LINE_H_
#define _LINE_H_
//设计模式之PIMPL

class Line
{
public:
	Line(int, int, int, int);
	~Line();

	void printLine() const;

	class LineImpl;

private:
	LineImpl *p;

};

#endif

 
 
