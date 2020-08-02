---
title: 剑指 Offer 60. n个骰子的点数
tags: LeetCode
notebook: a - 001 | ITabc
---
把n个骰子扔在地上，所有骰子朝上一面的点数之和为s。输入n，打印出s的所有可能的值出现的概率。
你需要用一个浮点数数组返回答案，其中第 i 个元素代表这 n 个骰子所能掷出的点数集合中第 i 小的那个的概率。

示例 1:
```cpp
输入: 1
输出: [0.16667,0.16667,0.16667,0.16667,0.16667,0.16667]
```

示例 2:
```cpp
输入: 2
输出: [0.02778,0.05556,0.08333,0.11111,0.13889,0.16667,0.13889,0.11111,0.08333,0.05556,0.02778]
```

---
Solution 1:

`dp[n][j]:` `n`个骰子，投出`j`的概率。
$d p[n][j]=\sum_{i=1}^{6} d p[n-1][j-i]$

```cpp
class Solution {
public:
    vector<double> twoSum(int n) 
    {
        vector<double> res; 
        int fenmu = pow(6, n);
        vector<vector<int>> dp(n+1, vector<int>((n+1)*6, 0));
        
        for(int i = 1; i <= 6; ++i)
        {
            dp[1][i] = 1;   
        }
        //遍历n个骰子
        for (int i = 2; i <= n; ++i) 
        {
            //所有点数的可能
            for (int j = i; j <= 6*i; ++j) 
            {
                for (int cur = 1; cur <= 6; ++cur) 
                {
                    if (j - cur <= 0) break;
                    dp[i][j] += dp[i-1][j-cur];
                }
            }
        }
        
        for(int i = n; i <= 6*n; ++i)
        {
            res.push_back(dp[n][i] * 1.0 / fenmu);
        }
        return res;
    }
};
```