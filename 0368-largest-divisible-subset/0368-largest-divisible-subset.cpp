class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int ln = nums.size();
        vector<int> dp(ln, 0);
        vector<int> dp_prev(ln, 0);
        vector<pair<int, int>> sorted {};
        for (int i = 0; i < ln; i++)
        {
            sorted.push_back({nums[i], i});
            dp_prev[i] = -1;
            dp[i] = 1;
        }
        sort(sorted.begin(), sorted.end());
        
        int maxIdx = 0;
        int maxVal = 0;
        for (int i = 0; i < ln; i++)
        {
            for (int j = i + 1; j < ln; j++)
            {
                int l = sorted[i].first;
                int r = sorted[j].first;
                if (r < l) swap(l, r);
                if (r % l == 0)
                {
                    if (dp[j] < dp[i] + 1)
                    {
                        dp[j] = dp[i] + 1;
                        if (dp[j] > maxVal)
                        {
                            maxVal = dp[j];
                            maxIdx = j;
                        }
                        dp_prev[j] = i;
                    }
                }
            }
        }

        vector<pair<int, int>> answerPair {};
        vector<int> answer {};
        while (maxIdx != -1)
        {
            answerPair.push_back(sorted[maxIdx]);
            maxIdx = dp_prev[maxIdx];
        }
        sort(sorted.begin(), sorted.end(), [](pair<int, int>& a, pair<int, int>&b){
            return a.second < b.second;
        });
        for (pair<int, int> arg :answerPair)
        {
            answer.push_back(arg.first);
        }
        // reverse(answer.begin(), answer.end());
        return answer;


    }
};