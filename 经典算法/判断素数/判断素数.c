# include <stdio.h>

// isPrime1: 如果n是素数返回值1，否则返回值0
int isPrime1(int n)
{
	int chushu;
	for(chushu=2; chushu<=n-1; chushu++)
	{
		if(n%chushu == 0)
		{
			return 0;
		}
	}
	return 1;
}

// 无返回值，如果n是素数则输出“n是素数”，否则输出“n是合数”
void isPrime2(int n)
{
	int chushu;
	for(chushu=2; chushu<=n-1; chushu++)
	{
		if(n%chushu==0)
		{
			// 如果n能被chushu整除则n一定是合数且没必要继续循环下去
			break;
		}
	}
	if(chushu==n)	// 只有n是素数时，for循环才会正常结束（不是由break提前结束），正常结束for后，chushu正好等于n
	{
		printf("%d 是素数\n", n);
	}
	else
	{
		printf("%d 是合数\n", n);
	}
}

void main()
{
	int x;
	scanf("%d", &x);
	// 调用isPrime1
	if(isPrime1(x))
	{
		printf("素数\n");
	}
	else
	{
		printf("合数\n");
	}

	// 调用isPrime2
	isPrime2(x);
}
