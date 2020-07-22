---
title: 剑指 Offer 32 - II. 从上到下打印二叉树 II
tags: LeetCode,树
notebook: a - 001 | ITabc
---
从上到下按层打印二叉树，同一层的节点按从左到右的顺序打印，每一层打印到一行。

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
  [9,20],
  [15,7]
]
```
提示：`节点总数 <= 1000`

---
Solution 1:
层序遍历，还是要注意遍历一层是`size`要先算出来，或者`size`从大到小，不然会出错，因为队列的大小一直在变化。
```cpp
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int>> res;
        if(root == nullptr)
            return res;
        queue<TreeNode*> que;
        que.push(root);
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
            res.push_back(tmp);
        }
        return res;
    }
};
```