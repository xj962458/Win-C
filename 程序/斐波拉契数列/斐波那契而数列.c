# include <stdio.h>

// ���Fibonacci���У�ֱ�����һ�����պô��ڵ���1000Ϊֹ
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