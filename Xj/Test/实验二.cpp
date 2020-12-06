#include "btree.cpp" //�����������Ļ��������㷨
#define MaxWidth 40
BTNode *CreateBT(char *pre, char *in, int n)
{
    BTNode *b;
    char *p;
    int k;
    if (n <= 0)
        return NULL;
    b = (BTNode *)malloc(sizeof(BTNode)); //�������������*b
    b->data = *pre;
    for (p = in; p < in + n; p++)                         //�������������ҵ���*pre��λ��k
        if (*p == *pre)                                   //preָ������
            break;                                        //��in���ҵ����˳�ѭ��
    k = p - in;                                           //ȷ���������in�е�λ��
    b->lchild = CreateBT(pre + 1, in, k);                //�ݹ鹹��������
    b->rchild = CreateBT(pre + k + 1, p + 1, n - k - 1); //�ݹ鹹��������
    return b;
}

int main()
{
    BTNode *b;
    ElemType pre[] = "ABDGCEF";
    ElemType in[] = "DGBAECF";
    int n = 7;
    b = CreateBT(pre, in, n);
    printf("��������:%s\n", pre);
    printf("��������:%s\n", in);
    printf("����һ�ö�����b:\n");
    printf("  ���ű�ʾ��:");
    DispBTree(b);
    DestroyBTree(b);
    return 0;
}
