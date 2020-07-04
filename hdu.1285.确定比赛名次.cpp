#include <bits/stdc++.h>
using namespace std;
int N, M, i, j, k, G[501][501], a, b, c, in[501];
struct nnode
{
    int index;
    nnode(int idx) : index(idx) {}
    friend bool operator<(nnode a, nnode b)
    {
        return a.index > b.index;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    while (cin >> N >> M)
    {
        memset(G, 0, sizeof(G));
        memset(in, 0, sizeof(in));
        while (M--)
        {
            cin >> a >> b;
            G[a][b]++;
            in[b]++;
        }
        // 优化为 o(n^2)
        priority_queue<nnode> pq;
        for (i = 1; i <= N; i++)
        {
            if (in[i] == 0)
            {
                pq.push(nnode(i));
            }
        }
        int cnt = 0;
        while (!pq.empty())
        {
            nnode t = pq.top();
            pq.pop();
            cnt++;
            cout << t.index;
            if (cnt != N)
            {
                cout << " ";
            }
            else
            {
                cout << endl;
            }
            for (i = 1; i <= N; i++)
            {
                if (i == t.index)
                    continue;
                if (G[t.index][i])
                {
                    in[i]-=G[t.index][i];
                    if (in[i] == 0)
                    {
                        pq.push(nnode(i));
                    }
                }
            }
        }
    }
    return 0;
}