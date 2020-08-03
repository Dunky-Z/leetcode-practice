---
title: 剑指 Offer 25. 合并两个排序的链表
tags: LeetCode
notebook: a - 001 | ITabc
---
输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然是递增排序的。

示例1：
```cpp
输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4
```
限制：`0 <= 链表长度 <= 1000`


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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
    {
        if(l1 == nullptr)
        {
            return l2;
        }
        else if(l2 == nullptr)
        {
            return l1;
        }
        else if(l1->val < l2->val)
        {
            l1->next = mergeTwoLists(l1->next,l2);
            return l1;
        }
        else
        {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;    
        }
        
    }
};
```

Solution 2:

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1), *cur = dummy;
        while(l1 && l2)
        {        
            if (l1 == nullptr) 
            {
                return l2;
            } else if (l2 == nullptr) 
            {
                return l1;
            }
            else if(l1->val< l2->val)
            {
                cur->next = l1;
                l1 = l1->next;
            }
            else
            {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        cur->next = l1 ? l1 : l2;
        return dummy->next;
        
    }
};
```