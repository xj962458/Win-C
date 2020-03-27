#include <stdio.h> 
void main()
{
	int i,j,sum,m;
	for(i=2;i<1000;i++)
	{
		sum=0;
		for(j=1;j<i;j++)
			if(i%j==0)
				sum+=j; 
		if(sum==i)
		{
			printf("%dits factors are 1",i);
			for(m=2;m<i;m++)
				if(i%m==0) printf(",%d",m);
				printf("\n");
		}
	}
}

