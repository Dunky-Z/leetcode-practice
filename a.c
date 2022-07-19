class Solution
{
public:
    int maximumSum(vector<int> &nums)
    {
        int n = nums.size();
        int dp[n];
        dp[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
        }
        int ans = dp[0];
        for (int i = 1; i < n; i++)
        {
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};