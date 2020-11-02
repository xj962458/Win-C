#include<stdio.h>
#define N 10
void main()
{
	int a[N+1],i,t;
	printf("From small to big N numbers:\n");
	for(i=0;i<N;i++)
		scanf("%d",&a[i]);
	printf("Input a number:a[N]=");
		scanf("%d",&a[N]);
	for(i=N;a[i]<a[i-1];i--)
	{
		t=a[i];
		a[i]=a[i-1];
		a[i-1]=t;
	}
	printf("the soted numbers:\n");
	for(i=0;i<N+1;i++)
		printf("%5d",a[i]);
	printf("\n");	
}

