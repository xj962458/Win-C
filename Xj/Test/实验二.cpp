#include "btree.cpp" //包含二叉树的基本运算算法
#define MaxWidth 40
BTNode *CreateBT(char *pre, char *in, int n)
{
    BTNode *b;
    char *p;
    int k;
    if (n <= 0)
        return NULL;
    b = (BTNode *)malloc(sizeof(BTNode)); //创建二叉树结点*b
    b->data = *pre;
    for (p = in; p < in + n; p++)                         //在中序序列中找等于*pre的位置k
        if (*p == *pre)                                   //pre指向根结点
            break;                                        //在in中找到后退出循环
    k = p - in;                                           //确定根结点在in中的位置
    b->lchild = CreateBT(pre + 1, in, k);                //递归构造左子树
    b->rchild = CreateBT(pre + k + 1, p + 1, n - k - 1); //递归构造右子树
    return b;
}

int main()
{
    BTNode *b;
    ElemType pre[] = "ABDGCEF";
    ElemType in[] = "DGBAECF";
    int n = 7;
    b = CreateBT(pre, in, n);
    printf("先序序列:%s\n", pre);
    printf("中序序列:%s\n", in);
    printf("构造一棵二叉树b:\n");
    printf("  括号表示法:");
    DispBTree(b);
    DestroyBTree(b);
    return 0;
}
