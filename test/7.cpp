#include<stdio.h>
#include<malloc.h>
#define MaxSize 30

typedef struct node
{
    char data;
    struct node *sublist; //������ָ��
    struct node *link;    //�ֵ���ָ��
} BTNode;

char a[MaxSize] = "8(9,2(3,1(4,5)),7(6,A))";

void CreatBTNode(BTNode *&b, char *str)
{
    //��һ������ջ�ṹ
    BTNode *St[MaxSize], *p = NULL;
    int top = -1;

    char ch;
    b = NULL;
    int k = 0;
    int i = 0;
    ch = str[i];
    bool flag = true;
    bool flag2 = false;
    while (ch != '\0')
    {
        switch (ch)
        {
            //��һ����ǣ��������������㣬
        case '(':
            flag = true;
            top++;
            St[top] = p;
            k = 1;
            break;
        case ',': //�������ǰ���һ���ַ��������ţ���ô�Ͳ���Ҫ��ջ
            if (flag2)
            {
                flag2 = false;
                break;
            }
            else
            {
                top++;
                St[top] = p;
                k = 2;
                break;
            }
            //��������ǵ�һ�����������ţ�ֻҪ��1

        case ')':
            flag2 = true;
            if (flag == true)
                top -= 1, flag = false;
            else
                top -= 2;
            break;
        default:
            //Ĭ������£�ch�Ǵ洢������
            p = (BTNode *)malloc(sizeof(BTNode));
            p->data = ch;
            p->sublist = p->link = NULL;
            if (b == NULL)
                b = p;
            else
            {
                //���ݵ�һ��switch��kֵ���ж�
                switch (k)
                {
                case 1: //����Ҫ��sublistָ��ָ��
                    St[top]->sublist = p;
                    break;
                    //������linkָ��ָ��
                case 2:
                    St[top]->link = p;
                    break;
                }
            }
        }
        i++;
        ch = str[i];
    }
}

int main()
{

    BTNode *b;
    CreatBTNode(b, a);
    // system("pause");
    return 0;
}