#include<stdio.h>
#include<malloc.h>
#define MaxSize 100

typedef int ElemType;

typedef struct
{
	ElemType data[MaxSize];		//��Ŷ���Ԫ��
	int front,rear;				//��ͷ�Ͷ�βָ��
}SqQueue;

//��ʼ������
void InitQueue(SqQueue *&q)
{
	q=(SqQueue *)malloc(sizeof(SqQueue));
	q->front=q->rear=0;
}
//����
bool enQueue(SqQueue *&q,ElemType e)
{
	if((q->rear+1)%MaxSize==q->front)
		return false;
	q->rear = (q->rear+1)%MaxSize;
	q->data[q->rear] = e;
	return true;
}
//����
bool deQueue(SqQueue *&q,ElemType &e)
{
	if(q->front==q->rear)
		return false;
	q->front=(q->front+1)%MaxSize;
	e=q->data[q->front];
	return true;
}
//�ж����Ƿ�Ϊ��
bool QueueEmpty(SqQueue *q)
{
	return (q->front==q->rear);
}
//���ٶ���
void DestroyQueue(SqQueue *&q)
{
	free(q);
}
//����
void Bs(int n)
{
	int i;
	int count=1;				//count�����ǵڼ���Ԫ��
	SqQueue *q;
	InitQueue(q);
	for(i=1;i<=n;i++)
	{
		enQueue(q,i);
	}
	while(!QueueEmpty(q))
	{
		deQueue(q,i);
		if(count%2==0)			//��ż����Ԫ��ʱ������
			enQueue(q,i);
		else
			printf("%d ",i);	//��������Ԫ��ʱ���������
		count++;
	}
	printf("\n");
	DestroyQueue(q);
}
int main(void)
{
	int n;
	printf("����n�ĸ�����");
	scanf("%d",&n);
	Bs(n);
	return 0;
}