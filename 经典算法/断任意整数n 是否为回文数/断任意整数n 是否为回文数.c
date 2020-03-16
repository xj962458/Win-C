#include<stdio.h>
void main()
{
	long n;
	int i,j,m,d[20];
	scanf("%ld",&n);
	m=0;
	while(n!=0)
	{
		n=n/10;
		m++;
	}
	for(i=0,j=m-1;i<j;i++,j--)
		if(d[i]!=d[j])
			break;
	if(i<j)
		printf("NOT");
	else	
		printf("YES");
}

