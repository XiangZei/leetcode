/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int numSquares(int n) {
        vector<int> squares;
        for(int i = 1; i < sqrt(n)+1; i++) {
            squares.push_back(i*i);
        }
        queue<int> q;
        q.push(n);
        int level = 0;
        while(!q.empty()) {
            level += 1;
            queue<int> next_q;
            while(!q.empty()) {
                int remainder = q.front();
                q.pop();
                for(auto square : squares) {
                    if(remainder == square) {
                        return level;
                    }else if(remainder < square) {
                        break;
                    } else {
                        next_q.push(remainder - square);
                    }
                }
            }
            q = next_q;
        }
        return level;
    }
};
// @lc code=end

