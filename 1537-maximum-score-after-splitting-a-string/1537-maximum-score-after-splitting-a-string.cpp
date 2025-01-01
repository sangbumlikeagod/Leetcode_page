class Solution {
public:
    int maxScore(string s) {
        // 한번만 계산해도 정확히 알 수 있지 않을까? 
        vector<pair<int, int>> dp (s.length() + 1, {0, 0});
        int answer = 0;
        for (int i = 1; i <= s.length(); i++)
        {
            dp[i].first = dp[i - 1].first;
            if (s[i - 1] == '0')
            {
                dp[i].first++;
            }
        }
        for (int i = s.length() - 1; i >= 0; i--)
        {
            dp[i].second = dp[i + 1].second;
            if (s[i] == '1')
            {
                dp[i].second++;
            }
        }

        for (int i = 1; i < s.length(); i++)
        {
            answer = max(answer, dp[i].first + dp[i].second);
        }
        return answer;
    }
};