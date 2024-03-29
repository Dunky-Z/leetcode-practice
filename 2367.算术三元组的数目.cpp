/*
 * @lc app=leetcode.cn id=2367 lang=cpp
 *
 * [2367] 算术三元组的数目
 */

// @lc code=start
class Solution {
public:
  int arithmeticTriplets(vector<int> &nums, int diff) {
    int ans = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (nums[j] - nums[i] != diff) {
          continue;
        }
        for (int k = j + 1; k < n; k++) {
          if (nums[k] - nums[j] == diff) {
            ans++;
          }
        }
      }
    }
    return ans;
  }
};
// @lc code=end
