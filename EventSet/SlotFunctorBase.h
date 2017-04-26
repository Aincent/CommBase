/*
 * SlotFunctorBase.h
 *
 *  Created on: 2014年5月7日
 *      Author: helh
 */

#ifndef SLOTFUNCTORBASE_H_
#define SLOTFUNCTORBASE_H_

#include "../Memory/MemAllocator.h"

namespace CommBaseOut
{
	class EventArgs;

	class SlotFunctorBase
#ifdef USE_MEMORY_POOL
: public MemoryBase
#endif
	{
	public:
		virtual ~SlotFunctorBase() {};
		virtual bool operator()(const EventArgs& args) = 0;
	};
}



#endif /* SLOTFUNCTORBASE_H_ */
