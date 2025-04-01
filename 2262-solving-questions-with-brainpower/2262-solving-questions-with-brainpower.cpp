class Solution {
    vector<long long> DP;
    long long dp(int idx, vector<vector<int>>& questions)
    {
        if (idx >= questions.size())
        {
            return 0;
        }
        if (DP[idx] != 0)
        {
            return DP[idx];
        }
        DP[idx] = max(dp(idx + questions[idx][1] + 1, questions) + questions[idx][0], DP[idx]);
        DP[idx] = max(dp(idx + 1, questions), DP[idx]);
        return DP[idx];
    }
public:
    long long mostPoints(vector<vector<int>>& questions) {
        DP.resize(questions.size(), 0);
        return dp(0, questions);
    }
};