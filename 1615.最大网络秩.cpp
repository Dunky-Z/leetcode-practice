/*
 * @lc app=leetcode.cn id=1615 lang=cpp
 *
 * [1615] 最大网络秩
 */

// @lc code=start
class Solution {
public:
  int maximalNetworkRank(int n, vector<vector<int>> &roads) {
    unordered_map<int, int> m;
    for (auto &road : roads) {
      m[road[0]]++;
      m[road[1]]++;
    }

    int maxRank = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        //   找出连通道路最多的两个城市
        int rank = m[i] + m[j];
        //  如果两个城市之间有道路，那么就减去一条道路
        for (auto &road : roads) {
          if ((road[0] == i && road[1] == j) ||
              (road[0] == j && road[1] == i)) {
            rank--;
            break;
          }
        }
        maxRank = max(maxRank, rank);
      }
    }
    return maxRank;
  }
};
// @lc code=end
