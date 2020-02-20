#include <stdio.h>
void main()
{
	int m,n,i,t;
	scanf("%d %d",&m,&n);
	if (m<n)
	{
		t=n;
		n=m;
		m=t;
	}
	i=n;
	while((m%i!=0)||(n%i!=0))
		i=i-1;
	printf("%d\n",i);
}
