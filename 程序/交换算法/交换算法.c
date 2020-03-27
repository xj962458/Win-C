# include <stdio.h>

void swap1(int a, int b)	// 形参是第1类的普通变量，形参的改变不会影响实参
{
	int t;
	t=a;
	a=b;
	b=t;
	printf("%d, %d\n", a, b);	// 输出2, 1
}

void swap2(int *a, int *b)
{
	int *t;
	t=a;	// 交换的是a，b两个指针的指向，交换后a指向y, b指向x
	a=b;
	b=t;
}

void swap3(int *a, int *b)	// 参数传递：a=&x;  b=&y  // *a<=>x  *b<=>y
{
	int t;
	t=*a;	// 交换*a 和 *b，等价于交换x, y
	*a=*b;
	*b=t;
}

void main()
{
	int x=1, y=2;
	swap1(x,y);
	printf("%d, %d\n", x, y);	// 输出1, 2

	swap2(&x, &y);
	printf("%d, %d\n", x, y);	// 输出1, 2

	swap3(&x, &y);
	printf("%d, %d\n", x, y);	// 输出2, 1
}
