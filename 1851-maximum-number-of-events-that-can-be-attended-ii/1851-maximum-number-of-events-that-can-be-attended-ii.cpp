class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        sort(events.begin(), events.end(), [](vector<int>& a, vector<int>& b){
            return a[1] < b[1];
        });
        vector<int> tmps {};
        for (vector<int>& event : events)
            {
                tmps.push_back(event[1]);
            }
        vector<int> nearest(n + 1);
        for (int i = 0; i < n; i++)
            {
                size_t arg = upper_bound(tmps.begin(), tmps.end(), events[i][0] - 1) - tmps.begin();
                // cout << arg << '\t';
                nearest[i] = arg;
            }
        // cout << '\n';
            
        vector<vector<int>> dp(n + 2, vector<int>(k + 2, 0));

        for (int i = 1; i <= n; i++)
            {
                int near = nearest[i - 1];
                for (int j = 1; j <= k; j++)
                {

                    dp[i][j] = max(dp[i - 1][j], dp[near][j - 1] + events[i - 1][2]);
                    // cout << dp[i][j] << ' ';
                }
                // cout << '\n';
            }

        int answer = 0;
        for (int i = 1; i <= n; i++)
            {
            for (int j = 1; j <= k; j++)
                {
                    answer = max(answer, dp[i][j]);
                }
            }
        return answer;
    }
};