/*
 * @lc app=leetcode.cn id=1638 lang=cpp
 *
 * [1638] 统计只差一个字符的子串数目
 */

// @lc code=start
class Solution {
public:
    int countSubstrings(string s, string t) {
        int l = s.size();
        int m = t.size();
        int ans
        for(int i =0; i < l; ++i)
        {
            for(int j = 0; j < m; ++j)
            {
                int diff = 0;
                for(int k = 0; k < l - i && k < m - j; ++k)
                {
                    if(s[i + k] != t[j + k])
                    {
                        diff++;
                    }
                    if(diff > 1)
                    {
                        break;
                    }
                    if(diff == 1)
                    {
                        ans++;
                    }
                }
            }
        }
        return ans;

    }
};
// @lc code=end

