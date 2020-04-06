#include<stdio.h>
struct node
{
    char no[12];        //商品编号
    char name[40];      //名称
    int workload;       //库存量
    struct node *next;  //指向下一节点的指针
};