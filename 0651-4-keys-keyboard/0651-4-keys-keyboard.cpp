class Solution {
public:
    int maxA(int n) {
        vector<unordered_map<int, int>> dp(n + 1);
        dp[0][1] = 0;
        for (int i = 0; i < n; i++)
            {
                for (auto arg = dp[i].begin(); arg != dp[i].end(); arg++)
                    {
                        dp[i + 1][arg -> first] = max((arg -> first) + (arg ->second), dp[i + 1][arg -> first]);
                        if (i < n - 2)
                        {
                            dp[i + 2][arg -> second] = max(dp[i + 2][arg -> second], (arg ->second));
                        }
                    }
            }
        int answer = 0;
        for (auto arg = dp[n].begin(); arg != dp[n].end(); arg++)
            {
                answer = max(answer, arg -> second);
            }
        return answer;
    }
};