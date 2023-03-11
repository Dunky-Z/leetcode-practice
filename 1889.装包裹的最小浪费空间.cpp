/*
 * @lc app=leetcode.cn id=1889 lang=cpp
 *
 * [1889] 装包裹的最小浪费空间
 */

// @lc code=start
class Solution {
public:
    int minWastedSpace(vector<int>& packages, vector<vector<int>>& boxes) {
        sort(packages.begin(), packages.end());
        int n = packages.size();
        vector<long long> pre(n + 1);
        for (int i = 0; i < n; i++) {
            pre[i + 1] = pre[i] + packages[i];
        }
        long long res = LLONG_MAX;
        for (auto& box : boxes) {
            sort(box.begin(), box.end());
            if (box.back() < packages.back()) {
                continue;
            }
            long long cur = 0;
            int j = 0;
            for (int i = 0; i < box.size(); i++) {
                while (j < n && packages[j] <= box[i]) {
                    j++;
                }
                cur += (long long)box[i] * (j - i);
            }
            res = min(res, cur - pre[n]);
        }
        return res == LLONG_MAX ? -1 : res % 1000000007;
    

    }
};
// @lc code=end

