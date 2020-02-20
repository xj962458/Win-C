#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//建立一个包含考生信息的结构体
struct student
{
    char name[40];  //姓名
    char no[18];    //身份证号
    int xb;     //性别：女性设为0，男性设为1
    int age;    //年龄
    char tele[20];  //电话号码
    struct student *next;
};

//对链表进行初始化操作,建立头结点
struct student *InitList(struct student *L)
{
    struct student *head;
    head=(struct  student *)malloc(sizeof(struct student));
    head->next=NULL;
    L=head;
    return L;
}

//求链表中节点的个数，即链表长度
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

//创建链表，将新生成的节点插入到链表的表头
struct student *CreateList(struct student *L,int n)
{
    int i;
    struct student *p;
    for(i=n;i>0;i--)
    {
        //将新生成的节点插入到链表中
        p=(struct  student *)malloc(sizeof(struct student));
        scanf("%s,%s,%d,%d,%s",&(p->name),&(p->no),&(p->xb),&(p->age),&(p->tele));
        p->next=L->next;
        L->next=p;
    }
    return L;
}

//对链表进行节点的插入操作
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
        printf("输入的位置不合法！\n");
        return L;
    }
    //生成一个新节点s
    s=(struct student *)malloc(sizeof(struct student));
    strcpy(s->name,stud.name);
    strcpy(s->no,stud.no);
    s->xb=stud.xb;
    s->age=stud.age;
    strcpy(s->tele,stud.tele);
    //节点的后插操作
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
    printf("\n请输入您要修改的考生信息的种类：");
    printf("1、姓名\n2、身份证号\n3、性别\n4、年龄\n5、电话号码\n");
    scanf("%d",&m);
    switch(m)
    {
        case 1:
            printf("请输入您修改后的姓名：\n");
            scanf("%s",c);
            strcpy(p->name,c);
        case 2:
            printf("请输入您修改后的身份证号：\n");
            scanf("%s",c);
            strcpy(p->no,c);
        case 3:
            printf("请输入您修改后的性别：\n");
            scanf("%d",&s);
            p->xb=s;
        case 4:
            printf("请输入您修改后的年龄：\n");
            scanf("%d",&s);
            p->age=s;
        case 0:
            printf("请输入您修改后的电话号码：\n");
            scanf("%s",c);
            strcpy(p->tele,c);
    }

}



//对链表及逆行节点的删除操作
struct student *ListDelete(struct student *L,int i)
{
    int j;
    struct student *q,*p;
    p=L;
    j=0;
    //查询指定位置上的节点
    while(p->next&&j<i-1)
    {
        p=p->next;
        j++;
    }
    if(!(p->next)||j>i-1)
    {
        printf("输入的位置不合法！");
        return L;
    }
    //删除指定节点
    q=p->next;
    p->next=q->next;
    free(q);
    return L;
}

//对链表的系欸但进行查询操作
int GetElem(struct student *L,int i)
{
    int j,e;
    struct student *p;
    if(i<1||i>ListLength(L))
    {
        printf("输入的位置不合法！");
        return 0;
    }
    p=L->next;
    j=1;
    while(j<i)
    {
        p=p->next;
        j++;
    }
    printf("第%d个考生的相关信息为如下:",i);
    printf("姓名\t\t身份证号\t性别\t年龄\t电话号码\n");
    printf("%s\t%s\t%d\t%d\t%s\n",p->name,p->no,p->xb,p->age,p->tele);
}

void  print(struct  student  *L) 
{ 
    struct  student *p; 
    printf("\n全部考生的数据如下:\n"); 
    p=L->next;
    printf("姓名\t\t身份证号\t性别\t年龄\t电话号码\n"); 
    while(p!=NULL)
    {
        printf("%s\t%s\t%d\t%d\t%s\n",p->name,p->no,p->xb,p->age,p->tele);
       p=p->next;
    }
}


//链表的操作
void menu()
{
    printf("*****************目录****************\n");
    printf("1、输出全部考生的相关信息              \n");
    printf("2、插入某个考生的信息                  \n");
    printf("3、查询并输出某个考生的相关信息         \n");
    printf("4、修改某个考生的相关信息              \n");
    printf("5、删除某个考生的相关信息              \n");
    printf("6、修改某个考生的信息                   \n");
    printf("0、退出                               \n");
    printf("**************************************\n");
}

//主程序
void main()
{
    int n,m,i,e;
    char name[20];
    struct student stud;
    struct student *L=NULL,*p=NULL;
    L=InitList(L);
    printf("请输入考生数：");
    scanf("%d",&n);
    printf("依次输入%d名考生的姓名、身份证号、性别（男1，女0)、年龄、电话号码（用空格隔开）:\n",n);
    L=CreateList(L,n);
    do
    {
        printf("\n\n");
        menu();
        printf("输入你的选择：");
        scanf("%d",&m);
        switch(m)
        {
            case 1:
                print(L);
                printf("\n");
                break;
            case 2:
                printf("请输入要插入位置:\n");
                scanf("%d",&i);
                printf("\n请输入插入的考生的姓名、身份证号、性别（男1，女0)、年龄、电话号码（用逗号隔开)\n");
                scanf("%s,%s,%d,%d,%s",&stud.name,&stud.no,&stud.xb,&stud.age,&stud.tele);
                L=ListInsert(L,i,stud);
                break;
            case 3:
                printf("输入需要查询考生的位置：");
                scanf("%d",&i);
                GetElem(L,i);
                break;
            case 4:
                printf("请输入您要修改的考生姓名和修改的考生信息种类\n");
                printf("功能完善中");
                break;
            case 5:
                printf("输入你要删除的考生的位置:");
                scanf("%s",&i);
                L=ListDelete(L,i);
                break;
            case 6:
                printf("请输入您要修改的学生的姓名");
                scanf("%s",name);
                ChaInfo(L,name);
                printf("\n修改成功！");
                break;
            case 0:
                printf("退出\n");
                exit(0);
                break;
            default:
                printf("输入错误！\n");
        }
    }while(m!=0);
}
