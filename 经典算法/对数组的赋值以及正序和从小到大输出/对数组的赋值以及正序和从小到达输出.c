#include<stdio.h>
void main()
{
	int a[10],n,i,j,min,t;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
	printf("\n");
	for(i=0;i<n;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
			if(a[j]<a[min])
			min=j;
			t=a[i];
			a[i]=a[min];
			a[min]=t;
	}
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
	printf("\n");
}


