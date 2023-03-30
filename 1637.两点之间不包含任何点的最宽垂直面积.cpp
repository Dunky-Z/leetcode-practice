/*
 * @lc app=leetcode.cn id=1637 lang=cpp
 *
 * [1637] 两点之间不包含任何点的最宽垂直面积
 */

// @lc code=start
class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        int max_width = 0;
        sort(points.begin(), points.end());
        for(int i = 1; i < points.size(); ++i)
        {
            max_width = max(points[i][0] - points[i-1][0], max_width);
        }
        return max_width;

    }
};
// @lc code=end
