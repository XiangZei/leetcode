/*
 * @lc app=leetcode.cn id=174 lang=cpp
 *
 * [174] 地下城游戏
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int calculateMinimumHP(vector<vector<int>> &dungeon)
    {
        int n = dungeon.size();
        int m = dungeon[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                if (i == n - 1 && j == m - 1)
                {
                    dp[i][j] = max(1, 1 - dungeon[i][j]);
                }
                else if (i == n - 1)
                {
                    dp[i][j] = max(1, dp[i][j + 1] - dungeon[i][j]);
                }
                else if (j == m - 1)
                {
                    dp[i][j] = max(1, dp[i + 1][j] - dungeon[i][j]);
                }
                else
                {
                    dp[i][j] = max(1, min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j]);
                }
            }
        }
        return dp[0][0];
    }
};
// @lc code=end
