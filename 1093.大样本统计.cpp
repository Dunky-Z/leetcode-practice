/*
 * @lc app=leetcode.cn id=1093 lang=cpp
 *
 * [1093] 大样本统计
 */

// @lc code=start
class Solution {
 public:
  vector<double> sampleStats(vector<int>& count) {
    auto find = [&](int i) -> int {
      for (int k = 0, t = 0;; ++k) {
        t += count[k];
        if (t >= i) {
          return k;
        }
      }
    };
    vector<double> res(5, 0);
    int n = count.size();
    int minNum = 1 << 30, maxNum = 0, mode = 0, modeCount = 0;
    long long  sum = 0, countSum = 0;
    for (int i = 0; i < n; ++i) {
      if (count[i] > 0) {
        maxNum = i;
        minNum = min(minNum, i);
        sum += 1LL * i * count[i];
        if (count[i] > modeCount) {
          modeCount = count[i];
          mode = i;
        }
      }
      countSum += count[i];
    }
    double mean = countSum % 2 == 1
                 ? find(countSum / 2 + 1)
                 : (find(countSum / 2) + find(countSum / 2 + 1)) / 2.0;
    res[0] = minNum;
    res[1] = maxNum;
    res[2] = sum * 1.0 / countSum;
    res[3] = mean;
    res[4] = mode;
    return res;
  }
}; 
// @lc code=end
