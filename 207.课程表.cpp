/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 * 你这个学期必须选修 numCourse 门课程，记为 0 到 numCourse-1 。
 * 在选修某些课程之前需要一些先修课程。 例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示他们：[0,1]
 * 给定课程总量以及它们的先决条件，请你判断是否可能完成所有课程的学习
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
vector<int> adjacentAry[100001];
int in[100001];
class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        for (int i = 0; i <= numCourses; i++)
        {
            adjacentAry[i].clear();
        }
        memset(in, 0, sizeof(in));

        for (auto v : prerequisites)
        {
            adjacentAry[v[1]].push_back(v[0]);
            in[v[0]]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++)
        {
            if (in[i] == 0)
            {
                q.push(i);
            }
        }
        int cnt = 0;
        while (!q.empty())
        {
            int t = q.front();
            q.pop();
            cnt++;
            for (int j = 0; j < adjacentAry[t].size(); j++)
            {
                int to = adjacentAry[t][j];
                in[to]--;
                if (in[to] == 0)
                {
                    q.push(to);
                }
            }
        }
        if (cnt < numCourses)
        {
            return false;
        }
        return true;
    }
};
// @lc code=end

int main()
{
    Solution s;
    vector<vector<int>> v;
    cout<<s.canFinish(1, v)<<endl;
    return 0;
}