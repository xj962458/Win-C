# include <stdio.h>

void swap1(int a, int b)	// �β��ǵ�1�����ͨ�������βεĸı䲻��Ӱ��ʵ��
{
	int t;
	t=a;
	a=b;
	b=t;
	printf("%d, %d\n", a, b);	// ���2, 1
}

void swap2(int *a, int *b)
{
	int *t;
	t=a;	// ��������a��b����ָ���ָ�򣬽�����aָ��y, bָ��x
	a=b;
	b=t;
}

void swap3(int *a, int *b)	// �������ݣ�a=&x;  b=&y  // *a<=>x  *b<=>y
{
	int t;
	t=*a;	// ����*a �� *b���ȼ��ڽ���x, y
	*a=*b;
	*b=t;
}

void main()
{
	int x=1, y=2;
	swap1(x,y);
	printf("%d, %d\n", x, y);	// ���1, 2

	swap2(&x, &y);
	printf("%d, %d\n", x, y);	// ���1, 2

	swap3(&x, &y);
	printf("%d, %d\n", x, y);	// ���2, 1
}