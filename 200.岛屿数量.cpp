/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
int vvisit[10000][10000];
int cnt, m,n;
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
void dfs(vector<vector<char>>& grid, int i, int j) {
    vvisit[i][j] = 1;
    for(int k = 0; k < 4; k++) {
        int xx = i + dx[k];
        int yy = j + dy[k];
        if(xx < 0 || xx >= n || yy < 0 || yy >= m || vvisit[xx][yy]) continue;
        if(grid[xx][yy] == '1') {
            dfs(grid,xx,yy);
        }
    }
}
class Solution1 {
public:
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        if(n == 0) {
            return 0;
        }
        m = grid[0].size();
        cnt = 0;
        memset(vvisit, 0, sizeof(vvisit));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == '1' && !vvisit[i][j]) {
                    cnt ++;
                    dfs(grid, i,j);
                }
            }
        }
        return cnt;
    }
};
// stack
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        if(n == 0) {
            return 0;
        }
        m = grid[0].size();
        memset(vvisit, 0, sizeof(vvisit));
        cnt = 0;
        for(int i = 0; i < n; i ++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == '1' && !vvisit[i][j]) {
                    cnt++;
                    stack<pair<int,int>> s;
                    s.push(make_pair(i,j));
                    while(!s.empty()) {
                        auto p = s.top();
                        int x = p.first;
                        int y = p.second;
                        vvisit[x][y] = 1;
                        s.pop();
                        for(int k = 0; k < 4; k++) {
                            int xx = x + dx[k];
                            int yy = y + dy[k];
                            if(xx < 0 || xx >= n || yy < 0 || yy >= m || vvisit[xx][yy]) continue;
                            if(grid[xx][yy] == '1') {
                                s.push(make_pair(xx,yy));
                            }
                        }

                    }
                }
            }
        }
        return cnt;
    }
};
// @lc code=end

