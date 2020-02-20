# include <stdio.h>

// 输出Fibonacci数列，直到最后一个数刚好大于等于1000为止
void main()
{
	int f1=0, f2=1, f;
	f = f1+f2;
	printf("%d, %d, %d, ", f1, f2, f);
	while(f<1000)
	{
		f1=f2;
		f2=f;
		f=f1+f2;
		printf("%d, ", f);
	}
	printf("\n");
}