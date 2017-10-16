#ifndef FILE_OPERATE_H_INCLUDED
#define FILE_OPERATE_H_INCLUDED
#include "cd.h"

/*-------有关文件的操作函数-------*/

int saveRecord(Dvd *head);
                                    //将文件存储入指定文件路径
//Dvd *loadRecord(Dvd *head,char *filePath);
                                    //文件读取并附加到链表尾部

#endif // FILE_OPERATE_H_INCLUDED
