#include "stdio.h"
void main()
{
	int a; 
	scanf("%d",&a); 
	if(a>0)
	{
		if(a%2==0)
			printf("It is PLUS even number");
		else
			printf("It is PLUS odd number");
	}
	else if(a<0)
	{	
	if(a%2==0)
		printf("It is MINUS even number");
	else
		printf("It is MINUS odd number");
	}
	else
		printf("It is ZERO");
}
