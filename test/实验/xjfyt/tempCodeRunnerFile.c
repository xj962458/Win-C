#include <stdio.h>
#include <math.h>
int main()
{
    int N = 7;
    scanf("%d", &N);
    int i, j;
    int k = N / 2;
    for (i = 1; i <= N; i++)
    {
        for (j = abs(k + 1 - i); j > 0; j--)
            putchar(' ');
        putchar('*');
        j = N - 2 - abs(k + 1 - i) * 2;
        if (-1 == j)
            putchar(8); //退格
        for (; j > 0; j--)
            putchar(' ');
        putchar('*');

        putchar(10); //换行
    }
    return 0;
}