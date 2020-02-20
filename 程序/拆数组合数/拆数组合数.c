# include <stdio.h>

void main()
{
	// 未知位数的拆数和组合
	int x, gw, k=0;
	scanf("%d", &x);
	while(x)
	{
		gw = x%10;
		k = k*10 + gw;	// 反向组合
		x = x/10;
	}
	printf("%d \n", k);
}