#include<stdio.h>
#include<math.h>
int main()
{
   long a,b,k;
   int m,n,s,x;
   printf("̽����n���������ͣ�������n:");
   scanf("%d",&n);
   a=1;
   m=0;
   while(1)
   {
      a++;    /*����a����*/
      s=0;
      for(b=a*100-99;b<=a*100-1;b+=2) /*ö��a�����������b*/
      {
         x=0;
         for(k=3;k<=sqrt(b);k+=2)
            if(b%k==0)
            {
               x=1;
               break;
            }
         if(x==0)  /*����ѭ�����������͵�̽��*/
            break;
         s=s+x;  /*���bΪ����ʱ��x=1��s��1*/
      }
      if(s==50)   /*s=50������������m��1*/
         m++;
      if(m==n)
         break;
   }
   printf("��%d����������Ϊ%ld���ͣ�\n",n,a);
   printf("�����͵����%ld--%ldȫΪ������\n",a*100-99,a*100);
}