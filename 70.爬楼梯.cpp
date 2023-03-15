/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution {
public:
  int climbStairs(int n) {
    vector<int> memo(n + 1, -1);
    memo[0] = 1;
    memo[1] = 1;
    for (int i = 2; i <= n; i++) {
      memo[i] = memo[i - 1] + memo[i - 2];
    }
    return memo[n];
  };
  // @lc code=end
