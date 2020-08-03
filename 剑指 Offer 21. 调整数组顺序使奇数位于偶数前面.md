---
title: 剑指 Offer 21. 调整数组顺序使奇数位于偶数前面
tags: LeetCode
notebook: a - 001 | ITabc
---
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有奇数位于数组的前半部分，所有偶数位于数组的后半部分。
示例：
```cpp
输入：nums = [1,2,3,4]
输出：[1,3,2,4] 
注：[3,1,2,4] 也是正确的答案之一。
```

提示：
```
1 <= nums.length <= 50000
1 <= nums[i] <= 10000
```


---

Solution 1:
双指针，首指针遇到奇数就跳过，尾指针遇到偶数跳过。首指针遇到偶数并且尾指针遇到奇数时两者交换。
```cpp
class Solution {
public:
    vector<int> exchange(vector<int>& nums) 
    {
        int n = nums.size();
        int l = 0, r = n - 1;
        while(l < r)
        {
            if(nums[l] % 2 == 1)
            {
                l++;
                continue;
            }
            if(nums[r] % 2 == 0)
            {
                r--;
                continue;
            }
            swap(nums[l], nums[r]);
        }
        return nums;
        
    }
};
```