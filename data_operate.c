#include "cd.h"
#include "info_show.h"
#include "init_io_free.h"

int checkBorrowSign(Dvd *head,char *dvdName)
{
    //��Ƭ��ѯ����Ӱ��Ƭ����ѯ��Ƭ�Ƿ�ɽ��ģ������3�֣��ɽ��ġ��ѽ�����޴�Ƭ��

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
    //�鿴�û��Ƿ�Ϊvip

    int i;
    int flag = FALSE;   //�ж��û��Ƿ�Ϊvip��־
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
    //��ѯ�û������鱾��

    Dvd *p;
    int num = 0;    //������
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
    //�ж��û��Ƿ�ɽ���ӰƬ
    //1.�ǻ�Ա����Ӱ��2.Ӱ���ѱ�����3.�޴�Ӱ��
    int temp = checkBorrowSign(head,dvdName);
    if(temp == ERROE)  //��ӰƬ
    {
        return ERROE;
    }
    else if(temp == CANBORROW)  //δ������
    {
        if(findVipName(name,vipList) == TRUE)
        {
            return CANBORROW;
        }
        else    //�жϸ÷ǻ�Ա�Ƿ��Ѿ����Ķ౾
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
    else    //�Ѿ�������
    {
        return BORROWED;
    }
}

int isLeap(int year)
{
    //�ж��Ƿ�Ϊ����

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
    //�ж�����Ϊ��һ���еĵڼ���

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
    //�����������͹黹���������鴫�룬��������
    int hours,i,days=0;
    if(lease[0] == revert[0])
    {
        //�����ͬ
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
    //��Ƭ�ϼܣ���ӵ�Ƭ��Ϣ

    Dvd *p,*pnew;
	int i,n;
	if(head == NULL)
    {
        printf("\n\t\t\t\t�Բ��𣬱�����¼���е�Ƭ��Ϣ��ſ�����µ�Ƭ\n");
        return head;
    }
	printf("\n\t\t\t\t��Ҫ����ӰƬ��Ϣ......����������Ҫ���ӵ�Ӱ������:");
    scanf("%d",&n);
	if(n == 0)
    {
		return head;
	}
	for(p = head;p&&p->next;p=p->next);      //βָ���ʼ��
	pnew = (Dvd*)malloc(sizeof(Dvd));
	printf("\n\t\t\t\t�����ΰ�ӰƬ���ơ����ҡ���Ƭ���͵�˳����������%d�ŵ�Ƭ����Ϣ:\n",n);
	printf("\n\t\t\t\t��1�ŵ�Ƭ��Ϣ:");
    pnew = getLine(pnew);
    p->next = pnew;
    p = p->next;
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

Dvd *dvdDelete(Dvd *head)
{
    //�¼�ӰƬ

}

Dvd *dvdBorrow(Dvd *head,char vipList[][20])
{
    //��Ƭ���ģ������Ա������Ƭ���ơ��������ڣ��޸ĵ�Ƭ������ǣ�ÿ����Աһ�οɽ��Ķ�Ƭ����

    char name[10],dvdName[20];
    Dvd *p = head;
    int temp;       //�洢������Ϣ

    printf("\n\t\t\t\t��������������:");
    scanf("%s",name);
    printf("\n\t\t\t\t����������Ҫ���ĵ�ӰƬ����:");
    scanf("%s",dvdName);
    temp = couldBorrow(head,name,dvdName,vipList);
    if(temp == ERROE)
    {
        printf("\n\t\t\t\t�Բ�����ʱ�޴�ӰƬ���޷�����!\n");
    }
    else if(temp == BORROWED)
    {
        printf("\n\t\t\t\t�Բ��𣬸�Ӱ���Ѿ������,�޷�����!\n");
    }
    else if(temp == MOREBORR)
    {
        printf("\n\t\t\t\t�Բ��𣬷ǻ�Ա�޷����Ķ��Ź��!\n");
    }
    else        //�ɽ���
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
        printf("\n\t\t\t\t���н����ʸ����������ʱ��(��ʽ����-��-�� ʱ):");
        scanf("%d-%d-%d %d",&(p->leaseInfo.leaseTime[0]),&(p->leaseInfo.leaseTime[1]),
                            &(p->leaseInfo.leaseTime[2]),&(p->leaseInfo.leaseTime[3]));
        printf("\n\t\t\t\t���ĳɹ�,�ǵü�ʱ�黹!\n");
    }
    return head;
}

Dvd *findDvd(Dvd *head,char dvdName[20])
{
    //�ҵ���Ϊdvdname�Ľڵ�
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
    //��Ƭ�黹�������Ա������Ƭ���ơ��黹���ڣ��޸ĵ�Ƭ������ǣ�����ÿƬ���

    char name[10];
    char dvdName[20];
    Dvd *p;     //����黹ӰƬ�Ľڵ�
    printf("\n\t\t\t\t�黹Ӱ��......\n");
    printf("\n\t\t\t\t��������������:");
    scanf("%s",name);
    printf("\n\t\t\t\t�����������黹��Ӱ������:");
    scanf("%s",dvdName);
    p = findDvd(head,dvdName);
    if(p == NULL)
    {
        printf("\n\t\t\t\t�Բ������Ƕ�û������Ƭ������ô��?\n");
    }
    else
    {
        printf("\n\t\t\t\t�밴(��-��-�� ʱ)�ĸ�ʽ����黹ʱ��:");
        scanf("%d-%d-%d %d",&(p->leaseInfo.backTime[0]),&(p->leaseInfo.backTime[1]),
                            &(p->leaseInfo.backTime[2]),&(p->leaseInfo.backTime[3]));
        p->leaseInfo.rent = calcuMoney(p->leaseInfo.leaseTime,p->leaseInfo.backTime);
        if(p->leaseInfo.rent < 0)
        {
            printf("\n\t\t\t\t�Բ�������ʱ������\n");
            p->leaseInfo.rent = 0;
            return head;
        }
        printf("\n\t\t\t\t�ѳɹ��黹��Ƭ����֧�� %d Ԫ���޷���\n",p->leaseInfo.rent);
        //�������
        p->dvdInfo.borrowSign = CANBORROW;
        p->leaseInfo.vipName[0] = '\0';
    }
    return head;
}

void searchDvdInfo(Dvd *head)
{
    //����Ƭ����ѯ��Ƭ��Ϣ

    char dvdName[20];
    Dvd *tempP;
    printf("\n\t\t\t\t��ѯ����...��������Ҫ��ѯ��ӰƬ����:");
    scanf("%s",dvdName);
    for(tempP = head;tempP&&strcmp(dvdName,tempP->dvdInfo.dvdname);tempP = tempP->next);
    if(tempP == NULL)
    {
        printf("\n\t\t\t\t��Ǹ�����޴�Ƭ��Ϣ\n");
    }
    else
    {
        printf("\n\t\t\t\t�Ѳ�ѯ��ӰƬ�����Ϣ...ӰƬ��Ϣ����:\n");
        printf("\n\t\t\t\tӰƬ����  ���й���  ӰƬ����  �Ƿ�ɽ���   ����ʱ��\n");
        printLine(tempP);
        printf("\n");
    }
}

void vipNameLeading(char vipList[][20])
{
    //��Ա������

    int i,n;
    printf("\n\t\t\t\t��Ҫ��ʼ����Ա��Ϣ......����������Ҫ���뼸λ��Ա����:");
    scanf("%d",&n);
    getchar();
    printf("\n\t\t\t\t����������%d����Ա������:\n",n);
    for(i=1;i<=n;i++)
    {
        printf("\n\t\t\t\t�������%d����Ա������:",i);
        scanf("%s",(vipList+i-1));
    }
    printf("\n\t\t\t\t����ɹ�......\n");
}

void vipNameAdd(char vipList[][20])
{
    //��ӻ�Ա����

    int i,j,n;
    printf("\n\t\t\t\t�����ӻ�Ա�����������뽫��Ӽ�λ��Ա:");
    scanf("%d",&n);
    getchar();
    printf("\n\t\t\t\t����������%d����Ա������:\n",n);
    for(i = 0;vipList[i][0];i++);        //β�±��ʼ��
    for(j = 1;j <= n;i++,j++)
    {
        printf("\t\t\t\t�������%d����Ա������:",j);
        scanf("%s",(vipList+i-1));
    }
    printf("\n\t\t\t\t����ɹ�......\n");
}






