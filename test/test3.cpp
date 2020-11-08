#include<iostream>
#include<string>
using namespace std;

#define MaxSize 50
typedef int ElemType;

typedef struct{
    ElemType data[MaxSize];
    int count,rear;
}SqQueue;
// 循环顺序队初始化
void InitQueue(SqQueue *&q)
{
    q = (SqQueue *)malloc(sizeof(SqQueue));
    q->count = 0;
    q->rear = 1;
}

// 循环顺序队入队
bool EnQueue(SqQueue *&q, ElemType e)
{
    if (q->count == MaxSize)
        return false;
    q->rear = (q->rear + 1) % MaxSize;
    q->data[q->rear] = e;
    q->count++;
    return true;
}

// 循环顺序队出队
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

// 循环顺序队判空算法
bool QueueEmpty(SqQueue *q)
{
    return (q->count == 0);
}
