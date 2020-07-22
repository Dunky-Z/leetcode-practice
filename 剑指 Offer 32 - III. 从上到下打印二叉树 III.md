---
title: 剑指 Offer 32 - III. 从上到下打印二叉树 III
tags: LeetCode,树
notebook: a - 001 | ITabc
---
请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印，其他行以此类推。

 

例如:
```cpp
给定二叉树: [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其层次遍历结果：

[
  [3],
  [20,9],
  [15,7]
]
```

提示：`节点总数 <= 1000`

---

在层序遍历的基础上，加一个变量，记录遍历到了第几层，如果是偶数层就将当前层的数据反转。
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
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int>> res;
        if(root == nullptr)
            return res;
        queue<TreeNode*> que;
        que.push(root);
        size_t level = 0;
        while(!que.empty())
        {
            vector<int> tmp; 
            //先算出size大小
            size_t n = que.size();
            for(size_t i = 0; i < n; ++i)
            {
                TreeNode* node = que.front();
                que.pop();
                tmp.push_back(node->val);
                if(node->left)
                {
                    que.push(node->left);
                }
                if(node->right)
                {
                    que.push(node->right);
                }
            }
            ++level;
            if(level % 2 == 0)
                reverse(tmp.begin(),tmp.end());
            res.push_back(tmp);
        }
        return res;
    }
};
```

Solution 2:
用双端队列`deuqe`的性质。
- 奇数层，从队列前取出元素，先将其左子树先入队尾，右子树后入队尾
- 偶数层，从队列尾取出元素，现将其右子树先入队首，左子树后入队首
```cpp
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr)
            return res;
        bool flag = true; 
        deque<TreeNode*> que;
        que.push_back(root);
        while (!que.empty())
        {
            int n = que.size();
            vector<int> tmp;
            TreeNode* node;
            while (n > 0)
            {
                if (flag) 
                {
                    node = que.front();
                    que.pop_front();
                    if (node->left)
                        que.push_back(node->left);
                    if (node->right)
                        que.push_back(node->right);
                }
                else  
                {
                    node = que.back();
                    que.pop_back();
                    if (node->right)
                        que.push_front(node->right); 
                    if (node->left)
                        que.push_front(node->left);
                }
                tmp.push_back(node->val);
                --n;
            }
            flag = !flag;
            res.push_back(tmp);
        }
        return res;
    }
};
```