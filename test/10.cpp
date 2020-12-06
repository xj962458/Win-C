#include <stdio.h>
#include <stdlib.h>
#define MAX 20

typedef struct CNode //���ӽ��
{
    int pos;            //����λ��
    struct CNode *next; //����ָ��
} CNode, *PChild;

typedef struct //�����
{
    char data;    //�����������
    PChild child; //��������
} CTRoot;

typedef struct //˳���ṹ
{
    CTRoot Node[MAX];
    int sum; //�������
} SqCTree, *CTree;

void InitCTree(CTree &CT) //��ʼ����
{

    CT = (SqCTree *)malloc(sizeof(SqCTree));
    CT->sum = 0;
    for (int i = 0; i < MAX; i++) //��ʼ�������ÿ�����ӽ��
    {
        CT->Node[i].child = (CNode *)malloc(sizeof(CNode));
        CT->Node[i].child->next = NULL;
    }
    printf("��ʼ��!\n");
}

void CreateCTree(CTree &CT) //������
{
    printf("����������:");
    scanf("%d", &CT->sum);
    fflush(stdin);

    int n;
    char ch;

    for (int i = 0; i < CT->sum; i++)
    {
        printf("�������%d��������ݼ��������ͺ���λ��:", i);

        scanf("%c", &ch);
        CT->Node[i].data = ch;

        scanf("%d", &n);

        PChild p = CT->Node[i].child;
        for (int j = 0; j < n; j++) //���뺢�ӽ��
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

void LevelOrderTraverse(CTree CT) //�������
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

    printf("\n�������:");
    LevelOrderTraverse(CT);
    return 0;
}
