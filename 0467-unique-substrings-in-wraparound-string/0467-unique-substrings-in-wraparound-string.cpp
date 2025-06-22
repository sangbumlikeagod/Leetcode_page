class Solution {
public:
    int findSubstringInWraproundString(string s) {
        int n = s.length();
        vector<vector<int>> dp(n + 1, vector<int>(26, 0));
        vector<int> maxMem(26);
        // 끝이 x인애가 더 맞겠다 
        dp[0][s[0] - 'a'] = 1;
        maxMem[s[0] - 'a'] = 1;
        for (int i = 1; i < n; i++)
        {
            int j = s[i] - 'a';
            dp[i][j] = max(dp[i][j], 1);

            maxMem[j] = max(dp[i][j], maxMem[j]);
            int ne = j == 0 ? 25 : j - 1;
            if (dp[i - 1][ne])
            {
                dp[i][j] = dp[i - 1][ne] + 1;
                maxMem[j] = max(maxMem[j], dp[i][j]);
            }
        }
        int answer = 0;
        for (int i = 0; i < 26; i++)
        {
            answer += maxMem[i];
        }
        return answer;
    }
};