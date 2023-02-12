/*
 * @lc app=leetcode.cn id=1109 lang=cpp
 *
 * [1109] 航班预订统计
 */

// @lc code=start

// 差分数组工具类
class Difference
{
    // 差分数组
private:
    vector<int> diff;

    /* 输入一个初始数组，区间操作将在这个数组上进行 */
public:
    Difference(vector<int> nums)
    {
        diff.resize(nums.size());
        // 根据初始数组构造差分数组
        diff[0] = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            diff[i] = nums[i] - nums[i - 1];
        }
    }

    /* 给闭区间 [i, j] 增加 val（可以是负数）*/
public:
    void increment(int i, int j, int val)
    {
        diff[i] += val;
        if (j + 1 < diff.size())
        {
            diff[j + 1] -= val;
        }
    }

    /* 返回结果数组 */
public:
    vector<int> result()
    {
        vector<int> res(diff.size());
        // 根据差分数组构造结果数组
        res[0] = diff[0];
        for (int i = 1; i < diff.size(); i++)
        {
            res[i] = res[i - 1] + diff[i];
        }
        return res;
    }
};

class Solution
{
public:
    vector<int> corpFlightBookings(vector<vector<int>> &bookings, int n)
    {
        vector<int> nums(n);
        Difference difference(nums);
        for (auto book : bookings)
        {
            int i = book[0] - 1;
            int j = book[1] - 1;
            difference.increment(i, j, book[2]);
        }
        return difference.result();
    }
};
// @lc code=end
