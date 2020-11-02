//顺序栈运算算法
#include <stdio.h>
#include <malloc.h>
#define MaxSize 100
typedef char ElemType;
typedef struct
{
    ElemType data[MaxSize];
    int top;                //栈指针
} SqStack;                  //声明顺序栈类型
void InitStack(SqStack *&s) //初始化顺序栈
{
    s = (SqStack *)malloc(sizeof(SqStack));
    s->top = -1;
}
void DestroyStack(SqStack *&s) //销毁顺序栈
{
    free(s);
}
bool StackEmpty(SqStack *s) //判断栈空否
{
    return (s->top == -1);
}
bool Push(SqStack *&s, ElemType e) //进栈
{
    if (s->top == MaxSize - 1) //栈满的情况，即栈上溢出
        return false;
    s->top++;
    s->data[s->top] = e;
    return true;
}
bool Pop(SqStack *&s, ElemType &e) //出栈
{
    if (s->top == -1) //栈为空的情况，即栈下溢出
        return false;
    e = s->data[s->top];
    s->top--;
    return true;
}
bool GetTop(SqStack *s, ElemType &e) //取栈顶元素
{
    if (s->top == -1) //栈为空的情况，即栈下溢出
        return false;
    e = s->data[s->top];
    return true;
}

void trans(char *exp, char postexp[])
{
    char e;
    SqStack *Optr;       //定义运算符栈（顺序栈）指针
    InitStack(Optr);     //初始化运算符栈
    int i = 0;           //i作为postexp的下标
    while (*exp != '\0') //exp表达式未扫描完时循环
    {
        switch (*exp) //根据元素类型,执行相应操作
        {
        case '(':            //判定为左括号,入运算符栈,继续扫描其它字符
            Push(Optr, '('); //左括号进栈
            exp++;           //继续扫描其他字符
            break;
        case '+': //为加或减号时,栈里的运算符存入postexp,直到栈空或者栈顶为'('时结束
        case '-':
            while (!StackEmpty(Optr)) //栈空时退出循环
            {
                GetTop(Optr, e); //取栈顶元素（运算符或者左括弧）e
                if (e != '(')    //e不是'('
                {
                    postexp[i++] = e; //将(运算符）e存放到postexp中
                    Pop(Optr, e);     //出栈元素（运算符或者左括弧） e
                }
                else
                    break; //碰到左括弧时,退出循环
            }
            Push(Optr, *exp); //将'+'或'-'进栈
            exp++;            //继续扫描其他字符
            break;
        default:                               //处理数字字符
            while (*exp >= '0' && *exp <= '9') //转存数字字符,
            {
                postexp[i++] = *exp; //直接将数字字符存储字符数组postexp中
                exp++;
            }                   //直到出现非数字字符时结束,此时再增加一个#
            postexp[i++] = '#'; //增加#或者非数字字符,标识一个数值串结束
        }
    }
    while (!StackEmpty(Optr)) //此时exp扫描完毕,栈元素全部放入postexp
    {
        Pop(Optr, e);     //出栈元素e
        postexp[i++] = e; //将e存放到postexp中
    }
    postexp[i] = '\0';   //给postexp表达式添加字符数组元素结束标识 DestroyStack(Optr); //销毁栈
}

int main()
{
    char exp[] = "(56-20)/(4+2)";
    char postexp[MaxSize];
    trans(exp, postexp);
    printf("%s",exp);
}