#ifndef CD_H_INCLUDED
#define CD_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define TRUE        1
#define FALSE       0
#define SUCCESS     1       //�ļ��洢�ɹ���־
#define FAIL        0       //�ļ��洢ʧ�ܱ�־
#define BORROWED    1       //�ѽ��ı�־
#define MOREBORR    2       //�ǻ�Ա���Ķ౾
#define CANBORROW   0       //�ɽ��ı�־
#define ERROE       -1      //�޴�Ƭ��־
#define MIN(a,b)	((a<b)?(a):(b))
#define MAX(a,b)	((a>b)?(a):(b))

struct _dvdInfo      //dvdInfo -> DVD information
{
    char dvdname[20];   //Ӱ������
    char country[10];   //����
    char type[10];      //Ӱ������
    int borrowSign;     //���ı�־
};
struct _leaseInfo    //leaseInfo -> lease information
{
    char vipName[10];   //��Ա��
    char dvdname[20];   //Ӱ������
    int leaseTime[4];   //����ʱ�䣬�ĸ�λ�÷ֱ��Ӧ������ʱ
    int backTime[4];    //�黹ʱ��
    int rent;           //���
};
typedef struct _dvd
{
    struct _dvdInfo dvdInfo;
    struct _leaseInfo leaseInfo;
    struct _dvd *next;
}Dvd;

#endif //_CD_H_INCLUDED
