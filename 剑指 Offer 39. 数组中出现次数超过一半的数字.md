---
title: 剑指 Offer 39. 数组中出现次数超过一半的数字
tags: LeetCode,位运算
notebook: 
---
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。  
你可以假设数组是非空的，并且给定的数组总是存在多数元素。
示例 1: 
```cpp
输入: [1, 2, 3, 2, 2, 2, 5, 4, 2]
输出: 2
```
限制：
```
1 <= 数组长度 <= 50000
```

Solution 1:
如果是个排序数组，那么中间的数字一定是答案。时间复杂度为O(nlogn)，这是调用快排算法所需的时间

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        return nums[nums.size() / 2];
    }
};
```

Solution 2：摩尔投票
这题就是要求一个众数，如果给数组中每个数都进行投票，众数投正，非众数投负，那么最后所有票数之和一定大于0。 设数组 nums 中的众数为 $x$ ，数组长度为 $n$ 。若 `nums` 的前 `a` 个数字的 `票数和=0` ，则数组后`(n-a)`个数字的票数和一定仍`>0`（即后 `(n-a)`个数字的众数仍为`x`）。由此，随机取一个数作为候选，这里为了方便就取数组首位，如果下个数与之相等计数`+1`，如不等`-1`。如计数器归零，更换候选。最后剩下的候选就是众数。

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        int candidate;
        int cnt = 0;
        for(auto& n : nums)
        {
            if(cnt == 0)
                candidate = n;
            cnt += (candidate == n) ? 1 : -1;
        }
        return candidate;     
    }
};
```