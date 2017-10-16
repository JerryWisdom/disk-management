
#include "cd.h"
#include "file_operate.h"
#include "data_operate.h"
#include "info_show.h"

Dvd *menuSelect(Dvd *head,char **vipList);
                                //主程序菜单选择函数
void Quit(Dvd *head);           //离开函数

int main()
{
    Dvd *head = NULL;
    char vipList[20][20] = {""};

    printf("\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("\t\t\t* * * * * * * * * * 影 碟 信 息 管 理 系 统 * * * * * * * * * *\n");
    printf("\t\t\t* * * * * * * * * * * * * 组 长 ： 杨 可 * * * * * * * * * * * * \n");
    printf("\t\t\t* * * * * * * 组 员 ： 饶 智 、 徐 建 淼 、 蓝 凯 豪 * * * * * * \n");
    printf("\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");

    while(1)
    {
        head = menuSelect(head,vipList);
    }

    return 0;
}





Dvd *menuSelect(Dvd *head,char **vipList)
{
    int choice;              //选择操作
    Dvd *pnew;               //保存新影碟节点信息

    printf("\n\t\t\t\t\t------------影碟信息管理系统------------\n\n");
    printf("\t\t\t\t[ 1 ] \t\t     影 碟 信 息 录 入\n\n");
    printf("\t\t\t\t[ 2 ] \t\t     会 员 信 息 录 入\n\n");
    printf("\t\t\t\t[ 3 ] \t\t     增 加 会 员 数 量\n\n");
    printf("\t\t\t\t[ 4 ] \t\t 新 品 上 架 ， 添 加 碟 片\n\n");
    printf("\t\t\t\t[ 5 ] \t\t       查 询 碟 片\n\n");
    printf("\t\t\t\t[ 6 ] \t\t       影 碟 借 阅\n\n");
    printf("\t\t\t\t[ 7 ] \t\t       影 碟 归 还\n\n");
    printf("\t\t\t\t[ 8 ] \t\t  浏 览 所 有 影 碟 信 息\n\n");
    printf(
           "\t\t\t\t[ 9 ] \t\t  影 碟 信 息 录 入 文 件\n\n");
    printf("\t\t\t\t[ 10 ] \t\t       离 开 系 统\n\n");
    printf("\t\t\t\t请输入相应操作序号:");
    scanf("%d",&choice);
    system("cls");
    switch(choice)
    {
        case 1:
            //初始化录入影片
            head = createLine(head);
            break;
        case 2:
            //初始化会员列表
            vipNameLeading(vipList);
            break;
        case 3:
            //添加新会员
            vipNameAdd(vipList);
            break;
        case 4:
            //追加影片信息
            head = addRecord(head);
            break;
        case 5:
            //查询影片信息
            searchDvdInfo(head);
            break;
        case 6:
            //借阅影片
            head = dvdBorrow(head,vipList);
            break;
        case 7:
            //归还影片
            head = dvdReturn(head);
            break;
        case 8:
            //浏览所有影片信息
            display(head);
            break;
        case 9:
            //将信息存入文件
            if(saveRecord(head) == SUCCESS)
            {
                printf("\n\t\t\t\t文件保存成功！\n\n");
            }
            else
            {
                printf("\n\t\t\t\t对不起，文件保存失败!\n\n");
            }
            break;
        case 10:
            //离开系统
            Quit(head);
            break;
        default:
            printf("\n\t\t\t\t对不起，您输入的操作数有误!\n\n");
    }
    return head;
}

void Quit(Dvd *head){
    freeLine(head);
    printf("\n\t\t\t\t关 闭 系 统 ......");
    exit(0);
}
