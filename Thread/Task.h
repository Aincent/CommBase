/*
 * Task.h
 *
 *  Created on: 2013年9月2日
 *      Author: helh
 */
#include <pthread.h>

#ifndef TASK_H_
#define TASK_H_

namespace CommBaseOut
{

enum E_TaskRet
{
	eTaskSuccess=0,
	eCreateThreadErr, //创建线程失败
};

/*
 * 执行永久多线程的任务
 * 此类为父类
 */
class Task
{
public:
	Task();
	virtual ~Task();

	/*
	 *开启任务
	 *return :
	 *param :num 线程的个数    attr用于调节线程属性
	 */
	int Start(int num, pthread_attr_t *attr = 0);

	/*
	 *结束任务
	 *return :
	 *param :
	 */
	int End();

	/*
	 * 可重载结束
	 * return :
	 * param:
	 */
	virtual void Close(){}

private:

	/*
	 * 线程入口
	 * return :
	 * param :
	 */
	static void * ThreadRun(void *p);

	/*
	 *任务执行接口,用来复写
	 *return :
	 *param :
	 */
	virtual int svr();

protected:

	bool m_flag; //线程结束标志

private:
	int m_count; //任务线程的个数
	pthread_t *m_pID; //创建的线程
};







}


#endif /* TASK_H_ */
