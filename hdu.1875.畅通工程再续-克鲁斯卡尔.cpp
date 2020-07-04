// 克鲁斯卡尔算法，核心就是对边集合进行排序，从小到大开始选择，将点进行合并
#include <bits/stdc++.h>
using namespace std;
int N, M, i, j, k, d, a, b, cnt, fa[101], visit[101];
double ans;
// 点
struct point
{
    int x, y;
} ps[101];
// 边
struct ppair
{
    int x, y;
    double dis;
} ppairs[10100];
bool compare(ppair p1, ppair p2)
{
    return p1.dis < p2.dis;
}
// 并查集init
void init(int n)
{
    for (int i = 0; i <= n; i++)
    {
        fa[i] = i;
    }
}
// 并查集get
int get(int x)
{
    if (fa[x] != x)
    {
        fa[x] = get(fa[x]);
    }
    return fa[x];
}
// 并查集merge
void merge(int a, int b, double d)
{
    int aa = get(a);
    int bb = get(b);
    if (d == INT_MAX)
    {
        return;
    }
    if (aa != bb)
    {
        ans += d;
        fa[aa] = bb;
    }
}
double caldis(point p1, point p2)
{
    double r = sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
    if (r > 1000.0 || r < 10.0)
    {
        return INT_MAX;
    }
    return r;
}
int main()
{
    cin >> N;
    while (N--)
    {
        cin >> M;
        init(M);
        memset(visit, 0, sizeof(visit));
        cnt = 0;
        for (i = 0; i < M; i++)
        {
            cin >> ps[i].x >> ps[i].y;
            for (j = 0; j < i; j++)
            {
                ppairs[cnt].x = i;
                ppairs[cnt].y = j;
                ppairs[cnt].dis = caldis(ps[i], ps[j]);
                cnt++;
            }
        }
        sort(ppairs, ppairs + cnt, compare);
        ans = 0;
        for (i = 0; i < cnt; i++)
        {
            merge(ppairs[i].x, ppairs[i].y, ppairs[i].dis);
        }
        int numberFather = 0;
        for (i = 0; i < M; i++)
        {
            int fa = get(i);
            if (!visit[fa])
            {
                numberFather++;
                visit[fa] = 1;
            }
        }
        if (numberFather != 1)
        {
            cout << "oh!" << endl;
        }
        else
        {
            ans = ans * 100;
            cout << fixed << setprecision(1) << ans << endl;
        }
    }
    return 0;
}