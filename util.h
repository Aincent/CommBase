#pragma once 
#include "define.h"

namespace CommBaseOut
{

extern "C" {
	void UtilOutPut(int one , int two);
};

class CUtil
{
public:
    CUtil();
    ~CUtil();

    /*
     * ����
  * return : 0 �ɹ�      ��1 ʧ��
  * param :����ģ����Ŀ�껺��      ����ģ���̣��Ŀ�껺���С       ��ӣ��Դ���桡�����C����̣����Ҫcopy���ֽ���
     */
	static int SafeMemmove(void *pDst, DWORD dwDstLen, const void *pSrc, DWORD dwCopyLen);

	/*
	 * 64λ���С��ģʽ�ֽ�����
	 * return �� ת�����8�ֽ�ֵ
	 * param ����ת����
	 */
	static DWORD64 ntohll(DWORD64 src);

	/*
	*	�ַ�תΪ����
	*	return �� �ɹ�����ת������ֵ��ʧ�ܷ���0
	*	param �� strҪת���ַ�
	*/
	static int StringToInt(const std::string &str);

	/*
	 * ByteToStr �ڴ�ת��Ϊ�ַ����
	 * return : 0 �ɹ�   -1 ʧ��
	 * param : buf �ڴ�ָ��  dwLen �ڴ泤��  str ת�����ַ�
	 */
	static int ByteToStr(const BYTE *buf, DWORD dwLen, std::string &str);

	/*
	 *GetBinPath  ��ȡ��ǰ���г����ļ�����ȫ·���������ļ���
	 *return :0 �ɹ�   -1 ʧ��
	 * param : strFileFullPath ��ǰ���г�������·��
	 */
  static int GetBinPath(std::string &strFileFullPath);

  /*
  *  ��ȡ��ǰ���г����ļ�����·������β����'/'
  *  return : 0 �ɹ�   -1 ʧ��
  *  param :strFileFullPath ��ǰ���г�������·��
   */
	static int GetModulePath(std::string &strFileFullPath);

	/*
	 * ������·����ȡ���·��
	 * return : 0 �ɹ�   -1 ʧ��
	 * param :strFilePath ���·��    strFullPath ���·��
	 */
	static int GetFullPath(const std::string &strFilePath, std::string &strFullPath);

	/*
	 *���·���Ҿ��·��
	 * return : 0 �ɹ�   -1 ʧ��
	 * param :strFilePath ���·��        strConvertPath���صľ��·��
				    strFilePath = "../../script/serverconfig.lua")
	        strConvertPath = "/home/work/ljh/branch/script/serverconfig.lua"
	 */
	static int GetFullPathFromRelative(const std::string &strFilePath, std::string &strConvertPath);

	/*
	 * ��ȡָ���ļ���С
	 * return : �ɹ������ļ���С��ʧ�ܷ���-1
	 * param :strFileName �ļ���
	 */
	static int64 GetFileSize(const std::string &strFileName);

	/*
	 * ��ȡ�ļ��д�С
	 * return : �ɹ������ļ��д�С��ʧ�ܷ���-1
	 * param : strFilePath �ļ���·��
	 */
	static int64 GetFolderSize(const std::string &strFilePath);

	/*
	 * ��ȡ�뵱ǰʱ�����һ����������ڣ������ʾ��󣬸����ʾ��ǰ
	 * return :
	 * param : nSpan �������    strDate ������yyyy-mm-dd��ʽ���
	 */
	static void GetSpanDate(int nSpan, std::string &strDate);
	static void GetSpanMinutes(std::string &strDate);

	/*
	 * ��ȡ��ǰ�ĺ���
	 * return : ��ǰ�ĺ�����
	 * param :
	 */
	static DWORD64 GetNowSecond();

	/*
	 * ��ȡ��ǰ��΢��
	* return : ��ǰ��΢����
	* param :
	 */
	static DWORD64 GetNowMicrosecod();

	/*
	 * ��ȡĳ���е�ĳ�µ�����
	* return : �µ�����
	* param :year ��Ҫ��ѯ�����    month��Ҫ��ѯ����
	 */
	static BYTE GetCurMonthDay(int year, int month);

	/*
	 * 获取下一次今日日期的间隔时间（有可能这个月有31号，但是下个月只有30号，下下个月是31号，需要遍历才知道）
	* return : 间隔时间(毫秒)
	* param :year 当前的年    month当前的月  day 当前的天    nMonth下次出现今天日期的月
	 */
	static int64 GetNextMonthDay(int year, int month, int day, int &nMonth);

	/*
	 * 判断是否是同一天
	* return : true 是同一天， false  不是
	* param :  time 需要比较的时间（毫秒）
	 */
	static bool IsSameDay(int64 btime);

	/*
	 * 判断是否是同一周
	* return : true 是同一周， false  不是
	* param :  time 需要比较的时间（毫秒）
	 */
	static bool IsSameWeek(int64 btime);

	/*
	 * 判断是否是同一月
	* return : true 是同一月， false  不是
	* param :  time 需要比较的时间（毫秒）
	 */
	static bool IsSameMonth(int64 btime);

	/*
	 * 把传入的年月日转换成一个时间点(年是具体的年，实现中会减去1900)
	* return : 转换后的毫秒数
	* param :  年月日时分秒
	 */
	static DWORD64 TimeToPoint(int year, int month, int day, int hour, int minutes, int seconds);

	/*
	 * 把传入的时间点（从1970年到现在的毫秒数）转换成年月日时分秒
	* return :
	* param :  传入的时间点， 返回的年月日时分秒的引用
	 */
	static void PointToTime(DWORD64 point, int &year, int &month, int &day, int &hour, int &minutes, int &seconds);

	/*
	 *��ȡ�ͻ���IP
	 *return : 0 �ɹ�   -1 ʧ��
	 *param :sock ����socket         strIp ���ؿͻ���IP
	 */
  //TODO�����
	static int GetClientIp(int sock, std::string &strIp);

	/*
	 * ��̱�Ϊ�ػ����
	 * return :
	 * param :
	 */
	static void InitDaemon();
	
	/*
	 * ��ȡip��ַ
	 * return : 0 �ɹ�   -1 ʧ��
	 * param : nSocket ����socket   strIpName�����ip
	 */
	static int GetIpName(int nSocket, char strIpName[IPSTR_LEN]);

	/*
	 * 获取设备ip
	 * return ：返回ip
	 * param　：socket    设备名
	 */
	static std::string GetIpByName(int socket, std::string &name);

	/*
	 * 获取设备ip
	 * return ：返回ip
	 * param　： 设备名
	 */
	static std::string GetIpByName(std::string &name);

	/*
	 * 获取cpu数目
	 * return ：返回数目
	 * param　：
	 */
	static int GetCPUCount();

	/*
	 * 获取utf8字符的长度
	 * return ：返回字节长度
	 * param　：
	 */
	static int GetUTF8Count(const char * str);

	/*
	 * 让线程睡眠毫秒时间,用来替换usleep
	 * return ：
	 * param　：毫秒数
	 */
	static void MSleep(int time);

private:

	/*
	 *fork�ӽ�̣��˳������
	 *return :
	 *param :
	 */
	static void DaemonFork();
};

}
