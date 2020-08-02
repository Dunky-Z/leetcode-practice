---
title: 剑指 Offer 62. 圆圈中最后剩下的数字
tags: LeetCode
notebook: a - 001 | ITabc
---

`0,1,,n-1`这`n`个数字排成一个圆圈，从数字`0`开始，每次从这个圆圈里删除第`m`个数字。求出这个圆圈里剩下的最后一个数字。

例如，`0、1、2、3、4`这`5`个数字组成一个圆圈，从数字`0`开始每次删除第`3`个数字，则删除的前`4`个数字依次是`2、0、4、1`，因此最后剩下的数字是`3`。

示例 1：
```
输入: n = 5, m = 3
输出: 3
```
示例 2：
```
输入: n = 10, m = 17
输出: 2
```

限制：
```
1 <= n <= 10^5
1 <= m <= 10^6
```

---

Solution 1:

[题解](https://leetcode-cn.com/problems/yuan-quan-zhong-zui-hou-sheng-xia-de-shu-zi-lcof/solution/javajie-jue-yue-se-fu-huan-wen-ti-gao-su-ni-wei-sh/)
```cpp
class Solution {
public:
    int lastRemaining(int n, int m) 
    {
        int res = 0;
        for(int i = 2; i <= n; ++i)
        {
            res = (res + m) % i;
        }
        return res;
    }
};
```