#include<stdio.h> 
void main( )
{
	int a[10],*p,*head,*end,temp; 
	printf("please input 10 numbers:\n");
	for(p=a;p<=a+9;p++)
		scanf("%d",p); 
	printf("The original array:\n");
	for(p=a;p<=a+9;p++)
		printf("%d ",*p);
	head=a; 
	end=a+9;
	while(head<end)
	{
	temp=*head;
	*head=*end;
	*end=temp;
	head++; 
	end--;
	}
	printf("The array has been inverted:\n"); 
	for(p=a;p<=a+9;p++)
		printf("%d   ",*p);
}
  