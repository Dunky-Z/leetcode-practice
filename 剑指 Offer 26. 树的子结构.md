---
title: 剑指 Offer 26. 树的子结构
tags: LeetCode,树
notebook: a - 001 | ITabc
---
输入两棵二叉树A和B，判断B是不是A的子结构。(约定空树不是任意一个树的子结构)
B是A的子结构， 即 A中有出现和B相同的结构和节点值。
例如:
```cpp
给定的树 A:

     3
    / \
   4   5
  / \
 1   2
给定的树 B：

   4 
  /
 1
返回 true，因为 B 与 A 的一个子树拥有相同的结构和节点值。
```
示例 1：
```
输入：A = [1,2,3], B = [3,1]
输出：false
```
示例 2：
```
输入：A = [3,4,5,1,2], B = [4,1]
输出：true
```
限制：`0 <= 节点个数 <= 10000`

---

Solution 1：

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
    bool isSubStructure(TreeNode* A, TreeNode* B) 
    {
        return (A != nullptr && B != nullptr) && (isSubHelper(A, B) 
        || isSubStructure(A->left, B) || isSubStructure(A->right, B));
    }
    bool isSubHelper(TreeNode* root, TreeNode* sub)
    {
        if(sub == nullptr)
            return true;
        if(root == nullptr || root->val != sub->val)
            return false;
        return isSubHelper(root->left, sub->left) && isSubHelper(root->right, sub->right);;
    }
};
```