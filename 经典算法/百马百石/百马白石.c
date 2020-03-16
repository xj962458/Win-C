#include <stdio.h>
void main()
{
	int i,j,k; 
	for(i=0;i<=33;i++)
	for(j=0;j<=50;j++)
	{
		k=100-i-j;
		if(3*i+2*j+k/2.0==100)
			printf("Da=%d,Zhong=%d,Xiao=%d\n",i,j,k);
	}
}

