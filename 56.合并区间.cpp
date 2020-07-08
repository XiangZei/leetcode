/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int i = 0, n = intervals.size(),j,t;
        vector<vector<int>> res;
        for(;i<n;) {
            t = intervals[i][1];
            j = i+1;
            for(;j<n && intervals[j][0] <= t;j++) {
                t = max(t, intervals[j][1]);
            }
            res.push_back({intervals[i][0], t});
            i=j;
        }
        return res;
    }
};
// @lc code=end


class SolutionUsePriority
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());
        priority_queue<int> pq;
        vector<vector<int>> res;
        int pre = -1, i = 0, n = intervals.size(), cur, biggest = -1;
        while (i < n || !pq.empty())
        {
            if (i < n)
            {
                cur = intervals[i][0];
                if (pre != -1 && cur != pre)
                {
                    biggest = pq.top();
                    pq.push(intervals[i][1]);
                }
                else
                {
                    pq.push(intervals[i][1]);
                }
            }
            if (i >= n)
            {
                biggest = pq.top();
                res.push_back({pre, biggest});
                break;
            }
            if (biggest != -1 && biggest < cur && pre <= biggest)
            {
                res.push_back({pre, biggest});
                pre = cur;
            }
            if (pre == -1)
            {
                pre = cur;
            }
            i++;
        }
        return res;
    }
};
