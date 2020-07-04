/*
 * @lc app=leetcode.cn id=1334 lang=cpp
 *
 * [1334] 阈值距离内邻居最少的城市
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
#define MA 10001
int G[101][101], dist[101], last[101];
int a,b,c;
class Solution
{
public:
    int findTheCity(int n, vector<vector<int> > &edges, int d)
    {
        // 贝尔曼福德 
        int sz = edges.size();
        for(int i = 0; i < sz; i++) {
            a = edges[i][0]; b = edges[i][1]; c = edges[i][2];
            vector<int> tmp;
            tmp.push_back(b); tmp.push_back(a); tmp.push_back(c); 
            edges.push_back(tmp);
        }
        int ccount = INT_MAX;
        int miIdx = 0;
        for(int i = n-1; i >= 0; i--) {
            for(int  j = 0; j < n; j++) {
                dist[j] = MA;
            }
            dist[i] = 0;
            for(int j = 0; j < n-1; j++) {
                for(int k = 0; k < edges.size(); k++) {
                    if (dist[edges[k][1]] > (dist[edges[k][0]] + edges[k][2])) {
                        dist[edges[k][1]] = dist[edges[k][0]] + edges[k][2];
                    }
                }
            }
            int count = 0;
            for(int j = 0; j < n; j++) {
                if(j==i) continue;
                if(dist[j] <= d) {
                    count++;
                }
            }
            if(count < ccount) {
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
    cout<<s.findTheCity(4,vet,4)<<endl;
    return 0;
}