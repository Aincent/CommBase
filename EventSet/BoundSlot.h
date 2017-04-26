/*
 * BoundSlot.h
 *
 *  Created on: 2014年5月7日
 *      Author: helh
 */

#ifndef BOUNDSLOT_H_
#define BOUNDSLOT_H_

#include <string>
#include "../Memory/MemAllocator.h"

using namespace std;


namespace CommBaseOut
{

class CEEvent;
class SubscriberSlot;

class BoundSlot
#ifdef USE_MEMORY_POOL
: public MemoryBase
#endif
{
public:
	typedef unsigned int Group;

	BoundSlot(Group group, const SubscriberSlot& subscriber, CEEvent& event, const char* pFileName, size_t line, const char* pFunName);

	BoundSlot(const BoundSlot& other);

	~BoundSlot();

	bool Connected() const;

	void Disconnect();

	bool operator==(const BoundSlot& other) const;

	bool operator!=(const BoundSlot& other) const;

	// 得到调试信息
	inline void GetDebufInfo(std::string& text) const
	{
		char temp[512] = {'\0'};
		snprintf(temp, 512, "fileName: %s  line:%zu fun:%s", m_fileName.c_str(), m_lineSize, m_funName.c_str());
		text += temp;
	}

private:
	friend class CEEvent;

	BoundSlot& operator=(const BoundSlot& other);
	Group m_group;
	SubscriberSlot* m_subscriber;
	CEEvent* m_event;

	string m_fileName; // 注册的文件名
	size_t      m_lineSize; // 行数
	string m_funName;  // 函数名
};
}



#endif /* BOUNDSLOT_H_ */
