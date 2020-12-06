#include <stdio.h>
int gcd(int a, int b)
{
    int r;
    while (b > 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
int f(int n)
{
    int i, num1, sum = 0;
    if (n == 1)
        return 1;
    else
    {
        for (i = 1; i <= n - 1; i++)
        {
            num1 = gcd(i, n - i);
            if (num1 == 1)
                sum += num1;
        }
        return sum;
    }
}
int g(int n)
{
    int d, sum = 0;
    for (d = 1; d <= n; d++)
        if (n % d == 0)
            sum += f(n / d);
    return sum;
}
int G(int n, int k)
{
    if (k == 1)
        return f(g(n));
    if (k > 1 && k % 2 == 0)
        return g(G(n, k - 1));
    if (k > 1 && k % 2 == 1)
        return f(G(n, k - 1));
}

int main()
{
    int i, nums, n, k;
    scanf("%d", &nums);
    int sum[nums];
    for (i = 1; i <= nums; i++)
    {
        scanf("%d %d", &n, &k);
        sum[i] = G(n, k);
    }
    for (i = 1; i <= nums; i++)
        printf("%d\n", sum[i]);
    return 0;
}