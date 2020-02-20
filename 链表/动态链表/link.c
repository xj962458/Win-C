#include<stdio.h>
#include<stdlib.h>

//数据
struct  Data
{
    int x;      //两个数据
    int y;
};

//结点
struct Node
{
    struct Data data;  //数据
    struct Node *pnext; //指针
};

//链表
struct List
{
    struct Node* pfront;    //第一个节点的指针
    struct Node* prear;     //最后一个节点的指针
    struct Node  const;     //有多少个结点


};

int main()
{
    int age;
    int i,j,k;
    for(i=1;i<=9;i++)
    {
        for(j=i;j<=9;j++)
            printf("%d*%d=%d ",i,j,i*j);
        printf("\n");
    }
}
struct student
{
    char name[20];
    char num[20];
    float chinese;
    float math;
    float enlinsh;
};
printf("%d\n");
printf("%d\b=n 0 ");
printf("%f\")