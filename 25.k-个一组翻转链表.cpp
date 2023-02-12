/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
 */

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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (!head || k == 1)
            return head;
        ListNode *dummy = new ListNode(-1);
        ListNode *pre = dummy;
        ListNode *cur = head;
        dummy->next = head;
        for (int i = 1; cur; ++i)
        {
            if (i % k == 0)
            {
                pre = reverseList(pre, cur->next);
                cur = pre->next;
            }
            else
                cur = cur->next;
        }
        return dummy->next;
    }
    ListNode *reverseList(ListNode *pre, ListNode *next)
    {
        ListNode *last = pre->next;
        ListNode *cur = last->next;
        while (cur != next)
        {
            last->next = cur->next;
            cur->next = pre->next;
            pre->next = cur;
            cur = last->next;
        }
        return last;
    }
};
// @lc code=end
