/*
 * MemberFunctionSlot.h
 *
 *  Created on: 2014年5月7日
 *      Author: helh
 */

#ifndef MEMBERFUNCTIONSLOT_H_
#define MEMBERFUNCTIONSLOT_H_

#include "SlotFunctorBase.h"

namespace CommBaseOut
{
	template<typename T>
	class MemberFunctionSlot : public SlotFunctorBase
	{
	public:
		typedef bool(T::*MemberFunctionType)(const EventArgs&);

		MemberFunctionSlot(MemberFunctionType func, T* obj) :
		d_function(func),
			d_object(obj)
		{}

		virtual bool operator()(const EventArgs& args)
		{
			return (d_object->*d_function)(args);
		}

	private:
		MemberFunctionType d_function;
		T* d_object;
	};
}





#endif /* MEMBERFUNCTIONSLOT_H_ */
