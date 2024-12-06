class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> banSearch;
        vector<int> prefixSum;
        prefixSum.push_back(0);
        for (int ban : banned)
        {
            banSearch.insert(ban);
        }

        for (int i = 1; i <= n; i++)
        {
            if (banSearch.find(i) != banSearch.end())
                continue;

            int prev = prefixSum.back();

            prefixSum.push_back(i + prev);
        }
        int answer = 0;
        for (int i = prefixSum.size() - 1; i >= 0; i--)
        {
            if (answer >= i)
            {
                break;
            }
            int idx = lower_bound(prefixSum.begin(), prefixSum.end(), prefixSum[i] - maxSum) - prefixSum.begin();
            answer = max(answer, i - idx);
        }
        return answer;
    }
};