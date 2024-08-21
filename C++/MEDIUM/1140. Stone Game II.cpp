class Solution
{
    int dp[100][100] = {0};
    vector<int> prefixSum = {0};
    int size;

private:
    int DP(int x, int y)
    {
        if (x >= size)
        {
            return 0;
        }
        if (dp[x][y])
        {
            return dp[x][y];
        }
        if (x + 2 * y >= size)
        {
            dp[x][y] = prefixSum[size] - prefixSum[x];
            return dp[x][y];
        }

        int mineTotal = prefixSum[size] - prefixSum[x];
        int oppsTotal = 100000000;
        for (int i = 1; i <= 2 * y; i++)
        {
            oppsTotal = min(oppsTotal, DP(x + i, max(i, y)));
        }
        dp[x][y] = mineTotal - oppsTotal;
        return dp[x][y];
    }

public:
    int stoneGameII(vector<int> &piles)
    {
        for (int pile : piles)
        {
            int before = prefixSum[prefixSum.size() - 1];
            prefixSum.push_back(pile + before);
        }
        size = piles.size();
        return DP(0, 1);
    }
};