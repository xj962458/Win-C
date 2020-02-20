#include <stdio.h>
void main()
{
	char c; 
	long t=0;
	while((c=getchar())!='\n')
	{
		if(c<'0'||c>'9')
		{	
			printf("input error and input over\n");
			break;
		}
		else if(c>='0'&&c<='9')
			t=t*10+(c-'0');
	}
	printf("%ld",t);
}
