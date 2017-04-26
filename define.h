/*
 * define.h
 *
 *  Created on: 2013��9��2��
 *      Author: helh
 */

#ifndef DEFINE_H_
#define DEFINE_H_


#include <arpa/inet.h>
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <stdarg.h>
#include <stdlib.h>
#include <sys/epoll.h>
#include <sys/resource.h>
#include <sys/stat.h>
#include <signal.h>
#include <string.h>
#include <stdio.h>
#include <sys/time.h>

#include <iostream>
#include <map>
#include <queue>
#include <vector>

namespace CommBaseOut
{

//�������
typedef unsigned char BYTE;
typedef unsigned short WORD;
typedef unsigned int DWORD;
typedef unsigned long long DWORD64;

typedef long long int64;

//IP�ַ��ȶ���
const int IPSTR_LEN = 16;
const int HOST_NAME_LEN = 64; //�����
const int FILENAME_LEN = 128; //�ļ����

//һ������
const int SECONDS_OF_DAY = 86400;
//һ������
const int SECONDS_OF_WEEK = 604800;
//һ����30������
const DWORD SECONDS_OF_MONTH = 2592000;

//һ����Ϣ����󳤶�
enum SendBufType
{
	eClientBuf,
	eServerBuf,
	eBufMax
};
const int MAX_NET_MSG_SIZE[eBufMax] = {1024 * 512, 1024 * 1024};

//���ܵ���Ϣ���
const int MAX_RECV_MSG_SIZE = 1024 * 64;
const int MAX_RECV_MSG_CONTENT_SIZE = 1024;
const int MAX_MSG_PACKET_SIZE = 1024 * 64;

//�������Ŀ
const int MAX_LISTEN_SIZE = 1000;

//epoll�򿪵�����fd��Ŀ
const int MAX_EPOLL_fd = 10000;

//epollע����¼������Ŀ
const int MAX_EPOLL_EVENT = 10000;

//1�볬ʱ //-1;	//epoll_wait��ʱʱ�䣬Ϊ-1��ʾ���ᳬʱ
const int EPOLL_TIMEOUT = 1000;

 //�ǻʱ��..��λ����
const int KEEP_IDLE = 180;
//̽����ʱ��
const int KEEP_INTERVAL = 5;
//̽�����
const int KEEP_COUNT = 3;

//��ʱ���۸���
const int SLOT_COUNT = 3000;
//��ʱ��ʱ��Ƭ (����)
const int SLOT_CHANGE_TIME = 100;

//mysql数据库的执行语句长度
const int MYSQL_EXECUTE_BUF = 32 * 1024;

}


#endif /* DEFINE_H_ */
