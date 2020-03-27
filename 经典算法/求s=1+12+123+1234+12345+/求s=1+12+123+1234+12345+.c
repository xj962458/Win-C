#include <stdio.h>
void main()
{
	int n,i,j;
	long s=0,t=0;
	scanf("%d",&n);
	printf("s=");
	for(i=1;i<=n;i++)
	{	
		t=0;
	for(j=1;j<=i;j++) 
		t=t*10+j; 
	printf("%ld+",t);
	s=s+t;
	}
	printf("\b=%ld",s);
}

