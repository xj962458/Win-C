#include<stdio.h>
#include<stdlib.h>
//�������n��Ԫ�ص���ֵ����������ͷ���ĵ������Ա�L��ͷ�巨��
typedef struct Node
{
    int data;
    struct Node *next;
}Node;
typedef struct Node *LinkList;  //����LinkList
void CreateListHead(LinkList *L,int n)
{
    LinkList p;
    int i;
    srand(time(0));     //��ʼ�����������
    *L=(LinkList)malloc(sizeof(Node));
    (*L)->next=NULL;            //�Ƚ���һ����ͷ�ڵ�ĵ�����
    for(i=0;i<n;i++)
    {
        p=(LinkList)malloc(sizeof(Node));
        p->data=rand()%100+1;   //�������100���ڵ�����
        p->next=(*L)->next;
        (*L)->next=p;       //���뵽����ͷ
    }
}
//�������n��Ԫ�ص���ֵ����������ͷ���ĵ������Ա�L��β�巨��
void CreateListTail(LinkList *L,int n)
{
    LinkList p,r;
    int i;
    srand(time(0));     //��ʼ���������
    *L=(LinkList)malloc(sizeof(Node));  //Ϊ�������Ա�
    r=*L;       //rΪuָ��β���Ľ��
    for(i=0;i<n;i++)
    {
        p=(Node *)malloc(sizeof(Node));   //�����½ڵ�
        p->data=rand()%100+1;       //�������100���ڵ�����
        r->next=p;      //����β�ն˽���ָ��ָ���½��
        r=p;             //����ǰ���½ڵ㶨��Ϊ��β�ն˽��

    }
}