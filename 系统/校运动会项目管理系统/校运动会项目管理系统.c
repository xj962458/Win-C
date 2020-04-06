#include<stdio.h>
struct node
{
    char xiangmu[40];               //比赛项目名称
    char name[10][40];              //学院名称
    float score[10];                //单项成绩
    int no[10];                     //单项名次
    struct node *next;              //指向下一节点的指针
}