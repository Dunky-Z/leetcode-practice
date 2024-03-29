/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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
    bool isPalindrome(ListNode *head)
    {
        ListNode *t = head;
        stack<int> stk;

        while (t != NULL)
        {
            stk.push(t->val);
            t = t->next;
        }

        while (head != NULL)
        {
            if (stk.top() != head->val)
                return false;
            else
            {
                stk.pop();
                head = head->next;
            }
        }
        return true;
    }
};
// @lc code=end
