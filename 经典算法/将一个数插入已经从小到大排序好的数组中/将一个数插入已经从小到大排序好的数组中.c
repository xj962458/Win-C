#include<stdio.h> 
void main()
{
	int a[50],n,x,j; 
	int i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	printf("input	x:");
	scanf("%d",&x);
	for(i=0;i<n;i++)
	if(a[i]>x)
		break;
	if(i==n)
		a[i]=x;
	else
		for(j=n-1;j>=i;j--)
			a[j+1]=a[j];
	a[i]=x; 
	for(i=0;i<=n;i++)
		printf("%5d",a[i]);
}

