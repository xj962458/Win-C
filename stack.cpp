//顺序栈运算算法
#include <stdio.h>
#include<iostream>
#include<string>
using namespace std;

#define MaxSize 100
typedef string ElemType;
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
void Push(SqStack *&s, ElemType e) //进栈
{
    s->top++;
    s->data[s->top] = e;
}
void Pop(SqStack *&s) //出栈
{
    ElemType e = s->data[s->top];
    s->top--;
}
ElemType GetTop(SqStack *s) //取栈顶元素
{
    ElemType e;
    e = s->data[s->top];
    return e;
}
