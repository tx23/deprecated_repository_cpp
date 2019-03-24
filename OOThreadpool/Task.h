 ///
 /// @file    Task.h
 /// @author  tangxin(tangxin_sysu@foxmail.com)
 /// @date    2019-02-10 05:50:20
 ///
#ifndef _WD_TASK_H_
#define _WD_TASK_H_

namespace wd
{
class Task
{
public:
	virtual void process() = 0;//纯虚函数
	virtual ~Task(){}
};

}

#endif
