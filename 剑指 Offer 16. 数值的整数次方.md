---
title: 剑指 Offer 16. 数值的整数次方
tags: LeetCode
notebook: a - 001 | ITabc
---
实现函数double Power(double base, int exponent)，求base的exponent次方。不得使用库函数，同时不需要考虑大数问题。

示例 1:
```cpp
输入: 2.00000, 10
输出: 1024.00000
```
示例 2:
```cpp
输入: 2.10000, 3
输出: 9.26100
```
示例 3:
```cpp
输入: 2.00000, -2
输出: 0.25000
解释: 2-2 = 1/22 = 1/4 = 0.25
```

说明:`-100.0 < x < 100.0`
`n` 是 `32` 位有符号整数，其数值范围是 `[−231, 231 − 1]`。

---

Solution 1:

```cpp
class Solution {
public:
    double myPow(double x, int n) 
    {
        if(x == 0)
            return 0;
        double res = 1.0;
        long b = n;
        if(b < 0)
        {
            b = -b;
            x = 1 / x;
        }
        while(b > 0)
        {
            //奇数时要多乘一个x
            if(b % 2)
                res *= x;
            x *= x;
            b = b >> 1;
        }
        return res;
    }
};
```

Solution 2：

```cpp

class Solution {
public:
    double myPow(double x, int n) 
    {
        double res = 1.0;
        for(int i = n; i != 0; i = i/2)
        {
            if(i % 2)
                res *= x;
            x *= x;
        }
        if(n > 0)
            return res;
        else 
            return 1 / res;
    }
};
```