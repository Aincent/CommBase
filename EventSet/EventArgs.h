/*
 * EventArgs.h
 *
 *  Created on: 2014年5月8日
 *      Author: helh
 */

#ifndef EVENTARGS_H_
#define EVENTARGS_H_

#include "../define.h"


namespace CommBaseOut
{


class EventArgs
{
public:
	friend class CEEvent;

	EventArgs(void) : handled(0), bfire(false) {}
	virtual ~EventArgs(void) {}

	DWORD handled;

	bool IsFire() const { return bfire; }
private:
	bool bfire;
};


}




#endif /* EVENTARGS_H_ */
