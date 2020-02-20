#include <stdio.h> 
void main()
{
	int sum=1,i,j;
	for(i=2;i<=100;i++)
	{
		for(j=2;j<i;j++)
			if(i%j==0&&j<i) break; if(i==j)	
				sum=sum+i;
	}
	printf("sum=%d",sum);
}
