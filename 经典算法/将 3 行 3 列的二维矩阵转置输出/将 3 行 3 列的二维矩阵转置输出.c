#include<stdio.h>
void main( )
{
	int a[3][3]={{1,2,3},{4,5,6},{7,8,9}};
	int b[3][3], i, j,*p =a;
	printf("array a:\n");
	for ( i = 0; i <= 1; i++)
	{
		for(j =0; j <= 2; j++)
		{
			printf("%5d",*p); 
			b[j][i]=a[i][j];
		}
	printf(" \n");
	}
	printf("array b:\n"); 
	for ( i = 0; i <= 2; i++)
	{
		for( j = 0; j <= 2; j++) 
			printf("%5d", *p);
		printf("\n");
	}
}
