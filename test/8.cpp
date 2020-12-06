#include <stdio.h>
#include <stdlib.h>

typedef struct CSNode
{
    int data;
    struct CSNode *firstchild, *nextsibling;
} CSNode;
//��α�������������
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
        printf("����%d������", ch);
        CreatTree((&(*T)->firstchild));
        printf("����%d���ֵ�", ch);
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
    printf("������ڵ㣺");
    CreatTree(&T);
    printf("���Ϊ��%d", depth(T));
}
