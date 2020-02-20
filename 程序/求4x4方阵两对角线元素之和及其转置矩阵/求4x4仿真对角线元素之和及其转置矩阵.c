#include<stdio.h>
void main()
{
	int a[4][4],b[4][4],i,j,s=0;
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			scanf("%d",&a[i][j]);
		for(i=0;i<4;i++)
			s+=a[i][i]+a[3-i][i];
		for(i=0;i<4;i++)
			for(j=0;j<4;j++)
				b[j][i]=a[i][j];
		printf("Array a:\n");
		for(i=0;i<4;i++)
		{
			for(j=0;j<4;j++)
				printf("%4d",a[i][j]);
			printf("\n");
		}
		printf("s=%d\n",s);
		printf("Array b:\n");
		for(i=0;i<4;i++)
		{
			for(j=0;j<4;j++)
				printf("%4d",b[i][j]);
			printf("\n");
		}
}