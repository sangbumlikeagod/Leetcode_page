class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        vector<vector<int>> dp(arr.size(), vector<int> (arr.size(), 1));
        for (int i = 0; i < arr.size(); i++)
        {
            // 뒤에있는 애들 먼저
            for (int j = i + 1; j < arr.size() - 1; j++)
            {
                if (dp[i][j] != 1) continue;
                int mightNext = arr[i] + arr[j];
                auto candid = lower_bound(arr.begin() + j, arr.end(), mightNext);
                if (candid == arr.end()) break;
                if (*candid == mightNext)
                {
                    dp[candid - arr.begin()][j] = max(dp[i][j] + 2, dp[candid - arr.begin()][j]);
                }
            }
            for (int j = 0; j < i; j++ )
            {
                if (dp[i][j] == 1)
                {
                    continue;
                }
                int mightNext = arr[i] + arr[j];
                auto candid = lower_bound(arr.begin() + j, arr.end(), mightNext);
                if (candid == arr.end()) break;
                if (*candid == mightNext)
                {
                   dp[candid - arr.begin()][i] = max(dp[i][j] + 1, dp[candid - arr.begin()][i]);
                }
            }
        }
        int answer = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            for (int j = 0; j < arr.size(); j++)
            {
                answer = max(dp[i][j], answer);
            }
        }
        if (answer == 1) return 0;
        return answer;
    }
};