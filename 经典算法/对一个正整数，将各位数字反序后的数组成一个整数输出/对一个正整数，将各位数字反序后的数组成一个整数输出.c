#include <stdio.h> 
void main()
{
	long m,n,sum=0;
	scanf("%ld",&m); 
	while(m>0)
	{
		n=m%10;
		m=m/10;
		sum=sum*10+n;
	}
	printf("%ld",sum);
}
