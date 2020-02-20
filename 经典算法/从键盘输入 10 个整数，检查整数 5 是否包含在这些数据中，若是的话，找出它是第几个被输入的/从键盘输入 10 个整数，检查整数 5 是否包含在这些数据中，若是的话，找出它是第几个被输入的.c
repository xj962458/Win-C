#include<stdio.h>
void main()
{
	int a[10],i;
	for(i=0;i<10;i++)
	scanf("%d",&a[i]);
	for(i=0;i<10;i++)
		if(a[i]==5)
		{
			printf("5 is input the position %d\n.",i+1);
			break;
		}
	if(i>=10)
	printf("5 is not in data.\n");
}
