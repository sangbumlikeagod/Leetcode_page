class Solution
{
    int dp[100001][2][3] = {0};

public:
    int checkRecord(int n)
    {
        const int modulo = 1000000007;
        dp[0][0][0] = 1;
        for (int x = 0; x < n; x++)
        {
            for (int y = 0; y < 2; y++)
            {
                for (int z = 0; z < 3; z++)
                {
                    if (dp[x][y][z])
                    {
                        if (!y)
                        {
                            dp[x + 1][1][0] = ((long long)dp[x][y][z] + (long long)dp[x + 1][1][0]) % modulo;
                        }
                        if (z != 2)
                        {
                            dp[x + 1][y][z + 1] = ((long long)dp[x][y][z] + (long long)dp[x + 1][y][z + 1]) % modulo;
                        }
                        dp[x + 1][y][0] = ((long long)dp[x][y][z] + (long long)dp[x + 1][y][0]) % modulo;
                    }
                }
            }
        }
        int answer = ((long long)dp[n][0][0] + (long long)dp[n][0][1] + (long long)dp[n][0][2] + (long long)dp[n][1][0] + (long long)dp[n][1][1] + (long long)dp[n][1][2]) % modulo;
        return answer % modulo;
    }
};