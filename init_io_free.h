#ifndef INIT_IO_FREE_H_INCLUDED
#define INIT_IO_FREE_H_INCLUDED
#include "cd.h"

/*-------�����ʼ�����ڵ��д����ӡ�����Լ��ͷſռ�����鹤��-------*/

Dvd *createLine(Dvd *head);		//����һ��n�ڵ����ݵ�����
Dvd *getLine(Dvd *p); 		    //��p��д������
void printLine(Dvd *p);			//���p�ڵ�������ĵ�Ƭ����
void freeLine(Dvd *head);       //�ͷ�head�����ڵ������ڴ�
void display(Dvd *head);	    //��ʾ���������������Ϣ
void afterOperate(Dvd *head);   //ÿ�β�������ʾ��Ϣ

#endif // INIT_IO_FREE_H_INCLUDED
