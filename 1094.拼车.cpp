/*
 * @lc app=leetcode.cn id=1094 lang=cpp
 *
 * [1094] 拼车
 */

// @lc code=start

class Solution
{
public:
    bool carPooling(vector<vector<int>> &trips, int capacity)
    {
        int cur = 0;
        vector<int> diff(1001);
        for (auto &trip : trips)
        {
            diff[trip[1]] += trip[0];
            diff[trip[2]] -= trip[0];
        }
        for (int i = 0; i <= 1000; ++i)
        {
            cur += diff[i];
            if (cur > capacity)
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
