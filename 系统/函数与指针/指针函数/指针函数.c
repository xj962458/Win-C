#include<stdio.h>
void main()
{
    int a=10,b=9,c;
    int *sum(int a,int b);
    printf("%d,%d\n",a,b);
    c=sum(a,b);
    printf("%d\n",c);

}

int *sum(int a,int b)
{
    int *p;
    int c;
    c=a+b;
    p=&c;
    return p;
}

/*ָ�뺯���Ƿ���ֵ��ָ��ĺ������䱾���Ǻ���
�������ͱ�ʶ�� *��������(��ʽ����)
{
    ������
}

*/