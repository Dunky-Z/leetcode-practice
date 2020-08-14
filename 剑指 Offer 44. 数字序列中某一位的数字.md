---
title: 剑指 Offer 44. 数字序列中某一位的数字
tags: LeetCode
notebook: a - 001 | ITabc
---
数字以`0123456789101112131415…`的格式序列化到一个字符序列中。在这个序列中，第`5`位（从下标`0`开始计数）是`5`，第`13`位是`1`，第`19`位是`4`,等等。

请写一个函数，求任意第n位对应的数字。

 

示例 1：
```
输入：n = 3
输出：3
```
示例 2：
```
输入：n = 11
输出：0
```

限制：`0 <= n < 2^31`


Solution 1:


```cpp
class Solution {
public:
    int findNthDigit(int n) 
    {
        // 计算该数字由几位数字组成，由1位：digits = 1；2位：digits = 2...
        long base = 9,digits = 1;
        while (n - base * digits > 0)
        {
            n -= base * digits;
            base *= 10;
            digits ++;
        }

        // 计算真实代表的数字是多少
        int idx = n % digits;  // 注意由于上面的计算，n现在表示digits位数的第n个数字
        if (idx == 0)
            idx = digits;
        long number = 1;
        for (int i = 1; i < digits; i++)
            number *= 10;
        number += (idx == digits)? n / digits - 1 : n / digits;

        // 从真实的数字中找到我们想要的那个数字
        for (int i = idx; i < digits; i++) 
            number /= 10;
        return number % 10;
    }
};
```