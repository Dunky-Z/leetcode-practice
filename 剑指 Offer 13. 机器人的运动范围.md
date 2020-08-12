---
title: 剑指 Offer 13. 机器人的运动范围
tags: LeetCode,深度优先搜索，图
notebook: a - 001 | ITabc
---

地上有一个m行n列的方格，从坐标 `[0,0]` 到坐标 `[m-1,n-1]` 。一个机器人从坐标 `[0, 0]` 的格子开始移动，它每次可以向左、右、上、下移动一格（不能移动到方格外），也不能进入行坐标和列坐标的数位之和大于k的格子。例如，当k为18时，机器人能够进入方格 `[35, 37]` ，因为`3+5+3+7=18`。但它不能进入方格 `[35, 38]`，因为`3+5+3+8=19`。请问该机器人能够到达多少个格子？

 

示例 1：
```
输入：m = 2, n = 3, k = 1
输出：3
```
示例 2：
```
输入：m = 3, n = 1, k = 0
输出：1
```
提示：
```
1 <= n,m <= 100
0 <= k <= 20
```

---

Solution 1:

```cpp

class Solution {
public:
    int m, n, k;
    vector<vector<bool>> visited;
    int movingCount(int m, int n, int k) 
    {
        if(m == 0 || n == 0)
            return 0;
        this->m = m;
        this->n = n;
        this->k = k;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        this->visited =  visited;
        return dfs(0,0,0,0);
        
    }
    int dfs(int x, int y, int sx, int sy)
    {
        if(x >= m || y >= n || k < sx + sy || visited[x][y])
            return 0;
        visited[x][y] = true;
        return 1 + dfs(x + 1, y, (x + 1) % 10 != 0 ? sx + 1 : sx - 8, sy)
                 + dfs(x, y + 1, sx, (y + 1) % 10 != 0 ? sy + 1 : sy - 8);
    }
};
```

Solution 2:


