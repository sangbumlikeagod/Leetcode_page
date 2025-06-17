class Solution {
    vector<int> dp;
    int DP(int n)
    {
        if (dp[n]) return dp[n];
        if (n == 0) return 0;
        int tmp = INT_MAX;
        for (int i = 100; i > 0; i--)
        {
            if (i * i <= n)
            {
                tmp = min(tmp, DP(n - i * i) + 1);
            }
        }
        return dp[n] = tmp;
    }
public:
    int numSquares(int n) {
        dp.resize(n + 1);
        return DP(n);
    }
};