#include <bits/stdc++.h>
using namespace std;
const int N = 666;
int n;
#define F(i) for (int i = 1; i <= n; i++)
struct Pos
{ //��ʾһ��λ�ã������˼��������
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
    { //ֻ�Ƿ�����map
        return make_pair(x, y) < make_pair(o.x, o.y);
    }
    Pos operator++()
    { //��һ��λ��
        y++;
        if (y > n)
        {
            y = 1;
            x++;
        }
        return *this;
    }
    operator bool() const
    { //ת��Ϊbool�Ľ���Ǹ�λ���Ƿ���������
        return x >= 1 && x <= n && y >= 1 && y <= n;
    }
};
#define Fp(i) for (Pos i = Pos(1, 1); i; ++i)
const Pos d[4] = {Pos(1, 0), Pos(-1, 0), Pos(0, 1), Pos(0, -1)}; //�ĸ�����
#define Fc(i) for (int i = 0; i < 4; i++)
template <class T>
struct Board
{ //�ʴɶ�ά�����ȡ����Posֱ�Ӵ�ȡ
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
{ //����λ������
    WALL = -1,
    BLACK = 0,
    WHITE = 1,
    EMPTY = 2
};

Board<Pos> fa;    //���鼯�ĸ�������
Board<int> qi;    //��ͨ���������¼�ڸ��ڵ��qi��
Board<int> color; //����ÿ���������

void init()
{ //��ʼ������
    Fp(p) color[p] = EMPTY;
    Fp(p) qi[p] = 0;
    F(i)
    color[i][0] = color[i][n + 1] = color[0][i] = color[n + 1][i] = WALL;
}

Pos find(Pos x)
{ //���鼯
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

bool merge(Pos x, Pos y)
{ //���鼯
    x = find(x), y = find(y);
    if (x == y)
        return false;
    qi[y] += qi[x];
    fa[x] = y;
    return true;
}

bool setgo(Pos p, TYPE c)
{ //��pλ�÷�����ɫΪc������
    if (color[p] != EMPTY)
        return false; //�Ѿ�������
    color[p] = c;
    fa[p] = p, qi[p] = 0; //�½�����
    Fc(i)
    {
        Pos now = p + d[i];
        if (color[now] == EMPTY)
        {
            qi[p]++; //����Ϊ��,��+1
        }
        else if (color[now] != WALL)
        {
            qi[find(now)]--; //������ͨ����-1
        }
    }
    Fc(i)
    {
        Pos now = p + d[i];
        if (color[now] == c)
            merge(p, now); //�ϲ���ͨ��
    }
    return true;
}

bool canset(Pos p, TYPE c)
{ //����Ƿ�����pλ�÷�����ɫΪc������
    if (color[p] != EMPTY)
        return false;   //ֻ�ܷ��ڿ�λ
                        //	printf("Trying (%d,%d) for %d\n",p.x,p.y,c);
    map<Pos, int> eff;  //��¼����������ӣ������Χ����ͨ����ٵ�����
    bool hasqi = false; //�������ӷ��º��Ƿ�����
    Fc(i)
    {
        Pos now = p + d[i];
        if (color[now] == EMPTY)
        {
            hasqi = true; //���ӱ��������
        }
        else if (color[now] != WALL)
        {
            eff[find(now)]++; //����ͨ��������-1
        }
    }
    for (map<Pos, int>::iterator it = eff.begin(); it != eff.end(); it++)
    {
        int nowqi = qi[find(it->first)] - it->second; //����ͨ��ʣ������
                                                      //		printf("Eff (%d,%d) [qi=%d]\n",it->first.x,it->first.y,nowqi);
        if (color[it->first] != c && nowqi == 0)
            return false; //�Է����ӱ�������
        else if (color[it->first] == c && nowqi != 0)
            hasqi = true; //��������������
    }
    return hasqi; //�����������������Ƿ�������һ����
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
        //��һ��ʼ������
        if (ch == 'X')
            setgo(p, BLACK);
        else if (ch == 'O')
            setgo(p, WHITE);
    }
    TYPE player = BLACK; //����
    Pos trying[2];       //���
    trying[BLACK] = Pos(1, 1);
    trying[WHITE] = Pos(1, 1);
    while (true)
    {
        Pos &nt = trying[player];
        while (nt && !canset(nt, player))
            ++nt; //�ӱ�������
        if (!nt)
        { //����Ѿ����������ˣ�˵��û�кϷ�λ���ܷ���
            printf("%d %d", -1, -1);
            break; //Game Over
        }
        assert(setgo(nt, player));
        printf("%d %d\n", nt.x, nt.y);
        //		if(nt.x>4)debug();
        //�����
        if (player == BLACK)
            player = WHITE;
        else
            player = BLACK;
    }
    return 0;
}