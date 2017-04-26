/*
 * AcceptManager.h
 *
 *  Created on: 2013��9��3��
 *      Author: helh
 */

#ifndef ACCEPTMANAGER_H_
#define ACCEPTMANAGER_H_

#include <vector>
#include "../Thread/Task.h"
#include "InetAddress.h"
#include "NetWorkConfig.h"
#include "../Memory/MemAllocator.h"
#include <unistd.h>

using namespace std;

namespace CommBaseOut
{

class Task;
class Context;
class Inet_Addr;
class AcceptorConfig;

class CAcceptor:public Task
#ifdef USE_MEMORY_POOL
, public MemoryBase
#endif
{
public:
	CAcceptor(Context *c);
	~CAcceptor();

	int Init(AcceptorConfig& conf);

	void CloseSocket(int sock)
	{
		//__sync_fetch_and_sub(&m_sockCount, 1);
		close(sock);
		sock = -1;
	}

	void SetIndex(int index)
	{
		m_index = index;
	}

private:
	virtual int svr();

private:
	int m_sockLis; //����socket
	AcceptorConfig m_addr;
	Context *m_c;
	int m_index;
};

class CAcceptorMgr
#ifdef USE_MEMORY_POOL
: public MemoryBase
#endif
{
public:
	CAcceptorMgr(Context *c);

	 ~CAcceptorMgr();

	int AddAccept(AcceptorConfig &conf);
	int DeleteAll();

private:
	vector<CAcceptor *> m_acceptor;
	Context *m_c;
};







}


#endif /* ACCEPTMANAGER_H_ */
