//˳��ջ�����㷨
#include <stdio.h>
#include<iostream>
#include<string>
using namespace std;

#define MaxSize 100
typedef string ElemType;
typedef struct
{
    ElemType data[MaxSize];
    int top;                //ջָ��
} SqStack;                  //����˳��ջ����
void InitStack(SqStack *&s) //��ʼ��˳��ջ
{
    s = (SqStack *)malloc(sizeof(SqStack));
    s->top = -1;
}
void DestroyStack(SqStack *&s) //����˳��ջ
{
    free(s);
}
bool StackEmpty(SqStack *s) //�ж�ջ�շ�
{
    return (s->top == -1);
}
void Push(SqStack *&s, ElemType e) //��ջ
{
    s->top++;
    s->data[s->top] = e;
}
void Pop(SqStack *&s) //��ջ
{
    ElemType e = s->data[s->top];
    s->top--;
}
ElemType GetTop(SqStack *s) //ȡջ��Ԫ��
{
    ElemType e;
    e = s->data[s->top];
    return e;
}
