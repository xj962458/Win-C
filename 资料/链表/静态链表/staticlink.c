//创建静态链表
#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;   //数据域
    struct Node* next;  //指针域
};
int main()
{
    struct Node Node1={1,NULL};
    struct Node Node2={2,NULL};
    struct Node Node3={3,NULL};
    Node1.next=&Node2;
    Node2.next=&Node3;
    system("pause");
    return 0;
}
