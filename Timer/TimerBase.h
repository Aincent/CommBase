/*
 * TimerBase.h
 *
 *  Created on: 2013-11-17
 *      Author: helh
 */

#ifndef TIMERBASE_H_
#define TIMERBASE_H_

#include "Timer.h"
#include "../Smart_Ptr.h"
#include "../Memory/MemAllocator.h"

namespace CommBaseOut
{

class TimerBase
#ifdef USE_MEMORY_POOL
: public MemoryBase
#endif
{
public:
	TimerBase(){}
	virtual ~TimerBase(){}

	virtual bool start(TimerBase* tm)
	{
		return true;
	}

	virtual int AddTimer(Safe_Smart_Ptr<Timer> &timer, int isNewTimer = 1)
	{
		return 0;
	}

	virtual int AddTimer(Safe_Smart_Ptr<Timer> &timer, DWORD slot)
	{
		return 0;
	}

private:
};

}


#endif /* TIMERBASE_H_ */
