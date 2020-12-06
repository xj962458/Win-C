//�ļ���:exp7-3.cpp
#include "btree.cpp" //�����������Ļ��������㷨
#define MaxWidth 40

BTNode *CreateBT2(char *post, char *in, int n)
{
    BTNode *b;
    char r, *p;
    int k;
    if (n <= 0)
        return NULL;
    r = *(post + n - 1);                  //�����ֵ
    b = (BTNode *)malloc(sizeof(BTNode)); //�������������*b
    b->data = r;
    for (p = in; p < in + n; p++) //��in�в��Ҹ����
        if (*p == r)
            break;
    k = p - in;                                        //kΪ�������in�е��±�
    b->lchild = CreateBT2(post, in, k);                //�ݹ鹹��������
    b->rchild = CreateBT2(post + k, p + 1, n - k - 1); //�ݹ鹹��������
    return b;
}

int main()
{
    BTNode *b;
    ElemType in[] = "DGBAECF";
    ElemType post[] = "GDBEFCA";
    int n = 7;
    printf("��������:%s\n", in);
    printf("��������:%s\n", post);
    b = CreateBT2(post, in, n);
    printf("����һ�ö�����b:\n");
    printf(" ���ű�ʾ��:");
    DispBTree(b);
    DestroyBTree(b);
    return 0;
}
