#include<stdio.h>
int main()
{
	int i,n,c=0;
	printf("请输入n:\n");
	scanf("%d",&n);
	for(i = 0; i < n; i++) 
	{
		n /= 5;
		c += n;
	}
	printf("该数阶乘后有%d个0",c);
    return 0;
}
