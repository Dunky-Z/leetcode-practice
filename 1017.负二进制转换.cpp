/*
 * @lc app=leetcode.cn id=1017 lang=cpp
 *
 * [1017] 负二进制转换
 */

// @lc code=start
class Solution {
 public:
  string baseNeg2(int n) {
    string res = "";
    while (n != 0) {
      res = to_string(n & 1) + res;
      n = -(n >> 1);
    }
    return res == "" ? "0" : res;
  }
};
// @lc code=end

char *baseNeg2(int n) {
  char *res = "";
  while (n != 0) {
    res = to_string(n & 1) + res;
    n = -(n >> 1);
  }
  return res == "" ? "0" : res;
}