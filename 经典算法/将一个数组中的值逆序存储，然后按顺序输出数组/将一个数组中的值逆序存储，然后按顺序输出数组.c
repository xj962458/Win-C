#include<stdio.h> 
void main()
{
	int i,j,t,n,a[100];
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0,j=n-1;i<j;i++,j--)
	{
		t=a[i];
		a[i]=a[j]; 
		a[j]=t;
	}
	for(i=0;i<n;i++)
		printf("%5d",a[i]);
}
