#include<stdio.h>
#include<malloc.h>
#define MaxSize 100

typedef int ElemType;

typedef struct
{
	ElemType data[MaxSize];		//存放队中元素
	int front,rear;				//队头和队尾指针
}SqQueue;

//初始化队列
void InitQueue(SqQueue *&q)
{
	q=(SqQueue *)malloc(sizeof(SqQueue));
	q->front=q->rear=0;
}
//进队
bool enQueue(SqQueue *&q,ElemType e)
{
	if((q->rear+1)%MaxSize==q->front)
		return false;
	q->rear = (q->rear+1)%MaxSize;
	q->data[q->rear] = e;
	return true;
}
//出队
bool deQueue(SqQueue *&q,ElemType &e)
{
	if(q->front==q->rear)
		return false;
	q->front=(q->front+1)%MaxSize;
	e=q->data[q->front];
	return true;
}
//判队列是否为空
bool QueueEmpty(SqQueue *q)
{
	return (q->front==q->rear);
}
//销毁队列
void DestroyQueue(SqQueue *&q)
{
	free(q);
}
//报数
void Bs(int n)
{
	int i;
	int count=1;				//count用来记第几个元素
	SqQueue *q;
	InitQueue(q);
	for(i=1;i<=n;i++)
	{
		enQueue(q,i);
	}
	while(!QueueEmpty(q))
	{
		deQueue(q,i);
		if(count%2==0)			//第偶数个元素时，进队
			enQueue(q,i);
		else
			printf("%d ",i);	//第奇数个元素时，出队输出
		count++;
	}
	printf("\n");
	DestroyQueue(q);
}
int main(void)
{
	int n;
	printf("输入n的个数：");
	scanf("%d",&n);
	Bs(n);
	return 0;
}