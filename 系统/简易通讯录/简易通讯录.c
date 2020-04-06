#include<stdio.h>
struct node
{
    char name[40];          //姓名
    char tele[20];          //电话
    char Email[40];         //电子邮箱
    char addr[80];          //通讯地址
    struct node *next;      //指向下一节点的指针
};