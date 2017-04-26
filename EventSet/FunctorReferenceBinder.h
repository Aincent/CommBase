/*
 * FunctorReferenceBinder.h
 *
 *  Created on: 2014年5月8日
 *      Author: helh
 */

#ifndef FUNCTORREFERENCEBINDER_H_
#define FUNCTORREFERENCEBINDER_H_

namespace CommBaseOut
{
	template<typename T>
	struct FunctorReferenceBinder
	{
		FunctorReferenceBinder(T& functor) :
	d_functor(functor)
	{}

	T& d_functor;
	};
}





#endif /* FUNCTORREFERENCEBINDER_H_ */
