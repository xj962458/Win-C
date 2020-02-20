#include <stdio.h>
#include <stdlib.h>

//构造链表节点的数据类型
struct Node
{
    int data;
    struct Node *next;
};

//对链表进行初始化操作
struct Node *InitList(struct Node *L)
{
    struct Node *head = NULL;

    head = (struct Node *)malloc(sizeof(struct Node));
    if (!head)
        return 0;
    head->next = NULL;
    L = head;
    return L;
}

//求链表中节点的个数，即链表长度
int ListLength(struct Node *L)
{
    struct Node *p = NULL;
    int count = 0;
    p = L;
    while (p->next)
    {
        count++;
        p = p->next;
    }
    return count;
}

//创建链表，将新生成的节点插入到链表的表头
struct Node *CreateList(struct Node *L, int n)
{
    int i;
    struct Node *p = NULL;
    for (i = n; i > 0; i--)
    {
        //将新生成的节点插入到链表中
        p = (struct Node *)malloc(sizeof(struct Node));
        scanf("%d", &p->data);
        p->next = L->next;
        L->next = p;
    }
    return L;
}

//对链表进行节点的插入操作
struct Node *ListInsert(struct Node *L, int i, int e)
{
    int j = 0;
    struct Node *s = NULL, *p = NULL;
    p = L;
    while (p && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (!p || j > i - 1)
    {
        printf("输入的位置不合法！\n");
        return L;
    }
    //生成一个新节点s
    s = (struct Node *)malloc(sizeof(struct Node));
    s->data = e;
    //节点的后插操作
    s->next = p->next;
    p->next = s;
    return L;
}

//对链表及逆行节点的删除操作
struct Node *ListDelete(struct Node *L, int i)
{
    int j;
    struct Node *q = NULL, *p = NULL;
    p = L;
    j = 0;
    //查询只当位置上的节点
    while (p->next && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (!(p->next) || j > i - 1)
    {
        printf("输入的位置不合法！");
        return L;
    }
    //删除指定节点
    q = p->next;
    p->next = q->next;
    free(q);
    return L;
}

//对链表的系欸但进行查询操作
int GetElem(struct Node *L, int i)
{
    int j, e;
    struct Node *p = NULL;
    if (i < 1 || i > ListLength(L))
    {
        printf("输入的位置不合法！");
        return 0;
    }
    p = L->next;
    j = 1;
    while (j < i)
    {
        p = p->next;
        j++;
    }
    e = p->data;
    printf("第%d个元素的数据为%d\n", i, e);
}

//链表的操作
void menu()
{
    printf("*****************目录***************\n");
    printf("1、输出这支单链表                     \n");
    printf("2、在单链表中插入一个新节点            \n");
    printf("3、在单链表中删除指定节点              \n");
    printf("4、查询单链表中的节点                  \n");
    printf("0、退出                               \n");
    printf("**************************************\n");
}

//主程序
int main()
{
    int n, m, i, e;
    struct Node *L = NULL, *p = NULL;
    L = InitList(L);
    printf("请输入元素数：");
    scanf("%d", &n);
    printf("依次输入%d个元素的数据（用空格隔开）:", n);
    L = CreateList(L, n);
    do
    {
        printf("\n\n");
        menu();
        printf("输入你的选择：");
        scanf("%d", &m);
        switch (m)
        {
        case 1:
            printf("这支单链表为:");
            p = L->next;
            while (p != NULL)
            {
                printf("%d->", p->data);
                p = p->next;
            }
            printf("\b\b\b\b");
            printf("\n");
            break;
        case 2:
            printf("依次输入插入位置和数据元素(空格隔开)：");
            scanf("%d %d", &i, &e);
            L = ListInsert(L, i, e);
            break;
        case 3:
            printf("输入你要删除的元素位置:");
            scanf("%d", &i);
            L = ListDelete(L, i);
            break;
        case 4:
            printf("输入需要查询元素的位置：");
            scanf("%d", &i);
            GetElem(L, i);
            break;
        case 0:
            printf("退出\n");
            exit(0);
            break;
        default:
            printf("输入错误！\n");
        }
    } while (m != 0);
}
