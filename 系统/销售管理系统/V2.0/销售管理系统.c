#include<stdio.h>
struct node
{
    char no[12];            //代号
    char name[40];          //姓名
    int month[12];          //月份
    float sales[12];        //月销售额
    float total;            //年度总销售额
    struct node *next;      //指向下一节点的指针
};