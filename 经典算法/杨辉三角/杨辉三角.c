#include<stdio.h> 
int main()
{
	int i,j,a[8][8]; 
	for(i=0;i<8;i++)
		for(j=0;j<8;j++)
			if(i==j||j==0)
				a[i][j]=1;
			else
				a[i][j]=a[i-1][j-1]+a[i-1][j];
	for(i=0;i<8;i++)
	{
		for(j=0;j<8;j++)
			printf("%5d",a[i][j]);
		printf("\n");
	}
}

