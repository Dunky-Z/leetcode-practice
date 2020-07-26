---
title: 剑指 Offer 14- I. 剪绳子
tags: LeetCode
notebook: a - 001 | ITabc
---

给你一根长度为 n 的绳子，请把绳子剪成整数长度的 `m` 段（`m、n`都是整数，`n>1`并且`m>1`），每段绳子的长度记为 `k[0],k[1]...k[m-1]` 。请问 `k[0]*k[1]*...*k[m-1]` 可能的最大乘积是多少？例如，当绳子的长度是`8`时，我们把它剪成长度分别为`2、3、3`的三段，此时得到的最大乘积是`18`。

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
提示：`2 <= n <= 58`

---

`dp[i]`：数字`i`分割得到的乘积最大值
`dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]))`：剪两段`j * (i - j)`的乘积和剪多段`j * dp[i - j]`的乘积的最大值与当前状态中取最大值

```cpp
class Solution {
public:
    int cuttingRope(int n) 
    {
        vector<int> dp(n + 1, 1);
        for(int i = 3; i <= n; ++i)
        {
            for(int j = 1; j < i; ++j)
            {
                dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));
                
            }
        }
        return dp[n];
    }
};
```
