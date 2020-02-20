#include <stdio.h> 
void main()
{
	int a;
	float b,c;
	scanf("%f",&b);
	a=(int)b;
	c=b-a;
	printf("%.2f=%d+%.2f",b,a,c);
}
