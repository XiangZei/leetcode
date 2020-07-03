/*
 * @lc app=leetcode.cn id=1334 lang=cpp
 *
 * [1334] 阈值距离内邻居最少的城市
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
#define MA 10001
int G[101][101], vis[101], dist[101];
class Solution
{
public:
    int findTheCity(int n, vector<vector<int>> &edges, int d)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                G[i][j] = MA;
            }
        }
        for (int i = 0; i < edges.size(); i++)
        {
            vector<int> e = edges[i];
            G[e[0]][e[1]] = e[2];
            G[e[1]][e[0]] = e[2];
        }
        int ccount = MA;
        int miIdx = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            memset(vis, 0, sizeof(vis));
            for (int j = 0; j < n; j++)
            {
                dist[j] = G[i][j];
            }
            dist[i] = 0;
            vis[i] = 1;
            int count = 0;
            for (int j = 0; j < n - 1; j++)
            {
                int ddd = MA;
                int idx = 0;
                for (int k = 0; k < n; k++)
                {
                    if (!vis[k] && dist[k] < ddd)
                    {
                        ddd = dist[k];
                        idx = k;
                    }
                }
                
                vis[idx] = 1;
                for (int k = 0; k < n; k++)
                {
                    if (!vis[k] && dist[k] > (G[idx][k] + dist[idx]))
                    {
                        dist[k] = G[idx][k] + dist[idx];
                    }
                }
            }
            for (int j = 0; j < n; j++)
            {
                if (j == i)
                    continue;
                if (dist[j] <= d)
                {
                    count++;
                }
            }
            if (count < ccount)
            {
                ccount = count;
                miIdx = i;
            }
        }
        return miIdx;
    }
};
// @lc code=end

int main()
{
    return 0;
}