/*
 * @lc app=leetcode.cn id=1334 lang=cpp
 *
 * [1334] 阈值距离内邻居最少的城市
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
#define MA 10001
int G[101][101], dist[101], last[101], vis[101];
int a, b, c;
class Solution
{
public:
    int findTheCity(int n, vector<vector<int> > &edges, int d)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                G[i][j] = MA;
            }
        }
        // spfa
        int sz = edges.size();
        for (int i = 0; i < sz; i++)
        {
            vector<int> e = edges[i];
            G[e[0]][e[1]] = e[2];
            G[e[1]][e[0]] = e[2];
        }
        int ccount = INT_MAX;
        int miIdx = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            queue<int> q;
            for (int j = 0; j < n; j++)
            {
                dist[j] = MA;
            }
            memset(vis, 0, sizeof(vis));
            dist[i] = 0;
            q.push(i);
            vis[i] = 1;
            while (!q.empty())
            {
                int startv = q.front();
                q.pop();
                vis[startv] = 0;
                for (int k = 0; k < n; k++)
                {
                    if (dist[k] > (dist[startv] + G[startv][k]))
                    {
                        dist[k] = (dist[startv] + G[startv][k]);
                        if (!vis[k])
                        {
                            q.push(k);
                            vis[k] = 1;
                        }
                    }
                }
            }
            int count = 0;
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
    Solution s;
    vector<vector<int> > vet;
    vector<int> t1;
    t1.push_back(0);
    t1.push_back(1);
    t1.push_back(3);
    vector<int> t2;
    t2.push_back(1);
    t2.push_back(2);
    t2.push_back(1);
    vector<int> t3;
    t3.push_back(1);
    t3.push_back(3);
    t3.push_back(4);
    vector<int> t4;
    t4.push_back(2);
    t4.push_back(3);
    t4.push_back(1);
    vet.push_back(t1);
    vet.push_back(t2);
    vet.push_back(t3);
    vet.push_back(t4);
    cout << s.findTheCity(4, vet, 4) << endl;
    return 0;
}