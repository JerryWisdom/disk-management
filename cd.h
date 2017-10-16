#ifndef CD_H_INCLUDED
#define CD_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define TRUE        1
#define FALSE       0
#define SUCCESS     1       //文件存储成功标志
#define FAIL        0       //文件存储失败标志
#define BORROWED    1       //已借阅标志
#define MOREBORR    2       //非会员借阅多本
#define CANBORROW   0       //可借阅标志
#define ERROE       -1      //无此片标志
#define MIN(a,b)	((a<b)?(a):(b))
#define MAX(a,b)	((a>b)?(a):(b))

struct _dvdInfo      //dvdInfo -> DVD information
{
    char dvdname[20];   //影碟名称
    char country[10];   //国家
    char type[10];      //影碟类型
    int borrowSign;     //借阅标志
};
struct _leaseInfo    //leaseInfo -> lease information
{
    char vipName[10];   //会员名
    char dvdname[20];   //影碟名称
    int leaseTime[4];   //出租时间，四个位置分别对应年月日时
    int backTime[4];    //归还时间
    int rent;           //租金
};
typedef struct _dvd
{
    struct _dvdInfo dvdInfo;
    struct _leaseInfo leaseInfo;
    struct _dvd *next;
}Dvd;

#endif //_CD_H_INCLUDED
