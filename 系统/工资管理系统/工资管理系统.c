#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char no[12];       //职工工号
    char name[40];     //姓名
    int month[12];     //月份
    float gz[12];      //月工资
    float total;       //年度总工资
    struct node *next; //指向下一节点的指针
};

struct node *Init()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->next == NULL;
    return head;
}

struct node *CreatNode(struct node)
