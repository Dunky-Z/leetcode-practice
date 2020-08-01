---
title: 剑指 Offer 42. 连续子数组的最大和
tags: LeetCode,动态规划
notebook: a - 001 | ITabc
---

输入一个整型数组，数组里有正数也有负数。数组中的一个或连续多个整数组成一个子数组。求所有子数组的和的最大值。
要求时间复杂度为`O(n)`。

示例1:
```
输入: nums = [-2,1,-3,4,-1,2,1,-5,4]
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
```

提示：
```
1 <= arr.length <= 10^5
-100 <= arr[i] <= 100
```


--- 

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int n = nums.size();
        int pre  = 0, res = nums[0];
        for(int i = 0; i < n; ++i)
        {
            pre = max(nums[i] + pre, nums[i]);
            res = max(res, pre);
        }      
        return res;
    }
};
```