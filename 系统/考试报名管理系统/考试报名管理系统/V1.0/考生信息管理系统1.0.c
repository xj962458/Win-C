#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//����һ�������ṹ��
typedef struct student
{
    char name[40];
    char no[18];
    int xb;
    int age;
    char tele[20];
    struct student *next;
}STU;

//����������������
STU *LIstInit(STU *L);
STU *ListCreate(STU *L, int n);
void ListInsert(STU *L);
void ListDelete(STU *L,char n[40]);
void LIstSearch(STU *L,char n[]);
void input(STU *p,int i);
void output(STU *L);
void menu();

//������ͷ����ʼ������
STU *LIstInit(STU *L)
{
    STU *head=NULL;
    head=(STU *)malloc(sizeof(STU));
    head->next=NULL;
    L = head;
    return L;
}

//���������������ɵĽڵ���뵽����ı�ͷ
STU *ListCreate(STU *L, int n)
{
    int i; 
    for (i = 0; i<n; i++)
    {
        STU *p;
        //�������ɵĽڵ���뵽������
        p=NULL;
        p = (STU *)malloc(sizeof(STU));
        input(p,i);
        p->next = L->next;
        L->next = p;
    }
    return L;
}

//��������нڵ�Ĳ������
void ListInsert(STU *L)
{
    STU *s = NULL;
    //����һ���½ڵ�s
    s = (STU *)malloc(sizeof(STU));
    printf("��������Ҫ����Ŀ���������:");
    scanf("%s",&s->name);
    printf("��������Ҫ����Ŀ��������֤��:");
    scanf("%s",&s->no);
    printf("��������Ҫ����Ŀ������Ա�Ů��Ϊ0������Ϊ1��:");
    scanf("%d",&s->xb);
    printf("��������Ҫ����Ŀ���������:");
    scanf("%d",&s->age);
    printf("��������Ҫ����Ŀ����ĵ绰����:");
    scanf("%s",&s->tele);
    s->next = L->next;
    L->next = s;
}

//������Ľ��нڵ��ɾ������
void ListDelete(STU *L,char n[])
{
    int i;
    STU *p=L->next,*pre=L;  //����pָ��ָ��ͷ�ڵ��ָ�򣬶���preָ��ͷ�ڵ㣬preʼ��ָ��p��ǰ���ڵ�
    while(p!=NULL)      //��δ�������β����һֱ������ȥ
    {                       
        if(strcmp(p->name,n)==0)      //���ڵ��������Ҫɾ���Ľڵ�һ������ɾ���ýڵ㣬�����ű���
        {
            pre->next=p->next;
            free(p);
            printf("ɾ���ɹ���");
            p=pre->next;
        }
        else               //���ڵ������������Ҫɾ���Ľڵ����������p����pre���ű�����ֱ������β
        {
            pre=p;
            p=p->next;
        }
    }
}

void LIstSearch(STU *L,char n[])
{
    STU *p=L->next;
    while(p!=NULL)
    {
        if(strcmp(p->name,n)==0)
        {
            printf("�ÿ�������Ϣ����:\n");
            printf("%s\t",p->name);
            printf("\t%s",p->no);
            printf("\t%d",p->xb);
            printf("\t%d",p->age);
            printf("\t%s",p->tele);
            printf("\n");
            p=p->next;
        }
        else
            p=p->next;
    }
}

void ListModify(STU *L,char na[])
{
    int x,a,item;
    char nam[40],no[18],tel[20];
    STU *p=L->next;
    while(p!=NULL)
    {
        if(strcmp(p->name,na)==0)
        {
            printf("��ѡ����Ҫ�޸ĵĿ�����Ϣ����:\n");
            printf("1������\n2�����֤��\n3���Ա�\n4������\n5���绰����\n");
            scanf("%d",&item);
            switch(item)
            {
                case 1:
                    printf("���������޸ĺ������:");
                    scanf("%s",nam);
                    strcpy(p->name,nam);
                    break;
                case 2:
                    printf("���������޸ĺ�����֤��:");
                    scanf("%s",no);
                    strcpy(p->no,no);
                    break;
                case 3:
                    printf("���������޸ĺ���Ա�:");
                    scanf("%d",&x);
                    p->xb=x;
                    break;
                case 4:
                    printf("���������޸ĺ������:");
                    scanf("%d",&a);
                    p->age=a;
                    break;
                case 5:
                    printf("���������޸ĺ�ĵ绰����:");
                    scanf("%s",tel);
                    strcpy(p->tele,tel);
                    break;
            }
        }
        p=p->next;
    }
}

void input(STU *p,int i)
{
    printf("�������%d������������:",i+1);
    scanf("%s",&p->name);
    printf("�������%d�����������֤��:",i+1);
    scanf("%s",&p->no);
    printf("�������%d���������Ա�Ů��Ϊ0������Ϊ1��:",i+1);
    scanf("%d",&p->xb);
    printf("�������%d������������:",i+1);
    scanf("%d",&p->age);
    printf("�������%d�������ĵ绰����:",i+1);
    scanf("%s",&p->tele);
}

void output(STU *L)
{
    STU *p=L->next;
    while(p!=NULL)
    {
        printf("%s\t",p->name);
        printf("\t%s",p->no);
        printf("\t%d",p->xb);
        printf("\t%d",p->age);
        printf("\t%s",p->tele);
        printf("\n");
        p=p->next;
    }
}

void menu()
{
    printf("\n\n\n\n");
	printf("\t\t\t===================ѧ���ɼ�����ϵͳ==================\n");
	printf("\t\t\t* ����:���¼�  �༶:�˹�����191  ѧ��:3190707121    *\n");
	printf("\t\t\t*                                                   *\n");
	printf("\t\t\t*          1>. ¼�뿼����Ϣ                         *\n");
	printf("\t\t\t*          2>. ȫ��������Ϣ                         *\n");
	printf("\t\t\t*          3>. �鿴������Ϣ                         *\n");
	printf("\t\t\t*          4>. �޸Ŀ�����Ϣ                         *\n");
	printf("\t\t\t*          5>. ɾ��������Ϣ                         *\n");
	printf("\t\t\t*          6>. ���뿼����Ϣ                         *\n");
	printf("\t\t\t*          7>. ��ȡѧ����Ϣ                         *\n");
	printf("\t\t\t*          8>. ����ѧ����Ϣ                         *\n");
	printf("\t\t\t*          0>. �˳�����ϵͳ                         *\n");
	printf("\t\t\t*                                    ��ӭʹ�ñ�ϵͳ!*\n");
	printf("\t\t\t=====================================================\n");
	printf("\t\t\t����ѡ����س�����ѡ��:                             \n");
}

int main()
{
    int item,n,m;         //item���ڽ�����������n���ڽ�������Ŀ�������
    char nam[30];         
    STU *L=NULL;
    L=LIstInit(L);
    do
    { 
        menu();
        printf("��������Ӧ�����֣�������Ӧ�Ĳ���:\n");
        scanf("%d",&item);
        switch(item)
        {
            case 1:
                printf("��������Ҫ¼��Ŀ�����Ŀ:");
                scanf("%d",&n);
                L=ListCreate(L,n);
                break;
            case 2:
                printf("ȫ��������Ϣ����:\n");
                printf("����\t\t���֤��\t\t�Ա�\t����\t�绰����\n");
                output(L);
                break;
            case 3:
                printf("��������Ҫ���ҵĿ�������:");
                scanf("%s",nam);
                LIstSearch(L,nam);
                break;                                             
            case 4:
                printf("��������Ҫ�޸ĵ�ѧ������:");
                scanf("%s",nam);
                ListModify(L,nam);
                break;
            case 5:
                printf("��������Ҫɾ����ѧ��������:");
                scanf("%s",nam);
                ListDelete(L,nam);
                break;
            case 6:
                ListInsert(L);
                break;
            case 0:
                printf("�����˳�������Ϣ����ϵͳ.....");
                exit(0);
        }
    }while(item);
    return 0;
}