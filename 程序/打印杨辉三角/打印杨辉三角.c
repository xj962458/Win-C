#include<stdio.h>
void main()
{
	int i,j,k,a[8][8]={{1},{1,1}};
	for(i=2;i<8;i++)
	{
		a[i][0]=1;
		for(j=1;j<=i;j++)
			a[i][j]=a[i-1][j-1]+a[i-1][j];
	}
	for(i=0;i<8;i++)
	{
		for(k=0;k<3*(8-i);k++)
			printf(" ");
		for(j=0;j<=i;j++)
			printf("%-6d",a[i][j]);
		printf("\n");
	}
}