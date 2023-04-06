/*
 * @lc app=leetcode.cn id=1218 lang=cpp
 *
 * [1218] 最长定差子序列
 */

// @lc code=start
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        // dp[i] 表示以 i 结尾的最长定差子序列的长度
        unordered_map<int, int> dp;
        int res = 0;
        for(auto num : arr)
        {
            // 以 num 结尾的最长定差子序列的长度肯定是
            // 以 num-difference 结尾的最长定差子序列的长度加 1
            dp[num] = dp[num - difference] + 1;
            res = max(res, dp[num]);
        }
        return res;
    }
};
// @lc code=end

