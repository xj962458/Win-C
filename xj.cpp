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
//���鼯
int qi[360005];
//id��Ӧ��λ�õ�����ֻ�в��鼯�ĸ�������ȷ����

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
        /*����ͬһ����ͨ��������ظ�������
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
        //������������
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
        //������
        while (1)
        {
            //�ظ���ͬһ���壬����ջ
            if (Q[th].empty())
            {
                Exit();
            }

            int f = Q[th].front();
            Q[th].pop();

            int x, y;
            aid(f, x, y);

            //cout<<"color="<<col[th]<<" ("<<x<<","<<y<<")"<<endl;

            //�Ѿ������ӣ�����
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
                //����һ����ɫ�����ˣ��ع�����
                //cout<<"RollBack by other color"<<endl;
                continue;
            }

            //��ô���ⲽ�����ٲ������һ���������ˣ������������ǲ��Ƕ����Լ�
            if (RollBackThisColor(x, y, th, ot, Qi))
            {
                //���Լ������ˣ��ع�����
                //cout<<"RollBack by this color"<<endl;
                continue;
            }

            //�Ѿ����Ϻ�������
            break;
        }
        //��ɫ����
        swap(th, ot);
    }
    return 0;
}

void Init()
{
    //��ʼ�����鼯
    for (int i = 1; i <= n * n; i++)
        fa[i] = i;

    //�ò��鼯��ͨ�����֣�ÿ��������ұߡ��±ߵĵ����ӾͿ�����
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

    //ͳ����
    memset(qi, 0, sizeof(qi));

    //ÿ����λ�Ը������ӵĹ���
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (g[i][j] != '.')
                continue;
            //�����ʹ�ö���
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
    //���º���

    return 0;
}