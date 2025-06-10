class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        for (vector<int>& arg : pairs)
        {
            arg[0] += 1000;
            arg[1] += 1000;
        }
        sort(pairs.begin(), pairs.end(), [](vector<int>& a, vector<int>& b){
            return a.back() < b.back();
        });
        vector<int> dp(2002, 0);
        int arrIdx = 0;

        for (int i = 0; i < 2001; i++)
        {
            while (arrIdx < pairs.size() && pairs[arrIdx][1] == i)
            {
                // cout << i << ' ' << arrIdx << '\n';
                dp[pairs[arrIdx][1] + 1] = max(dp[pairs[arrIdx][1] + 1], dp[pairs[arrIdx][0]] + 1);
                arrIdx++;
            }
            dp[i + 1] = max(dp[i + 1], dp[i]);
        }
        return dp[2001];
    }
};