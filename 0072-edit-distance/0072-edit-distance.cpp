class Solution {
public:
    int minDistance(string word1, string word2) {
        int p = word1.length(), q = word2.length();
        if (p < q)
        {
            swap(p, q);
            swap(word1, word2);
        }
        // else if (p == q)
        // {
        //     int answer = 0;
        //     for (int i = 0; i < p; i++)
        //     {
        //         answer += word1[i] == word2[i];
        //     }
        //     return answer;
        // }
        vector<vector<int>> dp(p + 1, vector<int>(q + 1, 501));
        dp[0][0] = 0;
        for (int i = 0; i < p; i++)
        {
            for (int j = 0; j < q; j++)
            {
                if (dp[i][j] != 501)
                {
                    if (word1[i] == word2[j])
                    {
                        // 그냥 넘기기
                        dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j]);
                    }
                    else
                    {
                        // 바꾸기
                        dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + 1);
                    }
                    // 지워야할때
                    dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);
                    dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + 1);
                }
            }
        }
        int answer = 501;
        for (int i = 0; i <= p; i++)
        {
            // dp[3] 0, 1 2 3포함 나머지는 다 없어져야함
            answer = min(p - (i) + dp[i][q], answer);
            // cout << p - (i - 1) << ' ' <<  dp[i][q] << '\n';
        } 
        for (int i = 0; i < q; i++)
        {
            // cout << p - (i - 1) << ' ' <<  dp[i][q] << '\n';
            answer = min(answer, q - i + dp[p][i]);
        }
        return answer;
    }
};