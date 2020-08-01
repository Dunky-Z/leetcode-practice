---
title: 剑指 Offer 50. 第一个只出现一次的字符
tags: LeetCode
notebook: a - 001 | ITabc
---

在字符串 `s` 中找出第一个只出现一次的字符。如果没有，返回一个单空格。 `s` 只包含小写字母。

示例:
```
s = "abaccdeff"
返回 "b"

s = "" 
返回 " "
```

限制：`0 <= s 的长度 <= 50000`

---

Solution 1:
数组建立一个哈希表，遍历所有字符，如果只存在一次，哈希表对应的value肯定就是1，只要再遍历一遍数组，第一个匹配到1的就是结果。
```cpp
class Solution {
public:
    char firstUniqChar(string s) 
    {
        int a[26] = {0};
        if(s == "") return ' ';
        for(int i = 0; i < s.size(); i++)
        {
            int b = s[i] - 'a';
            a[b] += 1;
        }
        for(int i = 0; i < s.size(); i++)
        {
            int b = s[i] - 'a';
            if(a[b] == 1) return s[i];
        }
        return ' ';
    }
};
```