/*
 * @lc app=leetcode.cn id=1053 lang=cpp
 *
 * [1053] 交换一次的先前排列
 */

// @lc code=start
class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        int n = arr.size();
        for(int i = n - 1; i > 0; i--)
        {
            // 找到第一个 arr[i-1] > arrp[i]
            if(arr[i - 1] > arr[i])
            {
               for(int j = n - 1; j > i - 1; j--)
               {
                   // 找到第一个 arr[j] < arr[i-1] && arr[j] != arr[j - 1]
                   if(arr[j] < arr[i - 1] && (j == n - 1 || arr[j] != arr[j - 1]))
                   {
                       swap(arr[i - 1], arr[j]);
                       return arr;
                   }
               }
            }
        }
        return arr;

    }
};
// @lc code=end

