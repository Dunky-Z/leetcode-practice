---
title: 剑指 Offer 17. 打印从1到最大的n位数
tags: LeetCode
notebook: a - 001 | ITabc
---

输入数字 `n`，按顺序打印出从 `1` 到最大的 `n` 位十进制数。比如输入 `3`，则打印出 `1、2、3` 一直到最大的 `3` 位数 `999`。

示例 1:
```
输入: n = 1
输出: [1,2,3,4,5,6,7,8,9]
```

说明：
```
用返回一个整数列表来代替打印
n 为正整数
```

---

Solution 1:
```cpp
template <class ForwardIterator, class T>
  void iota (ForwardIterator first, ForwardIterator last, T val)
为数组在[first,last]之间填充数值，以val为初值
```
```cpp
class Solution {
public:
    vector<int> printNumbers(int n) 
    {
        int sum = 0;
        for(int i = 0; i < n; ++i)
        {
            sum = sum * 10;
            sum = sum + 9;
        }
        vector<int> res(sum);
        iota(res.begin(), res.end(), 1);
        return res;
    }
};
```