---
title: 剑指 Offer 27. 二叉树的镜像
tags: LeetCode,剑指
notebook: a - 001 | ITabc
---
请完成一个函数，输入一个二叉树，该函数输出它的镜像。
例如输入：
```
     4
   /   \
  2     7
 / \   / \
1   3 6   9
```
镜像输出：
```
     4
   /   \
  7     2
 / \   / \
9   6 3   1
```
示例 1：
```
输入：root = [4,2,7,1,3,6,9]
输出：[4,7,2,9,6,3,1]
```
限制：`0 <= 节点个数 <= 1000`

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
    TreeNode* mirrorTree(TreeNode* root) 
    {
        if(root == nullptr)
            return nullptr;
        mirrorTree(root->left);
        mirrorTree(root->right);
        swap(root->left, root->right);
        return root;
    }
};
```
Solution 2:
类似层序遍历，用队列做辅助。首先将根节点入队，然后从队中取出来，交换其左右节点，如果其左右结点存在，就将其分别入队，以此类推直到队列中木有节点了停止循环，返回root即可
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
    TreeNode* invertTree(TreeNode* root) 
    {
        if(root == nullptr)
            return nullptr;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty())
        {
            TreeNode* node = que.front(), *tmp;
            que.pop();
            tmp = node->left;
            node->left = node->right;
            node->right = tmp;
            if(node->left) que.push(node->left);
            if(node->right) que.push(node->right);
        }
        return root;
    }
};
```