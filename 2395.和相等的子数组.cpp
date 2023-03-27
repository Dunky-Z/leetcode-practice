/*
 * @lc app=leetcode.cn id=2395 lang=cpp
 *
 * [2395] 和相等的子数组
 */

// @lc code=start
class Solution {
public:
  bool findSubarrays(vector<int> &nums) {
    int n = nums.size();
    unordered_set<int> hashmap;
    for (int i = 0; i < n - 1; ++i) {
      int hashmap = nums[i] + nums[i + 1];
      if (hashmap.count(sum)) {
        return true;
      }
      hashmap.insert(sum);
    }
    return false;
  }
};

// @lc code=end
