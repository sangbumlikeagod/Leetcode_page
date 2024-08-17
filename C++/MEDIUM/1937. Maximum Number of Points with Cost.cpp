class Solution
{
public:
    long long maxPoints(vector<vector<int>> &points)
    {
        int rSize = points.size();
        int cSize = points[0].size();
        long long answer = 0;
        vector<vector<long long>> dp(rSize, vector<long long>(cSize, 0));
        for (int i = 0; i < rSize; i++)
        {
            for (int j = 0; j < cSize; j++)
            {
                dp[i][j] += points[i][j];
                if (i == rSize - 1)
                {
                    answer = max(dp[i][j], answer);
                    continue;
                }
                else
                {
                    long long s = j - dp[i][j] > 0 ? j - dp[i][j] : 0;
                    long long e = j + dp[i][j] < cSize ? j + dp[i][j] : cSize;
                    for (int k = s; k < e; k++)
                    {
                        dp[i + 1][k] = max(dp[i + 1][k],
                                           dp[i][j] - abs(k - j));
                    }
                }
            }
        }
        return answer;
    }
};