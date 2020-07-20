---
title: 剑指 Offer 54. 二叉搜索树的第k大节点
tags: LeetCode,树
notebook: a - 001 | ITabc
---
给定一棵二叉搜索树，请找出其中第k大的节点。
示例 1:
```cpp
输入: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
输出: 4
```
示例 2:
```cpp
输入: root = [5,3,6,2,4,null,null,1], k = 3
       5
      / \
     3   6
    / \
   2   4
  /
 1
输出: 4
```
限制：`1 ≤ k ≤ 二叉搜索树元素个数`

---

Solution 1:
二叉树的中序遍历，只不过是先遍历右子树，再遍历左子树。因为题目要求找第`k`大的，二叉搜索树的右子树比左子树的值都要大。先右后左方便编码。

用变量`k`记录遍历到第几个结点。如果`k==0`提前终止遍历，因为已经找到了目标。
```cpp

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int kthLargest(TreeNode* root, int k) 
    {
        kthLargestHelper(root, k);
        return res;
    }
private:
    int res;
    void kthLargestHelper(TreeNode* root, int& k)
    {
        if(root == nullptr)
            return;
        kthLargestHelper(root->right, k);//先右后左，因为二叉搜索树右比左大
        //已经找到了目标，提前终止
        if(k == 0)
            return;
        //说明当前就是目标，记录目标
        if(--k == 0)
            res = root->val;
        kthLargestHelper(root->left, k);
    }
};
```