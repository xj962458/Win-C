#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
struct student
{
    char name[20];
    int num;
    int math;
};
struct Node{
    struct student data;   //数据域
    struct Node* next;  //指针域
};
struct Node* createList()   //创建一个链表头
{
    struct Node* headNode=(struct Node*)malloc(sizeof(struct Node));
    //通过动态内存申请使结构体指针headNode成为结构体变量
    //变量使用前必须初始化
    //headNode->data.num=1;
    headNode->next=NULL;
    return headNode;
}
struct Node* createNode(struct student data)   //创建一个链表结点
{
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}
//打印链表
void printList(struct Node* headNode)
{
    struct Node* pMove=headNode->next;
    printf("name\tnum\tmath\n");
    while(pMove)
    {
        printf("%s\t%d\t%d\n",pMove->data.name,pMove->data.num,pMove->data.math);
        pMove=pMove->next;
    }
    printf("\n");
}
//插入结点，参数：插入那个链表，插入结点的数据是多少
void insertNodeByHead(struct Node* headNode,struct student data)
{
    //创建新的结点
    struct  Node* newNode=createNode(data);
    newNode->next=headNode->next;
    headNode->next=newNode;
}
//按照指定num删除链表
void deleteNodeByAppoinNum(struct Node* headNode,int num)
{
    struct Node* posNode=headNode->next;
    struct Node* posNodeFront=headNode;
    if(posNode==NULL)
        printf("无法删除，链表为空\n");
    else
    {
        while(posNode->data.num!=num)
        {
            posNodeFront=posNode;
            posNode=posNodeFront->next;
            if(posNode==NULL)
            {
                printf("没有找到相关信息，无法删除\n");
                return;
            }
        }
        posNodeFront->next=posNode->next;
        free(posNode);



    }
}
int main()
{
    struct Node* list=createList();
    struct  student info;
    while(1)
    {
        printf("请输入学生的姓名    学号    数学成绩：\n");
        scanf("%s %d %d",&info.name,&info.num,info.math);
        insertNodeByHead(list,info);
        printf("continue(Y/N)?\n"); 
        setbuf(stdin,NULL);
        int choice=getchar();
        if(choice=='N'||choice=='n')
            break;
    }
    printList(list);
    printf("请输入要删除的学生学号：");
    scanf("%d",&info.num);
    deleteNodeByAppoinNum(list,info.num);
    printList(list);
    system("pause");
    return 0;
}
