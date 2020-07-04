// 克鲁斯卡尔算法，核心就是对边集合进行排序，从小到大开始选择，将点进行合并
#include <bits/stdc++.h>
using namespace std;
int N, M, i, j, k, d, a, b, cnt, fa[101], visit[101];
double ans, G[101][101], dist[101];
// 点
struct point
{
    int x, y;
} ps[101];
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
        for (i = 0; i < M; i++)
        {
            for (j = 0; j < M; j++)
            {
                G[i][j] = INT_MAX;
            }
        }
        for (i = 0; i < M; i++)
        {
            cin >> ps[i].x >> ps[i].y;
            for (j = 0; j < i; j++)
            {
                G[i][j] = G[j][i] = caldis(ps[i], ps[j]);
            }
        }
        memset(visit, 0, sizeof(visit));
        for (i = 0; i < M; i++)
        {
            dist[i] = INT_MAX;
        }
        ans = 0;
        dist[0] = 0;
        bool canfind = true;
        for (i = 0; i < M; i++)
        {
            double midis = INT_MAX;
            int miidx = 0;
            for (j = 0; j < M; j++)
            {
                if (!visit[j] && dist[j] < midis)
                {
                    midis = dist[j];
                    miidx = j;
                }
            }
            if (midis == INT_MAX)
            {
                canfind = false;
            }
            visit[miidx] = 1;
            ans += midis;
            for (j = 0; j < M; j++)
            {
                if (!visit[j] && G[miidx][j] < dist[j])
                {
                    dist[j] = G[miidx][j];
                }
            }
        }
        if (canfind)
        {
            ans *= 100;
            cout << fixed << setprecision(1) << ans << endl;
        }
        else
        {
            cout << "oh!" << endl;
        }
    }
    return 0;
}