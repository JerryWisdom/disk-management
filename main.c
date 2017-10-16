
#include "cd.h"
#include "file_operate.h"
#include "data_operate.h"
#include "info_show.h"

Dvd *menuSelect(Dvd *head,char **vipList);
                                //������˵�ѡ����
void Quit(Dvd *head);           //�뿪����

int main()
{
    Dvd *head = NULL;
    char vipList[20][20] = {""};

    printf("\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("\t\t\t* * * * * * * * * * Ӱ �� �� Ϣ �� �� ϵ ͳ * * * * * * * * * *\n");
    printf("\t\t\t* * * * * * * * * * * * * �� �� �� �� �� * * * * * * * * * * * * \n");
    printf("\t\t\t* * * * * * * �� Ա �� �� �� �� �� �� � �� �� �� �� * * * * * * \n");
    printf("\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");

    while(1)
    {
        head = menuSelect(head,vipList);
    }

    return 0;
}





Dvd *menuSelect(Dvd *head,char **vipList)
{
    int choice;              //ѡ�����
    Dvd *pnew;               //������Ӱ���ڵ���Ϣ

    printf("\n\t\t\t\t\t------------Ӱ����Ϣ����ϵͳ------------\n\n");
    printf("\t\t\t\t[ 1 ] \t\t     Ӱ �� �� Ϣ ¼ ��\n\n");
    printf("\t\t\t\t[ 2 ] \t\t     �� Ա �� Ϣ ¼ ��\n\n");
    printf("\t\t\t\t[ 3 ] \t\t     �� �� �� Ա �� ��\n\n");
    printf("\t\t\t\t[ 4 ] \t\t �� Ʒ �� �� �� �� �� �� Ƭ\n\n");
    printf("\t\t\t\t[ 5 ] \t\t       �� ѯ �� Ƭ\n\n");
    printf("\t\t\t\t[ 6 ] \t\t       Ӱ �� �� ��\n\n");
    printf("\t\t\t\t[ 7 ] \t\t       Ӱ �� �� ��\n\n");
    printf("\t\t\t\t[ 8 ] \t\t  � �� �� �� Ӱ �� �� Ϣ\n\n");
    printf(
           "\t\t\t\t[ 9 ] \t\t  Ӱ �� �� Ϣ ¼ �� �� ��\n\n");
    printf("\t\t\t\t[ 10 ] \t\t       �� �� ϵ ͳ\n\n");
    printf("\t\t\t\t��������Ӧ�������:");
    scanf("%d",&choice);
    system("cls");
    switch(choice)
    {
        case 1:
            //��ʼ��¼��ӰƬ
            head = createLine(head);
            break;
        case 2:
            //��ʼ����Ա�б�
            vipNameLeading(vipList);
            break;
        case 3:
            //����»�Ա
            vipNameAdd(vipList);
            break;
        case 4:
            //׷��ӰƬ��Ϣ
            head = addRecord(head);
            break;
        case 5:
            //��ѯӰƬ��Ϣ
            searchDvdInfo(head);
            break;
        case 6:
            //����ӰƬ
            head = dvdBorrow(head,vipList);
            break;
        case 7:
            //�黹ӰƬ
            head = dvdReturn(head);
            break;
        case 8:
            //�������ӰƬ��Ϣ
            display(head);
            break;
        case 9:
            //����Ϣ�����ļ�
            if(saveRecord(head) == SUCCESS)
            {
                printf("\n\t\t\t\t�ļ�����ɹ���\n\n");
            }
            else
            {
                printf("\n\t\t\t\t�Բ����ļ�����ʧ��!\n\n");
            }
            break;
        case 10:
            //�뿪ϵͳ
            Quit(head);
            break;
        default:
            printf("\n\t\t\t\t�Բ���������Ĳ���������!\n\n");
    }
    return head;
}

void Quit(Dvd *head){
    freeLine(head);
    printf("\n\t\t\t\t�� �� ϵ ͳ ......");
    exit(0);
}
