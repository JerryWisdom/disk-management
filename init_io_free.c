#include "cd.h"

Dvd *getLine(Dvd *p)
{
    //��p��д������

    scanf("%s%s%s",p->dvdInfo.dvdname,p->dvdInfo.country,p->dvdInfo.type);
    p->dvdInfo.borrowSign = CANBORROW;
    strcpy(p->leaseInfo.dvdname,p->dvdInfo.dvdname);
    *(p->leaseInfo.vipName) = "\0";
 	return p;
}

Dvd *createLine(Dvd *head)
{
    //����һ��n�ڵ����ݵ�����

    Dvd *p,*pnew;
	int i,n;
	if(head)
    {
        printf("\n\t\t\t\t�Բ��������Ѵ������ݣ��޷��ٴγ�ʼ��\n");
        return head;
    }
    printf("\n\t\t\t\t��Ҫ��ʼ������......����������Ҫ������Ӱ������:");
    scanf("%d",&n);
    getchar();
	head = (Dvd*)malloc(sizeof(Dvd));
	if(n == 0)
    {
		head = NULL;
		return head;
	}
	printf("\n\t\t\t\t�����ΰ�ӰƬ���ơ����ҡ���Ƭ���͵�˳����������%d�ŵ�Ƭ����Ϣ:\n",n);
	printf("\n\t\t\t\t��1�ŵ�Ƭ��Ϣ:");
	head = getLine(head);
	p = head;
	for(i = 1;i < n;i++)
    {
        printf("\n\t\t\t\t��%d�ŵ�Ƭ��Ϣ:",i+1);
		pnew = (Dvd*)malloc(sizeof(Dvd));
		pnew = getLine(pnew);
		p->next = pnew;
		p = p->next;
	}
	p->next = NULL;
	afterOperate(head);
	return head;
}

void printLine(Dvd *p)
{
    //���p�ڵ�������ĵ�Ƭ����

    if(p==NULL)
    {
        printf("\n\t\t\t\t�ýڵ���ӰƬ��Ϣ\n");
    }
	else
    {
		printf("\n\t\t\t\t%7s %7s  %7s ",p->dvdInfo.dvdname,p->dvdInfo.country,p->dvdInfo.type);
		if(p->dvdInfo.borrowSign == CANBORROW)
        {
            printf("   �ɽ���   ");
            printf(" ---  -��-��-��-ʱ\n");
        }
        else
        {
            printf("�ѽ��� ");
            printf("%s %d��%d��%d��%dʱ\n",p->leaseInfo.vipName,p->leaseInfo.leaseTime[0],
                    p->leaseInfo.leaseTime[1],p->leaseInfo.leaseTime[2],p->leaseInfo.leaseTime[3]);
        }
	}
}

void freeLine(Dvd *head)
{
    //�ͷ�head�����ڵ������ڴ�

	Dvd *p;         //��¼�ͷŽڵ���Ϣ
	while(head)
    {
        p = head;
        head = head->next;
        free(p);
    }
}

void display(Dvd *head)
{
    //��ʾ���������������Ϣ

	if(head == NULL)
    {
        printf("\n\t\t\t\t�Բ�����ʱû���κ�ӰƬ��Ϣ\n");
    }
    else
    {
        Dvd *p = head;
        printf("\n\t\t\t\t\t---------����ӰƬ��Ϣ����--------\n");
        printf("\n\t\t\t\t  Ƭ��  ���й���  ӰƬ����  �Ƿ�ɽ���  ������  ����ʱ��\n");
        while(p)
        {
            printLine(p);
            p = p->next;
        }
    }

}

void afterOperate(Dvd *head)
{
    //ÿ�β�������ʾ��Ϣ
    char seeInfo;            //������£������Ƿ�鿴���º���Ϣ
    printf("\n\t\t\t\tӰ����Ϣ����ɹ����Ƿ�鿴��ʱ��������[Y/N]:");
    getchar();
    scanf("%c",&seeInfo);
    if(seeInfo == 'Y' || seeInfo == 'y')
    {
        display(head);
    }
    printf("\n");
}


