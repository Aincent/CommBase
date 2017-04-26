/*
 * ConnManager.h
 *
 *  Created on: 2013��9��3��
 *      Author: helh
 */

#ifndef CONNMANAGER_H_
#define CONNMANAGER_H_

#include <map>
#include "../define.h"
#include "../Thread/Task.h"
#include "../Common.h"
#include "../Memory/MemAllocator.h"

using namespace std;

namespace CommBaseOut
{

enum EConnStatus
{
	eDisconnection, //�Ͽ�����
	eConnetion, //����״̬
	eReConnection, //����
	eDelConnection, //ɾ������
};

typedef struct
{
	int m_sock;
	BYTE m_status;
	BYTE m_index;
}ConnData;

class Context;

class CConnMgr : public Task
#ifdef USE_MEMORY_POOL
, public MemoryBase
#endif
{
public:
	CConnMgr(Context * c);
	~CConnMgr();

	int Init();

	int AddConn(int sock, int index);

	virtual void Close()
	{
//		m_flag = true;
//		m_event.SetEvent();
//		m_flag = false;
		End();
	}

private:
	virtual int svr();

private:
	map<int, ConnData> m_conn;
	CSimLock m_connLock;
	Context *m_c;
//	Event m_event;
};





}



#endif /* CONNMANAGER_H_ */
