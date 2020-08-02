---
title: 剑指 Offer 61. 扑克牌中的顺子
tags: LeetCode
notebook: a - 001 | ITabc
---
从扑克牌中随机抽5张牌，判断是不是一个顺子，即这5张牌是不是连续的。2～10为数字本身，A为1，J为11，Q为12，K为13，而大、小王为 0 ，可以看成任意数字。A 不能视为 14。

示例 1:
```cpp
输入: [1,2,3,4,5]
输出: True
```

示例 2:
```cpp
输入: [0,0,1,2,5]
输出: True
```
限制：
```
数组长度为 5 
数组的数取值为 [0, 13] .
```
---

Solution 1:
- 排序
- 统计0的个数
- 统计间隔的个数
如果间隔个数大于0的个数，就不是顺子，如果存在对子的情况，也不是顺子
```cpp
class Solution {
public:
    bool isStraight(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        int numZero = 0, numSpace;
        for(auto& num : nums)
            if(num == 0)
                numZero++;
        int left = numZero;
        int right = left + 1;
        while(right < nums.size())
        {
            if(nums[left] == nums[right])
                return false;
            numSpace += nums[right] - nums[left] - 1;
            left = right;
            right++;
        }
        return numSpace > numZero ? false : true;
    }
};
```
Solution 2:

```cpp
class Solution {
public:
    bool isStraight(vector<int>& nums) 
    {
        set<int> st;
        int max_ = 0, min_ = 14;
        for(auto& num : nums)
        {
            if(num == 0)
                continue;
            max_ = max(max_, num);
            min_ = min(min_, num);
            //有对子存在，直接返回false
            if(st.count(num))
                return false;
            st.insert(num);
        }
        return max_ - min_ < 5;
    }
};
```