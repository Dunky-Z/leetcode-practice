/*
 * @lc app=leetcode.cn id=2469 lang=cpp
 *
 * [2469] 温度转换
 */

// @lc code=start
class Solution {
public:
  vector<double> convertTemperature(double celsius) {
    return {celsius + 273.15, celsius * 1.8 + 32.0};
  }
};

double *convertTemperature(double celsius, int *returnSize) {
  double *res = (double *)malloc(sizeof(double) * 2);
  res[0] = celsius + 273.15;
  res[1] = celsius * 1.80 + 32.00;
  *returnSize = 2;
  return res;
}
// @lc code=end
