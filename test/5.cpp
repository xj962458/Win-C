#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 20
typedef char ElemType; //�궨�����ṹ����������
typedef struct Snode   //���ṹ
{
    ElemType data;
    int parent;
} PNode;

typedef struct //���ṹ
{
    PNode tnode[MAX_SIZE];
    int n; //������
} PTree;

PTree InitPNode(PTree tree)
{
    int i, j;
    char ch;
    printf("������ڵ����:\n");
    scanf("%d", &(tree.n));

    printf("���������ֵ��˫��λ�������е�λ���±�:\n");
    for (i = 0; i < tree.n; i++)
    {
        getchar();
        scanf("%c %d", &ch, &j);
        tree.tnode[i].data = ch;
        tree.tnode[i].parent = j;
    }
    return tree;
}

void FindParent(PTree tree)
{
    char a;
    int isfind = 0;
    printf("������Ҫ��ѯ�Ľ��ֵ:\n");
    getchar();
    scanf("%c", &a);
    for (int i = 0; i < tree.n; i++)
    {
        if (tree.tnode[i].data == a)
        {
            isfind = 1;
            int ad = tree.tnode[i].parent;
            printf("%c�ĸ��ڵ�Ϊ %c,�洢λ���±�Ϊ %d", a, tree.tnode[ad].data, ad);
            break;
        }
    }
    if (isfind == 0)
    {
        printf("�����޴˽ڵ�");
    }
}

int main()
{
    PTree tree;
    for (int i = 0; i < MAX_SIZE; i++)
    {
        tree.tnode[i].data=' ';
        tree.tnode[i].parent = 0;
    }

    tree = InitPNode(tree);
    for(int i=0;i<7;i++)
        FindParent(tree);
    return 0;
}