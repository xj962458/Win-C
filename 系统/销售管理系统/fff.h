#include<x.h>
int fff(int a[],int n,int p,int fz)
{   
    int i,j,s;
    a[p+1]=n;
    a[p+2]=0;
    for(i=1,j=1;a[i];i++)
    {
        if(a[i]<=a[i-1])j=0;           //������ͬ��ĸ����ȡ��2/3=1/3+1/3
        j*=a[i];                       //��ù���ĸ
    }
    for(i=1,s=0;a[i];i++)s+=j/a[i];
    if(s==fz)return 1;                 //�ҵ���������ֱ�ӷ�����ʾ�������Ӻ͵���fz��
    if(a[p]*a[p]>n)
		return 0;
    for(i=p>0?a[p]:2;i*i<=n;i++)
    {
        if(!(n%i))
        {
            a[++p]=i;                  //�洢����
            j=fff(a,n/i,p,fz);         //�ݹ����
            if (j)return 1;            //�Ѿ��ҵ��������������ٷֽ���ʽ
            p--;
        }
    }
    return 0;
}
