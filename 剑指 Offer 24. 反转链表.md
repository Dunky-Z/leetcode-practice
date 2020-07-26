---
title: 剑指 Offer 24. 反转链表
tags: LeetCode,链表
notebook: a - 001 | ITabc
---

定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点。

示例:
```cpp
输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL
```

限制：`0 <= 节点个数 <= 5000`

---

Solution 1:

```cpp
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
    ListNode* reverseList(ListNode* head) 
    {
        ListNode* pre = NULL;
        ListNode* cur = head;
		while (cur != NULL)
		{
            ListNode* next = cur->next;
			cur->next = pre;
			pre = cur;
			cur = next;
		}
		return pre;
    }
};
```
