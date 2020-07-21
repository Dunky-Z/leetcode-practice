---
title: 剑指 Offer 55 - II. 平衡二叉树
tags: LeetCode,剑指,树
notebook: a - 001 | ITabc
---
输入一棵二叉树的根节点，判断该树是不是平衡二叉树。如果某二叉树中任意节点的左右子树的深度相差不超过1，那么它就是一棵平衡二叉树。

示例 1:
```cpp
给定二叉树 [3,9,20,null,null,15,7]

    3
   / \
  9  20
    /  \
   15   7
返回 true 。
```
示例 2:
```cpp
给定二叉树 [1,2,2,3,3,null,null,4,4]

       1
      / \
     2   2
    / \
   3   3
  / \
 4   4
```

---
Solution 1:
刚做完二叉树深度的题，可以直接用这个接口。只要判断每个结点对应的树的深度是否满足平衡就可以了。

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
    bool isBalanced(TreeNode* root) 
    {
        if(root == nullptr)
            return true;
        if(abs(maxDepth(root->left) - maxDepth(root->right)) > 1)
            return false;
        return isBalanced(root->left) && isBalanced(root->right); 

    }
private:
    int maxDepth(TreeNode* node)
    {
        if(node == nullptr)
            return 0;
        int left = maxDepth(node->left);
        int right = maxDepth(node->right);
        return max(left, right) + 1;
    }
};
```
>上面那个方法正确但不是很高效，因为每一个点都会被上面的点计算深度时访问一次，我们可以进行优化。方法是如果我们发现子树不平衡，则不计算具体的深度，而是直接返回-1。那么优化后的方法为：对于每一个节点，我们通过checkDepth方法递归获得左右子树的深度，如果子树是平衡的，则返回真实的深度，若不平衡，直接返回-1，此方法时间复杂度O(N)，空间复杂度O(H)，参见代码如下：引用自[Grandyang](https://www.cnblogs.com/grandyang/p/4045660.html)
```cpp
class Solution {
public:    
    bool isBalanced(TreeNode *root) {
        if (checkDepth(root) == -1) return false;
        else return true;
    }
    int checkDepth(TreeNode *root) {
        if (!root) return 0;
        int left = checkDepth(root->left);
        if (left == -1) return -1;
        int right = checkDepth(root->right);
        if (right == -1) return -1;
        int diff = abs(left - right);
        if (diff > 1) return -1;
        else return 1 + max(left, right);
    }
};
```