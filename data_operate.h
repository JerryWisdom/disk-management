#ifndef DATA_OPERATE_H_INCLUDED
#define DATA_OPERATE_H_INCLUDED
#include "cd.h"

/*-------碟片查、借、归还操作-------*/


int checkBorrowSign(Dvd *head,char *dvdName);
            //碟片查询：按影碟片名查询碟片是否可借阅，结果有3种（可借阅、已借出、无此片）
int findVipName(char *name,char vipList[][20]);
            //查看用户是否为vip
int borrowNum(Dvd *head,char *name);
            //查询用户借阅书本数
int couldBorrow(Dvd *head,char *name,char *dvdName,char vipList[][20]);
            //判断用户是否可借阅书本
int calcuMoney(int *lease,int *revert);
            //将链表内租借和归还的两个数组传入，计算出租金
Dvd *addRecord(Dvd *head);
            //新片上架：添加碟片信息
Dvd *dvdDelete(Dvd *head);
            //下架影片
Dvd *dvdBorrow(Dvd *head,char vipList[][20]);
            //碟片借阅：输入会员名、碟片名称、借阅日期，修改碟片的租借标记（每个会员一次可借阅多片）。
Dvd *dvdReturn(Dvd *head);
            //碟片归还：输入会员名、碟片名称、归还日期，修改碟片的租借标记，计算每片租金
void searchDvdInfo(Dvd *head);
            //按碟片名查询碟片信息
void vipNameLeading(char vipList[][20]);
            //会员名称导入
void vipNameAdd(char vipList[][20]);
            //添加会员名称


#endif // DATA_OPERATE_H_INCLUDED
