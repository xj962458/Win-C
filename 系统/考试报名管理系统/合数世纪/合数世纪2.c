#include<stdio.h>
#include<math.h>
int main()
{
   long a,b;
   int s,x,i;
   for(a=21;a<=20000;a++)
   {
      s=0;
      for(b=(a-1)*100+1;b<=a*100-1;b+=2) /*ö��a�����������b*/
      {
         x=0;
         for(i=3;i<=sqrt(b);i+=2)
            if(b%i==0)
            {
               x=1;
               break;
            }
         if(x==0)  /*����ѭ�����������͵�̽��*/
            break;
         s=s+x;  /*���bΪ����ʱ��x=1��s��1*/
      }
      if(s==50)   /*s=50����������Ǻ�������*/
         break;
   }
   printf("��һ����������Ϊ%ld���ͣ�\n",a);
}