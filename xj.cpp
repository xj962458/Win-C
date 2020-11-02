#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

const int INF = 0x3f3f3f3f;

int solve();

int main()
{
#ifdef Yinku
    freopen("Yinku.in", "r", stdin);
#endif // Yinku
    solve();
}

int n;
char g[605][605];

inline int id(int i, int j)
{
    return (i - 1) * n + j;
}

inline void aid(int f, int &i, int &j)
{
    j = f % n;
    if (j == 0)
        j = n;
    i = (f - j) / n + 1;
    return;
}

int fa[360005];
//并查集
int qi[360005];
//id对应的位置的气，只有并查集的根保存正确的气

queue<int> Q[2];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

char col[2] = {'X', 'O'};

int find(int x)
{
    int r = x;
    while (fa[r] != r)
    {
        r = fa[r];
    }
    while (x != r)
    {
        int k = fa[x];
        fa[x] = r;
        x = k;
    }
    return r;
}

void merge(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y)
        return;
    fa[y] = x;
    return;
}

void Exit()
{
    puts("-1 -1");
    exit(0);
}

inline void Show()
{
    cout << "G:" << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << g[i] + 1 << endl;
    }
    cout << endl;

    /*cout<<"FA:"<<endl;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            printf("%2d ",fa[id(i,j)]);
        }
        cout<<endl;
    }
    cout<<endl;*/

    cout << "QI:" << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            qi[id(i, j)] = qi[find(id(i, j))];
            printf("%2d ", qi[id(i, j)]);
        }
        cout << endl;
    }
    cout << endl;
}

bool RollBackOtherColor(int ox, int oy, int th, int ot)
{
    int need = 0;
    for (int k = 0; k < 4; k++)
    {
        int x = ox + dx[k];
        int y = oy + dy[k];
        if (x >= 1 && x <= n && y >= 1 && y <= n && g[x][y] == col[ot])
            if (qi[find(id(x, y))] <= 0)
            {
                need = 1;
                break;
            }
    }

    if (!need)
        return 0;

    for (int k = 0; k < 4; k++)
    {
        int x = ox + dx[k];
        int y = oy + dy[k];
        if (x >= 1 && x <= n && y >= 1 && y <= n && g[x][y] != '.')
            qi[find(id(x, y))]++;
    }

    return 1;
}

bool RollBackThisColor(int ox, int oy, int th, int ot, int Qi)
{
    int newQi = Qi;
    vector<int> visited;
    for (int k = 0; k < 4; k++)
    {
        int x = ox + dx[k];
        int y = oy + dy[k];
        /*这样同一个连通块的气被重复计算了
        if(x>=1&&x<=n&&y>=1&&y<=n&&g[x][y]==col[th])
            newQi+=qi[find(id(x,y))];
        */
        if (x >= 1 && x <= n && y >= 1 && y <= n && g[x][y] == col[th])
        {
            int r = find(id(x, y));
            int s = visited.size();
            bool Visited = 0;
            for (int i = 0; i < s; i++)
            {
                if (visited[i] == r)
                {
                    Visited = 1;
                    break;
                }
            }
            if (Visited)
                continue;
            visited.push_back(r);
            newQi += qi[r];
        }
    }

    /*cout<<"newQi="<<newQi<<endl;
    cout<<"Qi="<<Qi<<endl;*/

    if (newQi > 0)
    {
        //还有气，落子
        g[ox][oy] = col[th];
        for (int k = 0; k < 4; k++)
        {
            int x = ox + dx[k];
            int y = oy + dy[k];
            if (x >= 1 && x <= n && y >= 1 && y <= n && g[x][y] == col[th])
                merge(id(ox, oy), id(x, y));
        }
        qi[find(id(ox, oy))] = newQi;
        printf("%d %d\n", ox, oy);
        //Show();
        return 0;
    }

    for (int k = 0; k < 4; k++)
    {
        int x = ox + dx[k];
        int y = oy + dy[k];
        if (x >= 1 && x <= n && y >= 1 && y <= n && g[x][y] != '.')
            qi[find(id(x, y))]++;
    }

    return 1;
}

int Move(int th, int ot)
{
    while (1)
    {
        //Show();
        //交替下
        while (1)
        {
            //重复下同一种棋，防爆栈
            if (Q[th].empty())
            {
                Exit();
            }

            int f = Q[th].front();
            Q[th].pop();

            int x, y;
            aid(f, x, y);

            //cout<<"color="<<col[th]<<" ("<<x<<","<<y<<")"<<endl;

            //已经被落子，重来
            if (g[x][y] != '.')
            {
                //cout<<"RollBack beacuse there is already a piece"<<endl;
                continue;
            }

            int Qi = 0;

            for (int k = 0; k < 4; k++)
            {
                int xx = x + dx[k];
                int yy = y + dy[k];
                if (xx >= 1 && xx <= n && yy >= 1 && yy <= n)
                {
                    if (g[xx][yy] != '.')
                        qi[find(id(xx, yy))]--;
                    else
                        Qi++;
                }
            }

            //Show();

            if (RollBackOtherColor(x, y, th, ot))
            {
                //把另一种颜色提子了，回滚重来
                //cout<<"RollBack by other color"<<endl;
                continue;
            }

            //那么下这步棋至少不会把另一种棋提子了，接下来看看是不是堵死自己
            if (RollBackThisColor(x, y, th, ot, Qi))
            {
                //把自己提子了，回滚重来
                //cout<<"RollBack by this color"<<endl;
                continue;
            }

            //已经被上函数落子
            break;
        }
        //颜色交换
        swap(th, ot);
    }
    return 0;
}

void Init()
{
    //初始化并查集
    for (int i = 1; i <= n * n; i++)
        fa[i] = i;

    //用并查集连通各部分，每个点和他右边、下边的点连接就可以了
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (g[i][j] == '.')
                continue;
            if (i + 1 <= n && g[i][j] == g[i + 1][j])
                merge(id(i, j), id(i + 1, j));
            if (j + 1 <= n && g[i][j] == g[i][j + 1])
                merge(id(i, j), id(i, j + 1));
        }
    }

    //统计气
    memset(qi, 0, sizeof(qi));

    //每个空位对各个棋子的贡献
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (g[i][j] != '.')
                continue;
            //插入待使用队列
            Q[0].push(id(i, j));
            Q[1].push(id(i, j));

            for (int k = 0; k < 4; k++)
            {
                int x = i + dx[k];
                int y = j + dy[k];
                if (x >= 1 && x <= n && y >= 1 && y <= n && g[x][y] != '.')
                    qi[find(id(x, y))]++;
            }
        }
    }
    return;
}

int solve()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", g[i] + 1);
    }
    Init();
    Move(0, 1);
    //先下黑棋

    return 0;
}