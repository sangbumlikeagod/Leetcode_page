class Solution {

public:
    int minimumDeleteSum(string s1, string s2) {
        int p = s1.length(), q = s2.length();
        vector<vector<int>> dp;
        dp.resize(p + 1, vector<int>(q + 1, 1000000));


        dp[0][0] = 0;

        for (int i = 0; i <= p; i++)
        {
            for (int j = 0; j <= q; j++)
            {
                // cout << i << ' ' << j << ' ' << dp[i][j] << '\n';
                if (i != p && j != q && s1[i] == s2[j])
                {
                    // cout << ' ' << i + 1 << ' ' << j + 1<< ' ' << dp[i + 1][j + 1] << ' ' << dp[i][j]  << '\n';
                    dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j]);
                }

                if (i != p) {
                    dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + s1[i]);
                    // cout << '\t' << i + 1 << ' ' << j << ' ' << dp[i + 1][j] << ' ' << dp[i][j]  << '\n';
                }

                if (j != q) {
                    dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + s2[j]);
                    // cout << "\t\t\t" << i << ' ' << j + 1 << ' ' << dp[i][j + 1] << ' ' << dp[i][j]  << '\n';
                }
                if (i != p && j != q) {
                    dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + s1[i] + s2[j]);
                    // cout << "\t\t" << i + 1 << ' ' << j + 1 << ' ' << dp[i + 1][j + 1] << ' ' << dp[i][j] + s1[i] + s2[j] << '\n';
                }
            }
        }
        return dp[p][q];
    }
};