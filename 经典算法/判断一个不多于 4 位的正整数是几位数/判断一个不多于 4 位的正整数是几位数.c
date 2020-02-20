#include<stdio.h>
void main()
{	
	int n;
	printf("Input anum(0<num<10000)"); 
	scanf("%d",&n);
	if(n<10)
		printf("1\n");
	else
	if(n<100)
		printf("2\n");
	else
	if(n<1000)
		printf("3\n");
	else
	printf("4\n");
}
