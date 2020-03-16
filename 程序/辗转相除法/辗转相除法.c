// 辗转相除法求最大公约数
# include <stdio.h>

void main()
{
	int x, y, t, yu;
	scanf("%d %d", &x, &y);
	// 辗转相除法要求第1个数大于等于第2个数
	if(x<y)
	{
		t=x;
		x=y;
		y=t;
	}

	yu=x%y;
	while(yu)
	{
		x=y;
		y=yu;
		yu=x%y;
	}
	printf("%d\n", y);
}



