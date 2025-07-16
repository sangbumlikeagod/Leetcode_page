class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();


        vector<vector<int>> dp(n + 1, vector<int>(4, 0));
        bool oddSig = false;
        bool evenSig = false;
        for (int i = 0; i < n; i++)
        {
            int thisOdd = nums[i] % 2;
            if (thisOdd)
            {
                // 홀짝
                if (dp[i][1])
                {
                    dp[i + 1][0] = max(dp[i + 1][0], dp[i][1] + 1);
                }
                // 짝홀
                if (dp[i][2])
                {
                    dp[i + 1][2] = max(dp[i + 1][2], dp[i][2] + 1);
                }

                
                if (oddSig)
                {
                    // 짝홀
                    dp[i][2] = max(dp[i][2], 2);
                }

                if (evenSig)
                {
                    // 홀 홀
                    dp[i][0] = max(dp[i][0], 2);
                }
            }
            else
            {
                // 짝짝
                if (dp[i][3])
                {
                    dp[i + 1][3] = max(dp[i + 1][3], dp[i][3] + 1);
                }
                // 홀홀
                if (dp[i][0])
                {
                    // 홀홀에서 홀짝으로
                    dp[i + 1][1] = max(dp[i + 1][1], dp[i][0] + 1);
                }

                if (oddSig)
                {
                    dp[i + 1][1] = max(dp[i + 1][1], 2);
                }
                if (evenSig)
                {
                    dp[i + 1][3] = max(dp[i + 1][3], 2);
                }
            }

            for (int j = 0; j < 4; j++)
            {
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
            }


            if (nums[i] % 2)
            {
                oddSig = true;
            }
            else
            {
                evenSig = true;
            }
        }

        int answer = 0;
        for (int j = 0; j < 4; j++)
            {
                answer = max(answer, dp[n][j]);
            }
        return answer;
    }
};