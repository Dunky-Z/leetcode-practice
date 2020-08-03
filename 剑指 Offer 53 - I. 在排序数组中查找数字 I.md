---
title: 剑指 Offer 53 - I. 在排序数组中查找数字 I
tags: LeetCode
notebook: a - 001 | ITabc
---
统计一个数字在排序数组中出现的次数。

示例 1:
```
输入: nums = [5,7,7,8,8,10], target = 8
输出: 2
```
示例 2:
```
输入: nums = [5,7,7,8,8,10], target = 6
输出: 0
```
限制：`0 <= 数组长度 <= 50000`

---

Solution 1:
分别找出`target`和`target-1`的右边界，结果就是两个边界之差

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        return helper(nums, target) - helper(nums, target - 1);
    }
    int helper(vector<int>& nums, int target)
    {
        int n = nums.size();
        int i = 0, j = n - 1;
        while(i <= j)
        {
            int mid = i + (j - i) / 2;
            if(nums[mid] <= target)
            {
                i = mid + 1;
            }
            else
            {
                j = mid - 1;
            }
        }
        return i;
    }
};
```