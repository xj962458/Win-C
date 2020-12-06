#include <cstdio>
#include <cstring>
using namespace std;

const int N = 610;
int n, X, Y, pushX, pushO, father[N * N], sum[N * N];
char map[N][N], push;
bool vis[N * N];

int find(int x)
{
    return x == father[x] ? x : father[x] = find(father[x]);
}

int C(int x, int y)
{
    if (x > n || y > n || x < 1 || y < 1)
        return 0;
    return (x - 1) * n + y;
}

bool check_push(char ch)
{
    char oth = (ch == 'X' ? 'O' : 'X');
    for (int k = (ch == 'X' ? pushX : pushO); k <= n * n; k++)
    {
        int i = (k - 1) / n + 1;
        int j = (k - 1) % n + 1;
        if (map[i][j] == '.')
        {
            if (map[i - 1][j] == oth)
                sum[find(C(i - 1, j))]--;
            if (map[i + 1][j] == oth)
                sum[find(C(i + 1, j))]--;
            if (map[i][j - 1] == oth)
                sum[find(C(i, j - 1))]--;
            if (map[i][j + 1] == oth)
                sum[find(C(i, j + 1))]--;

            int s = 4;
            if (map[i - 1][j] == ch)
            {
                s -= 2;
                if (!vis[find(C(i - 1, j))])
                {
                    vis[find(C(i - 1, j))] = 1;
                    s += sum[find(C(i - 1, j))];
                }
            }
            if (map[i + 1][j] == ch)
            {
                s -= 2;
                if (!vis[find(C(i + 1, j))])
                {
                    vis[find(C(i + 1, j))] = 1;
                    s += sum[find(C(i + 1, j))];
                }
            }
            if (map[i][j - 1] == ch)
            {
                s -= 2;
                if (!vis[find(C(i, j - 1))])
                {
                    vis[find(C(i, j - 1))] = 1;
                    s += sum[find(C(i, j - 1))];
                }
            }
            if (map[i][j + 1] == ch)
            {
                s -= 2;
                if (!vis[find(C(i, j + 1))])
                {
                    vis[find(C(i, j + 1))] = 1;
                    s += sum[find(C(i, j + 1))];
                }
            }
            vis[find(C(i - 1, j))] = vis[find(C(i + 1, j))] = vis[find(C(i, j - 1))] = vis[find(C(i, j + 1))] = 0;
            if (map[i - 1][j] == oth || i == 1)
                s--;
            if (map[i + 1][j] == oth || i == n)
                s--;
            if (map[i][j - 1] == oth || j == 1)
                s--;
            if (map[i][j + 1] == oth || j == n)
                s--;

            bool ok = 0;
            if (s && sum[find(C(i - 1, j))] && sum[find(C(i + 1, j))] && sum[find(C(i, j - 1))] && sum[find(C(i, j + 1))])
                ok = 1;

            if (map[i - 1][j] == oth)
                sum[find(C(i - 1, j))]++;
            if (map[i + 1][j] == oth)
                sum[find(C(i + 1, j))]++;
            if (map[i][j - 1] == oth)
                sum[find(C(i, j - 1))]++;
            if (map[i][j + 1] == oth)
                sum[find(C(i, j + 1))]++;

            if (ok)
            {
                sum[C(i, j)] = s;
                X = i, Y = j;
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    memset(sum, 0x3f3f3f3f, sizeof(sum));
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            map[i][j] = getchar();
            while (map[i][j] != 'X' && map[i][j] != 'O' && map[i][j] != '.')
                map[i][j] = getchar();
            father[C(i, j)] = C(i, j);
        }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            sum[C(i, j)] = 0;
            if (map[i - 1][j] == map[i][j] && map[i][j] != '.')
                father[find(C(i, j))] = find(C(i - 1, j));
            if (map[i][j - 1] == map[i][j] && map[i][j] != '.')
                father[find(C(i, j))] = find(C(i, j - 1));
            if (map[i - 1][j] == '.')
                sum[find(C(i, j))]++;
            if (map[i + 1][j] == '.')
                sum[find(C(i, j))]++;
            if (map[i][j + 1] == '.')
                sum[find(C(i, j))]++;
            if (map[i][j - 1] == '.')
                sum[find(C(i, j))]++;
        }
    push = 'X';
    pushX = pushO = 1;
    while (check_push(push))
    {
        map[X][Y] = push;
        if (map[X - 1][Y] == map[X][Y])
            father[find(C(X - 1, Y))] = find(C(X, Y));
        if (map[X + 1][Y] == map[X][Y])
            father[find(C(X + 1, Y))] = find(C(X, Y));
        if (map[X][Y - 1] == map[X][Y])
            father[find(C(X, Y - 1))] = find(C(X, Y));
        if (map[X][Y + 1] == map[X][Y])
            father[find(C(X, Y + 1))] = find(C(X, Y));

        char oth = (push == 'X' ? 'O' : 'X');
        if (map[X - 1][Y] == oth)
            sum[find(C(X - 1, Y))]--;
        if (map[X + 1][Y] == oth)
            sum[find(C(X + 1, Y))]--;
        if (map[X][Y - 1] == oth)
            sum[find(C(X, Y - 1))]--;
        if (map[X][Y + 1] == oth)
            sum[find(C(X, Y + 1))]--;

        printf("%d %d\n", X, Y);
        if (push == 'X')
            pushX = C(X, Y) + 1;
        else
            pushO = C(X, Y) + 1;
        push = (push == 'X' ? 'O' : 'X');
    }
    printf("-1 -1\n");
    return 0;
}
