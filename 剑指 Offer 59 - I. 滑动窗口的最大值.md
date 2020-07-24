---
title: 剑指 Offer 59 - I. 滑动窗口的最大值
tags: LeetCode
notebook: a - 001 | ITabc
---
给定一个数组 `nums` 和滑动窗口的大小 `k`，请找出所有滑动窗口里的最大值。

示例:
```cpp
输入: nums = [1,3,-1,-3,5,3,6,7], 和 k = 3
输出: [3,3,5,5,6,7] 
解释: 

  滑动窗口的位置                最大值
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
```

提示：
```
你可以假设 k 总是有效的，在输入数组不为空的情况下，1 ≤ k ≤ 输入数组的大小。
```
---
Solution 1：
暴力法就是没加入一个数都算出窗口最大值，这个当然过不了。如果能把窗口内的数进行排个序，最大值就很容易取出来了。而`set`每次加入新元素后都会进行排序。借助这个数据结构来做这题。遍历数组，逐一将其加到`set`中，遍历元素个数超过窗口大小时，就要把窗口左边的元素删除。但是`set`内的元素排过序了，所以不能直接删除，需要先查找一次左边的元素的位置，再通过`erase`删除。每遍历一个元素都将最大值，即`set`最右边的元素加入`res`。

时间复杂度：`find:O(logN)`\*`erase(logN)`\*`N`=`O(nlogN)`
空间复杂度：`O(1)`

```cpp
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        size_t n = nums.size();
        vector<int> res;
        multiset<int> st;
        for(size_t i = 0; i < n; ++i)
        {
            //每次将窗口的左侧元素删除
            if(i >= k)
                st.erase(st.find(nums[i-k]));
            
            st.insert(nums[i]);
            //窗口大小为k的时候将最大值加入res
            //因为set是升序排序的，最大值在最后
            if(i >= k - 1)
                res.push_back(*st.rbegin());
        }
        return res;
    }
};
```

Solution 2:
这道题主要花费时间还是在找最大值上，如果以更快的速度找到最大值，整体算法速度就会随之提升。在[队列最大值](https://leetcode-cn.com/problems/dui-lie-de-zui-da-zhi-lcof/)中，我们可以以`O(1)`时间取出队列的最大元素。当时使用了双端队列这个数据结构。在这里也可以用上。我们用双端队列`deque`记录窗口中的元素，并使其保持递减，那么队首的元素就是窗口的最大值。如何保持队列递减？只要待加入的元素大于队尾元素，就将队尾元素删除。每次滑动窗口都要判断队首元素是否等于刚被删除的元素，如果相等，要把队首元素一并删除。

```cpp
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        size_t n = nums.size();
        vector<int> res;
        if(n == 0)
            return res;
        deque<int> dque;
        for(int r = 0, l = 1 - k; r < nums.size(); ++r, ++l)
        {
            //如果窗口中最大值被删除，也要将队列中最大值删除
            if(l > 0 && dque.front() == nums[l-1])
                dque.pop_front();
            //删除队尾所有比待加入元素值小的数，保持队列递减
            while(!dque.empty() && dque.back() < nums[r])
                dque.pop_back();
            dque.push_back(nums[r]);
            //记录每次滑动的最大值
            if(l >= 0)
                res.push_back(dque.front());
        }
        return res;
    }
};
```