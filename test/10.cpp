#include <stdio.h>
#include <stdlib.h>
#define MAX 20

typedef struct CNode //孩子结点
{
    int pos;            //孩子位置
    struct CNode *next; //孩子指针
} CNode, *PChild;

typedef struct //根结点
{
    char data;    //根结点数据域
    PChild child; //孩子链表
} CTRoot;

typedef struct //顺序表结构
{
    CTRoot Node[MAX];
    int sum; //根结点数
} SqCTree, *CTree;

void InitCTree(CTree &CT) //初始化树
{

    CT = (SqCTree *)malloc(sizeof(SqCTree));
    CT->sum = 0;
    for (int i = 0; i < MAX; i++) //初始化数组的每个孩子结点
    {
        CT->Node[i].child = (CNode *)malloc(sizeof(CNode));
        CT->Node[i].child->next = NULL;
    }
    printf("初始化!\n");
}

void CreateCTree(CTree &CT) //创建树
{
    printf("请输入结点数:");
    scanf("%d", &CT->sum);
    fflush(stdin);

    int n;
    char ch;

    for (int i = 0; i < CT->sum; i++)
    {
        printf("请输入第%d个结点数据及孩子数和孩子位置:", i);

        scanf("%c", &ch);
        CT->Node[i].data = ch;

        scanf("%d", &n);

        PChild p = CT->Node[i].child;
        for (int j = 0; j < n; j++) //插入孩子结点
        {
            PChild s;
            s = (CNode *)malloc(sizeof(CNode));
            scanf("%d", &s->pos);
            s->next = NULL;
            p->next = s;
            p = p->next;
        }
        fflush(stdin);
    }
}

void LevelOrderTraverse(CTree CT) //层序遍历
{
    for (int i = 0; i < CT->sum; i++)
        printf("%c ", CT->Node[i].data);
    printf("\n");
}

int main()
{
    CTree CT;
    InitCTree(CT);

    CreateCTree(CT);

    printf("\n层序遍历:");
    LevelOrderTraverse(CT);
    return 0;
}
