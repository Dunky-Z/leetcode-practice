---
title: 剑指 Offer 47. 礼物的最大价值
tags: LeetCode,动态规划
notebook: a - 001 | ITabc
---
在一个 `m*n` 的棋盘的每一格都放有一个礼物，每个礼物都有一定的价值（价值大于 `0`）。你可以从棋盘的左上角开始拿格子里的礼物，并每次向右或者向下移动一格、直到到达棋盘的右下角。给定一个棋盘及其上面的礼物的价值，请计算你最多能拿到多少价值的礼物？

示例 1:
```
输入: 
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
输出: 12
解释: 路径 1→3→5→2→1 可以拿到最多价值的礼物
```

提示：
```
0 < grid.length <= 200
0 < grid[0].length <= 200
```

---
Solution 1:

`dp[i][j]`表示从`(0,0)`开始到`(i,j)`的最小路径和。因为`dp[i][j]`只和它上边和左边的元素有关，所以很容易写出状态转移方程：
`dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + grid[i][j]`。
由状态转移方程可以看出，`i,j`应该从`(1,1)`位置开始。不能从`(0,0)`。所以要先初始化好边界。边界也很容易初始化，就是将其元素相加。

```cpp
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) 
    {
        size_t rows = grid.size();
        size_t cols = grid[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, 0));
        dp[0][0] = grid[0][0];
        for(size_t i = 1; i < rows; ++i)
        {
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }
        for(size_t j = 1; j < cols; ++j)
        {
            dp[0][j] = dp[0][j-1] + grid[0][j];
        }
        for(size_t i = 1; i < rows; ++i)
        {
            for(size_t j = 1; j < cols; ++j)
            {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
        }
        return dp[rows-1][cols-1];
    }
};
```

Solution 2:
和主站64题最小路径和其实是同一道题，只是这题求的是最大路径和。只需要将最小值改为最大值即可。

用一维数组`dp[j]`来保存从第一个元素到`j`的最小路径。`dp[j]`是一行一行算的。`j`的最大值就是列数。不再提前初始化首行首列，在循环中判断，如果是第一列，即`j = 0`，`dp[j] + grid[i][j]`。因为`dp`是一行一行计算的，当求第二行的`dp[0]`时，`dp[0]+grid[i][j]`就是上一行第一个元素值加上当前元素值。初始化第一行时，因为`dp`初始化为整型最大值INT_MIN，所以`dp[j] = grid[i][j] + max(dp[j],dp[j-1])`中取最小值时一定取的是`dp[j-1]`。
```cpp
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) 
    {
        size_t rows = grid.size();
        size_t cols = grid[0].size();
        if(grid.empty() || cols == 0)
            return 0;
        vector<int> dp(cols, INT_MIN);
        dp[0] = 0;
        for(size_t i = 0; i < rows; ++i)
            for(size_t j = 0; j < cols; ++j)
            {
                if(j == 0)
                    dp[j] = dp[j] + grid[i][j];
                else dp[j] = grid[i][j] + max(dp[j], dp[j - 1]);
            }
        return dp[cols-1];
    }
};
```