#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char no[12];       //ְ������
    char name[40];     //����
    int month[12];     //�·�
    float gz[12];      //�¹���
    float total;       //����ܹ���
    struct node *next; //ָ����һ�ڵ��ָ��
};

struct node *Init()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->next == NULL;
    return head;
}

struct node *CreatNode(struct node)
