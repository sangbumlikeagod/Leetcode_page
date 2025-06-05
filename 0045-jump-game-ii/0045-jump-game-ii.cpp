class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 10001);
        dp[0] = 0;
        for (int i = 0; i < n - 1; i++)
            {
                for (int j = i + 1; j <= min(i + nums[i], n - 1); j++)
                    {
                        dp[j] = min(dp[j], dp[i] + 1);
                    }
            }

        return dp[n - 1];
    }
};