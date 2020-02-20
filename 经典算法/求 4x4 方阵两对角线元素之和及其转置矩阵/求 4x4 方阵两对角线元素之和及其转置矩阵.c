#include<stdio.h>
void main()
{
	int i,j,a[4][4],b[4][4],s=0;
	for(i=0;i<4;i++)
	for(j=0;j<4;j++)
	scanf("%d",&a[i][j]); 
	for(i=0;i<4;i++)
	for(j=0;j<4;j++)
	{
		b[i][j]=a[i][j];
		if(i==j||i+j==3)
			s=s+a[i][j];
	}
	for(i=0;i<4;i++)	
	{
		for(j=0;j<4;j++)
			printf("%5d",b[i][j]); 
		printf("\n");
 
	}
	printf("%5d",s);
}
