class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> dp;
        vector<vector<int>> related(n + 1, vector<int>{});
        vector<int> answer {};
        for (vector<int> query : queries) 
        {
            dp.resize(n + 1, INT_MAX);
            related[query[0]].push_back(query[1]);
            dp[0] = 0;
            for (int i = 0; i < n; i++)
            {
                for (int arg : related[i])
                {
                    dp[arg] = min(dp[arg], dp[i] + 1);
                }
                dp[i + 1] = min(dp[i + 1], dp[i] + 1);
            }
            answer.push_back(dp[n - 1]);
        }
        return answer;
    }
};