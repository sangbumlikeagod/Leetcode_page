class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int sr = strs.size();
        vector<vector<int>> counts (sr + 1, vector<int> {0, 0});
        vector<vector<vector<int>>> dp(sr + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        for (int i = 0; i < sr; i++)
        {
            string str = strs[i];
            for (char c : str)
            {
                if (c == '1')
                {
                    counts[i][1]++;
                }
                else
                {
                    counts[i][0]++;
                }
            }
        }

        dp[0][0][0] = 0;
        for (int i = 0; i < sr; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                for (int k = 0; k <= n; k++)
                {
                    if (dp[i][j][k] != -1)
                    {
                        if (j + counts[i][0] <= m && k + counts[i][1] <= n)
                        {
                            dp[i + 1][j + counts[i][0]][k + counts[i][1]] = max(dp[i][j][k] + 1, dp[i + 1][j + counts[i][0]][k + counts[i][1]]);
                        }
                        dp[i + 1][j][k] = max(dp[i][j][k], dp[i + 1][j][k]);
                    }
                }
            }
        }

        int answer = 0;
        for (int i = 0; i <= m; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                answer = max(dp[sr][i][j], answer);
            }
        }
        return answer;
        // 이거 노노야 
    }
};