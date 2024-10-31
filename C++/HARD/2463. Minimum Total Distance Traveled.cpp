#define veryLarge 2147483647000
class Solution
{
    vector<vector<long long>> dp;

public:
    long long minimumTotalDistance(vector<int> &robot, vector<vector<int>> &factory)
    {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        int rSize = robot.size();
        int fSize = factory.size();
        dp = vector<vector<long long>>(fSize + 1, vector<long long>(rSize + 1, veryLarge));
        long long answer = veryLarge;
        dp[0][0] = 0;
        // 팩토리
        for (int i = 0; i < fSize; i++)
        {
            // 로봇
            for (int j = 0; j < rSize; j++)
            {
                if (dp[i][j] == veryLarge)
                    continue;
                dp[i + 1][j] = min(dp[i][j], dp[i + 1][j]);
                long long ds = 0;
                for (int k = j + 1; k <= min(rSize, j + factory[i][1]); k++)
                {
                    // cout << k << dp[i][j] + ds;
                    ds += abs(factory[i][0] - robot[k - 1]);
                    dp[i + 1][k] = min(dp[i + 1][k], dp[i][j] + ds);
                }
            }
        }

        for (int i = 0; i <= fSize; i++)
        {
            if (dp[i][rSize] != -1)
            {
                answer = min(answer, dp[i][rSize]);
            }
        }
        return answer;
    }
};