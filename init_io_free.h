#ifndef INIT_IO_FREE_H_INCLUDED
#define INIT_IO_FREE_H_INCLUDED
#include "cd.h"

/*-------链表初始化、节点读写、打印内容以及释放空间等杂碎工作-------*/

Dvd *createLine(Dvd *head);		//创建一个n节点内容的链表
Dvd *getLine(Dvd *p); 		    //向p中写入内容
void printLine(Dvd *p);			//输出p节点所代表的碟片内容
void freeLine(Dvd *head);       //释放head链表内的所有内存
void display(Dvd *head);	    //显示整个链表的完整信息
void afterOperate(Dvd *head);   //每次操作完提示信息

#endif // INIT_IO_FREE_H_INCLUDED
