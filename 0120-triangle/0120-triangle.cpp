#define MAXIMUM 2000001
class Solution {

public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, MAXIMUM));
        dp[0][0] = triangle[0][0];
        for (int i = 0; i < n - 1; i++)
            {
                for (int j = 0; j <= i; j++)
                    {
                        dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + triangle[i + 1][j]);
                        dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + triangle[i + 1][j + 1]);
                    }
            }
        int answer = MAXIMUM;
        for (int i = 0; i < n; i++)
            {
                answer = min(answer, dp[n - 1][i]);
            }

        // for (int i = 0; i < n; i++)
        //     {
        //         for (int j = 0; j <= i; j++)
        //             {
        //                  cout << dp[i][j] << ' ';   
        //             }
        //         cout << '\n';
        //     }
        return answer;
    }
};