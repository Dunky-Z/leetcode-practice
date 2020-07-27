---
title: 剑指 Offer 22. 链表中倒数第k个节点
tags: LeetCode,链表
notebook: a - 001 | ITabc
---
输入一个链表，输出该链表中倒数第k个节点。为了符合大多数人的习惯，本题从1开始计数，即链表的尾节点是倒数第1个节点。例如，一个链表有6个节点，从头节点开始，它们的值依次是1、2、3、4、5、6。这个链表的倒数第3个节点是值为4的节点。
示例：
```
给定一个链表: 1->2->3->4->5, 和 k = 2.
返回链表 4->5.
```

---

Solution 1:
建立一个长度为`k`的窗口，`l,r`分别为窗口两端，然后`l,r`同时滑动，直到链表尾部，此时`l`所对应的结点就是倒数第`k`个结点
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
    ListNode* getKthFromEnd(ListNode* head, int k) 
    {
        ListNode* slow = head, *fast = head;
        while(k - 1 && fast->next != nullptr)
        {
            fast = fast->next;
            k--;
        }
        while(fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};
```

Solution 2：
和上面解法几乎一样，添加一个变量计算移动步数，省去一个`for`循环
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
    ListNode* getKthFromEnd(ListNode* head, int k) 
    {
        ListNode* slow = head, *fast = head;
        int t = 0;
        while(fast != nullptr)
        {
            if(t >= k) 
                slow = slow->next;
            fast = fast->next;
            t++;
        }
        return slow;
    }
};
```