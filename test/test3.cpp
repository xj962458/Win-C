#include<iostream>
#include<string>
using namespace std;

#define MaxSize 50
typedef int ElemType;

typedef struct{
    ElemType data[MaxSize];
    int count,rear;
}SqQueue;
// ѭ��˳��ӳ�ʼ��
void InitQueue(SqQueue *&q)
{
    q = (SqQueue *)malloc(sizeof(SqQueue));
    q->count = 0;
    q->rear = 1;
}

// ѭ��˳������
bool EnQueue(SqQueue *&q, ElemType e)
{
    if (q->count == MaxSize)
        return false;
    q->rear = (q->rear + 1) % MaxSize;
    q->data[q->rear] = e;
    q->count++;
    return true;
}

// ѭ��˳��ӳ���
bool DeQueue(SqQueue *&q, ElemType &e)
{
    int front;
    if (q->count == 0)
        return false;
    front=(q->rear-q->count+MaxSize)%MaxSize;
    front = (q->count + 1) % MaxSize;
    e = q->data[front];
    q->count--;
    return true;
}

// ѭ��˳����п��㷨
bool QueueEmpty(SqQueue *q)
{
    return (q->count == 0);
}
