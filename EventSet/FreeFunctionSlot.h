/*
 * FreeFunctionSlot.h
 *
 *  Created on: 2014年5月8日
 *      Author: helh
 */

#ifndef FREEFUNCTIONSLOT_H_
#define FREEFUNCTIONSLOT_H_

#include "SlotFunctorBase.h"

namespace CommBaseOut
{
	class FreeFunctionSlot : public SlotFunctorBase
	{
	public:
		typedef bool (SlotFunction)(const EventArgs&);

		FreeFunctionSlot(SlotFunction* func) :
		d_function(func)
		{}

		virtual bool operator()(const EventArgs& args)
		{
			return d_function(args);
		}

	private:
		SlotFunction* d_function;
	};
}





#endif /* FREEFUNCTIONSLOT_H_ */
