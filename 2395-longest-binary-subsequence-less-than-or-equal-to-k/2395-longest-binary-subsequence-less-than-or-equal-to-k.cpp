class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.length();
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, INT_MAX));
        int answer = 0;
        dp[0][0] = 0;
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                if (dp[i][j] != INT_MAX)
                {
                    // cout << i << ' ' << j << ' ' << dp[i][j] << '\n';
                    answer = max(answer, j);
                    dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
                    if ((dp[i][j] * 2) + (s[i] == '1') <= k)
                    {
                        dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] * 2 + (s[i] == '1'));
                    }
                }
            }
        } 
        return answer;
    }
};