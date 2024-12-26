class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        vector<vector<int>> dp(nums.size() + 1, vector<int> (2002, 0));

        dp[0][1000] = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < 2002; j++)
            {
                if (dp[i][j] == 0)
                    continue;
                dp[i + 1][j + nums[i]] += dp[i][j];
                dp[i + 1][j - nums[i]] += dp[i][j];
            }
        }

        return dp[nums.size()][target + 1000];
        
    }
};