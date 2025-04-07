class Solution {
public:
    bool canPartition(vector<int>& nums) {
        vector<vector<int>> dp(nums.size() + 1, vector<int> (40001, 0));
        int answer = 0;
        for (int num : nums)
        {
            answer += num;
        }
        if (answer % 2) return false;
        answer /= 2;
        for (int i = 0; i < nums.size(); i++)
        {
            if (dp[i][answer] != 0) return true;

            dp[i + 1][nums[i]] = 1;
            for (int j = 0; j < answer; j++)
            {
                if (dp[i][j])
                {
                    dp[i + 1][j] = 1;
                    dp[i + 1][j + nums[i]] = 1;
                }
            }
        }
        return false;
    }
};