/*
 * ClassBase.h
 *
 *  Created on: 2013��11��28��
 *      Author: helh
 */

#ifndef CLASSBASE_H_
#define CLASSBASE_H_

#include "Ref_Object.h"
#include "Memory/MemAllocator.h"

namespace CommBaseOut
{


/*
 * �ջ���
 * �����̳�
 */
class NullBase : public Ref_Object
//#ifdef USE_MEMORY_POOL
//, public MemoryBase
//#endif
{
public:
	virtual ~NullBase(){}
};

}



#endif /* CLASSBASE_H_ */
