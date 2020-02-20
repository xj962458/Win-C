#include<stdio.h>
void main()
{
	int i,n;
	long sum=0,a=1;
	printf("please input n:\n");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		a=a*i;
		sum+=a;
	}
	printf("1!+2!+...+%d!=%ld",n,sum);
}