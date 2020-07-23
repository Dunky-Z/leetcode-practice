---
title: 剑指 Offer 34. 二叉树中和为某一值的路径
tags: LeetCode,树,深度优先搜索
notebook: a - 001 | ITabc
---

输入一棵二叉树和一个整数，打印出二叉树中节点值的和为输入整数的所有路径。从树的根节点开始往下一直到叶节点所经过的节点形成一条路径。
示例:
```cpp
给定如下二叉树，以及目标和 sum = 22，

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
返回:

[
   [5,4,11,2],
   [5,8,4,5]
]
```
提示：`节点总数 <= 10000`

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
class Solution 
{
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) 
    {
        vector<int> t_path;
        helper(root, sum, t_path);
        return res;
    }
private:
    vector<vector<int>> res;
    void helper(TreeNode* root, int sum, vector<int>& t_path)
    {
        if(root == nullptr)
            return;
        t_path.push_back(root->val);
        //遍历到叶子结点，并且已经满足路径和，将答案保存
        if(root->val == sum && root->left == nullptr && root->right == nullptr)
        {
            res.push_back(t_path);
        }
        
        helper(root->left, sum - root->val, t_path);
        helper(root->right, sum - root->val, t_path);
        //遍历到叶节点没有满足要求，就将叶节点从临时路径中删除
        t_path.pop_back();
    }
};
```