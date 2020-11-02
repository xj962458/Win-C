//˳��ջ�����㷨
#include <stdio.h>
#include <malloc.h>
#define MaxSize 100
typedef char ElemType;
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
bool Push(SqStack *&s, ElemType e) //��ջ
{
    if (s->top == MaxSize - 1) //ջ�����������ջ�����
        return false;
    s->top++;
    s->data[s->top] = e;
    return true;
}
bool Pop(SqStack *&s, ElemType &e) //��ջ
{
    if (s->top == -1) //ջΪ�յ��������ջ�����
        return false;
    e = s->data[s->top];
    s->top--;
    return true;
}
bool GetTop(SqStack *s, ElemType &e) //ȡջ��Ԫ��
{
    if (s->top == -1) //ջΪ�յ��������ջ�����
        return false;
    e = s->data[s->top];
    return true;
}

void trans(char *exp, char postexp[])
{
    char e;
    SqStack *Optr;       //���������ջ��˳��ջ��ָ��
    InitStack(Optr);     //��ʼ�������ջ
    int i = 0;           //i��Ϊpostexp���±�
    while (*exp != '\0') //exp���ʽδɨ����ʱѭ��
    {
        switch (*exp) //����Ԫ������,ִ����Ӧ����
        {
        case '(':            //�ж�Ϊ������,�������ջ,����ɨ�������ַ�
            Push(Optr, '('); //�����Ž�ջ
            exp++;           //����ɨ�������ַ�
            break;
        case '+': //Ϊ�ӻ����ʱ,ջ������������postexp,ֱ��ջ�ջ���ջ��Ϊ'('ʱ����
        case '-':
            while (!StackEmpty(Optr)) //ջ��ʱ�˳�ѭ��
            {
                GetTop(Optr, e); //ȡջ��Ԫ�أ������������������e
                if (e != '(')    //e����'('
                {
                    postexp[i++] = e; //��(�������e��ŵ�postexp��
                    Pop(Optr, e);     //��ջԪ�أ������������������ e
                }
                else
                    break; //����������ʱ,�˳�ѭ��
            }
            Push(Optr, *exp); //��'+'��'-'��ջ
            exp++;            //����ɨ�������ַ�
            break;
        default:                               //���������ַ�
            while (*exp >= '0' && *exp <= '9') //ת�������ַ�,
            {
                postexp[i++] = *exp; //ֱ�ӽ������ַ��洢�ַ�����postexp��
                exp++;
            }                   //ֱ�����ַ������ַ�ʱ����,��ʱ������һ��#
            postexp[i++] = '#'; //����#���߷������ַ�,��ʶһ����ֵ������
        }
    }
    while (!StackEmpty(Optr)) //��ʱexpɨ�����,ջԪ��ȫ������postexp
    {
        Pop(Optr, e);     //��ջԪ��e
        postexp[i++] = e; //��e��ŵ�postexp��
    }
    postexp[i] = '\0';   //��postexp���ʽ����ַ�����Ԫ�ؽ�����ʶ DestroyStack(Optr); //����ջ
}

int main()
{
    char exp[] = "(56-20)/(4+2)";
    char postexp[MaxSize];
    trans(exp, postexp);
    printf("%s",exp);
}