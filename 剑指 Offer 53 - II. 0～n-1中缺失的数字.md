---
title: 剑指 Offer 53 - II. 0～n-1中缺失的数字
tags: LeetCode
notebook: a - 001 | ITabc
---

一个长度为n-1的递增排序数组中的所有数字都是唯一的，并且每个数字都在范围0～n-1之内。在范围0～n-1内的n个数字中有且只有一个数字不在该数组中，请找出这个数字。

示例 1:
```
输入: [0,1,3]
输出: 2
```
示例 2:
```
输入: [0,1,2,3,4,5,6,7,9]
输出: 8
```
限制：`1 <= 数组长度 <= 10000`

---


Solution 1:
有序数组搜索只管二分就好了
```cpp
class Solution {
public:
    int missingNumber(vector<int>& nums) 
    {
        int i = 0, j = nums.size() - 1;
        while(i <= j)
        {
            int mid = i + (j - i) / 2;
            //nums[mid] == mid 说明这一段里没有缺失的数字
            //那么缺失的数字一定在另一侧
            if(nums[mid] == mid)
                 i = mid + 1;
            else
                j = j - 1;
        }
        return i;
    }
};
```