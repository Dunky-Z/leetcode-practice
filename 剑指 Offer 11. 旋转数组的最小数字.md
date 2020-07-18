---
title: 剑指 Offer 11. 旋转数组的最小数字
tags: LeetCode,剑指
notebook: a - 001 | ITabc
---

把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。例如，数组 [3,4,5,1,2] 为 [1,2,3,4,5] 的一个旋转，该数组的最小值为1。  

示例 1：
```
输入：[3,4,5,1,2]
输出：1
```
示例 2：
```
输入：[2,2,2,0,1]
输出：0
```

Solution 1：
从`index = 1`开始遍历一遍数组，找到`num[index] < num[index - 1]`说明找到了转折点，直接返回`num[index]`即可。还要考虑数组是递增的，并没有反转的情况，那么只需要返回`num[0]`即可。
```cpp
class Solution {
public:
    int minArray(vector<int>& numbers) 
    {
        for(size_t i = 1; i < numbers.size(); ++i)
        {
            if(numbers[i] < numbers[i - 1])
                return numbers[i];
        }
        return numbers[0];
    }
};
```

Solution 2:
图转载自[Krahets](https://leetcode-cn.com/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof/solution/mian-shi-ti-11-xuan-zhuan-shu-zu-de-zui-xiao-shu-3/)

![](https://gitee.com//dominic_z/markdown_picbed/raw/master/img/Picture1.png)

- `num[m] > num[j]`:`m`一定在左排序数组中，因此执行`i = m + 1`
- `num[m] < num[j]`:`m`一定在右排序数组中，因此执行`j = m`
- `num[m] == num[j]`:`m`无法确定在哪一侧，执行`j = j - 1`缩小范围

```cpp
class Solution {
public:
    int minArray(vector<int>& numbers) 
    {
        size_t i = 0, j = numbers.size() - 1;
        while(i < j)
        {
            size_t m = i + (j - i) / 2;
            //如果j < mid ，最小值一定在[mid + 1, j]
            if(numbers[j] < numbers[m])
                i = m + 1;
            //如果相等，无法判断在哪一边，j--缩小一下范围
            else if(numbers[j] == numbers[m])
                j--;
            else
                j = m;
        }
        return numbers[i];
    }
};
```