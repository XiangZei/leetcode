#include <bits/stdc++.h>
using namespace std;
int N, M, i, j, k, G[501][501], a, b, c, in[501];
int main()
{
    // 超时分析： 每次寻找入度为零的点的时候，都需要从头遍历所有节点的入度O(N)。并且在更新相邻节点的入度时也是O(n)的
    // 综合复杂度是 O(n^3)
    ios::sync_with_stdio(false);
    while (cin >> N >> M)
    {
        vector<int> res;
        res.clear();
        memset(G, 0, sizeof(G));
        memset(in, 0, sizeof(in));
        while (M--)
        {
            cin >> a >> b;
            G[a][b]++;
            in[b]++;
        }
        int cnt = 0;
        while (cnt < N)
        {
            for (i = 1; i <= N; i++)
            {
                // 入度为零
                if (in[i] == 0)
                {
                    cnt++;
                    in[i]--;
                    res.push_back(i);
                    for (j = 1; j <= N; j++)
                    {
                        if (j == i)
                            continue;
                        if (G[i][j])
                        {
                            in[j]-=G[i][j];
                        }
                    }
                }
            }
        }
        for (i = 0; i < N; i++)
        {
            if (i == N - 1)
            {
                cout << res[i] <<endl;
            }
            else
            {
                cout << res[i] << " ";
            }
        }
    }
    return 0;
}