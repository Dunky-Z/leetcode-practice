---
title: 剑指 Offer 37. 序列化二叉树
tags: LeetCode,树
notebook: a - 001 | ITabc
---

请实现两个函数，分别用来序列化和反序列化二叉树。

示例: 
```cpp
你可以将以下二叉树：

    1
   / \
  2   3
     / \
    4   5

序列化为 "[1,2,3,null,null,4,5]"
```

---

>在计算机科学的数据处理中，是指将数据结构或对象状态转换成可取用格式（例如存成文件，存于缓冲，或经由网络中发送），以留待后续在相同或另一台计算机环境中，能恢复原先状态的过程。依照序列化格式重新获取字节的结果时，可以利用它来产生与原始对象相同语义的副本。-wikipedia

因为要传输，所以要输入输出流。istringstream和ostringstrem，序列化的过程就是先序遍历的过程。依次将根节点写入输出流。为了方便区分树的层次，遇到空节点写入"#"。

反序列化的过程就是递归建树的过程，取出收首元素，递归建立其左右子树。遇到"#"时结束本次递归，返回上一层。初始化输入流的方式`istringstream(data)`。

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
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) 
    {
        ostringstream out;
        serialize(root, out);
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) 
    {
        istringstream in(data);
        return deserialize(in);
    }
    
private:
    void serialize(TreeNode* root, ostringstream& out)
    {
        if(root)
        {
            out << root->val << " ";
            serialize(root->left, out);
            serialize(root->right, out);
        }
        else
            out << "# ";
    }
    
    TreeNode* deserialize(istringstream &in)
    {
        string val;
        in >> val;
        if(val == "#") return nullptr;
        TreeNode *root = new TreeNode(stoi(val));
        root->left = deserialize(in);
        root->right = deserialize(in);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
```