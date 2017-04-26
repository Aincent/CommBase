/*
 * Task.h
 *
 *  Created on: 2013��9��2��
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
	eCreateThreadErr, //�����߳�ʧ��
};

/*
 * ִ�����ö��̵߳�����
 * ����Ϊ����
 */
class Task
{
public:
	Task();
	virtual ~Task();

	/*
	 *��������
	 *return :
	 *param :num �̵߳ĸ���    attr���ڵ����߳�����
	 */
	int Start(int num, pthread_attr_t *attr = 0);

	/*
	 *��������
	 *return :
	 *param :
	 */
	int End();

	/*
	 * �����ؽ���
	 * return :
	 * param:
	 */
	virtual void Close(){}

private:

	/*
	 * �߳����
	 * return :
	 * param :
	 */
	static void * ThreadRun(void *p);

	/*
	 *����ִ�нӿ�,������д
	 *return :
	 *param :
	 */
	virtual int svr();

protected:

	bool m_flag; //�߳̽�����־

private:
	int m_count; //�����̵߳ĸ���
	pthread_t *m_pID; //�������߳�
};







}


#endif /* TASK_H_ */
