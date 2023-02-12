/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int m, int n)
    {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *p = dummy;

        for (int i = 0; i < m - 1; i++)
            p = p->next;
        ListNode *cur = p->next;
        for (int i = 0; i < n - m; i++)
        {
            ListNode *t = cur->next;
            cur->next = t->next;
            t->next = p->next;
            p->next = t;
        }
        return dummy->next;
    }
};
// @lc code=end
