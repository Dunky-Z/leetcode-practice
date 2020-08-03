---
title: 剑指 Offer 66. 构建乘积数组
tags: LeetCode
notebook: a - 001 | ITabc
---

给定一个数组 `A[0,1,…,n-1]`，请构建一个数组 `B[0,1,…,n-1]`，其中 `B` 中的元素 `B[i]=A[0]×A[1]×…×A[i-1]×A[i+1]×…×A[n-1]`。不能使用除法。
示例:
```
输入: [1,2,3,4,5]
输出: [120,60,40,30,24]
```

提示：
```
所有元素乘积之和不会溢出 32 位整数
a.length <= 100000
```

---

Solution 1:
题目看了半天才看懂，公式看的云里雾里的，其实意思就是，除了第`i`个元素，其余元素相乘的结果。
第一遍循环先算出`i`左边的乘积，第二遍循环算出`i`右边的乘积，再乘上左边的乘积。
![](https://pic.leetcode-cn.com/6056c7a5009cb7a4674aab28505e598c502a7f7c60c45b9f19a8a64f31304745-Picture1.png)
图片：[Krahets
](https://leetcode-cn.com/problems/gou-jian-cheng-ji-shu-zu-lcof/solution/mian-shi-ti-66-gou-jian-cheng-ji-shu-zu-biao-ge-fe/)
```cpp
class Solution {
public:
    vector<int> constructArr(vector<int>& a) 
    {
        int n = a.size();
        vector<int> res(n);
        if(n == 0)
            return res;
        int t = 1;
        res[0] = 1;
        //填充下三角
        for(int i = 1; i < n; i++)
        {
            res[i] = res[i - 1] * a[i - 1];
        }
        //填充上三角
        for(int i = n - 2; i >= 0; i--) {
            t *= a[i + 1];
            res[i] *= t;
        }
        return res;

    }
};
```