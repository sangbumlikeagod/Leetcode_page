class Solution
{
public:
    int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit, vector<int> &worker)
    {
        vector<pair<int, int>> difficultyProfit{};
        for (int i = 0; i < profit.size(); i++)
        {
            difficultyProfit.push_back({difficulty[i], profit[i]});
        }
        sort(difficultyProfit.begin(), difficultyProfit.end());
        sort(worker.begin(), worker.end());
        int pdIndex = 0;
        int maxValue = 0;
        int ans = 0;
        for (int index = 0; index < worker.size(); index++)
        {
            while (pdIndex < difficultyProfit.size() && worker[index] >= difficultyProfit[pdIndex].first)
            {
                maxValue = max(maxValue, difficultyProfit[pdIndex].second);
                pdIndex++;
            }
            ans += maxValue;
        }
        return ans;
    }
};