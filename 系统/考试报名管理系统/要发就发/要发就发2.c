#include<stdio.h>
#include<math.h>
int num[1000];  //��Ų�����1993��ȫ������
int fun(int i);//�������ж��Ƿ�Ϊ����
void main()
{
    int i,j,count=0;
    printf("�ڵ�һ����������������Ҫ��:\n");
    for(j=0,i=3;i<=1993;i+=2)       //���������1993��ȫ������
        if(fun(i))
            num[j++]=i;
    for(j--;num[j]>1898;j--)        //�����������ʼ��1898����
    {
        for(i=0;num[j]-num[i]>1898;i++);
        if(num[j]-num[i]==1898)         //�����������Ĳ�Ϊ1898�������
            printf("(%d).%3d,......,%d\n",++count,num[i],num[j]);
    }
}
int fun(int i)//����
{
    int j;
    if(i<=1) 
        return 0;
    if(i==2) 
        return 1;
    if(!(i%2)) 
        return 0;
    for(j=3;j<=(int)sqrt((double)i+1);j+=2)
        if(!(i%j)) 
            return 0;
    return 1;
}