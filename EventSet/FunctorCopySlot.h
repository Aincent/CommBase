/*
 * FunctorCopySlot.h
 *
 *  Created on: 2014年5月8日
 *      Author: helh
 */

#ifndef FUNCTORCOPYSLOT_H_
#define FUNCTORCOPYSLOT_H_

#include "SlotFunctorBase.h"

namespace CommBaseOut
{
	template<typename T>
	class FunctorCopySlot : public SlotFunctorBase
	{
	public:
		FunctorCopySlot(const T& functor) :
		  d_functor(functor)
		  {}

		  virtual bool operator()(const EventArgs& args)
		  {
			  return d_functor(args);
		  }

	private:
		T d_functor;
	};
}




#endif /* FUNCTORCOPYSLOT_H_ */
