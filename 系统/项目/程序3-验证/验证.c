#include <stdio.h>
void main()
{
	int a, b;
	a = 2, b = 3;
	printf("%d\n", a ^ b >> 2);
	a = a >> 2;
	b = b << 3;
	printf("%d,%d \n", a, b);
	getchar();
}
