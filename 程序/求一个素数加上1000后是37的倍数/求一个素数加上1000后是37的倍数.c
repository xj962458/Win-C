#include <stdio.h>
void  main()
{
	int i,n;
	for(n=2;n<=1000;n++)
	{
		for(i=2;i<n;i++)
			if(n%i==0)	break;
		if(i==n)
		{
			if((n+1000)%37==0)
			{
				printf("%d\n",n);
				break;
			}
		}
		
	}

}