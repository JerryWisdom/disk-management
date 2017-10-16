#include "cd.h"
#include "info_show.h"
#include "init_io_free.h"

int checkBorrowSign(Dvd *head,char *dvdName)
{
    //碟片查询：按影碟片名查询碟片是否可借阅，结果有3种（可借阅、已借出、无此片）

    Dvd *p = head;
    while(p)
    {
        if(strcmp(dvdName,p->dvdInfo.dvdname) == 0)
        {
            break;
        }
        p = p->next;
    }
    if(p == NULL)
    {
        return ERROE;
    }
    else
    {
        if(p->dvdInfo.borrowSign == CANBORROW)
        {
            return CANBORROW;
        }
        else
        {
            return BORROWED;
        }
    }
}

int findVipName(char name[],char vipList[][20])
{
    //查看用户是否为vip

    int i;
    int flag = FALSE;   //判断用户是否为vip标志
    for(i=0;strcmp(vipList[i],"") != 0;i++)
    {
        if(strcmp(name,vipList[i]) == 0)
        {
            flag = TRUE;
            break;
        }
    }
    return flag;
}

int borrowNum(Dvd *head,char *name)
{
    //查询用户借阅书本数

    Dvd *p;
    int num = 0;    //借阅数
    for(p = head;p != NULL;p = p->next)
    {
        if(strcmp(p->leaseInfo.vipName,name) == 0)
        {
            num++;
        }
    }
    return num;
}
int couldBorrow(Dvd *head,char *name,char *dvdName,char vipList[][20])
{
    //判断用户是否可借阅影片
    //1.非会员借张影碟2.影碟已被借走3.无此影碟
    int temp = checkBorrowSign(head,dvdName);
    if(temp == ERROE)  //无影片
    {
        return ERROE;
    }
    else if(temp == CANBORROW)  //未被借阅
    {
        if(findVipName(name,vipList) == TRUE)
        {
            return CANBORROW;
        }
        else    //判断该非会员是否已经借阅多本
        {
            if(borrowNum(head,name) > 0)
            {
                return MOREBORR;
            }
            else
            {
                return CANBORROW;
            }
        }
    }
    else    //已经被借阅
    {
        return BORROWED;
    }
}

int isLeap(int year)
{
    //判断是否为闰年

    if((year % 4 ==0 || year % 400 ==0) && (year % 100 !=0))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int dayInYear(int *data)
{
    //判断日期为这一年中的第几天

    int i,iRet = 0;
    int DAY[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    if(isLeap(data[0]))
    {
        DAY[1] = 29;
    }
    for(i=0; i < data[1] - 1; ++i)
    {
        iRet += DAY[i];
    }
    return iRet + data[2];
}

int calcuMoney(int *lease,int *revert)
{
    //将链表内租借和归还的两个数组传入，计算出租金
    int hours,i,days=0;
    if(lease[0] == revert[0])
    {
        //年份相同
        days = dayInYear(revert) - dayInYear(lease);
    }
    else
    {
        for(i=lease[0];i<revert[0];i++)
        {
            if(isLeap(i))
            {
                days += 366;
            }
            else
            {
                days += 365;
            }
        }
        days = days + dayInYear(revert) - dayInYear(lease);
    }
    hours = days * 24 + revert[3] - lease[3];
    if(hours < 0)
    {
        return ERROE;
    }
    if(hours % 72 == 0)
    {
        return hours / 72;
    }
    else
    {
        return (hours / 72) +1;
    }
}

Dvd *addRecord(Dvd *head)
{
    //新片上架：添加碟片信息

    Dvd *p,*pnew;
	int i,n;
	if(head == NULL)
    {
        printf("\n\t\t\t\t对不起，必须先录入有碟片信息后才可添加新碟片\n");
        return head;
    }
	printf("\n\t\t\t\t将要附加影片信息......请输入您将要附加的影碟张数:");
    scanf("%d",&n);
	if(n == 0)
    {
		return head;
	}
	for(p = head;p&&p->next;p=p->next);      //尾指针初始化
	pnew = (Dvd*)malloc(sizeof(Dvd));
	printf("\n\t\t\t\t请依次按影片名称、国家、碟片类型的顺序依次输入%d张碟片的信息:\n",n);
	printf("\n\t\t\t\t第1张碟片信息:");
    pnew = getLine(pnew);
    p->next = pnew;
    p = p->next;
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

Dvd *dvdDelete(Dvd *head)
{
    //下架影片

}

Dvd *dvdBorrow(Dvd *head,char vipList[][20])
{
    //碟片借阅：输入会员名、碟片名称、借阅日期，修改碟片的租借标记（每个会员一次可借阅多片）。

    char name[10],dvdName[20];
    Dvd *p = head;
    int temp;       //存储借阅信息

    printf("\n\t\t\t\t请输入您的姓名:");
    scanf("%s",name);
    printf("\n\t\t\t\t请输入您将要借阅的影片名称:");
    scanf("%s",dvdName);
    temp = couldBorrow(head,name,dvdName,vipList);
    if(temp == ERROE)
    {
        printf("\n\t\t\t\t对不起，暂时无此影片，无法借阅!\n");
    }
    else if(temp == BORROWED)
    {
        printf("\n\t\t\t\t对不起，该影碟已经被借出,无法借阅!\n");
    }
    else if(temp == MOREBORR)
    {
        printf("\n\t\t\t\t对不起，非会员无法借阅多张光碟!\n");
    }
    else        //可借阅
    {
        while(p)
        {
            if(strcmp(dvdName,p->dvdInfo.dvdname) == 0)
            {
                break;
            }
            p = p->next;
        }
        strcpy(p->leaseInfo.vipName,name);
        p->dvdInfo.borrowSign = BORROWED;
        printf("\n\t\t\t\t您有借阅资格，请输入借阅时间(格式：年-月-日 时):");
        scanf("%d-%d-%d %d",&(p->leaseInfo.leaseTime[0]),&(p->leaseInfo.leaseTime[1]),
                            &(p->leaseInfo.leaseTime[2]),&(p->leaseInfo.leaseTime[3]));
        printf("\n\t\t\t\t借阅成功,记得及时归还!\n");
    }
    return head;
}

Dvd *findDvd(Dvd *head,char dvdName[20])
{
    //找到名为dvdname的节点
    Dvd *p = head;
    while(p)
    {
        if(strcmp(p->dvdInfo.dvdname,dvdName) == 0)
        {
            break;
        }
        p = p->next;
    }
    return p;
}

Dvd *dvdReturn(Dvd *head)
{
    //碟片归还：输入会员名、碟片名称、归还日期，修改碟片的租借标记，计算每片租金

    char name[10];
    char dvdName[20];
    Dvd *p;     //储存归还影片的节点
    printf("\n\t\t\t\t归还影碟......\n");
    printf("\n\t\t\t\t请输入您的姓名:");
    scanf("%s",name);
    printf("\n\t\t\t\t请输入您将归还的影碟名称:");
    scanf("%s",dvdName);
    p = findDvd(head,dvdName);
    if(p == NULL)
    {
        printf("\n\t\t\t\t对不起，我们都没有这张片，你怎么还?\n");
    }
    else
    {
        printf("\n\t\t\t\t请按(年-月-日 时)的格式输入归还时间:");
        scanf("%d-%d-%d %d",&(p->leaseInfo.backTime[0]),&(p->leaseInfo.backTime[1]),
                            &(p->leaseInfo.backTime[2]),&(p->leaseInfo.backTime[3]));
        p->leaseInfo.rent = calcuMoney(p->leaseInfo.leaseTime,p->leaseInfo.backTime);
        if(p->leaseInfo.rent < 0)
        {
            printf("\n\t\t\t\t对不起，输入时间有误\n");
            p->leaseInfo.rent = 0;
            return head;
        }
        printf("\n\t\t\t\t已成功归还碟片，请支付 %d 元租赁费用\n",p->leaseInfo.rent);
        //数据清除
        p->dvdInfo.borrowSign = CANBORROW;
        p->leaseInfo.vipName[0] = '\0';
    }
    return head;
}

void searchDvdInfo(Dvd *head)
{
    //按碟片名查询碟片信息

    char dvdName[20];
    Dvd *tempP;
    printf("\n\t\t\t\t查询功能...请输入您要查询的影片名称:");
    scanf("%s",dvdName);
    for(tempP = head;tempP&&strcmp(dvdName,tempP->dvdInfo.dvdname);tempP = tempP->next);
    if(tempP == NULL)
    {
        printf("\n\t\t\t\t抱歉，暂无此片信息\n");
    }
    else
    {
        printf("\n\t\t\t\t已查询到影片相关信息...影片信息如下:\n");
        printf("\n\t\t\t\t影片名称  发行国家  影片类型  是否可借阅   借阅时间\n");
        printLine(tempP);
        printf("\n");
    }
}

void vipNameLeading(char vipList[][20])
{
    //会员名导入

    int i,n;
    printf("\n\t\t\t\t将要初始化会员信息......请输入您将要输入几位会员名称:");
    scanf("%d",&n);
    getchar();
    printf("\n\t\t\t\t请依次输入%d个会员的名称:\n",n);
    for(i=1;i<=n;i++)
    {
        printf("\n\t\t\t\t请输入第%d个会员的名称:",i);
        scanf("%s",(vipList+i-1));
    }
    printf("\n\t\t\t\t保存成功......\n");
}

void vipNameAdd(char vipList[][20])
{
    //添加会员名称

    int i,j,n;
    printf("\n\t\t\t\t将增加会员数量，请输入将添加几位会员:");
    scanf("%d",&n);
    getchar();
    printf("\n\t\t\t\t请依次输入%d个会员的名称:\n",n);
    for(i = 0;vipList[i][0];i++);        //尾下标初始化
    for(j = 1;j <= n;i++,j++)
    {
        printf("\t\t\t\t请输入第%d个会员的名称:",j);
        scanf("%s",(vipList+i-1));
    }
    printf("\n\t\t\t\t保存成功......\n");
}






