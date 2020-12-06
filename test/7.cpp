#include<stdio.h>
#include<malloc.h>
#define MaxSize 30

typedef struct node
{
    char data;
    struct node *sublist; //孩子链指针
    struct node *link;    //兄弟链指针
} BTNode;

char a[MaxSize] = "8(9,2(3,1(4,5)),7(6,A))";

void CreatBTNode(BTNode *&b, char *str)
{
    //做一个辅助栈结构
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
            //有一个标记，遇到左括号清零，
        case '(':
            flag = true;
            top++;
            St[top] = p;
            k = 1;
            break;
        case ',': //如果逗号前面的一个字符是右括号，那么就不需要进栈
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
            //这里如果是第一次遇到右括号，只要减1

        case ')':
            flag2 = true;
            if (flag == true)
                top -= 1, flag = false;
            else
                top -= 2;
            break;
        default:
            //默认情况下，ch是存储的数据
            p = (BTNode *)malloc(sizeof(BTNode));
            p->data = ch;
            p->sublist = p->link = NULL;
            if (b == NULL)
                b = p;
            else
            {
                //根据第一个switch的k值来判断
                switch (k)
                {
                case 1: //代表要用sublist指针指向
                    St[top]->sublist = p;
                    break;
                    //代表用link指针指向
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