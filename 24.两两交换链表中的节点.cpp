/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 */
#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head||!head->next) {
            return head;
        }
        ListNode* fir = head;
        ListNode* sec = head->next;
        fir->next = swapPairs(sec->next);
        sec->next = fir;
        return sec;
    }
};
// @lc code=end
int main() {
    ListNode* l1 = new ListNode(1);
    ListNode* fir = l1;
    l1->next = new ListNode(2);
    l1 = l1->next;
    l1->next = new ListNode(3);
    l1 = l1->next;
    l1->next = new ListNode(4);
    l1 = l1->next;
    l1->next = new ListNode(5);
    Solution s;
    ListNode* tt = fir;
    while(tt) {
        cout<<tt->val<<" ";
        tt = tt->next;
    }
    cout<<endl;
    ListNode* res = s.swapPairs(fir);
    while(res) {
        cout<<res->val<<" ";
        res = res->next;
    }
    cout<<endl;
}
