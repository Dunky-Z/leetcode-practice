---
title: 剑指 Offer 28. 对称的二叉树
tags: LeetCode
notebook: a - 001 | ITabc
---
请实现一个函数，用来判断一棵二叉树是不是对称的。如果一棵二叉树和它的镜像一样，那么它是对称的。
例如，二叉树 `[1,2,2,3,4,4,3]` 是对称的。
```cpp
    1
   / \
  2   2
 / \ / \
3  4 4  3
```
但是下面这个 `[1,2,2,null,3,null,3]` 则不是镜像对称的:
```cpp
    1
   / \
  2   2
   \   \
   3    3
```

---

Solution 1:

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
    bool isSymmetric(TreeNode* root) 
    {
        return root == nullptr ? true : isSymmetricHelper(root->left, root->right);
    }
    bool  isSymmetricHelper(TreeNode* left, TreeNode* right)
    {
        //left 和 right 同时越过叶子结点，根到叶子结点都是对称，返回true
        if(left == nullptr && right == nullptr)
            return true;
        //left 和 right 只有一个越过了叶子结点，或者两者值不同，不对称
        if(left == nullptr || right == nullptr || left->val != right->val)
            return false;
        //判断两结点左右，右左是否对称 两个条件都是true整个树才是对称，用&&连接
        return isSymmetricHelper(left->left, right->right) && isSymmetricHelper(left->right, right->left);
    }
};
```