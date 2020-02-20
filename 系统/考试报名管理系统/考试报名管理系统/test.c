#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//����һ������ָ��Ŀ����ṹ��
struct node
{
	char name[40];
	char no[18];
	int xb;
	int age;
	char tel[20];
    struct node *next;
};

//��������ĳ�ʼ��������һ����������ͷ
struct node *Init(struct node *L)
{
    struct node *head=(struct node *)malloc(sizeof(struct node));
    head->next==NULL;
    L=head;
    return L;
}

//������������ڵ㣬�洢������Ϣ
struct node *CreatNode(struct node *L,int n)
{
    int i;
    struct node *newNode=NULL;
    for(i=n;i>0;i--)
    {
        newNode=(struct node *)malloc(sizeof(struct node));
        scanf("%s,%s,%d,%d,%s",&newNode->name,&newNode->no,&newNode->xb,&newNode->age,&newNode->tel);
        newNode->next=L->next;
        L->next=newNode;
    }
    return L;
}

//��ӡȫ����������Ϣ
void PrintInfo(struct node *L)
{ 
    struct node *p=L->next;
    while(p!=NULL)
    {
        printf("%s\t%s\t%d\t%d\t%s\n",p->name,p->no,p->xb,p->age,p->tel);
        p=p->next;
    }
}

void DeleInfo(struct node *L,char name[])
{
    struct node *q;
    q=L->next;
    while(q!=NULL&&q->name!=name)
    {
        q=q->next;
    }
    free(q);
}

void GetElem(struct  node *L,char name[])
{
    
    struct node *p;
    p=L->next;
    while(p->name!=name)
    {
        p=p->next;
    }
    printf("%s\t%s\t%d\t%d\t%s\n",p->name,p->no,p->xb,p->age,p->tel);

}

void ChaInfo(struct node *L,char name[])
{
    int m,s;
    char c[30];
    struct node *p;
    p=L->next;
    while(p->name!=name)
    {
        p=p->next;
    }
    printf("\n��������Ҫ�޸ĵĿ�����Ϣ�����ࣺ");
    printf("1������\n2�����֤��\n3���Ա�\n4������\n5���绰����\n");
    scanf("%d",&m);
    switch(m)
    {
        case 1:
            printf("���������޸ĺ��������\n");
            scanf("%s",c);
            strcpy(p->name,c);
        case 2:
            printf("���������޸ĺ�����֤�ţ�\n");
            scanf("%s",c);
            strcpy(p->no,c);
        case 3:
            printf("���������޸ĺ���Ա�\n");
            scanf("%d",&s);
            p->xb=s;
        case 4:
            printf("���������޸ĺ�����䣺\n");
            scanf("%d",&s);
            p->age=s;
        case 0:
            printf("���������޸ĺ�ĵ绰���룺\n");
            scanf("%s",c);
            strcpy(p->tel,c);
    }

}

void menu()
{
    printf("*****************Ŀ¼*****************\n");
    printf("1��¼�뿼����Ϣ                        \n");
    printf("2�����ȫ�������������Ϣ               \n");
    printf("3������ĳ����������Ϣ                   \n");
    printf("4����ѯ�����ĳ�������������Ϣ         \n");
    printf("5���޸�ĳ�������������Ϣ               \n");
    printf("6��ɾ��ĳ�������������Ϣ               \n");
    printf("0���˳�                                \n");
    printf("**************************************\n");
}

void main()
{
    int item,n;
    char name[40];
    struct node *L=Init(L);
    while(1)
    {
        printf("�����ǿ�����Ϣ����ϵͳ����������Ӧ�����֣�ѡ����Ӧ�Ĳ���:\n\n\n");
        menu();
        scanf("%d",&item);
        switch(item)
        {
            case 1:
                printf("�����뿼����:");
                scanf("%d",&n);
                system("cls");
                printf("��������%d�����������������֤�š��Ա���1��Ů0)�����䡢�绰���루�ö��Ÿ�����:\n",n);
                L=CreatNode(L,n);
                break;
            case 2:
                printf("\n����\t���֤��\t�Ա�\t����\t�绰����\n");
                PrintInfo(L);
                break;
            case 3:
                printf("�����������Ŀ��������������֤�š��Ա���1��Ů0)�����䡢�绰���루�ö��Ÿ�����:\n");
                CreatNode(L,1);
                break;
            case 4:
                printf("��������Ҫ��ѯ�Ŀ���������:");
                scanf("%s",name);
                GetElem(L,name);
                break;
            case 5:
                printf("��������Ҫ�޸ĵ�ѧ��������");
                scanf("%s",name);
                ChaInfo(L,name);
                printf("\n�޸ĳɹ���");
                break;
            case 6:
                printf("��������Ҫɾ���Ŀ���������:");
                scanf("%s",name);
                DeleInfo(L,name);
                printf("\nɾ���ɹ���");
                break;
            case 0:
                printf("�˳���");
                exit(0);
                break;
            default :
                printf("�������\n");
        }
    }


}