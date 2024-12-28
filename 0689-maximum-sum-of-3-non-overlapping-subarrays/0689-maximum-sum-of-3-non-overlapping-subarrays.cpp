class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int s_size = nums.size();
        vector<int> dp (s_size, 0);
        vector<int> dp_pos (s_size, 0);
        vector<int> dp2 (s_size, 0);
        vector<pair<int, int>> dp2_pos (s_size, {0, 0});
        
        vector<int> windowValue (s_size, 0);
        int sum_dp = 0;
        for (int i = 0; i < k; i++)
        {
            sum_dp += nums[i];
        }
        dp[k - 1] = sum_dp;
        dp_pos[k - 1] = k - 1;
        windowValue[k - 1] = sum_dp;
        for (int i = k; i < s_size; i++)
        {
            sum_dp -= nums[i - k];
            sum_dp += nums[i];
            windowValue[i] = sum_dp;
            if (sum_dp > dp[i - 1])
            {
                dp[i] = sum_dp;
                dp_pos[i] = i;
            }
            else
            {
                dp[i] = dp[i - 1];
                dp_pos[i] = dp_pos[i - 1];
            }
        }

        dp2[2 * k - 1] = windowValue[k - 1] + windowValue[2 * k - 1];
        dp2_pos[2 * k - 1] = {k - 1, 2 * k - 1};
        for (int i = 2 * k; i < s_size; i++)
        {
            int me = windowValue[i];
            int be_val = dp[i - k];
            int be_idx = dp_pos[i - k];
            if (me + be_val > dp2[i - 1])
            {
                dp2[i] = me + be_val;
                dp2_pos[i] = {be_idx, i};
            }
            else
            {
                dp2[i] = dp2[i - 1];
                dp2_pos[i] = dp2_pos[i - 1];
            }
        }
        int default_value = dp2[2 * k - 1] + windowValue[3 * k - 1];
        vector<int> answer = {k - 1, 2 * k - 1, 3 * k - 1};

        for (int i = 3 * k; i < s_size; i++)
        {
            if (windowValue[i] + dp2[i - k] > default_value)
            {
                answer = {dp2_pos[i - k].first, dp2_pos[i - k].second, i};
                default_value = windowValue[i] + dp2[i - k];
            }
        }
        answer[0] -= k - 1;
        answer[1] -= k - 1;
        answer[2] -= k - 1;
        return answer;

    }
};