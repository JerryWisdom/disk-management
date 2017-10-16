#include "cd.h"

int saveRecord(Dvd *head)
{
     //将文件存储入指定文件路径

    FILE *fp;
    char filePath[15];       //保存文件存储路径
    if(head == NULL)
    {
        printf("\n\t\t\t\t对不起，无信息可录入\n");
        return ERROE;
    }
    printf("\n\t\t\t\t请输入文件完整保存路径:");
    scanf("%s",filePath);
    if(!(fp=fopen(filePath,"w")))
    {
        return FAIL;
    }
    Dvd *p = head;
    fprintf(fp,"片名\t发行国家\t影片类型\t是否可借阅\t借阅人 \t借阅时间\n");
    while(p)
    {
        fprintf(fp,"%5s\t%5s\t%5s",p->dvdInfo.dvdname,p->dvdInfo.country,p->dvdInfo.type);
        if(p->dvdInfo.borrowSign == CANBORROW)
        {
            fprintf(fp," 可借阅  ");
            fprintf(fp," ---  --年--月--日--时\n");
        }
        else
        {
            fprintf(fp," 已借阅 ");
            fprintf(fp,"%5s\t%d年%d月%d日%d时\n",p->leaseInfo.vipName,
                    p->leaseInfo.leaseTime[0],p->leaseInfo.leaseTime[1],
                    p->leaseInfo.leaseTime[2],p->leaseInfo.leaseTime[3]);
        }
        p=p->next;
    }
    fclose(fp);
    return SUCCESS;
}



