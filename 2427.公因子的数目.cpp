/*
 * @lc app=leetcode.cn id=2427 lang=cpp
 *
 * [2427] 公因子的数目
 */

// @lc code=start
class Solution {
public:
    int commonFactors(int a, int b) {
        if(a == 0 || b == 0) return 0;
        int count = 0;
        for(int i = 1; i <= a || i <= b; ++i)
        {
            if(a % i == 0 && b % i == 0)
            {
                count++;
            }
        }
        return count;
        
    }
};
// @lc code=end

