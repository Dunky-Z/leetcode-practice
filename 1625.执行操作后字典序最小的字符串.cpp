/*
 * @lc app=leetcode.cn id=1625 lang=cpp
 *
 * [1625] 执行操作后字典序最小的字符串
 */

// @lc code=start
class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        int n = s.size();
        vector<int> vis(n);
        string res = s;
        // 将 s 延长一倍，方便截取轮转后的字符串 t
        s = s + s;
        for (int i = 0; vis[i] == 0; i = (i + b) % n) {
            vis[i] = 1;
            // 可以执行任意次的操作，但实际上只需要执行 9 次就够了，超过就此就循环了
            for (int j = 0; j < 10; j++) {
                // 因为题目要求只加到奇数下标上，如果 b 是偶数，
                // 那么 k 的取值范围是 [0, 0]，否则是 [0, 9]
                int k_limit = b % 2 == 0 ? 0 : 9;
                for (int k = 0; k <= k_limit; k++) {
                    // 每次进行累加之前，重新截取 t
                    string t = s.substr(i, n);
                    // 累加奇数下标
                    for (int p = 1; p < n; p += 2) {
                        t[p] = '0' + (t[p] - '0' + j * a) % 10;
                    }
                    for (int p = 0; p < n; p += 2) {
                        t[p] = '0' + (t[p] - '0' + k * a) % 10;
                    }
                    res = min(res, t);
                }
            }
        }
        return res;
    }
};
// @lc code=end

