#include<stdio.h>          /*改进后*/
#include<stdlib.h>
int  n;
struct   student 
{
    long  num;  
    float  score;   
    struct  student  *next; 
}; 

struct student *creat();        //创建一个链表头
void  print(struct  student  *head);        //打印链表
struct  student  *del(struct student *head,long num);       //指定位置删除结点
struct  student  *insert(struct student *head, struct student *stud);       //插入结点