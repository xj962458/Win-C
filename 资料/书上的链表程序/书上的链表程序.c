#include <stdio.h>
#include <stdlib.h>

//��������ڵ����������
struct Node
{
    int data;
    struct Node *next;
};

//��������г�ʼ������
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

//�������нڵ�ĸ�������������
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

//���������������ɵĽڵ���뵽����ı�ͷ
struct Node *CreateList(struct Node *L, int n)
{
    int i;
    struct Node *p = NULL;
    for (i = n; i > 0; i--)
    {
        //�������ɵĽڵ���뵽������
        p = (struct Node *)malloc(sizeof(struct Node));
        scanf("%d", &p->data);
        p->next = L->next;
        L->next = p;
    }
    return L;
}

//��������нڵ�Ĳ������
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
        printf("�����λ�ò��Ϸ���\n");
        return L;
    }
    //����һ���½ڵ�s
    s = (struct Node *)malloc(sizeof(struct Node));
    s->data = e;
    //�ڵ�ĺ�����
    s->next = p->next;
    p->next = s;
    return L;
}

//���������нڵ��ɾ������
struct Node *ListDelete(struct Node *L, int i)
{
    int j;
    struct Node *q = NULL, *p = NULL;
    p = L;
    j = 0;
    //��ѯֻ��λ���ϵĽڵ�
    while (p->next && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (!(p->next) || j > i - 1)
    {
        printf("�����λ�ò��Ϸ���");
        return L;
    }
    //ɾ��ָ���ڵ�
    q = p->next;
    p->next = q->next;
    free(q);
    return L;
}

//�������ϵ�G�����в�ѯ����
int GetElem(struct Node *L, int i)
{
    int j, e;
    struct Node *p = NULL;
    if (i < 1 || i > ListLength(L))
    {
        printf("�����λ�ò��Ϸ���");
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
    printf("��%d��Ԫ�ص�����Ϊ%d\n", i, e);
}

//����Ĳ���
void menu()
{
    printf("*****************Ŀ¼***************\n");
    printf("1�������֧������                     \n");
    printf("2���ڵ������в���һ���½ڵ�            \n");
    printf("3���ڵ�������ɾ��ָ���ڵ�              \n");
    printf("4����ѯ�������еĽڵ�                  \n");
    printf("0���˳�                               \n");
    printf("**************************************\n");
}

//������
int main()
{
    int n, m, i, e;
    struct Node *L = NULL, *p = NULL;
    L = InitList(L);
    printf("������Ԫ������");
    scanf("%d", &n);
    printf("��������%d��Ԫ�ص����ݣ��ÿո������:", n);
    L = CreateList(L, n);
    do
    {
        printf("\n\n");
        menu();
        printf("�������ѡ��");
        scanf("%d", &m);
        switch (m)
        {
        case 1:
            printf("��֧������Ϊ:");
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
            printf("�����������λ�ú�����Ԫ��(�ո����)��");
            scanf("%d %d", &i, &e);
            L = ListInsert(L, i, e);
            break;
        case 3:
            printf("������Ҫɾ����Ԫ��λ��:");
            scanf("%d", &i);
            L = ListDelete(L, i);
            break;
        case 4:
            printf("������Ҫ��ѯԪ�ص�λ�ã�");
            scanf("%d", &i);
            GetElem(L, i);
            break;
        case 0:
            printf("�˳�\n");
            exit(0);
            break;
        default:
            printf("�������\n");
        }
    } while (m != 0);
}
