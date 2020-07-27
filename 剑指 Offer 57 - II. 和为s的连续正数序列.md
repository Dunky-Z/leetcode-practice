---
title: 剑指 Offer 57 - II. 和为s的连续正数序列
tags: LeetCode
notebook: 
---
输入一个正整数 `target` ，输出所有和为 `target` 的连续正整数序列（至少含有两个数）。

序列内的数字由小到大排列，不同序列按照首个数字从小到大排列。
示例 1：
```
输入：target = 9
输出：[[2,3,4],[4,5]]
```
示例 2：
```
输入：target = 15
输出：[[1,2,3,4,5],[4,5,6],[7,8]]
```

限制：`1 <= target <= 10^5`

---

Solution 1:
```cpp
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) 
    {
        vector<int> res_t;
        vector<vector<int>> res;
        for(int l = 1; l < target; ++l)
        {
            for(int n = 2; n < target / 2; ++n)
            {
                float r = (float)(2*target - l*n) / (float)n;
                if((int)r != r || (r - (float)l) + 1.0 != (float)n)
                {
                    continue;
                }
                else
                {
                    //递增填充数组
                    vector<int> res_t(n);
                    iota(res_t.begin(), res_t.end(), l);
                    res.push_back(res_t);
                }
            }
        }
        return res;
    }
};
```

Solution 2:
暴力枚举
```cpp
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) 
    {
        vector<vector<int>> vec;
        vector<int> res;
        int sum = 0, limit = (target - 1) / 2; // (target - 1) / 2 等效于 target / 2 下取整
        for (int i = 1; i <= limit; ++i) 
        {
            for (int j = i;; ++j) 
            {
                sum += j;
                if (sum > target) 
                {
                    sum = 0;
                    break;
                }
                else if (sum == target) 
                {
                    res.clear();
                    for (int k = i; k <= j; ++k) res.emplace_back(k);
                    vec.emplace_back(res);
                    sum = 0;
                    break;
                }
            }
        }
        return vec;
    }
};
```