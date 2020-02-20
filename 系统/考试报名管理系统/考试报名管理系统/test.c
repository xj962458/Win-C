#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//定义一个包含指针的考生结构体
struct node
{
	char name[40];
	char no[18];
	int xb;
	int age;
	char tel[20];
    struct node *next;
};

//考生链表的初始化，创建一个考生链表头
struct node *Init(struct node *L)
{
    struct node *head=(struct node *)malloc(sizeof(struct node));
    head->next==NULL;
    L=head;
    return L;
}

//创建考生链表节点，存储考生信息
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

//打印全部考生的信息
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
            strcpy(p->tel,c);
    }

}

void menu()
{
    printf("*****************目录*****************\n");
    printf("1、录入考生信息                        \n");
    printf("2、输出全部考生的相关信息               \n");
    printf("3、插入某个考生的信息                   \n");
    printf("4、查询并输出某个考生的相关信息         \n");
    printf("5、修改某个考生的相关信息               \n");
    printf("6、删除某个考生的相关信息               \n");
    printf("0、退出                                \n");
    printf("**************************************\n");
}

void main()
{
    int item,n;
    char name[40];
    struct node *L=Init(L);
    while(1)
    {
        printf("这里是考生信息管理系统，请输入相应的数字，选择相应的操作:\n\n\n");
        menu();
        scanf("%d",&item);
        switch(item)
        {
            case 1:
                printf("请输入考生数:");
                scanf("%d",&n);
                system("cls");
                printf("依次输入%d名考生的姓名、身份证号、性别（男1，女0)、年龄、电话号码（用逗号隔开）:\n",n);
                L=CreatNode(L,n);
                break;
            case 2:
                printf("\n姓名\t身份证号\t性别\t年龄\t电话号码\n");
                PrintInfo(L);
                break;
            case 3:
                printf("依次输入插入的考生的姓名、身份证号、性别（男1，女0)、年龄、电话号码（用逗号隔开）:\n");
                CreatNode(L,1);
                break;
            case 4:
                printf("请输入您要查询的考生的姓名:");
                scanf("%s",name);
                GetElem(L,name);
                break;
            case 5:
                printf("请输入您要修改的学生的姓名");
                scanf("%s",name);
                ChaInfo(L,name);
                printf("\n修改成功！");
                break;
            case 6:
                printf("请输入您要删除的考生的姓名:");
                scanf("%s",name);
                DeleInfo(L,name);
                printf("\n删除成功！");
                break;
            case 0:
                printf("退出！");
                exit(0);
                break;
            default :
                printf("输入错误！\n");
        }
    }


}