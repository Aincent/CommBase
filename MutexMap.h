//#pragma once
//
//#include <map>
//
//template<typename KEY, typename VALUE>
//class sMutexMapByID
//{
//public:
//	typedef typename std::map<KEY, VALUE> Map;         // ����
//	typedef typename Map::iterator        MapItr;      // �����
//	typedef typename Map::const_iterator  MapConstItr; // �����
//
//	Map          m_map;  // ����
//	Thread_Mutex m_lock; // �߳���
//
//	// �õ�
//	inline VALUE get(KEY id)
//	{
//		GUARD_RETURN(Thread_Mutex, obj, m_lock, VALUE(NULL));
//		return getNoLock(id);
//	}
//
//	// �õ�
//	inline VALUE getNoLock(KEY id)
//	{
//		MapItr itr = m_map.find(id);
//		if (itr == m_map.end())
//			return VALUE(NULL);
//
//		return itr->second;
//	}
//
//	// ���
//	inline bool add(KEY id, VALUE player)
//	{
//		GUARD_RETURN(Thread_Mutex, obj, m_lock, false);
//		return addNoLock(id, player);
//	}
//
//	inline bool addNoLock(KEY id, VALUE player)
//	{
//		return m_map.insert(std::make_pair(id, player)).second;
//	}
//
//	// ɾ��
//	inline bool remove(KEY id)
//	{
//		GUARD_RETURN(Thread_Mutex, obj, m_lock, false);
//		return removeNoLock(id);
//	}
//
//	// �������
//	inline void clear()
//	{
//		GUARD(Thread_Mutex, obj, m_lock);
//		m_map.clear();
//	}
//
//	// ɾ��
//	inline VALUE remove_get(KEY id)
//	{
//		VALUE value(NULL);
//		{
//			GUARD_RETURN(Thread_Mutex, obj, m_lock, value);
//			MapItr itr = m_map.find(id);
//			if (itr != m_map.end())
//			{
//				value = itr->second;
//				m_map.erase(itr);
//			}
//		}
//
//		return value;
//	}
//
//	// ɾ��
//	inline VALUE remove_get_nolock(KEY id)
//	{
//		MapItr itr = m_map.find(id);
//		if (itr != m_map.end())
//		{
//			VALUE value = itr->second;
//			m_map.erase(itr);
//			return value;
//		}
//
//		return VALUE(NULL);
//	}
//
//	// �Ƴ�����
//	inline bool removeNoLock(KEY id)
//	{
//		return m_map.erase(id) == 0 ? false : true;
//	}
//
//	// �õ�����
//	inline size_t getSize() const
//	{
//		return m_map.size();
//	}
//};
