class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp (400, INT_MAX);
        dp[1] = 0;
        int daysIdx = 0;
        for (int i = 1; i <= 365; i++)
        {
            if (days[daysIdx] == i)
            {
                // cout << i << '\n';
                if (dp[i] != INT_MAX)
                {
                    dp[i + 1] = min(dp[i + 1], dp[i] + costs[0]);
                    dp[i + 7] = min(dp[i + 7], dp[i] + costs[1]);
                    dp[i + 30] = min(dp[i + 30], dp[i] + costs[2]);
                }
                daysIdx++;
            }
            else
            {
                dp[i + 1] = min(dp[i + 1], dp[i]);
            }
            if (daysIdx == days.size()) break;
        }
        // cout << days.back() + 1 << '\n';
        int answer = INT_MAX;
        for (int i = 1; i <= 30; i++)
        {
            answer = min(answer, dp[days.back() + i]);
        }
        return answer;
    }
};