---
title: 剑指 Offer 10- II. 青蛙跳台阶问题
tags: LeetCode
notebook: a - 001 | ITabc
---
一只青蛙一次可以跳上1级台阶，也可以跳上2级台阶。求该青蛙跳上一个 n 级的台阶总共有多少种跳法。

答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。

示例 1：
```cpp
输入：n = 2
输出：2
```
示例 2：
```cpp
输入：n = 7
输出：21
```
提示：`0 <= n <= 100`


```cpp
class Solution {
public:
    int numWays(int n) 
    {
        if(n <= 1)
            return 1;
        int step1 = 1, step2 = 2, step3;
        for(int i = 3; i <= n; ++i)
        {
            step3 = (step1 + step2) % 1000000007;
            step1 = step2;
            step2 = step3;
        }
        //逻辑上应该返回step3,但是step3并没有被初始化
        //如果输入为n=2，就会出错，当然也可以多加一个if(n==2)判断
        //step2和step3值是一样的，所以返回step2也行，可以少写一个if
        return step2 % 1000000007;

    }
};
```