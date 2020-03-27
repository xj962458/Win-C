#include<stdio.h>
void main()
{	
	int a[100];
	int i,j,n,t,num=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n;i++)
		if(i%2==1&&a[i]%2==0)
			num++;
	for(i=0;i<n;i++)
		printf("%5d",a[i]);
	printf("\n%d",num);
}

