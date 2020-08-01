---
title: 剑指 Offer 40. 最小的k个数
tags: LeetCode
notebook: a - 001 | ITabc
---
输入整数数组 `arr` ，找出其中最小的 `k` 个数。例如，输入`4、5、1、6、2、7、3、8`这`8`个数字，则最小的`4`个数字是`1、2、3、4`。

示例 1：
```
输入：arr = [3,2,1], k = 2
输出：[1,2] 或者 [2,1]
```
示例 2：
```
输入：arr = [0,1,2,1], k = 1
输出：[0]
```

限制：
```
0 <= k <= arr.length <= 10000
0 <= arr[i] <= 10000
```

---

Solution 1:
维护一个大根堆，也就是C++中的优先队列。先压入`k`个元素，然后遍历后续的所有元素，遇到比堆顶小的就将堆顶删除，并压入当前数。遍历完成后，输出堆的前`k`个数即使结果。
```cpp
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) 
    {
        vector<int>vec(k, 0);
        if (k == 0) return vec;
        priority_queue<int>pq;
        for (int i = 0; i < k; ++i) pq.push(arr[i]);
        for (int i = k; i < (int)arr.size(); ++i) 
        {
            if (pq.top() > arr[i]) 
            {
                pq.pop();
                pq.push(arr[i]);
            }
        }
        for (int i = 0; i < k; ++i) 
        {
            vec[i] = pq.top();
            pq.pop();
        }
        return vec;
    }
};
```