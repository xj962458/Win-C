#include<stdio.h>
void main()
{
    int i,a,b;  //aΪ�������������bΪa���͵�50���������
    for(a=21;a<20000;a++)
    {
        for(b=(a-1)*100+1;b<a*100;b+=2)
        {
            for(i=3;i*i<b;i+=2)
            {
                if(b%i==0)
                    break;
            }
            if(i*i>=b)
                break;
        }
        if(b>=a*100)
        {
            printf("��һ������������%d����",a);
        }
    }
}