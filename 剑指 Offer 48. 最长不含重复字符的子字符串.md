---
title: 剑指 Offer 48. 最长不含重复字符的子字符串
tags: LeetCode
notebook: a - 001 | ITabc
---
请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子字符串的长度。

示例 1:
```
输入: "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
```
示例 2:
```
输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
```
示例 3:
```
输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
```

提示：`s.length <= 40000`

---

Solution 1:

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int freq[256] = {0};
        int res = 0;
        int l = 0, r = -1;
        const int n = s.size();
        while(l < n)
        {
            //如果待匹配元素不存在，将其标记存在，右指针向右移动一格
            if(r + 1 < n && freq[s[r + 1]] == 0)
            {
                freq[s[++r]]++;
            }
            else
            {
                //待匹配元素存在，左指针向右移，直到待匹配元素不存在的位置，并将对应标记减1
                freq[s[l++]]--;
            }
            
             res = max(res, r - l + 1);
        }
        return res;
    }
};
```