//创建动态链表
/*动态创建一个链表：动态内存申请+模块化设计
1、创建链表（创建一个表头表示整个链表
2、创建结点
3、插入结点
4、删除结点
5、打印遍历链表（测试）
*/
#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;   //数据域
    struct Node* next;  //指针域
};
struct Node* createList()   //创建一个链表头
{
    struct Node* headNode=(struct Node*)malloc(sizeof(struct Node));
    //通过动态内存申请使结构体指针headNode成为结构体变量
    //变量使用前必须初始化
    headNode->next=NULL;
    return headNode;
}
struct Node* createNode(int data)   //创建一个链表结点
{
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}
//打印链表
void printList(struct Node* headNode)
{
    struct Node* pMove=headNode->next;
    while(pMove)
    {
        printf("%d\t",pMove->data);
        pMove=pMove->next;
    }
    printf("\n");
}
//插入结点，参数：插入那个链表，插入结点的数据是多少
void insertNodeByHead(struct Node* headNode,int data)
{
    //创建新的结点
    struct  Node* newNode=createNode(data);
    newNode->next=headNode->next;
    headNode->next=newNode;
}
//指定位置删除链表
void deleteNodeByAppoin(struct Node* headNode,int posData)
{
    struct Node* posNode=headNode->next;
    struct Node* posNodeFront=headNode;
    if(posNode==NULL)`  
        printf("无法删除，链表为空\n");
    else
    {
        while(posNode->data!=posData)
        {
            posNodeFront=posNode;
            posNode=posNodeFront->next;
            if(posNode==NULL)
            {
                printf("没有找到相关信息，无法删除\n");
                return;
            }
        }
        posNodeFront->next=posNode->next;
        free(posNode);



    }
}
int main()
{
    struct Node* list=createList();
    insertNodeByHead(list,1);
    insertNodeByHead(list,2);
    insertNodeByHead(list,3);
    printList(list);
    deleteNodeByAppoin(list,2);
    printList(list);
    system("pause");
    return 0;
}
