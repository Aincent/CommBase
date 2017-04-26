/*
 * FunctorReferenceSlot.h
 *
 *  Created on: 2014年5月8日
 *      Author: helh
 */

#ifndef FUNCTORREFERENCESLOT_H_
#define FUNCTORREFERENCESLOT_H_

#include "SlotFunctorBase.h"

namespace CommBaseOut
{
	template<typename T>
	class FunctorReferenceSlot : public SlotFunctorBase
	{
	public:
		FunctorReferenceSlot(T& functor) :
		  d_functor(functor)
		  {}

		  virtual bool operator()(const EventArgs& args)
		  {
			  return d_functor(args);
		  }

	private:
		T& d_functor;
	};
}





#endif /* FUNCTORREFERENCESLOT_H_ */
