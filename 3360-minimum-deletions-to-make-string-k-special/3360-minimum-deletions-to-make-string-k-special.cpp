class Solution {
public:
    int minimumDeletions(string word, int k) {
        int n = word.length();
        vector<int> dp(26);
        for (char c : word)
        {
            dp[c - 'a']++;
        }
        sort(dp.begin(), dp.end());
        int idx = 0;

        // for (int arg : dp)
        // {
        //     cout << arg << ' ';
        // }

        while (dp[idx] == 0)
        {
            idx++;
        }
        int answer = INT_MAX;

        
        for (int j = dp[25]; j >= dp[idx]; j--)
        {
            // 시작시 이만큼 뺀다
            int tmp = dp[25] - j;

            for (int p = 24; p >= idx; p--)
            {
                if (dp[p] > j)
                {
                    tmp += dp[p] - j;
                }
                else if (dp[p] < j - k)
                {
                    tmp += dp[p];
                }
            }
            answer = min(answer, tmp);
        }
        return answer;
        
    }
};