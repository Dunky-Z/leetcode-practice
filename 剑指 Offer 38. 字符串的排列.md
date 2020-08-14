---
title: 剑指 Offer 38. 字符串的排列
tags: LeetCode
notebook: a - 001 | ITabc
---

输入一个字符串，打印出该字符串中字符的所有排列。

你可以以任意顺序返回这个字符串数组，但里面不能有重复元素。

示例:
```
输入：s = "abc"
输出：["abc","acb","bac","bca","cab","cba"]
```

限制：`1 <= s 的长度 <= 8`


---

```cpp
class Solution {
private:
    vector<string> res;
    void premutationHelper(string& s, int index)
    {
        if(index == s.size())
        {
            res.push_back(s);         
        }
        for(int i = index; i < s.size(); ++i)
        {
            bool flag = true;
            for(int j = index; j < i; ++j)
            {
                if(s[j] == s[i])
                    flag = false;
            }
            if(flag)
            {
                swap(s[index], s[i]);
                premutationHelper(s, index + 1);
                swap(s[index], s[i]);
            }
        }
    }
public:
    
    vector<string> permutation(string s) 
    {
        res.clear();
        if(s.size() == 0)
            return res;
        premutationHelper(s, 0);
        return res;
    }
};
```