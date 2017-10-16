#ifndef DATA_OPERATE_H_INCLUDED
#define DATA_OPERATE_H_INCLUDED
#include "cd.h"

/*-------��Ƭ�顢�衢�黹����-------*/


int checkBorrowSign(Dvd *head,char *dvdName);
            //��Ƭ��ѯ����Ӱ��Ƭ����ѯ��Ƭ�Ƿ�ɽ��ģ������3�֣��ɽ��ġ��ѽ�����޴�Ƭ��
int findVipName(char *name,char vipList[][20]);
            //�鿴�û��Ƿ�Ϊvip
int borrowNum(Dvd *head,char *name);
            //��ѯ�û������鱾��
int couldBorrow(Dvd *head,char *name,char *dvdName,char vipList[][20]);
            //�ж��û��Ƿ�ɽ����鱾
int calcuMoney(int *lease,int *revert);
            //�����������͹黹���������鴫�룬��������
Dvd *addRecord(Dvd *head);
            //��Ƭ�ϼܣ���ӵ�Ƭ��Ϣ
Dvd *dvdDelete(Dvd *head);
            //�¼�ӰƬ
Dvd *dvdBorrow(Dvd *head,char vipList[][20]);
            //��Ƭ���ģ������Ա������Ƭ���ơ��������ڣ��޸ĵ�Ƭ������ǣ�ÿ����Աһ�οɽ��Ķ�Ƭ����
Dvd *dvdReturn(Dvd *head);
            //��Ƭ�黹�������Ա������Ƭ���ơ��黹���ڣ��޸ĵ�Ƭ������ǣ�����ÿƬ���
void searchDvdInfo(Dvd *head);
            //����Ƭ����ѯ��Ƭ��Ϣ
void vipNameLeading(char vipList[][20]);
            //��Ա���Ƶ���
void vipNameAdd(char vipList[][20]);
            //��ӻ�Ա����


#endif // DATA_OPERATE_H_INCLUDED
