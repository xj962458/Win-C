#include <stdio.h>
void main()
{
	int a,b,c,t; 
	int max,min;
	scanf("%d%d%d",&a,&b,&c);
	max=min=a;
	if(max<b)
		max=b;
	else
		min=b;
	if(max<c)
		max=c;
	else
		min=c;
	printf("max=%d,min=%d",max,min);
}

