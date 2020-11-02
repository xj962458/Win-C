#include <bits/stdc++.h>
using namespace std;
const int N = 666;
int n;
#define F(i) for (int i = 1; i <= n; i++)
struct Pos
{ //表示一个位置，重载了几个运算符
    int x, y;
    Pos(int _x, int _y)
    {
        x = _x, y = _y;
    }
    Pos()
    {
    }
    Pos operator+(const Pos o) const
    {
        return Pos(x + o.x, y + o.y);
    }
    bool operator==(const Pos o) const
    {
        return x == o.x && y == o.y;
    }
    bool operator<(const Pos o) const
    { //只是方便用map
        return make_pair(x, y) < make_pair(o.x, o.y);
    }
    Pos operator++()
    { //下一个位置
        y++;
        if (y > n)
        {
            y = 1;
            x++;
        }
        return *this;
    }
    operator bool() const
    { //转化为bool的结果是该位置是否在棋盘内
        return x >= 1 && x <= n && y >= 1 && y <= n;
    }
};
#define Fp(i) for (Pos i = Pos(1, 1); i; ++i)
const Pos d[4] = {Pos(1, 0), Pos(-1, 0), Pos(0, 1), Pos(0, -1)}; //四个方向
#define Fc(i) for (int i = 0; i < 4; i++)
template <class T>
struct Board
{ //资瓷二维数组存取与用Pos直接存取
    T dat[N][N];
    T &operator[](const Pos o)
    {
        return dat[o.x][o.y];
    }
    T *operator[](const int o)
    {
        return dat[o];
    }
};

enum TYPE
{ //棋盘位置种类
    WALL = -1,
    BLACK = 0,
    WHITE = 1,
    EMPTY = 2
};

Board<Pos> fa;    //并查集的父亲数组
Board<int> qi;    //联通块的气数记录在根节点的qi上
Board<int> color; //棋盘每个点的种类

void init()
{ //初始化棋盘
    Fp(p) color[p] = EMPTY;
    Fp(p) qi[p] = 0;
    F(i)
    color[i][0] = color[i][n + 1] = color[0][i] = color[n + 1][i] = WALL;
}

Pos find(Pos x)
{ //并查集
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

bool merge(Pos x, Pos y)
{ //并查集
    x = find(x), y = find(y);
    if (x == y)
        return false;
    qi[y] += qi[x];
    fa[x] = y;
    return true;
}

bool setgo(Pos p, TYPE c)
{ //在p位置放置颜色为c的棋子
    if (color[p] != EMPTY)
        return false; //已经有棋子
    color[p] = c;
    fa[p] = p, qi[p] = 0; //新建集合
    Fc(i)
    {
        Pos now = p + d[i];
        if (color[now] == EMPTY)
        {
            qi[p]++; //相邻为空,气+1
        }
        else if (color[now] != WALL)
        {
            qi[find(now)]--; //相邻联通块气-1
        }
    }
    Fc(i)
    {
        Pos now = p + d[i];
        if (color[now] == c)
            merge(p, now); //合并联通块
    }
    return true;
}

bool canset(Pos p, TYPE c)
{ //检查是否能在p位置放置颜色为c的棋子
    if (color[p] != EMPTY)
        return false;   //只能放在空位
                        //	printf("Trying (%d,%d) for %d\n",p.x,p.y,c);
    map<Pos, int> eff;  //记录如果放了棋子，会给周围的联通块减少的气数
    bool hasqi = false; //己方棋子放下后是否还有气
    Fc(i)
    {
        Pos now = p + d[i];
        if (color[now] == EMPTY)
        {
            hasqi = true; //棋子本身就有气
        }
        else if (color[now] != WALL)
        {
            eff[find(now)]++; //该联通块气数将-1
        }
    }
    for (map<Pos, int>::iterator it = eff.begin(); it != eff.end(); it++)
    {
        int nowqi = qi[find(it->first)] - it->second; //该联通块剩余气数
                                                      //		printf("Eff (%d,%d) [qi=%d]\n",it->first.x,it->first.y,nowqi);
        if (color[it->first] != c && nowqi == 0)
            return false; //对方棋子被堵死了
        else if (color[it->first] == c && nowqi != 0)
            hasqi = true; //己方棋子有气了
    }
    return hasqi; //己方棋子连起来后是否至少有一口气
}
/*
const char db[]={'X','O','.'}; 
void debug(){
	F(i){
		F(j)printf("%d",qi[find(Pos(i,j))]);
		printf("\n");
	}
	F(i){
		F(j)printf("%c",db[color[i][j]]);
		printf("\n");
	}
	getchar();
}
*/
int main()
{
    scanf("%d", &n);
    init();
    Fp(p)
    {
        char ch;
        do
        {
            ch = getchar();
        } while (ch != 'O' && ch != 'X' && ch != '.');
        //放一开始的棋子
        if (ch == 'X')
            setgo(p, BLACK);
        else if (ch == 'O')
            setgo(p, WHITE);
    }
    TYPE player = BLACK; //黑先
    Pos trying[2];       //标记
    trying[BLACK] = Pos(1, 1);
    trying[WHITE] = Pos(1, 1);
    while (true)
    {
        Pos &nt = trying[player];
        while (nt && !canset(nt, player))
            ++nt; //从标记向后尝试
        if (!nt)
        { //标记已经在棋盘外了，说明没有合法位置能放了
            printf("%d %d", -1, -1);
            break; //Game Over
        }
        assert(setgo(nt, player));
        printf("%d %d\n", nt.x, nt.y);
        //		if(nt.x>4)debug();
        //换玩家
        if (player == BLACK)
            player = WHITE;
        else
            player = BLACK;
    }
    return 0;
}