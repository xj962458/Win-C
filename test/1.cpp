//exp6-5.cpp
#include <stdio.h>
#define N 4
#define M 10
int value(int a[], int i, int j) //压缩为一维数组
{
	if (i >= j)
		return a[(i * (i + 1)) / 2 + j];
	else
		return a[(j * (j + 1)) / 2 + i];
}
void madd(int a[], int b[], int c[][N]) //压缩存储a和b的和
{
	int i, j;
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			c[i][j] = value(a, i, j) + value(b, i, j);
}
void mult(int a[], int b[], int c[][N]) //压缩存储a和b的乘积
{
	int i, j, k, s;
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
		{
			s = 0;
			for (k = 0; k < N; k++)
				s = s + value(a, i, k) * value(b, k, j);
			c[i][j] = s;
		}
}
void disp1(int a[]) //输出原始矩阵
{
	int i, j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
			printf("%4d", value(a, i, j));
		printf("\n");
	}
}
void disp2(int c[][N]) //输出求和，求积矩阵
{
	int i, j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
			printf("%4d", c[i][j]);
		printf("\n");
	}
}
int main()
{
	int a[M] = {9, 1, 2, 3, 7, 6, 5, 8, 4, 0};
	int b[M] = {11, 14, 12, 31, 71, 13, 56, 83, 42, 14};
	int c1[N][N], c2[N][N];
	madd(a, b, c1);
	mult(a, b, c2);
	printf("a矩阵为:\n");
	disp1(a);
	printf("b矩阵为:\n");
	disp1(b);
	printf("a+b:\n");
	disp2(c1);
	printf("a*b:\n");
	disp2(c2);
	return 0;
}