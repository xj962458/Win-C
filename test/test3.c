#include <stdio.h>
#include <stdlib.h>
struct node
{ //链表结点
    int data;
    struct node *next;
};
//创建链表
struct node *create(int Array[])
{
    int i;
    struct node *p, *pre, *head;                       //pre保存当前接待你得前驱节点，head为头结点
    head = (struct node *)malloc(sizeof(struct node)); //创建头结点
    head->next = NULL;                                 //头结点不需要数据域，指针域初始值为NULL
    pre = head;                                        //记录pre为head
    for (i = 0; i <= 5; i++)
    {
        p = (struct node *)malloc(sizeof(struct node)); //新建结点
        //将Array[i]赋给新建的结点作为数据域，也可以用scanf输入
        p->data = Array[i];
        p->next = NULL; //新结点的指针设为NULL
        pre->next = p;  //前驱结点的指针域设为当前新建节点的地址
        pre = p;        //把pre设为p,作为下个结点得前驱结点
    }
    return head; //返回头结点指针
};

//查找元素
int search(struct node *head, int x)
{
    int count = 0;               //计数器
    struct node *p = head->next; //从第一个结点开始
    while (p != NULL)            //只要没有到链表表尾
    {
        if (p->data == x)
            count++; //当前节点数据与为x，count++
        p = p->next; //指针移动到下一节点
    }
    return count; //返回计数器count
}

//插入结点
//将a拆入以head为头结点得链表第pos个位置上
void insert(struct node *head, int pos, int a)
{
    struct node *p = head;
    for (int i = 0; i < pos - 1; i++)
        p = p->next;                                             //Pos-1是为了到插入位置得前一个结点
    struct node *q = (struct node *)malloc(sizeof(struct node)); //新建结点
    q->data = a;                                                 //新建结点得数据域为a
    q->next = p->next;                                           //新节点得下一个结点执行那个原先插入位置的结点
    p->next = q;                                                 //前一个位置的结点指向新节点
}

//删除结点
//删除以head为头结点的链表中所有数据为b的结点
void del(struct node *head, int b)
{
    //p和pre都是指向结点的指针类型，他们是指针而不是结点
    struct node *p = head->next; //p从第一个结点开始枚举
    struct node *pre = head;     //pre始终保存p的前驱接待你的指针
    while (p != NULL)
    {
        if (p->data == b) //数据域恰好为b，说明要删除此结点
        {
            pre->next = p->next;
            free(p);
            p = pre->next;
        }
        else
        {
            //数据域不是b，把pre和p都后移一位
            pre = p;
            p = p->next;
        }
    }
}

int main()
{
    int Array[5] = {5, 3, 6, 1, 2}, num;
    struct node *L = create(Array); //新建链表。返回头指针head
    L = L->next;                    //从第一个结点开始有数据域
    while (L != NULL)
    {
        printf("%d ", L->data); //输出每个节点得数据域
        L = L->next;
    }
    printf("请输入您要搜索的数据\n");
    scanf("%d", &num);
    printf("您需要查找的数据%d共有%d个\n", num, search(L, num));
    return 0;
}
