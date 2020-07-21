---
title: 剑指 Offer 55 - I. 二叉树的深度
tags: LeetCode,树,剑指
notebook: a - 001 | ITabc
---
输入一棵二叉树的根节点，求该树的深度。从根节点到叶节点依次经过的节点（含根、叶节点）形成树的一条路径，最长路径的长度为树的深度。

例如：
```cpp
给定二叉树 [3,9,20,null,null,15,7]，

    3
   / \
  9  20
    /  \
   15   7
返回它的最大深度 3 。
```

---
Solution 1:
DFS
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
    int maxDepth(TreeNode* root) 
    {
        if(root == nullptr)
            return 0;
        int right = maxDepth(root->right);
        int left = maxDepth(root->left);
        return max(right, left) + 1;
    }
};
```

Solution 2:  
BFS  用队列作为辅助。但是有个地方要注意，在遍历队列元素时，用队列大小初始化`i`。而不能从`0-size`因为`que`大小一直是变化的···

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
    int maxDepth(TreeNode* root) 
    {
        if(root == nullptr)
            return 0;
        queue<TreeNode*> que;
        que.push(root);
        int res = 0;
        while(!que.empty())
        {
            for(int i = que.size() - 1; i >= 0; --i)
            {
                TreeNode *node = que.front(); 
                que.pop();
                TreeNode *l = node->left, *r = node->right;
                if(l) que.push(l);
                if(r) que.push(r);          
            }
            res++;
        }
        return res;
    }
};
```