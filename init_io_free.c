#include "cd.h"

Dvd *getLine(Dvd *p)
{
    //向p中写入内容

    scanf("%s%s%s",p->dvdInfo.dvdname,p->dvdInfo.country,p->dvdInfo.type);
    p->dvdInfo.borrowSign = CANBORROW;
    strcpy(p->leaseInfo.dvdname,p->dvdInfo.dvdname);
    *(p->leaseInfo.vipName) = "\0";
 	return p;
}

Dvd *createLine(Dvd *head)
{
    //创建一个n节点内容的链表

    Dvd *p,*pnew;
	int i,n;
	if(head)
    {
        printf("\n\t\t\t\t对不起，链表已存有内容，无法再次初始化\n");
        return head;
    }
    printf("\n\t\t\t\t将要初始化链表......请输入您将要创建的影碟张数:");
    scanf("%d",&n);
    getchar();
	head = (Dvd*)malloc(sizeof(Dvd));
	if(n == 0)
    {
		head = NULL;
		return head;
	}
	printf("\n\t\t\t\t请依次按影片名称、国家、碟片类型的顺序依次输入%d张碟片的信息:\n",n);
	printf("\n\t\t\t\t第1张碟片信息:");
	head = getLine(head);
	p = head;
	for(i = 1;i < n;i++)
    {
        printf("\n\t\t\t\t第%d张碟片信息:",i+1);
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
    //输出p节点所代表的碟片内容

    if(p==NULL)
    {
        printf("\n\t\t\t\t该节点无影片信息\n");
    }
	else
    {
		printf("\n\t\t\t\t%7s %7s  %7s ",p->dvdInfo.dvdname,p->dvdInfo.country,p->dvdInfo.type);
		if(p->dvdInfo.borrowSign == CANBORROW)
        {
            printf("   可借阅   ");
            printf(" ---  -年-月-日-时\n");
        }
        else
        {
            printf("已借阅 ");
            printf("%s %d年%d月%d日%d时\n",p->leaseInfo.vipName,p->leaseInfo.leaseTime[0],
                    p->leaseInfo.leaseTime[1],p->leaseInfo.leaseTime[2],p->leaseInfo.leaseTime[3]);
        }
	}
}

void freeLine(Dvd *head)
{
    //释放head链表内的所有内存

	Dvd *p;         //记录释放节点信息
	while(head)
    {
        p = head;
        head = head->next;
        free(p);
    }
}

void display(Dvd *head)
{
    //显示整个链表的完整信息

	if(head == NULL)
    {
        printf("\n\t\t\t\t对不起，暂时没有任何影片信息\n");
    }
    else
    {
        Dvd *p = head;
        printf("\n\t\t\t\t\t---------完整影片信息如下--------\n");
        printf("\n\t\t\t\t  片名  发行国家  影片类型  是否可借阅  借阅人  借阅时间\n");
        while(p)
        {
            printLine(p);
            p = p->next;
        }
    }

}

void afterOperate(Dvd *head)
{
    //每次操作完提示信息
    char seeInfo;            //链表更新，输入是否查看更新后信息
    printf("\n\t\t\t\t影碟信息保存成功，是否查看此时链表内容[Y/N]:");
    getchar();
    scanf("%c",&seeInfo);
    if(seeInfo == 'Y' || seeInfo == 'y')
    {
        display(head);
    }
    printf("\n");
}


