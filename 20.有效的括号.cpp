/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        stack<char> sta; 
        for (auto c: s) {
            if(c=='('||c=='['||c=='{') {
                sta.push(c);
            } else {
                if(sta.empty()) {
                    return false;
                }
                if(sta.top() == '(' && c == ')' ||
                sta.top() == '{' && c=='}' || 
                sta.top() == '[' && c == ']') {
                    sta.pop();
                } else {
                    return false;
                }
            }
        }    
        if (!sta.empty()) {
            return false;
        }   
        return true;
    }
};
// @lc code=end

