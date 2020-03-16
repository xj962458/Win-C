#include<stdio.h>
#include<stdlib.h>
//随机产生n个元素的数值，建立带标头结点的单链线性表L（头插法）
typedef struct Node
{
    int data;
    struct Node *next;
}Node;
typedef struct Node *LinkList;  //定义LinkList
void CreateListHead(LinkList *L,int n)
{
    LinkList p;
    int i;
    srand(time(0));     //初始化随机数种子
    *L=(LinkList)malloc(sizeof(Node));
    (*L)->next=NULL;            //先建立一个带头节点的单链表
    for(i=0;i<n;i++)
    {
        p=(LinkList)malloc(sizeof(Node));
        p->data=rand()%100+1;   //随机生成100以内的数字
        p->next=(*L)->next;
        (*L)->next=p;       //插入到链表头
    }
}
//随机产生n个元素的数值，建立带标头结点的单链线性表L（尾插法）
void CreateListTail(LinkList *L,int n)
{
    LinkList p,r;
    int i;
    srand(time(0));     //初始化随机种子
    *L=(LinkList)malloc(sizeof(Node));  //为整个线性表
    r=*L;       //r为u指向尾部的结点
    for(i=0;i<n;i++)
    {
        p=(Node *)malloc(sizeof(Node));   //生成新节点
        p->data=rand()%100+1;       //随机生成100以内的数字
        r->next=p;      //将表尾终端结点的指针指向新结点
        r=p;             //将当前的新节点定义为表尾终端结点

    }
}
