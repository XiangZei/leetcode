/*
 * @lc app=leetcode.cn id=162 lang=cpp
 *
 * [162] 寻找峰值
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n, mid;
        while(left < right) {
            mid = left + (right-left)/2;
            if(nums[mid]<nums[mid+1]) left = mid+1;
            else right = mid;
        }
        return left;
    }
};
// @lc code=end

