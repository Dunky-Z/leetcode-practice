/*
 * @lc app=leetcode.cn id=2404 lang=cpp
 *
 * [2404] 出现最频繁的偶数元素
 */

// @lc code=start
class Solution {
 public:
  int mostFrequentEven(vector<int>& nums) {
    unordered_map<int, int> m;
    for (auto num : nums) {
      if (num % 2 == 0) {
        m[num]++;
      }
    }

    int res = -1;
    int t = 0;
    for (auto i : m) {
        if(res == -1 || i.second > t || i.second == t && i.first < res) {
            res = i.first;
            t = i.second;
        }
    }
    return res;
  }
};
// @lc code=end
