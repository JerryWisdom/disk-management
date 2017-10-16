#include "cd.h"

int saveRecord(Dvd *head)
{
     //���ļ��洢��ָ���ļ�·��

    FILE *fp;
    char filePath[15];       //�����ļ��洢·��
    if(head == NULL)
    {
        printf("\n\t\t\t\t�Բ�������Ϣ��¼��\n");
        return ERROE;
    }
    printf("\n\t\t\t\t�������ļ���������·��:");
    scanf("%s",filePath);
    if(!(fp=fopen(filePath,"w")))
    {
        return FAIL;
    }
    Dvd *p = head;
    fprintf(fp,"Ƭ��\t���й���\tӰƬ����\t�Ƿ�ɽ���\t������ \t����ʱ��\n");
    while(p)
    {
        fprintf(fp,"%5s\t%5s\t%5s",p->dvdInfo.dvdname,p->dvdInfo.country,p->dvdInfo.type);
        if(p->dvdInfo.borrowSign == CANBORROW)
        {
            fprintf(fp," �ɽ���  ");
            fprintf(fp," ---  --��--��--��--ʱ\n");
        }
        else
        {
            fprintf(fp," �ѽ��� ");
            fprintf(fp,"%5s\t%d��%d��%d��%dʱ\n",p->leaseInfo.vipName,
                    p->leaseInfo.leaseTime[0],p->leaseInfo.leaseTime[1],
                    p->leaseInfo.leaseTime[2],p->leaseInfo.leaseTime[3]);
        }
        p=p->next;
    }
    fclose(fp);
    return SUCCESS;
}



