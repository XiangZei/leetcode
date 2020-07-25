/*
 * @lc app=leetcode.cn id=315 lang=cpp
 *
 * [315] 计算右侧小于当前元素的个数
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());
        map<int,int> m;
        int cnt = 0;
        for (int i:s) {
            m[i] = ++cnt;
        }
        vector<int> v(cnt+1, 0);
        vector<int> res(nums.size(), 0);
        for(int i = nums.size()-1; i >= 0; i--) {
            res[i] = v[m[nums[i]]-1];
            for (int j = m[nums[i]]; j <= cnt; j++)
            {
                v[j]++;
            }
        }
        return res;
    }
};
// @lc code=end
/*
5 2 6 1


0 1 2 3 4
  | | | |
  1 2 5 6

*/

int main(){
    Solution s;
    vector<int> vv = {5, 2, 6, 1};
    vector<int> v = s.countSmaller(vv);
    for (int i:v) {
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}
