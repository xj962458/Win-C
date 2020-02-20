#include<stdio.h>
void main()
{
	int a,b,c,max;
	scanf("%d%d%d",&a,&b,&c);
	max=a;
	if(max<b) 
		max=b;
	if(max<c)
		max=c;
	printf("max is:%d\n",max);
}
