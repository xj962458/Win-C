#include<stdio.h>          /*�Ľ���*/
#include<stdlib.h>
int  n;
struct   student 
{
    long  num;  
    float  score;   
    struct  student  *next; 
}; 

struct student *creat();        //����һ������ͷ
void  print(struct  student  *head);        //��ӡ����
struct  student  *del(struct student *head,long num);       //ָ��λ��ɾ�����
struct  student  *insert(struct student *head, struct student *stud);       //������