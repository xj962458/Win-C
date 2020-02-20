#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//����һ������������Ϣ�Ľṹ��
struct student
{
    char name[40];  //����
    char no[18];    //���֤��
    int xb;     //�Ա�Ů����Ϊ0��������Ϊ1
    int age;    //����
    char tele[20];  //�绰����
    struct student *next;
};

//��������г�ʼ������,����ͷ���
struct student *InitList(struct student *L)
{
    struct student *head;
    head=(struct  student *)malloc(sizeof(struct student));
    head->next=NULL;
    L=head;
    return L;
}

//�������нڵ�ĸ�������������
int ListLength(struct student *L)
{
    struct student *p=NULL;
    int count=0;
    p=L;
    while(p->next)
    {
        count++;
        p=p->next;
    }
    return count;
}

//���������������ɵĽڵ���뵽����ı�ͷ
struct student *CreateList(struct student *L,int n)
{
    int i;
    struct student *p;
    for(i=n;i>0;i--)
    {
        //�������ɵĽڵ���뵽������
        p=(struct  student *)malloc(sizeof(struct student));
        scanf("%s,%s,%d,%d,%s",&(p->name),&(p->no),&(p->xb),&(p->age),&(p->tele));
        p->next=L->next;
        L->next=p;
    }
    return L;
}

//��������нڵ�Ĳ������
struct student *ListInsert(struct student *L,int i,struct student stud)
{
    int j=0;
    struct student *s,*p;
    p=L;
    while(p&&j<i-1)
    {
        p=p->next;
        j++;
    }
    if(!p||j>i-1)
    {
        printf("�����λ�ò��Ϸ���\n");
        return L;
    }
    //����һ���½ڵ�s
    s=(struct student *)malloc(sizeof(struct student));
    strcpy(s->name,stud.name);
    strcpy(s->no,stud.no);
    s->xb=stud.xb;
    s->age=stud.age;
    strcpy(s->tele,stud.tele);
    //�ڵ�ĺ�����
    s->next=p->next;
    p->next=s;
    return L;
}

void ChaInfo(struct student *L,char name[])
{
    int m,s;
    char c[30];
    struct student *p;
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
            strcpy(p->tele,c);
    }

}



//���������нڵ��ɾ������
struct student *ListDelete(struct student *L,int i)
{
    int j;
    struct student *q,*p;
    p=L;
    j=0;
    //��ѯָ��λ���ϵĽڵ�
    while(p->next&&j<i-1)
    {
        p=p->next;
        j++;
    }
    if(!(p->next)||j>i-1)
    {
        printf("�����λ�ò��Ϸ���");
        return L;
    }
    //ɾ��ָ���ڵ�
    q=p->next;
    p->next=q->next;
    free(q);
    return L;
}

//�������ϵ�G�����в�ѯ����
int GetElem(struct student *L,int i)
{
    int j,e;
    struct student *p;
    if(i<1||i>ListLength(L))
    {
        printf("�����λ�ò��Ϸ���");
        return 0;
    }
    p=L->next;
    j=1;
    while(j<i)
    {
        p=p->next;
        j++;
    }
    printf("��%d�������������ϢΪ����:",i);
    printf("����\t\t���֤��\t�Ա�\t����\t�绰����\n");
    printf("%s\t%s\t%d\t%d\t%s\n",p->name,p->no,p->xb,p->age,p->tele);
}

void  print(struct  student  *L) 
{ 
    struct  student *p; 
    printf("\nȫ����������������:\n"); 
    p=L->next;
    printf("����\t\t���֤��\t�Ա�\t����\t�绰����\n"); 
    while(p!=NULL)
    {
        printf("%s\t%s\t%d\t%d\t%s\n",p->name,p->no,p->xb,p->age,p->tele);
       p=p->next;
    }
}


//����Ĳ���
void menu()
{
    printf("*****************Ŀ¼****************\n");
    printf("1�����ȫ�������������Ϣ              \n");
    printf("2������ĳ����������Ϣ                  \n");
    printf("3����ѯ�����ĳ�������������Ϣ         \n");
    printf("4���޸�ĳ�������������Ϣ              \n");
    printf("5��ɾ��ĳ�������������Ϣ              \n");
    printf("6���޸�ĳ����������Ϣ                   \n");
    printf("0���˳�                               \n");
    printf("**************************************\n");
}

//������
void main()
{
    int n,m,i,e;
    char name[20];
    struct student stud;
    struct student *L=NULL,*p=NULL;
    L=InitList(L);
    printf("�����뿼������");
    scanf("%d",&n);
    printf("��������%d�����������������֤�š��Ա���1��Ů0)�����䡢�绰���루�ÿո������:\n",n);
    L=CreateList(L,n);
    do
    {
        printf("\n\n");
        menu();
        printf("�������ѡ��");
        scanf("%d",&m);
        switch(m)
        {
            case 1:
                print(L);
                printf("\n");
                break;
            case 2:
                printf("������Ҫ����λ��:\n");
                scanf("%d",&i);
                printf("\n���������Ŀ��������������֤�š��Ա���1��Ů0)�����䡢�绰���루�ö��Ÿ���)\n");
                scanf("%s,%s,%d,%d,%s",&stud.name,&stud.no,&stud.xb,&stud.age,&stud.tele);
                L=ListInsert(L,i,stud);
                break;
            case 3:
                printf("������Ҫ��ѯ������λ�ã�");
                scanf("%d",&i);
                GetElem(L,i);
                break;
            case 4:
                printf("��������Ҫ�޸ĵĿ����������޸ĵĿ�����Ϣ����\n");
                printf("����������");
                break;
            case 5:
                printf("������Ҫɾ���Ŀ�����λ��:");
                scanf("%s",&i);
                L=ListDelete(L,i);
                break;
            case 6:
                printf("��������Ҫ�޸ĵ�ѧ��������");
                scanf("%s",name);
                ChaInfo(L,name);
                printf("\n�޸ĳɹ���");
                break;
            case 0:
                printf("�˳�\n");
                exit(0);
                break;
            default:
                printf("�������\n");
        }
    }while(m!=0);
}
