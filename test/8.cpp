#include <stdio.h>
#include <stdlib.h>

typedef struct CSNode
{
    int data;
    struct CSNode *firstchild, *nextsibling;
} CSNode;
//层次遍历构建二叉树
void CreatTree(CSNode **T)
{
    int ch;
    scanf("%d", &ch);
    if (ch == -1)
    {
        *T = NULL;
        return;
    }
    else
    {
        (*T) = (CSNode *)malloc(sizeof(CSNode));
        (*T)->data = ch;
        printf("输入%d的左孩子", ch);
        CreatTree((&(*T)->firstchild));
        printf("输入%d的兄弟", ch);
        CreatTree(&(*T)->nextsibling);
    }
    return;
}
int depth(CSNode *T)
{
    CSNode *p;
    if (!T)
        return 0;
    if ((*T).firstchild == NULL)
        return 1;
    int dep, max = 0;
    p = (*T).firstchild;
    for (; p != NULL; p = p->nextsibling)
    {
        dep = depth(p);
        if (dep > max)
        {
            max = dep;
        }
    }
    return max + 1;
}
int main()
{
    CSNode *T;
    printf("输入根节点：");
    CreatTree(&T);
    printf("深度为：%d", depth(T));
}
