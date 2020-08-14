---
title: 剑指 Offer 43. 1～n整数中1出现的次数
tags: LeetCode
notebook: a - 001 | ITabc
---

输入一个整数 n ，求1～n这n个整数的十进制表示中1出现的次数。

例如，输入12，1～12这些整数中包含1 的数字有1、10、11和12，1一共出现了5次。

示例 1：
```
输入：n = 12
输出：5
```
示例 2：
```
输入：n = 13
输出：6
```

---
Solution 1：
[题解](https://leetcode-cn.com/problems/1nzheng-shu-zhong-1chu-xian-de-ci-shu-lcof/solution/mian-shi-ti-43-1n-zheng-shu-zhong-1-chu-xian-de-2/)

```cpp
class Solution {
public:
    int countDigitOne(int n) 
    {
        double digit = 1;//从个位开始
        int res = 0;
        int high = n / 10, cur = n % 10, low = 0;
        //高位还没有越过第一个数字，当前位也没有越过第一个数字
        while(high != 0 || cur != 0)
        {
            if(cur == 0)
                res += high * digit;
            else if(cur == 1)
                res += high * digit + low + 1;
            else
                res += (high + 1) * digit;
            low += cur * digit; 
            cur = high % 10;
            high /= 10;
            digit *= 10;
        }
        return res;
    }
};
```