/*
 * @lc app=leetcode.cn id=410 lang=cpp
 *
 * [410] 分割数组的最大值
 * 
 * 
 * 给定一个非负整数数组和一个整数 m，你需要将这个数组分成 m 个非空的连续子数组。设计一个算法使得这 m 个子数组各自和的最大值最小。

注意:
数组长度 n 满足以下条件:

1 ≤ n ≤ 1000
1 ≤ m ≤ min(50, n)
示例:

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/split-array-largest-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool ccheck(vector<int> &nums, int mid, int m)
    {
        long long sum = 0;
        int cnt = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (sum + nums[i] > mid)
            {
                cnt++;
                sum = nums[i];
            }
            else
            {
                sum += nums[i];
            }
        }
        if(cnt<=m) {
            return true;
        }
        return false;
    }
    int splitArray(vector<int> &nums, int m)
    {
        long long left = 0, right = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            right += nums[i];
            if (left < nums[i])
                left = nums[i];
        }
        while (left < right)
        {
            long long mid = left + (right - left) / 2;
            if (ccheck(nums, mid, m))
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        return left;
    }
    
};
// @lc code=end
class Solution1
{
public:
    int splitArray(vector<int> &nums, int m)
    {
        int n = nums.size();
        vector<long long> sub(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            sub[i + 1] = sub[i] + nums[i];
        }
        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, LLONG_MAX));
        dp[0][0] = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= min(m, i); j++)
            {
                for (int k = 0; k < i; k++)
                    dp[i][j] = min(dp[i][j], max(dp[k][j - 1], sub[i] - sub[k]));
            }
        }
        return (int)dp[n][m];
    }
};
int main()
{
    Solution s;
    vector<int> v = {7, 2, 5, 10, 8};
    int a = s.splitArray(v, 2);
    cout << a << endl;

    return 0;
}