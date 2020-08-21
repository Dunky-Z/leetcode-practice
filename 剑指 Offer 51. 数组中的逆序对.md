---
title: 剑指 Offer 51. 数组中的逆序对
tags: LeetCode
notebook: a - 001 | ITabc
---

在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数。

示例 1:
```
输入: [7,5,6,4]
输出: 5
```

限制：`0 <= 数组长度 <= 50000`

---
Solution 1:

```cpp
class Solution {
public:
    int global_count = 0;
    int reversePairs(vector<int>& nums) 
    {
        vector<int> copyarr(nums.size(), 0);
        merge_sort(nums, copyarr, 0, nums.size()-1);
        return global_count;
    }

    void merge_sort(vector<int>& nums, vector<int>& copyarr, int left, int right) 
    {
        if (left >= right) return;
        int mid = left + (right - left) / 2;
        merge_sort(nums, copyarr, left, mid);
        merge_sort(nums, copyarr, mid+1, right);
        int i = left, j = mid + 1, k = left;
        while (i <= mid && j <= right) 
        {
            //nums.
            if (nums[j] < nums[i]) 
            {
                copyarr[k++] = nums[j++];
                //前半段数组，从i到mid之间的数组都要比后半段数字大
                //所以此时新增逆序对就是mid-i+1
                global_count += (mid - i + 1);        
            } else 
            {
                copyarr[k++] = nums[i++];
            }
        }
        //前半段有元素没有比较完，直接复制到排序后的数组中
        if (i <= mid) copy(nums.begin() + i, nums.begin() + mid + 1, copyarr.begin() + k);
        //前半段有元素没有比较完，直接复制到排序后的数组中
        if (j <= right) copy(nums.begin() + j, nums.begin() + right+1, copyarr.begin() + k);
        //将排序完的两小段，填入原数组进入下一次递归
        copy(copyarr.begin() + left, copyarr.begin() + right + 1, nums.begin() + left);
    }
};
```