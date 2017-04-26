/*
 * LuaPoolInterface.h
 *
 *  Created on: 2013��10��10��
 *      Author: helh
 */

#ifndef LUAPOOLINTERFACE_H_
#define LUAPOOLINTERFACE_H_

#include "../Smart_Ptr.h"
#include "lua.hpp"
#include "LuaInterface.h"


namespace CommBaseOut
{

class LuaPoolInterface
{
public:
	LuaPoolInterface();
	~LuaPoolInterface();

	/**
	*  执行已经加载lua程序或者lua函数
	*	return : E_LuaRet
	*	param : nArgs lua函数参数个数    nRets lua函数返回结果
	*	 note : 执行一段lua的chunk时，nArgs和nRets都为0
	*/
	int Call(int nArgs = 0, int nRets = 0);

	/**
	*	 ����һ��ȫ�ֱ�����ֵΪ�ַ�ֵ
	*	return : E_LuaRet
	*	param : strGlobalName ȫ�ֱ�����     strGlobalValue ȫ�ֱ���ֵ
	*/
	int SetGlobalString(const char *strGlobalName, const char *strGlobalValue);

	/**
	* ����һ��ȫ�ֱ�����ֵΪlightuserdata
	*	return : E_LuaRet
	*param : strGlobalName ȫ�ֱ�����      pValue lightuserdataֵ
	*/
	int SetGlobalLightUserData(const char *strGlobalName, void *pValue);

	/**
	* ����һ��ȫ�ֱ�����ֵΪint
	*	return : E_LuaRet
	*	param : strGlobalName ȫ�ֱ�����       nValue Ҫ���õ�ֵ
	*/
	int SetGlobalInt(const char *strGlobalName, int nValue);

	/**
	* ��lua���½�һ����
	*/
	void CreateNewTable();

	/**
	* ��lua���������ֶκ�ֵ
	*	return : E_LuaRet
	*param : strFieldName ���ֶ���           nValue �ֶε�ֵ
	*/
	int SetFieldInt(const char *strFieldName, int nValue);

	/**
	* ��lua���������ֶκ�ֵ
	*	return : E_LuaRet
	* param : nIndex �ֶ�����     nValue �ֶε�ֵ
	*/
	int SetFieldInt(int nIndex, int nValue);

	/**
	*	 ��lua��������һ��������
	*	return : E_LuaRet
	*	param : nIndex ���ֶ�����
	*/
	int SetFieldTable(int nIndex);

	/**
	*	 ��lua��������һ��������
	*	return : E_LuaRet
	*	param : strTableName ���ֶ�����
	*/
	int SetFieldTable(const char *strTableName);

	/**
	*	 ����table����
	*	return : E_LuaRet
	*	param : strTableName ����table���
	*/
	int FinishTable(const char *strTableName);

	/**
	*	 ��lua��ע��һ��C����
	*	return : E_LuaRet
	*	param : strFunName Ҫע�ắ�����      lua_CFunction fun Ҫע�ắ��
	*/
	int RegisterFun(const char *strFunName, lua_CFunction fun);

	/**
	*	 Ҫ����lua��������ջ
	*	return : E_LuaRet
	*	param strFunName Ҫ����lua������
	*/
	int SetLuaFunction(const char *strFunName);

	/**
	*	   ��������ջ
	*	 return: E_LuaRet
	*	 param : nValue Ҫ��ջ��ֵ
	*	 note �������ռ��һ��ջ�ռ�
	*/
	int SetInt(int nValue);

	/**
	*	   ��һ����������ջ
	*	 return : E_LuaRet
	*	 param : fValue Ҫ��ջ��ֵ
	*	 note �������ռ��һ��ջ�ռ�
	*/
	int SetFloat(float fValue);

	/**
	*	   ���ַ���ջ
	*	 return : E_LuaRet
	*	 param : strValue Ҫ��ջ��ֵ
	*	 note �������ռ��һ��ջ�ռ�
	*/
	int SetString(const char *strValue);

	/**
	*	   ��ջһ��lightuserdata��һ������ָ����ջ
	*	 return : E_LuaRet
	*	 param : pValue Ҫ��ջ��ֵ
	*	 note �������ռ��һ��ջ�ռ�
	*/
	int SetLightUserData(void *pValue);

	/**
	*	   ��ȡһ������ֵ
	*	 return : ���ر���ֵ
	*	 param : strParamName Ҫ��ȡ�ı�����  nIndex ��ȡ��������ջλ�ã�Ĭ�ϴ�ջ��ȡ
	*/
	int GetInt(const char *strParamName = NULL, int nIndex = -1);

	/**
	*	   ��ȡһ��������
	*	 param : strParamName Ҫ��ȡ�ı�����    nIndex ��ȡ��������ջλ�ã�Ĭ�ϴ�ջ��ȡ
	*	 return : ���ر���ֵ
	*/
	float GetFloat(const char *strParam = NULL, int nIndex = -1);

	/**
	*	   ��ȡ�ַ��ֵ
	*	 return : E_LuaRet
	*	 param : buf ��ȡ����ֵ��Ż�����   nLen �������   strParamName Ҫ��ȡ������ΪNULLʱ����ջ��ֵ  nIndex ��ȡ��������ջλ�ã�Ĭ�ϴ�ջ��ȡ
	*/
	int GetString(char *buf, int nLen, const char* strParamName = NULL, int nIndex = -1);

	/**
	*	   ��һ��table��ջ
	*	 return : E_LuaRet
	*	 param : strTableName Ҫ��ջtable��
	*	 note ������ɺ�ռ��ջ�ռ��1��ʹ�������Ҫ����CloseTable
	*/
	int GetTable(const char *strTableName);

	/**
	*	   �����õ�table��ջ
	*/
	void CloseTable(void);

	/**
	*	   ��ȡ���Ԫ�ظ���
	*	 return : �ɹ�����table���ֶ���ʧ�ܷ���С��0
	*	 param :
	*/
	int GetTableFieldCount(void);

	/**
	*	   ��ȡ��ά���е���ֵ, ��ȡ��info={{1, 9, 3}, {29, 89, 55}}�е�ֵ9
	*	 return :
	* param : nKey1 ���е�һά������, ��: nKey1=1����ȡ��һά�ı�Ԫ��Ϊ: {1, 9, 3}
		         nKey2 Ϊ���еڶ�ά��������: nKey1=1��nKey2=2����ȡ��һά��Ԫ��: {1, 9, 3}�е�Ԫ��: 9��
	*/
	int GetFieldIntInTableList(int nKey1, int nKey2);

	/**
	*	   ��ȡ��ά���е��ַ�, ��ȡ��info={{1, "abc", 3}, {29, 89, 55}}�е��ַ�"abc"
	* return :
	* param : nKey1 ���е�һά������, ��: nKey1=1����ȡ��һά�ı�Ԫ��Ϊ: {1, "abc", 3}
			          nKey2 Ϊ���еڶ�ά��������: nKey1=1��nKey2=2����ȡ��һά��Ԫ��: {1, "abc", 3}�е�Ԫ��: "abc"��
	*/
	int GetFieldStringInTableList(char *buf, int nLen, int nKey1, int nKey2);

	/**
	*	   ��ȡtable��һ��field������ֵ
	*	 return : ����key��Ӧ��ֵ��С
	*	 param : strKey Ҫ��ȡ��key���
	*	 note ��table��keyΪ�ַ�ʱ���ô˺���
	*/
	int GetFieldInt(const char *strKey);

	/**
	*	   ��ȡtable��һ��field������ֵ
	*	 return : ����key��Ӧ��ֵ��С
	*	 param : nKey Ҫ��ȡ��key����
	*	 note ��table��keyΪ����ʱ���ô˺���
	*/
	int GetFieldInt(int nKey);

	/**
	*	   ��ȡtable��һ��field�ĸ�����ֵ
	*	 return : ����key��Ӧ��ֵ
	*	 param : nKey Ҫ��ȡ��key����
	*	 note ��table��keyΪ����ʱ���ô˺���
	*/
	float GetFieldFloat(int nKey);

	/**
	*	 table��һ��fieldΪtableʱ�����ô˷�����ȡtable��һ��field
	*	 return : E_LuaRet
	*	 param : nKey Ҫ��ȡ��key����
	*	 note ��table��keyΪ����ʱ���ô˺���������ռ��ջ�ռ��1
	*/
	int GetFieldTable(int nKey);

	/**
	*	 table��һ��fieldΪtableʱ�����ô˷�����ȡtable��һ��field
	*	 param : nKey Ҫ��ȡ��key����
	*	 return : E_LuaRet
	*	 note ��table��keyΪ����ʱ���ô˺���������ռ��ջ�ռ��1
	*/
	int GetFieldTable(const char *sKey);

	/**
	*	   ��ȡtable��һ��field���ַ�ֵ
	*	 return : E_LuaRet
	*	 param : buf ��ȡ�ַ�����   nLen �������С   strKey Ҫ��ȡ��key���
	*	 note ��table��keyΪ�ַ�ʱ���ô˺���
	*/
	int GetFieldString(char *buf, int nLen, const char *strKey);

	/**
	*	   ��ȡtable��һ��field���ַ�ֵ
	*	 return : E_LuaRet
	*	 param : buf ��ȡ�ַ�����  nLen �������С  nKey Ҫ��ȡ��key����
	*	 note ��table��keyΪ����ʱ���ô˺���
	*/
	int GetFieldString(char *buf, int nLen, int nKey);

	/**
	*	   ��ջ
	*	 return :
	*	 param : n Ҫ��ջ��Ŀ
	*/
	void Pop(int n);

	/**
	*	   ��ȡstack top
	*	 return : stack top
	*	 param :
	*/
	int GetStackTop();

	void SavedStackSize();

	Smart_Ptr<CLuaInterface> & GetLua()
	{
		return m_lua;
	}

private:
	Smart_Ptr<CLuaInterface> m_lua;
};

}
#endif /* LUAPOOLINTERFACE_H_ */
