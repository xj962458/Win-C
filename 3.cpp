#include <stdio.h>
#include <malloc.h>
typedef int  ElemType;
#define MaxSize 50
typedef struct sqstack
{
    ElemType data[MaxSize];
    int top;
}SqStack;

void InitStack(SqStack *&s)//��ʼ��˳��ջ
{
    s=(SqStack *)malloc(sizeof(SqStack));
    s->top=-1;
}
bool StackEmpty(SqStack *s)//�ж�˳����Ƿ�Ϊ��
{
    return(s->top==-1);
}
void DestroyStack(SqStack *&s)//�ͷ�˳���ռ�õ��ڴ�ռ�
{
    free(s);
} 
bool Push(SqStack *&s,ElemType e)//����Ԫ��
{   if (s->top==MaxSize-1) //ջ�����������ջ�����
        return false;
    s->top++; //ջ��ָ����1
    s->data[s->top]=e; //Ԫ��e����ջ��ָ�봦
    return true;
}
bool Pop(SqStack *&s,ElemType &e)//��ջ��Ԫ�ظ���e
{
    if (s->top==-1) //ջΪ�յ��������ջ�����
        return false;
    e=s->data[s->top]; //ȡջ��ָ��Ԫ�ص�Ԫ��
    s->top--; //ջ��ָ���1���´���ջʱ�����Ԫ�ػᱻ���ǣ��ʲ������
    return true;
}
void DispStack(SqStack *s)
{
    while(s->top!=-1)
    {
        printf("%d ",s->data[s->top]);
        s->top--;
    }
    printf("\n");
} 
void CreateStack(SqStack *&s,ElemType a[],int n) //���彨��˳��ջ
{
    int i=0;
    s=(SqStack *)malloc(sizeof(SqStack));//һ���Է����data��
    s->top=0;
    while(s->top<n) //iɨ��a��Ԫ��
    {
        s->data[s->top]=a[i];
        s->top++;i++; //k��¼���뵽s�е�Ԫ�ظ���
    }
}
int main()
{   ElemType e;
    SqStack *st;
    InitStack(st);//��ʼ��˳��ջ
    printf("ջst�Ƿ�Ϊ��: %d\n",StackEmpty(st));
    Push(st,'a');
    Push(st,'b');
    Push(st,'c');
    printf("ջst�Ƿ�Ϊ��: %d\n",StackEmpty(st));
    printf("��ջ˳��: ");
    while(!StackEmpty(st))
    {   Pop(st,e);
        printf("%c ",e);
    }
     DestroyStack(st);
}



