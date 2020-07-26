---
title: 剑指 Offer 14- II. 剪绳子 II
tags: LeetCode
notebook: a - 001 | ITabc
---

给你一根长度为 `n` 的绳子，请把绳子剪成整数长度的 `m` 段（`m、n`都是整数，`n>1`并且`m>1`），每段绳子的长度记为 `k[0],k[1]...k[m - 1]` 。请问 `k[0]*k[1]*...*k[m - 1]` 可能的最大乘积是多少？例如，当绳子的长度是`8`时，我们把它剪成长度分别为`2、3、3`的三段，此时得到的最大乘积是`18`。

答案需要取模 `1e9+7（1000000007）`，如计算初始结果为：`1000000008`，请返回 `1`。

示例 1：
```
输入: 2
输出: 1
解释: 2 = 1 + 1, 1 × 1 = 1
```
示例 2:
```
输入: 10
输出: 36
解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36
```

提示：`2 <= n <= 1000`

---

Solution 1:

![](https://gitee.com//dominic_z/markdown_picbed/raw/master/img/20200726100953.png)

```cpp
class Solution {
public:
    int cuttingRope(int n) 
    {
        if(n <= 3)
            return n - 1;
        int p = 1000000007;
        long res = 1;
        while(n > 4)
        {
            res *= 3;
            res %= p;
            n -= 3;
        }
        return (int)(res * n % p);
    }
};
```

Solution 2:

```cpp
class Solution {
public:
    int cuttingRope(int n) 
    {
        if(n <= 3)
            return n - 1;
        int b = n % 3;
        int p = 1000000007;
        long rem = 1, x = 3;
        for(int a = n / 3 - 1; a > 0; a /= 2)
        {
            if(a % 2 == 1)
                rem = (rem * x) % p;
            x = (x * x) % p;
        }
        if(b == 0)
            return (int)(rem * 3 % p);
        if(b == 1)
            return (int)(rem * 4 % p);
        return (int)(rem * 6 % p);
    }
};
```
