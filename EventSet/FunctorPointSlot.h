/*
 * FunctorPointSlot.h
 *
 *  Created on: 2014年5月8日
 *      Author: helh
 */

#ifndef FUNCTORPOINTSLOT_H_
#define FUNCTORPOINTSLOT_H_

#include "SlotFunctorBase.h"

namespace CommBaseOut
{
	template<typename T>
	class FunctorPointerSlot : public SlotFunctorBase
	{
	public:
		FunctorPointerSlot(T* functor) :
		  d_functor(functor)
		  {}

		  virtual bool operator()(const EventArgs& args)
		  {
			  return (*d_functor)(args);
		  }

	private:
		T* d_functor;
	};
}





#endif /* FUNCTORPOINTSLOT_H_ */
