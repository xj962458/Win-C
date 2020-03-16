# include <stdio.h>

// 计算1!+2!+3!+...+10!  凡是类似先累乘后累加的题目均可用一个for循环加上两条累乘累加语句来实现。
void main()
{
	int sum=0, product = 1, i;	// i: !前面的整数
	for(i=1; i<=10; i++)
	{
		product = product * i;
		sum = sum + product ;
	}
	printf("%d \n", sum);
}
