//文件名:exp7-3.cpp
#include "btree.cpp" //包含二叉树的基本运算算法
#define MaxWidth 40

BTNode *CreateBT2(char *post, char *in, int n)
{
    BTNode *b;
    char r, *p;
    int k;
    if (n <= 0)
        return NULL;
    r = *(post + n - 1);                  //根结点值
    b = (BTNode *)malloc(sizeof(BTNode)); //创建二叉树结点*b
    b->data = r;
    for (p = in; p < in + n; p++) //在in中查找根结点
        if (*p == r)
            break;
    k = p - in;                                        //k为根结点在in中的下标
    b->lchild = CreateBT2(post, in, k);                //递归构造左子树
    b->rchild = CreateBT2(post + k, p + 1, n - k - 1); //递归构造右子树
    return b;
}

int main()
{
    BTNode *b;
    ElemType in[] = "DGBAECF";
    ElemType post[] = "GDBEFCA";
    int n = 7;
    printf("中序序列:%s\n", in);
    printf("后序序列:%s\n", post);
    b = CreateBT2(post, in, n);
    printf("构造一棵二叉树b:\n");
    printf(" 括号表示法:");
    DispBTree(b);
    DestroyBTree(b);
    return 0;
}
