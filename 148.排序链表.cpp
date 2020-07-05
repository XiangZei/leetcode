/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
 */
#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
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
class Solution
{
public:
    ListNode *merge(ListNode *l1, ListNode *l2)
    {
        ListNode dummy(0);
        ListNode *l3 = &dummy;
        while (l1 && l2)
        {
            if (l1->val <= l2->val)
            {
                l3->next = l1;
                l1 = l1->next;
                l3 = l3->next;
            }
            else
            {
                l3->next = l2;
                l2 = l2->next;
                l3 = l3->next;
            }
        }
        if (l1)
        {
            l3->next = l1;
        }
        if (l2)
        {
            l3->next = l2;
        }
        return dummy.next;
    }
    ListNode *sortList(ListNode *head)
    {
        if (!head || !head->next)
        {
            return head;
        }
        ListNode *slow = head;
        ListNode *fast = head->next;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *tmp = slow->next;
        slow->next = NULL;
        ListNode *l1 = sortList(head);
        ListNode *l2 = sortList(tmp);
        return merge(l1, l2);
    }
};
// @lc code=end

int main()
{
    ListNode *root = new ListNode(-1);
    ListNode *pt;
    pt = root;
    pt->next = new ListNode(5);
    pt = pt->next;
    pt->next = new ListNode(3);
    pt = pt->next;
    pt->next = new ListNode(4);
    pt = pt->next;
    pt->next = new ListNode(0);
    Solution s;
    ListNode *res = s.sortList(root);
    while (res)
    {
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;
    return 0;
}

// 使用非递归方式
class Solution1
{
public:
    ListNode *cut(ListNode *head, int n)
    {
        ListNode *p = head;
        while (--n && p)
        {
            p = p->next;
        }
        if (!p)
            return nullptr;
        ListNode *next = p->next;
        p->next = nullptr;
        return next;
    }

    ListNode *merge(ListNode *l1, ListNode *l2)
    {
        ListNode dummyHead(0);
        ListNode *p = &dummyHead;
        while (l1 && l2)
        {
            if (l1->val < l2->val)
            {
                p->next = l1;
                p = l1;
                l1 = l1->next;
            }
            else
            {
                p->next = l2;
                p = l2;
                l2 = l2->next;
            }
        }
        p->next = l1 ? l1 : l2;
        return dummyHead.next;
    }

    ListNode *sortList(ListNode *head)
    {
        ListNode dummyHead(0);
        dummyHead.next = head;
        ListNode *p = head;
        int length = 0;
        while (p)
        {
            ++length;
            p = p->next;
        }
        for (int size = 1; size < length; size <<= 1)
        {
            ListNode *cur = dummyHead.next;
            ListNode *tail = &dummyHead;
            while (cur)
            {
                ListNode *left = cur;
                ListNode *right = cut(left, size);
                cur = cut(right, size);
                tail->next = merge(left, right);
                while (tail->next)
                {
                    tail = tail->next;
                }
            }
        }
        return dummyHead.next;
    }
};