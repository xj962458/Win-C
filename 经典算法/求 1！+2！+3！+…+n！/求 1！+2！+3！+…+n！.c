#include <stdio.h>
void main()
{
	long s=1,i,t=1,n;
	scanf("%ld",&n);
	for(i=2;i<=n;i++)
	{
		t=t*i;
		s=s+t;
	}
	printf("%ld",s);
 
}


