/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
class Solution
{
public:
    bool isPalindrome(int x)
    {
        int rev = 0;
        if (x < 0 || x % 10 == 0 && x != 0)
            return false;
        while (x > rev)
        {
            rev = rev * 10 + x % 10;
            x = x / 10;
        }
        return rev == x || rev / 10 == x;
    }
};
// @lc code=end
